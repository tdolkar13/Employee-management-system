/*
 * ============================================================
 *  main.c  —  Entry point
 *
 *  Responsibilities:
 *    - Define global employee array and counter
 *    - Load saved data on startup
 *    - Show the main menu and dispatch to functions
 *
 *  Does NOT contain any logic — all logic lives in the
 *  other .c files.
 * ============================================================
 */

#include "employee.h"
struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

int main() {
    int choice;

    loadFromFile();  

    do {
        printf("\n\t\t\t\t\t\t\tEmployee Management System\n");
        printf("\t\t\t\t\t\t\t----------------------------------\n");
        printf("\t\t\t\t\t\t\t1. Add Employee\n");
        printf("\t\t\t\t\t\t\t2. Display Employees\n");
        printf("\t\t\t\t\t\t\t3. Change Employee\n");
        printf("\t\t\t\t\t\t\t4. Delete Employee\n");
        printf("\t\t\t\t\t\t\t5. Export Employees to File\n");
        printf("\t\t\t\t\t\t\t6. Search Employee\n");
        printf("\t\t\t\t\t\t\t7. Exit\n");
        printf("\t\t\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1: addEmployee();      break;
            case 2: displayEmployees(); break;
            case 3: modifyEmployee();   break;
            case 4: deleteEmployee();   break;
            case 5: exportEmployees();  break;
            case 6: searchEmployee();   break;
            case 7:
                logAction("EXIT", "Program exited normally");
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7);

    return 0;
}

// #include "employee.h"
// Brings in your header file. This gives main.c access to the Employee struct, all constants like MAX_EMPLOYEES, and all function names like addEmployee(), loadFromFile() etc.

// cstruct Employee employees[MAX_EMPLOYEES];
// Creates the array that holds all employee records in RAM. Think of it as a table with 100 rows — each row is one employee. MAX_EMPLOYEES = 100 is defined in employee.h.

// cint numEmployees = 0;
// A counter that tracks how many employees are currently stored. Starts at 0. Goes up by 1 every time you add someone, down by 1 when you delete.

// cint main() {
// Every C program starts here. This is the entry point — the first function the computer runs.

// cint choice;
// Declares a variable to store whatever number the user types in the menu (1 through 7).

// cloadFromFile();
// Before showing the menu, load any previously saved data from employees.dat. So if you added employees yesterday, they appear again today.

// cdo {
// Start of a do-while loop. The menu will keep showing again and again until the user picks 7 (Exit). The do means it always runs at least once.

// cprintf("\n\t\t\t\t\t\t\tEmployee Management System\n");
// printf("\t\t\t\t\t\t\t----------------------------------\n");
// Prints the menu title and a divider line. The \t is a tab character — used here to push the text to the centre of the screen. \n moves to the next line.

// cprintf("\t\t\t\t\t\t\t1. Add Employee\n");
// printf("\t\t\t\t\t\t\t2. Display Employees\n");
// printf("\t\t\t\t\t\t\t3. Change Employee\n");
// printf("\t\t\t\t\t\t\t4. Delete Employee\n");
// printf("\t\t\t\t\t\t\t5. Export Employees to File\n");
// printf("\t\t\t\t\t\t\t6. Search Employee\n");
// printf("\t\t\t\t\t\t\t7. Exit\n");
// Prints each menu option on its own line. These are just display — no logic here.

// cprintf("\t\t\t\t\t\t\tEnter your choice: ");
// Prints the prompt asking the user to type a number. No \n at the end — so the cursor stays on the same line waiting for input.

// cscanf("%d", &choice);
// Reads the number the user typed and stores it in choice. %d means expect an integer. &choice means "store it at the memory address of choice".

// cclearBuffer();
// After scanf, a leftover \n (Enter key) stays in the input buffer. This function flushes it out so the next input (like fgets for a name) works correctly. Defined in utils.c.

// cswitch (choice) {
// Checks what number the user typed and jumps to the matching case. Cleaner than writing many if / else if statements.

// ccase 1: addEmployee();      break;
// case 2: displayEmployees(); break;
// case 3: modifyEmployee();   break;
// case 4: deleteEmployee();   break;
// case 5: exportEmployees();  break;
// case 6: searchEmployee();   break;
// Each case calls the matching function from employee_operations.c or file_handler.c. The break exits the switch so it doesn't fall through to the next case.

// ccase 7:
//     logAction("EXIT", "Program exited normally");
//     printf("Exiting program...\n");
//     break;
// When the user picks 7 — writes one final line to activity_log.txt, prints a goodbye message, then break exits the switch. The while condition below will then also become false and the loop ends.

// cdefault:
//     printf("Invalid choice! Please enter a number between 1 and 7.\n");
// If the user types anything other than 1–7 (like 9 or 0), this catches it and prints an error. The menu then shows again.

// c} while (choice != 7);
// Loop condition — keep repeating the whole menu as long as choice is not 7. The moment the user picks 7, the loop stops and the program ends.

// creturn 0;
// Tells the operating system the program finished successfully. 0 means no errors. This is standard for every C program.

// Big picture — how it all flows
// Program starts
//       ↓
// loadFromFile()  ← load saved data
//       ↓
// Show menu  ←─────────────────┐
//       ↓                      │
// User types number             │
//       ↓                      │
// switch → call function        │
//       ↓                      │
// choice != 7? ────── YES ──────┘
//       │
//      NO
//       ↓
// Program ends (return 0)You said: explain in  nepali n english mixed while presenting codeexplain in  nepali n english mixed while presenting code10:58 PMClaude responded: main.main.c — Line by Line Explanation

