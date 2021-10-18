#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <stdexcept>
#include <utility>
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> m;
    for(auto i = s.begin(); i != s.end();)
    {
        for(auto it = s.begin(); it != s.end(); it++) *it = tolower(*it);
        std::string pom;
        while(1)
        {
            if((*i >= '0' && *i <= '9') || (*i >= 'A' && *i <= 'Z') || (*i >= 'a' && *i <= 'z')) {break;}
            else { if(i != s.end()) i++;}
        }
       // while(*i == ' ' && i != s.end()) i++;
        while(1)
        {
             if((*i >= '0' && *i <= '9') || (*i >= 'A' && *i <= 'Z') || (*i >= 'a' && *i <= 'z')){
                if(i != s.end()) pom.push_back(*i++);}
             else {break;}
        }
       // while(*i != ' ' && i != s.end()) {pom.push_back(*i); i++;};
       // for(auto it = pom.begin(); it != pom.end(); it++) tolower(*it);
        std::pair<std::string, std::set<int>> p;
        p.first = pom;
        auto brzi(i);
        int ii(0);
        while(brzi != s.end()) {brzi++; ii++;}
        int br = s.size() - ii - pom.size();
        std::set<int> sett;
        sett.insert(br);
        p.second = sett;
        auto it(m.find(pom));
        if(it == m.end()) m.insert(p);
        else (*it).second.insert(br);
    }
    return m;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> m)
{
    auto it(m.find(s));
    if(it == m.end()) throw std::logic_error("Pojam nije nadjen");
    return (*it).second;
}
void IspisiSet(std::set<int> s)
{
    auto pomocni(s.end());
    pomocni--;
    for(auto it = s.begin(); it != s.end(); it++) {
            if(it != pomocni) std::cout<<*it<<",";
    }
    std::cout<<*pomocni;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m)
{
    for(auto it = m.begin(); it != m.end(); it++)
    {
        std::cout<<it->first<<": ";
        IspisiSet(it->second);
        std::cout<<std::endl;
    }
}

int main()
{

    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> m(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(m);
    std::string temp;
    while(1)
    {

        std::cout<<"Unesite rijec: ";
        std::cin>>temp;
        if(temp == ".") break;
        try{
        std::set<int> novi = PretraziIndeksPojmova(temp, m);
        auto pomocni(novi.end());
        pomocni--;
        for(auto it = novi.begin(); it != novi.end(); it++) {
            if(it != pomocni) std::cout<<*it<<" ";
            }
         std::cout<<*pomocni;
         std::cout<<std::endl;
    }
    catch(std::logic_error l)
    {
        std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
    }
}
    return 0;
}

