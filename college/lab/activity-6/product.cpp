#include <iostream>
using namespace std;

struct Product {
    string code;
    string name;
    double price;
    int quantity;
};

int n;

int main()
{
    cout << "Amount of products: ";
    cin >> n;
    if (n > 50) n=50;
    Product products[n];


    double totalPrice = 0;   
    double totalQuantity = 0;
    double rate = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Product " << i + 1 << endl;
        cout << "Code: ";
        cin >> products[i].code;
        cout << "Name: ";
        cin >> products[i].name;
        cout << "Price: ";
        cin >> products[i].price;
        cout << "Quantity: ";
        cin >> products[i].quantity;
        cout << endl;

        totalPrice += products[i].price * products[i].quantity;
        totalQuantity += products[i].quantity;
    }

    rate = totalPrice / totalQuantity;

    cout << "Total products purchased: " << totalQuantity << endl;
    cout << "Total price: " << totalPrice << endl;
    cout << "Rate price of products: " << rate << endl;
    return 0;
}
