#include <iostream>
#include <list>
#include <set>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

int main() {
    list<int> myList;
    set<int> myTree;

    // Заполнение списка и дерева случайными числами
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < 1000000; ++i) {
        int num = dis(gen);
        myList.push_back(num);
        myTree.insert(num);
    }

    // Поиск в списке
    int searchNum = dis(gen);

    auto start = chrono::high_resolution_clock::now();
    for (const auto& num : myList) {
        if (num == searchNum) {
            break;
        }
    }
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << "Search in list: " << duration.count() << " seconds" << endl;

    // Поиск в дереве
    start = chrono::high_resolution_clock::now();
    myTree.find(searchNum);
    end = chrono::high_resolution_clock::now();

    duration = end - start;
    cout << "Search in tree: " << duration.count() << " seconds" << endl;

    return 0;
}