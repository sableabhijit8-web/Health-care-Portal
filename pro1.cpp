#include<iostream>
using namespace std;


void printArray(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";

    }cout<<endl;
}
void sortOne(int arr[],int n){
  int low = 0, mid=0, high= n-1;
     

   while (mid <= high)
   {
    if(arr[mid]==0){
        swap(arr[low],arr[mid]);
        low++;
        mid++;
    }
    else if (arr[mid]==1){
        mid++;
    }
    else{
        swap(arr[mid],arr[high]);
        high--;
    }
    
   }
}




int main (){
 int arr[19] = {0,1,2,0,1,2,0,1,1,1,1,2,2,2,2,0,0,0,1};

 sortOne(arr,19);
 printArray(arr,19);
}