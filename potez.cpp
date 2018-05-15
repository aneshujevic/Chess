#include "potez.h"

#define C_TOP       "\u265c"
#define B_TOP       "\u2656"
#define C_KRALJ     "\u265a"
#define B_KRALJ     "\u2654"
#define C_KRALJICA  "\u265b"
#define B_KRALJICA  "\u2655"
#define C_LOVAC     "\u265d"
#define B_LOVAC     "\u2657"
#define C_KONJ      "\u265e"
#define B_KONJ      "\u2658"
#define C_PIJUN     "\u265f"
#define B_PIJUN     "\u2659"


bool make_input(string unos, int &x, int &y)
{
    if (!isdigit(unos[1]))
    {
        cout << RED BOLD << "Neispravan unos." << RESET << endl;
        return false;
    }

    if (!isalpha(unos[0]))
    {
        cout << RED BOLD << "Pogresan unos." << RESET << endl;
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
        default: cout << RED BOLD << "Pogresan unos." << endl << YEL BOLD << "Pokusajte ponovo:" << RESET << endl; return false;
    }

    if (broj - 1 < 0 || broj - 1 > 7)
    {
        cout << RED BOLD << "Pogresan unos." << endl << YEL BOLD << "Pokusajte ponovo:" << RESET << endl;
        return false;
    }
    x = 8 - broj;
    return true;
}

void pijun_do_kraja(int x, int y, Tabla *prva, bool bela)
{
    int izbor;
    cout << GRN BOLD;
    cout << "Izaberite koju figuru zelite na mesto pijuna:" << endl;
    cout << "1. Kraljica" << endl;
    cout << "2. Konj" << endl;
    cout << "3. Top" << endl;
    cout << "4. Lovac" << endl;
    cout << "5. Pijun" << endl;
    cout << RESET;
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
            cout << YEL BOLD << "Unesite odgovarajuci broj!" << RESET << endl;
            pijun_do_kraja(x, y, prva, bela);
    }

}

