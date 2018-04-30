#ifndef TABLA_H
#define TABLA_H
#include "figura.h"

class
Tabla
{
private:
  Figura ***tabla;

public:
  Tabla();
  ~Tabla();
  void prikaz();
};


#endif
