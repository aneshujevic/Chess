#ifndef PIJUN_H
#define PIJUN_H

#include "../figura.h"
#include "../tabla.h"

class Pijun : public Figura
{
private:
  Tabla *prva;

public:
  Pijun(int, int, bool, Tabla *);
  void pomeri(int x, int y);
};

#endif
