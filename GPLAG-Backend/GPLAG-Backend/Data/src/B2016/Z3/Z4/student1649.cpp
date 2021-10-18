/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <list>
#include <stdexcept>
#include <iterator>
int DuzinaImena(const std::string &Ime){
    int Duzina(0);
    for(auto x: Ime) if((toupper(x)>='A' && toupper(x)<='Z') || (x>='0' && x<='9') ) Duzina++;
    return Duzina;
}
std::vector<std::set<std::string>>Razvrstavanje (std::vector<std::string> VektorImena, int BrojTimova){
    int BrojImena(VektorImena.size());
    if(BrojTimova<1 || BrojTimova>BrojImena) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    std::list<std::string> ListaImena;
    for(auto &x:VektorImena) ListaImena.push_back(x);
    std::vector<std::set<std::string>> Timovi(BrojTimova);
    auto It(ListaImena.begin());
    for(int i=0;i<(BrojImena%BrojTimova);i++){
        int BrojClanova(BrojImena/BrojTimova+1),j(0);
        while(j<BrojClanova){
            //std::cout<<"\n NA IMENU SAM:::: "<<*It;
            Timovi[i].insert(*It);
            int Korak(DuzinaImena(*It)-1);
            It=ListaImena.erase(It);
            if(It==ListaImena.end()) It=ListaImena.begin();
            int k(0);
            while(k<Korak){
                if(It==ListaImena.end()){
                    It=ListaImena.begin();
                    continue;
                }
                It++;
                k++;
            }
            if(It==ListaImena.end()) It=ListaImena.begin();
            j++;
        }
    }
    for(int i=(BrojImena%BrojTimova);i<BrojTimova;i++){
        int BrojClanova(BrojImena/BrojTimova),j(0);
        while(j<BrojClanova){
            //std::cout<<"\n NA IMENU SAM:::: "<<*It;
            Timovi[i].insert(*It);
            int Korak(DuzinaImena(*It)-1);
            It=ListaImena.erase(It);
            if(It==ListaImena.end()) It=ListaImena.begin();
            if(ListaImena.size()){
                int k(0);
                while(k<Korak){
                    if(It==ListaImena.end()){
                        It=ListaImena.begin();
                        continue;
                    }
                    It++;
                    k++;
                }
                if(It==ListaImena.end()) It=ListaImena.begin();
            }
            j++;
        }
    }
    return Timovi;
}
int main(){
    std::cout<<"Unesite broj djece: ";
    int BrojDjece;
    std::cin>>BrojDjece;
    std::vector<std::string> ImenaDjece;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<BrojDjece;i++){
        std::string Ime;
        std::getline(std::cin,Ime);
        ImenaDjece.push_back(Ime);
    }
    std::cout<<"\nUnesite broj timova: ";
    int BrojTimova;
    std::cin>>BrojTimova;
    try{
        auto Timovi(Razvrstavanje(ImenaDjece,BrojTimova));
        for(int i=0;i<Timovi.size();i++){
            std::cout<<"Tim "<<i+1<<": ";
            for(auto it=Timovi[i].begin();it!=Timovi[i].end();it++){
                std::cout<<*it;
                if(std::distance(it,Timovi[i].end())!=1) std::cout<<", ";
            }
            std::cout<<std::endl;
        }
    }catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
    return 0;
}