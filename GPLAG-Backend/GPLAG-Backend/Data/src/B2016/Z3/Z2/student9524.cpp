/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <stdexcept>

std::string PretvoriUMalaSlovaSve(char slovo){
    if(slovo>='A' && slovo<='Z'){
        slovo+=('a'-'A');
        std::string krajnjeslovo;
        krajnjeslovo.push_back(slovo);
        return krajnjeslovo;
        
    }else{
        std::string inace;
        inace.push_back(slovo);
        return inace;
    }
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst){
    std::map<std::string, std::set<int>> Indeks;
    
    std::vector<std::string> rijeci;
    std::vector<std::set<int>> pozicije;
    for(int i=0; i<tekst.size(); i++){
        std::string rijec;
        int pamti_indeks;
        std::set<int> poz;
        bool indikator(false);
        while((tekst[i]>='a'&& tekst[i]<='z') || (tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='0' && tekst[i]<='9')){
            if(!indikator)pamti_indeks=i;
            
            rijec+=PretvoriUMalaSlovaSve(tekst[i]);
            
            i++;
            indikator=true;
            if(i>=tekst.size())break;
        }
        if(indikator){
            bool vec_ima(false);
            for(int j=0; j<rijeci.size(); j++){
                if(rijec==rijeci[j]){
                    vec_ima=true;
                    pozicije[j].insert(pamti_indeks);
                    break;
                }
            }
            if(!vec_ima || rijeci.size()==0){
                rijeci.push_back(rijec);
                poz.insert(pamti_indeks);
                pozicije.push_back(poz);
            }
        }
        //for(int j=0; j<rijeci.size(); j++)
        
    }
    for(int j=0; j<rijeci.size(); j++) Indeks.insert(std::make_pair(rijeci[j], pozicije[j]));
    
    
    /*for(auto it=Indeks.begin(); it!=Indeks.end(); it++){
        std::cout << it->first << ": ";
        for(int x: it->second) std::cout << x << " ";
        std::cout << std::endl;
    }*/
    
    return Indeks;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> indeks){
    
    auto it(indeks.find(rijec));
    if(it==indeks.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
    
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> indeks){
    for(auto it=indeks.begin(); it!=indeks.end(); it++){
        std::cout << it->first << ": ";
        for(int x : it->second){
            if(it->second.find(x)==--(it->second.end())) std::cout << x;
            else std::cout << x << ",";
        }
        std::cout << std::endl;
    }
}

int main (){
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    
    auto indeks(KreirajIndeksPojmova(tekst));
    for(auto it=indeks.begin(); it!=indeks.end(); it++){
        std::cout << it->first << ": ";
        for(int x : it->second){
            if(it->second.find(x)==--(it->second.end())) std::cout << x;
            else std::cout << x << ",";
        }
        std::cout << std::endl;
    }
    
    std::string rijec;
    for(;;){
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".")break;
        
        auto it(indeks.find(rijec));
        if(it==indeks.end()) std::cout << "Unesena rijec nije nadjena!";
        else{
            for(int x : it->second){
                std::cout << x << " ";
            }
        }
        std::cout << std::endl;
    }
    
	return 0;
}