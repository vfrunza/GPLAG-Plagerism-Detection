/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <stdexcept>
#include <map>
#include <queue>

enum class Boje
{
    Pik,Tref,Herc,Karo
};
struct Karta {
    Boje boja;
    std::string vrijednost;
};
struct Cvor{
    Karta karta;
    Cvor* sljedeci;
}
Cvor* KreirajSpil(){
    
}
int main(){
    return;
}