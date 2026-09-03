 #include<iostream>
 using namespace std;

class  Student {
public:
   string name;
   double* cgpaPtr;

    Student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;

    }

    Student(Student &obj){
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;

    }
    void getinfo(){
        cout<<"name : "<<name<<endl;
         cout<<"cgpa : "<<*cgpaPtr<<endl;
    }
};






 int main(){

    Student s1("Abhijit sable",8.45);
    Student s2(s1);

    s1.getinfo();
    *(s2.cgpaPtr) = 9.2;
    s1.getinfo();

    s2.name = "vivek"
    s2.getinfo();
    return 0;
 }