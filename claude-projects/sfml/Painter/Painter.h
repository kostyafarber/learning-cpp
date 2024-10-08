#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

using namespace std;

class Painter {
public:
  Painter(int width, int height, const string &title);
  ~Painter() = default;

  void set_draw(function<void(sf::RenderWindow &)> drawfunc);
  sf::Vector2f get_center();
  void run();

private:
  sf::RenderWindow win;
  function<void(sf::RenderWindow &)> drawFunction;
};