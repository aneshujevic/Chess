#ifndef FIG_H
#define FIG_H

#include <cmath>
#include <string>
#include <iostream>
#include "colors.h"

using namespace std;

class Figura
{
protected:
  bool bela;
  int pozicija_x;
  int pozicija_y;
  std::string simbol;

public:
  Figura();
  Figura(bool, int, int);
  bool get_bela();
  void set_x(int);
  void set_y(int);
  void set_pozicija(int, int);
  void set_simbol(std::string);
  int get_x();
  int get_y();
  std::string get_simbol();
  virtual bool pomeri(int, int) = 0;
};

#endif
