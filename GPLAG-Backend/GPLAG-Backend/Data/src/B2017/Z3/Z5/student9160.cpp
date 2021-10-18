/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <algorithm>

enum class Boje {Pik, Tref, Herc, Karo};
const std::vector<std::string> ImeKarte{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

struct Karta{
    Boje boja;
    std::string karta;
};

struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};

int BrojElemenata(Cvor *pocetak){
    int brojac(1);
    auto poc = pocetak->sljedeci;
    for(auto c = poc; c!=pocetak; c = c->sljedeci)
    brojac++;
    return brojac;
}

Cvor* KreirajSpil(){
    Cvor *pocetak(nullptr), *prethodni;
    for(int i(0);i<4;i++){
        for(int j(0);j<ImeKarte.size();j++){
            // kreiranje cvora
            Cvor *novi(nullptr);
            try{
                novi = new Cvor;
            }catch(std::bad_alloc){
                throw;
            }
            (novi->karta).boja = Boje(i);
            (novi->karta).karta = ImeKarte.at(j);
            novi->sljedeci = nullptr; 
            // spajanje svorova
            if(!pocetak) pocetak = novi;
            else prethodni->sljedeci = novi;
            prethodni = novi;
            if(j==ImeKarte.size()-1 && i == 3)
                novi->sljedeci = pocetak;
        }
    }
    return pocetak;
}

void IspisiSpil(Cvor *pocetak){
    const std::vector<std::string> boje{"Pik","Tref","Herc","Karo"};
    Boje temp = Boje::Pik;
    for(int b(0);b<4;b++){
        std::cout<<boje.at(b)<<": ";
        //Boje temp_boja = pocetak->karta.boja;
        while(pocetak->karta.boja == temp){
            std::cout<<pocetak->karta.karta<<" ";
            pocetak = pocetak->sljedeci;
        }
        temp = (*pocetak).karta.boja;
        std::cout<<std::endl;
    }    
}
bool CompCard(std::string a, std::string b){
    const std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    auto prvi(std::find(karte.begin(),karte.end(),a));
    auto drugi(std::find(karte.begin(),karte.end(),b));
    if(std::distance(prvi,drugi)<=0)return false;
    return true;
}
bool Sortirano(Cvor *pocetak){
    Cvor *it(pocetak),*slj(pocetak->sljedeci);
    if(it == slj)return true;
    do{
        if(slj->karta.boja == it->karta.boja && CompCard(slj->karta.karta,it->karta.karta))
            return false;
        it = it->sljedeci;
        slj = slj->sljedeci;
    }while(it != pocetak);
    return true;
}
bool Sadrzaj(Cvor *pocetak){
    const std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int n=BrojElemenata(pocetak);
    
    for(int i(0);i<n;i++){
        int brojac(0);
        for(int j(0);j<karte.size();j++)
            if(pocetak->karta.karta != karte.at(j))brojac++;
        if(brojac == karte.size())return false;
        pocetak = pocetak->sljedeci;
    }
    return true;
}
void Test(Cvor *pocetak){
    if(BrojElemenata(pocetak)>52 || !Sortirano(pocetak) || !Sadrzaj(pocetak))
        throw std::logic_error("Neispravna lista");
}
bool Isti(Cvor c, std::pair<Boje,std::string> p){
    return c.karta.boja == p.first && c.karta.karta == p.second;
}
void IzbaciKarte(Cvor *&pocetak, std::multimap<Boje,std::string> parovi){
    // treba testirati
    Test(pocetak);
    
   /* for(auto itMapa(parovi.begin());itMapa!=parovi.end();){
        auto itList(pocetak);auto n(BrojElemenata(pocetak));
        for(int i(0);i<n;i++){
            auto temp1=itList->sljedeci;
            if(Isti(*temp1,*itMapa)){
                // brisanje elemenata mape i elemnata iz lanca cvorova
                auto temp=itList->sljedeci;
                itList = temp->sljedeci;
                delete temp;
                itMapa = parovi.erase(itMapa);
                if(itMapa == parovi.end())return;
            }
        }
    }
*/
}
int main ()
{
    try{
        auto spil(KreirajSpil());
        int n = BrojElemenata(spil);
        std::cout<<n<<std::endl;
        IspisiSpil(spil);
        std::pair<Boje,std::string> par(std::make_pair(Boje::Pik,std::string("2")));
        std::pair<Boje,std::string> pa2(std::make_pair(Boje::Tref,std::string("2")));
        
        std::multimap<Boje,std::string> m{par,par,par,pa2,pa2,pa2};
        
        IzbaciKarte(spil,m);
        IspisiSpil(spil);
    }catch(std::bad_alloc){
        std::cout<<"Nema memorije"<<std::endl;
    }
    catch(std::logic_error e){
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}