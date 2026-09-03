#include<stdio.h>

void selectionsort(int arr[], int n){
   for (int i = 0; i < n - 1; i++) {
        int smallindex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallindex]) { // Find smaller element
                smallindex = j;
            }
        }

        // Swap arr[i] and arr[smallindex]
        int temp = arr[i];
        arr[i] = arr[smallindex];
        arr[smallindex] = temp;
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
   selectionsort(arr , n);

   //print the sorted array
   printf("Sorted array:");
   for(int i = 0; i < n; i++){
    printf("%d", arr[i]);
}
return 0;

}
