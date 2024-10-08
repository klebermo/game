#include "2D/Surface.hpp"

#include "netpbm.hpp"
#include "jpeg.hpp"

int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cout << "Usage: game <file_name>" << std::endl;
        return 0;
    }

    std::string file_name(argv[1]);
    std::string extension;
    
    std::stringstream ss(file_name);
    while(getline(ss, extension, '.'));

    if(extension == "pbm") {
        Bitmap image;
        image.read_file(file_name);
        
        std::vector<float> vertices_vec = image.toArray();
        float *vertices = vertices_vec.data();
        int width = image.getWidth();
        int height = image.getHeight();

        Surface * view = new Surface("image: "+file_name, width, height);
        view->getRenderer()->setImage(vertices, width, height);
        view->loop();

        delete vertices;
        delete view;
    }
    
    if(extension == "pgm") {
        Graymap image;
        image.read_file(file_name);

        std::vector<float> vertices_vec = image.toArray();
        float *vertices = vertices_vec.data();
        int width = image.getWidth();
        int height = image.getHeight();

        Surface * view = new Surface("image: "+file_name, width, height);
        view->getRenderer()->setImage(vertices, width, height);
        view->loop();

        delete vertices;
        delete view;
    }

    if(extension == "ppm") {
        Pixmap2 image;
        image.read_file(file_name);

        std::vector<float> vertices_vec = image.toArray();
        float *vertices = vertices_vec.data();
        int width = image.getWidth();
        int height = image.getHeight();

        Surface * view = new Surface("image: "+file_name, width, height);
        view->getRenderer()->setImage(vertices, width, height);
        view->loop();

        delete vertices;
        delete view;
    }

    if(extension == "jpg" || extension == "jpeg") {
        JPEG image;
        image.read(file_name);

        /*std::vector<float> vertices_vec = image.toArray();
        float *vertices = vertices_vec.data();
        int width = image.getWidth();
        int height = image.getHeight();

        Surface * view = new Surface("image: "+file_name, width, height);
        view->getRenderer()->setImage(vertices, width, height);
        view->loop();

        delete vertices;
        delete view;*/
    }

    if(extension == "png") {
        //
    }

    if(extension == "mp4") {
        //
    }

    return 1;
}
