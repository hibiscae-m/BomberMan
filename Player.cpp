//
// Created by Marius on 16/08/2023.
//

#include "Player.h"
#include "ResourcesManager.h"

Player::Player() {
    initializeSprite();
}

void Player::initializeSprite() {
    sprite.setTexture(ResourcesManager<sf::Texture>::getResource("resources/player.png"));
    sprite.setTextureRect(sf::IntRect({animation.x * SPRITE_SIZE.x, animation.y * SPRITE_SIZE.y},
                                      {SPRITE_SIZE.x, SPRITE_SIZE.y}));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition({100, 100});
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::update(const sf::Time deltaTime) {
    move(deltaTime);
    playAnimation(deltaTime);
}

void Player::move(const sf::Time deltaTime) {
    sf::Vector2f movement = {0.f, 0.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        animation.y = Direction::Up;
        movement += {0.f, -speed};
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        animation.y = Direction::Down;
        movement += {0.f, speed};
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        animation.y = Direction::Side;
        sprite.setScale(-1.f, 1.f);
        movement += {-speed, 0.f};
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        animation.y = Direction::Side;
        sprite.setScale(1.f, 1.f);
        movement += {speed, 0.f};
    }
    sf::Vector2f idle = {0.f, 0.f}; // for some reason I could not check equality with { 0.f, 0.f }
    if (movement != idle) {               // so I did this messy looking stuff.
        isIdle = false;
        sprite.move(movement * deltaTime.asSeconds());
    }
    else {
        isIdle = true;
    }
}

void Player::playAnimation(const sf::Time deltaTime) {
    timeSinceLastUpdate += deltaTime;
    if (timeSinceLastUpdate > animationTimePerFrame) {
        timeSinceLastUpdate -= animationTimePerFrame;
        if (isIdle) {
            animation = {6, Direction::Down};
        }
        else {
            animation.x++;
            if (animation.x > 2) {
                animation.x = 0;
            }
        }
        sprite.setTextureRect(sf::IntRect({animation.x * SPRITE_SIZE.x, animation.y * SPRITE_SIZE.y},
                                          {SPRITE_SIZE.x, SPRITE_SIZE.y}));
    }
}
