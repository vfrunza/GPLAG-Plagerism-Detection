/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <utility>
#include <list>
#include <map>
#include <stdexcept>
#include <queue>
#include <algorithm>
#include <iterator>

enum class Boje{Pik, Tref, Herc, Karo};
std::string Brojevi[13]{"2","3","4","5","6","7", "8","9","10","J","Q","K","A"};

typedef std::pair<Boje, std::string> KARTA;

struct Karta{
    Boje boja;
    std::string vrijednost; //prepraviti  vrijednost
}

struct Cvor{
    Karta karta;
    Cvor *sljedeci;
}

int vrijednost_karte(const KARTA &k){
    //svakoj karti dajem odredjeni broj
    //100 * redni broj boje + redni broj karte
    //na taj nacin ih je lakse poredati po redu koji je definiran u zadatku
    //vraca -1 ako karta nije smislena
    
    int vrijednost (1);
    if(int(k.first)==0 || int(k.first)==1 || int(k.first)==2 || int(k.first)==3)
        vrijednost *= 100 * int(k.first); 
    for(int j=0; j<13; j++)
        if(Brojevi[j] == k.second){
            return vrijednost + j;
        }
    return -1;
}

Cvor *KreirajSpil(){
    Cvor *pok_na_prvi (nullptr) pok_na_prethodni(nullptr);
    for(int i=0; i<13; i++)
    
    /*
    for(int i=0; i<13; i++)
        L.push_back(std::make_pair(Boje(0),Brojevi[i]));
    for(int i=0; i<13; i++)
        L.push_back(std::make_pair(Boje(1),Brojevi[i]));
    for(int i=0; i<13; i++)
        L.push_back(std::make_pair(Boje(2),Brojevi[i]));
    for(int i=0; i<13; i++)
        L.push_back(std::make_pair(Boje(3),Brojevi[i]));
    return L;
    */
}

bool PrvaKartaManja( KARTA &prva, KARTA &druga){
    return(vrijednost_karte(prva)<=vrijednost_karte(druga));
}

bool JeLiSortirana(std::list<std::pair<Boje, std::string>> &L){
    //vraca true ako je lista bila vec sortirana
    //vraca false ako lista nije bila sortirana i uz to je sortira
    auto iterator_na_zadnji = L.end();
    iterator_na_zadnji--;
    
    for (auto i=L.begin(); i!=iterator_na_zadnji; i++){
        int vrijednost_i (vrijednost_karte(*i)); //vrijednost karte na koju pokazuje iterator i 
        auto j(i); 
        for(j++; j!=L.end(); j++){
            int vrijednost_j(vrijednost_karte(*j));
            if(vrijednost_i > vrijednost_j){
                return false;
            }
        }
    }
    return true;
}

bool SmisleneKarte(std::list<std::pair<Boje, std::string>> &L){
    for (auto i=L.begin(); i!=L.end(); i++){
        if (vrijednost_karte(*i)==-1)
            return false;
    }
    return true;

    
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &L, std::multimap<Boje, std::string> &MM){
    if(L.size()>52) throw std::logic_error("Neispravna lista!");
    if(!JeLiSortirana(L)) throw std::logic_error("Neispravna lista!");
    
        for (auto i=MM.begin(); i!= MM.end(); i++){
            auto k=i;
            for (k++; k!=MM.end();)
                if(vrijednost_karte(*k)==vrijednost_karte(*i)){
                    k = MM.erase(k);
                }
                else
                        k++;
        }
        
        for(auto i=MM.begin(); i!=MM.end(); i++)
            for(auto j=L.begin(); j!= L.end(); )
                if(vrijednost_karte(*i)==vrijednost_karte(*j))
                    j=L.erase(j);
                else j++;
            
        
}

 
std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &L, const short int &r, const int b){
    if(b<1 || !(r>0 && r<53)) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(L.size()>52) throw std::logic_error("Neispravna lista!");
    if(!SmisleneKarte(L) || !JeLiSortirana(L)) throw std::logic_error("Neispravna lista!");
    
    std::queue<std::pair<Boje, std::string>> q;
    int kopija_n(b);
    for(std::list<std::pair<Boje, std::string>>::iterator i=L.begin(); i!=L.end() && kopija_n>0; i++){
        int kopija_r(r-1);
        while(kopija_r>0){
            i++;
            if(i==L.end()) i=L.begin();
            kopija_r--;
        }
        kopija_n--;     
        q.push((*i));
        i=L.erase(i);
        i--;
    }
    return q;
}

