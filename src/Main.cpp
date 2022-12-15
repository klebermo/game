#include "2D/Surface.hpp"

#include "netpbm.hpp"
#include "jpeg.h"
#include "png.h"

#include <chrono>
#include <random>
using namespace std;

int random_number();
std::vector<std::vector<int>> get_matrix(int width, int height);
std::vector<std::vector<pixel>> generate_pbm(int width, int height);
std::vector<std::vector<pixel>> generate_pgm(int width, int height);
std::vector<std::vector<pixel>> generate_ppm(int width, int height);

int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cout << "Usage: game <file_name>" << std::endl;
        return 0;
    }

    std::string opt(argv[1]);
    if(!opt.empty()) {
        if(opt == "-h" || opt == "--help") {
            std::cout << "Usage: game <file_name>" << std::endl;
            return 0;
        }

        if(opt == "pbm") {
            Bitmap image;
            image.setPixels(generate_pbm(400, 400));
            image.write_ascii_file("test1.pbm");
            image.write_binary_file("test2.pbm");
            return 0;
        }

        if(opt == "pgm") {
            Graymap image;
            image.setMaxValue(255);
            image.setPixels(generate_pgm(400, 400));
            image.write_ascii_file("test1.pgm");
            image.write_binary_file("test2.pgm");
            return 0;              
        }

        if(opt == "ppm") {
            Pixmap2 image;
            image.setMaxValue(255);
            image.setPixels(generate_ppm(400, 400));
            image.write_ascii_file("test1.ppm");
            image.write_binary_file("test2.ppm");
            return 0;
        }
    }

    if (SDL_Init(SDL_INIT_VIDEO) >= 0) {
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

        if(extension == "png") {
            //
        }

        if(extension == "mp4") {
            //
        }

        SDL_Quit();
    }

    return 1;
}

int random_number(int max_value) {
    random_device rd;
    mt19937::result_type seed = rd() ^ ( (mt19937::result_type) chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count() + (mt19937::result_type) chrono::duration_cast<chrono::microseconds>( chrono::high_resolution_clock::now().time_since_epoch() ).count() );
    mt19937 gen(seed);
    mt19937::result_type n = gen();
    return n % max_value;
}

std::vector<std::vector<int>> get_matrix(int width, int height) {
    std::vector<std::vector<int>> result;
    for(int i=0; i<height; i++) {
        std::vector<int> row;
        for(int j=0; j<width; j++)
            row.push_back(random_number(255));
        result.push_back(row);
    }
    return result;
}

std::vector<std::vector<pixel>> generate_pbm(int width, int height) {
    std::vector<std::vector<pixel>> image;

    std::vector<std::vector<int>> pixels = get_matrix(width, height);
    for(int i=0; i<height; i++)  {
        std::vector<pixel> row;
        for(int j=0; j<width; j++) {
            pixel p;
            p.r = p.g = p.b = pixels[i][j] % 2? 0 : 1;
            row.push_back(p);
        }
        image.push_back(row);
    }
    
    return image;
}

std::vector<std::vector<pixel>> generate_pgm(int width, int height) {
    std::vector<std::vector<pixel>> image;

    std::vector<std::vector<int>> pixels = get_matrix(width, height);
    for(int i=0; i<height; i++) {
        std::vector<pixel> row;
        for(int j=0; j<width; j++) {
            pixel p;
            p.r = p.g = p.b = pixels[i][j];
            row.push_back(p);
        }
        image.push_back(row);
    }
    
    return image;
}

std::vector<std::vector<pixel>> generate_ppm(int width, int height) {
    std::vector<std::vector<pixel>> image;

    std::vector<std::vector<int>> r = get_matrix(width, height);
    for(int i=0; i<height; i++) {
        std::vector<pixel> row;
        for(int j=0; j<width; j++) {
            pixel p;
            p.r = p.g = p.b = r[i][j];
            row.push_back(p);
        }
        image.push_back(row);
    }
    
    std::vector<std::vector<int>> g = get_matrix(width, height);
    for(int i=0; i<height; i++) {
        std::vector<pixel> row;
        for(int j=0; j<width; j++) {
            pixel p;
            p.r = p.g = p.b = g[i][j];
            row.push_back(p);
        }
        image.push_back(row);
    }
    
    std::vector<std::vector<int>> b = get_matrix(width, height);
    for(int i=0; i<height; i++) {
        std::vector<pixel> row;
        for(int j=0; j<width; j++) {
            pixel p;
            p.r = p.g = p.b = b[i][j];
            row.push_back(p);
        }
        image.push_back(row);
    }

    return image;
}
