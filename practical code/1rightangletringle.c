// Algorithm: Display Right Angle Triangle

// Step 1: Start
// Step 2: Initialize variables — e.g., i, j, and n (number of rows).
// Step 3: Set the value of n (for example, n = 5).
// Step 4: Repeat steps for i = 1 to n:
//   a. For each row i, print i number of * symbols.
//   b. Move to the next line after inner loop ends.
// Step 5: Stop
#include<stdio.h>

int main(){
    int i, j, row;
    printf("Enter your row here:");
    scanf("%d", & row);
    for(int i=1; i<=row; i++){
      for(int j=1; j<i; j++){
        printf("%d", j);
      }
      printf("\n");
    }
    return 0;
}