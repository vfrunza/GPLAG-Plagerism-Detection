/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iterator>
#include <stdexcept>
#include <map>
#include <set>
#include <utility>
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string recenica) {
    std::map<std::string, std::set<int>> indeksi;
    std::vector<std::string> words;
    std::set<int> skup;
    for(int i=0; i<recenica.length(); i++) recenica[i]=tolower(recenica[i]);
    for(int i=0; i<recenica.length(); i++) {
             std::string pomocni;
            for(int j=recenica.length()-1; j>=i; j--){
              pomocni=recenica.substr(i, j-i+1);
               bool rijec_je=true;
            if((i==0 || recenica[i-1]<'0' || (recenica[i-1]>'9' && recenica[i-1]<'A') || (recenica[i-1]>'Z' && recenica[i-1]<'a')|| recenica[i-1]>'z') &&( j==recenica.length()-1 || recenica[j+1]<'0' || (recenica[j+1]>'9' && recenica[j+1]<'A') || (recenica[j+1]>'Z' && recenica[j+1]<'a') ||recenica[j+1]>'z')) {
             for(int k=0; k<pomocni.length(); k++) if(pomocni[k]<'0' || (recenica[k]>'9' && recenica[k]<'a') || recenica[k]>'z') rijec_je=false;
          } else rijec_je=false;
            if(rijec_je) {
                bool sama=true;
                for(int k=0; k<words.size(); k++) {if(pomocni==words[k]) sama=false;}
                if(sama) {words.push_back(pomocni);
                indeksi.insert(std::make_pair(pomocni, skup));
                }}}}
            for(int i=0; i<recenica.length(); i++) {
                for(int j=recenica.length()-1; j>=i; j--) {
                    std::string podstring(recenica.substr(i, j-i+1));
                    for(int l=0; l<words.size(); l++) if(podstring==words[l]) indeksi[podstring].insert(i); 
                }}
        return indeksi;
}
std::set<int> PretraziIndeksPojmova(std::string word, std::map<std::string, std::set<int>> mapa) {
    auto it=mapa.find(word);
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena");
    else return it->second;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    for(auto p=mapa.begin(); p!=mapa.end(); p++) {
        std::cout<<(p->first);
        std::cout<<": ";
        auto pocetak((p->second).begin()), kraj((p->second).end()), pok((p->second).begin());
        int naprijed(0);
        while(naprijed<distance(pocetak, kraj)) {
            if(naprijed+1<distance(pocetak, kraj)) std::cout<<*pok<<",";
            else std::cout<<*pok;
            naprijed++;
            pok++;
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    std::string s, trazena;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    auto indeksi=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(indeksi);
    for(;;) {
        std::cout<<"\nUnesite rijec: ";
        std::cin>>trazena;
        if(trazena!=".") {
            try{
                auto pozicije=PretraziIndeksPojmova(trazena, indeksi);
                for(int x: pozicije) std::cout<<x<<" ";
            } catch(...) {std::cout<<"Unesena rijec nije nadjena!";}
        } else break;
    }
	return 0;
}