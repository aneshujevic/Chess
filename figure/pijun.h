#ifndef PIJUN_H
#define PIJUN_H

#include "../figura.h"

class Pijun : public Figura
{
public:
  Pijun(int, int, bool);
  void pomeri(int x,int y);
};

#endif
