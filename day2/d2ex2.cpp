#include <iostream>
#include <string>
#include <map>

class Item {
  private:
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


class Bag {
  private:
    int slots;
    int empty_slots;
    std::map<Item*, int> items;

  public:
    Bag(int slots) {
      this->slots = slots;
      this->empty_slots = slots;
    }

    void add_item(Item* item, int amount) {
      this->items[item] = amount;
      this->empty_slots--;
    }

    void drop_item(int item_id, int amount) {
      for (std::map<Item*, int>::iterator it = this->items.begin();
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

    Item* get_item(int item_id) {
      for (std::map<Item*, int>::iterator it = this->items.begin();
        it != this->items.end(); ++it) {
          if (it->first->get_id() == item_id) {
            return it->first;
          }
      }
      return nullptr;
    }

    Item* pick_item(int item_id) {
      Item* item;
      for (std::map<Item*, int>::iterator it = this->items.begin();
        it != this->items.end(); ++it) {
          if (it->first->get_id() == item_id) {
            drop_item(item_id, 1);
            return it->first;
          }
      }
      return nullptr;
    }
};

int main() {
  // Create items
  Item* item0 = new Item(0, "Item 0", 20, 0, 0,   0);
  Item* item1 = new Item(1, "Item 1",  0, 5, 0,   0);
  Item* item2 = new Item(2, "Item 2",  0, 0, 5,   0);
  Item* item3 = new Item(3, "Item 3",  0, 0, 0, 1.5);
  // Create bag
  Bag* bag = new Bag(10);
  // Add items to bag
  bag->add_item(item0, 4);
  bag->add_item(item1, 2);
  bag->add_item(item2, 2);
  bag->add_item(item3, 1);
  // Drop an item
  bag->drop_item(3, 1);
  // Get an item
  Item* item = bag->get_item(3);
  if (item == nullptr) {
    std::cout << "There is no Item 3 in the bag." << '\n';
  }
  // Drop an item
  bag->drop_item(0, 1);
  // Get an item
  item = bag->get_item(0);
  std::cout << "Selected item: " << item->get_name() << '\n';
  return 0;
}
