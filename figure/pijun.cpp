#include "pijun.h"
#include "../figura.h"

Pijun::Pijun(int x, int y, bool b): Figura(b, x, y)
{
  if (bela)
  {
    simbol = "\u2659";
  }
  else
  {
    simbol = "\u265f";
  }
}
