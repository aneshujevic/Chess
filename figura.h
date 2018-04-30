#ifndef FIG_H
#define FIG_H

#include<string>

class
Figura
{
  protected:
    bool bela;
    int pozicija_x;
    int pozicija_y;
    std::string simbol;

  public:
    Figura();
    Figura(bool,int,int);
    void set_x(int);
    void set_y(int);
    void set_pozicija(int,int);
    void set_simbol(std::string);
    int get_x();
    int get_y();
    std::string get_simbol();

    //TODO: GET POZICIJA ,VIRTUAL POMERAJ
};


#endif
