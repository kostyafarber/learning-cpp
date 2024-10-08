#include "BlockContainer.h"
#include "Painter.h"

int main() {
  Painter p(800, 500, "Exercise 4");

  p.set_draw([&](sf::RenderWindow &window) -> void {
    BlockContainer block(30, 90);
    block.center_rec(p.get_center());

    window.draw(block.rec);
  });

  p.run();
}