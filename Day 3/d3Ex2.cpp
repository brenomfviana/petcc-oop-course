#include <iostream>

class Item {
    protected:
        int id;
        std::string name;
        int health, speed, attack, defense;
    public:
        Item(int id, std::string name, int health, int speed,
            int attack, int defense) {
                this->id = id;
                this->name = name;
                this->health = health;
                this->speed = speed;
                this->attack = attack;
                this->defense = defense;
        }       
        int get_id() { return this->id; }
        
        std::string get_name() { return this->name; }
        
        int get_health() { return this->health; }
        
        int get_speed() { return this->speed; }
        
        int get_attack() { return this->attack; }
        
        int get_defense() { return this->defense; }
};

class ItemConsume: public Item {
    public:
        ItemConsume(int id,std::string name, int health,
            int speed, int attack, int defence): Item(id, name, health,speed,attack,defence)
        {        }

        void print(){
            std::cout << "nome: " << this->name << std::endl;
            std::cout << "cura: " << this->health << std::endl;
        }
};

class Equipment: public Item {
    public:
      Equipment( int id,std::string name, int attack, int defence): Item(id, name, 0,0,attack,defence)
       {       }

        void print(){
            std::cout << "nome: " << this->name << std::endl;
            std::cout << "ataque: " << this->attack << std::endl;
        }
};

int main(){
ItemConsume potion(20, "Heal Potion", 20, 0, 0, 0);
Equipment sword(10, "Great Sword", 100, 0);

potion.print();

sword.print();
}