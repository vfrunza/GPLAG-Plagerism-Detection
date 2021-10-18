/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <vector>
#include <stdexcept>

std::map<std::string, std::vector<int>> KreirajIndeksPojmova(std::string tekst){
    std::string s(tekst);
    std::map<std::string, std::vector<int>> mapa;
    for(int i=0; i<s.length(); i++) {
        while(((s[i]>9 && s[i]<'A') || (s[i]>'Z' && s[i]<'a') || s[i]>'z') && i!=s.size() ) i++;
        int indeks = i;
        int kraj(i);
        while(((s[i]>=0 && s[i]<=9) || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) && i!=s.size()) {
            i++;
            kraj++;
        }
        std::string pomocna(s.substr(indeks,kraj));
        for(auto x: pomocna) {
            if(x>=65 && x<=90) x+='a'-'A';
        }
        mapa[pomocna].push_back(indeks);
    }
    return mapa;
}

std::vector<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::vector<int>> mapa) {
    if(!mapa.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    else {
        auto x=mapa.find(rijec);
        return x->second;
    }
}

void IspisiIndeksPojmova(std::map<std::string, std::vector<int>> mapa) {
    for(auto x: mapa){
        std::cout<<x.first<<": ";
        auto indeksi=x.second;
        for(int i=0; i<indeksi.size()-1;i++) std::cout<<indeksi[i]<<",";
        std::cout<<indeksi[indeksi.size()];
        std::cout<<std::endl;
    }
}
int main ()
{   std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,tekst); //srsly
    IspisiIndeksPojmova(KreirajIndeksPojmova(tekst));
    std::string rijec;
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::cin>>rijec;
        if(rijec==".") break;
        try{
            std::vector<int> indeksi(PretraziIndeksPojmova(rijec, KreirajIndeksPojmova(tekst)));
            for(auto x: indeksi) std::cout<<x<<" "<<std::endl;
        }
        catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what();
        }
        
    }
	return 0;
}