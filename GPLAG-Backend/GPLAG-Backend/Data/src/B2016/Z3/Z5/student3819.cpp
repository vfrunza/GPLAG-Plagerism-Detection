/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <new>
struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int brojtimova) {
    std::vector<std::set<std::string>> timovi;
    std::set<std::string> skup;
    if(brojtimova<1 || brojtimova>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int mod(imena.size()%brojtimova);
    int cijeli(imena.size()/brojtimova);
    Dijete *pocetak(nullptr), *prethodni;
    for(int i(0); i<imena.size(); i++) {
        Dijete *novi=(new Dijete);
        novi->ime=imena[i];
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==imena.size()-1) {
            prethodni->sljedeci=pocetak;
        }
    }
    Dijete *p=pocetak;
    for(int i(0); i<mod; i++) {
        timovi.push_back(skup);
        for(int j(0); j<cijeli+1; j++) {
            std::string imeduzina(p->ime);
            int duzina(0);
            for(int i(0); i<imeduzina.length(); i++) 
                if((imeduzina[i]>='A' && imeduzina[i]<='Z') || (imeduzina[i]>='a' && imeduzina[i]<='z') || (imeduzina[i]>='0' && imeduzina[i]<='9')) duzina++;
            timovi[i].insert(p->ime);
            if(p==pocetak) {
                p=pocetak->sljedeci;
                prethodni->sljedeci=p;
                delete pocetak;
            }
            else {
                Dijete *hard=p->sljedeci;
                delete p;
                p=hard->sljedeci;
                delete hard;
            }
            for(int i(0); i<duzina; i++) {
                p=p->sljedeci;
            }
        }
           
    }
    int brojac(0);
    for(Dijete *p=pocetak; p!=nullptr; p=p->sljedeci) {
        brojac++;
        std::cout << p->ime <<std::endl;
        if(brojac==10)break;
    }
    
    return timovi;
}
int main (){
    int brojdjece, brojtimova;
    std::string ime;
    std::vector<std::string> imena;
    std::cout << "Unesite broj djece: ";
    std::cin >> brojdjece;
    std::cout << "Unesite imena djece: " << std::endl;
    std::cin.ignore(10000,'\n');
    for(int i(0); i<brojdjece; i++) {
        std::getline(std::cin, ime);
        imena.push_back(ime);
        ime.clear();
    }
    std::cout << "Unesite broj timova: ";
    std::cin >> brojtimova;
    try {
        auto timovi=Razvrstavanje(imena, brojtimova);
        for(int i(0); i<timovi.size(); i++) {
            int brojac(0);
            std::cout << "Tim " << i+1 << ": ";
            for(auto x: timovi[i]) {
                brojac++;
                if(brojac==timovi[i].size())
                    std::cout << x;
                else 
                     std::cout << x << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error izuzetak) {
        std::cout << izuzetak.what();
    }
	return 0;
}