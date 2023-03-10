#include <iostream>
#include <fstream>

using namespace std;

class Student{
    public:
    string name;
    int roll;
    string branch;

    //for overloading friend function is used

    friend ofstream & operator<<(ofstream &ofs,Student &s);
    friend ifstream & operator>>(ifstream &ifs, Student &s);

};
ofstream & operator<<(ofstream &ofs,Student &s){
    ofs<<s.name<<endl;
    ofs<<s.roll<<endl;
    ofs<<s.branch<<endl;
    return ofs;
}

ifstream & operator>>(ifstream &ifs, Student &s){
    ifs>>s.name>>s.roll>>s.branch;
    return ifs;
}
int main(){
    Student s1;
    s1.name = "Anchit";
    s1.roll = 1;
    s1.branch = "CS";

    ofstream ofs("Student.txt",ios::trunc);
    ofs<<s1;
    ofs.close();

    ifstream ifs("Student.txt");
    ifs>>s1;

    cout<<"Name: "<<s1.name<<endl;
    cout<<"RollNO: "<<s1.roll<<endl;
    cout<<"Branch: "<<s1.branch<<endl;

    ifs.close();

    cout<<hex<<163;
}