//
// Created by Marius on 17/08/2023.
//

#include "ResourcesManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

template<>
std::unordered_map<std::string_view, sf::Texture> ResourcesManager<sf::Texture>::resources{};

template<>
std::unordered_map<std::string_view, sf::SoundBuffer> ResourcesManager<sf::SoundBuffer>::resources{};

template<>
std::unordered_map<std::string_view, sf::Font> ResourcesManager<sf::Font>::resources{};