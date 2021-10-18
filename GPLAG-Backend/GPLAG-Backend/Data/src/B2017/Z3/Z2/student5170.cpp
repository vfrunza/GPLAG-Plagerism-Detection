/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <utility>
#include <set>
#include <tuple>
#include <map>
#include <vector>
#include <string>

typedef std::map<std::string, std::vector<std::string>>Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string,int,int>>> Indeks;

bool slovoilibroj(char a) { if((a>='A' && a<='Z')|| (a>='a' && a<='z')|| (a>='0'&&a<='9') )return true;return false; }
std::string pretvoriumale(std::string rijec) {for(int i=0;i<rijec.size();i++) if(rijec[i]>='A' && rijec[i]<='Z')rijec[i]+=32;return rijec;}
Indeks KreirajIndeksPojmova(Knjiga knjiga) {
    
    for(auto it=knjiga.begin();it!=knjiga.end();it++) {
        for(int i=0;i<it->second.size();i++) {
            it->second[i]=pretvoriumale(it->second[i]);
        }
    }
    
   Indeks indeks;
   for(auto it=knjiga.begin();it!=knjiga.end();it++) { //kroz mapu, it->second je vektor
       
       for(int i=0;i<it->second.size();i++) {  //kroz vektor stringova
           
            for(int j=0;j<it->second[i].size();j++) {
                while(j<it->second[i].size() && !slovoilibroj(it->second[i][j]))j++;
                int k=j;
                while(k<it->second[i].size() && slovoilibroj(it->second[i][k]))k++;
                if(!indeks.count( it->second[i].substr(j,k-j)) ) {   //ako nema rijeci dosad
                    std::set<std::tuple<std::string,int,int>> pomocniset;
                    for(auto it2=it;it2!=knjiga.end();it2++) {
                        
                        int l;
                        if(it2==it)l=i;else l=0;
                        for(;l<it2->second.size();l++) {
                            int o; if(l==i)o=j; else o=0;
                            for(;o<it2->second[l].size();o++) {
                                while(o<it2->second[l].size() && !slovoilibroj(it2->second[l][o]))o++;
                                int p=o;
                                while(p<it2->second[l].size() && slovoilibroj(it2->second[l][p]))p++;
                                if(pretvoriumale(it2->second[l].substr(o,p-o))==it->second[i].substr(j,k-j)){
                                    pomocniset.insert(std::make_tuple(it2->first,l+1,o));
                                }
                                o=p;
                            }
                            
                        }
                        
                    }
                   
                    indeks.insert(std::make_pair( it->second[i].substr(j,k-j),pomocniset) );
                }
             j=k;   
            }
       }
       
   }
   
    return indeks;
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec, Indeks indeks) {
    rijec=pretvoriumale(rijec);
    if(!indeks.count(rijec)) throw std::logic_error ("Pojam nije nadjen");
    return indeks[rijec];
}

void IspisiIndeksPojmova (Indeks indeks) {
    for(auto it=indeks.begin();it!=indeks.end();it++) {
        std::cout<<it->first<<": ";
        auto pomocni=it->second;
        int broj=pomocni.size();int brojac=0;
        for(auto it2=pomocni.begin();it2!=pomocni.end();it2++) {
            std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
            if(brojac!=broj-1)std::cout<<", "; else std::cout<<std::endl;
            brojac++;
        }
    } 
}

int main ()
{   
    
    Knjiga knjiga;
    while(1) {
    std::cout<<"Unesite naziv poglavlja: ";
    std::string poglavlje;std::getline(std::cin,poglavlje);
    if(poglavlje.size()==1 && poglavlje[0]=='.')break;
    std::vector<std::string>vektor;
    int brojstranice=0;
    while(1) {
        std::cout<<"Unesite sadrzaj stranice "<<brojstranice+1<<": ";
        std::string stranica;
        std::getline(std::cin,stranica);
        if(stranica.size()==1 && stranica[0]=='.') break;
        vektor.push_back(stranica);
        brojstranice++;
    }
     knjiga.insert(std::make_pair(poglavlje,vektor));   
    }
    std::cout<<std::endl;
    std::cout<<"Kreirani indeks pojmova: "<<std::endl;
    Indeks indeks=KreirajIndeksPojmova(knjiga);
    IspisiIndeksPojmova(indeks);
    std::cout<<std::endl;
    while(1) {
        try {
        std::cout<<"Unesite rijec: ";
        std::string rijec; std::getline(std::cin,rijec);
        if(rijec.size()==1 && rijec[0]=='.')break;
        if(PretraziIndeksPojmova(rijec,indeks).size()!=0) {
        auto pomocniset=PretraziIndeksPojmova(rijec,indeks);
        for(auto it=pomocniset.begin();it!=pomocniset.end();it++) {
            std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
        } std::cout<<std::endl;
    }
        }
        catch(std::logic_error izuzetak) {std::cout<<"Unesena rijec nije nadjena!"<<std::endl;}
    }
    
    
   
	return 0;
}
