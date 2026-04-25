/*
 * ============================================================
 *  employee_operations.c  —  All CRUD operations
 *
 *  Functions in this file:
 *    - addEmployee()      add a new record
 *    - displayEmployees() print all records
 *    - searchEmployee()   find by ID or name
 *    - modifyEmployee()   update an existing record
 *    - deleteEmployee()   remove a record
 * ============================================================
 */

#include "employee.h"

/* ── Add a new employee ─────────────────────────────────── */
void addEmployee() {
    if (numEmployees >= MAX_EMPLOYEES) {
        printf("Maximum number of employees reached!\n");
        return;
    }

    struct Employee newEmployee;
    int empIdExists = 0;

    printf("Enter Employee ID: ");
    scanf("%d", &newEmployee.emp_id);
    clearBuffer();

    /* Check for duplicate ID */
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].emp_id == newEmployee.emp_id) {
            empIdExists = 1;
            break;
        }
    }

    if (empIdExists) {
        printf("Employee with ID %d already exists!\n", newEmployee.emp_id);
        logAction("ADD FAILED", "Duplicate ID attempted");
        return;
    }

    printf("Enter Name: ");
    fgets(newEmployee.name, MAX_NAME_LENGTH, stdin);
    strtok(newEmployee.name, "\n");

    printf("Enter Age: ");
    scanf("%d", &newEmployee.age);
    clearBuffer();

    printf("Enter Salary: ");
    scanf("%f", &newEmployee.salary);
    clearBuffer();

    printf("Enter Position: ");
    fgets(newEmployee.position, MAX_NAME_LENGTH, stdin);
    strtok(newEmployee.position, "\n");

    employees[numEmployees++] = newEmployee;
    printf("Employee added successfully!\n");

    /* Save data + write log */
    saveToFile();
    logAction("ADD", newEmployee.name);
}

/* ── Display all employees ──────────────────────────────── */
void displayEmployees() {
    if (numEmployees == 0) {
        printf("No employees to display!\n");
        logAction("DISPLAY", "No records found");
        return;
    }

    printf("\n--- All Employees (%d) ---\n", numEmployees);
    for (int i = 0; i < numEmployees; i++) {
        printEmployee(&employees[i]);
    }

    logAction("DISPLAY", "All records listed");
}

/* ── Search by ID or Name ───────────────────────────────── */
void searchEmployee() {
    int searchChoice;

    printf("\nSearch By:\n");
    printf("1. Employee ID\n");
    printf("2. Employee Name\n");
    printf("Enter your choice: ");
    scanf("%d", &searchChoice);
    clearBuffer();

    if (searchChoice == 1) {
        /* ── Search by ID (exact match) ── */
        int empId, found = 0;

        printf("Enter Employee ID to search: ");
        scanf("%d", &empId);
        clearBuffer();

        for (int i = 0; i < numEmployees; i++) {
            if (employees[i].emp_id == empId) {
                printf("\n--- Employee Found ---\n");
                printEmployee(&employees[i]);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("No employee found with ID %d.\n", empId);
            logAction("SEARCH", "ID not found");
        } else {
            logAction("SEARCH", "Found by ID");
        }

    } else if (searchChoice == 2) {
        /* ── Search by Name (partial, case-sensitive) ── */
        char searchName[MAX_NAME_LENGTH];
        int found = 0;

        printf("Enter Name (or part of name) to search: ");
        fgets(searchName, MAX_NAME_LENGTH, stdin);
        strtok(searchName, "\n");

        printf("\n--- Search Results ---\n");

        for (int i = 0; i < numEmployees; i++) {
            if (strstr(employees[i].name, searchName) != NULL) {
                printEmployee(&employees[i]);
                found = 1;
            }
        }

        if (!found) {
            printf("No employee found with name containing \"%s\".\n", searchName);
            logAction("SEARCH", "Name not found");
        } else {
            logAction("SEARCH", "Found by name");
        }

    } else {
        printf("Invalid search option!\n");
    }
}

/* ── Modify an existing employee ───────────────────────── */
void modifyEmployee() {
    int empId, found = 0;

    printf("Enter Employee ID to modify: ");
    scanf("%d", &empId);
    clearBuffer();

    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].emp_id == empId) {
            printf("Editing: %s\n", employees[i].name);

            printf("Enter new Name: ");
            fgets(employees[i].name, MAX_NAME_LENGTH, stdin);
            strtok(employees[i].name, "\n");

            printf("Enter new Age: ");
            scanf("%d", &employees[i].age);
            clearBuffer();

            printf("Enter new Salary: ");
            scanf("%f", &employees[i].salary);
            clearBuffer();

            printf("Enter new Position: ");
            fgets(employees[i].position, MAX_NAME_LENGTH, stdin);
            strtok(employees[i].position, "\n");

            printf("Employee details modified successfully!\n");
            saveToFile();
            logAction("MODIFY", employees[i].name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found!\n", empId);
        logAction("MODIFY FAILED", "ID not found");
    }
}

/* ── Delete an employee ─────────────────────────────────── */
void deleteEmployee() {
    int empId, found = 0;

    printf("Enter Employee ID to delete: ");
    scanf("%d", &empId);
    clearBuffer();

    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].emp_id == empId) {
            char deletedName[MAX_NAME_LENGTH];
            strcpy(deletedName, employees[i].name);

            /* Shift array left to fill the gap */
            for (int j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;

            printf("Employee deleted successfully!\n");
            saveToFile();
            logAction("DELETE", deletedName);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found!\n", empId);
        logAction("DELETE FAILED", "ID not found");
    }
}
