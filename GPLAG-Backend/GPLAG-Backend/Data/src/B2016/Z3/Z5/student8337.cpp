/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector> 
#include <set>
#include <stdexcept>

struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

std::vector< std::set<std::string> > Razvrstavanje(std::vector<std::string> v, int br_timova){
    if(br_timova < 1 || br_timova > v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int ostatak(v.size() % br_timova);
    std::vector< std::set<std::string> > povratni(br_timova);
    
    Dijete *pocetak(nullptr), *prethodni;
    for(int i=0; i<v.size(); i++){
        Dijete *novi(new Dijete);
        novi->sljedeci = pocetak;
        novi->ime = v[i];
        if(i==0){
            pocetak = novi;
        }else{
            prethodni->sljedeci = novi;
        }
        prethodni = novi;
    }
    
    for(int i=0; i<br_timova; i++){
        if(i<ostatak){
            for(int j=0; j < (v.size()/br_timova)+1; j++){
                int duzina_imena(0);
                std::string pom(pocetak->ime);
                for(int k=0; k<pom.length(); k++){
                    if((pom[k] >= 'a' && pom[k] <= 'z')||(pom[k] >= 'A' && pom[k] <= 'Z')||(pom[k]>='0' && pom[k]<='9')){
                        duzina_imena++;
                    }
                }
                povratni[i].insert(pom);
                
                Dijete* pomocni = pocetak;
                if(!((prethodni == pocetak) && (pocetak->sljedeci = pocetak))){
                    prethodni->sljedeci = pocetak->sljedeci;
                    pocetak = pocetak->sljedeci;
                    duzina_imena--;
                
                    for(int k=0; k<duzina_imena; k++){
                        prethodni = pocetak;
                        pocetak = pocetak->sljedeci;
                    }
                }
                delete pomocni;
            }
        }else{
            for(int j=0; j < (v.size()/br_timova); j++){
                int duzina_imena(0);
                std::string pom(pocetak->ime);
                for(int k=0; k<pom.length(); k++){
                    if((pom[k] >= 'a' && pom[k] <= 'z')||(pom[k] >= 'A' && pom[k] <= 'Z')||(pom[k]>='0' && pom[k]<='9')){
                        duzina_imena++;
                    }
                }
                povratni[i].insert(pom);
                Dijete* pomocni = pocetak;
                if(!((prethodni == pocetak) && (pocetak->sljedeci = pocetak))){
                    prethodni->sljedeci = pocetak->sljedeci;
                    pocetak = pocetak->sljedeci;
                    duzina_imena--;
                
                    for(int k=0; k<duzina_imena; k++){
                        prethodni = pocetak;
                        pocetak = pocetak->sljedeci;
                    }
                }
                delete pomocni;
            }
        }
    }
    return povratni;
}
int main ()
{
    try{
        int n;
        std::cout << "Unesite broj djece: ";
        std::cin >> n;
        std::cin.ignore(1000, '\n');
        std::vector<std::string> v(n);
        std::cout << "Unesite imena djece: " << std::endl;
        for(int i=0; i<n; i++){
            std::getline(std::cin, v[i]);
        }
        int br_timova;
        std::cout << "Unesite broj timova: ";
        std::cin >> br_timova;
        std::vector< std::set<std::string> > timovi(Razvrstavanje(v, br_timova));
        for(int i=0; i<timovi.size(); i++){
            std::cout << "Tim " << i+1 << ": ";
            for(auto it=timovi[i].begin(); it!=timovi[i].end(); it++){
                if(it != --timovi[i].end()){
                    std::cout << *it <<", ";
                }else{
                    std::cout << *it;
                }
            }
            std::cout << std::endl;
        }
    }catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}