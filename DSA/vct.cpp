 #include<iostream>
 #include<vector>

 using namespace std;

 int main(){
    vector<int> vec = {'a','b','c'};

    cout<< "size"<<vec.size()<<endl;

    for(char val : vec){
        cout<<val<<endl;
    }
    return 0;
 }
