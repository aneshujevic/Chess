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

void pijun_do_kraja(int x, int y, Tabla *prva, bool bela)
{
    int izbor;
    cout << "Izaberite koju figuru zelite na mesto pijuna:" << endl;
    cout << "1. Kraljica" << endl;
    cout << "2. Konj" << endl;
    cout << "3. Top" << endl;
    cout << "4. Lovac" << endl;
    cout << "5. Pijun" << endl;
    cin >> izbor;

    switch(izbor)
    {
        case 1:
            prva->tabla[x][y] = new Kraljica(x, y, bela, prva);
            break;
        case 2:
            prva->tabla[x][y] = new Konj(x, y, bela, prva);
            break;
        case 3:
            prva->tabla[x][y] = new Top(x, y, bela, prva);
            break;
        case 4:
            prva->tabla[x][y] = new Lovac(x, y, bela, prva);
            break;
        case 5: break;

        default:
            cout << "Unesite odgovarajuci broj!" << endl;
            pijun_do_kraja(x, y, prva, bela);
    }

}