/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <locale>
#include <stdexcept>

bool DaLiJeOk(char c){
    if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) return true;
    return false;
}

std::set<int> GdjeJeRijec(const std::string &tekst, std::string rijec){
    std::set<int> pozicije;
    for(int i=0; i<tekst.size(); i++){
        while(tekst[i]!=rijec[0] && tekst[i]!=std::toupper(rijec[0]) && tekst[i]!=std::tolower(rijec[0])) { if(i==tekst.size()-1) break; i++; }
        if(!(i==0 || !DaLiJeOk(tekst[i-1]))) continue;
        int poz(i);
        int j(0);
        while(tekst[i]==rijec[j] || tekst[i]==std::toupper(rijec[j]) || tekst[i]==std::tolower(rijec[j])){
            if(i==tekst.size()-1) {
                j++;
                break;
            }
            i++;
            j++;
        }
        if(j==rijec.size() && (i==tekst.size()-1 || !DaLiJeOk(tekst[i]))) pozicije.insert(poz);
    }
    return pozicije;
}
std::map<std::string, std::set<int>>KreirajIndeksPojmova(std::string tekst){
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<tekst.size(); i++){
        std::string rijec;
        while(i<tekst.size() && !((tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='0' && tekst[i]<='9')))  i++;
        int poc;
        if(i==tekst.size()) break;
        else  poc=i;
        int duzina(0);
        while(DaLiJeOk(tekst[i])) {
            i++;
            duzina++;
        }
        rijec=tekst.substr(poc,duzina);
        for(int i=0; i<rijec.size(); i++){
            rijec[i]=std::tolower(rijec[i]);
        }
        auto it(mapa.find(rijec));
        if(it==mapa.end()){
            mapa.insert(std::make_pair(rijec,GdjeJeRijec(tekst,rijec)));
        }
        else continue;
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> indeks_pojmova){
    auto it(indeks_pojmova.find(rijec));
    if(it==indeks_pojmova.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    auto it(mapa.begin());
    while(it!=mapa.end()){
        std::cout<<it->first<<": ";
        int i(0);
        for(auto x : it->second) {
            i++;
            if(i==it->second.size()) std::cout<<x;
            else std::cout<<x<<",";
        }
        it++;
        std::cout<<std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    for(;;){
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try{
            auto skup(PretraziIndeksPojmova(rijec, mapa));
            for(auto x : skup) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}