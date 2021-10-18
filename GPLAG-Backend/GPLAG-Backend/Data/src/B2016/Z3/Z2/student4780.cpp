/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <set>

bool Funkcija(char znak){
    if((znak>='0' && znak<='9')|| (znak>='a' && znak<='z') )
    return true;
    return false;
}

void Funkcija2(std:: string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i]>='A' && s[i]<='Z')s[i]+=32;
    }
}

void Funkcija3(std::set<int> &ret2){
    auto r=ret2.begin();
    while(ret2.begin()!=ret2.end())
    r=ret2.erase(r);
}

bool Funkcija4(std::string ret1,std::string indeks, int i){
    int velicina=ret1.size();
    int kraj=indeks.size()-1;
    if((indeks.substr(i,velicina)==ret1) && (i==0  || !Funkcija(indeks[i-1]))  && (i==kraj  || !Funkcija(indeks[i+velicina]))) return true;
    return false;
}


std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string indeks ){
    std::string ret1;
    int p=1;
    std::set<int>ret2;
    std::map<std::string, std::set<int>>ret;
    Funkcija2(indeks);
    for(int i=0; i<indeks.size(); i++){
    if(!Funkcija(indeks[i])) p=1;
    else 
    if(p==1){
        p=0;
        Funkcija3(ret2);
     ret1.resize(0);
    while(Funkcija(indeks[i])){
        if(i==indeks.size()) break;
        ret1+=indeks[i];
        i++;
    }
    for(int k=0; k<indeks.size(); k++)
    if(Funkcija4(ret1, indeks, k))
    ret2.insert(k);
    ret.insert(make_pair(ret1,ret2));
    i--;
    }
    }
    return ret;
}

    
std::set<int>PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<int>>pojmovi){
    auto i=pojmovi.find(rijec);
    Funkcija2(rijec);
    std::set<int> sk;
    if(i==pojmovi.end()) 
     throw std::logic_error("Unesena rijec nije nadjena!");
    for(auto &j: pojmovi){
        if(rijec==j.first)sk=j.second;
    }
    return sk;
}

void IspisiIndeksPojmova(const std::map<std::string, std::set<int>> &pojmovi){
    for(auto &i : pojmovi ){
        std::cout<<i.first<<": ";
        auto zadnji=max_element(i.second.begin(), i.second.end());
    for(auto &j: i.second){
        if(j==*zadnji){
            std::cout<<j;
        }
        else{
            std::cout<<j<<",";
        }
    }
    std::cout<<std::endl;
    
    
    
}
    
}





int main()
{
    std::set<int> skup;
    std::string text,rijec;
    std::cout<<"Unesite tekst: ";
    getline(std::cin, text);
    std::map<std::string, std::set<int>>poojmovi=KreirajIndeksPojmova(text);
    IspisiIndeksPojmova(poojmovi);
    while(1){
        std::cout<<"\nUnesite rijec: ";
        std::cin>>rijec;
        if(rijec==".")return 0;
        try{
            skup=PretraziIndeksPojmova(rijec,poojmovi);
           for(auto x: skup)
           std::cout<<x<<" ";
            std::cout<<std::endl;
        
        }
        catch(std::logic_error l){
            std::cout<<l.what();
        }
    }
	return 0;
}

