// Algorithm: Display Pyramid Pattern using Stars

// Step 1: Start
// Step 2: Set a fixed value of n (for example, n = 5)
// Step 3: Repeat steps for each row i from 1 to n
//   a. Print (n - i) spaces
//   b. Print i stars (for the left side)
//   c. Print (i - 1) stars (for the right side)
//   d. Move to the next line
// Step 4: Stop

#include <stdio.h>

int main() {
    int n ;
    printf("Enter your number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        // spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // increasing numbers
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        // decreasing numbers
        for (int j = i - 1; j >= 1; j--) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
