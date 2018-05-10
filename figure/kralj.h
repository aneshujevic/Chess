#ifndef KRALJ_H
#define KRALJ_H

#include "../figura.h"
#include "../tabla.h"

class Kralj : public Figura
{
private:
  Tabla *prva;

public:
  Kralj(int, int, bool, Tabla *);
  void pomeri(int x, int y);
};

#endif
