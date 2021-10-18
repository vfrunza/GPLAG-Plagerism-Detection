/B2016/2017: Zadaća 3, Zadatakk 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

bool jelrijec(char a){
    if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))return true;
    return false;
}

char lower(char a){
    if(a>='A' && a<='Z')a=a-'A'+'a';
    return a;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> g){
    for(auto i=g.begin();i!=g.end();i++){
        std::cout<<i->first<<": ";
        for(auto j=(i->second).begin();j!=(i->second).end();){
            std::cout<<*j;
            if(++j!=(i->second).end())std::cout<<',';
        }
        std::cout<<'\n';
    }
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> a){
    std::string temp;
    for(auto i:s)temp=temp+lower(i);
    if(a.count(temp)==0){
        throw std::logic_error("Pojam nije nadjen");
    }
    return a[temp];
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> rjes;
    int poc=0;
    std::string pomocna;
    for(int i=0;i<s.size();i++){
        if(jelrijec(s[i])){
            if(pomocna.size()==0)poc=i;
            pomocna=pomocna+lower(s[i]);
        } 
        if(!jelrijec(s[i]) || i+1==s.size()){
            if(pomocna.size()!=0){
                rjes[pomocna].insert(poc);
            }
            pomocna="";
        }
    }
    return rjes;
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string a;
    std::getline(std::cin, a);
    auto g=KreirajIndeksPojmova(a);
    IspisiIndeksPojmova(g);
    do{
        std::cout<<"Unesite rijec: ";
        std::cin>>a;
        if(a==".")break;
        try{
            auto r=PretraziIndeksPojmova(a, g);
            for(auto i=r.begin();i!=r.end();i++){
                std::cout<<*i<<" ";
            }
        }
        catch(...){
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<"\n";
    }while(true);
	return 0;
}