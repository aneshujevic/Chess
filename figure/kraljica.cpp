#include "kraljica.h"
#include "../figura.h"

Kraljica::Kraljica(int x, int y, bool b) : Figura(b, x, y)
{
  if (bela)
    simbol = "\u2655";
  else
    simbol = "\u265b";
}
void Kraljica::pomeri(int x, int y) {}
