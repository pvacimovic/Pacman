//
//  LilBall.cpp
//  FirstSFML
//
//  Created by Petar Acimovic on 5/24/22.
//  Copyright © 2022 Petar Acimovic. All rights reserved.
//

#include "LilBall.hpp"

// private
void LilBall::initShape()
{
    this->shape.setFillColor(sf::Color::White);
    this->shape.setRadius(5.f);

}

// constructor and destructor
LilBall::LilBall()
{
    this->initShape();
}

LilBall::LilBall(float x, float y)
{
    this->initShape();
    this->shape.setPosition(x, y);
}

LilBall::~LilBall()
{
    
}

// functions:

void LilBall::setLocation(float x, float y)
{
    this->shape.setPosition(x, y);
}

void LilBall::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}

void LilBall::update(sf::RenderTarget* target)
{
    this->setLocation();
}
