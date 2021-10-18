/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <cstring>
#include <utility>
int Duzina (std::string s) {
    int broj_rijeci=0;
    for (int i=0; i<s.size(); i++) {
        while (i<s.size() && (((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')) || (s[i]>='0'&&s[i]<='9'))) {
            broj_rijeci++;
            i++;
        }
    }
    return broj_rijeci;
}
std::vector<std::set<std::string>>Razvrstavanje (std::vector<std::string>vs, int broj_timova) {
    std::list<std::string> lista;
    for (int i=0; i<vs.size(); i++) {
        lista.push_back(vs[i]);
    }
    auto it=lista.begin();
    int broj_djece=vs.size();
    std::vector<std::set<std::string>>vss;
    int modul=broj_djece%broj_timova;
    int razlika=broj_djece/broj_timova;
    for (int i=0; i<broj_timova; i++) {
        int n;
        std::set<std::string> skup;
        if (modul>=1) {
            n=razlika+1;
            modul--;
        }
        else  n=razlika;
        int broj_slova;
                while (n>0){
                        skup.insert(*it);
                        broj_slova=Duzina(*it);
                        it=lista.erase(it);
                        n--;
                    if (lista.size()==0) break;
                    while(broj_slova>1){
                        if (it==lista.end()) {
                            it=lista.begin();
                            if(lista.size()==1) break;
                        }
                        it++;
                        if(it==lista.end()) it=lista.begin();
                        broj_slova--;
                    }
                }
            vss.push_back(skup);
    }
    return vss;
}

int main () {
    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::vector<std::string>vs;
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::string ime;
    std::getline(std::cin,ime);
    for (int i=0; i<broj_djece; i++){
        std::getline(std::cin,ime);
        vs.push_back(ime);
    }
    int broj_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;
    try {
       if (broj_timova<1 || broj_timova>broj_djece) throw std::logic_error ("Razvrstavanje nemoguce"); 
    }
    catch (std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
        return 0;
    }
    std::vector<std::set<std::string>>vss;
    vss=Razvrstavanje(vs,broj_timova);
    int m=1;
    for (int i(0);i<vss.size();i++) {
        auto it2=vss[i].end();
        it2--;
        std::cout<< "Tim "<<i+1<<": ";
            for (auto it=vss[i].begin();it!=vss[i].end();it++) {
            if(it==it2) std::cout<< *it;
                
            else std::cout<<*it<<", ";
            }
            std::cout<<std::endl;
        m++;
    }
	return 0;
}