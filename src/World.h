#ifndef WORLD_H

class World {
protected:
  GLuint vao;
  GLuint vbo;
  GLuint vertexShader;
  GLuint fragmentShader;
  GLuint shaderProgram;

  GLuint loadShader(GLuint type, const GLchar* shaderCode);
public:
  World();
  ~World();
  void draw();
};

#endif //WORLD_H
