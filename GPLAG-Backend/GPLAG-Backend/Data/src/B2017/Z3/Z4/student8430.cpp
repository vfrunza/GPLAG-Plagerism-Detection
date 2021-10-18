/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <map>
#include <stdexcept>

enum class Boje {Pik=1, Tref=2, Herc=3, Karo=4};
typedef std::list<std::pair<Boje, std::string>> Spil;

Spil KreirajSpil(){
    Spil lista;
    for(int i=1; i<=4; i++){
        lista.push_back(std::make_pair(Boje(i), "2"));
        lista.push_back(std::make_pair(Boje(i), "3"));
        lista.push_back(std::make_pair(Boje(i), "4"));
        lista.push_back(std::make_pair(Boje(i), "5"));
        lista.push_back(std::make_pair(Boje(i), "6"));
        lista.push_back(std::make_pair(Boje(i), "7"));
        lista.push_back(std::make_pair(Boje(i), "8"));
        lista.push_back(std::make_pair(Boje(i), "9"));
        lista.push_back(std::make_pair(Boje(i), "10"));
        lista.push_back(std::make_pair(Boje(i), "J"));
        lista.push_back(std::make_pair(Boje(i), "D"));
        lista.push_back(std::make_pair(Boje(i), "K"));
        lista.push_back(std::make_pair(Boje(i), "A"));
    }
    return lista;
}


int main ()
{
    try{
    std::cout<<"Unesite korak razbrajanja: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int m;
    std::cin>>m;
    if(n<1 || n>52 || m<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    }catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
        return 0;
    }
    KreirajSpil();
	return 0;
}
