/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <set>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> m;
    
    for(int i=0; i<s.length(); i++)
    {
        std::set<int> skup;
        std::string pom;
        while(i < s.length() ) if(s[i] == ' ' || !(s[i] >='A' && s[i] <= 'Z' || s[i] >='a' && s[i] <= 'z' || s[i] >='0' && s[i] <= '9'))i++; else break;
        
        while(i < s.length())
            {           
                if(s[i] >='A' && s[i] <= 'Z') s[i]=s[i]+ 32; 
            else if(s[i] >='A' && s[i] <= 'Z' || s[i] >='a' && s[i] <= 'z' || s[i] >='0' && s[i] <= '9')  pom.push_back(s[i++]); else break;
            }
            auto p(m.find(pom));
          //  std::cout<<pom<<std::endl;
            if(p != m.end())
            {
                p->second.insert(i-pom.size());
            }
            else
            {
                skup.insert(i-pom.size())   ; 
                m.insert(std::pair<std::string, std::set<int>>(pom, skup));
            }
    }
    return m;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> m)
{
    auto p(m.find(s));
    if(p == m.end()) throw std::logic_error("Pojam nije nadjen"); //ako nije pronadjena u mapi
    return p->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m){
    for( auto it=m.begin(); it!=m.end(); it++)
    {
        std::cout<<it->first<<": ";
        int brojac(0);
        int i = 0;
        for(std::set<int>::iterator it1 = it->second.begin();  it1 != it->second.end(); it1++)   brojac++;
        for(std::set<int>::iterator it1 = it->second.begin();  it1 != it->second.end(); it1++){
        
    if(i < brojac - 1) std::cout<<*it1 <<","; else std::cout<<*it1;
    i++;
        }
        
        std::cout<<std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
   std::string s,pom;
   //std::string s { "abc qwe stsda abc abc dhi qwe hrkw dhi"},pom;
    //std::string s{"  pqr,  ab/123 (qwe) tt2 "};
    std::getline(std::cin, s);
    auto indeks_pojmova(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(indeks_pojmova);
    while(1){
        std::cout<<"Unesite rijec: ";
        std::cin>>pom;
        if(pom==".") return 0;
        try{
            auto skup = PretraziIndeksPojmova(pom,indeks_pojmova);
            for(auto x : skup) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<"Unesena rijec nije nadjena!\n";
        }
    }
}
