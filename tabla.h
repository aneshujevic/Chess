#ifndef TABLA_H
#define TABLA_H
#include "figura.h"

class Tabla
{
public:
  Figura ***tabla;
  Tabla();
  ~Tabla();
  void prikaz();
};

#endif