bool sah(bool beli_na_potezu, Tabla *prva)
{
    int kralj_x;
    int kralj_y;
    string simbol;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (prva->tabla[i][j]) {
                if (prva->tabla[i][j]->get_bela() == beli_na_potezu
                && (prva->tabla[i][j]->get_simbol() == B_KRALJ || prva->tabla[i][j]->get_simbol() == C_KRALJ))
                {
                    kralj_x = i;
                    kralj_y = j;
                    goto van_petlji;
                }
            }
        }
    }


    van_petlji:

    // Ide dole, gore, desno i levo i trazi da li ima top ili kraljica suprotne boje
    for (int i = kralj_x+1; i < 8; i++)
    {
        if (prva->tabla[i][kralj_y] && prva->tabla[i][kralj_y]->get_bela() == beli_na_potezu)
            break;

        if (prva->tabla[i][kralj_y] && prva->tabla[i][kralj_y]->get_bela() != beli_na_potezu)
        {
            simbol = prva->tabla[i][kralj_y]->get_simbol();

            if (simbol == B_TOP || simbol == C_TOP || simbol == B_KRALJICA || simbol == C_KRALJICA)
                return true;
        }
    }


    for (int i = kralj_x-1; i >= 0; i--)
    {
        if (prva->tabla[i][kralj_y] && prva->tabla[i][kralj_y]->get_bela() == beli_na_potezu)
            break;

        if (prva->tabla[i][kralj_y] && prva->tabla[i][kralj_y]->get_bela() != beli_na_potezu)
        {
            simbol = prva->tabla[i][kralj_y]->get_simbol();

            if (simbol == B_TOP || simbol == C_TOP || simbol == B_KRALJICA || simbol == C_KRALJICA)
                return true;
        }
    }


    for (int i = kralj_y + 1; i < 8; i++)
    {
        if (prva->tabla[kralj_x][i] && prva->tabla[kralj_x][i]->get_bela() == beli_na_potezu)
            break;

        if (prva->tabla[kralj_x][i] && prva->tabla[kralj_x][i]->get_bela() != beli_na_potezu)
        {
            simbol = prva->tabla[kralj_x][i]->get_simbol();

            if (simbol == B_TOP || simbol == C_TOP || simbol == B_KRALJICA || simbol == C_KRALJICA)
                return true;
        }
    }

    for (int i = kralj_y-1; i >= 0; i--)
    {
        if (prva->tabla[kralj_x][i] && prva->tabla[kralj_x][i]->get_bela() == beli_na_potezu)
            break;

        if (prva->tabla[kralj_x][i] && prva->tabla[kralj_x][i]->get_bela() != beli_na_potezu)
        {
            simbol = prva->tabla[kralj_x][i]->get_simbol();

            if (simbol == B_TOP || simbol == C_TOP || simbol == B_KRALJICA || simbol == C_KRALJICA)
                return true;
        }
    }


    // Ide ukoso u svim pravcima i trazi da li ima lovac ili kraljica suprotne boje
    for (int i = kralj_x+1, j = kralj_y+1; i < 8 && j < 8; i++, j++)
    {
        if (prva->tabla[i][j] && prva->tabla[i][j]->get_bela() == beli_na_potezu)
            break;

        if (prva->tabla[i][j] && prva->tabla[i][j]->get_bela() != beli_na_potezu)
        {
            simbol = prva->tabla[i][j]->get_simbol();

            if (simbol == B_LOVAC || simbol == C_LOVAC || simbol == B_KRALJICA || simbol == C_KRALJICA)
                return true;
        }
    }

    for (int i = kralj_x-1, j = kralj_y-1; i >= 0 && j >= 0; i--, j--)
    {
        if (prva->tabla[i][j] && prva->tabla[i][j]->get_bela() == beli_na_potezu)
            break;

        if (prva->tabla[i][j] && prva->tabla[i][j]->get_bela() != beli_na_potezu)
        {
            simbol = prva->tabla[i][j]->get_simbol();

            if (simbol == B_LOVAC || simbol == C_LOVAC || simbol == B_KRALJICA || simbol == C_KRALJICA)
                return true;
        }
    }

    for (int i = kralj_x, j = kralj_y; i < 8 && j >= 0; i++, j--)
    {
        if (prva->tabla[i][j] && prva->tabla[i][j]->get_bela() == beli_na_potezu)
            break;

        if (prva->tabla[i][j] && prva->tabla[i][j]->get_bela() != beli_na_potezu)
        {
            simbol = prva->tabla[i][j]->get_simbol();

            if (simbol == B_LOVAC || simbol == C_LOVAC || simbol == B_KRALJICA || simbol == C_KRALJICA)
                return true;
        }
    }

    for (int i = kralj_x, j = kralj_y; i >= 0 && j < 8; i--, j++)
    {
        if (prva->tabla[i][j] && prva->tabla[i][j]->get_bela() != beli_na_potezu)
            break;

        if (prva->tabla[i][j] && prva->tabla[i][j]->get_bela() != beli_na_potezu)
        {
            simbol = prva->tabla[i][j]->get_simbol();

            if (simbol == B_LOVAC || simbol == C_LOVAC || simbol == B_KRALJICA || simbol == C_KRALJICA)
                return true;
        }
    }

    // Da li kralja kaci konj suprotne boje
    if (kralj_x + 2 < 8 && kralj_y + 1 < 8
    && prva->tabla[kralj_x + 2][kralj_y + 1]
    && beli_na_potezu != prva->tabla[kralj_x + 2][kralj_y + 1]->get_bela()
    && (prva->tabla[kralj_x + 2][kralj_y + 1]->get_simbol() == C_KONJ
        || prva->tabla[kralj_x + 2][kralj_y + 1]->get_simbol() == B_KONJ))
        return true;

    if (kralj_x + 1 < 8 && kralj_y + 2 < 8
    && prva->tabla[kralj_x + 1][kralj_y + 2]
    && beli_na_potezu != prva->tabla[kralj_x + 1][kralj_y + 2]->get_bela()
    && (prva->tabla[kralj_x + 1][kralj_y + 2]->get_simbol() == C_KONJ
        || prva->tabla[kralj_x + 1][kralj_y + 2]->get_simbol() == B_KONJ))
        return true;

    if (kralj_x - 2 >= 0 && kralj_y - 1 >= 0
    && prva->tabla[kralj_x - 2][kralj_y - 1]
    && beli_na_potezu != prva->tabla[kralj_x - 2][kralj_y - 1]->get_bela()
    && (prva->tabla[kralj_x - 2][kralj_y - 1]->get_simbol() == C_KONJ
        || prva->tabla[kralj_x - 2][kralj_y - 1]->get_simbol() == B_KONJ))
        return true;

    if (kralj_x - 1 >= 0 && kralj_y - 2 >= 0
    && prva->tabla[kralj_x - 1][kralj_y - 2]
    && beli_na_potezu != prva->tabla[kralj_x - 1][kralj_y - 2]->get_bela()
    && (prva->tabla[kralj_x - 1][kralj_y - 2]->get_simbol() == C_KONJ
        || prva->tabla[kralj_x - 1][kralj_y - 2]->get_simbol() == B_KONJ))
        return true;

    if (kralj_x + 2 < 8 && kralj_y - 1 >= 0
    && prva->tabla[kralj_x + 2][kralj_y - 1]
    && beli_na_potezu != prva->tabla[kralj_x + 2][kralj_y - 1]->get_bela()
    && (prva->tabla[kralj_x + 2][kralj_y - 1]->get_simbol() == C_KONJ
        || prva->tabla[kralj_x + 2][kralj_y - 1]->get_simbol() == B_KONJ))
        return true;

    if (kralj_x + 1 < 8 && kralj_y - 2 >= 0
    && prva->tabla[kralj_x + 1][kralj_y - 2]
    && beli_na_potezu != prva->tabla[kralj_x + 1][kralj_y - 2]->get_bela()
    && (prva->tabla[kralj_x + 1][kralj_y - 2]->get_simbol() == C_KONJ
        || prva->tabla[kralj_x + 1][kralj_y - 2]->get_simbol() == B_KONJ))
        return true;

    if (kralj_x - 2 >= 0 && kralj_y + 1 < 8
    && prva->tabla[kralj_x - 2][kralj_y + 1]
    && beli_na_potezu != prva->tabla[kralj_x - 2][kralj_y + 1]->get_bela()
    && (prva->tabla[kralj_x - 2][kralj_y + 1]->get_simbol() == C_KONJ
        || prva->tabla[kralj_x - 2][kralj_y + 1]->get_simbol() == B_KONJ))
        return true;

    if (kralj_x - 1 >= 0 && kralj_y + 2 < 8
    && prva->tabla[kralj_x - 1][kralj_y + 2]
    && beli_na_potezu != prva->tabla[kralj_x - 1][kralj_y + 2]->get_bela()
    && (prva->tabla[kralj_x - 1][kralj_y + 2]->get_simbol() == C_KONJ
        || prva->tabla[kralj_x - 1][kralj_y + 2]->get_simbol() == B_KONJ))
        return true;


    // Da li postoji pijun koji moze pojesti kralja
    if (beli_na_potezu)
    {
        if (kralj_x - 1 >= 0 && kralj_y - 1 >= 0
        && prva->tabla[kralj_x - 1][kralj_y - 1]
        && prva->tabla[kralj_x - 1][kralj_y - 1]->get_simbol() == C_PIJUN)
         return true;

        if (kralj_x - 1 >= 0 && kralj_y + 1 < 8
        && prva->tabla[kralj_x - 1][kralj_y + 1]
        && prva->tabla[kralj_x - 1][kralj_y + 1]->get_simbol() == C_PIJUN)
         return true;
    }
    else
    {
        if (kralj_x + 1 < 8 && kralj_y - 1 >= 0
        && prva->tabla[kralj_x + 1][kralj_y - 1]
        && prva->tabla[kralj_x + 1][kralj_y - 1]->get_simbol() == B_PIJUN)
         return true;

        if (kralj_x + 1 < 8 && kralj_y + 1 < 8
        && prva->tabla[kralj_x + 1][kralj_y + 1]
        && prva->tabla[kralj_x + 1][kralj_y + 1]->get_simbol() == B_PIJUN)
         return true;
    }

    return false;
}
