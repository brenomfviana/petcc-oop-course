#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <iterator>

class Item {
  protected:
    int id;
    std::string name;
    int health;
    int speed;
    int attack;
    float defense;

  public:
    Item(int id, std::string name, int health, int speed, int attack,
      float defense) {
        this->id = id;
        this->name = name;
        this->health = health;
        this->speed = speed;
        this->attack = attack;
        this->defense = defense;
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
    ConsumableItem(int id, std::string name, int health, int speed,
      int attack, float defense): Item(id, name, health, speed, attack,
        defense) { /* empty */ }
    void print() {
      std::cout << "----------------------------" << '\n';
      std::cout << "ID: " << id << '\n';
      std::cout << "Name: " << name << '\n';
      std::cout << "Health: " << health << '\n';
      std::cout << "Speed: " << speed << '\n';
      std::cout << "Attack: " << attack << '\n';
      std::cout << "Defence: " << defense << '\n';
      std::cout << "----------------------------" << '\n';
    }
};

static std::list <ConsumableItem> generate_items(int min, int max,
  std::list<std::string> names, float battle_items) {
    srand(time(NULL));
    int random = rand() % max + min;

    std::list<ConsumableItem> itens;

    int battle_items_qnt = random * battle_items;

    for (int i = 0; i < battle_items_qnt; i++) {
      int name_rand = rand() % names.size();
      std::list <std::string>::iterator it;
      it = names.begin();
      for (int i = 0; i < name_rand; i++) {
        it++;
      }
      std::string name = *it;
      int speed_rand = rand() % 5 + 2;
      int attack_rand = rand() % 5 + 2;
      int defense_rand = rand() % 5 + 2;
      ConsumableItem item(i, name, 0, speed_rand, attack_rand, defense_rand);
      itens.push_back(item);
    }

    for (int i = battle_items_qnt; i < random; i++) {
      srand(time(NULL));
      int health_rand = rand() % 20 + 8;
      ConsumableItem item(i, "Potion Health", health_rand, 0, 0, 0);
      itens.push_back(item);
    }

    return itens;
}

int main() {
  std::string strs[] = { "Power Potion", "Fire Potion", "Water Potion", "Leaf Potion" };
  std::list<std::string> names(strs, strs + sizeof(strs) / sizeof(std::string));
  // Genenate and print items
  for (ConsumableItem ci : generate_items(5, 10, names, 0.7)) {
    ci.print();
  }
}
