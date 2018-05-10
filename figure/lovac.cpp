#include "lovac.h"
#include "../figura.h"


Lovac::Lovac(int x, int y, bool b, Tabla *prva) : Figura(b, x, y)
{
  this->prva=prva;
  if (bela)
    simbol = "\u2657";
  else
    simbol = "\u265d";
}
void Lovac::pomeri(int x,int y)
{
  if( x < 0 || x > 7 || y < 0 || y > 7)
  {
    cout << "Nije moguce izvrsiti potez." << endl;
    return;
  }

  if( x - pozicija_x != y - pozicija_y)
  {
    cout<<"Nije moguce izvrsiti potez." << endl;
    return;
  }
  if (x > pozicija_x && y > pozicija_y)
  {
    for(int i=pozicija_x ,j=pozicija_y; i <= x && j <= y ; i++ , j++)
    {
      if(prva->tabla[i][j] != NULL)
      {
        cout<<"Nije moguce preskakati figure lovcem!"<<endl;
        return;
      }
    }
  }
  else if (x > pozicija_x && y < pozicija_y)
  {
    for(int i=pozicija_x ,j=pozicija_y; i <= x && j >= y ; i++ , j--)
    {
      if(prva->tabla[i][j] != NULL)
      {
        cout<<"Nije moguce preskakati figure lovcem!"<<endl;
        return;
      }
    }
  }
  else if (x < pozicija_x && y > pozicija_y)
  {
    for(int i=pozicija_x ,j=pozicija_y; i >= x && j <= y ; i-- , j++)
    {
      if(prva->tabla[i][j] != NULL)
      {
        cout<<"Nije moguce preskakati figure lovcem!"<<endl;
        return;
      }
    }
  }
  else
  {
    for(int i=pozicija_x ,j=pozicija_y; i >= x && j >= y ; i-- , j--)
    {
      if(prva->tabla[i][j] != NULL)
      {
        cout<<"Nije moguce preskakati figure lovcem!"<<endl;
        return;
      }
    }
  }

  if (prva->tabla[x][y] != NULL)
  {
    if (prva->tabla[x][y]->get_bela() == this->get_bela())
    {
      cout << "Nije moguce izvrsiti potez." << endl;
      return;
    }
    else
    {
      // TODO: Groblje
    }
  }

  int px=pozicija_x;
  int py=pozicija_y;
  pozicija_x=x;
  pozicija_y=y;
  prva->tabla[x][y]=this;
  prva->tabla[px][py]=nullptr;
}
