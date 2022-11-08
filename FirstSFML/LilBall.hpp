//
//  LilBall.hpp
//  FirstSFML
//
//  Created by Petar Acimovic on 5/24/22.
//  Copyright © 2022 Petar Acimovic. All rights reserved.
//

#ifndef LilBall_hpp
#define LilBall_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class LilBall
{
    sf::CircleShape shape;
    void initShape();
    
public:
    LilBall();
    LilBall(float x, float y);
    virtual ~LilBall();
    void setLocation(float x = 500.f, float y = 600.f); // example of locations
    void update(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};


#endif /* LilBall_hpp */
