#include <random>

#include "SFML/Graphics.hpp"

namespace Utils {
namespace Drawing {
void drawText(const float &x, const float &y, const int &size, const std::string &txt, sf::Font &font,
              const sf::Color &color, const bool &centered, sf::RenderWindow &window) {
    sf::Text text(txt, font, size);
    text.setPosition(sf::Vector2f(x, y));

    if (centered)
        text.setOrigin(sf::Vector2f(text.getLocalBounds().left + (text.getLocalBounds().width / 2),
                                    text.getLocalBounds().top + (text.getLocalBounds().height / 2)));
    text.setFillColor(color);

    window.draw(text);
}
}  // namespace Drawing

template <typename T>
sf::Vector2<T> mapSurfaceCoords(const sf::Vector2<T> &map_from, const sf::Vector2<T> &map_to, const sf::Vector2<T> coords) {
    sf::Vector2<T> pos;
    pos.x = coords.x * map_to.x / map_from.x;
    pos.y = coords.y * map_to.y / map_from.y;

    return pos;
}
}  // namespace Utils