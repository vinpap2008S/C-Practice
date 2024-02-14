/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Spravochnik {
public:
    struct Record {
        string name;
        string owner;
        string phone;
        string address;
        string activity;
    };

    vector<Record> records;

    void searchByName(const string& name) {
        for (const auto& record : records) {
            if (record.name == name) {
                displayRecord(record);
            }
        }
    }

    void searchByOwner(const string& owner) {
        for (const auto& record : records) {
            if (record.owner == owner) {
                displayRecord(record);
            }
        }
    }

    void searchByPhone(const string& phone) {
        for (const auto& record : records) {
            if (record.phone == phone) {
                displayRecord(record);
            }
        }
    }

    void searchByActivity(const string& activity) {
        for (const auto& record : records) {
            if (record.activity == activity) {
                displayRecord(record);
            }
        }
    }

    void displayAllRecords() {
        for (const auto& record : records) {
            displayRecord(record);
        }
    }

    void addRecord(const Record& newRecord) {
        records.push_back(newRecord);
    }

    void saveToFile() {
        ofstream file("spravochnik.txt");
        if (file.is_open()) {
            for (const auto& record : records) {
                file << record.name << "," << record.owner << "," << record.phone << "," << record.address << "," << record.activity << "\n";
            }
            file.close();
        }
        else {
            cerr << "Unable to open file for writing." << endl;
        }
    }

private:
    void displayRecord(const Record& record) {
        cout << "Name: " << record.name << endl;
        cout << "Owner: " << record.owner << endl;
        cout << "Phone: " << record.phone << endl;
        cout << "Address: " << record.address << endl;
        cout << "Activity: " << record.activity << endl;
        cout << "---------------------------------" << endl;
    }
};

int main() {
    Spravochnik spravochnik;

    Spravochnik::Record newRecord = { "FirmName", "OwnerName", "1234567890", "Address", "Activity" };
    spravochnik.addRecord(newRecord);

    spravochnik.searchByName("FirmName");
    spravochnik.displayAllRecords();

    spravochnik.saveToFile();

    return 0;
}
*/