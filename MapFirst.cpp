//
// Created by Marius on 21/09/2023.
//
#include "MapFirst.h"
#include <iostream>

std::vector<std::vector<int>> MapFirst::getMap() {
    std::vector<std::vector<int>> result;
    for (auto i = 0u; i < HEIGHT; i++) {
        std::vector<int> buffer_vector;
        for (auto j = 0u; j < WIDTH; j++) {
            buffer_vector.push_back(MAP[i][j]);
        }
        result.push_back(buffer_vector);
        buffer_vector.clear();
    }
    std::cout << result.size() << std::endl;
    return result;
}

sf::Vector2i MapFirst::getMapSize() {
    return { WIDTH, HEIGHT };
}
