#include "tabla.h"
#include "potez.h"
#include <iostream>
#include <string>


using namespace std;

void clear_screen()
{
#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
  system("clear");
#endif
}

void wait_msg()
{
#if defined(_WIN32) || defined(_WIN64)
  system("TIMEOUT /T 2");
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
  system("sleep 2");
#endif
}

int main()
{
  int from_x;
  int from_y;
  int to_x;
  int to_y;
  string from_unos;
  string to_unos;
  Tabla prva;

  bool beli_na_potezu = true;

  clear_screen();
  cout<<"\n\n\n\n\n\t\t\tDOBRODOSLI U MALU SKOLU SAHA HEHEEHEHE\n\n\n\n";
  system("sleep 5");
  clear_screen();

  while(true)
  {
    fflush(stdout);
    clear_screen();
    prva.prikaz();
    
    if(beli_na_potezu)
        cout<<"Na potezu je igrac cije su figure bele.."<<endl;
    else
        cout<<"Na potezu je igrac cije su figure crne.."<<endl;

    cout << "Unesite koordinate figure koju zelite pomeriti: ";
    cin >> from_unos;
    
  
     if (!make_input(from_unos, from_x, from_y))
     {
      wait_msg();
      continue;
     }
     else if(prva.tabla[from_x][from_y] == nullptr )         
    {
        cout<<"Ne postoji figura na toj poziciji1!"<<endl;
        wait_msg();
        continue;
    }
    

    cout << "Unesite koordinate polja na koje pomerate figuru: ";
    cin >> to_unos;
    
     if (!make_input(to_unos, to_x, to_y))
     {
      wait_msg();
      continue;
     }
     
    if (prva.tabla[from_x][from_y]->get_bela() != beli_na_potezu)
    {
      cout << "Ne mozete da pomerate protivnicke figure." << endl << "Pokusajte ponovo." << endl;
      wait_msg();
      continue;
    }

    if(!prva.tabla[from_x][from_y]->pomeri(to_x, to_y))
    {
      wait_msg();                       //Nakon ispisa poruke ceka dve sekunde pre nego sto predje u novu iteraciju i samim tim ocisti ekran
      continue;
    }
    beli_na_potezu = !beli_na_potezu;  //Menja se koje je boje igrac na potezu
  }

  return 0;
}
