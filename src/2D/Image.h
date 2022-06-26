#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <sstream>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Image {
private:
    std::vector<float> vertexList;
    int width;
    int height;

    GLuint vao;
    GLuint vbo;
    GLuint mProgram;
    GLuint vertexShader;
    GLuint fragmentShader;

    const GLchar* vertexSource =
    "#version 150 core\n"
    "in vec2 position;"
    "in vec3 color;"
    "out vec3 Color;"
    "void main() {"
    "   Color = color;"
    "   gl_Position = vec4(position, 0.0, 1.0);"
    "}";

    const GLchar* fragmentSource =
    "#version 150 core\n"
    "in vec3 Color;"
    "out vec4 outColor;"
    "void main() {"
    "   outColor = vec4(Color, 1.0);"
    "}";
public:
    Image(std::vector<float> v, int w, int h);
    void init();
    void draw();
    void exit();
    int size();
    GLuint loadShader(GLuint type, const GLchar* shaderCode);
};

#endif
