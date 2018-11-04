#include "graphics.hpp" 
#include "entity.hpp"
#include "timer.hpp"
#include <iostream>
 
void game_loop(sdl::Graphics& graphics)
{
 
    SDL_Event events{};
    bool isOpen{true};



    sdl::Timer timer{};
    sdl::Entity::Sprite sprite{graphics, "ressources/ship.png"};
    sprite.setPosition(100, 100);
    sprite.setOrigin(sprite.getWidth() / 2, sprite.getHeight() / 2);

    auto speed = 0; // speed = a * t
    const auto gravity = 9.81;


    while(isOpen)
    {
        timer.start_timer();

        while(SDL_PollEvent(&events))
        {
            if(events.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                isOpen = false; 
            }
            else if(events.type == SDL_KEYDOWN)
            {
                if(events.key.keysym.sym == SDLK_LEFT)
                {
                    sprite.setRotation(sprite.getRotation() - 10);
                }
                else if(events.key.keysym.sym == SDLK_RIGHT)
                {
                    sprite.setRotation(sprite.getRotation() + 10);
                }
                else if(events.key.keysym.sym == SDLK_UP)
                {
                    sprite.move(sdl::Entity::Vector2f::Vector2fCreateFromAngle(5, 180 + sprite.getRotation()));
                }
                else if(events.key.keysym.sym == SDLK_DOWN)
                {
                    sprite.move(sdl::Entity::Vector2f::Vector2fCreateFromAngle(5, sprite.getRotation()));
                }
            }
        }
        sprite.move(0, 1);
        
        graphics.setBackgroundColor(0, 0, 0, 255);
        graphics.clear();
        sprite.draw(graphics);
        graphics.update();

        timer.limitFPS();
    }
 
}

int main(int argc, char** argv)
{   
 
    sdl::Graphics graphics{"Asteroids"};

    graphics.setCallback(game_loop);
    graphics.loop();
 
    return 0;
}