#include <iostream>
#include <string>
using namespace std;
// Q4
class Post
{
protected:
    string Name;
    string To;
    float StampCost;

public:
    // Constructor
    Post()
    {
        StampCost = 1.0;
        To = "";
        Name = "";
    }

    // User Input
    void Read()
    {
        cout << "Enter Sender Name: ";
        getline(cin, Name);

        cout << "Enter Receiver Address: ";
        getline(cin, To);

        cout << "Enter Stamp Cost: ";
        cin >> StampCost;
        cin.ignore(); // Clear buffer
    }

    // Display values
    void Print()
    {
        cout << "\nPost Details ";
        cout << "Sender Name: " << Name << endl;
        cout << "Receiver Address: " << To << endl;
        cout << "Stamp Cost: $" << StampCost << endl;
    }

    // Return StampCost
    float TotalCost()
    {
        return StampCost;
    }
};
class RegisteredPost : public Post
{
protected:
    float Weight;
    float RegistrationCost;

public:
    // Constructor: Weight 20g, Reg Cost 10$
    RegisteredPost()
    {
        Weight = 20.0;
        RegistrationCost = 10.0;
    }

    // Read
    void Read()
    {
        Post::Read();

        cout << "Enter Weight (gms): ";
        cin >> Weight;

        cout << "Enter Registration Cost: ";
        cin >> RegistrationCost;
        cin.ignore(); // Clear buffer
    }

    // Print
    void Print()
    {
        Post::Print();
        cout << "Weight: " << Weight << " gms" << endl;
        cout << "Registration Cost: $" << RegistrationCost << endl;
    }

    // TotalCost = StampCost + RegistrationCost
    float TotalCost()
    {
        return Post::TotalCost() + RegistrationCost;
    }
};

// Q5
class InsuredRegisteredPost : public RegisteredPost
{
private:
    float AmtInsured;

public:
    // Constructor AmtInsured 20$
    InsuredRegisteredPost()
    {
        AmtInsured = 20.0;
    }

    // Read
    void Read()
    {
        RegisteredPost::Read();

        cout << "Enter Insured Amount: ";
        cin >> AmtInsured;
        cin.ignore(); // Clear buffer
    }
    // TotalCost: (Stamp + Reg) + Insured
    float TotalCost()
    {
        return RegisteredPost::TotalCost() + AmtInsured;
    }
    // Print
    void Print()
    {
        RegisteredPost::Print();
        cout << "Insured Amount: $" << AmtInsured << endl;
        cout << "Grand Total: $" << TotalCost() << endl;
    }
};
int main()
{
    InsuredRegisteredPost envelope;
    envelope.Read();
    cout << "Post Details..";
    envelope.Print();
    return 0;
}