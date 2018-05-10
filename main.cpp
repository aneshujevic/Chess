#include "tabla.h"

int main()
{
  Tabla prva;
  prva.prikaz();
  prva.tabla[7][6]->pomeri(5,5);
  prva.prikaz();
  prva.tabla[5][5]->pomeri(4, 3);
  prva.prikaz();
  prva.tabla[4][3]->pomeri(2, 4);
  prva.prikaz();
  prva.tabla[2][4]->pomeri(0, 3);
  prva.prikaz();
  prva.tabla[0][3]->pomeri(2, 2);
  prva.prikaz();

  prva.tabla[6][1]->pomeri(4, 1);
  prva.prikaz();
  prva.tabla[4][1]->pomeri(3, 1);
  prva.prikaz();
  prva.tabla[3][1]->pomeri(2, 1);
  prva.prikaz();
  prva.tabla[2][1]->pomeri(1, 2);
  prva.prikaz();
  return 0;
}
