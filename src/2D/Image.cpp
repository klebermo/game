#include "Image.h"

Image::Image(float * values, int width, int height) {
  this->vertexList = values;
  this->width = width;
  this->height = height;
}

Image::~Image() {
  glDeleteProgram(mProgram);
  glDeleteShader(fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
}

void Image::init() {
  // Create Vertex Array Object
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // Create a Vertex Buffer Object and copy the vertex data to it
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, this->size() * sizeof(float), this->vertexList, GL_STATIC_DRAW);

  vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
  fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);

  mProgram = glCreateProgram();
  glAttachShader(mProgram, vertexShader);
  glAttachShader(mProgram, fragmentShader);
  glBindFragDataLocation(mProgram, 0, "outColor");
  glLinkProgram(mProgram);
}

void Image::draw() {
  glUseProgram(mProgram);

  // Specify the layout of the vertex data
  GLint posAttrib = glGetAttribLocation(mProgram, "position");
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

  // Get the location of the color uniform
  GLint colAttrib = glGetAttribLocation(mProgram, "color");
  glEnableVertexAttribArray(colAttrib);
  glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

  // Clear the screen to black
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw a triangle from the 3 vertices
  glDrawArrays(GL_POINTS, 0, this->size());
}

int Image::size() {
  return 5*width*height;
}

GLuint Image::loadShader(GLuint type, const GLchar* shaderCode) {
  GLuint shader = glCreateShader(type);
  glShaderSource(shader, 1, &shaderCode, NULL);
  glCompileShader(shader);
  return shader;
}