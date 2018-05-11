#ifndef TOP_H
#define TOP_H
#include "../figura.h"
#include "../tabla.h"

class Top : public Figura
{
private:
  Tabla *prva;

public:
  Top(int, int, bool, Tabla *);
  bool pomeri(int x, int y);
};

#endif
