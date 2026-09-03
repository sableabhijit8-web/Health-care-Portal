 #include<iostream>
 using namespace std;

class Teacher
{
private:
   double salary;
public:
   string name;
   string dept;
   string subject;
   

   void changeDept(string newDept){
    dept = newDept;
   }
   void setSalary(double s){
         salary = s;
   }

   double getSalary(){
    return salary;
   }

};

int main (){
    Teacher t1; // automatically call constructor ...
    t1.name = "abhijit";
    t1.subject = "c++";
    t1.dept = "Electonics and Telecommunication";
    t1.setSalary(500000) ;

    cout<< t1.name<< endl;
    cout<< t1.getSalary()<<endl;

    return 0;
}
