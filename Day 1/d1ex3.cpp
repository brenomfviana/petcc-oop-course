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
};

int main() {
  Map map;
  return 0;
}
