/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<vector>
#include<set>
#include<list>
#include<stdexcept>

int duzinaImena(std::string s){
    int brojac=0;
    for(int i=0;i<s.size();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) brojac++;
        
    }
    return brojac;
}

std::vector<std::set<std::string>>Razvrstavanje(std::vector<std::string> imenik, int k){
     if(k<1 || k>imenik.size()) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
     std::list<std::string>lista;
     for(int i=0;i<imenik.size();i++)
     lista.push_back(imenik[i]);
     
     std::vector<std::set<std::string>>vektorSkupova;
     std::vector<int>brojaci;
     for(int i=0;i<imenik.size()%k;i++)
     brojaci.push_back(imenik.size()/k+1);
     
     for(int i=0;i<k-(imenik.size()%k);i++)
     brojaci.push_back(imenik.size()/k);
     
     auto it=lista.begin();
     int brRep=0;
     for(int i=0;i<brojaci.size();i++){
         int brojac=0;
         std::set<std::string>skup;
         while(brojac!=brojaci[i]){
             auto kraj=lista.end();
             for(int k=0;k<brRep-1;k++){
                 it++;
                 if(it==lista.end()) it=lista.begin();
             }
             skup.insert(*it);
             brRep=duzinaImena(*it);
             it=lista.erase(it);
             if(it==lista.end()) it=lista.begin();
             brojac++;
         }
         vektorSkupova.push_back(skup);
     }
     return vektorSkupova;
}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::vector<std::string>vektor(n);
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::cin.ignore(1000, '\n');
    for(int i=0;i<n;i++){
        std::string s;
        std::getline(std::cin,s);
        vektor[i]=s;
    }
    std::cout<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    try{
        std::vector<std::set<std::string>>vektorSkupova;
        vektorSkupova=Razvrstavanje(vektor,k);
        for(int i=0;i<vektorSkupova.size();i++){
            int brojac=1;
            std::cout<<"Tim "<<i+1<<": ";
            for(std::string x:vektorSkupova[i]){
                if(brojac++!=vektorSkupova[i].size()) std::cout<<x<<", ";
                else std::cout<<x;
            }
            std::cout<<std::endl;
        }
    }catch(std::logic_error l){
        std::cout<<l.what();
    }
	return 0;
}