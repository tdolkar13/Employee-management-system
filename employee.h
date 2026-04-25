/*
 * ============================================================
 *  employee.h  —  Shared header file
 *
 *  This file is #included by every other .c file.
 *  It defines:
 *    - Constants (MAX sizes, file names)
 *    - The Employee struct
 *    - Global variable declarations (extern)
 *    - All function prototypes
 * ============================================================
 */

#ifndef EMPLOYEE_H   /* Header guard — prevents double inclusion */
#define EMPLOYEE_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* ── Constants ──────────────────────────────────────────── */
#define MAX_EMPLOYEES   100
#define MAX_NAME_LENGTH  50
#define DATA_FILE       "employees.dat"   /* binary save file  */
#define EXPORT_FILE     "employees.txt"   /* text export file  */
#define LOG_FILE        "activity_log.txt" /* activity log file */

/* ── Employee record ────────────────────────────────────── */
struct Employee {
    int   emp_id;
    char  name[MAX_NAME_LENGTH];
    int   age;
    float salary;
    char  position[MAX_NAME_LENGTH];
};

/* ── Global storage (defined in main.c, used everywhere) ── */
extern struct Employee employees[MAX_EMPLOYEES];
extern int numEmployees;

/* ── Prototypes: employee_operations.c ─────────────────── */
void addEmployee();
void displayEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();

/* ── Prototypes: file_handler.c ─────────────────────────── */
void saveToFile();
void loadFromFile();
void exportEmployees();
void logAction(const char *action, const char *detail);

/* ── Prototypes: utils.c ────────────────────────────────── */
void clearBuffer();
void printSeparator();
void printEmployee(struct Employee *e);

#endif /* EMPLOYEE_H */
