#ifndef LOVAC_H
#define LOVAC_H
#include "../figura.h"
#include "../tabla.h"

class Lovac : public Figura
{
private:
  Tabla *prva;

public:
  Lovac(int, int, bool, Tabla *);
  bool pomeri(int x, int y);
};

#endif
