/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <new>
#include <queue>
#include <stack>
#include <iterator>
#include <algorithm>

enum class Boje{Pik,Tref,Herc,Karo};

std::string printBoju(Boje boja);

struct Karta{
    Boje boja;
    std::string vrijednost;
};

struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};
/*
bool DaLiJeValidan(std::list<std::pair<Boje,std::string>> spil){
    for(auto it=spil.begin();it!=spil.end();it++){
        if(it->first!=Boje::Pik && it->first!=Boje::Karo && it->first!=Boje::Herc && it->first!=Boje::Tref){
            return false;
            break;
        }
        if(it->second!="2" && it->second!="3" && it->second!="4" && it->second!="5" && it->second!="6" && it->second!="7" && it->second!="8" && it->second!="9" &&
            it->second!="10" && it->second!="J" && it->second!="Q" && it->second!="K" && it->second!="A") {
                return false;
                break;
        }
    }
    return true;
}
*/


std::vector<std::string> Elementi{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

int VelicinaSpila(Cvor *prvi){
    int brojac(0);
    Cvor *trenutni=prvi;
    
    while (trenutni->sljedeci!=prvi) {
        brojac++;
        trenutni=trenutni->sljedeci;
        
    }
    brojac++;
    return brojac;
}

int pretvoriUInt(std::string par){
        if(par=="J") return 11;
        else if(par=="Q") return 12;
        else if(par=="K") return 13;
        else if(par=="A") return 14;
        return std::stoi(par);
}

/*
void sortirajSpil(std::list<std::pair<Boje, std::string>> &spil){
    spil.sort( [](std::pair<Boje, std::string> &a, std::pair<Boje, std::string> &b) -> bool
    {
       return pretvoriUInt(a.second) < pretvoriUInt(b.second); 
    });
}

bool DaLiSuSortirani (std::list<std::pair<Boje,std::string>> spil){
 
    bool gotovPik(false);
    bool gotovTref(false);
    bool gotovHerc(false);
    
    int brojPik(0);
    int brojTref(0);
    int brojHerc(0);
    int brojKaro(0);
    
    auto itPikP = spil.begin();
    auto itPikK = spil.begin();
    auto itTrefP = spil.begin();
    auto itTrefK = spil.begin();
    auto itHercP = spil.begin();
    auto itHercK = spil.begin();
    auto itKaroP = spil.begin();
    auto itKaroK = spil.begin();
    
    for(auto it = spil.begin(); it != spil.end(); it++){
        if(it->first==Boje::Pik && brojPik==0){
            if(gotovPik) return false;
            itPikP = it;
            itPikK = it;
            brojPik++;
        }
        else if(it->first==Boje::Pik){
            if(gotovPik) return false;
            itPikK++;
            brojPik++;
        }
        
        if(it->first==Boje::Tref && brojTref==0){
            gotovPik = true;
            if(gotovTref) return false; 
            itTrefP=it;
            itTrefK=it;
            brojTref++;
        }
        else if(it->first==Boje::Tref){
            if(gotovTref) return false;
            itTrefK++;
            brojTref++;
        }
        
        if(it->first==Boje::Herc && brojHerc==0){
            gotovPik = true;
            gotovTref = true;
            if(gotovHerc) return false;
            itHercP=it;
            itHercK=it;
            brojHerc++;
        }
        else if(it->first==Boje::Herc){
            if(gotovHerc) return false;
            itHercK++;
            brojHerc++;
        }
        if(it->first==Boje::Karo && brojKaro==0){
            gotovPik = true;
            gotovTref = true;
            gotovHerc = true;
            itKaroP=it;
            itKaroK=it;
            brojKaro++;
        }
        else if(it->first==Boje::Karo){
            itKaroK++;
            brojKaro++;
        }
    }
    
    if(brojPik > 1){
        auto prethodni = itPikP;
       do{
            itPikP++;
            if(pretvoriUInt(itPikP->second) <= pretvoriUInt(prethodni->second))
                return false;
            prethodni++;
        }while(itPikP!=itPikK);
    }
    
    if(brojTref>1){
        auto prethodni=itTrefP;
        do{
            itTrefP++;
            if(pretvoriUInt(itTrefP->second)<=pretvoriUInt(prethodni->second))
                return false;
            prethodni++;
        }while (itTrefP!=itTrefK); 
    }    
    if(brojHerc>1){
        auto prethodni=itHercP;
        do{
            itHercP++;
            if(pretvoriUInt(itHercP->second)<=pretvoriUInt(prethodni->second))
                return false;
            prethodni++;
        }while(itHercP!=itHercK);
    }
    
    if(brojKaro>1){
        auto prethodni=itKaroP;
        do{
            itKaroP++;
            if(pretvoriUInt(itKaroP->second)<=pretvoriUInt(prethodni->second))
                return false;
            prethodni++;
        }while(itKaroP!=itKaroK);
    }
    return true;
    
}
*/
Cvor *KreirajSpil(){
    
    Cvor *pocetak(nullptr), *prethodni(nullptr);
    try{
        for(int i=0;i<4;i++){
            Boje trenutnaboja =(Boje)i;
            for(int j=0;j<Elementi.size();j++){
                //Cvor *novi(new Cvor{{trenutnaboja,Elementi.at(j)},nullptr});
                Cvor *novi = (new Cvor);
                novi->karta.boja=trenutnaboja;
                //std::cout << printBoju(novi->karta.boja) << std::endl;
                novi->karta.vrijednost=Elementi.at(j);
                novi->sljedeci=nullptr;
                if(!pocetak) pocetak = novi;
                else {
                    novi->sljedeci=pocetak;
                    prethodni->sljedeci=novi;
                }
                prethodni=novi;
            }
        }
        
        /*//print
        auto p = pocetak;
        do {
            std::cout<< printBoju(p->karta.boja)<< " " << p->karta.vrijednost << 
            " sljedeca: " << printBoju(p->sljedeci->karta.boja) << " " << 
            p->sljedeci->karta.vrijednost << std::endl;
            
            p = p-> sljedeci;
        }
        while (p!=pocetak);
        
        //brisanje
        
        *auto p = pocetak;
        auto q = pocetak->sljedeci;
        delete p;
        for(q; q!=pocetak; q=q->sljedeci){
            std::cout << printBoju(q->karta.boja) << " " << q->karta.vrijednost << " sljedeca: " << printBoju(q->sljedeci->karta.boja) << " " << q->sljedeci->karta.vrijednost << std::endl;
            delete q;
        }*/
        
        //delete q;
        /*
        Cvor *pomocni = pocetak;
        do{
            pomocni = pomocni->sljedeci;
        }while(pomocni->sljedeci!=pocetak);
        
        pomocni->sljedeci = pocetak;
        delete pomocni;
        */
    }
    catch(std::bad_alloc){
        std::cout << "Entered catch" << std::endl;
        for(auto p=pocetak;p!=prethodni;p=p->sljedeci){
            delete p;
            throw;
        }
    }
    return pocetak;

}

void IspisiSpil(Cvor *&pocetak) {
    if(pocetak!=nullptr) {
        auto p = pocetak;
        do {
            std::cout<< printBoju(p->karta.boja)<< " " << p->karta.vrijednost << 
            " sljedeca: " << printBoju(p->sljedeci->karta.boja) << " " << 
            p->sljedeci->karta.vrijednost << std::endl;
            
            p = p-> sljedeci;
        }
        while (p!=pocetak);
    }
    
}
void UnistiSpil(Cvor *&pocetak) {
    
    auto drugi = pocetak -> sljedeci;
    pocetak -> sljedeci = nullptr;
    
    auto next = drugi -> sljedeci;
    while (drugi)
    {
        delete drugi;
        drugi = next;
        if(drugi)
            next = drugi -> sljedeci;
    }
    pocetak = nullptr;
    /*
        auto posljednji = pocetak;
        do {
            posljednji = posljednji-> sljedeci;
        }
        while (posljednji->sljedeci != pocetak);
        
        posljednji -> sljedeci = nullptr;
        auto next = pocetak->sljedeci;
        while(pocetak) {
            delete pocetak;
            pocetak = next;
            if(pocetak)
                next = pocetak -> sljedeci;
        }*/
}
void IzbaciKarte( Cvor *&prvi,std::multimap<Boje,std::string> &m){
   // if((spil.size()>52) || (!DaLiSuSortirani(spil)) || (!DaLiSuSortirani(spil))) throw std::logic_error("Neispravna lista!");
   Cvor *pomocni=prvi;
   Cvor *prethodni=nullptr;
   
   while (pomocni->sljedeci!=nullptr) {
       
       auto iter=m.begin();
      while(iter!=m.end()){
      // std::cout << "Usao na  "<< printBoju(pomocni->karta.boja) << pomocni->karta.vrijednost <<"      "<< printBoju(iter->first) << iter->second << std::endl;
        if( (pomocni->karta.boja==iter->first) && (pomocni->karta.vrijednost==iter->second) ){
            if(m.size()>1){
                iter=m.erase(iter);
            }
            else {
                m.clear();
            }
            prethodni->sljedeci=pomocni->sljedeci;
            delete pomocni;
            pomocni=prethodni->sljedeci;
          //std::cout << "Izlazim na "<<printBoju(pomocni->karta.boja)<<pomocni->karta.vrijednost<<"  "  << std::endl;  
        }
        if(m.size()>0)
            iter++; 
        else 
            iter=m.end();
        prethodni=pomocni;
      }
      pomocni=pomocni->sljedeci;
      
    //I ovdje memorijska  std::cout << printBoju(prvi->karta.boja)  << prvi->karta.vrijednost<< "prvi , a pomocni"<<printBoju(pomocni->karta.boja) <<pomocni->karta.vrijednost << std::endl;
   }
}

/*std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(Cvor *prvi,const short int &r, const int &b){
 //   if(b<1 || r<1 ||r>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
  //  if(spil.size()>52 || (!DaLiJeValidan(spil)) || (!DaLiSuSortirani(spil)) ) throw std::logic_error("Neispravna lista!");
    
    Cvor *pomocni=prvi;
    Cvor *prethodni=nullptr;
    std::stack<std::pair<std::string,std::string>> povratni ;
    
    int pozicija(0);
    int finalna;
    int pomjer;
     
    for(int i = 0; i < b; i++){
        for(int j=0;j<r;j++){
            pomocni=pomocni->sljedeci;
        }
        povratni.push(std::make_pair(printBoju(pomocni->karta.boja),pomocni->karta.vrijednost));
        
        prethodni->sljedeci=pomocni->sljedeci;
        delete pomocni;
    }    
        /*
        finalna=pozicija+r;
        if(finalna > spil.size()){
            //pomjer = finalna - (spil.size());
            pozicija = pomjer;
        }
        else{
            pomjer = r-1;
            pozicija += r;
        }
        if(std::distance(it, spil.end()) >= r){
        
            std::advance(it, pomjer);
            pozicija-=1;
        }
        else{
          
            pomjer+=1;
            std::advance(it, pomjer);
            pozicija-=1;
        }
        povratni.push(std::make_pair(printBoju(it->first),it->second));
        it=spil.erase(it);
    }
    return povratni;    
}
/*
Boje vratiEnum(std::string s){
    if(s=="Pik") return Boje::Pik;
    else if(s=="Tref") return Boje::Tref;
    else if(s=="Herc") return Boje::Herc;
    else if(s=="Karo") return Boje::Karo;
    return Boje::Pik;
}

bool DaLiJeRedValidan(std::queue<std::pair<std::string,std::string>> red){
    while (!red.empty()) {
        if(red.front().first!="Pik" && red.front().first!="Tref" && red.front().first!="Herc" && red.front().first!="Karo"){
            return false;
            break;
        }
        if(red.front().second!="2" && red.front().second!="3" && red.front().second!="4" && red.front().second!="5" && red.front().second!="6" && red.front().second!="7" && red.front().second!="8" && 
            red.front().second!="9" && red.front().second!="10" && red.front().second!="J" && red.front().second!="Q" && red.front().second!="K" && red.front().second!="A" ){
                return false;
                break;
            }
        red.pop();
    }
    return true;
}


void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &spil,std::queue<std::pair<std::string,std::string>> &povratni, int n){
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(spil.size()>52 || (!DaLiJeValidan(spil)) || (!DaLiSuSortirani(spil))) throw std::logic_error("Neispravna lista!");
    if(n>povratni.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(!DaLiJeRedValidan(povratni)) throw std::logic_error("Neispravne karte!");
    
    
    for(int i=0;i<n;i++){
            spil.push_back(std::make_pair(vratiEnum(povratni.front().first),povratni.front().second));
            povratni.pop();
    }
    
    sortirajSpil(spil);
    
}
*/
std::string printBoju(Boje boja){
    switch(boja) {
        case Boje::Pik:{
            return "Pik";
            break;
        }
        case Boje::Tref:{
            return "Tref";
            break;
        }
        case Boje::Herc:{
            return "Herc";
            break;
        }
        case Boje::Karo:{
            return "Karo";
            break;
        }
    }
    return "greska";
}

void ispisiMapu(std::multimap<Boje, std::string> m){
    if(m.size()==0) std::cout << "Nema clanova u mapi!" << std::endl;
    for(auto it=m.begin(); it!=m.end(); it++){
        std::cout << printBoju(it->first) << " " << it->second << std::endl;
    }
}
/*
void ispisiQueue(std::queue<std::pair<std::string, std::string>> q){
    if(q.empty()) std::cout << "Nema clanova u queueu!" << std::endl;
    while(!q.empty()){
        std::cout << q.front().first << " " << q.front().second<< std::endl;
        q.pop();
    }
}

void ispisiListu(std::list<std::pair<Boje,std::string>>spil){
    std::cout << "Pik: ";
    for(auto it=spil.begin();it!=spil.end();it++){
        if(it->first==Boje::Pik) std::cout << it->second<<" ";   
    }
    std::cout << std::endl;
    
    std::cout << "Tref: ";
    for(auto it=spil.begin();it!=spil.end();it++){
        if(it->first==Boje::Tref) std::cout << it->second << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Herc: ";
    for(auto it=spil.begin();it!=spil.end();it++){
        if(it->first==Boje::Herc) std::cout << it->second <<" ";
    }
    std::cout << std::endl;
    
    std::cout << "Karo: ";
    for(auto it=spil.begin();it!=spil.end();it++){
        if(it->first==Boje::Karo) std::cout << it->second << " ";
    }
    std::cout  << std::endl;
        
}
int prebrojiKarte(std::list<std::pair<Boje,std::string>>spil){
    int brojac(0);
    for(auto it=spil.begin();it!=spil.end();it++){
        brojac++;
    }
return brojac;
}


int main ()
{   int r,b,a;
    std::list<std::pair<Boje,std::string>> spil{{Boje::Pik,"4"},{Boje::Tref,"2"}};
    std::multimap<Boje,std::string> m{{Boje::Karo,"2"},{Boje::Pik,"3"},{Boje::Tref,"3"}};
    
    Cvor *prvi=nullptr;
    Cvor *zadnji=nullptr;
    
  try{
      
    spil=KreirajSpil();
    std::cout << "Unesite korak razbrajanja: " ;
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: " ;
    std::cin >> b;
   auto queue1 = IzbaciKarteRazbrajanjem(spil, r, b);
   std::cout << "U spilu trenutno ima "<<prebrojiKarte(spil)<<" karata, i to:" << std::endl;
   ispisiListu(spil);
   std::cout << "Unesite broj karata koje zelite vratiti u spil: " ;
   std::cin >> a;
   VratiPrvihNKarata(spil,queue1,a);
   std::cout << "U spilu trenutno ima "<<prebrojiKarte(spil)<<" karata, i to:" << std::endl;
   ispisiListu(spil);
  } 
  catch(std::exception &e){
      std::cout << "Izuzetak: "<<e.what() << std::endl;
  }
   
	return 0;
}

*/ 
void Isprintaj(Cvor *prvi){
    Cvor *pomocni=prvi;
   do {
        std::cout << printBoju(pomocni->karta.boja) <<" "<<pomocni->karta.vrijednost << std::endl;
        pomocni = pomocni->sljedeci;
    }
    while (pomocni!=prvi);
        
}
int main ()
{
    std::multimap<Boje,std::string> m{{Boje::Karo,"2"},{Boje::Pik,"3"},{Boje::Tref,"3"}};
   // std::stack<std::list<std::string,std::string>> izbacene ;
    Cvor *prva_karta = nullptr;
    prva_karta=KreirajSpil();
    //Isprintaj(prva_karta);
//    IzbaciKarte(prva_karta,m);
    //Isprintaj(prva_karta);
   // ispisiMapu(m);
   IspisiSpil(prva_karta);
   UnistiSpil(prva_karta);
   IspisiSpil(prva_karta);
	return 0;
}
