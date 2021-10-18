/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
int main ()
{
	return 0;
}#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
#include <cmath>
struct Dijete{
    std::string ime;
    Dijete *sljedeci;
};
bool simbol(char s){
    if((s>='a' && s<='z')||(s>='A' && s<='Z')||(s>='0' && s<='9')) return true; return false;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> iblisovi_podanici, int broj_ekipa);

int main (){
    try{
std::vector<std::string> iblisovi_podanici;
std::cout<<"Unesite broj djece: "; int brojiblisovih_podanika; std::cin>> brojiblisovih_podanika;
std::string dijet; std::cout<<"Unesite imena djece:"<<std::endl;
std::cin.ignore(1000,'\n');
for(unsigned i=0;i<brojiblisovih_podanika;i++){
    std::getline(std::cin,dijet);
    iblisovi_podanici.push_back(dijet);
}
std::cout<<"Unesite broj timova: "; int brojtimovaiblisovih_podanika; std::cin>>brojtimovaiblisovih_podanika;
std::vector<std::set<std::string>> razvrstanipodanici;
razvrstanipodanici = Razvrstavanje(iblisovi_podanici,brojtimovaiblisovih_podanika);
for(unsigned i=0; i<razvrstanipodanici.size();i++){
    std::cout<<"Tim "<<i+1<<": ";
    int brojac=0;
    for(auto it=razvrstanipodanici[i].begin(); it!=razvrstanipodanici[i].end();it++){
        if(brojac != razvrstanipodanici[i].size()-1){std::cout<<*it<<", ";brojac++;}
        else std::cout<<*it;}
        std::cout<<std::endl;
}
}catch(std::logic_error &ghreshka){std::cout<<ghreshka.what();}
return 0;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> iblisovi_podanici, int broj_ekipa){
if(broj_ekipa<1 || broj_ekipa>iblisovi_podanici.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> iblisovi_namjesnici;
    for(unsigned i=0;i<iblisovi_podanici.size();i++) iblisovi_namjesnici.push_back(iblisovi_podanici[i]);
    std::vector<std::set<std::string>> ekipe;
    ekipe.resize(broj_ekipa);
    int broj_ekipa_plus1 = iblisovi_namjesnici.size() % broj_ekipa;
    int broj_clanova_ekipeplus1 = std::floor(iblisovi_namjesnici.size()/broj_ekipa) + 1 ;

    int broj_clanova_ekpenormalnih = std::floor(iblisovi_namjesnici.size()/broj_ekipa);
auto it = iblisovi_namjesnici.begin();
unsigned brojacigraca;
unsigned i=0; a: if(i<broj_ekipa_plus1) brojacigraca = broj_clanova_ekipeplus1;
else if(i>=broj_ekipa_plus1) brojacigraca =broj_clanova_ekpenormalnih;
b:  while(iblisovi_namjesnici.size()){
        ekipe[i].insert(*it);
        brojacigraca--;
        int brojac = (*it).length();
        for(unsigned i=0;i<(*it).length();i++) if(!simbol((*it)[i])) brojac--;
        iblisovi_namjesnici.erase(it++);
    for(;brojac-1>=0;it++){
        if(!iblisovi_namjesnici.size()) goto b;
        if(it == iblisovi_namjesnici.end()) it = iblisovi_namjesnici.begin();
        brojac--;
    }it--;
    if(!brojacigraca){i++; goto a;}
}
return ekipe;
}