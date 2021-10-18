/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <stdexcept>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> spisak_djece,int br_timova){
    std::list<std::string> lista;
    std::set<std::string> set;
    std::string pomocni,poz_poc,poz_kraj;
    std::vector<std::set<std::string>> timovi;
    int br_djece=0,br_djece_po_timu,ostatak,pomjeranje=0;
    for(auto x:spisak_djece){ lista.push_back(x); br_djece++;}
    if(br_timova <1 || br_timova>br_djece) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    br_djece_po_timu=br_djece/br_timova;
    ostatak=br_djece%br_timova;
    std::list<std::string>::iterator pocetak(lista.begin());
    std::list<std::string>::iterator kraj(lista.end()); kraj--;
    poz_poc=*pocetak;
    while(lista.size()!=0){
        while(ostatak!=0){
            for(int i=0;i<br_djece_po_timu+1;i++){
                set.insert(*pocetak);
                pomocni=(*pocetak);
                poz_poc=*pocetak;
                for(int j=0;j<pomocni.length();j++){
                    if((pomocni[j]>='0' && pomocni[j]<='9')||(pomocni[j]>='a' && pomocni[j]<='z')||(pomocni[j]>='A' && pomocni[j]<='Z')) pomjeranje++;
                }
                pomjeranje-=1;
                if(pocetak!=kraj) pocetak=lista.erase(pocetak);
                else {
                    lista.erase(pocetak);
                    pocetak=lista.begin();
                }
                kraj=lista.end();kraj--;
                pomocni.resize(0);
                poz_poc=*pocetak;
                if(lista.size()!=1)for(int j=0;j<pomjeranje;j++){
                    if(pocetak!=kraj)pocetak++;
                    else pocetak=lista.begin();
                }
                pomjeranje=0;
            }
            timovi.push_back(set);
            set.clear();
            ostatak--;
            poz_poc=*pocetak;
        }
        for(int i=0;i<br_djece_po_timu;i++){
            set.insert(*pocetak);
            pomocni=(*pocetak);
            for(int j=0;j<pomocni.length();j++){
            if((pomocni[j]>='0' && pomocni[j]<='9')||(pomocni[j]>='a' && pomocni[j]<='z')||(pomocni[j]>='A' && pomocni[j]<='Z')) pomjeranje++;
            }
            pomjeranje-=1;
            if(pocetak!=kraj) pocetak=lista.erase(pocetak);
            else {
                lista.erase(pocetak);
                if(lista.size()==0) goto L1;
                pocetak=lista.begin();
            }
            kraj=lista.end(); kraj--;
            pomocni.resize(0);
            if(lista.size()!=1)for(int j=0;j<pomjeranje;j++) {
                if(pocetak!=kraj)pocetak++;
                else pocetak=lista.begin();
                poz_poc=*pocetak;
            }
            pomjeranje=0;
        }
        L1:
        timovi.push_back(set);
        set.clear();
    }
    return timovi;
}
int main ()
{
    int br_djece,br_timova;
    std::string pomocni;
    std::vector<std::string> spisak_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>br_djece;
    std::cout<<"Unesite imena djece:\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    for(int i=0;i<br_djece;i++){
        std::getline(std::cin,pomocni);
        spisak_djece.push_back(pomocni);
        pomocni.resize(0);
    }
    std::cout<<"Unesite broj timova: ";
    std::cin>>br_timova;
    try{
    std::vector<std::set<std::string>> timovi=Razvrstavanje(spisak_djece,br_timova);
    for(int k=0;k<timovi.size();k++){
        std::cout<<"Tim "<<k+1<<": ";
        std::set<std::string>::iterator it(timovi[k].begin());
        std::set<std::string>::iterator it2(timovi[k].end()); it2--;
        for(it=timovi[k].begin();it!=timovi[k].end();it++){
            if(it!=it2) std::cout<<*it<<", ";
            else std::cout<<*it;
        }
        std::cout<<std::endl;
    } } catch(...){
        std::cout<<"Izuzetak: Razvrstavanje nemoguce";
    }
	return 0;
}