#include <iostream>

using namespace std;

int main() {
    int counter = 0;

    auto printTable = [&counter](int width, int height) {
        cout << "******************************" << endl;
        cout << "*                            *" << endl;
        cout << "*     разыскивается          *" << endl;
        cout << "*    Маленькая Разбойница    *" << endl;
        cout << "*                            *" << endl;
        cout << "******************************" << endl;

        counter++;
        };

    printTable(30, 5);
    printTable(40, 7);

    cout << "Количество напечатанных табличек: " << counter << endl;

    return 0;
}