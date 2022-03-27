#include "World.h"

World::World(GLfloat * vertices) {
  this->vertexList = vector<float>(vertices, vertices + sizeof(vertices) / sizeof(float));

  // Create Vertex Array Object
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  // Create a Vertex Buffer Object and copy the vertex data to it
  glGenBuffers(1, &vbo);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, this->vertices().size() * sizeof(float), this->vertices().data(), GL_STATIC_DRAW);

  vertexShader = loadShader(GL_VERTEX_SHADER, vertexShaderCode().c_str());
  fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentShaderCode().c_str());

  mProgram = glCreateProgram();
  glAttachShader(mProgram, vertexShader);
  glAttachShader(mProgram, fragmentShader);
  glLinkProgram(mProgram);
}

World::~World() {
  glDeleteProgram(this->mProgram);
  glDeleteShader(this->fragmentShader);
  glDeleteShader(this->vertexShader);
}

void World::draw() {
  glUseProgram(this->mProgram);

  // Specify the layout of the vertex data
  GLint posAttrib = glGetAttribLocation(mProgram, "position");
  glEnableVertexAttribArray(posAttrib);
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

  // Get the location of the color uniform
  GLint uniColor = glGetUniformLocation(mProgram, "triangleColor");
  glUniform3f(uniColor, 2.0f, 0.0f, 0.0f);

  // Clear the screen to black
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Draw a triangle from the 3 vertices
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

vector<float> World::vertices() {
  return vertexList;
}

string World::vertexShaderCode() {
  const GLchar* vertexSource =
      "#version 150 core\n"
      "in vec2 position;"
      "void main() {"
      "   gl_Position = vec4(position, 0.0, 1.0);"
      "}";
  return string(vertexSource);
}

string World::fragmentShaderCode() {
  const GLchar* fragmentSource =
      "#version 150 core\n"
      "out vec4 outColor;"
      "uniform vec3 triangleColor;"
      "void main() {"
      "   outColor = vec4(triangleColor, 1.0);"
      "}";
  return string(fragmentSource);
}
