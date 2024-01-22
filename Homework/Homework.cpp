#include <iostream>
#include <list>
#include <string>

using namespace std;
/*
int main() {
    list<string> todoList; // список для хранения дел
    list<string> archiveList; // список для хранения выполненных дел
    setlocale(LC_ALL, "ru");
    int choice;
    string task;

    do {
        // Вывод меню пользователя
        cout << "Меню:\n";
        cout << "1. Добавить дело\n";
        cout << "2. Дело выполнено\n";
        cout << "3. Отобразить список дел\n";
        cout << "4. Отобразить отчёт\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите новое дело: ";
            cin.ignore(); // Игнорируем символ новой строки после ввода числа
            getline(cin, task); // Читаем всю строку включая пробелы
            todoList.push_back(task); // Добавляем дело в конец списка
            break;
        case 2:
            if (todoList.empty()) {
                cout << "Список дел пуст!\n";
            }
            else {
                cout << "Введите номер выполненного дела: ";
                int index;
                cin >> index;
                if (index >= 1 && index <= todoList.size()) {
                    auto it = todoList.begin();
                    advance(it, index - 1); // Перемещаем итератор на нужную позицию
                    archiveList.push_back(*it); // Перемещаем дело в архив
                    todoList.erase(it); // Удаляем дело из списка
                    cout << "Дело успешно перемещено в архив!\n";
                }
                else {
                    cout << "Неверный номер дела!\n";
                }
            }
            break;
        case 3:
            if (todoList.empty()) {
                cout << "Список дел пуст!\n";
            }
            else {
                cout << "Список дел:\n";
                int i = 1;
                for (const auto& task : todoList) {
                    cout << i << ". " << task << "\n";
                    i++;
                }
            }
            break;
        case 4:
            if (archiveList.empty()) {
                cout << "Отчёт пуст!\n";
            }
            else {
                cout << "Отчёт (список выполненных дел):\n";
                int i = 1;
                for (const auto& task : archiveList) {
                    cout << i << ". " << task << "\n";
                    i++;
                }
            }
            break;
        case 0:
            cout << "Программа завершена.\n";
            break;
        default:
            cout << "Неверный выбор! Попробуйте ещё раз.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}*/