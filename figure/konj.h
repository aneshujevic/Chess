#ifndef KONJ_H
#define KONJ_H
#include "../figura.h"
#include "../tabla.h"

class Konj : public Figura
{
private:
  Tabla *prva;
public:
  Konj(int, int, bool, Tabla*);
  void pomeri(int x,int y);
};

#endif
