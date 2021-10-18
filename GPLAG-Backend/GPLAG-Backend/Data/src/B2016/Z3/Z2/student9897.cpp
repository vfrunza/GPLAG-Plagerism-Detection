/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <vector>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s) {
    
    std::map<std::string, std::set<int>> mapa; 
    int duzina(s.length()); 
    
    for (int i=0; i<duzina; i++) {
        std::set<int> indeksi; 
         
        if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) {
        int br(i);
        
        while ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) {
            if (i==duzina) break; 
            i++;
        }
        
        int prva(i); 
        int d; 
        d=(prva-br); 
        
        std::string pomocna(s.substr(br,d));
        
        int br2(0); 
        
        for (int j=0; j<duzina; j++) {
            if ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')) {
            br2=j; 
        
        while ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')) {
            if (j==duzina) break; 
            j++; 
        }
    }
    
     std::string rijec(s.substr(br2, j-br2));  
     if (rijec==pomocna) 
     indeksi.insert(br2);
            
        }
        mapa.insert (std::make_pair(pomocna, indeksi));
        
     }
    }

    return mapa; 
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa) {
  
    auto it(mapa.find(rijec)); 
    
    if (it==mapa.end()) throw std::logic_error ("Unesena rijec nije nadjena!"); 
    return it->second; 
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa) {
    std::vector<int> vektor;
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        int brojac(0); 
         
        for (auto it1(it->second.begin()); it1!=(it->second.end()); it1++)
            brojac++; 
            vektor.push_back(brojac); 
        }
        int a(0); 
        
        for (auto it=mapa.begin(); it!=mapa.end(); it++) {
            std::cout << it->first << ": "; 
            int brojac(0); 
            
            for (auto x : it->second) {
                if (brojac!=vektor[a]-1) std::cout << x << ","; 
                else std::cout << x << " "; 
                brojac++; 
            }
            a++; 
            std::cout << std::endl;
    }
}

int main ()
{
    std::string s; 
    std::cout << "Unesite tekst: "; 
    std::getline(std::cin, s); 
    
    auto mapa(KreirajIndeksPojmova(s)); 
    IspisiIndeksPojmova(mapa);
    
    for (;;) {
    std::string rijec; 
    std::cout << "Unesite rijec: "; 
    std::getline(std::cin, rijec); 
    
    if (rijec==".") break; 
    
    try {
        auto skup(PretraziIndeksPojmova(rijec, mapa)); 
        for (auto x : skup) 
        std::cout << x << " "; 
        std::cout << std::endl; 
    }
    catch(std::logic_error e) {
        std::cout << e.what() << std::endl;
    }
    }
   
	return 0;
}