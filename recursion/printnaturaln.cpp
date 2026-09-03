#include<iostream>
using namespace std;

void print(int i,int n){
    // base cas
   if(i > n){
    return;
   }
   print(i+1,n);
   cout<<i<<endl;
}
int main(){
    int n; 
    cout<<"Enter your number";
    cin>>n;
    print(1,n);
}