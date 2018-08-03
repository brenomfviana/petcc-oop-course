#include <iostream>

class Item {
  protected:
    int id;
    std::string name;

  public:
    Item(int id, std::string name) {
        this->id = id;
        this->name = name;
    }

    int get_id() {
      return this->id;
    }

    std::string get_name() {
      return this->name;
    }

    int get_health() {
      return this->health;
    }

    int get_speed() {
      return this->speed;
    }

    int get_attack() {
      return this->attack;
    }

    int get_defense() {
      return this->defense;
    }
};

class ConsumableItem: public Item {
  public:
    ConsumableItem(int id, std::string name, int health, int speed): Item(id, name) {
        this->health = health;
        this->speed = speed;
    }

    void print() {
      std::cout << "id: " << this->id << std::endl;
      std::cout << "name: " << this->name << std::endl;
      std::cout << "health: " << this->health << std::endl;
      std::cout << "speed: " << this->speed << std::endl;
    }
};

class Equipment: public Item {
  public:
    Equipment(int id,std::string name, int attack, float defense) : Item(id, name) {
        this->attack = attack;
        this->defense = defense + 1;
    }

    void print() {
      std::cout << "id: " << this->id << std::endl;
      std::cout << "name: " << this->name << std::endl;
      std::cout << "attack: " << this->attack << std::endl;
      std::cout << "defense: " << this->defense << std::endl;
    }
};

int main() {
  ConsumableItem potion(20, "Heal Potion", 20, 0, 0, 0);
  Equipment sword(10, "Great Sword", 100, 0);
  potion.print();
  sword.print();
}
