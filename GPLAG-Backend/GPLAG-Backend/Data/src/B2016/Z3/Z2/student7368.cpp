/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <stdexcept>
#include <algorithm>

std::map<std::string,std::set<int>>KreirajIndeksPojmova (std::string s){
    std::map<std::string,std::set<int>>mapa;
    std::vector<std::string>vs={"kghf"};
    for (int i=0; i<s.length(); i++) if (s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
    
    for (int i=0; i<s.length(); i++) {
        bool u_vec_ima_rijec=false;
        std::string rijec;
        std::set<int>v;//izmjena
        while (i<s.length() && !(s[i]>='a'&&s[i]<='z') && !(s[i]>='0'&&s[i]<='9')) i++;
        int index1=i;
        while (i<s.length() && ((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))) {
            rijec.push_back(s[i]); i++;
        }
        for (int h=0; h<vs.size(); h++) {
            if (vs[h]==rijec) {u_vec_ima_rijec=true;break;}
        }
        vs.push_back(rijec);
        if (u_vec_ima_rijec==false) {
        v.insert(index1);

        for (int j=i; j<s.length(); j++) {
            std::string rijec2;
            while (j<s.length() && !(s[j]>='a'&&s[j]<='z')&&!(s[j]>='0'&&s[j]<='9')) j++;
            int index2=j;
            while (j<s.length() && ((s[j]>='a'&&s[j]<='z')||(s[j]>='0'&&s[j]<='9'))) {
                rijec2.push_back(s[j]); j++;
            }
            if (rijec==rijec2) {
                v.insert(index2);
            }
        }
        mapa.insert(std::make_pair(rijec,v));
    }
  }
   return mapa;   
}
std::set<int>PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>>mapa) {
    bool ima=false;
    std::set<int>skup;
    std::map<std::string,std::set<int>>::iterator it;
    for (it=mapa.begin(); it!=mapa.end(); it++) {
        if (mapa.count(rijec)) {
            ima=true;
            std::set<int>skup1=mapa[rijec];
            skup=skup1;
            break;
        }
    }
    if (ima==false) throw std::logic_error ("Unesena rijec nije nadjena!");
    return skup;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>>mapa) {
    for (auto it=mapa.begin(); it!=mapa.end(); it++){
        std::cout<<it->first<<": ";
        std::vector<int>v;
        std::set<int>inVec=it->second;
            for (auto i: inVec) v.push_back(i); 
            for (int i=0; i<v.size(); i++) { 
            std::cout<<v[i];
            if (i<inVec.size()-1) std::cout<<",";
        }
        std::cout<<std::endl;
    }
}
int main () {
    std::string recenica;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, recenica);
    IspisiIndeksPojmova(KreirajIndeksPojmova(recenica));
    std::map<std::string,std::set<int>>mapa=KreirajIndeksPojmova(recenica);
    while (1) {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if (rijec==".") break;
        std::set<int>v;//izmjena
        try{
            v=PretraziIndeksPojmova(rijec,mapa);
            for (auto i: v) std::cout<<i<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
        }
    }
	return 0;
}