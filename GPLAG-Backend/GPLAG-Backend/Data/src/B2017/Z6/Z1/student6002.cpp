/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>

class Spremnik
{
    double Tezina;
std: string NazivPredmeta;
};


class Sanduk : Spremnik
{
    std::vector<double> TezinaPredmeta;
public:
Sanduk (double T, std:string naziv) {}


};
class Vreca : Spremnik
{
    double TezinaPraskasteMaterije;
public:
    Vreca () {}
};
class Bure : Spremnik
{
    double Gustina, Zapremina;
public:
    Bure () {}
};

int main ()
{
    return 0;
}
