#include "Image.h"

const GLchar * Image::vertexShaderCode() {
  const GLchar* vertexSource =
  "#version 150 core\n"
  "in vec2 position;"
  "in vec3 color;"
  "out vec3 Color;"
  "void main() {"
  "   Color = color;"
  "   gl_Position = vec4(position, 0.0, 1.0);"
  "}";
  return vertexSource;
}

const GLchar * Image::fragmentShaderCode() {
  const GLchar* fragmentSource =
  "#version 150 core\n"
  "in vec3 Color;"
  "out vec4 outColor;"
  "void main() {"
  "   outColor = vec4(Color, 1.0);"
  "}";
  return fragmentSource;
}

GLuint Image::loadShader(GLuint type, const GLchar* shaderCode) {
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &shaderCode, NULL);
  glCompileShader(shader);
  return shader;
}

Image::Image(float * values, int size) {
  this->vertexList = values;
  this->size = size;
  // Create Vertex Array Object
  glGenVertexArrays(1, &this->vao);
  glBindVertexArray(vao);

  // Create a Vertex Buffer Object and copy the vertex data to it
  glGenBuffers(1, &this->vbo);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, this->size * sizeof(float), this->vertexList, GL_STATIC_DRAW);

  vertexShader = loadShader(GL_VERTEX_SHADER, vertexShaderCode());
  fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentShaderCode());

  mProgram = glCreateProgram();
  glAttachShader(mProgram, vertexShader);
  glAttachShader(mProgram, fragmentShader);
  glBindFragDataLocation(mProgram, 0, "outColor");
  glLinkProgram(mProgram);
}

Image::~Image() {
  glDeleteProgram(this->mProgram);
  glDeleteShader(this->fragmentShader);
  glDeleteShader(this->vertexShader);
  glDeleteBuffers(1, &this->vbo);
  glDeleteVertexArrays(1, &this->vao);
}

void Image::draw() {
  glUseProgram(this->mProgram);

  // Specify the layout of the vertex data
  GLint posAttrib = glGetAttribLocation(this->mProgram, "position");
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

  // Get the location of the color uniform
  GLint colAttrib = glGetAttribLocation(this->mProgram, "color");
  glEnableVertexAttribArray(colAttrib);
  glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

  // Clear the screen to black
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw a triangle from the 3 vertices
  glDrawArrays(GL_POINTS, 0, this->size);
}

float * Image::getVertices() {
  return vertexList;
}

int Image::getWidth() {
  return width;
}

int Image::getHeight() {
  return height;
}

int Image::getSize() {
  return 5*width*height;
}
