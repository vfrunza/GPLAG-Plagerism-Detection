/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int BrojSlova(std::string s){
    int brojac(0);
    for(int i = 0; i < s.size(); i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) brojac++;
    }
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int broj_timova){
    
    if(broj_timova<1 || broj_timova>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista;
    for(int i = 0; i < v.size(); i++)
        lista.push_back(v[i]);
    
    auto t = lista.begin();
    auto kraj = --lista.end();
    std::vector<std::set<std::string>> vektor;
    if(v.size()%broj_timova==0){
        
        int broj_slova (0);
        for(int i = 0; i < broj_timova; i++){
            std::set<std::string> pomocni_skup;
            int broj_smjestenih = 0;
            int maksimalno_smjestenih = v.size()/broj_timova;
            while (broj_smjestenih<maksimalno_smjestenih){
                
                while(broj_slova!=0){
                    if(t==kraj) t = lista.begin();
                    else t++;
                    broj_slova--;
                }
                
                pomocni_skup.insert(*t);
                broj_smjestenih++;
                broj_slova=BrojSlova(*t)-1;
                if(t==kraj) {
                    kraj--;
                    t = lista.erase(t);
                    t = lista.begin();
                }
                else
                t = lista.erase(t);
            }
            vektor.push_back(pomocni_skup);
            
            
        }
        
    }
    else {
        int broj_slova(0);
        int ostatak(v.size()%broj_timova);
        for(int i = 0; i < broj_timova; i++){
            std::set<std::string> pomocni_set;
            int broj_smjestenih(0);
            int maksimalno_smjestenih;
            if(ostatak!=0){
                 maksimalno_smjestenih = (v.size()/broj_timova) +1;
                 ostatak--;
            }
            else {
                maksimalno_smjestenih = v.size()/broj_timova;
            }
            while (broj_smjestenih<maksimalno_smjestenih){
                
                while(broj_slova!=0){
                    if(t==kraj) t = lista.begin();
                    else t++;
                    broj_slova--;
                }
                
                pomocni_set.insert(*t);
                broj_smjestenih++;
                broj_slova=BrojSlova(*t)-1;
                if(t==kraj) {
                    kraj--;
                    t = lista.erase(t);
                    t = lista.begin();
                }
                else {
                    t = lista.erase(t);
                }
                
            }
            vektor.push_back(pomocni_set);
                
        }
        
    }
    return vektor;
}
int main ()
{
    try{
        int n,k;
        std::vector<std::string> v;
        std::cout << "Unesite broj djece: ";
        std::cin >> n;
        std::cout << "Unesite imena djece: " << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        for(int i = 0; i < n; i++){
            std::string pom;
            std::getline(std::cin, pom);
            v.push_back(pom);
        }
        std::cout << "Unesite broj timova: ";
        std::cin >> k;
        std::vector<std::set<std::string>> vektor = Razvrstavanje(v,k);
        for(int i = 0; i < vektor.size(); i++){
            std::cout << "Tim " << i+1 << ": ";
            int velicina_seta ( vektor[i].size() - 1), j(0);
            for(auto x : vektor[i]){
                if(j!=velicina_seta) std::cout << x << ", ";
                else std::cout << x;
                j++;
            }
            std::cout << std::endl;
        }
    }
    catch(std::logic_error e){
        std::cout << "Izuzetak: " <<e.what();
    }
    
	return 0;
}