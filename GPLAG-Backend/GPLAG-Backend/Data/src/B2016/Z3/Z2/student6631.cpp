/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

std::vector<std::string> KreirajVektor(std::string s){
    std::map<std::string, std::set<int>> rez;
    std::vector<std::string> spisak;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    int pocetna, krajnja;
    for(int i=0; i<s.size();i++){
        if(s[i]==' ')continue;
        else if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            pocetna=i;
            int pomocna=i;
            while((s[pomocna]>='a' && s[pomocna]<='z') || (s[pomocna]>='0' && s[pomocna]<='9')){
                pomocna++;
            }
            krajnja=pomocna;
            i=krajnja;
            std::string rijec(s.substr(pocetna, krajnja-pocetna));
            spisak.push_back(rijec);
        }
    }
    std::sort(spisak.begin(), spisak.end());
    int broj = std::unique(spisak.begin(), spisak.end()) - spisak.begin();
    spisak.resize(broj);
    return spisak;
}

std::set<int> KreirajSkup(std::string s, std::string element){
    std::set<int> skup;
	int i = s.find(element);
	while(i != std::string::npos)
	{
		skup.insert(i);
		i =s.find(element, i + element.size());
	}
    return skup;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> rez;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::vector<std::string> v(KreirajVektor(s));
  
    for(auto i=v.begin();i!=v.end();i++){
        std::string pomocna=*i;
        std::set<int> skup(KreirajSkup(s,pomocna));
        rez.insert(std::make_pair(pomocna, skup));
    }
    
    return rez;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>>m){
    std::set<int> skup;
    auto it=m.find(rijec);
    if(it==m.end())throw std::logic_error("Pojam nije nadjen");
    else skup=it->second;
    return skup;
}


void IspisiIndeksPojmova(std::map<std::string,std::set<int>> m){
    for(auto it=m.begin(); it!=m.end();it++){
        std::cout<<it->first<<": ";
        for(auto it2=it->second.begin();it2!=it->second.end();it2++){
        std::cout<<*it2;
        auto uslov(it->second.end());
        uslov--;
        if(it2!=uslov) std::cout<<",";
    }
    std::cout<<std::endl;
    }
}

void IspisiSkup(std::set<int> skup){
    for(auto x: skup){
        std::cout<<x<<" ";
    }
}
int main(){
    
    std::cout<<"Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> mapa(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(mapa);
    std::string unos, kraj(".");
    while(std::cout<<"Unesite rijec: ",std::getline(std::cin, unos),unos!=kraj){
    try{
    std::set<int> skup(PretraziIndeksPojmova(unos,mapa));
    IspisiSkup(skup);
    std::cout<<std::endl;
    }
    
    catch(std::logic_error msg){
        std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
    }
    }
    return 0;
}

int main2 ()
{
    std::string test="abc qwe stsda abc abc dhi qwe hrkw dhi";
    std::string test2="abc";
    std::map<std::string,std::set<int>> rez;
    std::vector<std::string> rijeci(KreirajVektor(test));
    std::string output(test);
/*    std::sort(rijeci.begin(), rijeci.end());
    int broj = std::unique(rijeci.begin(), rijeci.end()) - rijeci.begin();
    rijeci.resize(broj);*/
    for(auto x: rijeci){
        std::cout<<x<<" ";
    }
    
    std::set<int> mapa(KreirajSkup(test2, test));
    for(auto x: mapa){
        std::cout<<x<<" ";
    }
    
    
	return 0;
}