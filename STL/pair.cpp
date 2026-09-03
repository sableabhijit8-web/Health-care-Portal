#include<iostream>
using namespace  std;
void explainpair(){
    pair<int, int> p1 = {1,3};
    cout << p1.first<<" "<<p1.second;

    cout<<endl;

    pair<int, pair<int,int>> p2 = {1,{2,3}};
    cout<<p2.first << " " << p2.second.second<<" "<<p2.second.first<< endl;
    
    pair<int, int> arr[] = {{1,2},{2,5},{5,1}};
    cout<<arr[2].second;
}
int main(){
    explainpair();

}