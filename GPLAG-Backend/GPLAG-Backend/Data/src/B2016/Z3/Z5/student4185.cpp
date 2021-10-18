/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <set>
#include <list>
#include <string>
#include <vector>
#include <stdexcept>

struct Dijete
{
    std::string ime;
    Dijete * sljedeci;
};

std::vector<int> BrojClanova(int a, int timovi)
{
    int prvi = a % timovi;
    std::vector<int> vrati ;
    if (prvi == 0) {vrati.resize(timovi,a/timovi);   }
    for(int i = 0; i < timovi; i++){
        if(i < prvi){
            vrati.push_back((a / timovi) + 1);
        }
        else vrati.push_back(a/timovi);
    }
    return vrati;
}

int KolikoZnakova(std::string prebroj)
{
    int brojac = 0;
    for(int i = 0; i < prebroj.size(); i++){
        if ((prebroj[i] <= 'Z' && prebroj[i] >= 'A') || (prebroj[i] <= 'z' && prebroj[i] >= 'a') || (prebroj[i] <= '9' && prebroj[i] >= '0')) brojac++;
    }
    return brojac;
}

Dijete * KreirajListu(std::vector<std::string> prebaci){
    Dijete * pocetak(nullptr), * prethodni;
    for(int i = 0; i < prebaci.size(); i++){
        Dijete * uvezi = new Dijete;
        uvezi->ime = prebaci[i];
        uvezi->sljedeci = nullptr;
        if (!pocetak) pocetak = uvezi;
        else prethodni->sljedeci = uvezi;
        prethodni = uvezi;
        if(prebaci[i] == prebaci[prebaci.size()-1]) prethodni->sljedeci = pocetak;
    }
    return pocetak;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> spisak, int timovi){
    if (timovi<1 || timovi>spisak.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<int> brojclanova ;
    brojclanova = BrojClanova(spisak.size(),timovi);
    auto it = KreirajListu(spisak);
    std::vector<std::set<std::string>> rezultat(timovi);
    auto iti = it;
    int pocetni = 0;
    for(int i = 0; i < timovi; i++){
        for(int j = 0; j < brojclanova[i]; j++){
            int brojac = 1;
            while(brojac < pocetni){
                if (it == nullptr) return rezultat;
                
                it = it->sljedeci;
                brojac++;
            }
            auto prethodni = it;
            auto spasi = it;
            for(prethodni = it->sljedeci; prethodni != it; prethodni = prethodni->sljedeci){
                if(prethodni->sljedeci == it)  spasi = prethodni;
            }
            prethodni = spasi;
            rezultat[i].insert(it->ime);
            pocetni = KolikoZnakova(it->ime);
            prethodni->sljedeci = it->sljedeci;
            delete it;
            if( it != prethodni)
            it = prethodni->sljedeci;
        }
    }    return rezultat;
}



int main ()
{   
    std::cout << "Unesite broj djece: ";
    int brojdjece;
    std::cin >> brojdjece;
    std::vector<std::string> djeca ;
    std::cin.ignore(1000,'\n');
    std::cout << "Unesite imena djece: \n";
    for(int i = 0; i < brojdjece; i++){
        std::string pomocni;
        std::getline(std::cin, pomocni);
        djeca.push_back(pomocni);
    }
    std::cout << "Unesite broj timova: ";
    int brojtimova;
    std::cin >> brojtimova;
    try{
        std::vector<std::set<std::string>> rezultat = Razvrstavanje(djeca,brojtimova);
        std::vector<int> brojclanova = BrojClanova(brojdjece,brojtimova);
        
        for(int i = 0; i < rezultat.size(); i++){
            std::cout << "Tim " << i + 1 <<": ";
            for(auto it = rezultat[i].begin(); it != rezultat[i].end(); it++){
                if(it != (--(rezultat[i].end()))) std::cout << *it <<", ";
                else std::cout << *it;
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error greska){
        std::cout <<"Izuzetak: "<< greska.what() << std::endl;
        return 0;
    }
	return 0;
}