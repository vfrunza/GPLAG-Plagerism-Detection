/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <stdexcept>
#include <cctype>


void  PrebaciVelikaSlovaUMala(std::string &s){
    
    for(int i = 0; i < s.length(); i++){
        if(s[i]>='A' && s[i]<='Z') s[i] = tolower(s[i]);
    }
}
std::set<int> PozicijeNaKojimSePojavljuje(std::string rijec, std::string recenica, int pocni_od){
    
    std::set<int> set;
    for(int i = pocni_od; i < recenica.length() - rijec.length()+1; i++){
      
        if(recenica.substr(i, rijec.length() ) == rijec && (i+rijec.length()==recenica.length() || ((recenica[i+rijec.length()]<'a' || recenica[i+rijec.length()]>'z') && (recenica[i+rijec.length()]<'0' || recenica[i+rijec.length()]>'9'))) && (i==0 || ((recenica[i-1]<'a' || recenica[i-1]>'z') && (recenica[i-1]<'0' || recenica[i-1]>'9')) )) {
            
            set.insert(i);
        }
    }
    return set;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    
    PrebaciVelikaSlovaUMala(s);
    
    
    std::map<std::string, std::set<int>> mapa;
    
    int i = 0;
    while(i != s.length()-1){
        if(((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && (i==0 || ((s[i-1]<'a' || s[i-1]>'z') && (s[i-1]<'0' || s[i-1]>'9')))){
           
            int pocetak_rijeci = i;
            int kraj_rijeci = i;
            while(((s[kraj_rijeci]>='a' && s[kraj_rijeci]<='z') || (s[kraj_rijeci]>='0' && s[kraj_rijeci]<='9') ) && kraj_rijeci<s.length()){
                kraj_rijeci++;
            }
            std::string pom = s.substr(pocetak_rijeci, kraj_rijeci-pocetak_rijeci);
            bool ima_vec = false;
            if(mapa.size()!=0){
                
                for(auto x  : mapa) if( x.first == pom) ima_vec = true;
            }
            if(ima_vec == false) {
                std::set<int> pom_set = PozicijeNaKojimSePojavljuje(pom, s,pocetak_rijeci);
                //std::cout<<"ovdje je " <<pom;
                mapa.insert(std::pair<std::string, std::set<int>>(pom,pom_set));
            }
            
        }
        
        i++;
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa)
{
    std::set<int> s={};
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
    {
        
        if(it->first==rijec)
        {
            for(int x: it->second)
            {
                s.insert(x);
            }
            return s;
        }
    }
    throw std::logic_error ("Unesena rijec nije nadjena!");
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
    {
        
        std::cout<<it->first<<": ";
        int i(0), ukupno(it->second.size()-1);
        for(int x : it->second)
        {
            if(i==ukupno) std::cout<<x;
            else std::cout<<x<<",";
            i++;
        }
        std::cout<<std::endl;
    }
    
}
int main ()
{
    
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> mapa = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    while(1){
        std::cout<<"Unesite rijec: ";
        std::string pom;
        std::getline(std::cin, pom);
        if(pom == ".") break;
        try{
            auto skup = PretraziIndeksPojmova(pom, mapa);
            int i(0), ukupno(skup.size()-1);
            for(auto x : skup){
                if(i==ukupno) std::cout<<x;
                else std::cout<<x<<" ";
                i++;
            }
        }
        catch(std::logic_error e){
            std::cout<<e.what();
        }
        std::cout<<std::endl;
    }
    /*
    auto m = KreirajIndeksPojmova("cvbkn34m5.n,34r67fgudbsc$%&/I()HVBNBn/&/&n///z&asdb23rgf87baew bfcQN3RCG3BR83O4NZTH");
    IspisiIndeksPojmova(m);
    auto skup = PretraziIndeksPojmova("n", m);
    for (const auto &c : skup) std::cout << c << " ";*/
    
	return 0;
}