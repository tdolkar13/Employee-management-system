/*
 * ============================================================
 *  utils.c  —  Utility / helper functions
 *
 *  Functions in this file:
 *    - clearBuffer()    flush leftover input after scanf
 *    - printSeparator() print a divider line
 *    - printEmployee()  print one employee record neatly
 * ============================================================
 */

#include "employee.h"

/*
 * clearBuffer
 * After scanf("%d"), a '\n' is left in stdin.
 * If fgets() runs next it reads that '\n' and returns empty.
 * This function discards everything up to and including '\n'.
 */
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Print a visual separator line */
void printSeparator() {
    printf("------------------------------\n");
}

/*
 * printEmployee
 * Prints one employee record in a clean, aligned format.
 * Takes a pointer so no copy of the struct is made.
 */
void printEmployee(struct Employee *e) {
    printf("\n");
    printf("  Employee ID : %d\n",   e->emp_id);
    printf("  Name        : %s\n",   e->name);
    printf("  Age         : %d\n",   e->age);
    printf("  Salary      : %.2f\n", e->salary);
    printf("  Position    : %s\n",   e->position);
    printSeparator();
}
