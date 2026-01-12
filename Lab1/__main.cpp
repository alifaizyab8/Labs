#include <iostream>
#include <string>
using namespace std;

class student
{
    string name;
    int roll;
    int quiz[3];

public:
    void setName()
    {   cout << "Enter Student name: ";
        cin >> name; }
    void setRoll()
    {   cout << "Enter Student Roll Number: ";
        cin >> roll; }
    void setQuiz()
    {   for (int i = 0; i < 3; i++) {
            cout << "Quiz " << i + 1 << ": ";
            cin >> quiz[i];
        } }
    void getName() { cout << "Student name: " << name << endl; }
    void getRoll() { cout << "Roll number: " << roll << endl; }
    void getQuiz()
    {   for (int i = 0; i < 3; i++)
            cout << "Quiz " << i + 1 << ": " << quiz[i] << endl; }
    void printStudent()
    {   getName();
        getRoll();
        getQuiz(); }
};

int main()
{   student s1;
    s1.setName();
    s1.setRoll();
    s1.setQuiz();
    s1.printStudent();
    return 0; }
