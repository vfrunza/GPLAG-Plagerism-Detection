/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>

typedef std::map<std::string, std::vector<std:: string>> Knjiga;

std::map<std::string, std::tuple<std::string,int, int> > KreirajIndeksPojmova(Knjiga k){
    std::map<std::string, std::tuple<std::string, int, int> > povratni;
    for(int)
}

std::tuple<std::string, int, int > >PretraziIndeksPojmova(std::string s, std::map<std::string,std::tuple<std::string, int, int> > indeks){
    std::tuple<std::string, int, int > > pov;
    if(indeks.find(s)==indeks.end()) throw std::logic_error("Pojam nije nadjen");
    else {
        pov=std::make_tuple(indeks->second);
    }
    return pov;
}

void IspisiIndeksPojmova(const std::map<std::string, std::tuple<std::string, int, int> > indeks){
    for(auto it(indeks.begin());it!=indeks.end();it++){
        std::cout<<it->first<<": ";
        auto it1(it->second);
        
        
    }
}
int main (){
    std::cout<<"Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin,tekst);
    std::map<std::string, std::set<int>> m(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(m);
    std::string t;
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,t);
        if(temp=='.') break;
        try{
            std::set<int> temp(PretraziIndeksPojmova(t,m));
            int br(0);
            for(auto x: temp){
                br++;
                if(br==temp.size()) std::cout<<x<<std::endl;
                else std::cout<<x<<",";
            }
        }
        catch(...){
            std::cout<<"Unesena rijec nije nadjena"<<std::endl;
        }
        
    }
	return 0;
}
