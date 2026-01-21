#include <iostream>
using namespace std;

class myIntArray
{
private:
    int size;
    int *arr;

public:
    // Parameterized Constructor
    myIntArray(int s)
    {
        size = s;
        arr = new int[size];

        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
            cin.ignore();
        }
    }

    // Copy Constructor
    myIntArray(const myIntArray &obj)
    {
        size = obj.size;
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }

    // Method to display array
    void display() const
    {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Method to add contents of array
    int sum() const
    {
        int total = 0;
        for (int i = 0; i < size; i++)
        {
            total += arr[i];
        }
        return total;
    }

    // Destructor
    ~myIntArray()
    {
        delete[] arr;
    }
};

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    // Using parametrized constructor
    myIntArray A(n);

    cout << "Original Array: " << endl;
    A.display();
    cout << "Sum of elements: " << A.sum() << endl;

    // Using copy constructor
    myIntArray B = A;

    cout << "Copied Array: " << endl;
    B.display();
    cout << "Sum of elements: " << B.sum() << endl;

    return 0;
}
