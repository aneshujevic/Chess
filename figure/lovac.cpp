#include "lovac.h"
#include "../figura.h"

Lovac::Lovac(int x, int y, bool b) : Figura(b, x, y)
{
  if (bela)
    simbol = "\u2657";
  else
    simbol = "\u265d";
}
void Lovac::pomeri(int x,int y){}
