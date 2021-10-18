/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <utility>
#include <stdexcept>

bool slovo(char c){ return ((c>='a' && c<='z') || (c>='A' && c<='Z'));}
bool broj(char c){ return (c>='0' && c<='9');}
void Pretvori(std::string &rijec){
    for(int i=0;i<rijec.size();i++)
        if(rijec[i]>='A' && rijec[i]<='Z')
            rijec[i]-='A'-'a';
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string recenica){
    std::map<std::string, std::set<int>> indeks_pojmova;
    for(int i=0;i<recenica.size();i++){
        std::string rijec;
        
        while(i<recenica.size() && (slovo(recenica[i]) || broj(recenica[i]))){
            rijec.push_back(recenica[i]);
            i++;
        }
        if(rijec.size()!=0){
            Pretvori(rijec);
            indeks_pojmova[rijec].insert(i-rijec.size());
            --i;
        }
    }
    return indeks_pojmova;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> indeks_pojmova){
    Pretvori(rijec);
    if(indeks_pojmova.find(rijec)!= indeks_pojmova.end())
        return indeks_pojmova[rijec];
    else
        throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> indeks_pojmova){
    for(auto it = indeks_pojmova.begin(); it!=indeks_pojmova.end();it++){
        std::cout<<it->first<<": ";
        for(auto i=it->second.begin(); i!=--(it->second.end());i++)
            std::cout<<*i<<",";
        std::cout<<*--(it->second.end())<<std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string recenica;
    std::getline(std::cin,recenica);
    
    std::map<std::string, std::set<int>> indeks_pojmova = KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(indeks_pojmova);
    while(1){
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::cin>>rijec;
        if(rijec==".")
            break;
        try{
            for(auto i : PretraziIndeksPojmova(rijec,indeks_pojmova))
                std::cout<<i<<" ";
            std::cout<<std::endl;
        } catch(std::logic_error) {std::cout<<"Unesena rijec nije nadjena!\n";}
    }
	return 0;
}