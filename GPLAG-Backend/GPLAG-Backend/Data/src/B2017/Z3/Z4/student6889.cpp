#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <new>
#include <utility>
#include <stdexcept>
#include <memory>
#include <functional>
#include <cmath>
#include <list>
#include <string>
#include <map>
#include <queue>
enum class Boje {Pik,Tref,Herc,Karo};
typedef std::list<std::pair<std::string,std::string>> Karte;
Karte KreirajSpil(){
            Karte spil;
            std::string m;
            std::string b;
            for(int i=1;i<=4;i++){
                if(i==1){
                    b="Pik";
                }
                if(i==2){
                    b="Tref";
                }
                if(i==3){
                   b="Herc";
                }    
                if(i==4){
                    b="Karo";
                }
                for(int j=2;j<=14;j++){
                    if(j<=10){
                        m=std::to_string(j);
                    }
                    if(j==11){
                        m="J";
                    }
                    if(j==12){
                        m="Q";
                    }
                    if(j==13){
                        m="K";
                    }
                    if(j==14){
                        m="A";
                    }
                    spil.push_back(std::make_pair(b,m));
                }
                    
                }
                return spil;
}
void IzbaciKarte(Karte &x,std::multimap<std::string,std::string> &mapa){
    if(x.size()>52) throw std::logic_error ("Izuzetak: Neispravna lista!");
    for(auto l=x.begin();l!=x.end();l++){
        for(auto y=mapa.begin();y!=mapa.end();y++){
            if(((*l).first==(y->first)) && (*l).second==(y->second)){
                mapa.erase(y->first);
                mapa.erase(y->second);
                l=x.erase(l);
            }
        }
    }
}
std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(Karte &cards,const short int &a,const int &b){
    if(a<1 || a>52 || b<1) throw std::domain_error("Izuzetak: Neispravni elementi za izbacivanje!");
    if(cards.size()>52) throw std::logic_error("Izuzetak: Neispravna lista!");
    std::queue<std::pair<std::string,std::string>> kju;
    int nabrajanje=1;
    int brojUbacenih=0;
    auto y=cards.begin();
    for(;;){
        if(y==cards.end()) y=cards.begin();
        if(nabrajanje%a==0){
            kju.push(std::make_pair((*y).first,(*y).second));
            brojUbacenih++;
            y=cards.erase(y);
            nabrajanje++;
            if(brojUbacenih==b) break;
        }
        nabrajanje++;
        y++;
    }
    return kju;
}
void IzbaciPrvihNKarata(Karte &cards,typename std::queue<std::pair<std::string,std::string>> &ku,int n){
    if(n<0) throw std::domain_error("Izuzetak: Broj n je besmislen!");
    if(n>ku.size()) throw std::range_error("Izuzetak: Nedovoljno karata u redu!");
    int a=0;
    while(a<n){
        a++;
        int broj=0;
            if((ku.front().first)=="Pik"){
                if(ku.front().second=="2") broj=0;
                if(ku.front().second=="3") broj=1;
                if(ku.front().second=="4") broj=2;
                if(ku.front().second=="5") broj=3;
                if(ku.front().second=="6") broj=4;
                if(ku.front().second=="7") broj=5;
                if(ku.front().second=="8") broj=6;
                if(ku.front().second=="9") broj=7;
                if(ku.front().second=="10") broj=8;
                if(ku.front().second=="J") broj=9;
                if(ku.front().second=="Q") broj=9;
                if(ku.front().second=="K") broj=10;
                if(ku.front().second=="A") broj=12;
        }
        if((ku.front().first)=="Tref"){
                if(ku.front().second=="2") broj=12;
                if(ku.front().second=="3") broj=12;
                if(ku.front().second=="4") broj=13;
                if(ku.front().second=="5") broj=14;
                if(ku.front().second=="6") broj=15;
                if(ku.front().second=="7") broj=16;
                if(ku.front().second=="8") broj=17;
                if(ku.front().second=="9") broj=20;
                if(ku.front().second=="10") broj=19;
                if(ku.front().second=="J") broj=20;
                if(ku.front().second=="Q") broj=21;
                if(ku.front().second=="K") broj=22;
                if(ku.front().second=="A") broj=23;
        }
        if((ku.front().first)=="Herc"){
                if(ku.front().second=="2") broj=24;
                if(ku.front().second=="3") broj=25;
                if(ku.front().second=="4") broj=26;
                if(ku.front().second=="5") broj=27;
                if(ku.front().second=="6") broj=28;
                if(ku.front().second=="7") broj=29;
                if(ku.front().second=="8") broj=30;
                if(ku.front().second=="9") broj=31;
                if(ku.front().second=="10") broj=32;
                if(ku.front().second=="J") broj=33;
                if(ku.front().second=="Q") broj=34;
                if(ku.front().second=="K") broj=35;
                if(ku.front().second=="A") broj=36;
        }
        if((ku.front().first)=="Karo"){
                if(ku.front().second=="2") broj=37;
                if(ku.front().second=="3") broj=38;
                if(ku.front().second=="4") broj=39;
                if(ku.front().second=="5") broj=40;
                if(ku.front().second=="6") broj=41;
                if(ku.front().second=="7") broj=42;
                if(ku.front().second=="8") broj=43;
                if(ku.front().second=="9") broj=44;
                if(ku.front().second=="10") broj=45;
                if(ku.front().second=="J") broj=46;
                if(ku.front().second=="Q") broj=47;
                if(ku.front().second=="K") broj=48;
                if(ku.front().second=="A") broj=49;
        }
        int m=0;
        for(auto x=cards.begin();x!=cards.end();x++){
            if(m==broj){
                cards.insert(x,std::make_pair((ku.front().first),(ku.front().second)));
                break;
            }
            m++;
        }
        ku.pop();
    }
}

