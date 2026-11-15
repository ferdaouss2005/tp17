#include <iostream>
#include "Point.h"
#include "Triangle.h"

using namespace std;

int main() {

    Point p1(0, 0);
    Point p2(3, 0);
    Point p3(0, 4);

    Triangle t(p1, p2, p3);

    cout << "Perimetre du triangle : "
         << t.perimetre() << endl;

    return 0;
}
