
#include "Painter.h"
#include "TextRenderer.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
  TextRenderer tr(
      "/Users/kostyafarber/Library/Fonts/BerkeleyMonoVariable-Regular.ttf");
  Painter p(800, 700, "Exercise 2");

  sf::Text t("Hello World", tr.font, 16);
  p.set_draw([t](sf::RenderWindow &window) { window.draw(t); });

  p.run();
}