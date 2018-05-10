#include "tabla.h"

int main()
{
  Tabla prva;
  prva.prikaz();
  prva.tabla[0][1]->pomeri(2,2);
  system("sleep 5");
  system("clear");
  prva.prikaz();
  return 0;
}
