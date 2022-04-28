#pragma once

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

#include "SFML/Graphics.hpp"
#include "imgui-SFML.h"
#include "imgui.h"

class Game {
public:
    Game();
    ~Game();

    int run();

    void handleEvents();
    void update();
    void render();
    void renderUI();
    void afterRender();

private:
    sf::RenderWindow window;
    sf::Event event;

    sf::Font pixel_font;
    sf::Font smooth_font;

    sf::Clock deltaClock;

    float my_color[4];
    bool my_tool_active;
};