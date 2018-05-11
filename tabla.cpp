#include "tabla.h"
#include "figura.h"
#include "figure/konj.h"
#include "figure/kralj.h"
#include "figure/kraljica.h"
#include "figure/lovac.h"
#include "figure/pijun.h"
#include "figure/top.h"
#include <iostream>

Tabla::Tabla()
{
  tabla = new Figura **[8];
  for (int i = 0; i < 8; i++)
  {
    tabla[i] = new Figura *[8];
  }

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (i == 0)
      {
        if (j == 0 || j == 7)
        {
          tabla[i][j] = new Top(i, j, false, this);
        }
        else if (j == 1 || j == 6)
        {
          tabla[i][j] = new Konj(i, j, false, this);
        }
        else if (j == 2 || j == 5)
        {
          tabla[i][j] = new Lovac(i, j, false, this);
        }
        else if (j == 3)
        {
          tabla[i][j] = new Kraljica(i, j, false, this);
        }
        else if (j == 4)
        {
          tabla[i][j] = new Kralj(i, j, false, this);
        }
      }
      else if (i == 1)
      {
        tabla[i][j] = new Pijun(i, j, false, this);
      }
      else if (i == 6)
      {
        tabla[i][j] = new Pijun(i, j, true, this);
      }
      else if (i == 7)
      {
        if (j == 0 || j == 7)
        {
          tabla[i][j] = new Top(i, j, true, this);
        }
        else if (j == 1 || j == 6)
        {
          tabla[i][j] = new Konj(i, j, true, this);
        }
        else if (j == 2 || j == 5)
        {
          tabla[i][j] = new Lovac(i, j, true, this);
        }
        else if (j == 3)
        {
          tabla[i][j] = new Kraljica(i, j, true, this);
        }
        else if (j == 4)
        {
          tabla[i][j] = new Kralj(i, j, true, this);
        }
      }
      else
      {
        tabla[i][j] = nullptr;
      }
    }
  }
}

Tabla::~Tabla()
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      delete tabla[i][j];
    }
    delete[] tabla[i];
  }
  delete[] tabla;
}

void Tabla::prikaz()
{
  for (auto i = 0; i < 8; i++)
  {
    std::cout << 8 - i << " ";
    for (auto j = 0; j < 8; j++)
    {
      if (tabla[i][j])
        std::cout << tabla[i][j]->get_simbol() << " ";
      else
      {
        if (i % 2 == j % 2)
          // std::cout << "⬛";
          std::cout << "\u2b1b";
        else
          // std::cout << "⬜";
          std::cout << "\u2b1c";
      }
    }
    std::cout << std::endl;
  }
  std::cout << "  A B C D E F G H" << std::endl;
}
