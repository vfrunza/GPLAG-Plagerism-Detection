/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <set>
#include <stdexcept>

bool JeLiSlovo(char c)
{
    return ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'));
}

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga &knjiga)
{
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> vracamo;

    for(Knjiga::iterator it_m=knjiga.begin(); it_m!=knjiga.end(); it_m++) {
        std::string poglavlje(it_m->first);
        for(int i=0; i<knjiga[poglavlje].size(); i++) {
            std::string Stranica(knjiga[poglavlje][i]);
            
             int broj_stranice=i+1;
            std::string trenutna_rijec="";
            int indeks_rijeci=0;
            for(int j=0; j<Stranica.length(); j++) {
                
                if(JeLiSlovo(Stranica[j])) {
                    if(trenutna_rijec=="") indeks_rijeci=j;
                    trenutna_rijec+=tolower(Stranica[j]);
                } else if(!JeLiSlovo(Stranica[j])){
                    if(trenutna_rijec!="") {
                        vracamo[trenutna_rijec].insert(std::tuple<std::string, int, int>(poglavlje, broj_stranice, indeks_rijeci));
                    }
                    trenutna_rijec="";
                }
            }
            vracamo[trenutna_rijec].insert(std::tuple<std::string, int, int>(poglavlje, broj_stranice, indeks_rijeci));
            
        }
    }
  //  std::cout<<vracamo.size();
    return vracamo;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> &mapa)
{
   // std::cout<<"Usli smo: "<<mapa.size();
    for(auto it(mapa.begin()); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        std::set<std::tuple<std::string, int, int>>::iterator it_t;
        for(it_t=mapa[it->first].begin(); it_t!=mapa[it->first].end(); it_t++) {
            std::cout<<std::get<0>(*it_t)<<"/"<<std::get<1>(*it_t)<<"/"<<std::get<2>(*it_t);
            auto pred_kraj(mapa[it->first].end());
            pred_kraj--;
            if(it_t!=pred_kraj) std::cout<<", "; //ispraviti
            else std::cout<<std::endl;
        }
    }
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string &s, std::map<std::string, std::set<std::tuple<std::string, int, int>>> &mapa)
{
    std::set<std::tuple<std::string, int, int>> indeks;
    for(auto it(mapa[s].begin()); it!=mapa[s].end(); it++) {
        indeks.insert(*it);
    }
    if(indeks.size()==0) throw std::logic_error("Unesena rijec nije nadjena!");
    return indeks;
}

int main ()
{
    Knjiga knjiga;
    while(1) {
        int i(0);
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::cin>>poglavlje;std::cin.clear();
        std::cin.ignore(10000, '\n');
        if((poglavlje[i]=='.' && poglavlje[i+1]==' ' && i+1<poglavlje.length() )|| (poglavlje[i]=='.' && i+1==poglavlje.length())) break;
        
        std::vector<std::string> stranice;
        int brojac(0);
        while(1) {
            std::cout<<"Unesite sadrzaj stranice "<<brojac+1<<": ";
            std::string stranica;
            std::getline(std::cin, stranica);
            
            if((stranica[0]=='.' && stranica[1]==' ' && 1<stranica.length()) || (stranica[0]=='.' && 1==stranica.length())) break;
            
          //  std::cout<<stranica;
            stranice.push_back(stranica);
           // std::cout<<stranice[i];
            brojac++;
        }
        i++;
        knjiga.insert(std::make_pair(poglavlje, stranice));
    }
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks_pojmova(KreirajIndeksPojmova(knjiga));
    IspisiIndeksPojmova(indeks_pojmova);
    
    while(1){
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
       // if((rijec[i]=='.' && rijec[i+1]==' ' && i+1<rijec.length()) || (rijec[i]=='.' && i+1==rijec.length())) break;
        if((rijec[0]=='.' && rijec[1]==' ' && 1<rijec.length()) || (rijec[0]=='.' && 1==rijec.length())) break;
        try{
            std::set<std::tuple<std::string, int, int>> nadjena(PretraziIndeksPojmova(rijec, indeks_pojmova));
            //std::set<std::tuple<std::string, int, int>>::iterator pok(nadjena.begin());
            for(std::set<std::tuple<std::string, int, int>>::iterator pok(nadjena.begin()); pok!=nadjena.end(); pok++)
                std::cout<<std::get<0>(*pok)<<"/"<<std::get<1>(*pok)<<"/"<<std::get<2>(*pok)<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }
    }
    
    return 0;
}
