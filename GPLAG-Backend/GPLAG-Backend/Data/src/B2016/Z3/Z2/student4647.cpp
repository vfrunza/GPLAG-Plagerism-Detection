/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> mapa;
    
    for(int i=0; i<s.size(); i++) {
    std::set<int> skup;
    std::string str;
        while((s[i]>='A'&& s[i]<='Z') || (s[i]>='a'&& s[i]<='z') || (s[i]>='0' && s[i]<='9')) {
            if(s[i]>='A'&& s[i]<='Z') str.push_back(s[i]+32); 
            else str.push_back(s[i]);
            i++; 
            if(i==s.size()) break; }
        for(int k=0; k<s.size(); k++) {
        int m=0;
        int poc=k;
        while (s[k]==str[m] || s[k]==str[m]+32 ||s[k]==str[m]-32) {k++; m++; if(m==str.size()) break; if(k==s.size()) break;}
        
        if((str.size()!=0) &&
        (k==s.size() || !((s[k]>='A'&& s[k]<='Z') || (s[k]>='a'&& s[k]<='z') || (s[k]>='0' && s[k]<='9'))) && m==str.size() && 
        (s[poc]==s[0] || !((s[poc-1]>='A'&& s[poc-1]<='Z') || (s[poc-1]>='a'&& s[poc-1]<='z') || (s[poc-1]>='0' && s[poc-1]<='9'))) ){
        skup.insert(poc);}
        }
        if(str.size()!=0)
    mapa.insert(std::make_pair(str, skup));
    std::set<int>::iterator it1{skup.begin()};
    std::set<int>::iterator it2{skup.end()};
    skup.erase(it1, it2);
    str.resize(0);
    }

return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> mapa) {
    std::set<int> skup;
    for(int i=0; i<s.size(); i++) {
        if ((s[i]>='A'&& s[i]<='Z')) s[i]=s[i]+32;
    }
    for( auto it=mapa.begin(); it!=mapa.end(); it++) {

        if(s==it->first){
        skup=it->second;
        return skup;
    }
    }
        throw std::logic_error("Pojam nije nadjen");

}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa) {
    for( auto it=mapa.begin(); it!=mapa.end(); it++) {
    std::cout<<it->first<<": ";
    auto m=it->second.begin();
    int vel=it->second.size();
    for(int i=0; i<vel-1; i++) {std::cout<<*m<<","; m++;} 
    std::cout<<*m;
    std::cout<<std::endl;
    }
}

int main ()
{
    std::string rec;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, rec);
    std::map<std::string, std::set<int>> mapa=KreirajIndeksPojmova(rec);
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    std::cout<<"Unesite rijec: ";
    std::getline(std::cin, rijec);
    while(rijec!=".") {
    try {
    std::set<int> noviset=PretraziIndeksPojmova(rijec, mapa);
    for( int x: noviset) std::cout<<x<<" ";
    std::cout<<std::endl;}
     catch(std::logic_error) {std::cout<<"Unesena rijec nije nadjena!"<<std::endl;}
     std::cout<<"Unesite rijec: ";
    std::getline(std::cin, rijec);
  }
	return 0;
}