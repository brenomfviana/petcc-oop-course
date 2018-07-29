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

class ItemConsume: public Item {
    public:
        ItemConsume(int id,std::string name, int health,
            int speed, int attack, float defence): Item(id, name, health,speed,attack,defence)
        {        }

};

static std::list <ItemConsume> generate_items(int min, int max,std::list<std::string> names, float battle_items);


int main(){


}

static std::list <ItemConsume> generate_items(int min, int max,std::list<std::string> names, float battle_items){
  srand(time(NULL));
  int random = rand() % max + min;

  std::list<ItemConsume> itens;

  int battle_items_qnt = random*battle_items;

  for(int i = 0; i < battle_items_qnt; i++){ 
    srand(time(NULL));
    int name_rand = rand() % names.size();
    std::list <std::string>::iterator it;
    it = names.begin();
    for(int i =0;i<name_rand;i++){
      it++;
    }
    std::string nameTry = *it;
    srand(time(NULL));
    int speed_rand = rand() % 5 + 2;
    srand(time(NULL));
    int attack_rand = rand() % 5 + 2;
    srand(time(NULL));
    int defense_rand = rand() % 5 + 2;
    ItemConsume item(i,nameTry,0,speed_rand,attack_rand,defense_rand);
    itens.push_back(item);
  }

  for(int i = battle_items_qnt; i < random; i++){ 
    srand(time(NULL));
    int health_rand = rand() % 20 + 8;
    ItemConsume item(i,"potion health",health_rand,0,0,0);
    itens.push_back(item);
  }

  return itens;
}