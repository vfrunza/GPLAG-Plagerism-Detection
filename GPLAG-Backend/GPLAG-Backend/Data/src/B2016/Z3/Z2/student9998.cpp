/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<string>
#include<map>
#include<set>
#include<iterator>
#include<stdexcept>
#include<cstring>

bool slovo(char a){
    if ((a>='a' && a<='z') || (a>='A' && a<='Z')) return true;
    return false;
}

bool cifra (char a){
    if(a>='0' && a<='9') return true;
    return false;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    
    for(int i=0;i<s.length();i++)
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
        
    std::map<std::string, std::set<int>> mapa;
    for(int i=0;i<s.size();i++){
        if(!slovo(s[i]) && !cifra(s[i])) i++;
        if (slovo(s[i]) || cifra(s[i])) {
            int index=i;
            std::string s1;
            while( (slovo (s[i]) || cifra(s[i])) && i!=s.size()) {
                s1.push_back(s[i]);
                i++;
            }
        //ubaciti u mapu
        mapa[s1].insert(index); 
        //mapa.insert(std::make_pair(rijec,index));
      }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string,std::set<int>>mapa){
    for(int i=0;i<rijec.length();i++) if(rijec[i]>='A' && rijec[i]<='Z') rijec[i]+=32;
    
    std::set<int>skup_pozicija;
    for(auto it=mapa.begin();it!=mapa.end();it++){
        if(rijec==it->first) skup_pozicija=it->second;
        else if(!mapa.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    }
    return skup_pozicija;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::set<int>skup=it->second;
        std::cout<<it->first<<": ";
        auto a=skup.end();
        a--;
        for(auto j=skup.begin();j!=a;j++)     
            std::cout<<*j<<",";
        std::cout<<*(a++)<<std::endl;;
    }
}

int main ()
{
    
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    std::map<std::string, std::set<int>> mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);

    for(;;){
        try{
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        std::set<int> skup=PretraziIndeksPojmova(rijec,mapa);
        for(auto i=skup.begin();i!=skup.end();i++) std::cout<<*i<<" ";
        std::cout<<std::endl;
     }
     catch(std::logic_error e){
         std::cout<<"Unesena rijec nije nadjena!\n";
     }
    }
    
	return 0;
}