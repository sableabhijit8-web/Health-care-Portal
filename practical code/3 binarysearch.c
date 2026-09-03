// Algorithm: Binary Search

// Step 1: Start

// Step 2: Declare an array arr[], and variables n (size of array) and k (element to search).

// Step 3: Input the number of elements n.

// Step 4: Input n elements of the array in sorted order (ascending).

// ⚠️ Binary Search only works on sorted arrays.

// Step 5: Input the target element k (the number to search).

// Step 6: Initialize
//   start = 0 and end = n - 1.

// Step 7: Repeat while start <= end:
//   a. Calculate mid = start + (end - start) / 2.
//   b. If arr[mid] == k, return mid (element found).
//   c. Else if arr[mid] < k, set start = mid + 1.
//   d. Else, set end = mid - 1.

// Step 8: If the loop ends and element not found, return -1.

// Step 9: Display the result:
//   If result ≠ -1 → print “Element found at index result”.
//   Else → print “Element not found”.

// Step 10: Stop


#include<stdio.h>

int Binarysearch(int arr[], int n, int k){
int start = 0, end = n-1;

while(start <= end){
    int mid = start + (end-start)/2;
    // if k is present at the mid element
    if(arr[mid] == k){
        return mid;
    }
    // if mid is less than the k
    else if(arr[mid] < k){
        start = mid+1;
    }
    // if mid is grater than k
    else{
        end = mid-1;
    }
}
return -1;
}
int main(){
   int arr[1000];
   int n, k;
// take a how many element is present in the array form user
   printf("Enter the number of element in array:");
   scanf("%d", &n);
// take elements array form user
   printf("Enter the element: ");
   for(int i=0; i<n; i++){
   scanf("%d", &arr[i]);
   }
   //take a target form user
   int k;
   printf("enter the k");
   scanf("%d", &k);
// function call
   int result = Binarysearch(arr , n , k);
   if(result != -1){
    printf("Element found at index %d\n", result);
   }
   else{
     printf("Element is not found %d\n", result);
   }

   return 0;

}