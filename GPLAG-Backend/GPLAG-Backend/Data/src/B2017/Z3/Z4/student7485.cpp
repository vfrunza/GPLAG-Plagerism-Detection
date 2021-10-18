/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector> 
#include <stdexcept>
#include <map>

using std::cout;
using std::cin;
using std::list;
using std::pair;
using std::vector;
using std::multimap;

enum class Boje {Pik, Tref, Herc, Karo};

typedef list<pair<Boje, string>> Spil;

Spil KreirajSpil()
{
    vector<string> v{"dva","tri","cetiri","pet","sest","sedam","osam","devet","deset","dzandar","dama","kralj","as"};
    Spil vracaj;
    for(int i=0; i<4; i++)
    {
        Boje boja;
        if (i==0)
            boja=Pik;
        if (i==1)
            boja=Tref;
        if (i==2)
            boja=Herc;
        if (i==3)
            boja=Karo;
        for(int j=0; j<13; j++)
        {
            pair<Boje, string> par;
            par=std::make_pair(boja, v[j]);
            vracaj.push_back(par);
        }    
    }
    
    return vracaj;
}

void IzbaciKarte(Spil &spil, multimap<Boje, string> &mapa)
{
    int brojac(0);
    for(auto it=spil.begin(); it!=spil.end(); it++)
        brojac++;
    if (brojac!=52)
        throw std::logic_error("Neispravna lista!");
    
    multimap<Boje, string> kopija;
    
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
        kopija.insert({mapa->first, mapa->second});
    
        
        
}


int main ()
{
	return 0;
}
