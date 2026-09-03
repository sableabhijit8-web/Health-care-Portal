// // vector हा STL container आहे
// // vector dynamic array आहे जो runtime ला grow आणि shrink होऊ शकतो
// #include<iostream>
// #include<vector>
// using namespace  std;

// // void explainvector(){
// //     // create a vector
// //     vector<int> v;
// //     // add element in vector
// //     v.push_back(1); //{1}
// //     v.emplace_back(2); //{1,2}

// //     // print vector
// //     for(int i=0; i<v.size(); i++){ 
// //     cout<<v[i]<<endl; 
// // }


// //     // pair of vector
// //     vector<pair<int, int>> vec;
// //     vec.push_back({1,2});
// //     vec.emplace_back(1,2);

// //      // print vector of pairs
// //     for(int i = 0; i < vec.size(); i++) {
// //         cout << vec[i].first << " " << vec[i].second << endl;
// //     }
// //     // multiple element vector 
// //     vector<int> v3(5,100);//{100,100,100,100,100}
// //      for(int i = 0; i < v3.size(); i++) {
// //         cout << v3[i] << endl;
// //     }
// //     // vector<int> v4(5)//{0,0,0,0,0}
// //     //  for(int i=0; i<v4.size(); i++){ 
// //     // cout<<v4[i]<<endl; 
// //     // vector<int> v1(5,20)
// //     // vector<int> v2(v1); // this create a copy of the v1
// // }
// // void vectoriterator(){
// //     // vector<int>::iterator it = v.end();// its point to the address of the node
// //     // it++;// increment by one
// //     // cout<<*(it)<<" ";// bcz of the * noe it point to the node value

// //     // vector<int>::itrator it = v.end();// itpont to thr last element of the vector
// //     // vector<int>::itrator it = v.rend();//think in reverse manner
// //     // vector<int>::itrator it = v.rbegin();// htinlk in reverse manner

// //     // cout <<v[0] <<" "< v.at(0);// access the 0th index
// //     // cout<< v.back() <<" "; // pont to yhe last element 


// //     for(vector<int>iterator:: it = v.begin(); it!=v.end(); it++){
// //         cout<<*(it) <<" ";
// //     }
// //     //OR
// //     for(auto it = v.begin(); it != v.end(); it++){
// //         cout<<*(it)<<" ";
// //     }
// //     //or
// //     for(auto it : v){
// //         cout<<it<<endl;
// //     }

// // // erase onr element form the vector{10,20,30,40}
// // v.erase(v.begin()+1);//{10.30,40}

// // // erase multiple element {10,20,30,40,50}
// // v.erase(v.begin()+2,v.begin()+4)//{{10,20,50}}
// // }


// // insertion in vector
// void insertion(){
//     vector<int> v(2,50);//{50,50}
//     v.insert(v.begin(),300); //{100,50,50}
//     v.insert(v.begin()+1,2,10);//{300,10,10.,50, 50}
// }

// //{10,20}
// cout<<v.size();//2

// //{10,20}
// v.pop_back();//{10}

// //v1 = {10,20}
// //v2 = {30,40}

// v1.swap(v2)// therefore v1 = {30,40} and v2 = {10,20}

// v.clear()// clear all the vector

// cout<<v.empty()

// int main(){
//      explainvector();
//      vectoriterator();
//      insertion();

// }