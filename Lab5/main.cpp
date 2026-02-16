#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Student
{
private:
    char *Name;
    int Rollno;
    double Marks[5];
    float Percentage;

public:
    // Default Constructor
    Student()
    {
        Name = new char[32];
        cout << "Please enter name: ";
        cin.getline(Name, 32);
        cout << "Please enter Roll Number: ";
        cin >> Rollno;
        cin.ignore();
        for (int i = 0; i < 5; i++)
        {
            cout << "Please enter Marks of test " << i + 1 << ": ";
            cin >> Marks[i];
        }
        cin.ignore();
        // Calculate initial percentage based on standard 500
        calculatePercentage();
    }

    // Parameterized Constructor
    Student(char *n, int r, double arr[5]) : Rollno(r)
    {
        Name = new char[32];
        strcpy(Name, n);
        copy(arr, arr + 5, Marks);
        calculatePercentage();
    }

    // Copy Constructor
    Student(const Student &s)
    {
        Name = new char[32];
        strcpy(Name, s.Name);
        Rollno = s.Rollno;
        copy(s.Marks, s.Marks + 5, Marks);
        Percentage = s.Percentage;
    }

    virtual ~Student()
    {
        delete[] Name;
    }

    // Getters
    const char *getName() const
    {
        return Name;
    }
    int getRollNumber() const
    {
        return Rollno;
    }
    const double *getMarks() const
    {
        return Marks;
    }
    float getPercentage() const
    {
        return Percentage;
    }

    // Setters
    void setPercentage(float p)
    {
        Percentage = p;
    }

    // Virtual
    virtual void calculatePercentage()
    {
        double total = 0;
        for (double x : Marks)
        {
            total += x;
        }
        Percentage = (total / 500.0) * 100;
    }

    void Grade()
    {

        calculatePercentage();

        cout << "Percentage: " << Percentage << "%\n";
        if (Percentage >= 80)
            cout << "Grade is A\n";
        else if (Percentage >= 70)
            cout << "Grade is B\n";
        else
            cout << "Grade is C\n";
    }

    double highestMarks()
    {
        double high = Marks[0];
        for (double x : Marks)
        {
            if (x > high)
                high = x;
        }
        return high;
    }

    virtual void display()
    {
        cout << "\n--- Student Details ---\n";
        cout << "Name: " << Name << endl;
        cout << "Roll No: " << Rollno << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Test " << i + 1 << ": " << Marks[i] << endl;
        }
        cout << "Highest Score: " << highestMarks() << endl;
        Grade();
    }
};

class ScienceStudent : public Student
{
public:
    // 1. Default Constructor
    ScienceStudent() : Student() {}

    // Overriding Base class
    void calculatePercentage() override
    {
        double total = 150; // Extra science marks
        const double *m = getMarks();
        for (int i = 0; i < 5; i++)
        {
            total += m[i];
        }
        setPercentage((total / 650.0) * 100);
    }

    void display() override
    {
        cout << "Science Student Record\n";
        Student::display();
    }
};

class ArtStudent : public Student
{
public:
    // 1. Default Constructor
    ArtStudent() : Student() {}

    // Overriding Base class
    void calculatePercentage() override
    {
        double total = 100; // Extra art marks
        const double *m = getMarks();
        for (int i = 0; i < 5; i++)
        {
            total += m[i];
        }
        setPercentage((total / 600.0) * 100);
    }

    void display() override
    {
        cout << "\nArts Student Record";
        Student::display();
    }
};

int main()
{

    ScienceStudent s1;
    s1.display();

    ArtStudent s2;
    s2.display();
    return 0;
}