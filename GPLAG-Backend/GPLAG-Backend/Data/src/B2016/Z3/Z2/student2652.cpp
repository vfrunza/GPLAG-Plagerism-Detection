/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
bool opseg (std::string tekst){
    if (tekst[0]>=48 && tekst[0]<=57) return true;
    if (tekst[0]>=65 && tekst[0]<=90) return true;
    if (tekst[0]>=97 && tekst[0]<=122) return true;
    return false;
}
std::map <std::string, std::set<int>> KreirajIndeksPojmova (std::string tekst){
    std::map <std::string, std::set<int> > mapa;
    for (int i=0; i<tekst.size(); i++){
        while (opseg(tekst.substr(i,1))==false) i++;
        std::string pomocni;
        while (opseg(tekst.substr(i,1))==true && i<tekst.size() ){
        pomocni += tekst.substr(i, 1); i++;}
        //std::cout<<pomocni<<std::endl;
        auto it(mapa.find(pomocni));
        if(it == mapa.end()) {
            std::set<int> skup;
            skup.insert(i-pomocni.size());
           
            mapa.insert(std::make_pair(pomocni, skup));
        }
        else{it->second.insert(i-pomocni.size());
            mapa.insert(std::make_pair(pomocni, it->second));
        }
    }
    
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map <std::string, std::set<int> > mapa ) {
    auto it(mapa.find(rijec));
    if(it == mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!\n");
    else return it->second;
}
void IspisiIndeksPojmova (std::map <std::string, std::set<int> > mapa){
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
    std::cout << it->first << ": ";
    bool prvi = true;
    for(auto iter=it->second.begin(); iter!=it->second.end(); iter++){
    if (!prvi) std::cout<<",";
    std::cout<<(*iter); 
     prvi = false;
    }
    std::cout<<std::endl;
}
}
int main ()
{
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, tekst);
    IspisiIndeksPojmova(KreirajIndeksPojmova(tekst));
    for ( ; ; ){
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::cin>>rijec;
        if (rijec == ".") break;
       try { for (int x: PretraziIndeksPojmova(rijec, KreirajIndeksPojmova(tekst)  )) {std::cout<<x<<" ";} std::cout<<std::endl;}
       catch (std::logic_error e) {std::cout<<e.what();}
    } 
	return 0;
}