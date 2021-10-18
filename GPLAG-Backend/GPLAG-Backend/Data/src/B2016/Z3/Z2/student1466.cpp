/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <utility>

bool slovo(char s) {

      if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z' )|| ( s>= '0' && s <= '9')) return true;
      else return false;
      
      
   }

   
std::string svemaleno (std::string s) {
    
    for (int i = 0; i < s.length(); i++){
    if(s[i]>= 'A' && s[i]<= 'Z'  ) s[i]+=32;
    }
    return s;
    
}
 std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s) {

    std::map<std::string, std::set<int>> mapa;
    for (int i = 0; i < s.length(); i++){
                     std::set<int> setic;

       std::string pomocni;
while (slovo(s[i]) == false && i < s.length() ) { 
    i++;

    }
  while (slovo(s[i]) == true) { 
    
     pomocni+=s[i];
    i++;
    }

    for (int j = 0; j < s.length(); j++){
        
  std::string novi;
  while (slovo(s[j]) == false && j < s.length()) { 
    j++;
    }
if  (slovo(s[j]) == true) { int a=j;

    while (slovo(s[j]) == true) { 
    
    novi+=s[j];
    j++;
    }
    
        if (svemaleno(pomocni)==svemaleno(novi))     
  {  setic.insert(a);
            }

        }

    }
                                mapa.insert(std::make_pair(svemaleno(pomocni),setic));


       } 
return mapa;

    }
  
 
    
  std::set<int>  PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> r) {
s=svemaleno(s);
if(!r.count(s)) throw std::logic_error("Unesena rijec nije nadjena!");
else return r[s];

        }
        
        void IspisiIndeksPojmova (std::map<std::string, std::set<int>> r) {
for(auto it = r.begin(); it != r.end(); ++it ){
   std::cout << it->first << ": ";

    for(auto setov = it->second.begin(); setov != it->second.end(); ++setov) {
           setov++;
            auto pomocni=setov;
            setov--;
            if (pomocni==it->second.end()) std::cout << *setov << std::endl;
            else std::cout << *setov << ",";
}
}
}
int main ()
{
    
  
       
       std::cout<<"Unesite tekst: ";
       std::string tekst;
       getline(std::cin, tekst);

std::map<std::string, std::set<int>> r=KreirajIndeksPojmova(tekst);
IspisiIndeksPojmova(r);
std::string rijec;
std::cout<<"Unesite rijec: ";

std::cin>>rijec;
   if(rijec == ".") return 0;
while (rijec != ".") {
       
  try {      auto setic=PretraziIndeksPojmova(rijec,r);
 for (std::set<int>::iterator it=setic.begin(); it!=setic.end(); ++it)
     std::cout<< *it<<" ";
     std::cout<<std::endl;
}
  
catch(std::logic_error e)   {
    
    std::cout<<e.what()<<std::endl; 
       
       
   }
    std::cout<<"Unesite rijec: ";
    std::cin>>rijec;
   if(rijec == ".") return 0;
 
}

	return 0;
}