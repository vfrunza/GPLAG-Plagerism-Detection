#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<tuple>
#include<set>
#include<stdexcept>
std::string PretvoriUMala(std::string s) {
    std::string novi;
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='A' && s[i]<='Z') novi.push_back(s[i]+32);
        else novi.push_back(s[i]);
    }
    return novi;
}
typedef std::map<std::string,std::vector<std::string>> Knjiga;
std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova(Knjiga tekst) {
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeksp;
    for(auto it=tekst.begin(); it!=tekst.end(); it++) {
        std::string poglavlje(it->first);
        std::vector<std::string> stranice(it->second);
        for(int j=0; j<stranice.size(); j++) {
            int brojstr(j+1);
            std::string str(stranice[j]);
            for(int k=0; k<str.size(); k++) {
                if(str[k]==' ') {
                    while(str[k]==' ' && k<str.size()) {
                        k++;
                        if(k==str.size()) break;
                    }
                }
                if(k==str.size()) break;
                int poz(k);
                std::string rijec;
                if((str[k]>='A' && str[k]<='Z') || (str[k]>='a' && str[k]<='z') || (str[k]>='0' && str[k]<='9')) {
                    while(((str[k]>='A' && str[k]<='Z') || (str[k]>='a' && str[k]<='z')|| (str[k]>='0' && str[k]<='9')) && k<str.size()) {
                        rijec.push_back(str[k]);
                        k++;
                        if(k==str.size()) break;
                    }
                    rijec=PretvoriUMala(rijec);
                    auto t(std::make_tuple(poglavlje,brojstr,poz));
                    auto trazi(indeksp.find(rijec));
                    if(trazi==indeksp.end()) {
                        std::set<std::tuple<std::string,int,int>> skup;
                        skup.insert(t);
                        indeksp.insert(std::make_pair(rijec,skup));
                    } 
                    else trazi->second.insert(t);
                    
                    if(k==str.size()) break;
                    else k--;
                }
            }
        }
    }
    return indeksp;
}
std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<std::tuple<std::string,int,int>>> mapa) {
    rijec=PretvoriUMala(rijec);
    auto it(mapa.find(rijec));
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    std::set<std::tuple<std::string,int,int>> pozicije(it->second);
    return pozicije;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<std::tuple<std::string,int,int>>> mapa) {
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        std::set<std::tuple<std::string,int,int>> skup(it->second);
        int vel(skup.size()), zarez(0);
        for(auto el: skup) {
            std::cout<<std::get<0>(el)<<"/"<<std::get<1>(el)<<"/"<<std::get<2>(el);
            zarez++;
            if(zarez!=vel) std::cout<<", ";
        }
        std::cout<<std::endl;
    }
}
int main () {
    Knjiga mapa; 
    for(;;) {
       std::cout<<"Unesite naziv poglavlja: ";
        std::string naslov;
        std::getline(std::cin,naslov);
        if(naslov==".") break;
        std::vector<std::string> v;
        int brojac(1);
        for(;;) {
            std::cout<<"Unesite sadrzaj stranice "<<brojac<<": ";
            std::string sadrzajstr;
            std::getline(std::cin,sadrzajstr);
            if(sadrzajstr==".") break;
            v.push_back(sadrzajstr);
            brojac++;
        }
        mapa.insert(std::make_pair(naslov,v));
    }
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> indekspojmova(KreirajIndeksPojmova(mapa));
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(indekspojmova);
    for(;;) {
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::cin>>rijec;
        std::cin.ignore(1000,'\n');
        if(rijec==".") break;
        try {
            std::set<std::tuple<std::string,int,int>>pozicije(PretraziIndeksPojmova(rijec,indekspojmova));
            for(auto p: pozicije) std::cout<<std::get<0>(p)<<"/"<<std::get<1>(p)<<"/"<<std::get<2>(p)<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    return 0;
}