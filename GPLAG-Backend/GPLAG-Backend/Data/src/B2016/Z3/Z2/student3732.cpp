/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>
std::map<std::string, std::set<int>> KreirajIndeksPojmova (const std::string &s)
{
    std::map<std::string, std::set<int>> mapa;
    for(unsigned int i=0; i<s.length(); i++){
        if(isalpha(s[i])){       //biblioteka cctype
            std::set<int> skup;
            std::string temp; 
            while(s[i]!=' ' && i<s.length()){
                temp.push_back(s[i]);
                i++;
            }
            auto p(mapa.find(temp));
            if(p!=mapa.end()) p->second.insert(i-temp.size());
            else {
                skup.insert(i-temp.size());
                mapa.insert(std::pair<std::string, std::set<int>>(temp,skup));
            }
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (const std::string &s, std::map<std::string, std::set<int>> mapa){
    auto p(mapa.find(s));
    if(p==mapa.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    return p->second;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa){
   for(std::map<std::string, std::set<int>>::iterator p(mapa.begin()); p !=mapa.end(); p++)
   {
        std::cout<< p->first <<": ";
        int i(0);
        for(std::set<int>::iterator q(p->second.begin()); q!=p->second.end(); q++, i++){
            std::cout<<*q;
            if(i!=int (p->second.size())-1) 
            std::cout<<",";
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string s; 
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
	auto Indeks(KreirajIndeksPojmova(s));
	IspisiIndeksPojmova(Indeks);
	std::vector<std::string> v;
	for(;;)
	{   
	    std::cin>>s;
	    if(s==".")break;
	    v.push_back(s);
	}
	for(std::string s:v) 
	        try {
	            std::cout<<"Unesite rijec: ";
	            auto p(PretraziIndeksPojmova(s, Indeks));
	            for(int q:p)
	            std::cout<<q<<" ";
	            std::cout<<std::endl;
	        }catch (std::logic_error izuzetak){
	        std::cout<<izuzetak.what()<<std::endl;
	    }
	//    std::cout<<"Unesite rijec: ";
	return 0;
}