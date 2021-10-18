 /B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <memory>
#include <algorithm>
std::string PretvoriUMala(std::string rijec){
    for(int i=0;i<rijec.length();i++){
        if(rijec[i]>='A' && rijec[i]<='Z') {rijec[i]+=32;}
    }
    return rijec;
}
int Brojrijeci(std::string recenica){
    int brojac{};
    for(int i=0;i<recenica.length();i++){
        while (!((recenica[i]>='0' && recenica[i]<='9') || (recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))) i++;
        while(((recenica[i]>='0' && recenica[i]<='9') || (recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z'))) i++;
         brojac++;
    }
    return brojac;
}
std::vector<std::string> DajVektorRijeci(std::string recenica){
    std::vector<std::string> rezultat;
    for(int i=0;i<recenica.length();i++){
        if(recenica[i]>='A' && recenica[i]<='Z') {recenica[i]+=32;}
    }
    for(int i=0;i<recenica.length();i++){
        std::string pomocna;
        while(!((recenica[i]>='0' && recenica[i]<='9') || (recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && i!=recenica.length()) {i++;}
        int j=i, duzina{};
        while(((recenica[j]>='0' && recenica[j]<='9') || (recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' && recenica[j]<='z')) && j!=recenica.length())  {j++; duzina++;}
        pomocna=recenica.substr(i,duzina);
        i=j-1;
        rezultat.push_back(pomocna);
    }
    return rezultat;
}
void DodajRijec(std::vector<std::string> &vs, std::string s){
    bool ima=false;
      for (int j=0; j<vs.size(); j++) if (s==vs[j]) ima=true;
       if (ima==false)vs.push_back(s); 
}
std::string Rijec(std::string recenica, int &broj){
    std::string rezultat;
    for(int i=broj;i<recenica.length();i++){
        std::string pomocna;
        while(!((recenica[i]>='0' && recenica[i]<='9') || (recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && i!=recenica.length()) {i++;}
        int j=i, duzina{};
        while(((recenica[j]>='0' && recenica[j]<='9') || (recenica[j]>='A' && recenica[j]<='Z') || (recenica[j]>='a' && recenica[j]<='z')) && j!=recenica.length())  {j++; duzina++;}
        pomocna=recenica.substr(i,duzina);
        //i=j-1;
        broj=j;
        rezultat=pomocna;
        break;
    }
    return rezultat;
}
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string recenica){
    int n{Brojrijeci(recenica)};
    for(int i=0;i<recenica.length();i++){
        if(recenica[i]>='A' && recenica[i]<='Z') {recenica[i]+=32;}
    }
    std::map<std::string, std::set<int>> mapa;
    std::vector<std::string> vs;
    auto VektorRijeci = DajVektorRijeci(recenica);
    
    for(int i=0;i<n;i++){
        DodajRijec(vs, VektorRijeci[i]);
    }
    std::vector<std::set<int>> vekskup;
    for(int i=0;i<vs.size();i++){
        std::set<int> skup;
        for(int j=0;j<recenica.length();j++){
            std::string pomocna{Rijec(recenica, j)};
            int index{};
            if(vs[i]==pomocna) {
                index=j-pomocna.length(); 
                skup.insert(index);}
        }
        vekskup.push_back(skup);
    }
    
    for(int i=0;i<vs.size();i++){
        mapa.insert(std::make_pair(vs[i], vekskup[i]));
    }
	return mapa;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa ){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<< it->first<<": ";
    
    auto it2 = it;
    std::set<int> intovi = it2->second;
    auto jedan = intovi.begin();
    std::cout<<*jedan;
    jedan++;
    for(; jedan!=intovi.end();jedan++){
        std::cout<<","<<*jedan;
    }
    std::cout<<std::endl;
    }
}
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa){
    for(int i=0;i<rijec.length();i++){
        if(rijec[i]>='A' && rijec[i]<='Z') {rijec[i]+=32;}
    }
    std::set<int> skup;
    auto it(mapa.find(rijec));
    if(it == mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else skup = it->second;
    return skup;
}
int main (){
    std::cout<<"Unesite tekst: ";
    std::string recenica;
    std::getline(std::cin, recenica);
	
	std::vector<std::string> vek {DajVektorRijeci(recenica)};
	std::map<std::string, std::set<int>> mapa;
	
    mapa = KreirajIndeksPojmova(recenica);
	IspisiIndeksPojmova(mapa);
	std::cout<<"Unesite rijec: ";
	std::string rijec;
    while(std::getline(std::cin, rijec) && rijec!="."){
        std::set<int> skup;
        try{
            skup = PretraziIndeksPojmova(rijec, mapa);
            for(auto x: skup) std::cout<<x<<" ";
        }catch(...){
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<"\nUnesite rijec: ";
    }

	return 0;
}