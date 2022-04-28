#include "game.h"

#include "utils.h"

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game") {
    // Init resources
    if (!pixel_font.loadFromFile("../res/pixel_font.ttf")) {
        throw "Error loading pixel font";
    }

    if (!smooth_font.loadFromFile("../res/smooth_font.ttf")) {
        throw "Error loading pixel font";
    }

    sf::Image img;
    if (!img.loadFromFile("../res/icon.png")) {
        throw "Error loading window icon.";
    }

    // Init window
    sf::Vector2u img_size = img.getSize();
    window.setIcon(img_size.x, img_size.y, img.getPixelsPtr());

    // Init UI
    if (!ImGui::SFML::Init(window)) {
        throw "Error initializing UI";
    };

    ImGuiIO& io = ImGui::GetIO();
    io.MouseDrawCursor = false;
}

Game::~Game() {}

int Game::run() {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            handleEvents();
        }

        ImGui::SFML::Update(window, deltaClock.restart());
        update();

        window.clear(sf::Color::Black);
        render();
        renderUI();
        ImGui::SFML::Render(window);
        window.display();

        afterRender();
    }

    window.close();
    ImGui::SFML::Shutdown();

    return 0;
}

void Game::handleEvents() {
    switch (event.type) {
        case sf::Event::Closed: {
            window.close();
            break;
        }
        case sf::Event::KeyPressed: {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
            }

            break;
        }
        case sf::Event::MouseButtonPressed: {
            switch (event.mouseButton.button) {
                case sf::Mouse::Left:
                    break;
                case sf::Mouse::Right:
                    break;
            }
            break;
        }
    }
}

void Game::update() {}

void Game::render() {}

void Game::renderUI() {
    ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */
            }
            if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */
            }
            if (ImGui::MenuItem("Close", "Ctrl+W")) {
                my_tool_active = false;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    // Edit a color (stored as ~4 floats)
    ImGui::ColorEdit4("Color", my_color);

    // Plot some values
    const float my_values[] = {0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f};
    ImGui::PlotLines("Frame Times", my_values, IM_ARRAYSIZE(my_values));

    // Display contents in a scrolling region
    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Important Stuff");
    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++) ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();
    ImGui::End();
}

void Game::afterRender() {}