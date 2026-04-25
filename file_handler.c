/*
 * ============================================================
 *  file_handler.c  —  All file input/output
 *
 *  Functions in this file:
 *    - loadFromFile()    load binary data on startup
 *    - saveToFile()      save binary data after every change
 *    - exportEmployees() write readable .txt copy
 *    - logAction()       append a timestamped line to log file
 * ============================================================
 */

#include "employee.h"

/* ── Load binary data from employees.dat ───────────────── */
void loadFromFile() {
    FILE *file = fopen(DATA_FILE, "rb");

    if (file == NULL) {
        /* First run — no file yet, that is fine */
        printf("No saved data found. Starting fresh.\n");
        logAction("STARTUP", "No data file found, starting fresh");
        return;
    }

    fread(&numEmployees, sizeof(int), 1, file);
    fread(employees, sizeof(struct Employee), numEmployees, file);
    fclose(file);

    printf("%d employee record(s) loaded.\n", numEmployees);
    logAction("STARTUP", "Data loaded from employees.dat");
}

/* ── Save binary data to employees.dat ─────────────────── */
void saveToFile() {
    FILE *file = fopen(DATA_FILE, "wb");

    if (file == NULL) {
        printf("ERROR: Could not save data!\n");
        logAction("SAVE ERROR", "Could not open employees.dat for writing");
        return;
    }

    fwrite(&numEmployees, sizeof(int), 1, file);
    fwrite(employees, sizeof(struct Employee), numEmployees, file);
    fclose(file);

    printf("Data saved successfully!\n");
}

/* ── Export all records to employees.txt (human-readable) ─ */
void exportEmployees() {
    if (numEmployees == 0) {
        printf("No employees to export!\n");
        return;
    }

    FILE *file = fopen(EXPORT_FILE, "w");
    if (file == NULL) {
        printf("Error opening export file!\n");
        logAction("EXPORT ERROR", "Could not open employees.txt");
        return;
    }

    fprintf(file, "EMPLOYEE RECORDS\n");
    fprintf(file, "================\n\n");

    for (int i = 0; i < numEmployees; i++) {
        fprintf(file, "Employee ID : %d\n",   employees[i].emp_id);
        fprintf(file, "Name        : %s\n",   employees[i].name);
        fprintf(file, "Age         : %d\n",   employees[i].age);
        fprintf(file, "Salary      : %.2f\n", employees[i].salary);
        fprintf(file, "Position    : %s\n",   employees[i].position);
        fprintf(file, "----------------------------\n\n");
    }

    fprintf(file, "Total Records: %d\n", numEmployees);
    fclose(file);

    printf("Employee records exported to %s successfully!\n", EXPORT_FILE);
    logAction("EXPORT", "Records written to employees.txt");
}

/*
 * logAction
 * Appends one timestamped line to activity_log.txt.
 * Called automatically after every user action.
 *
 * Example output in log file:
 *   [2024-11-15 14:32:07] ADD        | Aarav Sharma
 *   [2024-11-15 14:33:01] DELETE     | Ram Bahadur
 */
void logAction(const char *action, const char *detail) {
    FILE *log = fopen(LOG_FILE, "a");   /* "a" = append, never overwrites */
    if (log == NULL) return;            /* silently skip if log can't open */

    /* Get current date and time */
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timestamp[25];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

    fprintf(log, "[%s] %-16s| %s\n", timestamp, action, detail);
    fclose(log);
}
