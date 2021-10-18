/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <set>
#include <iterator>

struct Dijete {
  std::string ime;
  Dijete* sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int br_timova)
{
    std::vector<std::set<std::string>> vektor_timova;
    int brojac(vektor_timova.size());
    Dijete *pocetak(nullptr), *prethodni;
    for(int i=0; i<imena.size(); i++)
    {
        Dijete *novi(new Dijete);
        novi->ime=imena[i];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i+1==imena.size()) prethodni->sljedeci=pocetak;
    }
    auto it(pocetak);
    for(int i=0; i<br_timova; i++) {
        std::set<std::string> skup;
        int br_slova(0), br_clanova(0);
        int br_djece(imena.size());
        int clanovi(br_djece/br_timova), koliko_prvih(br_djece%br_timova);
        
        if(i<koliko_prvih) {
            while(br_clanova<br_clanova+1) {
                skup.insert(it->ime);
                br_slova=0;
                auto pamti(it); 
                it=it->sljedeci;
                prethodni->sljedeci=it;
                delete pamti;
                brojac--;
                br_clanova++;
                for(int j=0; j<it->ime.length(); j++) if(it->ime[j]!=' ' && it->ime[j]!='-') br_slova++;
                for(int broj=1; broj<=br_slova; broj++) {
                    prethodni=prethodni->sljedeci;
                    it=it->sljedeci;
                }
            }
        }
        else {
            while(br_clanova<clanovi) {
                skup.insert(it->ime);
                br_slova=0; 
                auto pamti(it);
                it=it->sljedeci;
                prethodni->sljedeci=it;
                delete pamti;
                brojac--;
                br_clanova++;
                for(int j=0; j<it->ime.length(); j++) if(it->ime[j]!=' ' && it->ime[j]!=' ') br_slova++;
                for(int broj=1; broj<=br_slova; broj++) {
                    prethodni=prethodni->sljedeci;
                    it=it->sljedeci;
                }
                
            }
        }
        vektor_timova.push_back(skup);
    }
    return vektor_timova;
}

int main ()
{
    try{
        int broj_djece;
        std::cout << "Unesite broj djece: ";
        std::cin >> broj_djece;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Unesite imena djece: " << std::endl;
        std::vector<std::string> imena_djece;
        for(int i=0; i<broj_djece; i++) {
            std::string rijec;
            std::getline(std::cin, rijec);
            imena_djece.push_back(rijec);
        }
        int broj_timova;
        std::cout << "Unesite broj timova: ";
        std::cin >> broj_timova;
        if(broj_timova<1 || broj_timova>broj_djece) throw std::logic_error("Razvrstavanje nemoguce");
        auto razvrstano(Razvrstavanje(imena_djece, broj_timova));
        for(int i=0; i<razvrstano.size(); i++) {
            std::set<std::string>skup(razvrstano[i]);
            std::cout << "Tim "<< i+1 << ": ";
            for(auto it1=skup.begin(); it1!=skup.end(); it1++) {
                auto it2(it1);
                it2--;
                std::cout <<*it1;
                if(it2!=it1) std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error tekst)
    {
        std::cout << tekst.what() << std::endl;
    }
	return 0;
}