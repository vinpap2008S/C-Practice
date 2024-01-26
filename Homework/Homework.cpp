#include <iostream>
#include <list>
using namespace std;

class Weapon
{
protected:
	int damage;
	int shootCount;
	int maxAmmo;
public:

	Weapon(int damage, int shootCount, int maxAmmo) : damage(damage), shootCount(shootCount), maxAmmo(maxAmmo) {}
	int shoot()
	{
		if (shootCount > 0) {
			shootCount--;
			return damage;
		}
		if (shootCount == 0)
			return -1;
		else
		{
			return damage;
		}

	}
};
class Blaster : public Weapon {
public:
	Blaster() : Weapon(10, -1, 6) {}
};
class Pistol : public Weapon {
public:
	Pistol() : Weapon(20, 6, 6) {}
};
class MachineGun : public Weapon {
public:
	MachineGun() : Weapon(5, 100, 100) {}
};
/*
int main()
{
	list<Weapon*> weapons;
	Blaster* blaster = new Blaster();
	Pistol* pistol = new Pistol();
	MachineGun* machineGun = new MachineGun();

	weapons.push_back(blaster);
	weapons.push_back(pistol);
	weapons.push_back(machineGun);
	while (weapons.size()>1)
	{
		for (Weapon* weapon : weapons) {
			if (weapon->shoot() != -1)
				cout << "Damage: " << weapon->shoot() << endl;
			else
				delete weapon;
		}
		cout << endl;
	}


	for (Weapon* weapon : weapons) {
		cout << "Damage: " << weapon->shoot() << endl;
	}


	for (Weapon* weapon : weapons) {
		delete weapon;
	}

	return 0;
}
*/