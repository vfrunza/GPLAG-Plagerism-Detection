#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include<memory>
using std::string;
using std::cout;
using std::cin;
std::vector<string>vK {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

enum class Boje
{
    Pik, Tref, Herc, Karo
};
using std::string;
struct Karta {
    Boje boja;
    string vrijednost;
};
struct Cvor {
    Karta karta;
    //Cvor *sljedeci;
    std::shared_ptr<Cvor> sljedeci;
};

int Velicina(std::shared_ptr<Cvor>pocetak){
    int brojac(0);
    auto kopija(pocetak);
    while(kopija->sljedeci!=pocetak){
        brojac++;
        kopija=kopija->sljedeci;
    }
    brojac++;
    return brojac;
}



bool ProvjeriBoje( Boje boja)
{
    if(boja!=Boje::Pik && boja!=Boje::Tref && boja!=Boje::Herc && boja!=Boje::Karo)
        return false;
    return true;
}
bool ProvjeriKartu(string k)
{

    int istina(1);
    for(int i=0; i<13; i++) {
        if(k==vK[i]) {
            istina=1;
            break;
        } else istina=0;
    }
    if(istina) return true;
    return false;
}

bool ProvjeriRed(std::stack<std::pair<string,string>> stek)  //prepraviti na stek
{
    while(!stek.empty()) {
        std::pair<string,string> par(stek.top());
        if(par.first!="Pik" && par.first!="Tref" && par.first!="Herc" && par.first!="Karo") return false;
        if(!ProvjeriKartu(par.second)) return false;
        stek.pop();
    }
    return true;
}
bool ProvjeriStek(std::stack<std::pair<string,string>> red)
{
    while(!red.empty()) {
        std::pair<string,string> par(red.top());
        red.pop();
        if(par.first!="Pik" && par.first!="Tref" && par.first!="Herc" && par.first!="Karo") return false;
        if(!ProvjeriKartu(par.second)) return false;
        
    }
    return true;
}


string Konvertuj(Boje b)
{
    if(b==Boje::Pik) return "Pik";
    else if(b==Boje::Tref) return "Tref";
    else if(b==Boje::Herc) return "Herc";
    else return "Karo";
}

Boje KonvertujUB(string b)
{
    if(b=="Pik") return Boje::Pik;
    else if(b=="Tref") return Boje::Tref;
    else if(b=="Herc") return Boje::Herc;
    else return Boje::Karo;
}

int VelicinaListe(std::shared_ptr<Cvor>pocetak)
{
    auto kopija(pocetak);
    int brojac(0);
    while(kopija->sljedeci!=pocetak) {
        brojac++;
        kopija=kopija->sljedeci;
    }
    return brojac;
}

std::shared_ptr<Cvor> KreirajSpil()
{
   std::shared_ptr<Cvor> pocetak(nullptr);std::shared_ptr<Cvor>prethodni;
    for(int i(0); i<52; i++) {
      std::shared_ptr<Cvor>novi(new Cvor);
        if(i<=12) {
            novi->karta.boja=Boje::Pik;
            novi->karta.vrijednost=vK[i];
        } else if(i>=13 && i <=25) {
            novi->karta.boja=Boje::Tref;
            novi->karta.vrijednost=vK[i-13];
        } else if(i>=26 && i<=38) {
            novi->karta.boja=Boje::Herc;
            novi->karta.vrijednost=vK[i-26];
        } else if(i>=39) {
            novi->karta.boja=Boje::Karo;
            novi->karta.vrijednost=vK[i-39];
        }
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else if(i==51) {
            prethodni->sljedeci=novi;
            novi->sljedeci=pocetak;
            break; //zbog zadnjeg reda petlje
        } else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    return pocetak;
}

std::shared_ptr<Cvor> Nadji(std::shared_ptr<Cvor>pocetak,std::pair<Boje,std::string>par)
{
  std::shared_ptr<Cvor> rez=pocetak; //novi pokazivac na pocetak
    while(rez->sljedeci!=pocetak) {
        if(rez->karta.boja==par.first && rez->karta.vrijednost==par.second)
            return rez;
        rez=rez->sljedeci;
    }
    if(rez->karta.boja == par.first && rez->karta.vrijednost == par.second) return rez;
    //ako se nije prekinuo program,karte nema u listi i tada vracam ->
    return nullptr;
}

std::shared_ptr<Cvor> DajPrethodni(std::shared_ptr<Cvor>pocetak,std::shared_ptr<Cvor>trazeni)
{
   std::shared_ptr<Cvor> dalje=pocetak;
    while(dalje->sljedeci!=trazeni) {
        //std::cout << "zapeo sam tugi";
        dalje=dalje->sljedeci;
    }
    return dalje;
}

void IzbaciKarte(std::shared_ptr<Cvor>&pocetak,std::multimap<Boje, std::string> &multimapa)
{
  
  if(Velicina(pocetak)>52) throw std::logic_error("Neispravna lista!");
  auto nesto(pocetak);
    while(nesto->sljedeci!=pocetak){
 if(!ProvjeriBoje(nesto->karta.boja)) throw std::logic_error("Neispravna lista!");
        nesto=nesto->sljedeci;
    }
    if(!ProvjeriBoje(nesto->karta.boja)) throw std::logic_error("Neispravna lista!");    

   auto nesto2(pocetak);
   while(nesto2->sljedeci!=pocetak){
        if(!ProvjeriKartu(nesto2->karta.vrijednost)) throw std::logic_error("Neispravna lista!");
       nesto2=nesto2->sljedeci; }//provjera da li su karte besmislene
   // if(!DaLijeRedOk(spil)) throw std::logic_error("Neispravna lista!"); ZAVRSIT
  
  
    for(auto it=multimapa.begin(); it!=multimapa.end();) {
        auto nadjeno(Nadji(pocetak,*it));
        if(nadjeno!=nullptr) {
            if(nadjeno == pocetak) {
                //kako postaviti uslov da nadjeni pokazuje na prvi cvor
                //treba azurirati pocetak
                pocetak = pocetak->sljedeci;
                if(pocetak == pocetak->sljedeci) pocetak = nullptr;
                auto prethodni = DajPrethodni(pocetak, nadjeno);
                prethodni->sljedeci = pocetak;
               // delete nadjeno;
                it=multimapa.erase(it);
            } else {
                auto kopija(nadjeno); //plitka kopija
                auto prethodni(DajPrethodni(pocetak,nadjeno));
                kopija=kopija->sljedeci; //kopiju preusmjeravam na sljedeci element kako ne bi izgubila pokazivac na njega
               // delete prethodni->sljedeci;
                prethodni->sljedeci=kopija; //prethodni pokazije na cvor koji je sljedbenik izbrisanom cvoru
                it=multimapa.erase(it);
            }
        } else it++;
    }
}



std::stack<std::pair<string,string>> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor>&pocetak,const short int &r,const int &b)
{
     if(r<1 || r>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
     if(Velicina(pocetak)>52) throw std::logic_error("Neispravna lista!");
  auto nesto(pocetak);
    while(nesto->sljedeci!=pocetak){
 if(!ProvjeriBoje(nesto->karta.boja)) throw std::logic_error("Neispravna lista!");
        nesto=nesto->sljedeci;
    }
    if(!ProvjeriBoje(nesto->karta.boja)) throw std::logic_error("Neispravna lista!");    

   auto nesto2(pocetak);
   while(nesto2->sljedeci!=pocetak){
        if(!ProvjeriKartu(nesto2->karta.vrijednost)) throw std::logic_error("Neispravna lista!");
       nesto2=nesto2->sljedeci; }//provjera da li su karte besmislene
   // if(!DaLijeRedOk(spil)) throw std::logic_error("Neispravna lista!"); ZAVRSIT
    
    
    std::stack<std::pair<string,string>> stek;
  std::shared_ptr<Cvor> kopija=pocetak;
   
    for(int i(0); i<r-1; i++) kopija=kopija->sljedeci; //pomjeram za r mjesta
    int brojizbacenih(0);
    while(brojizbacenih!=b && pocetak!=nullptr) {
        string boja(Konvertuj(kopija->karta.boja));
        string karta1(kopija->karta.vrijednost);
        stek.push(std::make_pair(boja,karta1));

        auto kopija2(kopija); //plitka kopija
        auto prethodni(DajPrethodni(pocetak,kopija2));
        kopija=kopija->sljedeci; //kopiju preusmjeravam na sljedeci element kako ne bi izgubila pokazivac na njega
        if(kopija2 == pocetak) pocetak = pocetak->sljedeci;
        if(pocetak == pocetak->sljedeci) pocetak = nullptr;
        //delete prethodni->sljedeci;
        if(pocetak != nullptr) {
            prethodni->sljedeci=kopija; //da ne bi sada morala stavljat vracanje na prethodni element moze li
            for(int i=0; i<r-1; i++) kopija=kopija->sljedeci;
        }
        brojizbacenih++;
    }
if(pocetak==nullptr) pocetak->sljedeci=nullptr; 
    return stek;
}

void VratiPosljednjihNKarata(std::shared_ptr<Cvor>&pocetak,std::stack<std::pair<string,string>> &stek,int n)
{
 if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>stek.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(!ProvjeriStek(stek)) throw std::logic_error("Neispravne karte!");


    auto kopija(pocetak);
    int j(n);
    while(j!=0) {
        
        kopija = pocetak;
        std::pair<string,string> par(stek.top());
        stek.pop();
        auto rezPar=std::make_pair(KonvertujUB(par.first),par.second);
        auto itUbacivanje = std::find(vK.begin(), vK.end(), rezPar.second);
        bool postoji(false);
        if(pocetak != nullptr) {
            while(kopija->sljedeci != pocetak) {
                if(kopija->karta.boja == rezPar.first && kopija->karta.vrijednost == rezPar.second) postoji = true;
                kopija = kopija->sljedeci;
            }
            if(kopija->karta.boja == rezPar.first && kopija->karta.vrijednost == rezPar.second) postoji = true;
            if(postoji) {
                continue;
            }
      std::shared_ptr<Cvor> novi ( new Cvor);
            novi->karta.boja = rezPar.first;
            novi->karta.vrijednost = rezPar.second;
            novi->sljedeci = nullptr;
            kopija = pocetak;
            bool ubacena(false);
            while(kopija->sljedeci != pocetak) {
                int kontrolna(0);
                while(kopija->karta.boja < rezPar.first) {
                    if(kopija == pocetak) kontrolna++;
                    if(kontrolna > 1) break;
                    kopija = kopija->sljedeci;
                }
                if(kopija->karta.boja == rezPar.first) { // ima karata koje su iste boje kao ova nasa
                    while(kopija->karta.boja == rezPar.first) {
                        auto itKopija = std::find(vK.begin(), vK.end(), kopija->karta.vrijednost);
                        if(itUbacivanje > itKopija) kopija = kopija->sljedeci;
                        else break;
                    }
                    j--;
                    ubacena = true;
                    auto prethodni = DajPrethodni(pocetak, kopija);
                    novi->sljedeci = kopija;
                    prethodni->sljedeci = novi;
                    if(prethodni->karta.boja > novi->karta.boja) pocetak = novi;
                    else if(prethodni->karta.boja == novi->karta.boja) {
                        auto itPrethodni = std::find(vK.begin(), vK.end(), prethodni->karta.vrijednost);
                        if(itUbacivanje < itPrethodni) pocetak = novi;
                    }
                    break;
                } else { // nalazimo se kod karte koja je sljedbenik naše
                    j--;
                    ubacena = true;
                    auto prethodni(DajPrethodni(pocetak, kopija));
                    novi->sljedeci = kopija;
                    prethodni->sljedeci = novi;
                    if(novi->karta.boja < kopija->karta.boja) pocetak = novi;
                    else if(novi->karta.boja == kopija->karta.boja) {
                        auto itNovi = std::find(vK.begin(), vK.end(), novi->karta.vrijednost);
                        auto itKopija = std::find(vK.begin(), vK.end(), kopija->karta.vrijednost);
                        if(itNovi < itKopija) pocetak = novi;
                    }
                    break;
                }
            }
            if(!ubacena) {
                kopija->sljedeci = novi;
                novi->sljedeci = kopija;
                if(novi->karta.boja == kopija->karta.boja) {
                    auto itKopija = std::find(vK.begin(), vK.end(), kopija->karta.vrijednost);
                    if(itUbacivanje < itKopija) pocetak = novi;
                }
                if(novi->karta.boja < kopija->karta.boja) pocetak = novi;
                j--;
            }
        } else {
         std::shared_ptr<Cvor> novi (new Cvor);
            novi->karta.boja = rezPar.first;
            novi->karta.vrijednost = rezPar.second;
            novi->sljedeci = nullptr;
            pocetak = novi;
            pocetak->sljedeci = pocetak;
            j--;
        }
    }
}
int main ()
{
  std::shared_ptr<Cvor>  spil;
try{
    cout<<"Unesite korak razbrajanja: ";
    short int korak_razbrajanja;
    cin>>korak_razbrajanja;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    int izbaciti;
    cin>>izbaciti; //poziv funkcije kreiraj spil
     spil=KreirajSpil();
    auto stek(IzbaciKarteRazbrajanjem(spil,korak_razbrajanja,izbaciti)); //iz spila izbacene karte i vracen red koji sadrzi izbacene karte
  
    cout<<"U spilu trenutno ima "<<Velicina(spil)<<" karata, i to:"<<std::endl;

auto kopija5(spil);
while(kopija5->sljedeci!=spil){
     cout<<Konvertuj(kopija5->karta.boja)<<": ";
        auto boja(kopija5->karta.boja);
         while(kopija5->sljedeci!=spil && kopija5->karta.boja==boja ) {
            cout<<kopija5->karta.vrijednost<<" ";
            kopija5=kopija5->sljedeci;
        }
        if(kopija5->sljedeci==spil) break;
        cout<<std::endl;
        
}

  cout<<kopija5->karta.vrijednost<<" ";  
    cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
    int n;
    cin>>n;
    VratiPosljednjihNKarata(spil,stek,n);
    cout<<"U spilu trenutno ima "<<Velicina(spil)<<" karata, i to:"<<std::endl;
    
    auto kopija6(spil);
while(kopija6->sljedeci!=spil){
     cout<<Konvertuj(kopija6->karta.boja)<<": ";
        auto boja(kopija6->karta.boja);
         while(kopija6->sljedeci!=spil && kopija6->karta.boja==boja ) {
            cout<<kopija6->karta.vrijednost<<" ";
            kopija6=kopija6->sljedeci;
           
        }
       if(kopija6->sljedeci==spil) break;
        cout<<std::endl;
        
}
  cout<<kopija6->karta.vrijednost<<" ";  
    
}
catch(std::logic_error e) {
        cout<<"Izuzetak: "<<e.what();
    } catch(std::domain_error e) {
        cout<<"Izuzetak: "<<e.what();
    } catch(std::range_error e) {
        cout<<"Izuzetak: "<<e.what();
    }
    

spil->sljedeci=nullptr;

    return 0;
}