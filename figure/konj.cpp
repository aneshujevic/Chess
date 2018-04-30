#include "konj.h"
#include "../figura.h"

Konj::Konj(int x, int y, bool b) : Figura(b, x, y)
{
  if (bela)
    simbol = "\u2658";
  else
    simbol = "\u265e";
}
