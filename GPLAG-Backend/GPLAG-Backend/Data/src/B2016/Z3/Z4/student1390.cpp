/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <iterator>
#include <stdexcept>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int br_timova){
    if(br_timova<1 || br_timova>v.size())throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> vektor;
    std::vector<int> slova;
    std::vector<int> broj_timova_konacni;
    if((v.size()%br_timova)==0){for(int i=0;i<br_timova;i++)broj_timova_konacni.push_back(v.size()/br_timova);}
    else {
        int broj_tim=v.size()%br_timova;
        int razlika=v.size()/br_timova;
    for(int i=0;i<br_timova;i++){
        if(broj_tim>i)broj_timova_konacni.push_back(razlika+1);
        else broj_timova_konacni.push_back(razlika);
    }
    }
    for(int i=0;i<v.size();i++){
        int broj(0);
        for(int j=0;j<v[i].length();j++){
            if((v[i][j]>='a' && v[i][j]<='z') || (v[i][j]>='A' && v[i][j]<='Z') || (v[i][j]>='0' && v[i][j]<='9'))broj++;
        }
        slova.push_back(broj);
    }
    std::list<std::string> lista;
    for(int i=0;i<v.size();i++)lista.push_back(v[i]);
    std::list<std::string>::iterator it(lista.begin());
    int brojac(0),pomocna(0),prvi(0),pamti,clanovi(0);
    for(int i=0;i<broj_timova_konacni.size();i++){
        std::set<std::string> skup;
      while(it!=lista.end()){
            if(prvi==0){ 
                skup.insert(*it);
                clanovi++;
                it=lista.erase(it);
                pamti=slova[i];
                slova.erase(slova.begin()+i);
                prvi=1;
                if(clanovi==broj_timova_konacni[i])break;
                pomocna--;
            }
                
                brojac++;
                pomocna++;
                if(pomocna==slova.size())pomocna=0;

            if(pamti==brojac){
                skup.insert(*it);
                clanovi++;
                pamti=slova[pomocna];
                slova.erase(slova.begin()+pomocna);
                it=lista.erase(it);
                brojac=1;
                if(pomocna==slova.size())pomocna=0;
                if(it==lista.end())it=lista.begin();
                if(clanovi==broj_timova_konacni[i])break;
            }
            it++;
            if(it==lista.end()){
                it=lista.begin();
              }
      }
        clanovi=0;
        brojac=0;
        vektor.push_back(skup);
        pomocna--;
        skup.clear();
    }
    return vektor;
}

int main ()
{
    std::cout << "Unesite broj djece: " ;
    int n;
    std::cin >> n;
    std::cin.ignore(10000,'\n');
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> v;
    std::string a;
    for(int i=0;i<n;i++){
        std::getline(std::cin,a);
        v.push_back(a);
    }
    std::cout << "Unesite broj timova: ";
    int timovi;
    std::cin >> timovi;
    std::vector<std::set<std::string>> vek;
    try{
    vek=Razvrstavanje(v,timovi);
    for(int i=0;i<vek.size();i++){
        std::cout << "Tim "<<i+1<<": " ;
        auto it1(vek[i].begin());
        auto it2(vek[i].end());
        it2--;
        while(it1!=it2)std::cout << *it1++ <<", ";
        std::cout << *it1<<std::endl;
    }
    }catch(std::logic_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}