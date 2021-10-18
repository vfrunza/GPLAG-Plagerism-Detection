#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stdexcept>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&& s[i]<='Z'){
            s[i]+='a'-'A';
        }
    }
    std::map<std::string,std::set<int>> mapa;
    int i(0);
    while(i<s.length()){
        while((s[i]<'A' && s[i]>'9') || (s[i]<'a' && s[i]>'Z' ) || (s[i]<'0' || s[i]>'z' )){
            i++;
            if(i==s.length()) break;
        }
        int brojac_slova(0),pocetak(i);
        while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            i++;
            brojac_slova++;
            if(i==s.length()) break;
        }
        std::string temp;
        temp=s.substr(pocetak,brojac_slova);
        if(temp!=""){
        mapa[temp].insert(pocetak);
        }
        i++;
    }
    return mapa;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> moja_mapa){
    auto it(moja_mapa.begin());
    while(it!=moja_mapa.end()){
        std::cout<<(it->first)<<": ";
        auto iter(it->second.begin());
        int brojac(0);
        while(iter!=(it->second.end())){
            if(brojac==(it->second).size()-1){
                std::cout<<*iter;
                break;
            }
            std::cout<<*iter<<",";
            iter++;
            brojac++;
        }
        std::cout<<std::endl;
        it++;
    }
    
}
std::set<int> PretraziIndeksPojmova(std::string pojam,std::map<std::string,std::set<int>> moja_mapa){
    auto it(moja_mapa.begin());
    while(it!=moja_mapa.end()){
        if(it->first==pojam){
            return it->second;
        }
        it++;
    }
    throw std::logic_error("Unesena rijec nije nadjena!");
}

int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>> moja_mapa;
    moja_mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(moja_mapa);
    std::string str;
    do{
    std::cout<<"Unesite rijec: ";
    getline(std::cin,str);
    std::set<int> skupic;
    if(str==".")break;
    try{
    skupic=PretraziIndeksPojmova(str,moja_mapa);
    }catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
        std::cout<<"Unesite rijec: ";
        return 0;
    }
    auto iterator(skupic.begin());
    while (iterator!=skupic.end()) {
        std::cout<<*iterator++<<" ";
        
    }
    std::cout<<std::endl;
    }while(str!=".");
	return 0;
}