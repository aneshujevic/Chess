#include "kralj.h"
#include "../figura.h"

Kralj::Kralj(int x, int y, bool b, Tabla *prva) : Figura(b, x, y)
{
  this->prva = prva;

  if (bela)
    simbol = "\u2654";
  else
    simbol = "\u265a";
}

bool Kralj::pomeri(int x, int y)
{
  if (x < 0 || x > 7 || y < 0 || y > 7)
  {
    cout << RED BOLD << "Nije moguce izvrsiti potez." << RESET << endl;
    return false;
  }

  if (abs(x - pozicija_x) > 1 || abs(y - pozicija_y) > 1)
  {
    cout << RED BOLD << "Nije moguce izvrsiti potez. Krece se vise od jednog polja." << RESET << endl;
    return false;
  }

  if (prva->tabla[x][y] != nullptr && prva->tabla[x][y]->get_bela() == this->get_bela())
  {
    cout << RED BOLD << "Nije moguce izvrsiti potez. Ne mozete jesti svoje figure." << RESET << endl;
    return false;
  }

  int px = pozicija_x;
  int py = pozicija_y;
  pozicija_x = x;
  pozicija_y = y;
  prva->tabla[x][y] = this;
  prva->tabla[px][py] = nullptr;
  return true;
}
