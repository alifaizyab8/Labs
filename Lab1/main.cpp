#include <iostream>
using namespace std;
class complex_number
{
    double real, img;

public:
    // Setters for real and imaginary values
    void set_real()
    {
        cout << "Please enter the value of Real Part" << endl;
        cin >> real;
    }
    void set_img()
    {
        cout << "Please enter the value of Imaginary Part" << endl;
        cin >> img;
    }
    void print()
    {
        if (img > 0)
        {
            cout << real << " + " << img << "i" << endl;
        }
        else
        {
            cout << real << " - " << (-1.0) * img << "i" << endl;
        }
    }
};
int main()
{
    complex_number c1;
    c1.set_real();
    c1.set_img();
    c1.print();

    return 0;
}
