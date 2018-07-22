#include <iostream>

class Player {
  public:
    int health_p;
    int speed_p;
    int attack_p;
    float defense_p;

    Player(int health_p, int speed_p, int attack_p, int defense_p) {
      this->health_p = health_p;
      this->speed_p = speed_p;
      this->attack_p = attack_p;
      this->defense_p = defense_p;
    }

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
  Player* p1 = new Player(10, 10, 10, 0.5);
  std::cout << "Player 1 created." << '\n';
  // Player 2
  Player* p2 = new Player(5, 5, 5, 0.8);
  std::cout << "Player 2 created." << '\n';
  // Battle
  std::cout << "Player 1 attacks Player 2." << '\n';
  p1->attack(p2);
  if (p2->is_dead()) {
    std::cout << "Player 2 died, Player 1 won." << '\n';
  }
  return 0;
}
