#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <map>
#include <vector>

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
        this->defense = defense + 1;
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
    ConsumableItem(int id, std::string name, int health, int speed): Item(id, name,
      health, speed, 0, 0) { /* empty */ }

    void print() {
      std::cout << "id: " << this->id << std::endl;
      std::cout << "name: " << this->name << std::endl;
      std::cout << "health: " << this->health << std::endl;
      std::cout << "speed: " << this->speed << std::endl;
    }
};

class Equipment: public Item {
  public:
    Equipment(int id,std::string name, int attack, float defense) : Item(id, name,
      0, 0, attack, defense) { /* empty */ }

    void print() {
      std::cout << "id: " << this->id << std::endl;
      std::cout << "name: " << this->name << std::endl;
      std::cout << "attack: " << this->attack << std::endl;
      std::cout << "defense: " << this->defense << std::endl;
    }
};


class Bag {
  private:
    int slots;
    int empty_slots;
    std::map<ConsumableItem*, int> items;

  public:
    Bag(int slots=10) {
      this->slots = slots;
      this->empty_slots = slots;
    }

    Bag(int slots, std::vector<ConsumableItem*> items, std::vector<int> amounts) {
      this->slots = slots;
      this->empty_slots = slots;
      // Inserts items
      if ((this->slots > items.size()) && (items.size() == amounts.size())) {
        for (int i = 0; i < items.size(); i++) {
          this->items[items[i]] = amounts[i];
        }
      }
    }

    void add_item(ConsumableItem* item, int amount) {
      this->items[item] = amount;
      this->empty_slots--;
    }

    void drop_item(int item_id, int amount) {
      for (std::map<ConsumableItem*, int>::iterator it = this->items.begin();
        it != this->items.end(); ++it) {
          if (it->first->get_id() == item_id) {
            if (it->second == amount) {
              this->items.erase(it);
            } else if (it->second > amount) {
              it->second -= amount;
            } else {
              std::cout << "Error" << '\n';
              return;
            }
            this->empty_slots++;
            break;
          }
      }
    }

    ConsumableItem* get_item(int item_id) {
      for (std::map<ConsumableItem*, int>::iterator it = this->items.begin();
        it != this->items.end(); ++it) {
          if (it->first->get_id() == item_id) {
            return it->first;
          }
      }
      return nullptr;
    }

    std::vector<int> get_items() {
      std::vector<int> v;
      for (std::map<ConsumableItem*, int>::iterator it = this->items.begin();
        it != this->items.end(); ++it) {
          v.push_back(it->first->get_id());
      }
      return v;
    }

    ConsumableItem* pick_item(int item_id) {
      for (std::map<ConsumableItem*, int>::iterator it = this->items.begin();
        it != this->items.end(); ++it) {
          if (it->first->get_id() == item_id) {
            drop_item(item_id, 1);
            return it->first;
          }
      }
      return nullptr;
    }
};

class Player {
  private:
    int health_p;
    int speed_p;
    int attack_p;
    float defense_p;
    Equipment* weapon;
    Equipment* shield;
    Bag* bag;

  public:
    Player(int health_p, int speed_p, int attack_p, float defense_p,
      Equipment* weapon, Equipment* shield, Bag* bag) {
        this->health_p = health_p;
        this->speed_p = speed_p;
        this->attack_p = attack_p;
        this->defense_p = defense_p;
        this->weapon = weapon;
        this->shield = shield;
        this->bag = bag;
    }

    void attack(Player* p) {
      p->set_health(p->get_health() - (((float) this->get_attack()) * p->get_defense()));
      if (p->get_health() < 0) {
        p->set_health(0);
      }
    }

    bool use_item(int item_id) {
      Item* item = this->bag->pick_item(item_id);
      if (item == nullptr) {
        return false;
      }
      this->health_p += item->get_health();
      this->speed_p += item->get_speed();
      this->attack_p += item->get_attack();
      this->defense_p *= item->get_defense();
      return true;
    }

    bool is_dead() {
      return (this->health_p == 0);
    }

    void set_health(int health_p) {
      this->health_p = health_p;
    }

    int get_health() {
      return this->health_p;
    }

    int get_speed() {
      return this->speed_p;
    }

    int get_attack() {
      if (this->weapon != nullptr) {
        return (this->attack_p + this->weapon->get_attack());
      }
      return this->attack_p;
    }

    float get_defense() {
      if (this->shield != nullptr) {
        return (this->defense_p * this->shield->get_defense());
      }
      return this->defense_p;
    }

    Bag* get_bag() {
      return bag;
    }
};

class Battle {
  public:
    Battle() { /* empty */ };

    static int random_move(Player p) {
      return (rand() % (p.get_bag()->get_items().size() + 1)) - 1;
    };

    static void battle(Player p1, Player p2) {
      // Controller
      bool turn = false;
      if (p1.get_speed() > p2.get_speed()) {
        turn = true;
      }
      // Battle
      while(!p1.is_dead() && !p2.is_dead()) {
        std::cout << "Health (Player 1): " << p1.get_health() << '\n';
        std::cout << "Health (Player 2): " << p2.get_health() << '\n';
        if (turn) {
          int i = random_move(p1);
          if (i == -1) {
            std::cout << "  Player 1 attacks Player 2" << '\n';
            p1.attack(&p2);
            turn = false;
          } else {
            if (p1.use_item(i)) {
              std::cout << "  Player 1 uses item " << i << '\n';
              // Using speed item, who is faster?
              if (i == 1 && p1.get_speed() > p2.get_speed()) {
                turn = true;
              } else {
                turn = false;
              }
            } else {
              std::cout << "  Player 1 attacks Player 2" << '\n';
              p1.attack(&p2);
              turn = false;
            }
          }
        } else {
          int i = random_move(p2);
          if (i == -1) {
            std::cout << "  Player 2 attacks Player 1" << '\n';
            p2.attack(&p1);
            turn = true;
          } else {
            if (p2.use_item(i)) {
              std::cout << "  Player 2 uses item " << i << '\n';
              // Using speed item, who is faster?
              if (i == 1 && p2.get_speed() > p1.get_speed()) {
                turn = false;
              } else {
                turn = true;
              }
            } else {
              std::cout << "  Player 2 attacks Player 1" << '\n';
              p2.attack(&p1);
              turn = true;
            }
          }
        }
        usleep(1000);
      };
      if (p1.is_dead()) {
        std::cout << "Player 1 died, Player 2 won." << '\n';
      }
      if (p2.is_dead()) {
        std::cout << "Player 2 died, Player 1 won." << '\n';
      }
    }
};

int main() {
  // Create items
  ConsumableItem* item0 = new ConsumableItem(0, "Item 0", 20, 0);
  ConsumableItem* item1 = new ConsumableItem(1, "Item 1",  0, 1.5);
  // Create a list
  std::vector<ConsumableItem*> items;
  items.push_back(item0);
  items.push_back(item1);
  // Amounts
  std::vector<int> amounts;
  amounts.push_back(4);
  amounts.push_back(1);
  // Create bags
  Bag* bag1 = new Bag(10, items, amounts);
  Bag* bag2 = new Bag(10, items, amounts);
  // Equipment
  Equipment* long_sword = new Equipment(10, "Long Sword", 15, 0);
  Equipment* iron_shield = new Equipment(5, "Iron Shield", 0, 0.4);
  // Create players
  Player p1(150, 15, 20, 0.5, long_sword, iron_shield, bag1);
  Player p2(100, 20, 20, 0.8, long_sword, iron_shield, bag2);
  // Battle
  Battle battle;
  battle.battle(p1, p2);
  return 0;
}
