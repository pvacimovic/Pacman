//
//  game.cpp
//  FirstSFML
//
//  Created by Petar Acimovic on 5/18/22.
//  Copyright © 2022 Petar Acimovic. All rights reserved.
//

#include "game.hpp"

// private

void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 1250; // 550 for smaller, 1250 for bigger
    this->videoMode.width = 1650; // 750 for smaller, 1650 for smaller
    this->window = new sf::RenderWindow(this->videoMode, "SFML window", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    this->window->setFramerateLimit(60);
}

// create map

void Game::setMap()
{
    
    int rows = 25; // 11 for small, 25 for bigger
    int col = 33; // 15 for small, 33 for bigger
    
    float x_wall = 0.f;
    float y_wall = 0.f;
    float x_ball = 25.f;
    float y_ball = 25.f;
    
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<col; j++)
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

// constructiors / destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

// accessors

const bool Game::running() const
{
    return this->window->isOpen();
}

// modifiers

// public

void Game::pollEvents()
{
    // event polling
    while(this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::updateCollision()
{
    // check if there is collision (eating)
    // i need for statement that checks all balls

    for(int i = 0; i < balls.size(); i++)
    {
        if(this->player.getShape().getGlobalBounds().intersects(balls.at(i).getGlobalBounds()))
        {
            this->balls.erase(balls.begin() + i);
            this->player.pointsUp(); // adds one to points
        }
    }
        
}

void Game::updateWallCollision()
{

    // if player touches a wall he stayes there
    
    sf::Vector2f currPosition;
    currPosition = this->player.getShape().getPosition();
    
    for(int i = 0; i < walls.size(); i++)
    {
        if(this->player.getShape().getGlobalBounds().intersects(walls.at(i).getGlobalBounds()))
        {
            //this->player.setLocation(currPosition.x, currPosition.y);
            
            // take one of the last elements in vector
            
            float c = 5;
            int n = player.getHistory().size() - 10; // last element (if not works take some further element)
            
            float x1 = player.getHistory().at(n).x;
            float y1 = player.getHistory().at(n).y;
            float x2 = currPosition.x;
            float y2 = currPosition.y;
            float x,y;
            
            x = x2 - ((x2-x1)/c);
            y = y2 - ((y2-y1)/c);
            
            this->player.setLocation(x, y);
            
        }
    }
        
}

void Game::updateMap()
{
    this->setMap();
    //this->setLocationWall(0.f, 0.f);
}

void Game::renderMap()
{
    
    for (int i=0; i<walls.size(); i++)
    {
        this->window->draw(this->walls.at(i));
    }
    
    for (int i=0; i<balls.size(); i++)
    {
        this->window->draw(this->balls.at(i));
    }

}

// overall update and render

void Game::update()
{
    this->pollEvents();
    
    //this->ball.update(this->window); // update one ball for examples
    
    //this->updateMap();
    
    this->player.update(this->window);
    
    this->updateCollision();
    
    this->updateWallCollision();
}

void Game::render()
{
    /*
     @returns void
     
    - clear old frame
    - render objects
    - display frame in window
     
     */
    
    this->window->clear();
    
    // render stuff
    
    // draw stuff
    //this->ball.render(this->window); // render one ball for example
    
    this->renderMap(); // render map

    this->player.render(this->window);
    
    this->window->display();
}
