//
//  player.cpp
//  FirstSFML
//
//  Created by Petar Acimovic on 5/19/22.
//  Copyright © 2022 Petar Acimovic. All rights reserved.
//

#include "player.hpp"

// private
void Player::initVariables()
{
    this->movementSpeed = 5.f;
    this->points = 0;
}

void Player::initShape()
{
    this->shape.setFillColor(sf::Color::Yellow);
    this->shape.setRadius(23.f);
    // position:
    //this->shape.setPosition(400.f, 300.f);
}

// constructor and destructor
Player::Player(float x, float y)
{
    // set shape to a position
    this->shape.setPosition(x, y);
    
    this->initVariables();
    this->initShape();
    
    this->getLocation();
}

Player::~Player()
{
    
}

// functions:

const sf::CircleShape & Player::getShape() const
{
    return this->shape;
}

const std::vector<coordinates> Player::getHistory() const
{
    return this->history;
}

void Player::pointsUp()
{
    points += 1;
}

void Player::pointsDown()
{
    points -= 1;
}

void Player::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

void Player::updateInput() // Keyboard Input for moving the player
{
    
    // Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->shape.move(-this->movementSpeed, 0.f);
        this->getLocation();
    }
    // Right
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->shape.move(this->movementSpeed, 0.f);
        this->getLocation();
    }
    // Up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->shape.move(0.f, -this->movementSpeed);
        this->getLocation();
    }
    // Down
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->shape.move(0.f, this->movementSpeed);
        this->getLocation();
    }
    
}

void Player::setLocation(float x, float y)
{
    this->shape.setPosition(x, y);
}

void Player::getLocation()
{
    sf::Vector2f currPosition;
    currPosition = this->getShape().getPosition();
    coordinates location;
    location.x = currPosition.x;
    location.y = currPosition.y;
    history.push_back(location);
}

void Player::updateWindowBoundCollision(const sf::RenderTarget* target){
    
    sf::FloatRect playerBounds = this->shape.getGlobalBounds();
    
    // for not leaving window ever
    /*
     
    
    // Left side
    if(playerBounds.left <= 0.f)
        this->shape.setPosition(0.f, playerBounds.top);
    // right side
    else if(playerBounds.left + playerBounds.width >= target->getSize().x)
        this->shape.setPosition(target->getSize().x-playerBounds.width, playerBounds.top);
     
    */
    
    // for teleporting from one side to other side:
    
    // left
    if(playerBounds.left <= 0.f - playerBounds.width)
        this->shape.setPosition(target->getSize().x-playerBounds.width, playerBounds.top);
    // right side
    else if(playerBounds.left + playerBounds.width >= target->getSize().x + playerBounds.width)
        this->shape.setPosition(0.f, playerBounds.top);
    
    
    playerBounds = this->shape.getGlobalBounds(); // update position for corners and stuff this has to be here
    
    // top
    if(this->shape.getGlobalBounds().top <= 0.f)
        this->shape.setPosition(playerBounds.left, 0.f);
    // Bottom
    else if(playerBounds.top + playerBounds.height >= target->getSize().y)
        this->shape.setPosition(playerBounds.left, target->getSize().y-playerBounds.height);
}

void Player::update(const sf::RenderTarget* target)
{
    this->updateInput();
    
    // bounds for collision
    this->updateWindowBoundCollision(target);
}
