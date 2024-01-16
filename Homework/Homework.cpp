#include <iostream>
#include <string>

using namespace std;

int main() {
    string task;
    cout << "Введите задачу: ";
    cin >> task;

    int pos = 0;
    int sum = 0;

    while (pos < task.length()) {
        int start = task.find_first_of("0123456789", pos);
        if (start == -1) {
            break;
        }

        int end = task.find_first_not_of("0123456789", start);
        if (end == -1) {
            end = task.length();
        }

        string number_str = task.substr(start, end - start);
        int number = stoi(number_str);
        sum += number;

        pos = end;
    }

    cout << "Ответ: " << sum << endl;

    return 0;
}
