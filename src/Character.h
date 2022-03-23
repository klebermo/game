#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
protected:
  //
public:
  Character();
  ~Character();
  virtual void draw() = 0;
};

#endif //CHARACTER_H
