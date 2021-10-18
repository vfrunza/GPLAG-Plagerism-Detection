/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
enum class Boje{Pik,Tref,Herc,Karo};
typedef std::multimap<Boje, std::string> multimap;
typedef std::stack<std::pair<Boje, std::string>> stack;
struct Karta{
  Boje boja;
  std::string vrijednost;
};
struct Cvor{
  Karta karta;
  Cvor *sljedeci;
};

Cvor *KreirajSpil(){
    std::vector<std::string> a{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    Cvor *pocetak(nullptr), *prethodni;
    for(int i=0;i<4;i++){
      for(int j=0;j<a.size();j++){
        Karta b;
        b.boja=Boje(i);
        b.vrijednost=a[j];
        Cvor *novi(new Cvor);
        novi->karta=b;
        novi->sljedeci=nullptr;
        if(!pocetak)pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
      }
    }
    prethodni->sljedeci=pocetak;
    return pocetak;
}

bool LegalnaLista(Cvor *pocetak, int brojac){
  auto pomocna(pocetak);
  for(int i=0;i<brojac;i++){
    if(pomocna->sljedeci==pocetak)return true;
    pomocna=pomocna->sljedeci;
  }
  return false;
}

void IzbaciKarte(Cvor*& pocetak, multimap &a){
 Cvor* trenutna(pocetak);
 int broj{};
 while(trenutna->sljedeci!=pocetak){
   trenutna=trenutna->sljedeci;
   broj++;
 }
 broj++;
 if(!LegalnaLista(pocetak,broj)) throw std::logic_error("Neispravna lista!");
 
Cvor* prethodna(trenutna);
 trenutna=pocetak;
 Cvor*pomoc(nullptr);
 for(auto it=a.begin();it!=a.end();it++){
   while(pomoc!=pocetak){
   if(it->first==trenutna->karta.boja&&it->second==trenutna->karta.vrijednost) {
     it=a.erase(it);
     it--;
     prethodna->sljedeci=trenutna->sljedeci;
     auto p(trenutna);
     trenutna=trenutna->sljedeci;
     pomoc=trenutna;
     delete p;
     broj--;
     if(broj==0)pocetak=nullptr;
   }
   else {
       prethodna=trenutna;
       trenutna=trenutna->sljedeci;
       pomoc=trenutna;
   }
   }
 } 
 
}
 
stack IzbaciKarteRazbrajanjem(Cvor *pocetak,const short int &r, const int b){
    if(r<1||r>52||b<1)throw std::logic_error("Izuzetak: Neispravni elementi za izbacivanje!");
    Cvor* trenutna(pocetak);
  /*  int broj{};
    while(trenutna->sljedeci!=pocetak){
    trenutna=trenutna->sljedeci;
    broj++;
 }
 broj++;
 if(!LegalnaLista(pocetak,broj)) throw std::logic_error("Neispravna lista!");
 trenutna=pocetak;*/
 stack s;
 multimap izbaci;
 for(int i=0;i<b;i++){
     for(int j=0;j<r;j++) trenutna=trenutna->sljedeci;
     s.push(std::make_pair(trenutna->karta.boja,trenutna->karta.vrijednost));
     izbaci.insert(std::make_pair(trenutna->karta.boja,trenutna->karta.vrijednost));
     
 }
 IzbaciKarte(pocetak,izbaci);
 return s;
}
int Pretvori(std::string a){
     std::vector<std::string> karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
     int vrati{15};
     for(int i=0;i<karte.size();i++){ if(a==karte[i]) vrati=i;}
     return vrati;
}
bool SmislenStek(stack a){
    while(!a.empty()){
        if(int(a.top().first)<0||int(a.top().first)>3)return false;
        if(Pretvori(a.pop().second)==15) return false;
        a.pop();
    }
    return true;
}

VratiPosljednjihNKarata(Cvor *pocetak, stack& stek, int b){
    if(b>int(stek.size())) throw std::range_error("Nedovoljno karata u steku!");
    if(!SmislenStek) throw std::logic_error("Neispravne karte");
    for(int i=0;i<b;i++){
        
    }
}


int main ()
{
  auto p(KreirajSpil());
  /*//IzbaciKarte(p);
  //auto p(KreirajSpil());
  std::cout<<"\n";
  for(int i=0;i<13;i++){
    std::cout<<int(p->karta.boja)<<"|"<<p->karta.vrijednost<<std::endl;
    p=p->sljedeci;
  }*/
	return 0;
}
