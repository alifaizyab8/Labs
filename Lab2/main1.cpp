#include <iostream>
using namespace std;

class Counter
{
private:
    int value;

public:
    Counter() : value(0)
    {
        cout << "Constructed using Default Constructor" << endl;
        cout<<"Current value : "<<value<<endl<<endl;
    }
    void Increment()
    {
        cout << "Incremented by 1" << endl;
        value++;
        cout<<"Current value : "<<value<<endl<<endl;
    }
    void Decrement()
    {
        cout << "Decremented by 1" << endl;
        value--;
        cout<<"Current value : "<<value<<endl<<endl;
    }
    friend void Reset(Counter &c)
    {
        cout << "Value reset to 0 !" << endl;
        c.value = 0;
    }
};

int main()
{
    Counter c;
    c.Increment();
    c.Decrement();
    Reset(c);
    return 0;
}