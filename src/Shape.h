#ifndef SHAPE_H
#define SHAPE_H

class Shape {
protected:
  //
public:
  Shape();
  ~Shape();
  virtual void draw() = 0;
};

#endif //SHAPE_H
