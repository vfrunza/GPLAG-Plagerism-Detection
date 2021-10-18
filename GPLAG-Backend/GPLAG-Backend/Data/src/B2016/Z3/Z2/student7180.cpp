/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <set>
#include<cstring>

bool DaLiJeDobro(char a)
{
    if((a>='A' && a<='Z') || (a>='a' && a<='z') || (a>='0' && a<='9')) return true;
    return false;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s)
{
    for(int i=0; i<s.size(); i++)
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) s[i]=tolower(s[i]);
    
    std::map<std::string, std::set<int>> m;
    for(int k=0; k<s.size(); k++)
    {
        if(DaLiJeDobro(s[k]))
        {
            int pom1=k;
            while(k!=s.size() && DaLiJeDobro(s[k])) {k++;}
            int pom2=k;
            std::string s1=s.substr(pom1, pom2-pom1);
            std::set<int>p;
            for(int j=0; j<s.size(); j++)
                if(s.substr(j, s1.size())==s1 && (j==0 || !DaLiJeDobro(s[j-1])) && (s1.size()==s.size() || !DaLiJeDobro(s[j+s1.size()]))) p.insert(j);
                m.insert(make_pair(s1, p));
        }
    }
    return m;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> m)
{
    for(int i=0; i<s.size(); i++)
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) s[i]=tolower(s[i]);
    
    for(auto it=m.begin(); it!=m.end(); it++)
        if(it->first==s) return it->second;
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int> > m)
{
   for(auto it=m.begin(); it!=m.end(); it++)
   {
        std::cout<<it->first<<": ";
        int br=it->second.size();
        for(auto x: it->second)
        {
            if(br!=1) std::cout<<x<<",";
            else std::cout<<x;
            br--;
        }
        std::cout<<std::endl;
    }
}

int main ()
{
	std::string s;
	std::cout<<"Unesite tekst: ";
	std::getline(std::cin,s);
	auto m=KreirajIndeksPojmova(s);
	IspisiIndeksPojmova(m);
	for(;;)
	{
	    std::cout<<"Unesite rijec: ";
	    std::string p;
	    std::getline(std::cin,p);
	    if(p==".") break;
	    try{
	        std::set<int> pom=PretraziIndeksPojmova(p,m);
	        for(auto x: pom) std::cout<<x<<" ";
	        std::cout<<std::endl;
	    }
	    catch(std::logic_error)
	    {
	        std::cout<<"Unesena rijec nije nadjena!";
	        std::cout<<std::endl;
        }
	}
	return 0;
}
