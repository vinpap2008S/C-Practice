#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Monster {
private:
    std::string name;
    std::string weapon1;
    std::string weapon2;

public:
    Monster(std::string n, std::string w1, std::string w2) : name(n), weapon1(w1), weapon2(w2) {}

    void attack(Monster& other) {
        std::cout << name << " attacks with " << weapon1 << " and " << weapon2 << std::endl;
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
        std::swap(attacker, defender);
    }

    if (monster1.isDefeated()) {
        std::cout << "Monster2 wins!" << std::endl;
    }
    else {
        std::cout << "Monster1 wins!" << std::endl;
    }

    return 0;
}
