#include<iostream>
using namespace std;



void printArray(int arr[],int n){

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}


void swapAlternative(int arr[],int size, int temp){

    for(int i = 0; i<size; i+=2){
      if(i+1 < size){
         swap(arr[i],arr[i+1]);
      }
   }
}




int main() {
    int even[8] = {1,2,3,4,5,6,7,8};
    int odd[5] = {1,2,3,4,5};

    swapAlternative(even,8,2);
    printArray(even,8);

    cout<<endl;

    swapAlternative(odd,5,2);
    printArray(odd,5);

    return 0;
}




