//
// Created by Marius on 17/08/2023.
//

#ifndef DISPLAYMAP_GAME_H
#define DISPLAYMAP_GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void draw();
    sf::RenderWindow window;
};


#endif //DISPLAYMAP_GAME_H
