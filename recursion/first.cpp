#include<iostream>
using namespace std;
int cnt = 0;
void print(){
    // base case
    if(cnt == 5){
        return;
    }
    cout<< "abhijit" <<endl;
    cnt++;
    // recrsion call
    print();
}
int main(){
    print();
}
