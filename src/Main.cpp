#include "2D/Surface.h"

#include "netpbm.h"

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

        Netpbm * image;
        
        int width = 0, height = 0;
        float * vertices;

        if(extension == "pbm") {
          image = new Bitmap(argv[1]);
          width = image->getWidth(), height = image->getHeight(), vertices = image->toArray();
        }

        if(extension == "pgm") {
          image = new Graymap(argv[1]);
          width = image->getWidth(), height = image->getHeight(), vertices = image->toArray();
        }

        if(extension == "ppm") {
          image = new Pixmap2(argv[1]);
          width = image->getWidth(), height = image->getHeight(), vertices = image->toArray();
        }

        Surface * view = new Surface("image", width, height);
        Image * pic = new Image(vertices, width, height);
        view->getRenderer()->setImage(pic);
        view->loop();

        delete vertices;
        delete pic;
        delete image;

        SDL_Quit();
    }

    return 1;
}
