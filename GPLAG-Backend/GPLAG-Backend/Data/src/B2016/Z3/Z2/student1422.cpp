/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <stdexcept>
#include <cctype>

typedef std::string string;
typedef std::map<std::string,std::set<int>> map;
typedef std::set<int> set;

bool IsAlpha(char slovo){
    if((slovo>='a' && slovo<='z')||(slovo>='A' && slovo<='Z'))
    return true;
    return false;
}

bool IsNumber(char znak){
    if(znak>='0' && znak<='9')
    return true;
    return false;
}

bool SveMala(string rijec){
    int i(0);
    while(i!=int(rijec.length())){
        if(rijec[i]>='A' && rijec[i]<='Z') return false;
        i++;
    }
    return true;
}

string PretvoriUMala(string rijec){
    int i(0);
    while(i!=int(rijec.length())){
        rijec[i]=std::tolower(rijec[i]);
        i++;
    }
    return rijec;
}

set PretraziIndeksPojmova(string rijec, map m){
    auto it(m.find(rijec));
    if (it==m.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    return m[rijec];
}

bool ImaUMapi(string kljuc, map m){
    auto it(m.find(kljuc));
    if (it==m.end()) return false;
    return true;
}

map KreirajIndeksPojmova(string tekst){
    int i(0),j(0);
    map m;

    while(i!=int(tekst.length())){
        int pocetak(i);
        while(j!=int(tekst.length())){
            if(j==int(tekst.length())-1 || ((!IsAlpha(tekst[j])) && !(IsNumber(tekst[j])))){
                int kraj(j);
                if(j==int(tekst.length())-1) kraj++;
                 string tmp(tekst.substr(pocetak, kraj-pocetak));
                 if(!(SveMala(tmp))) tmp=PretvoriUMala(tmp);
                if(!(ImaUMapi(tmp,m))) m[tmp].insert(pocetak);
                else{
                    auto it(m.find(tmp));
                    it->second.insert(pocetak);
                }
                j++; 
                break;
            }
            j++;
        }
        
        i=j-1;
        i++;
    }
    return m;
}

void IspisiIndeksPojmova(map m){
    for(auto it=m.begin();it!=m.end();it++){
        std::cout<<it->first<<": ";
        for(auto x:it->second){ 
            std::cout<<x;
            if(x!=*(--it->second.end())) std::cout<<",";
        }
        std::cout<<std::endl;
    }
}

int main (){
    string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,tekst);
    map m(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(m);
    string rijec;
    do{
        std::cout<<"Unesite rijec: ";
        std::cin.clear();
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        try{
            set skup(PretraziIndeksPojmova(rijec,m));
            for(auto x:skup) std::cout<<x<<" ";
            std::cout<<std::endl;
        }catch(std::logic_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }
    }while(1);
	return 0;
}