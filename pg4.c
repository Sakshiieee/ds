#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
    char emp_name[20];
    int emp_id;
    char dept_name[20];
    float salary;
};

// Function to compute the total salary of a department
void compute_total_sal(struct employee *e, char dn[], int m);

void main() {
    int m, i;
    struct employee *emp; // Pointer to dynamically allocate memory for employees
    char dname[20], choice;

    printf("Enter the number of employees: ");
    scanf("%d", &m);

    // Allocate memory for 'm' employee structures
    emp = (struct employee *)malloc(m * sizeof(struct employee));

    // Read employee details
    for (i = 0; i < m; i++) {
        printf("Enter the details of Employee %d\n", i + 1);
        printf("Enter the employee name: ");
        scanf("%s", &(emp + i)->emp_name);
        printf("Enter the employee ID: ");
        scanf("%d", &(emp + i)->emp_id);
        printf("Enter the employee department: ");
        scanf("%s", &(emp + i)->dept_name);
        printf("Enter the salary of employee: ");
        scanf("%f", &(emp + i)->salary);
    }

    // Print employee details
    printf("************************Employee Details************************\n");
    printf("%-15s%-25s%-15s%-15s\n", "ID", "EMPLOYEE NAME", "DEPARTMENT", "SALARY");
    for (i = 0; i < m; i++) {
        printf("%-15d%-25s%-15s%-15.2f\n", 
            (emp + i)->emp_id, (emp + i)->emp_name, (emp + i)->dept_name, (emp + i)->salary);
    }

    // Loop to calculate total salary for specified department
    do {
        printf("\nEnter the department for which the total salary has to be computed: ");
        scanf("%s", dname);
        compute_total_sal(emp, dname, m); // Call function to compute salary
        printf("\nDo you want to continue [Y/N]: ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    // Free allocated memory
    free(emp);
}

// Function to compute total salary of a department
void compute_total_sal(struct employee *e, char dn[], int m) {
    float totalsal = 0;
    int i, flag = 0;

    // Iterate through all employees
    for (i = 0; i < m; i++) {
        if (strcmp((e + i)->dept_name, dn) == 0) { // Match department name
            flag = 1;
            totalsal += (e + i)->salary; // Add salary to total
        }
    }

    if (flag == 0) {
        printf("\nNo such department\n");
    } else {
        printf("\nTotal salary of employees in department %s is %.2f\n", dn, totalsal);
    }
}
