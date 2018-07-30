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
};

class Gun : public Weapon {
  public:
    Gun(std::string name, int damage, int level) :
      Weapon(name, damage, level) { /* empty */ }
    void info() {
      std::cout << "Gun={Name=" << this->name << ",Damage=" << this->damage
        << ",Level=" << this->level << "}" << '\n';
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
};

int main() {
  Weapon* g1 = new Gun("Simple gun", 5, 1);
  Weapon* g2 = new Gun("Shotgun", 20, 2);
  Weapon* b1 = new Bow("Simple Bow", 8, 1);
  Weapon* b2 = new Bow("Bow of Triumph", 35, 5);
  std::vector<Weapon*> weapons;
  weapons.push_back(g1);
  weapons.push_back(g2);
  weapons.push_back(b1);
  weapons.push_back(b2);
  for (Weapon* w : weapons) {
    w->info();
  }
  return 0;
}
