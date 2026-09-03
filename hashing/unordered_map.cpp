#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_map<int,int> mpp;

    // Input and frequency counting
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mpp[x]++;
    }

    // Print frequency (sorted order)
    for(auto it : mpp){
        cout << it.first << " -> " << it.second << endl;
    }

    int q;
    cin >> q;

    while(q--){
        int number;
        cin >> number;

        // Safe fetching (no unwanted insertion)
        if(mpp.find(number) != mpp.end()){
            cout << mpp[number] << endl;
        }
        else{
            cout << 0 << endl;
        }
    }

    return 0;
 }