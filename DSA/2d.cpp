 #include<iostream>
 using namespace std;


 int main(){
    // create a 2D array
    int arr[3][4];

    // taking a input -> row wise input
    for(int row=0; row<3; row++){
        for(int col = 0; col<4; col++){
            cin>>arr[row][col];
        }
    }


    //print kaise kare
     for(int row=0; row<3; row++){
        for(int col = 0; col<4; col++){
            cout<< arr[row][col]<<endl;
        }
        cout<<endl;
    }
   return 0;

 }