void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &L,std::queue<std::pair<Boje, std::string>> &R, int n){
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>R.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(L.size()>52) throw std::logic_error("Neispravna lista!");
    if(!SmisleneKarte(L) || !JeLiSortirana(L)) throw std::logic_error("Neispravna lista!");
    
    for(int i=0; i<n; i++){
        L.push_back(R.front());
        R.pop();
    }
    
    
    L.sort(PrvaKartaManja);
    
}

int main (){
    int r,b, n;
    std::pair<Boje, std::string> k;
    std::list<std::pair<Boje, std::string>> moja_lista;
    moja_lista = KreirajSpil();
    
    
    moja_lista.sort(PrvaKartaManja);
    
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    try{

    //std::multimap<Boje, std::string> MM{{Boje::Pik, "2"},{Boje::Pik, "7"},{Boje::Pik, "2"},{Boje::Pik, "7"},{Boje::Tref, "5"}};
    //IzbaciKarte(moja_lista,MM);
    std::queue<std::pair<Boje, std::string>> q;
    q=IzbaciKarteRazbrajanjem(moja_lista,r,b);
    
    std::cout << "U spilu trenutno ima " << moja_lista.size() << " karata, i to: ";
    
    std::cout << std::endl << "Pik: ";
    for(std::pair<Boje, std::string> karta: moja_lista)
        if(int(karta.first)==0) std::cout << karta.second << " ";
    
    std::cout << std::endl << "Tref: ";
    for(std::pair<Boje, std::string> karta: moja_lista)
        if(int(karta.first)==1) std::cout << karta.second << " ";
    
    std::cout << std::endl << "Herc: ";
    for(std::pair<Boje, std::string> karta: moja_lista)
        if(int(karta.first)==2) std::cout << karta.second << " ";
    
    std::cout << std::endl << "Karo: ";
    for(std::pair<Boje, std::string> karta: moja_lista)
        if(int(karta.first)==3) std::cout << karta.second << " ";
    
    
    std::cout<< std::endl << "Unesite broj karata koje zelite vratiti u spil: ";
    std::cin >> n;
    VratiPrvihNKarata(moja_lista,q,n);
    
    std::cout << "U spilu trenutno ima " << moja_lista.size() << " karata, i to: ";
    
    
    std::cout <<std::endl << "Pik: ";
    for(std::pair<Boje, std::string> karta: moja_lista)
        if(int(karta.first)==0) std::cout << karta.second << " ";
    
    std::cout << std::endl << "Tref: ";
    for(std::pair<Boje, std::string> karta: moja_lista)
        if(int(karta.first)==1) std::cout << karta.second << " ";
    
    std::cout << std::endl << "Herc: ";
    for(std::pair<Boje, std::string> karta: moja_lista)
        if(int(karta.first)==2) std::cout << karta.second << " ";
    
    std::cout << std::endl << "Karo: ";
    for(std::pair<Boje, std::string> karta: moja_lista)
        if(int(karta.first)==3) std::cout << karta.second << " ";
    
    }
    catch(std::range_error e){
        std::cout << "Izuzetak: "<<e.what(); 
    }
    catch(std::domain_error e){
        std::cout << "Izuzetak: "<<e.what(); 
    }
    catch(std::logic_error e){
        std::cout << "Izuzetak: "<<e.what(); 
    }

    return 0;
	
}