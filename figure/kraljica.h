#ifndef KRALJICA_H
#define KRALJICA_H

#include "../figura.h"
#include "../tabla.h"

class Kraljica : public Figura
{
private:
  Tabla *prva;

public:
  Kraljica(int, int, bool, Tabla *);
  bool pomeri(int x, int y);
};

#endif
