#include "tabla.h"
#include "potez.h"
#include "interface.h"
#include <iostream>
#include <string>

using namespace std;

bool pojeden_kralj = false;


int main()
{
  int from_x;
  int from_y;
  int to_x;
  int to_y;
  string from_unos;
  string to_unos;
  string player1;
  string player2;
  Tabla prva;

  bool beli_na_potezu = true;

  clear_screen();
  cout << "\n\n\n\n\n\t\t\tDOBRODOSLI U MALU SKOLU SAHA\n\n\n\n";
  wait_msg();
  clear_screen();

  while(1)
  {
    bool kraj=false;
    cout<<"Molimo da prvi igrac unese svoje ime:";
    cin>>player1;
    cout<<"Molimo da drugi igrac unese svoje ime:";
    cin>>player2;
    
    if(same_strings(player1,player2))
    {
        cout<<"Molimo da unesete razlicita imena igraca."<<endl;
        wait_msg();
        clear_screen();
    }
    else
        kraj=true;
    
    if(kraj) break;
  }

        
  
  
  while (true)
  {
    fflush(stdout);
    clear_screen();

    if(sah(beli_na_potezu, &prva))
    {
        cout << "\n\n\n\n\n\t\t\tSAH!\n\n\n\n";
        wait_msg();
        clear_screen();
    }

    if (pojeden_kralj)
    {
      if (beli_na_potezu)
        cout << "Bravo "<<player2<<", pobedio/la si." << endl;
      else
        cout << "Bravo "<<player1<<", pobedio/la si." << endl;
      continue;
    }

    prva.prikaz();

    if (beli_na_potezu)
      cout << "Na potezu je "<<player1<<".. \t\t*Bele figure*" << endl;
    else
      cout << "Na potezu je "<<player2<<".. \t\t*Crne figure*" << endl;

    cout << "Unesite koordinate figure koju zelite pomeriti: ";
    cin >> from_unos;

    if (!make_input(from_unos, from_x, from_y))
    {
      wait_msg();
      continue;
    }
    else if (prva.tabla[from_x][from_y] == nullptr)
    {
      cout << "Ne postoji figura na toj poziciji!" << endl;
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
      cout << "Ne mozete da pomerate protivnicke figure." << endl
           << "Pokusajte ponovo." << endl;
      wait_msg();
      continue;
    }

    if (!prva.tabla[from_x][from_y]->pomeri(to_x, to_y))
    {
      wait_msg(); //Nakon ispisa poruke ceka dve sekunde pre nego sto predje u novu iteraciju i samim tim ocisti ekran
      continue;
    }
    beli_na_potezu = !beli_na_potezu; //Menja se koje je boje igrac na potezu
  }

  return 0;
}
