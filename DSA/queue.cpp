 #include<iostream>
 #include<queue>
 using namespace std;
 
 int main(){
    // create a queue
    queue<int> q;
    q.push(17);
    q.push(20);
    q.push(23);
    q.push(30);
    q.pop();
    q.pop();
    q.pop();
    cout<<"size odf queue :"<<q.size()<<endl;

    if(q.empty()){
        cout<<"queue is empty "<<endl;
    }
    else{
        cout<< " queue is not empty"<<endl;
    }
   cout<<" first element  :"<<q.front()<<endl;
 }