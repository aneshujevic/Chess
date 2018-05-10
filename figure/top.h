#ifndef TOP_H
#define TOP_H
#include "../figura.h"

class Top : public Figura
{
public:
  Top(int, int, bool);
  void pomeri(int x, int y);
};

#endif
