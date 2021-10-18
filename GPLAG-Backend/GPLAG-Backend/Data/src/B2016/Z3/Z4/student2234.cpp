/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <deque>
#include <set>
#include <iterator>
int BrojSlova(std::string s){
    int brojac(0);
    for(int i(0);i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))brojac++;
    }
    return brojac;
}
std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string>s,int br_timova){
    if(s.size()<br_timova || br_timova<1)throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string>igraci;
    for(int i(0);i<s.size();i++){
        igraci.push_back(s[i]);
    }
    int br_igraca=std::distance(igraci.begin(),igraci.end());
    std::vector<std::set<std::string>>raspored(br_timova);
    int br_vecih_timova(br_igraca%br_timova);
    int br_clanova_vecih_timova(br_igraca/br_timova+1);
    int br_clanova_manjih_timova(br_igraca/br_timova);
    std::deque<int>ekipe(br_timova);
    for(int j(0);j<br_vecih_timova;j++)ekipe[j]=br_clanova_vecih_timova;
    for(int j(br_vecih_timova);j<br_timova;j++)ekipe[j]=br_clanova_manjih_timova;
    auto iterator(igraci.begin());
    for(int i(0);i<br_timova;i++){
        int osobe(ekipe[i]);
        while(osobe!=0 && !igraci.empty()){
            std::string s1(*iterator);
            int razmak(BrojSlova(s1));
            raspored[i].insert(s1);
            iterator=igraci.erase(iterator);
            osobe--;
            if(iterator==igraci.end())iterator=igraci.begin();
            for(int i(0);i<razmak-1;i++){
                iterator++;
                if(iterator==igraci.end())iterator=igraci.begin();
            }
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