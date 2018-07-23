#include <iostream>

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
      return this->speed_p;
    }

    int get_speed() {
      return this->speed_p;
    }
};

int main() {
  // Create players
  Player p1(150, 15, 20, 0.5);
  Player p2(100, 20, 20, 0.8);
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
      std::cout << "  Player 1 attacks Player 2" << '\n';
      p1.attack(&p2);
      turn = false;
    } else {
      std::cout << "  Player 2 attacks Player 1" << '\n';
      p2.attack(&p1);
      turn = true;
    }
  }
  if (p1.is_dead()) {
    std::cout << "Player 2 died, Player 1 won." << '\n';
  }
  if (p2.is_dead()) {
    std::cout << "Player 1 died, Player 2 won." << '\n';
  }
  return 0;
}
