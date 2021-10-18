/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <set>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Imena, int broj_timova){
    if(broj_timova<1 || broj_timova>Imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(int i{0}; i<Imena.size(); i++) lista.push_back(Imena[i]);
    std::vector<std::set<std::string>> vrati(broj_timova);
    int enplusjedan, br_dj_po_timu;
    br_dj_po_timu = Imena.size() / broj_timova;
    enplusjedan = br_dj_po_timu * broj_timova;
    enplusjedan = Imena.size() - enplusjedan;
    std::list<std::string>::iterator it;
    it=lista.begin();
    int preskoci{0}, j{1};
    for(int i{0}; i<broj_timova; i++){
        if(i==0) j=0;
        if(i < enplusjedan){
            int brojac{0};
            for(;;){
                if(it == lista.end()){
                    it=lista.begin();
                }
                if(j == preskoci){
                   vrati[i].insert(*it);
                   int duzina{0};
                   for(int h{0}; h<(*it).size(); h++) if(((*it)[h]>='0' && (*it)[h]<='9') || ((*it)[h]>='A' && (*it)[h]<='Z')  || ((*it)[h]>='a' && (*it)[h]<='z')) duzina++;
                   preskoci = duzina;
                   it = lista.erase(it);
                   brojac++;
                   j=0;
                }
                else it++;
                j++;
                if(brojac == br_dj_po_timu+1) break;
            }
        }
        else{
            int brojac{0};
            for(;;){
                if(it == lista.end()){
                    it=lista.begin();
                }
                if(j == preskoci){
                    vrati[i].insert(*it);
                    int duzina{0};
                    for(int h{0}; h<(*it).size(); h++) if((*it)[h] != ' ') duzina++;
                    preskoci = duzina;
                    it = lista.erase(it);
                    brojac++;
                    j=0;
                }
                else it++;
                j++;
                if(brojac == br_dj_po_timu) break;
            }
        }
    }
    return vrati;
}

int main (){
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite imena djece: ";
    std::vector<std::string> Imena(n);
    for(int i{0}; i<n; i++){
        std::getline(std::cin, Imena[i]);
    }
    std::cout << "\nUnesite broj timova: ";
    int timovi;
    std::cin >> timovi;
    try{
        auto pisi(Razvrstavanje(Imena, timovi));
        for(int i{0}; i<timovi; i++){
            std::cout << "Tim " << i+1 << ": ";
            std::set<std::string>::iterator it{pisi[i].begin()};
            while(it != pisi[i].end()){
                std::cout << *it;
                it++;
                if(it != pisi[i].end()) std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}