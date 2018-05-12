#include "top.h"
#include "../figura.h"

Top::Top(int x, int y, bool b, Tabla *prva) : Figura(b, x, y)
{
  this->prva = prva;
  if (bela)
    simbol = "\u2656";
  else
    simbol = "\u265c";
}
bool Top::pomeri(int x, int y)
{
  if (x < 0 || x > 7 || y < 0 || y > 7)
  {
    cout << "Nije moguce izvrsiti potez. Polje je van table" << endl;
    return false;
  }

  if (!((x == pozicija_x && y != pozicija_y) || (x != pozicija_x && y == pozicija_y)))
  {
    cout << "Nije moguce izvrsiti potez. Top se ne moze kretati ukoso." << endl;
    return false;
  }

  if (x > pozicija_x)
  {
    for (int i = pozicija_x + 1; i < x - 1; i++)
    {
      if (prva->tabla[i][pozicija_y] != nullptr)
      {
        cout << "Nije moguce izvrsiti potez. Ne mozete preskakati figure. 1" << endl;
        return false;
      }
    }
  }
  else if (x < pozicija_x)
  {
    for (int i = pozicija_x - 1; i > x + 1; i--)
    {
      if (prva->tabla[i][pozicija_y] != nullptr)
      {
        cout << "Nije moguce izvrsiti potez. Ne mozete preskakati figure. 2" << endl;
        return false;
      }
    }
  }
  else if (y > pozicija_y)
  {
    for (int i = pozicija_y + 1; i < y - 1; i++)
    {
      if (prva->tabla[pozicija_x][i] != nullptr)
      {
        cout << "Nije moguce izvrsiti potez. Ne mozete preskakati figure. 3" << endl;
        return false;
      }
    }
  }
  else
  {
    for (int i = pozicija_y - 1; i > y + 1; i--)
    {
      if (prva->tabla[pozicija_x][i] != nullptr)
      {
        cout << "Nije moguce izvrsiti potez. Ne mozete preskakati figure. 4" << endl;
        return false;
      }
    }
  }
  int px = pozicija_x;
  int py = pozicija_y;
  pozicija_x = x;
  pozicija_y = y;
  prva->tabla[x][y] = this;
  prva->tabla[px][py] = nullptr;
  return true;
}
