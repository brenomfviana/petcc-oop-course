#include <iostream>
#include <string>
#include <map>

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

class ItemConsume: public Item {
    public:
        ItemConsume(int id,std::string name, int health,
            int speed, int attack, float defence): Item(id, name, health,speed,attack,defence)
        {        }

};

class Equipment: public Item {
    public:
      Equipment( int id,std::string name, int attack, float defence): Item(id, name, 0,0,attack,defence)
       {       }
};


class Bag {
  private:
    int slots;
    int empty_slots;
    std::map<ItemConsume*, int> items;

  public:
    Bag(int slots) {
      this->slots = slots;
      this->empty_slots = slots;
    }

    void add_item(ItemConsume* item, int amount) {
      this->items[item] = amount;
      this->empty_slots--;
    }

    void drop_item(int item_id, int amount) {
      for (std::map<ItemConsume*, int>::iterator it = this->items.begin();
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

    ItemConsume* get_item(int item_id) {
      for (std::map<ItemConsume*, int>::iterator it = this->items.begin();
        it != this->items.end(); ++it) {
          if (it->first->get_id() == item_id) {
            return it->first;
          }
      }
      return nullptr;
    }

    ItemConsume* pick_item(int item_id) {
      for (std::map<ItemConsume*, int>::iterator it = this->items.begin();
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
    Equipment weapon, shield; 
    Bag* bag;

  public:
    Player(int health_p, int speed_p, int attack_p, float defense_p,
      Equipment weapon, Equipment shield,Bag* bag ): health_p(health_p), speed_p(speed_p), attack_p(attack_p),
      defense_p(defense_p),weapon(weapon),shield(shield),bag(bag)
      {    }

    void attack(Player* p) {
      p->health_p -= (this->attack_p * p->defense_p);
      p->health_p = (p->health_p < 0 ? 0 : p->health_p);
    }

    bool is_dead() {
      return (this->health_p == 0);
    }

    int get_health() {
      return this->health_p;
    }

    void set_health(Item i) {
      health_p=+i.get_health();
    }

    int get_speed() {
      return this->speed_p;
    }
};

int main() {
  // Create items
  ItemConsume* item0 = new ItemConsume(0, "Item 0", 20, 0, 0,   0);
  ItemConsume* item1 = new ItemConsume(1, "Item 1",  0, 5, 0,   0);
  ItemConsume* item2 = new ItemConsume(2, "Item 2",  0, 0, 5,   0);
  ItemConsume* item3 = new ItemConsume(3, "Item 3",  0, 0, 0, 1.5);
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

  Equipment Long_Sword(10,"Long Sword",100,0);
  Equipment Iron_Shield(5,"Iron Shield",0,100);
  Player p(100,10,25,50,Long_Sword,Iron_Shield,bag);
  return 0;
}