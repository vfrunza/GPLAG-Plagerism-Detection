/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
bool simbol(char s){if((s>='a' && s<='z') || (s>='A' && s<='Z')||(s>='0' && s<='9')) return true; return false;}
bool vecima(std::map<std::string,std::set<int>> mapa, std::string s){return mapa.count(s);}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> izlaz;
    for(int i=0;i<s.length();i++){
//letaj po stringu
        while(!simbol(s[i])) i++; //dodji do sljedeceg "slova"
        std::string temp;
        unsigned d=i;
        while(i!=s.length() && simbol(s[i])){
            if(s[i]>='A' && s[i]<='Z'){
                temp+=(s[i++]+'a'-'A');
            }
            else temp+=s[i++];
        }
        izlaz[temp].insert(d);
    }
return izlaz;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>> mapa){
    unsigned i=0;
    while(i!=s.length()){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]+=('a'-'A');
                i++;
            }else i++;
        }
    auto it = mapa.find(s);
    if(it == mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!\n");
std::set<int> izlaz = it->second;
    return izlaz;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> hu_ha){
    for(const auto &it:hu_ha){
    std::cout<<it.first<<": ";
    unsigned brojac(1);
    for(const auto &it1:it.second){
        if(brojac == it.second.size()){ std::cout<<it1; break;}
        std::cout<<it1<<",";
        brojac++;
    }
    std::cout<<std::endl;
} 
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string proba;
    std::getline(std::cin,proba);
std::map<std::string,std::set<int>>hu_ha=KreirajIndeksPojmova(proba);
IspisiIndeksPojmova(hu_ha);
std::string rijec;
while(rijec!="."){try{
    std::cout<<"Unesite rijec: ";
std::getline(std::cin,rijec);
if(rijec == ".") break;
std::set<int> skup=PretraziIndeksPojmova(rijec, hu_ha);
for(const auto &it:skup){
    std::cout<<it<<" ";
}std::cout<<std::endl;
}catch(std::logic_error &greshka){ std::cout<<greshka.what();}//"Unesena rijec nije nadjena!\n";}
}
	return 0;
}