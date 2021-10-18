/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>


struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

int BrojSlova(std::string s){
    int brojac(0);
    for(int i = 0; i < s.size(); i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) brojac++;
    }
    return brojac;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int broj_timova){
    
    
    if(broj_timova<1 || broj_timova>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *t = new Dijete();
    t->ime = v[0];
    t->sljedeci = nullptr;
    Dijete *pocetak = t;
    //Dijete *kraj = t;
    
    for(int i = 1; i < v.size(); i++){
        Dijete *dijete = new Dijete;
        dijete->ime = v[i];
        
        t->sljedeci = dijete;
        t = t->sljedeci;
        if(i==v.size()-1) {
            t->sljedeci = pocetak;
            //kraj = t;
        }
        
    }
    t = pocetak;
    std::vector<std::set<std::string>> vektor;
    int ukupno = v.size();
    if(v.size()%broj_timova==0){
        
        int broj_slova (0);
        for(int i = 0; i < broj_timova; i++){
            std::set<std::string> pomocni_skup;
            int broj_smjestenih = 0;
            int maksimalno_smjestenih = v.size()/broj_timova;
            while (broj_smjestenih<maksimalno_smjestenih){
                
                while(broj_slova!=0){
                
                    t=t->sljedeci;
                    broj_slova--;
                }
                
                pomocni_skup.insert(t->ime);
                broj_smjestenih++;
                broj_slova=BrojSlova(t->ime)-1;
                auto pom = pocetak; 
                while(pom->sljedeci!=t){
                    pom=pom->sljedeci;
                }
                pom->sljedeci = t->sljedeci;
                if(t==pocetak){
                    pocetak = pocetak->sljedeci;
                }
                t->sljedeci=nullptr;
                delete t;
                ukupno--;
                if(ukupno!=0) t=pom->sljedeci;
                
                
                
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
                    maksimalno_smjestenih = (v.size()/broj_timova)+1;
                    ostatak--;
                }
                else
                    maksimalno_smjestenih = v.size()/broj_timova;
                
                while(broj_smjestenih<maksimalno_smjestenih){
                    
                    while(broj_slova!=0){
                        t = t->sljedeci;
                        broj_slova--;
                    }
                    pomocni_set.insert(t->ime);
                    broj_smjestenih++;
                    broj_slova = BrojSlova(t->ime)-1;
                    auto pom = pocetak; 
                    while(pom->sljedeci!=t){
                        pom=pom->sljedeci;
                    }
                    if(t==pocetak)
                        pocetak = pocetak->sljedeci;
                    pom->sljedeci = t->sljedeci;
                    t->sljedeci = nullptr;
                    delete t;
                    ukupno--;
                    if(ukupno!=0) t=pom->sljedeci;
                        
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
        std::cout << "Izuzetak: " << e.what();
    }
	return 0;
}