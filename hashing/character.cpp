#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;


    // for count we use
    // for lower(26) case ch-'a'
    // for upper casr(26) ch -"A"
    // and for all character using hashing array 256
    int hash[25] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i]-'a']++;
    }

    int q;
    cin>>q;
    while (q--){
        char c;
        cin>>c;

        // featch
        cout<<hash[c-'a']<<endl;
        
    }
}