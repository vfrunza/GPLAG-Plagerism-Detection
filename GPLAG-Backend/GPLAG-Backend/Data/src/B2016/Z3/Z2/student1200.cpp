/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <iterator>
#include <string>
#include <stdexcept>

bool IsCharOrDigit(char x) {
	return (x>='a' && x<='z') || (x>='A' || x<='Z') || (x>='0' || x<='9');
}

typedef std::map<std::string,std::set<int>> decl_map;
decl_map KreirajIndeksPojmova(std::string s)
{ 
    decl_map m;
    for(int i(0);i<s.length();i++)
    {
        if((IsCharOrDigit(s[i]))
        { 
	  std::string temp;
          int pamti{i};
            while( i!=s.length()-1 && IsCharOrDigit(s[i]) )
            {
              temp.push_back(s[i]);
              i++;
            }
        i--;
        m[temp].insert(pamti);
        }
    }
    return m;
}

std::set<int> PretraziIndeksPojmova(std::string s,decl_map m)
{  
if(m.find(s)!=m.end())
	return m[s];
else throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(decl_map m)
{
     for(auto it = m.begin(); it!= m.end(); it++) {
        std::cout<<it->first<<": ";
        for(auto it2 = (it->second).begin(); it2!= (it->second).end();it2++) {
            auto tmp = it2;
            tmp++;
            if(tmp==(it->second).end()) std::cout<<*it2;
              else std::cout<<*it2<<",";
        }
        std::cout<<std::endl;
     }
}

int main()
{ decl_map m;
    std::string s;
    std::cout<<"Unesi recenicu:";
    std::getline(std::cin,s);
    m= KreirajIndeksPojmova(s);
   IspisiIndeksPojmova(m);
 while(true)
{ try{
    std::string trazi;
    std::cin>>trazi;
   std::cin.ignore(10000, '\n');
    if(trazi==".") break;
 auto skup(PretraziIndeksPojmova(trazi,m));
 for(auto it_skup(skup.begin());it_skup!=skup.end();it_skup++)
 {
     std::cout<<*it_skup;
    if(it_skup==--skup.end()) continue;
    else std::cout<<",";
 }
    std::cout<<std::endl;
    }
  catch(std::logic_error x)
    {
        std::cout<<x.what()<<std::endl;
        continue;
    }
}
    return 0;
}
