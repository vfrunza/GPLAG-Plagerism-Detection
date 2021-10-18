/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string> 
#include <set>
#include <list>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int br_timova) {
    if (br_timova<1 || br_timova>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for (int i = 0; i < imena.size(); i++) 
        lista.push_back(imena[i]);
    int broj_prvih_timova(imena.size()%br_timova);
    bool prvi_timovi(true);
    int broj_clanova (int(imena.size()/br_timova));
    int brojac(0);
    int brojac1(0);
    int brojac_prvih_timova(0);
    bool djeljiv(!broj_prvih_timova);
    std::vector<std::set<std::string>> vektor(br_timova); 
    auto it(lista.begin());
    for (;;) {
        
        if(djeljiv && ((!prvi_timovi && brojac == broj_clanova-1) || (prvi_timovi && brojac == broj_clanova))) {
            brojac1++;
            broj_prvih_timova++;
            brojac=0;
        }

       vektor[brojac1].insert(*it);

        auto rijec((*it));
        int br(0);
        for (int i=0; i<rijec.length(); i++) {
            if ((rijec[i]>='a' && rijec[i]<='z') || (rijec[i]>='A' && rijec[i]<='Z') || (rijec[i]>='0' && rijec[i]<='9') ) br++;
        } 
        it = lista.erase(it);
        if (it==lista.end()) it=lista.begin();
        if (!lista.size()) break;

        if(!djeljiv && brojac_prvih_timova == broj_prvih_timova) prvi_timovi=false;
        if(!djeljiv && ((!prvi_timovi && brojac == broj_clanova-1) || (prvi_timovi && brojac == broj_clanova))) {
            brojac1++;
            brojac_prvih_timova++;
            brojac=0;
            brojac--;
        }
        brojac++;
        while (br!=1) {
         /*   if (lista.size()==1 && !djeljiv) {
                vektor[brojac1].insert(*it);
                return vektor;
            }*/
            it++;
            if(it == lista.end()) it=lista.begin();
            br--;
        }

    }
    return vektor;
}
int main ()
{   try {
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite imena djece: "<<std::endl;
    std::vector<std::string> imena(n);
    std::cin.ignore (10000,'\n');
    for (int i=0; i< n; i++) std::getline(std::cin, imena[i]);
    std::cout << "Unesite broj timova: "; 
    int m;
    std::cin >> m;

        std::vector<std::set<std::string>> kontejner {Razvrstavanje(imena, m)};
    
    
    for (int i=0; i<kontejner.size(); i++) {
        std::cout << "Tim " << i+1 << ": ";
        auto it(kontejner[i].begin());
        for (int j=0; j<kontejner[i].size()-1; j++) {
            std::cout << *it << ", ";
            it++;
        }
        std::cout << *it << std::endl;  
    }
    }
    catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
} 