#include "potez.h"


bool make_input(string unos, int &x, int &y)
{
    if (!isdigit(unos[1]))
    {
        cout << "Neispravan unos." << endl;
        return false;
    }

    if (!isalpha(unos[0]))
    {
        cout << "Pogresan unos." << endl;
        return false;
    }
    int broj = atoi(&unos[1]);
    unos[0]=toupper(unos[0]);

    switch(unos[0])
    {
        case 'A': y = 0; break;
        case 'B': y = 1; break;
        case 'C': y = 2; break;
        case 'D': y = 3; break;
        case 'E': y = 4; break;
        case 'F': y = 5; break;
        case 'G': y = 6; break;
        case 'H': y = 7; break;
        default: cout << "Pogresan unos." << endl << "Pokusajte ponovo:" << endl; return false;
    }

    if (broj - 1 < 0 || broj - 1 > 7)
    {
        cout << "Pogresan unos." << endl << "Pokusajte ponovo:" << endl;
        return false;
    }
    x = 8 - broj;
    return true;
}
