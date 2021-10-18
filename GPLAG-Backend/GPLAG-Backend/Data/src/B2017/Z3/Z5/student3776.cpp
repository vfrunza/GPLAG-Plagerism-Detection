#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <utility>
enum class Boje {Pik,Tref,Herc,Karo};
struct Karta{
    Boje boja;
    std::string vrijednost;
};
struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};
 
 
std::queue<std::pair<std::string,std::string>> IzbaciKarte(Cvor *&pocetak ,const std::pair<int,int> par);
void VratiPrvihNKarata(Cvor *cvor,std::queue<std::pair<std::string,std::string>> &red,int n);
int PrebrojiKarte(Cvor *cvor);
void UnistiSpil(Cvor *cvor);
Cvor *KreirajSpil();
 
int main() {
    try{
        Cvor *pok=KreirajSpil();
        int korak,brkarata;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>korak;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>brkarata;
        std::pair<int,int> par_izbaci;
        par_izbaci=std::make_pair(korak,brkarata);
        std::queue<std::pair<std::string,std::string>> red=IzbaciKarte(pok,par_izbaci);
        int brizb=PrebrojiKarte(pok);
        std::cout<<"U spilu trenutno ima: "<<52-brizb<<" karata, i to:"<<std::endl;
        //***ISPIS KARATA U SPILU***
        Cvor *pocetni=pok;
        Boje tmpboja=Boje(0);
       
        std::cout<<"Pik: ";
        for(;;){
            Karta tmpkarta=pocetni->karta;
            if(tmpkarta.boja!=tmpboja){
                if(tmpkarta.boja==Boje(1)){
                    std::cout<<std::endl;
                    std::cout<<"Tref: ";
                    tmpboja=Boje(1);
                }
                else if(tmpkarta.boja==Boje(2)){
                    std::cout<<std::endl;
                    std::cout<<"Herc: ";
                    tmpboja=Boje(2);
                }  
                else if(tmpkarta.boja==Boje(3)){
                    std::cout<<std::endl;
                    std::cout<<"Karo: ";
                    tmpboja=Boje(3);
                }
            }
            std::cout<<tmpkarta.vrijednost<<" ";
            if(pocetni->sljedeci==pok){
                break;
            }
            pocetni=pocetni->sljedeci;
        }
        std::cout<<std::endl;
        /*
        int vracanje;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>vracanje;
        VratiPrvihNKarata(pok,red,vracanje);
        std::cout<<"Broj karata u steku: "<<red.size()<<std::endl;
        std::cout<<"Trenutne karte u steku: "<<std::endl;
        std::queue<std::pair<std::string,std::string>> red1=red;
        while(!red1.empty()){
            std::pair<std::string,std::string> p=red1.front();          
            std::cout<<p.first<<" "<<p.second<<std::endl;
            red1.pop();
        }
        std::cout<<"Raspored: "<<std::endl;
        Cvor *sort=pok;
        std::cout<<(sort->karta).vrijednost<<" ";
        sort=sort->sljedeci;
        while(sort!=pok){
            std::cout<<(sort->karta).vrijednost<<" ";
            sort=sort->sljedeci;
        }
        */
        return 0;
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
    catch(std::range_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
    catch(const char *c){
        std::cout<<c<<std::endl;
    }
}
Cvor *KreirajSpil(){
    try{
        Cvor *pocetak(nullptr), *prethodni;
    for(int i=0;i<4;i++){
        Boje tmpboja=Boje(i);
        for(int j=2;j<=14;j++) {
            Karta tmpkarta;
            std::string tmp;
            if(j==2)tmp="2";
            else if(j==3)tmp="3";
            else if(j==4)tmp="4";
            else if(j==5)tmp="5";
            else if(j==6)tmp="6";
            else if(j==7)tmp="7";
            else if(j==8)tmp="8";
            else if(j==9)tmp="9";
            else if(j==10)tmp="10";
            else if(j==11)tmp="J";
            else if(j==12)tmp="Q";
            else if(j==13)tmp="K";
            else if(j==14)tmp="A";
            tmpkarta.boja=tmpboja;
            tmpkarta.vrijednost=tmp;
            Cvor *novi(new Cvor);
            novi->karta = tmpkarta; novi->sljedeci = nullptr;
            if(i==0 && j==2){
                pocetak=novi;
                prethodni=novi;
            }
            else if(i==3 && j==14) {
                prethodni->sljedeci = novi;
                novi->sljedeci=pocetak;
               
            }
            else {
                prethodni->sljedeci = novi;
                prethodni=novi;
            }
        }
    }
    return pocetak;
       
    }
    catch(std::bad_alloc){
        throw ("Memorijska greska");
    }
}
std::queue<std::pair<std::string,std::string>> IzbaciKarte(Cvor *&pocetak,const std::pair<int,int> par){
    if(par.first<1 || par.first>52 || par.second<1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    std::queue<std::pair<std::string,std::string>> red;
    int brkarata=par.second;
    int korak=par.first;
    Cvor *poc=pocetak;
    //za izbacivanje svih karata
    if(brkarata==PrebrojiKarte(poc)){
        Cvor *kopija=pocetak;
        for(int i=0;i<brkarata;i++){
            Karta tmpkarta=kopija->karta;
            //ubacivanje u red
            std::string tmpstringovski;
            if(tmpkarta.boja==Boje(0))tmpstringovski="Herc";
            if(tmpkarta.boja==Boje(1))tmpstringovski="Karo";
            if(tmpkarta.boja==Boje(2))tmpstringovski="Pik";
            if(tmpkarta.boja==Boje(3))tmpstringovski="Tref";
            std::pair<std::string,std::string> sljpar;
            sljpar=std::make_pair(tmpstringovski,tmpkarta.vrijednost);
            red.push(sljpar);
            kopija=kopija->sljedeci;
            if(i==brkarata-1){
                Cvor *krajnji=pocetak;
                while(krajnji->sljedeci!=pocetak)krajnji=krajnji->sljedeci;
                krajnji->sljedeci=nullptr;
                while(pocetak->sljedeci!=nullptr){
                    Cvor *cvor1=pocetak;
                    pocetak=pocetak->sljedeci;
                    cvor1->sljedeci=cvor1;
                    delete cvor1;
                }
                pocetak=nullptr;
            }
        }
    }
    //za izbacivanje n-1 karata
    /*else if(brkarata==PrebrojiKarte(poc)-1){
       
    }*/
    else{
        Cvor *poc1=pocetak;
        int k=0;
        int p=0;
        while((poc->sljedeci)!=poc1)poc=poc->sljedeci;
        for(int i=0;i<brkarata;i++){
            for(int j=0;j<korak-1;j++){
                poc1=poc1->sljedeci;
                poc=poc->sljedeci;
                p++;
                std::cout<<p;
               
            }
            Karta tmpkarta=poc1->karta;
            //ubacivanje u red
            std::string tmpstringovski;
            if(tmpkarta.boja==Boje(0))tmpstringovski="Pik";
            if(tmpkarta.boja==Boje(1))tmpstringovski="Tref";
            if(tmpkarta.boja==Boje(2))tmpstringovski="Herc";
            if(tmpkarta.boja==Boje(3))tmpstringovski="Karo";
            std::pair<std::string,std::string> sljpar;
            sljpar=std::make_pair(tmpstringovski,tmpkarta.vrijednost);
            red.push(sljpar);
            //BRISANJE
            Cvor *slijed=poc1;
            if(slijed==pocetak){
                Cvor *priv=pocetak;
                while((priv->sljedeci)!=pocetak)priv=priv->sljedeci;
                pocetak=pocetak->sljedeci;
                priv->sljedeci=pocetak;
                slijed->sljedeci=slijed;
                delete slijed;
            }
            else{
                poc1=poc1->sljedeci;
                poc->sljedeci=slijed->sljedeci;
                slijed->sljedeci=slijed;
                delete slijed;
            }
            k++;
        }
    }
    return red;
}
int PrebrojiKarte(Cvor *cvor){
    Cvor *cvorpoc=cvor;
    int br=0;
    if(cvor==cvor->sljedeci){
        br=1;
        return br;
    }
    br++;
    while((cvor->sljedeci)!=cvorpoc){
        cvor=cvor->sljedeci;
        br++;
    }
    br=52-br;
    return br;
}
void VratiPrvihNKarata(Cvor *cvor,std::queue<std::pair<std::string,std::string>> &red,int n){
    int vel=red.size();
    if(n>vel)throw std::range_error("Nedovoljno karata u steku!");
    /*if(cvor==nullptr){
        for(int i=0;i<n;i++){
           
        }
    }
    else{*/
        Cvor *poc=cvor;
        Cvor *uporedni=cvor;
        while((uporedni->sljedeci)!=poc)uporedni=uporedni->sljedeci;
        for(int i=0;i<n;i++){
            std::pair<std::string,std::string> par=red.front();
            Boje tmpboja;
            int poredbeni;
            int k;
            if(par.first=="Pik"){
                tmpboja=Boje(0);
                k=0;
            }
            if(par.first=="Tref"){
                tmpboja=Boje(1);
                k=1;
            }
            if(par.first=="Herc"){
                tmpboja=Boje(2);
                k=2;
            }
            if(par.first=="Karo"){
                tmpboja=Boje(3);
                k=3;
            }
            if(par.second=="2")poredbeni=2;
            if(par.second=="3")poredbeni=3;
            if(par.second=="4")poredbeni=4;
            if(par.second=="5")poredbeni=5;
            if(par.second=="6")poredbeni=6;
            if(par.second=="7")poredbeni=7;
            if(par.second=="8")poredbeni=8;
            if(par.second=="9")poredbeni=9;
            if(par.second=="10")poredbeni=10;
            if(par.second=="J")poredbeni=11;
            if(par.second=="Q")poredbeni=12;
            if(par.second=="K")poredbeni=13;
            if(par.second=="A")poredbeni=14;
            int cvorboja;
            if((cvor->karta).boja==Boje(0))cvorboja=0;
            if((cvor->karta).boja==Boje(1))cvorboja=1;
            if((cvor->karta).boja==Boje(2))cvorboja=2;
            if((cvor->karta).boja==Boje(3))cvorboja=3;
            int cvorp;
            if((cvor->karta).vrijednost=="2")cvorp=2;
            if((cvor->karta).vrijednost=="3")cvorp=3;
            if((cvor->karta).vrijednost=="4")cvorp=4;
            if((cvor->karta).vrijednost=="5")cvorp=5;
            if((cvor->karta).vrijednost=="6")cvorp=6;
            if((cvor->karta).vrijednost=="7")cvorp=7;
            if((cvor->karta).vrijednost=="8")cvorp=8;
            if((cvor->karta).vrijednost=="9")cvorp=9;
            if((cvor->karta).vrijednost=="10")cvorp=10;
            if((cvor->karta).vrijednost=="J")cvorp=11;
            if((cvor->karta).vrijednost=="Q")cvorp=12;
            if((cvor->karta).vrijednost=="K")cvorp=13;
            if((cvor->karta).vrijednost=="A")cvorp=14;
           
           
            while(cvorboja!=k){
                cvor=cvor->sljedeci;
                uporedni=uporedni->sljedeci;
                if((cvor->karta).boja==Boje(0))cvorboja=0;
                if((cvor->karta).boja==Boje(1))cvorboja=1;
                if((cvor->karta).boja==Boje(2))cvorboja=2;
                if((cvor->karta).boja==Boje(3))cvorboja=3;
            }
            while(cvorp<poredbeni){
                cvor=cvor->sljedeci;
                uporedni=uporedni->sljedeci;
                if((cvor->karta).vrijednost=="2")cvorp=2;
                if((cvor->karta).vrijednost=="3")cvorp=3;
                if((cvor->karta).vrijednost=="4")cvorp=4;
                if((cvor->karta).vrijednost=="5")cvorp=5;
                if((cvor->karta).vrijednost=="6")cvorp=6;
                if((cvor->karta).vrijednost=="7")cvorp=7;
                if((cvor->karta).vrijednost=="8")cvorp=8;
                if((cvor->karta).vrijednost=="9")cvorp=9;
                if((cvor->karta).vrijednost=="10")cvorp=10;
                if((cvor->karta).vrijednost=="J")cvorp=11;
                if((cvor->karta).vrijednost=="Q")cvorp=12;
                if((cvor->karta).vrijednost=="K")cvorp=13;
                if((cvor->karta).vrijednost=="A")cvorp=14;
            }
            Cvor *novi(new Cvor);
            (novi->karta).boja=tmpboja ;
            (novi->karta).vrijednost=par.second;
            novi->sljedeci = nullptr;
            uporedni->sljedeci=novi;
            novi->sljedeci=cvor;
            red.pop();
            uporedni=uporedni->sljedeci;
            while((uporedni->sljedeci)!=poc)uporedni=uporedni->sljedeci;
            cvor=poc;
        }
       
   /* }*/
   
}
void UnistiSpil(Cvor *cvor){
    Cvor *krajnji=cvor;
    while(krajnji->sljedeci!=cvor)krajnji=krajnji->sljedeci;
    krajnji->sljedeci=nullptr;
    while(cvor->sljedeci!=nullptr){
        Cvor *cvor1=cvor;
        cvor=cvor->sljedeci;
        cvor1->sljedeci=cvor1;
        delete cvor1;
    }
    delete cvor;
}