#include "kraljica.h"
#include "../figura.h"

extern bool pojeden_kralj;

Kraljica::Kraljica(int x, int y, bool b, Tabla *prva) : Figura(b, x, y)
{
  this->prva = prva;

  if (bela)
    simbol = "\u2655";
  else
    simbol = "\u265b";
}
bool Kraljica::pomeri(int x, int y)
{
  if (x < 0 || x > 7 || y < 0 || y > 7)
  {
    cout << "Nije moguce izvrsiti potez. Polje je van table" << endl;
    return false;
  }

  if (!((x == pozicija_x && y != pozicija_y) || (x != pozicija_x && y == pozicija_y))
    && (abs(x - pozicija_x) != abs(y - pozicija_y)))
  {
    cout << "Nije moguce izvrsiti potez. Kraljicom se ne moze kretati na taj nacin." << endl;
    return false;
  }



  if (x > pozicija_x)
  {
    for (int i = pozicija_x + 1; i < x - 1; i++)
    {
      if (prva->tabla[i][pozicija_y] != nullptr)
      {
        cout << "Nije moguce izvrsiti potez. Ne mozete preskakati figure." << endl;
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
        cout << "Nije moguce izvrsiti potez. Ne mozete preskakati figure." << endl;
        return false;
      }
    }
  }
  else if (y > pozicija_y)
  {
    for (int i = pozicija_y + 1; i < y - 1; i++)
    {
      if (prva->tabla[i][pozicija_y] != nullptr)
      {
        cout << "Nije moguce izvrsiti potez. Ne mozete preskakati figure." << endl;
        return false;
      }
    }
  }
  else if (y < pozicija_y)
  {
    for (int i = pozicija_y - 1; i > y + 1; i--)
    {
      if (prva->tabla[i][pozicija_y] != nullptr)
      {
        cout << "Nije moguce izvrsiti potez. Ne mozete preskakati figure." << endl;
        return false;
      }
    }
  }
  else if (x > pozicija_x && y > pozicija_y)
  {
    for (int i = pozicija_x + 1, j = pozicija_y + 1; i < x && j < y; i++, j++)
    {
      if (prva->tabla[i][j] != NULL)
      {
        cout << "Nije moguce preskakati figure kraljicom!" << endl;
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
        cout << "Nije moguce preskakati figure kraljicom!" << endl;
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
        cout << "Nije moguce preskakati figure kraljicom!" << endl;
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
        cout << "Nije moguce preskakati figure kraljicom!" << endl;
        return false;
      }
    }
  }

  if (prva->tabla[x][y] != nullptr && prva->tabla[x][y]->get_bela() == this->get_bela())
  {
    cout << "Nije moguce izvrsiti potez. Ne mozete jesti svoje figure." << endl;
    return false;
  }

  if (prva->tabla[x][y] != nullptr && (prva->tabla[x][y]->get_simbol() == "\u2654" || prva->tabla[x][y]->get_simbol() == "\u265a"))
      pojeden_kralj = true;

  int px = pozicija_x;
  int py = pozicija_y;
  pozicija_x = x;
  pozicija_y = y;
  prva->tabla[x][y] = this;
  prva->tabla[px][py] = nullptr;
  return true;
}
