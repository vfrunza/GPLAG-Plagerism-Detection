/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
char UMalo(char x){
    if(x>='A' && x<='Z') return x+('a'-'A');
    return x;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string Tekst){
    std::map<std::string,std::set<int>> Indeks;
    int i(0);
    while(i<Tekst.length()){
        if((UMalo(Tekst[i])>='a' && UMalo(Tekst[i])<='z') || (Tekst[i]>='0' && Tekst[i]<='9')){
            int j(i);
            while(j<Tekst.length()) if((UMalo(Tekst[j])>='a' && UMalo(Tekst[j])<='z') || (Tekst[j]>='0' && Tekst[j]<='9')) j++; else break;
            std::string Rijec(Tekst.substr(i,j-i));
            for(auto &x:Rijec) x=UMalo(x);
            //std::cout<<"\nxxNASAO SAM RIJEC:"<<Rijec;
            Indeks[Rijec];
            auto it(Indeks.find(Rijec));
            it->second.insert(i);
            i=j;
        }else i++;
    }
    return Indeks;
}
std::set<int> PretraziIndeksPojmova(std::string Rijec, std::map<std::string,std::set<int>> Indeks){
    for(auto &x: Rijec) x=UMalo(x);
    auto it(Indeks.find(Rijec));
    if(it==Indeks.end()) throw std::logic_error("Pojam nije nadjen\n");
    return it->second;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> Indeks){
    for(auto x:Indeks){
        std::cout<<x.first<<": ";
        int i(0),j(x.second.size());
        auto it(x.second.begin());
        while(i<j){
            std::cout<<*it++;
            if(i!=j-1) std::cout<<",";
            i++;
        }
        std::cout<<"\n";
    }
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string Tekst;
    std::getline(std::cin, Tekst);
    auto Indeks(KreirajIndeksPojmova(Tekst));
    IspisiIndeksPojmova(Indeks);
    for(;;){
        std::string Unos;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, Unos);
        if(Unos==".") break;
        try{
            auto Pozicije(PretraziIndeksPojmova(Unos, Indeks));
            for(auto x: Pozicije) std::cout<<x<<" ";
            std::cout<<"\n";
        }catch(std::logic_error izuzetak){
            std::cout<<"Unesena rijec nije nadjena!\n";
        }
    }
	return 0;
}