int main ()
{
    Karte m;
    m=KreirajSpil();
    try{
    std::cout << "Unesite korak razbrajanja: ";
    int korak;
    if(!(std::cin>> korak)) return 1;
    
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    int brojkarti;
    std::cin>>brojkarti;
    std::queue<std::pair<std::string,std::string>> kju(IzbaciKarteRazbrajanjem(m,korak,brojkarti));
    std::cout << "U spilu trenutno ima " << m.size() << " karata, i to:";
    std::cout << "\nPik: ";
    for(auto x=m.begin();x!=m.end();x++){
        if ((*x).first=="Pik") std::cout << (*x).second<<" ";
    }
     std::cout << "\nTref: ";
    for(auto x=m.begin();x!=m.end();x++){
        if ((*x).first=="Tref") std::cout << (*x).second<<" ";
    }
     std::cout << "\nHerc: ";
    for(auto x=m.begin();x!=m.end();x++){
        if ((*x).first=="Herc") std::cout << (*x).second<<" ";
    }
     std::cout << "\nKaro: ";
    for(auto x=m.begin();x!=m.end();x++){
        if ((*x).first=="Karo") std::cout << (*x).second<<" ";
    }
    std::cout <<"\nUnesite broj karata koje zelite vratiti u spil: ";
    int vratiUSpil;
    std::cin>>vratiUSpil;
    IzbaciPrvihNKarata(m,kju,vratiUSpil);
    std::cout << "U spilu trenutno ima " << m.size() << " karata, i to:";
    std::cout << "\nPik: ";
    for(auto x=m.begin();x!=m.end();x++){
        if ((*x).first=="Pik") std::cout << (*x).second<<" ";
    }
     std::cout << "\nTref: ";
    for(auto x=m.begin();x!=m.end();x++){
        if ((*x).first=="Tref") std::cout << (*x).second<<" ";
    }
     std::cout << "\nHerc: ";
    for(auto x=m.begin();x!=m.end();x++){
        if ((*x).first=="Herc") std::cout << (*x).second<<" ";
    }
     std::cout << "\nKaro: ";
    for(auto x=m.begin();x!=m.end();x++){
        if ((*x).first=="Karo") std::cout << (*x).second<<" ";
    }
    }
    catch(std::range_error e){
        std::cout << e.what();
    }
     catch(std::logic_error e){
        std::cout << e.what();
    }
     catch(std::domain_error e){
        std::cout << e.what();
    }
	return 0;
}