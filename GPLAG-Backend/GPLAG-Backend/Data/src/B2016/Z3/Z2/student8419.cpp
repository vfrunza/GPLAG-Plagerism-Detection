/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>
#include <utility>

bool JeLiSlovo(char c){
    return((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'));
}

std::string PretvoriUMalaSlova(std::string s){
   for(int i=0; i<s.length(); i++){
       if(!(s[i]>='a' && s[i]<='z') && (s[i]>='A' && s[i]<='Z')) s[i]+='a'-'A';
   }
    return s;
}

std::map<std::string, std::set<int>> IzdvojiRijeci(std::string &s){
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<s.length(); i++){
        if(JeLiSlovo(s[i])){
            int j=i;
            while(JeLiSlovo(s[j])) j++;
            std::string rijec;
            rijec=PretvoriUMalaSlova(s.substr(i, j-i));
            mapa[rijec]={};
            i=j;
        }
    }
    return mapa;
}

bool JesuLiJednaki(std::string s1, std::string s2){
    for(char c: s1) c=std::toupper(c);
    for(char c: s2) c=std::toupper(c);
    return s1==s2;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s){
    int neslovo(1);
    std::map<std::string, std::set<int>> mapa=IzdvojiRijeci(s);
    for(int i=0; i<s.length(); i++){
        if(!(JeLiSlovo(s[i]))){
            neslovo=1;
        }
        else if(neslovo==1){
            neslovo=0;
            int j=i; 
            while(JeLiSlovo(s[j])) j++;
            for(auto it=mapa.begin(); it!=mapa.end(); it++){
                std::string pomocni=PretvoriUMalaSlova(s.substr(i, j-i));
                if(JesuLiJednaki(pomocni, it->first)){
                    (it->second).insert(i);
                }
            }
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa){
    auto it=mapa.begin();
    for(it=mapa.begin(); it!=mapa.end(); it++){
        if(rijec==it->first) return it->second;
    }
    if(it==mapa.end()) throw std::logic_error ("Pojam nije nadjen");
}

int PrebrojiRijeci(std::set<int> skup){
    int brojac(0);
    for(auto it=skup.begin(); it!=skup.end(); it++) brojac++;
    return brojac;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first<<": ";
        int broj_rijeci=PrebrojiRijeci(it->second);
        int brojac(0);
        for(auto it2=(it->second).begin(); it2!=(it->second).end(); it2++){
            brojac++;
            if(brojac==broj_rijeci) std::cout<<*it2;
            else std::cout<<*it2<<",";
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> mapa = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    do{
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try{
            std::set<int> skup=PretraziIndeksPojmova(rijec, mapa);
            for(auto it=skup.begin(); it!=skup.end(); it++) std::cout<<*it<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }while(rijec!=".");
	return 0;
}