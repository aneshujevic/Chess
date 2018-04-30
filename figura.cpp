#include "figura.h"

Figura::Figura()
{
  bela = true;
  pozicija_x = pozicija_y = 0;
  simbol = "X";
}

Figura::Figura(bool bela, int x, int y)
{
  this->bela = bela;
  pozicija_x = x;
  pozicija_y = y;
  simbol = "X";
}

void Figura::set_x(int x)
{
  pozicija_x = x;
}

void Figura::set_y(int y)
{
  pozicija_y = y;
}

void Figura::set_pozicija(int x, int y)
{
  pozicija_x = x;
  pozicija_y = y;
}

void Figura::set_simbol(std::string simbol)
{
  this->simbol = simbol;
}

int Figura::get_y()
{
  return pozicija_y;
}

int Figura::get_x()
{
  return pozicija_x;
}

std::string
Figura::get_simbol()
{
  return simbol;
}
