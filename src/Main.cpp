#include "2D/Surface.h"

#include "netpbm.hpp"

int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cout << "Usage: game <file_name>" << std::endl;
        return 0;
    }

    if (SDL_Init(SDL_INIT_VIDEO) >= 0) {
        std::string file_name(argv[1]);
        std::string extension;
        
        std::stringstream ss(file_name);
        while(getline(ss, extension, '.'));

        if(extension == "pbm") {
            Bitmap image(file_name.c_str());
            Surface * view = new Surface("image", image.getWidth(), image.getHeight());
            view->getRenderer()->setImage(image.toArray(), image.getWidth(), image.getHeight());
            view->loop();
            delete view;
        }
        
        if(extension == "pgm") {
            Graymap image(file_name.c_str());
            Surface * view = new Surface("image", image.getWidth(), image.getHeight());
            view->getRenderer()->setImage(image.toArray(), image.getWidth(), image.getHeight());
            view->loop();
            delete view;
        }

        if(extension == "ppm") {
            Pixmap2 image(file_name.c_str());
            Surface * view = new Surface("image", image.getWidth(), image.getHeight());
            view->getRenderer()->setImage(image.toArray(), image.getWidth(), image.getHeight());
            view->loop();
            delete view;
        }

        if(extension == "jpg" || extension == "jpeg") {
            //
        }

        if(extension == "png") {
            //
        }

        if(extension == "mpg" || extension == "mpeg") {
            //
        }

        SDL_Quit();
    }

    return 1;
}
