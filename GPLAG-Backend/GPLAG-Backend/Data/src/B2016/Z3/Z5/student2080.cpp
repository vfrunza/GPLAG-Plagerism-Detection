/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <deque>
#include <set>
#include <iterator>
struct Dijete{
    std::string ime;
    Dijete* sljedeci;
};
int BrojSlova(std::string s){
    int brojac(0);
    for(int i(0);i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))brojac++;
    }
    return brojac;
}
std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string>s,int br_timova){
    if(s.size()<br_timova || br_timova<1)throw std::logic_error("Razvrstavanje nemoguce");
    Dijete*pocetak(nullptr),*prethodni;
    for(int i(0);i<s.size();i++){
        Dijete*novi=(new Dijete);
        novi->ime=s[i];
        novi->sljedeci=nullptr;
        if(!pocetak)pocetak=novi;
        if(i==s.size()-1)prethodni->sljedeci=pocetak;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    int br_igraca(s.size());
    std::vector<std::set<std::string>>raspored(br_timova);
    int br_vecih_timova(br_igraca%br_timova);
    int br_clanova_vecih_timova(br_igraca/br_timova+1);
    int br_clanova_manjih_timova(br_igraca/br_timova);
    std::deque<int>ekipe(br_timova);
    for(int j(0);j<br_vecih_timova;j++)ekipe[j]=br_clanova_vecih_timova;
    for(int j(br_vecih_timova);j<br_timova;j++)ekipe[j]=br_clanova_manjih_timova;
    Dijete*pok=pocetak;
    Dijete*bris=pocetak;
    for(int i(0);i<br_timova;i++){
        int osobe(ekipe[i]);
        while(osobe!=0 && br_igraca!=0){
            int razmak(BrojSlova(pok->ime));
            raspored[i].insert(pok->ime);
            for(int k(0);k<br_igraca-1;k++){
                bris=bris->sljedeci;
            }
            bris=bris->sljedeci->sljedeci;
            delete pok;
            for(int j(0);j<razmak;j++){
               pok=pok->sljedeci;
            }
            if(pok==pok->sljedeci){
                delete pok;
                pok=nullptr;
            }
            osobe--;
            br_igraca--;
            
        }
    }
    return raspored;
}
int main ()
{   std::cout<<"Unesite broj djece: ";
    int br;
    std::cin>>br;
    std::cin.ignore(100,'\n');
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string>spisak(br);
    for(int i(0);i<spisak.size();i++){
        std::getline(std::cin,spisak[i]);
    }
    std::cout<<std::endl<<"Unesite broj timova: ";
    int timovi;
    std::cin>>timovi;
    std::vector<std::set<std::string>>rezultat;
    try{
        rezultat=Razvrstavanje(spisak,timovi);
    for(int i(0);i<timovi;i++){
        std::cout<<"Tim "<<i+1<<": ";
        auto iter(rezultat[i].begin());
        auto slon(rezultat[i].end());
        slon--;
        for(;iter!=slon;iter++){
            std::cout<<*iter<<", ";
        }
        std::cout<<*iter<<std::endl;
    }
    }
    catch(std::logic_error greska){
        std::cout<<"Izuzetak: "<<greska.what();
    }
	return 0;
}