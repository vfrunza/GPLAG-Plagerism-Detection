/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> spisak_djece, int br_timova){
    int br_djece(spisak_djece.size());
    if(br_timova<1 || br_timova>br_djece) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    Dijete *pocetak(nullptr),*prethodni,*brisi;
    std::vector<std::set<std::string>> timovi;
    for(int i=0;i<spisak_djece.size();i++){
        Dijete *novi(new Dijete);
        novi->ime=spisak_djece[i]; novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    prethodni->sljedeci=pocetak;
    std::set<std::string> s;
    s.insert(pocetak->ime);
    std::string pomocni;
    int br_djece_po_timu,ostatak,pomjeranje=0;
    int ponavljanje=br_djece;
    br_djece_po_timu=br_djece/br_timova;
    ostatak=br_djece%br_timova;
    while(br_timova!=0){
        while(ostatak!=0){
            for(int i=0;i<br_djece_po_timu+1;i++){
                s.insert(pocetak->ime);
                brisi=pocetak;
                pomocni=pocetak->ime;
                for(int j=0;j<pomocni.length();j++) if((pomocni[j]>='0' && pomocni[j]<='9')||(pomocni[j]>='a' && pomocni[j]<='z')||(pomocni[j]>='A' && pomocni[j]<='Z')) pomjeranje++;
                pomjeranje-=1;
                prethodni->sljedeci=pocetak->sljedeci;
                pocetak=pocetak->sljedeci;
                delete brisi;
                ponavljanje--;
                if(ponavljanje!=0){
                for(int k=0;k<pomjeranje;k++){
                    prethodni=pocetak;
                    pocetak=pocetak->sljedeci;
                }}
                pomjeranje=0;
            }
            timovi.push_back(s);
            s.clear();
            ostatak--;
            br_timova--;
        }
        for(int i=0;i<br_djece_po_timu;i++){
            s.insert(pocetak->ime);
            brisi=pocetak;
            pomocni=pocetak->ime;
            for(int j=0;j<pomocni.length();j++) if((pomocni[j]>='0' && pomocni[j]<='9')||(pomocni[j]>='a' && pomocni[j]<='z')||(pomocni[j]>='A' && pomocni[j]<='Z')) pomjeranje++;
            pomjeranje-=1;
            prethodni->sljedeci=pocetak->sljedeci;
            pocetak=pocetak->sljedeci;
            delete brisi;
            ponavljanje--;
            if(ponavljanje!=0){
            for(int k=0;k<pomjeranje;k++){
                prethodni=pocetak;
                pocetak=pocetak->sljedeci;
            }}
            pomjeranje=0;
        }
        timovi.push_back(s);
        s.clear();
        br_timova--;
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
    std::cout<<"Unesite imena djece: \n";
    std::cin.clear();
    std::cin.ignore(10000,'\n');
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
        }
    } catch(...){
        std::cout<<"Izuzetak: Razvrstavanje nemoguce";
    }
	return 0;
}