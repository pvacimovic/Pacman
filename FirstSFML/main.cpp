
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "game.hpp"

int main(int, char const**)
{
    // init game engine
    Game game; 
    
//    sf::Texture texture;
//    if(!texture.loadFromFile("Resources/wall.png")){
//        return 0;
//    }
//
//    sf::Sprite sprite;
//    sprite.setTexture(texture);

    // Start the game loop
    
    int i = 0; // best solution i could think to just update the map once
    
    while(game.running())
    {
        // Update
        game.update();
        
//        game.drawSprite(sprite);
        
        if(i==0)
        {
            game.updateMap();
        }
        
        // Render
        game.render();
        
        i=1;
    }

    return EXIT_SUCCESS;
}
