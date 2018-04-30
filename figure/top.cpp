#include "top.h"
#include "../figura.h"

Top::Top(int x,int y,bool b): Figura(b,x,y)
{
  if(bela)
    simbol="\u2656";
  else
    simbol="\u265c";
}
