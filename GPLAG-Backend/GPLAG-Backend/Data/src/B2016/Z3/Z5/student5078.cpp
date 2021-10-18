/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
struct Dijete{
    std::string ime;
    Dijete *sljedeci=nullptr;
};
bool BrojSlovo(char znak){
    if((toupper(znak)<='Z' && toupper(znak)>='A') || (znak>='0' && znak<='9'))return true;
    return false;
}
int Duzina(std::string Ime){
    int broj(0);
    for(int i=0;i<Ime.size();i++)
        if(BrojSlovo(Ime[i]))broj++;
    return broj;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Spisak,int BrojT){
    if(BrojT<1 || BrojT>Spisak.size())throw std::logic_error("Razvrstavanje nemoguce");
    Dijete *pocetak(nullptr),*iza_p(nullptr);
    for(int i=0;i<Spisak.size();i++){
       Dijete *novi=new Dijete;
       novi->ime=Spisak[i];
       novi->sljedeci=nullptr;
       if(!pocetak)pocetak=novi;
       else iza_p->sljedeci=novi;
       iza_p=novi;
    }
    iza_p->sljedeci=pocetak;
    std::vector<std::set<std::string>> Vrati;
    Vrati.resize(BrojT);
    std::vector<int> Limit(BrojT,Spisak.size()/BrojT);
    for(int i=0;i<Spisak.size()%BrojT;i++){
        Limit[i]++;
    }
    auto it=pocetak;
    auto prijeit=iza_p;
    int j(1);
    int brojac(0);
    for(int i(0);i<Spisak.size();i++){
        int duz=Duzina(it->ime);
        Vrati[brojac].insert(it->ime);
        auto sac_sljed=it->sljedeci;
        delete it;
        if(i+1<Spisak.size()){
        prijeit->sljedeci=sac_sljed;
        it=sac_sljed;
        for(int k(1);k<duz;k++){
            prijeit=it;
            it=it->sljedeci;
        }}
        if(j==Limit[brojac]){
            brojac++;
            j=0;
        }
        j++;
    }
    return Vrati;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int br_djece;
    std::cin>>br_djece;
    std::cin.ignore(10000,'\n');
    std::vector<std::string> jedan;
    jedan.resize(br_djece);
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<br_djece;i++){
        std::string ime;
        getline(std::cin,ime,'\n');
        jedan[i]=ime;
    }
    int br_timova;
    std::cout<<std::endl<<"Unesite broj timova: ";
    std::cin>>br_timova;
    try{
    auto p=Razvrstavanje(jedan,br_timova);
    for(int i=0;i<p.size();i++){
           std::cout<<"Tim "<<i+1<<": ";
        for(auto it(p[i].begin());it!=p[i].end();it++){
            std::cout<<*it;
            auto it2=it;
            if(++it2!=p[i].end())std::cout<<", ";
        }std::cout<<std::endl;
    }
    }
    catch(std::logic_error x){
    std::cout<<"Izuzetak: "<<x.what();
    return 0;
    }
	return 0;
}
