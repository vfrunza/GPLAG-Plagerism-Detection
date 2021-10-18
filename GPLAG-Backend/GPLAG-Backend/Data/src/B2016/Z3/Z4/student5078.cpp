/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

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
    std::list<std::string> Lista;
    auto It=Lista.begin();
    for(int i=0;i<Spisak.size();i++){
        Lista.insert(It,Spisak[i]);
    }
    std::vector<std::set<std::string>> Vrati;
    Vrati.resize(BrojT);
    std::vector<int> Limit(BrojT,Spisak.size()/BrojT);
    for(int i=0;i<Spisak.size()%BrojT;i++){
        Limit[i]++;
    }
    It=Lista.begin();
    int j(0);
    int brojac(0);
    while(Lista.size()!=0){
        Vrati[brojac].insert(*It);
        int limit=Duzina(*It);
        It=Lista.erase(It);
        if(It==Lista.end())It=Lista.begin();
        for(int k=1;k<limit;k++){
            It++;
            if(It==Lista.end())It=Lista.begin();
        }
        j++;
        if(j==Limit[brojac]){j=0;brojac++;}
            if(Lista.size()==1){
            Vrati[brojac].insert(*It);
            Lista.erase(It);
            break;
        }
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
