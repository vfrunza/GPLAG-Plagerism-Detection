/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <cstring>
#include <utility>
char Sve_U_Mala(char c){
    return std::tolower(c);
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    for(int i=0;i<s.length();i++){
        s[i]=Sve_U_Mala(s[i]);
    }
    /*for(int i=0;i<s.length();i++){
        std::cout<<s[i];
    }*/
    std::set<int> skup;
    std::string rijec;
    int i=0,j=0,k;
    std::map<std::string,  std::set<int>> map;
    while(s[i]!='\0'){
        while(s[i]<'0' || (s[i]>'9' && s[i]<'A') || (s[i]>'Z' && s[i]<'a') || s[i]>'z') i++;
        j=i;
        k=i;
        while((s[j]>='0' && s[j]<='9') || (s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z')) j++;
    while(i<j){
        rijec+=s[i];
        i++;
    }
    auto it(map.find(rijec));
    if(it==map.end()) {
        skup.insert(k);
        map.insert(std::make_pair(rijec,skup));
    }
    else {
        map[rijec].insert(k);
    }
    skup.clear();
    rijec.resize(0);
}
    return map;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m){
    for(auto i=m.begin();i!=m.end();i++){
        std::cout<<i->first<<": ";
        for(auto j=i->second.begin();j!=i->second.end();j++){
            auto x=i->second.end(); x--;
            if(j==x) std::cout<<*j;
            else std::cout<<*j<<",";
        }
        std::cout<<std::endl;
    }
}
std::set<int> PretraziIndeksPojmova(std::string string, std::map<std::string, std::set<int>> m){
    auto it(m.find(string));
    if(it==m.end()) {
        throw std::logic_error("Pojam nije nadjen");
    } else{
        return it->second;
    }
}
int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>> m=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    std::string trazi=" ";
    std::set<int> indeksi;
    while(trazi!="."){
            try{
            std::cout<<"Unesite rijec: ";
            trazi.resize(0);
            std::getline(std::cin,trazi);
            if(trazi==".")break;
            indeksi=PretraziIndeksPojmova(trazi,m);
            for(auto x: indeksi) std::cout<<x<<" ";
            std::cout<<std::endl;
        } catch(...){
            std::cout<<"Unesena rijec nije nadjena!\n";
        }
    }
	return 0;
}