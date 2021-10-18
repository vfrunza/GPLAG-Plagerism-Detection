/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <set>

bool DioRijeci(std::string &tekst, int i){
    if ((tekst.at(i)>='a' && tekst.at(i)<='z') || (tekst.at(i)>='A' && tekst.at(i)<='Z') || (tekst.at(i)>='0' && tekst.at(i)<='9')) return true;
    return false;
}

bool PreskociPrazno (std::string &tekst, int &i){
    while(DioRijeci(tekst, i)==false) {
            i++;
            if(i>=(int(tekst.length()))) return true;
        }
    return false;
}

void DoIzaKrajaRijeci (std::string &tekst, int &i){
    while(DioRijeci(tekst, i)){
        i++;
        if(i>=int(tekst.length())) break;
    }
}

std::string MalaSlova(std::string pomocni){
    for(int i(0); i<int(pomocni.length()); i++){
        if(pomocni.at(i)>='A' && pomocni.at(i)<='Z') pomocni.at(i)=pomocni.at(i)+'a'-'A';
    }
    return pomocni;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string tekst){
    std::map<std::string, std::set<int>> skup;
    
    for (int i(0); i<int(tekst.length()); i++){
        if(PreskociPrazno(tekst, i)) break;
        
        int pocetak(i);
        DoIzaKrajaRijeci(tekst, i);
        
        std::string pomocni(MalaSlova(tekst.substr(pocetak, i-pocetak)));
        if(!skup.count(pomocni)) skup.insert(std::make_pair(pomocni, std::set<int> {pocetak}));
        else skup[pomocni].insert(pocetak);
        
    }
    return skup;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>>skup){
    if(!skup.count(rijec)) throw std::logic_error ("Unesena rijec nije nadjena!");
    auto it(skup.find(rijec));
    return it->second;
}

void IspisiIndekse(std::set<int> indeks){
    for(auto it=indeks.begin(); it!=indeks.end(); it++){
        auto p=indeks.end(); p--;
        if(it==p) std::cout<<*it;
        else std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>>skup){
    for(auto it=skup.begin(); it!=skup.end(); it++){
        std::cout<<it->first<<": ";
        std::set<int> pomocni(it->second);
        for(auto t=pomocni.begin(); t!=pomocni.end(); t++){
            auto p=pomocni.end(); p--;
            if(t==p) std::cout<<*t;
            else std::cout<<*t<<",";
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    
    std::map<std::string, std::set<int>> skup(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(skup);
    
    for(;;){
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        rijec=MalaSlova(rijec);
        
        try{
            std::set<int> indeks(PretraziIndeksPojmova(rijec, skup));
            IspisiIndekse(indeks);
        }
        catch(std::logic_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }
        
    }
    
	return 0;
}