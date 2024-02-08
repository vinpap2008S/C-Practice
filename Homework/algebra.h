#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>

class Dictionary {
private:
    std::unordered_map<std::string, std::vector<std::string>> words;

public:
    void addWord(const std::string& word, const std::vector<std::string>& synonyms) {
        words[word] = synonyms;
    }

    std::vector<std::string> translate(const std::string& word) {
        if (words.find(word) != words.end()) {
            return words[word];
        }
        return { "Translation not found" };
    }

    void randomTest(int N) {
        std::vector<std::string> testedWords;
        srand(time(0));

        std::ofstream testFile("test_results.txt");
        if (testFile.is_open()) {
            testFile << "Tested Words:\n";

            for (int i = 0; i < N; ++i) {
                int randomIndex = rand() % words.size();
                auto it = std::next(words.begin(), randomIndex);
                std::string word = it->first;

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
            std::cerr << "Unable to open file for writing." << std::endl;
        }
    }
};

int main() {
    Dictionary dict;

    // Добавление слов и синонимов
    dict.addWord("apple", { "яблоко", "яблоко" });
    dict.addWord("house", { "дом", "жилище" });
    dict.addWord("car", { "машина", "автомобиль" });

    // Перевод слова
    std::vector<std::string> translation = dict.translate("apple");
    std::cout << "Translation of 'apple': ";
    for (const auto& synonym : translation) {
        std::cout << synonym << ", ";
    }
    std::cout << std::endl;

    // Проведение теста и запись результатов в файл
    dict.randomTest(3);

    return 0;
}