//
//  player.hpp
//  FirstSFML
//
//  Created by Petar Acimovic on 5/19/22.
//  Copyright © 2022 Petar Acimovic. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

struct coordinates
{
    float x;
    float y;
};

class Player
{
    sf::CircleShape shape;
    float movementSpeed;
    
    // functions:
    void initVariables();
    void initShape();
    
    int points;
    std::vector<coordinates> history; // to store all locations where the ball was
    
public:
    // constructors / destructors
    Player(float x = 100.f, float y = 150.f);
    virtual ~Player();
    
    // functions

    
    const sf::CircleShape& getShape() const;
    const std::vector<coordinates> getHistory() const;
    
    void pointsUp();
    void pointsDown();
    
    void getLocation();
    void setLocation(float x, float y);
    void updateInput();
    void updateWindowBoundCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};

 
#endif /* player_hpp */
