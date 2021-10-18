/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <set>
#include <algorithm>
#include <set>
#include <utility>
#include <iterator>


std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    
    std::map<std::string, std::set<int>> mapa;
    std::string rijec;
    std::set<int> skup;
    bool vani=0;
    int brojac;
    for(int i=0; i<s.length(); i++) {
        while(s[i]<48 || (s[i]>57 && s[i]<65) || (s[i]>90 && s[i]<97)  || s[i]>122){ i++;
        if(i==s.length()) { vani=1; break; }
        }
        if(vani==1) break;
        rijec="";
        if(i!=s.length()) {
            brojac=i;
        while(((s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97  && s[i]<=122)) && i!=s.length()) {
            rijec.push_back(tolower(s[i]));
            i++;
        }
        }
        
        
        mapa.insert(std::make_pair(rijec,skup));
    
        for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        if(rijec==it->first) it->second.insert(brojac);
    }
      
    }  
        
        return mapa;
    
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa ) {
    for(int i=0; i<s.length(); i++) {
        s[i]=tolower(s[i]);
    }
    std::set<int> skup;
    bool tacno=0;
     for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        if(s==it->first){
             for(int broj : it->second) 
             skup.insert(broj);
             tacno=1; 
        }
     }
        if(tacno==0) throw std::logic_error("Unesena rijec nije nadjena!");
    
    
    return skup;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout << it->first;
        std::cout << ": ";
        auto skupovi=it->second;
        for(auto it1=skupovi.begin(); it1!=skupovi.end(); it1++) {
            if(it1!=(--(skupovi.end())))
            std::cout << *it1 << ",";
            else std::cout << *it1;
        }
        std::cout << std::endl;
    }
    
}

int main ()
{
    std::string s;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    
   
    std::string rijec="glupost";
    IspisiIndeksPojmova(mapa);

    
    while(1) {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec == ".") return 0;
        std::set<int> skup;
    try{
        skup=PretraziIndeksPojmova(rijec, mapa);
        for(int broj : skup) std::cout << broj << " ";
        std::cout<<"\n";
        
    }catch(std::logic_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    }
    
    
	return 0;
}