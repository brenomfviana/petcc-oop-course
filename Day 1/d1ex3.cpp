#include <iostream>

class Map {
  public:
    int **map;

    Map() {
      this->map = new int*[16];
      for (int i = 0; i < 16; ++i) {
        this->map[i] = new int[16];
      }
    }

    ~Map() {
      for (int i = 0; i < 16; ++i) {
        delete map[i];
      }
      delete this->map;
    }
    /* Exercício bônus */
    /* Essa função deve imprimir os elementos da matriz */
    void print() {
      /* Coloque seu código aqui */
      for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
          std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
      }
    }
    /* Essa função deve alterar uma célula da matriz */
    void strike(int x, int y) {
      /* Coloque seu código aqui */
      ++map[x][y];
    }
};

int main() {
  Map map;
  int x, y;
  while (true) /* loop infinito */{
    map.print();
    std::cout << "Digite coordenada x:\n";
    std::cin >> x;
    std::cout << "Digite coordenada y:\n";
    std::cin >> y;
    map.strike(x, y);
  }
  return 0;
}
