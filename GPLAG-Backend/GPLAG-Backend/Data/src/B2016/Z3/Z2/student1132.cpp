/B2016/2017: Zadaća 3, Zadatak 2
#include<iostream>
#include<set>
#include<map>
#include<string>
#include<stdexcept>
#include<cctype>
bool ok(char x){return (x>='A'&&x<='Z') || (x>='a'&&x<='z') || (x>='0'&&x<='9');}
std::string u_mala(std::string s)
{
    for(auto& e: s) e = std::tolower(e);
    return s;
}
std::map<std::string,std::set<int> > KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int> > mapa;
    std::string a;
    for(int i=0;; i++)
    {
        if(i==s.size() || !ok(s[i])) 
        {
            if(a != "") 
            {
                mapa[u_mala(a)].insert(i-a.size());
                a = "";
            }
            if(i == s.size()) break;
        }
        else if(ok(s[i])) a += s[i];
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int> >& mapa)
{
    if(mapa.count(u_mala(s)) == 0) throw std::logic_error("Pojam nije nadjen");
    else return mapa[u_mala(s)];
}
void IspisiIndeksPojmova(const std::map<std::string,std::set<int> >& mapa)
{
    for(auto par: mapa)
    {
        std::cout<<par.first<<": ";
        auto skup = par.second;
        for(auto e: skup) 
        {
            if(e != *skup.rbegin()) std::cout<<e<<",";
            else std::cout<<e;
        }
        std::cout<< std::endl;
    }
}
int main ()
{
    std::cout<< "Unesite tekst: ";
	std::string s;
	std::getline(std::cin, s);
	auto mapa = KreirajIndeksPojmova(s);
	IspisiIndeksPojmova(mapa);
	for(;;)
	{
	    std::cout<<"Unesite rijec: ";
	    std::getline(std::cin, s);
	    if(s == ".") break;
	    try
	    {
	        auto skup = PretraziIndeksPojmova(s, mapa);
	        for(auto e: skup) std::cout<< e<< " ";
	        std::cout<< std::endl;
	    }
	    catch(std::logic_error e)
	    {
	        std::cout<<"Unesena rijec nije nadjena!\n";
	    }
	}
	return 0;
}