/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <iterator>
#include <stdexcept>
#include <new>
struct Dijete{
    std::string ime;
    Dijete *sljedeci;
}djeca[100];
/*std::vector<std::set<std::string>>*/ void Razvrstavanje(std::vector<std::string>ime1, int tim){
    Dijete *pocetak(nullptr), *prethodni;
    std::vector<std::set<std::string>>skup;
    int niz[100]{0};
    int ostatak, rezultat{0}, broj(ime1.size()), vel{0}, ind{0}, poz{0};
    ostatak=broj%tim;
    rezultat=broj/tim;
    for(int i=0; i<tim; i++){
        if(ostatak>0){
            niz[i]=rezultat+1;
            ostatak--;
        }
        else niz[i]=rezultat;
    }
    skup.resize(tim);
    for(int i=0; i<tim; i++) skup.resize(niz[i]);
    for(int i=0; i<ime1.size(); i++){
        Dijete *novi(new Dijete);
        novi->djeca[i].ime=ime1[i]; novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
 /*   for(Dijete *p=pocetak; p!=nullptr; p=p->sljedeci){
        std::cout <<p->ime<<std::endl;
    }*/
    int broj1{0}, brojac2{0}, i{0};
    for(;;){
        vel=niz[ind];
        for(Dijete *p=pocetak; p!=nullptr; p=p->sljedeci){
         skup[ind].insert(djeca[i].ime);
         i++;
         poz++;
         if(poz>=vel){ind++; poz=0;}
         delete p->sljedeci;
         broj1++;
         p--;
         if(broj1==broj) break;
        }
    }
    for(Dijete *p=pocetak; p!=nullptr; p=p->sljedeci)
     delete []p;
}
int main (){
    try{
        int n, tim;
        std::vector<std::string> ime;
        std::string pom;
        std::vector<std::set<std::string>>skup;
        std::cout<<"Unesite broj djece: ";
        std::cin >>n;
        std::cin.ignore(10000,'\n');
        std::cout<<"Unesite imena djece: "<<std::endl;
        for(int i=0; i<n; i++){
            std::getline(std::cin, pom);
            ime.push_back(pom);
        }
        std::cout<<"Unesite broj timova: ";
        std::cin >>tim;
        if(tim<1 || tim>n) throw std::logic_error("Razvrstavanje nemoguce");
        //skup=Razvrstavanje(ime,tim);
        Razvrstavanje(ime,tim);
        int i{0}, j{0};
        for(std::set<std::string>const &abc : skup){
            std::cout<<"Tim "<<i+1<<": ";
            for(const std::string s : abc){
                if(j<abc.size()-1)
                 std::cout <<s<<", ";
                else std::cout <<s;
                j++;
            }
            j=0;
            i++;
            std::cout <<std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout <<izuzetak.what()<<std::endl;
    }
	return 0;
}