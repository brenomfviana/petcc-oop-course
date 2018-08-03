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
};

class ConsumableItem: public Item {
  private:
    int health;
    int speed;

  public:
    ConsumableItem(int id, std::string name, int health, int speed) :
      Item(id, name) {
        this->health = health;
        this->speed = speed;
      }

    int get_health() {
      return this->health;
    }

    int get_speed() {
      return this->speed;
    }

    void print() {
      std::cout << "----------------------------" << '\n';
      std::cout << "ID: " << id << '\n';
      std::cout << "Name: " << name << '\n';
      std::cout << "Health: " << health << '\n';
      std::cout << "Speed: " << speed << '\n';
      std::cout << "----------------------------" << '\n';
    }
};

static std::list <ConsumableItem> generate_items(int min, int max,
  std::list<std::string> names) {
    srand(time(NULL));
    int random = rand() % max + min;

    std::list<ConsumableItem> itens;

    int battle_items_qnt = random *
      (static_cast<float>(rand()) / static_cast<float>(RAND_MAX));

    for (int i = 0; i < battle_items_qnt; i++) {
      int name_rand = rand() % names.size();
      std::list <std::string>::iterator it;
      it = names.begin();
      for (int i = 0; i < name_rand; i++) {
        it++;
      }
      std::string name = *it;
      int speed_rand = rand() % 5 + 2;
      ConsumableItem item(i, name, 0, speed_rand);
      itens.push_back(item);
    }

    for (int i = battle_items_qnt; i < random; i++) {
      srand(time(NULL));
      int health_rand = rand() % 20 + 8;
      ConsumableItem item(i, "Potion Health", health_rand, 0);
      itens.push_back(item);
    }

    return itens;
}

int main() {
  std::string strs[] = { "Power Potion", "Fire Potion", "Water Potion", "Leaf Potion" };
  std::list<std::string> names(strs, strs + sizeof(strs) / sizeof(std::string));
  // Genenate and print items
  for (ConsumableItem ci : generate_items(5, 10, names)) {
    ci.print();
  }
}
