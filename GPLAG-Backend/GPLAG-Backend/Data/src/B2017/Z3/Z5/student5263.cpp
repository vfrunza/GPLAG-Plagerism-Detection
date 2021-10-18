/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
enum class Boje{Pik, Tref, Herc, Karo};
struct Karta{
    Boje boja;
    std::string vrijednost;
};
struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};
Cvor *KreirajSpil(){
    Cvor *pocetak(nullptr), *prethodni;
    std::vector<std::string> v={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    Karta spil;
    for(int i=0; i<v.size(); i++)    spil.boja=Boje::Pik; spil.vrijednost=v.at(i);
    for(int i=0; i<v.size(); i++)    spil.boja=Boje::Tref; spil.vrijednost=v.at(i);
    for(int i=0; i<v.size(); i++)    spil.boja=Boje::Herc; spil.vrijednost=v.at(i);
    for(int i=0; i<v.size(); i++)    spil.bojaBoje::Karo; spil.vrijednost=v.at(i);
    Cvor *novi(new Cvor);
    novi->karta=spil;
    novi->sljedeci=nullptr;
    
}
int main ()
{
	return 0;
}
