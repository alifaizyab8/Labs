#include <iostream>
using namespace std;

class myclass
{
    int data[2];

public:
    int *p;

public:
    myclass()
    {
        p = data;
    }
};
int main()
{
    myclass *cp;
    cp = new myclass[3];

    cout << "Assigning values to myclass array" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Currently in Object " << i + 1 << " of array: myclass" << endl;
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter data for the array of Object " << i + 1 << " value number " << j + 1 << endl;
            cin >> (cp + i)->p[j];
            cin.ignore();
        }
    }
    cout << "Displaying values of myclass array" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Object " << i + 1<< " data:  ";
        for (int j = 0; j < 2; j++)
        {
            cout << (cp + i)->p[j]<<" ";
        }
        cout << endl;
    }

    return 0;
}
