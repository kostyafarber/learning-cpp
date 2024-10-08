#include "Painter.h"
#include "TextRenderer.h"

int main() {
  Painter p(800, 700, "Exercise 3");

  p.set_draw([](sf::RenderWindow &window) {
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));

    sf::Vector2f windowCenter(window.getSize().x / 2.f,
                              window.getSize().y / 2.f);

    rectangle.setOrigin(rectangle.getSize() / 2.f);

    rectangle.setPosition(windowCenter);

    rectangle.setFillColor(sf::Color(255, 255, 255, 128));

    window.draw(rectangle);
  });

  p.run();
}