#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "Image.hpp"
#include "Video.hpp"
#include "Animation.hpp"
#include "../Input/Input.hpp"

class Renderer {
private:
    Image * image;
    Video * video;
    Animation * animation;
    Input input;
public:
    Renderer();
    ~Renderer();

    void setImage(float * vertices, int width, int height);
    void setVideo();
    void setAnimation();

    void drawFrame(SDL_Window * window);
    void playVideo(SDL_Window * window);
    void showAnimation(SDL_Window * window);
};

#endif
