#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
        if (!isValid()) {
            throw invalid_argument("Triangle cannot be created. Invalid sides.");
        }
    }

    double getPerimeter() const {
        return side1 + side2 + side3;
    }

    double getArea() const {
        double p = getPerimeter() / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }

    bool isValid() const {
        return (side1 + side2 > side3) && (side2 + side3 > side1) && (side1 + side3 > side2);
    }
};

bool compareByPerimeter(const Triangle& t1, const Triangle& t2) {
    return t1.getPerimeter() < t2.getPerimeter();
}

bool compareByArea(const Triangle& t1, const Triangle& t2) {
    return t1.getArea() < t2.getArea();
}

int main() {
    try {
        Triangle t1(3, 4, 5);
        Triangle t2(5, 12, 13);
        Triangle t3(8, 15, 17);

        cout << "Perimeter Comparison: " << compareByPerimeter(t1, t2) << endl;
        cout << "Area Comparison: " << compareByArea(t1, t2) << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
