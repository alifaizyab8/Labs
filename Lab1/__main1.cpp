#include <iostream>
#include <string>
using namespace std;

class student
{
    string name;
    int roll;
    int quiz[3];

public:
    void setName();
    void setRoll();
    void setQuiz();
    void getName();
    void getRoll();
    void getQuiz();
    void printStudent();
};

void student::setName()
{
    cout << "Enter Student name : " << endl;
    cin >> name;
}

void student::setRoll()
{
    cout << "Enter Student Roll Number : " << endl;
    cin >> roll;
}

void student::setQuiz()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Quiz " << i + 1 << ": " << endl;
        cin >> quiz[i];
    }
}

void student::getName()
{
    cout << "Student name: " << name << endl;
}

void student::getRoll()
{
    cout << "Roll number: " << roll << endl;
}

void student::getQuiz()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Quiz " << i + 1 << ": " << quiz[i] << endl;
    }
}

void student::printStudent()
{
    getName();
    getRoll();
    getQuiz();
}

int main()
{
    student s1;
    s1.setName();
    s1.setRoll();
    s1.setQuiz();
    s1.printStudent();
    return 0;
}
