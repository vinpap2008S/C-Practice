#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <ctime>

using namespace std;

class Dictionary {
private:
    map<string, vector<string>> words;

public:
    void addWord(const string& word, const vector<string>& synonyms) {
        words[word] = synonyms;
    }

    vector<string> translate(const string& word) {
        if (words.find(word) != words.end()) {
            return words[word];
        }
        return { "Translation not found" };
    }

    void randomTest(int N) {
        vector<string> testedWords;
        srand(time(0));

        ofstream testFile("test_results.txt");
        if (testFile.is_open()) {
            testFile << "Tested Words:\n";

            for (int i = 0; i < N; ++i) {
                int randomIndex = rand() % words.size();
                auto it = next(words.begin(), randomIndex);
                string word = it->first;

                testFile << word << "\n";
                testedWords.push_back(word);
            }

            testFile << "\nResults:\n";
            for (const auto& word : testedWords) {
                testFile << "Word: " << word << "\n";
                testFile << "Translation: ";
                for (const auto& synonym : translate(word)) {
                    testFile << synonym << ", ";
                }
                testFile << "\n\n";
            }

            testFile.close();
        }
        else {
            cerr << "Unable to open file for writing." << endl;
        }
    }
};

int main() {
    Dictionary dict;

    // Чтение слов и синонимов из файла
    ifstream file("words.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string word;
            vector<string> synonyms;

            size_t pos = line.find(':');
            if (pos != string::npos) {
                word = line.substr(0, pos);
                string synonymsStr = line.substr(pos + 1);
                size_t start = 0, end = synonymsStr.find(',');
                while (end != string::npos) {
                    synonyms.push_back(synonymsStr.substr(start, end - start));
                    start = end + 1;
                    end = synonymsStr.find(',', start);
                }
                synonyms.push_back(synonymsStr.substr(start));
            }

            dict.addWord(word, synonyms);
        }
        file.close();
    }
    else {
        cerr << "Unable to open file with words." << endl;
        return 1;
    }

    // Перевод слова
    vector<string> translation = dict.translate("apple");
    cout << "Translation of 'apple': ";
    for (const auto& synonym : translation) {
        cout << synonym << ", ";
    }
    cout << endl;

    // Проведение теста и запись результатов в файл
    dict.randomTest(3);

    return 0;
}