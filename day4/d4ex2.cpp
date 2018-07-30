#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

class Weapon {
  protected:
    std::string name;
    int damage;
    int level;

  public:
    Weapon(std::string name, int damage, int level) {
      this->name = name;
      this->damage = damage;
      this->level = level;
    }
    virtual void info() { /* empty */ };
    virtual int get_rank() = 0;
};

class Gun : public Weapon {
  public:
    Gun(std::string name, int damage, int level) :
      Weapon(name, damage, level) { /* empty */ }
    void info() {
      std::cout << "Gun={Name=" << this->name << ",Damage=" << this->damage
        << ",Level=" << this->level << "}" << '\n';
    }
    int get_rank() {
      return this->level * (this->damage * 2);
    }
};

class Bow : public Weapon {
  public:
    Bow(std::string name, int damage, int level) :
      Weapon(name, damage, level) { /* empty */ }
    void info() {
      std::cout << "Bow={Name=" << this->name << ",Damage=" << this->damage
        << ",Level=" << this->level << "}" << '\n';
    }
    int get_rank() {
      return this->level * this->damage;
    }
};

// Descending order
bool rank_comparator (Weapon* i, Weapon* j) { return (i->get_rank() > j->get_rank()); }

int main() {
  Weapon* g1 = new Gun("Simple gun I", 5, 1);
  Weapon* g2 = new Gun("Simple gun II", 7, 2);
  Weapon* g3 = new Gun("Shotgun I", 20, 2);
  Weapon* g4 = new Gun("Shotgun II", 25, 3);
  Weapon* b1 = new Bow("Simple Bow I", 8, 1);
  Weapon* b2 = new Bow("Simple Bow II", 12, 2);
  Weapon* b3 = new Bow("Bow of Triumph I", 35, 5);
  Weapon* b4 = new Bow("Bow of Triumph II", 45, 7);
  std::vector<Weapon*> weapons;
  weapons.push_back(g1);
  weapons.push_back(g2);
  weapons.push_back(g3);
  weapons.push_back(g4);
  weapons.push_back(b1);
  weapons.push_back(b2);
  weapons.push_back(b3);
  weapons.push_back(b4);
  std::sort (weapons.begin(), weapons.end(), rank_comparator);
  int i = 0;
  for (Weapon* w : weapons) {
    w->info();
    i++;
    if (i == 5) {
      break;
    }
  }
  return 0;
}
