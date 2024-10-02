#include <format>
#include <iostream>
#include <string>

struct RGB {
  int r;
  int g;
  int b;

  bool operator==(const RGB &) const = default;
};

class Colour {
public:
  static std::string red;
  static std::string green;
  static std::string blue;

  RGB rbg;

  Colour() {}
  Colour(int r, int g, int b) {
    rbg.r = r;
    rbg.g = g;
    rbg.b = b;
  }
  bool operator==(const Colour &) const = default;
};

std::string Colour::red = "red";
std::string Colour::green = "green";
std::string Colour::blue = "blue";

using namespace std;

int main() {
  Colour c1, c2;
  Colour c3(80, 65, 33);
  Colour c4(80, 65, 33);

  Colour c5(80, 65, 24);

  cout << format("Comparing c1 and c2, static classes, {}\n", c1 == c2);
  cout << format("Comparing c2 and c3, static and custom classes, {}\n",
                 c2 == c3);

  cout << format("Comparing c3 and c4, custom classes same members, {}\n",
                 c3 == c4);

  cout << format("Comparing c4 and c5, custom classes same members, {}\n",
                 c4 == c5);

  return 0;
};