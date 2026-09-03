#include <stdio.h>
#include <string.h>  // Needed for strcmp()

int main() {
    char names[100][50]; // 100 names, each up to 49 characters + null terminator
    int n;
    char key[50];
    printf("Enter number of names: ");
    scanf("%d", &n);
    printf("Enter %d names:", n);
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]); // Reads each name
    }
    printf("Enter name to search: ");
    scanf("%s", key);   
    for(int i = 0; i < n; i++) {
        if(strcmp(names[i], key) == 0) { // Use strcmp to compare strings
            printf("Name found at index %d", i);
            return 0;
        }
    }
    printf("Name not found");
    return 0;
}
