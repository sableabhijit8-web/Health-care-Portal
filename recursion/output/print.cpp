#include<iostream>
using namespace std;

void print(int i,int n){
    // base cas
   if(i > n){
    return;
   }
   cout<<"abhijit"<<endl;
   print(i+1,n);
}
int main(){
    int n; 
    cout<<"How many time do you want to print the name";
    cin>>n;
    print(1,n);
}