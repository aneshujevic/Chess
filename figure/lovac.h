#ifndef LOVAC_H
#define LOVAC_H
#include "../figura.h"

class Lovac : public Figura
{
public:
  Lovac(int, int, bool);
  void pomeri(int x,int y);
};

#endif
