#include<iostream>
#include<string>
using namespace std;
//Encapsulaion
class Teacher{
    //Access modifier
    private:
    double salary;
    //protected:
    public:
    //properties or attribures
    string name;
    string dept;
    string subject;
 

    //methods or member function
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

int main(){
    Teacher t1;
    t1.name = "Tejbir Singh";
    t1.dept = "Instrumentation and Control with Tech";
    t1.subject = "Competitive programming";
    //t1.salary = 82000000;
    t1.setSalary(80000000);
    cout <<   t1.getSalary() << endl;
    cout << "Name: " << t1.name << endl;
    cout<< "Subject: " << t1.subject << endl;

    return 0;
}