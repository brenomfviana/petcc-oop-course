#include <iostream>

class Player {
  public:
    int health_p;
    int speed_p;
    int attack_p;
    float defense_p;

    void attack(Player* p) {
      p->health_p -= (int) (this->attack_p * p->defense_p);
      p->health_p = (p->health_p < 0 ? 0 : p->health_p);
    }

    bool is_dead() {
      return (this->health_p == 0);
    }
};

int main() {
  // Player 1
  Player p1;
  p1.health_p = 10;
  p1.speed_p = 10;
  p1.attack_p = 10;
  p1.defense_p = 0.5;
  std::cout << "Player 1 created." << '\n';
  // Player 2
  Player p2;
  p2.health_p = 5;
  p2.speed_p = 5;
  p2.attack_p = 5;
  p2.defense_p = 0.8;
  std::cout << "Player 2 created." << '\n';
  // Battle
  std::cout << "Player 1 attacks Player 2." << '\n';
  p1.attack(&p2);
  if (p2.is_dead()) {
    std::cout << "Player 2 died, Player 1 won." << '\n';
  }
  return 0;
}
