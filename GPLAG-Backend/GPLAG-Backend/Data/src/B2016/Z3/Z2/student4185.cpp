/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <exception>
#include <algorithm>
#include <cctype>

void SveUMala(std::string &pretvori){
    std::transform(pretvori.begin(),pretvori.end(),pretvori.begin(),tolower);
}

bool SlovoBroj(char z){
    if ((z >= 'a'&& z <= 'z') || (z >= '0'&& z <= '9') ) {return true;}
    return false;
}

void IspisiIndeksPojmova(const std::map<std::string, std::set<int>> &mapica){
    for (auto it = mapica.begin(); it != mapica.end(); it++) {
        std::cout << it->first << ": ";
        for(auto iti = it->second.begin(); iti != it->second.end(); iti++){
            if (iti == (--(it->second.end()))) {
                std::cout<< *iti <<std::endl;
            }
            else std::cout << *iti << ",";
        }
    }
}

std::set<int> PretraziIndeksPojmova(std::string stringic, const std::map<std::string, std::set<int>> &mapica){
    std::string original = stringic;
    SveUMala(original);
    auto it(mapica.find(original));
    if (it == mapica.end()) {throw std::logic_error("Pojam nije nadjen");    }
    return it->second;
}

void UbaciUMapu(std::string stringic, int index, std::map<std :: string,std::set<int>> &mapica){
    if(!mapica.count(stringic)) {
        std::set<int> skup;
        skup.insert(index);
        mapica[stringic] = skup;
    }
    else {
        auto iti(mapica.find(stringic));
        (iti->second).insert(index);
    }
}

std::map<std::string , std::set<int>> KreirajIndeksPojmova(std::string stringic){
    std::string sacuvaj = stringic;
    SveUMala(stringic);
    auto it = stringic.begin();
    std::map<std::string, std::set<int>> mapica;
    int pozicija = 0;
    
    while(pozicija<stringic.size()){
        std::string pomocna;
        if (SlovoBroj(*it)) {
            int index = pozicija;
            auto novi = it;
            pomocna.push_back(*novi);
            novi++;
            pozicija++;
            while(pozicija != stringic.size() && SlovoBroj(*novi)){
                pomocna.push_back(*novi);
                novi++;
                pozicija++;
            }
            UbaciUMapu(pomocna, index, mapica);
        it = novi;
        }
        it++;
        pozicija++;
    } 
    return mapica;
}

int main ()
{  
    std::string test;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, test);
    std::map<std :: string,std::set<int>> index;
    index = KreirajIndeksPojmova(test);
    IspisiIndeksPojmova(index);
    
    std::cout<<std::endl;
    for(;;){
        std::string trazise;
        std::string tacka(".");
        std::cout<<"Unesite rijec: ";
        std::getline(std :: cin,trazise);
        if(trazise != tacka){
            try{
        std::set<int> setic(PretraziIndeksPojmova(trazise,index)) ;
        for(auto x : setic) std::cout<< x <<" ";
        std::cout<<std::endl;
            }
            catch(...) {
                
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
            }
        }
        else break;
    }
    
	return 0;
}