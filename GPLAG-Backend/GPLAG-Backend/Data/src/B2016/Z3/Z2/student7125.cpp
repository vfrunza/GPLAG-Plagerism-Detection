/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <utility>
#include <set>
#include <string>
#include <stdexcept>


std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string ulaz);
std::set<int> PretraziIndeksPojmova(std::string ulaz, std::map<std::string,std::set<int>> mapa);
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa);
void mytolower(std::string &ulaz);
bool jestotreba(char &p);
std::set<int> pozicije(std::string &ulaz, std::string sub);

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string ulaz;
    std::getline(std::cin,ulaz);
    auto mapa(KreirajIndeksPojmova(ulaz));
    IspisiIndeksPojmova(mapa);
    while(true){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,ulaz);
        if(ulaz == ".")
            break;
        try{
        auto skup(PretraziIndeksPojmova(ulaz,mapa));
        for(auto it(skup.begin()); it != skup.end(); it++){
            std::cout<< *it <<" ";
        }
        std::cout<<std::endl;
        }catch(std::logic_error){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    
	return 0;
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string ulaz){
    //inicijalizuj mapu
    std::map<std::string,std::set<int>> mapa;
    //sva slova ulaza postavi na mala
    mytolower(ulaz);
    //izračunaj odmah duđinu da se žaba funkcija length ne poziva više puta
    int p(0),duz(ulaz.length());
    while(p < duz){
        //preskoči sve što ne treba
        while(p < duz  && !jestotreba(ulaz[p])) p++;
        
        int q(p);
        //kada si došao na riječ nađi koliko ima elemenata
        while(q < duz  && jestotreba(ulaz[q])) q++;
        //za tu riječ pretraži u stringu eventalna ponavljanja i ubaci ih u mapu
        mapa[ulaz.substr(p,q-p)] = pozicije(ulaz,ulaz.substr(p,q-p));
        //preskoči tu riječ
        while(p < duz  && jestotreba(ulaz[p])) p++;
    }
    
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string ulaz, std::map<std::string,std::set<int>> mapa){
    mytolower(ulaz);
    int i(0);
    //pretražuj riječ
    auto it(mapa.find(ulaz));
    //ako nije pronađena riječ iterator će pokazivati iza kraja
    if(it == mapa.end() || ulaz.length() == 0)
        throw std::logic_error("Pojam nije nadjen");
    //ako je pronađen vrati indeks pojmova
    return mapa[ulaz];
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    for(auto it(mapa.begin()); it != mapa.end(); it++){
        std::cout<< it->first<<": ";
       for(auto it2(it->second.begin()); it2 != it->second.end(); it2++){
           auto it3(it2);
           it3++;
           //ispisuj zarez samo ako it2 nije zadnji član skupa
           if(it3 != it->second.end())
            std::cout<<*it2<<",";
            else std::cout<<*it2;
       }
        std::cout<<std::endl;
    }
}
//pomoćna funkcija za prebacivanje sve u mala slova(nisam bio siguran da li možemo koristiti bibliotečno mytolower pa sam svoju napisao)
void mytolower(std::string &ulaz){
    for(int i(0); i < ulaz.length(); i++)
        if(ulaz[i] >= 'A' && ulaz[i] <= 'Z')
            ulaz[i] -= 'A' -'a';
}
//funkcija za testiranje karaktera nekog
bool jestotreba(char &p){
    if ((p >= 'a' && p <= 'z') ||(p>= '0' && p <= '9'))
        return true;
    return false;
}
std::set<int> pozicije(std::string &ulaz, std::string sub){
    int p(0),duz(ulaz.length());
    //inicijalizuj skup, te pomocne varijable
    std::set<int> poz;
    while(p < duz){
        //preskači sve što ne treba
        while(p < duz  && !jestotreba(ulaz[p])) p++;
        int q(p);
        //nađi dužinu riječi
        while(q < duz  && jestotreba(ulaz[q])) q++;
        //testiraj da li je proslijeđena riječ ona koja nam treba
        if(sub == ulaz.substr(p,q-p))
            poz.insert(p);
        //ako jeste ona koja treba onda ubaci njenu poziciju u skup
        //preskoči ostatak riječi
        while(p < duz  && jestotreba(ulaz[p])) p++;
    }
    //vrati skup
    return poz;
}