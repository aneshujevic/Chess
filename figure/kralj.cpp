#include "kralj.h"
#include "../figura.h"

Kralj::Kralj(int x, int y, bool b) : Figura(b, x, y)
{
  if (bela)
    simbol = "\u2654";
  else
    simbol = "\u2654";
}
