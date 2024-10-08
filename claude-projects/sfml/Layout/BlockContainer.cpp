#include "BlockContainer.h"

BlockContainer::BlockContainer(float m_x, float m_y)
    : rec(sf::Vector2(m_x, m_y)) {};

void BlockContainer::center_rec(sf::Vector2f point) {
  center_origin();
  rec.setPosition(point);
}
void BlockContainer::center_origin() { rec.setOrigin(rec.getSize() / 2.f); }