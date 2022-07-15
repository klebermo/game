#ifndef ANIMATION_H
#define ANIMATION_H

#include "Image.h"

#include <vector>

class Animation {
protected:
    std::vector<Image *> frames;
public:
    Animation();
    ~Animation();
    void init();
    void draw();
    void exit();
};

#endif
