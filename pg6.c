#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct student {
    char name[20];
    char USN[10];
};

struct stack {
    struct student stud[SIZE];
    int top; // Keeps track of the top of the stack
};

void push(struct stack *ps, struct student st1);
struct student pop(struct stack *ps);

void main() {
    struct stack s;
    struct student st1, rt1;
    int choice, i;
    s.top = -1; // Initialize stack as empty

    do {
        printf("\n1:PUSH\t2:POP\t3:DISPLAY\t4:QUIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter the name and USN of student to push: ");
                scanf("%s %s", st1.name, st1.USN);
                push(&s, st1); // Push the student onto the stack
                break;
            
            case 2: 
                rt1 = pop(&s); // Pop the top student from the stack
                printf("The student popped is %s with USN %s\n", rt1.name, rt1.USN);
                break;
            
            case 3: 
                if(s.top == -1) 
                    printf("\nStack empty");
                else {
                    printf("Stack contents are:\n");
                    for(i = s.top; i >= 0; i--) { // Display all elements in the stack
                        printf("%s %s\n", s.stud[i].name, s.stud[i].USN);
                    }
                }
                break;
            
            case 4: 
                printf("QUITTING OPERATION STACK ..........\n");
                break;
            
            default: 
                printf("No such option\n");
        }
    } while(choice != 4); // Exit when the user chooses to quit
}

void push(struct stack *ps, struct student st1) {
    if(ps->top == SIZE - 1) { // Check for stack overflow
        printf("Stack Overflow\n");
    } else {
        ++(ps->top); // Move to the next position
        strcpy(ps->stud[ps->top].name, st1.name); // Copy name
        strcpy(ps->stud[ps->top].USN, st1.USN); // Copy USN
    }
}

struct student pop(struct stack *ps) {
    struct student r;
    if(ps->top == -1) { // Check for stack underflow
        printf("\nStack Underflow");
        exit(1);
    }
    r = ps->stud[ps->top]; // Retrieve the top element
    (ps->top)--; // Decrease the stack top
    return r; // Return the popped student
}
