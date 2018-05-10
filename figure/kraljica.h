#ifndef KRALJICA_H
#define KRALJICA_H

#include "../figura.h"

class Kraljica : public Figura
{
public:
  Kraljica(int, int, bool);
  void pomeri(int x,int y);
};

#endif
