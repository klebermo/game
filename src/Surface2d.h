#ifndef SURFACE2D_H
#define SURFACE2D_H

#include "Surface.h"

class Surface2d : public Surface {
private:
  //
public:
  Surface2d();
  Surface2d(string windows_title);
  ~Surface2d();

  void loop();
};

#endif //SURFACE2D_H
