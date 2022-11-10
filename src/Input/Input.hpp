#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Input {
private:
    SDL_Event windowEvent;
public:
    bool pollEvent();
    SDL_Event getEvent();
};

#endif
