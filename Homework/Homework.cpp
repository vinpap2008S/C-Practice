#include <string>
#include <iostream>
#include <filesystem>

using namespace std;

namespace fs = filesystem;

int main() {
    string directoryPath;

    cout << "Введите путь к директории: ";
    cin >> directoryPath;

    try {
        uintmax_t totalSize = 0;

        for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
            if (fs::is_regular_file(entry)) {
                totalSize += fs::file_size(entry);
            }
        }

        cout << "Объем, занимаемый директорией: " << totalSize << " байт" << endl;
    }
    catch (const fs::filesystem_error& e) {
        cerr << "Ошибка файловой системы: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Произошла неизвестная ошибка" << endl;
    }

    return 0;
}
