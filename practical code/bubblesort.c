// 🧠 Algorithm: Bubble Sort

// Step 1: Start

// Step 2: Declare an array arr[] and an integer variable n.

// Step 3: Input the number of elements n.

// Step 4: Input all n elements into the array arr[].

// Step 5: Repeat the following process to sort the array:
//   For i = 0 to n - 2
//    For j = 0 to n - i - 2
//     If arr[j] > arr[j + 1]
//      → Swap arr[j] and arr[j + 1].
//      (Using a temporary variable temp.)

// Step 6: After all passes, the array is sorted in ascending order.

// Step 7: Print the sorted array.

// Step 8: Stop

#include<stdio.h>

void Bubblesort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){// compare first two element 
            if(arr[j] > arr[j+1]){
                // swap the element 
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int arr[1000], n;
   // size of element 
    printf("Enter the size of element the array: ");
    scanf("%d", &n);

   //  enter the element 
   printf("Enter the element the array:");
   for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
   }

   // sort the array
   Bubblesort(arr , n);

   //print the sorted array
   printf("Sorted array:");
   for(int i = 0; i < n; i++){
    printf("%d", arr[i]);
}
return 0;

}