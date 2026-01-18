#include <iostream>
#include <cmath>
using namespace std;
class Complex_No
{
private:
    double Real, Imaginary;

public:
    Complex_No(double c, double i) : Real(c), Imaginary(i)
    {
        cout << "Constructed using Paramaterized Constructor " << endl;
    }
    Complex_No() : Real(0), Imaginary(0)
    {
        cout << "Constructed using Default Constructor" << endl;
    }
    Complex_No(Complex_No &num) : Real(num.Real), Imaginary(num.Imaginary)
    {
        cout << "Constructed using Copy Constructor" << endl;
    }
    void display() const
    {
        if (Imaginary >= 0)
        {
            cout << Real << " + " << Imaginary << "i" << endl;
        }
        else
        {
            cout << Real << " - " << (-1.0) * Imaginary << "i" << endl;
        }
    }
    double magnitude() const
    {
        return sqrt(Real * Real + Imaginary * Imaginary);
    }
    Complex_No add(Complex_No &c) const
    {
        Complex_No temp;
        temp.Real += c.Real;
        temp.Imaginary += c.Imaginary;
        return temp;
    }
};
int main()
{
    Complex_No c1(12.5, -13.2);
    c1.display();
    Complex_No c2;
    c2.display();
    Complex_No c3(c1);
    c3.display();
    cout << "The magnitude of Complex Number is : " << c3.magnitude() << endl;
    Complex_No c4 = c2.add(c1);
    c4.display();

    return 0;
}
