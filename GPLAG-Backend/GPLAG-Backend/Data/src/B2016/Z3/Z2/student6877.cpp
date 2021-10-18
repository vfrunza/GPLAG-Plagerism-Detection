/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream> 
#include <cstring>
#include <map>
#include <utility>
#include <set>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst){
    std::map<std::string,std::set<int>> Indeks_pojmova;
    std::string pomocni;
    for(int i=0;i<tekst.length();i++){
        int indeks(0);
        while(i<tekst.length() && tekst[i]!=' '){
            pomocni.push_back(tekst[i]);
            i++;
        }
        indeks=(i-pomocni.length());
        auto it(Indeks_pojmova.find(pomocni));
        if(it==Indeks_pojmova.end() && pomocni!="" ) Indeks_pojmova[pomocni].insert(indeks);
        else Indeks_pojmova[pomocni].insert(indeks);
        pomocni="";
    }
    return Indeks_pojmova;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<int>> Indeks_pojmova){
    std::set<int> indeksi;
    auto it(Indeks_pojmova.find(rijec));
    if(it!=Indeks_pojmova.end()){
        for(auto a : it->second){
            indeksi.insert(a);
        }
    }
    
    return indeksi;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> Indeks_pojmova){
     for(auto it : Indeks_pojmova){
         std::cout <<it.first<<": ";
         for(auto x: it.second){
             std::cout <<x<<",";
         }
     
     std::cout<<std::endl;
    } 
}


                            
int main ()
{
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::cin >> tekst;
    std::map<std::string,std::set<int>> kip(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(kip);
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    std::cout << "Unesite rijec: ";
    std::string rijec;
    std::cin >> rijec;
    std::set<int> ind(PretraziIndeksPojmova(rijec,kip));
    for(int x: ind) std::cout <<x<<",";
	return 0;
}