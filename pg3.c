#include <stdio.h>

/* Function to copy string s2 to s1 */
void strcopy(char *s1, char *s2) {
    while (*s2 != '\0') {
        *s1 = *s2; // Copy each character from s2 to s1
        s1++;
        s2++;
    }
    *s1 = '\0'; // Null-terminate the destination string
}

/* Function to compare two strings s1 and s2 */
int strcomp(char *s1, char *s2) {
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2) {
            return (*s1 - *s2); // Return difference if characters mismatch
        }
        s1++;
        s2++;
    }
    return 0; // Strings are equal
}

/* Function to concatenate s2 to the end of s1 */
void strconcat(char *s1, char *s2) {
    while (*s1 != '\0') {
        s1++; // Move to the end of s1
    }
    while (*s2 != '\0') {
        *s1 = *s2; // Append each character of s2 to s1
        s1++;
        s2++;
    }
    *s1 = '\0'; // Null-terminate the resulting string
}

/* Function to reverse a string */
void Strreverse(char *s1) {
    int len = 0;
    char *start = s1, temp;
    
    // Find the length of the string
    while (*s1 != '\0') {
        s1++;
        len++;
    }
    s1--; // Move to the last character

    // Reverse the string in-place
    for (int i = 0; i < len / 2; i++) {
        temp = *start;  // Swap characters
        *start = *s1;
        *s1 = temp;

        start++;
        s1--;
    }
}

/* Main function demonstrating the string operations */
int main() {
    char s1[80], s2[80], t1[80];
    int choice, result;

    printf("Enter 2 strings:\n");
    fgets(s1, sizeof(s1), stdin); // Read string 1
    fgets(s2, sizeof(s2), stdin); // Read string 2

    strcopy(t1, s1); // Backup original string s1

    printf("---------MENU-----------\n");
    printf("1. Compare strings\n");
    printf("2. Copy string\n");
    printf("3. Concatenate strings\n");
    printf("4. Reverse strings\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcopy(s1, t1); // Restore original s1
                result = strcomp(s1, s2);
                if (result > 0) {
                    printf("%s is greater than %s\n", s1, s2);
                } else if (result < 0) {
                    printf("%s is greater than %s\n", s2, s1);
                } else {
                    printf("Strings are equal\n");
                }
                break;

            case 2:
                strcopy(s1, t1); // Restore original s1
                printf("Strings before copying: s1=%s, s2=%s\n", s1, s2);
                strcopy(s1, s2); // Copy s2 into s1
                printf("After copying: s1=%s, s2=%s\n", s1, s2);
                break;

            case 3:
                strcopy(s1, t1); // Restore original s1
                printf("Strings before concatenation: s1=%s, s2=%s\n", s1, s2);
                strconcat(s1, s2); // Concatenate s2 to s1
                printf("After concatenation: s1=%s, s2=%s\n", s1, s2);
                break;

            case 4:
                strcopy(s1, t1); // Restore original s1
                printf("Strings before reversing: s1=%s, s2=%s\n", s1, s2);
                printf("Strings after reversing:\n");
                Strreverse(s1); // Reverse s1
                printf("s1=%s\n", s1);
                Strreverse(s2); // Reverse s2
                printf("s2=%s\n", s2);
                break;

            default:
                printf("Invalid choice. Exiting program.\n");
                return 0; // Exit program
        }
    }
}
