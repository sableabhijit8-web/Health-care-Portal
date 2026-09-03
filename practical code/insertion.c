#include<stdio.h>

void insertionsort(int arr[], int n){
    for(int i=0; i<n-1; i++){
      int curr = arr[i];
      int prev = i-1;

      while (prev >= 0 && arr[prev] > curr){
       arr[prev+1] = arr[prev];
        prev--;
      }
     arr[prev+1] = curr;
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
   insertionsort(arr , n);

   //print the sorted array
   printf("Sorted array:");
   for(int i = 0; i < n; i++){
    printf("%d", arr[i]);
}
return 0;

}