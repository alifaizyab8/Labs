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
    Student()
    {
        Name = new char[32];
        cout << "Please enter name : \n";
        cin.getline(Name, 32);
        cout << "Please enter Roll Number : \n";
        cin >> Rollno;
        cin.ignore();
        for (int i = 0; i < 5; i++)
        {
            cout << "Please enter Marks of test " << i + 1 << "\n";
            cin >> Marks[i];
        }
        cout << "Please enter Percentage : \n";
        cin >> Percentage;
    }
    Student(char *n, int r, double arr[5], float p) : Rollno(r), Percentage(p)
    {
        Name = new char[32];
        strcpy(Name, n);
        copy(arr, arr + 5, Marks);
    }
    Student(Student &s)
    {
        Name = new char[32];
        strcpy(Name, s.Name);
        Rollno = s.Rollno;
        copy(s.Marks, s.Marks + 5, Marks);
        Percentage = s.Percentage;
    }
    ~Student()
    {
        delete[] Name;
    }

    // Getters

    const char *getName()
    {
        return Name;
    }
    const int getRollNumber()
    {
        return Rollno;
    }
    const double *getMarks()
    {
        return Marks;
    }
    float getPercentage()
    {
        return Percentage;
    }

    // Setters

    void setName(char *n)
    {
        strcpy(Name, n);
    }
    void setRollNumber(int r)
    {
        Rollno = r;
    }
    void setMarks(double arr[5])
    {
        copy(arr, arr + 5, Marks);
    }
    void setPercentage(float p)
    {
        Percentage = p;
    }

    void calculatePercentage()
    {
        double total = 0, percent;
        for (int x : Marks)
        {
            total += x;
        }
        percent = (total / 500.0) * 100;
        Percentage = percent;
    }
    void Grade()
    {
        calculatePercentage();
        if (Percentage >= 80)
        {
            cout << "Grade is A\n";
        }
        else if (Percentage >= 70)
        {
            cout << "Grade is B\n";
        }
        else
        {
            cout << "Grade is C\n";
        }
    }
    double highestMarks()
    {
        double high;
        high = Marks[0];
        for (int x : Marks)
        {
            if (x > high)
            {
                high = x;
            }
        }
        return high;
    }
};

int main()
{
    const int N = 1;
    int temp[5];
    Student *S_Array = new Student[N];
    for (int i = 0; i < N; i++)
    {
        cout << S_Array[i].getName() << endl;
        cout << S_Array[i].getRollNumber() << endl;
        copy(S_Array[i].getMarks(), S_Array[i].getMarks() + 5, temp);
        for (int i = 0; i < 5; i++)
        {
            cout << "Marks for Quiz " << i + 1 << " are " << temp[i] << endl;
        }

        S_Array[i].Grade();
        cout << S_Array[i].getPercentage() << endl;
        cout << "Highest Marks in 5 Quizzes is " << S_Array[i].highestMarks() << endl;
    }

    return 0;
}