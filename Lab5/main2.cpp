#include <iostream>
#include <string>
using namespace std;
class Product
{
protected:
    string name;
    int productID;

public:
    // Constructor
    Product(string n, int id)
    {
        name = n;
        productID = id;
    }
    // Display
    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Product ID: " << productID << endl;
    }
};
class UtilityItem : public Product
{
private:
    float discount;

public:
    // Constructor
    UtilityItem(string n, int id, float d) : Product(n, id)
    {
        discount = d;
    }

    // Display
    void show()
    {
        cout << "\nUtility Item Details" << endl;
        Product::show();
        cout << "Discount: " << discount << "%" << endl;
    }
};
class FoodItem : public Product
{
private:
    string expiryDate;

public:
    // Constructor
    FoodItem(string n, int id, string date) : Product(n, id)
    {
        expiryDate = date;
    }

    // Display
    void show()
    {
        cout << "\nFood Item Details" << endl;
        Product::show();
        cout << "Expiry Date: " << expiryDate << endl;
    }
};

int main()
{
    UtilityItem washingMachine("Washing Machine", 123, 15.5);
    washingMachine.show();
    FoodItem milk("Milk", 142, "12-Dec-2023");
    milk.show();

    return 0;
}