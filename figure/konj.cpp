#include "konj.h"
#include "../figura.h"

Konj::Konj(int x, int y, bool b, Tabla *prva) : Figura(b, x, y)
{
  this->prva=prva;
  if (bela)
    simbol = "\u2658";
  else
    simbol = "\u265e";
}

void Konj::pomeri(int x,int y)
{
  if( x < 0 || x > 7 || y < 0 || y > 7)
  {
    cout << "Nije moguce izvrsiti potez." << endl;
    return;
  }

  if( (abs(pozicija_x - x) == 2 && abs(pozicija_y - y) == 1) ||
      (abs(pozicija_x - x) == 1 && abs(pozicija_y - y) == 2)  )
  {
    if(prva->tabla[x][y] != NULL)
    {
      if(prva->tabla[x][y]->get_bela() == this->get_bela())
      {
         cout<<"Nije moguce izvrsiti potez."<<endl;
         return;
      }
      else
      {
          //TODO SLANJE NA GROBALJE POJEBENE FIGURE
      }
    }
    int px=pozicija_x;
    int py=pozicija_y;
    pozicija_x=x;
    pozicija_y=y;
    prva->tabla[x][y]=this;
    prva->tabla[px][py]=nullptr;
  }
}
