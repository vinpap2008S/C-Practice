#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class Monster {
private:
    string name;
    string weapon1;
    string weapon2;

public:
    Monster(string n, string w1, string w2) : name(n), weapon1(w1), weapon2(w2) {}

    void attack(Monster& other) {
        cout << name << " attacks with " << weapon1 << " and " << weapon2 << endl;
        // реализация атаки
    }

    bool isDefeated() {
        return weapon1.empty() && weapon2.empty();
    }
};

int main() {
    srand(time(0));

    Monster monster1("Monster1", "Axe", "Sword");
    Monster monster2("Monster2", "Club", "Bow");

    Monster* attacker = &monster1;
    Monster* defender = &monster2;

    while (!monster1.isDefeated() && !monster2.isDefeated()) {
        attacker->attack(*defender);
        swap(attacker, defender);
    }

    if (monster1.isDefeated()) {
        cout << "Monster2 wins!" << endl;
    }
    else {
        cout << "Monster1 wins!" << endl;
    }

    return 0;
}
