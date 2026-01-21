#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    int age;
    float marks;

public:
    // Default Constructor
    Student() : rollNo(0), name(""), age(0), marks(0.0) {}

    // Parameterized Constructor
    Student(int r, string n, int a, float m) : rollNo(r), name(n), age(a), marks(m) {}

    // Setters
    void setRollNo(int r)
    {
        rollNo = r;
    }

    // Getter
    int getRollNo() const
    {
        return rollNo;
    }

    // Input Function
    void inputData()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Marks: ";
        cin >> marks;
        cin.ignore();
    }

    // Display Function
    void displayData() const
    {
        cout << "Roll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        cout << "Age     : " << age << endl;
        cout << "Marks   : " << marks << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    const int SIZE = 3;
    Student students[SIZE];

    cout << "===== ENTER STUDENT RECORDS =====\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Student " << i + 1 << endl;
        students[i].inputData();
        cout << endl;
    }
    // Pointer

    Student *ptr = students;
    int searchRoll;
    cout << "Enter Roll Number to Search: " << endl;
    cin >> searchRoll;
    cin.ignore();
    // Considering that initially record not found
    bool searchStatus = false;
    for (int i = 0; i < SIZE; i++)
    {
        if ((ptr + i)->getRollNo() == searchRoll)
        {
            cout << "Record Found:\n";
            (ptr + i)->displayData();
            searchStatus = true;
            break;
        }
    }
    if (!searchStatus)
    {
        cout << "Record not found!\n";
    }

    cout << "\n===== DISPLAYING STUDENT RECORDS =====\n\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Student " << i + 1 << endl;
        students[i].displayData();
    }

    return 0;
}
