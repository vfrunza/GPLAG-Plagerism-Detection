#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stdexcept>
int Duzina(std::string s){
    return s.size();
}
bool Odgovara(std::string ime,std::vector<std::string>Imena){
    int indeks(0);
    for(int i(0);i<Imena.size();i++){
    std::string prvi(Imena[indeks]);
    return false;
    indeks+=Duzina(prvi);
    }
    
}

std::vector<std::set<std::string>> RasporedTimova(std::vector<std::string>Imena,int BrojTimova){
    int BrojDjece(Imena.size());
    std::vector<std::set<std::string>>Timovi(BrojTimova);
    for(int i(1);i<=BrojTimova;i++){
    }
    return Timovi;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string>Imena,int BrojTimova){
    std::vector<std::set<std::string>>Razvrstani;
    std::list<std::string>KopiranaImena;
    if(BrojTimova<1 || BrojTimova>Imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::copy(Imena.begin(),Imena.end(),KopiranaImena.begin());
    for(auto it=KopiranaImena.begin();it!=KopiranaImena.end();it++){
           if(Odgovara(*it,Imena))        it=KopiranaImena.erase(it);
        }
        return Razvrstani;
    }

int main ()
{
    try{
        std::cout<<"Unesite broj djece: ";
        int brdjc(0);
        std::cin>>brdjc;
        std::vector<std::string>Djeca(brdjc);
        std::cout<<"Unesite imena djece: ";
        for(int i(0);i<brdjc;i++){
            std::cin>>Djeca[i];
        }
        std::cout<<"Unesite broj timova: ";
        int BrojTimova(0);
        std::cin>>BrojTimova;
        std::vector<std::set<std::string>>Timovi=Razvrstavanje(Djeca,BrojTimova);
        for(int i(0);i<Timovi.size();i++){
            std::cout<<"Tim "<<i<<":"<<" "<<std::endl;
        }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}