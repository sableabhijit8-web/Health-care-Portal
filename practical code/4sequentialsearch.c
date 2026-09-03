// Algorithm: Sequential Search

// Step 1: Start
// Step 2: Input number of elements n
// Step 3: Input n elements into array arr[]
// Step 4: Input the element to search (target)
// Step 5: For each index i = 0 to n - 1
//   If arr[i] == target, then
//    Print "Element found at index i" and stop
// Step 6: If the loop finishes without finding the element,
//   Print "Element not found"
// Step 7: Stop

#include<stdio.h>

int SequentialSearch(int arr[], int n , int target){

    for(int i=0; i<=n; i++){
     if(arr[i] == target)
     return i;
    }
    return -1;
}
int main(){
    int arr[1000];
    int n, target;
    
    // how many element are present in the arry giving by the user
    printf("How many element present in the array: ");
    scanf("%d", &n);

    // take a element form the user
    printf("Enter element in array: ");
    for(int i=0; i<=n; i++){
      scanf("%d", &arr[i]);
    }
    //take a taget form user
     printf("Enter element to search: ");
    scanf("%d", &target);

    int result = SequentialSearch(arr, n, target);

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}

