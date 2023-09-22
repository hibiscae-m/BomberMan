//
// Created by Marius on 17/08/2023.
//

#include "Game.h"
#include "WindowSettings.h"
#include "GameManager.h"

Game::Game() :
    window(sf::VideoMode(WindowSettings::WINDOW_WIDTH, WindowSettings::WINDOW_HEIGHT),
           WindowSettings::WINDOW_NAME.data())
{}

void Game::run() {
    sf::Clock gameClock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time framePerSecond = sf::seconds(WindowSettings::TIME_PER_FRAME);
    GameManager::loadMap(GameManager::MAP::First);
    GameManager::initializePlayers();
    while (window.isOpen()) {
        timeSinceLastUpdate += gameClock.restart();
        if (timeSinceLastUpdate > framePerSecond) {
            timeSinceLastUpdate -= framePerSecond;
            processEvents();
            GameManager::update(framePerSecond);
            GameManager::clear();
            draw();
        }
    }
}

void Game::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::draw() {
    window.clear();
    GameManager::drawMap(window);
    GameManager::drawBombs(window);
    GameManager::drawPlayers(window);
    GameManager::drawExplosions(window);
    window.display();
}