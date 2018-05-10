#include "tabla.h"

int main()
{
  Tabla prva;
  prva.prikaz();
  prva.tabla[0][2]->pomeri(2,4);

  prva.prikaz();
  return 0;
}
