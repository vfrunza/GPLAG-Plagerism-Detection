/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>

typedef std::map<std::string, std::vector<std::string>> Knjiga;


std::map<std::string, std::tuple<std::string, int, int>> KreirajIndeksPojmova(Knjiga tekst)
{

}

PretraziIndeksPojmova(std::string rijec, std::map a) {
    a = KreirajIndeksPojmova(rijec);
    
}
IspisiIndeksPojmova(std::map m, ) {
    
    
    
    std::cout<<   <<"/" <<"/"<<std::endl;
}

int main ()
{
    std::string poglavlje;

    std::cout<<"Unesite naziv poglavlja: ";
    std::cin>>poglavlje;

    // std::cin.getline(poglavlje, sizeof(poglavlje));


    for(int i=0; i < (sizeof(poglavlje)); i++) {
    std::string sadrzaj;
    std::vector<std::string>>v;

    std::cout<<"Unesite sadrzaj stranice "<<i+1<<": ";
    for(int j=0; ; j++) {
            std::getline(std::cin, v[i]);
            if(v.size() ==1 && v.at(0) == ".") {
                v.resize(0);
                break;
            }
        }
        

    }
    
    indeks = KreirajIndeksPojmova(sadrzaj);
    
    std::cout<<"Kreirani indeks pojmova: ";
    
    for(int i=0; i<indeks.size(); i++) {
        
    }
             
    return 0;
}
