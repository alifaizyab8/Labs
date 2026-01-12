#include <iostream>
#include <string>
#include <vector>
using namespace std;
class student
{
    string name;
    int roll;
    int quiz[3];

public:
    // Setters for individual properties
    void setName()
    {
        cout << "Enter Student name : " << endl;
        cin >> name;
    }
    void setRoll()
    {
        cout << "Enter Student Roll Number : " << endl;
        cin >> roll;
    }
    void setQuiz()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Quiz " << i + 1 << ": " << endl;

            cin >> quiz[i];
        }
    }
    // Getters for Individual Properties
    void getName()
    {
        cout << "Student name: " << name << endl;
    }
    void getRoll()
    {
        cout << "Roll number: " << roll << endl;
    }
    void getQuiz()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "Quiz " << i + 1 << ": " << quiz[i] << endl;
        }
    }
    // Printing Function
    void printStudent()
    {
        getName();
        getRoll();
        getQuiz();
    }
};

int main()
{
    student s1;
    s1.setName();
    s1.setRoll();
    s1.setQuiz();
    s1.printStudent();
    return 0;
}