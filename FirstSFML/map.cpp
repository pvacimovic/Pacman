//
//  map.cpp
//  FirstSFML
//
//  Created by Petar Acimovic on 5/24/22.
//  Copyright © 2022 Petar Acimovic. All rights reserved.
//

#include "map.hpp"

// private funcions
void Map::initShape()
{
    this->wall.setSize(sf::Vector2f(50.f,50.f));
    this->wall.setFillColor(sf::Color::Blue);
}

// constructor and destructor
Map::Map()
{
    this->initShape();
    //this->setLocationWall(x, y);
}

Map::~Map()
{
    
}

// public methods
void Map::setLocationWall(float x, float y)
{
    this->wall.setPosition(x, y);
}

void Map::setLocationBall(float x, float y)
{
    //this->ball.setLocation(x,y);
}

void Map::setMap()
{
    
    float x_wall = 0.f;
    float y_wall = 0.f;
    float x_ball = 25.f;
    float y_ball = 25.f;
    
    for (int i=0; i<25; i++)
    {
        for (int j=0; j<33; j++)
        {
            
            if (mat[i][j]==1) // mat2 for smaller
            {
                sf::RectangleShape blueSquare;
                blueSquare.setSize(sf::Vector2f(50.f,50.f));
                blueSquare.setFillColor(sf::Color::Blue);
                blueSquare.setPosition(x_wall,y_wall);
                
                walls.push_back(blueSquare);
            }
            else if (mat[i][j]==0) // mat2 for smaller
            {
//                LilBall whiteBall;
//                whiteBall.setLocation(x_ball, y_ball);
//                
//                balls.push_back(whiteBall);
                
                sf::CircleShape whiteBall;
                whiteBall.setFillColor(sf::Color::White);
                whiteBall.setRadius(5.f);
                whiteBall.setPosition(x_ball, y_ball);
                
                balls.push_back(whiteBall);
            }
            
            // update x coordinate
            x_wall = x_wall + 50.f;
            x_ball = x_ball + 50.f;
        }
        // update y coordinate
        y_wall = y_wall + 50.f;
        y_ball = y_ball + 50.f;
        
        // return x to the begining
        x_wall = 0.f;
        x_ball = 25.f;
    }
}

// render update

void Map::updateMap(sf::RenderTarget *target)
{
    this->setMap();
    //this->setLocationWall(0.f, 0.f);
}

void Map::renderMap(sf::RenderTarget *target)
{
    
    for (int i=0; i<walls.size(); i++)
    {
        target->draw(this->walls.at(i));
    }
    
    for (int i=0; i<balls.size(); i++)
    {
        target->draw(this->balls.at(i));
    }

}
