#include <iostream>
#include <math.h>
#define RANGE 30
using namespace std;

struct point {
    float x;
    float y;
};

struct trianglePoint {
    point A;
    point B;
    point C;
};

float length(point A, point B) {
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

float triangleArea(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}


int main() {
    struct point A, B;
    struct trianglePoint triangle;
    A.x = (float) rand()/RAND_MAX*RANGE;
    A.y = (float) rand()/RAND_MAX*RANGE;

    B.x = (float) rand()/RAND_MAX*RANGE;
    B.y = (float) rand()/RAND_MAX*RANGE;

    triangle.A.x = (float) rand()/RAND_MAX*RANGE;
    triangle.A.y = (float) rand()/RAND_MAX*RANGE;
    triangle.B.x = (float) rand()/RAND_MAX*RANGE;
    triangle.B.y = (float) rand()/RAND_MAX*RANGE;
    triangle.C.x = (float) rand()/RAND_MAX*RANGE;
    triangle.C.y = (float) rand()/RAND_MAX*RANGE;


    cout << "Length of AB: " << length(A, B) << endl;
    cout << "Area of triangle: " << triangleArea(length(A, B), length(A, triangle.A), length(B, triangle.A)) << endl;  
}