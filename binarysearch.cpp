#include<iostream>
using namespace std;


int binarysearch(int arr[],int size,int key){
    int start = 0;
    int end = size-1;

    int mid = start + (end-start/2);

    while (start <= end)
 
    {
      if (arr[mid] == key)
      {
        return mid;
      }
         
      if (arr[mid] <  key)
      {
        start = mid+1;

      }
      else {
        end = mid-1;
      }
      
      mid = start+(end-start/2);
    }
    return -1;
}



int main(){
      int even[8] = {2,4,6,8,10,12,30,22};
      int odd[6] = {1,3,5,7,9,11};

      int evenindex = binarysearch(even,8,20);

      cout<<"index of 8 is "<< evenindex <<endl;

      int oddindex = binarysearch(odd,6,20);

      cout << "index of 7 is "<< oddindex << endl;
}