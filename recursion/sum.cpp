#include<iostream>
using namespace std;

long long fact(long long n){
   // base case
   if( n == 0 || n == 1) return 1;
   return n * fact(n-1);
}
int main(){
    long long n;
    cout<<"Enter you number"<<endl;
    cin >> n;
    cout << fact(n);
    return 0;
}