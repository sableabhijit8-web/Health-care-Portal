
#include<iostream>
#include<string>
Using namespace std;

class person{
public:
string name;
int age;

person(string name , int age){
    this->name = name;
    this-> age = age;
}
class student: public person 
{
}