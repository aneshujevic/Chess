#include "lovac.h"
#include "../figura.h"

Lovac::Lovac(int x, int y, bool b, Tabla *prva) : Figura(b, x, y)
{
  this->prva = prva;
  if (bela)
    simbol = "\u2657";
  else
    simbol = "\u265d";
}
bool Lovac::pomeri(int x, int y)
{
  if (x < 0 || x > 7 || y < 0 || y > 7)
  {
    cout << "Nije moguce izvrsiti potez." << endl;
    return false;
  }

  if (abs(x - pozicija_x) != abs(y - pozicija_y))
  {
    cout << "Nije moguce izvrsiti potez." << endl;
    return false;
  }

  if (x > pozicija_x && y > pozicija_y)
  {
    for (int i = pozicija_x + 1, j = pozicija_y + 1; i < x && j < y; i++, j++)
    {
      if (prva->tabla[i][j] != NULL)
      {
        cout << "Nije moguce preskakati figure lovcem!" << endl;
        return false;
      }
    }
  }
  else if (x > pozicija_x && y < pozicija_y)
  {
    for (int i = pozicija_x + 1, j = pozicija_y - 1; i < x && j > y; i++, j--)
    {
      if (prva->tabla[i][j] != NULL)
      {
        cout << "Nije moguce preskakati figure lovcem!" << endl;
        return false;
      }
    }
  }
  else if (x < pozicija_x && y > pozicija_y)
  {
    for (int i = pozicija_x - 1, j = pozicija_y + 1; i > x && j < y; i--, j++)
    {
      if (prva->tabla[i][j] != NULL)
      {
        cout << "Nije moguce preskakati figure lovcem!" << endl;
        return false;
      }
    }
  }
  else
  {
    for (int i = pozicija_x - 1, j = pozicija_y - 1; i > x && j > y; i--, j--)
    {
      if (prva->tabla[i][j] != NULL)
      {
        cout << "Nije moguce preskakati figure lovcem!" << endl;
        return false;
      }
    }
  }

  if (prva->tabla[x][y] != NULL)
  {
    if (prva->tabla[x][y]->get_bela() == this->get_bela())
    {
      cout << "Nije moguce izvrsiti potez. Figura koju pokusavate da pojedete je iste boje." << endl;
      return false;
    }
    else
    {
      // TODO: Groblje
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
