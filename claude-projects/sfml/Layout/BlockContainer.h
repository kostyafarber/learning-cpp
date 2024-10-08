#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class BlockContainer {
public:
  float m_x;
  float m_y;

  float padding;
  float margin;

  float width;
  float height;

  void center_rec(sf::Vector2f point);

  BlockContainer(float x, float y);

  sf::RectangleShape rec;

private:
  void center_origin();
};