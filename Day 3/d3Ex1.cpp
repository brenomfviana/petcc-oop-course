#include <iostream>

class Item {
    private:
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

class Player {
  private:
    int health_p;
    int speed_p;
    int attack_p;
    float defense_p;

  public:
    Player(int health_p, int speed_p, int attack_p, float defense_p) {
      this->health_p = health_p;
      this->speed_p = speed_p;
      this->attack_p = attack_p;
      this->defense_p = defense_p;
    }

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

class Batalha {
    public:
        Batalha(){};
         static int random_move(Player p){
            if((p.get_health() < 30)){                
                return 0;
            }else{                
                return 1;
            }
        };

        static void battle(Player p1, Player p2) {
              bool turn;
              Item i(0, "poção de cura", 20, 0,0,0);
              if (p1.get_speed() > p2.get_speed()) {
                turn = true;
              }
              // Battle
              while(!p1.is_dead() && !p2.is_dead()) {
                std::cout << "Health (Player 1): " << p1.get_health() << '\n';
                std::cout << "Health (Player 2): " << p2.get_health() << '\n';
                if (turn) {
                  int action = random_move(p1);
                  if (action == 1){
                    std::cout << "  Player 1 attacks Player 2" << '\n';
                    p1.attack(&p2);
                  }else{
                    std::cout << "  Player 1 heals" << '\n';
                    p1.set_health(i);
                  }                  
                  turn = false;
                } else {
                  int action = random_move(p2);
                  if (action == 1){
                    std::cout << "  Player 2 attacks Player 1" << '\n';
                     p2.attack(&p1);
                  }else{
                    std::cout << "  Player 2 heals" << '\n';
                    p2.set_health(i);
                  }       
                  turn = true;
                }
              }
              if (p1.is_dead()) {
                std::cout << "Player 1 died, Player 2 won." << '\n';
              }
              if (p2.is_dead()) {
                std::cout << "Player 2 died, Player 1 won." << '\n';
              }
        };
};

int main(){
Player p1(150, 15, 40, 0.5);
Player p2(100, 20, 20, 0.8);
Batalha battle2;

battle2.battle(p1,p2);
}