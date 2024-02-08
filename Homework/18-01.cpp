#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Weapon {
public:
    Weapon(const string& name) : name(name) {}

    void attack() {
        cout << name << " attacks!" << endl;
    }

private:
    string name;
};

class Monster {
public:
    Monster(const string& name) : name(name) {}

    void equipWeapon(unique_ptr<Weapon> weapon) {
        weapons.push_back(move(weapon));
    }

    void attack() {
        for (const auto& weapon : weapons) {
            weapon->attack();
        }
    }

private:
    string name;
    vector<unique_ptr<Weapon>> weapons;
};

int main() {
    unique_ptr<Weapon> sword = make_unique<Weapon>("Sword");
    unique_ptr<Weapon> axe = make_unique<Weapon>("Axe");

    Monster monster("Dragon");
    monster.equipWeapon(move(sword));
    monster.equipWeapon(move(axe));

    monster.attack();

    return 0;
}