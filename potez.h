#ifndef POTEZ_H
#define POTEZ_H

#include <iostream>
#include <cstdlib>
#include "tabla.h"

#include "figura.h"
#include "figure/konj.h"
#include "figure/kralj.h"
#include "figure/kraljica.h"
#include "figure/lovac.h"
#include "figure/pijun.h"
#include "figure/top.h"

using namespace std;

bool make_input(string, int &, int &);

void pijun_do_kraja(int, int, Tabla *, bool);

bool sah(bool, Tabla *);

#endif
