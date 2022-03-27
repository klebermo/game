#ifndef SURFACE2D_H
#define SURFACE2D_H

#include "Surface.h"

class Surface2d : public Surface {
private:
  //
public:
  Surface2d(string windows_title, int width, int height);
  ~Surface2d();

  void loop(float * array);
};

#endif //SURFACE2D_H
