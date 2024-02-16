#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define constanta 2

bool twice(int elem1, int elem2)
{
    return elem1 == elem2 - constanta;
}
bool pol(int elem1)
{
    return elem1 <= 0;
}
class Student {
public:
    string name;
    vector<int> grades;

    Student(const string& name, const vector<int>& grades) : name(name), grades(grades) {}
};

int main() {
    vector<int> numbers = { -1, 4, 6, 10, 13 };
    
    vector<int>::iterator result1 = adjacent_find(numbers.begin(), numbers.end(), twice);

    if (result1 == numbers.end()) {
        cout << "not";
    }
    else
    {
        cout << "yes";
    }
    if (!any_of(numbers.begin(), numbers.end(), pol)) {
        cout << "pol";
    }
    else
    {
        cout << "otr";
    }
    vector<Student> students = {
        Student("Иван", {9, 7, 8}),
        Student("Мария", {6, 5, 7}),
        Student("Алексей", {8, 9, 10}),
        Student("Екатерина", {7, 6, 6}),
        Student("Петр", {9, 8, 9}),
        Student("Анна", {3,5,3})
    };

    int count = count_if(students.begin(), students.end(), [](const Student& student) {
        return any_of(student.grades.begin(), student.grades.end(), [](int grade) {
            return grade > 6;
            });
        });

    cout << "Количество студентов с оценкой выше 6: " << count << endl;

    return 0;
}