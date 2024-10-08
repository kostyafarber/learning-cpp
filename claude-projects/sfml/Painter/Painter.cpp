#include "Painter.h"

using namespace std;

Painter::Painter(int width, int height, const string &title)
    : win(sf::RenderWindow(sf::VideoMode(width, height), title)) {}

void Painter::set_draw(std::function<void(sf::RenderWindow &)> drawFunc) {
  drawFunction = drawFunc;
}

sf::Vector2f Painter::get_center() {
  return sf::Vector2f(win.getSize().x / 2.f, win.getSize().y / 2.f);
}

void Painter::run() {
  while (win.isOpen()) {
    // Process events
    sf::Event event;
    while (win.pollEvent(event)) {
      // Close window: exit
      switch (event.type) {
      case sf::Event::Closed:
        win.close();
        break;
      }
    }
    win.clear();
    if (drawFunction) {
      drawFunction(win);
    }
    win.display();
  }
}
