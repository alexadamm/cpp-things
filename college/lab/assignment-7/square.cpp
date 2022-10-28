#include <iostream>
using namespace std;

float squarePerimeter(float x, float y) {
    return 2 * (x + y);
}

float squareArea(float x, float y) {
    return x * y;
}

int main(int argc, char const *argv[])
{   
    float x, y;
    cout << "Input square width & length: " << endl;
    cin >> x >> y;
    cout << "The square area is: " << squareArea(x, y) << endl;
    cout << "The square perimeter is: " << squarePerimeter(x, y) << endl;
    return 0;
}
