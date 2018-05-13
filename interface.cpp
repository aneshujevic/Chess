#include "interface.h"

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

//konvertuje stringove u format velikog pocetnog slova i ostatka malih slova i proverava da li su dati jednaki
bool same_strings(string & s1,string & s2)
{
    if(s1[0] >= 'a' && s1[0] <= 'z')
            s1[0]= 'A' + s1[0] - 'a';
    if(s2[0] >= 'a' && s2[0] <= 'z')
            s2[0]= 'A' + s2[0] - 'a';

    if(s1.size() == s2.size())
        for(int i = 1; i < s1.size(); i++)
        {
            if(s1[i] >= 'A' && s1[i] <= 'Z')
                s1[i] = 'a' + s1[i] - 'A';
            if(s2[i] >= 'A' && s2[i] <= 'Z')
                s2[i] = 'a' + s2[i] - 'A';
        }
    else
    {
        for(int i = 1;i < s1.size(); i++)
            if(s1[i] >= 'A' && s1[i] <= 'Z')
                s1[i] = 'a' + s1[i] - 'A';

        for(int i = 1; i < s2.size(); i++)
            if(s2[i] >= 'A' && s2[i] <= 'Z')
                s2[i] = 'a' + s2[i] - 'A';
    }

    if(!s1.compare(s2))
        return true;

    return false;
}

void sah_msg()
{
    cout << "       __  __                                                    " << endl;
    cout << "       \\ \\/ /                                                    " << endl;
    cout << "        \\__/                                                     " << endl;
    cout << "      ________         ____________         _____       _____    " << endl;
    cout << "     |        |       |            |       |     |     |     |   " << endl;
    cout << "     |   _____|       |    ____    |       |     |     |     |   " << endl;
    cout << "      \\  \\            |   |____|   |       |     |_____|     |   " << endl;
    cout << "       \\  \\           |            |       |                 |   " << endl;
    cout << "        \\  \\          |    ____    |       |                 |   " << endl;
    cout << "         \\  \\         |   |    |   |       |      _____      |   " << endl;
    cout << "      ____\\  \\        |   |    |   |       |     |     |     |   " << endl;
    cout << "     |        |       |   |    |   |       |     |     |     |   " << endl;
    cout << "     |________|       |___|    |___|       |_____|     |_____|   " << endl;
    cout << "                                                                 " << endl;
}