#ifndef SURFACE3D_H
#define SURFACE3D_H

#include "Surface.h"

class Surface3d : public Surface {
private:
  //
public:
  Surface3d(string windows_title, int width, int height);
  ~Surface3d();

  void loop();
};

#endif //SURFACE3D_H
