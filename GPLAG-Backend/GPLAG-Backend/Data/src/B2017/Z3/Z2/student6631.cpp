/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>
#include <iterator>
#include <type_traits>
#include <functional>
#include <utility>
#include <cstdio>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <cstring>





typedef std::map<std::string, std::vector<std::string>> Knjiga;
std::map<std::string, std::tuple<std::string, int, int>> mapa;
/*std::string pretvori (std::string s)
{
	for(int i=0;i<s.size();i++){
      if(s.at(i)>='a'&&s.at(i)<='z') s.at(i)-='a'-'A';
   }
	return s;
}*/
std::map<std::string, std::tuple<std::string, int, int>> &KreirajIndeksPojmova(Knjiga k)
{
   
    int br(0);
    
    for(auto it = k.begin(); it != k.end(); it++)
    {
        
        std::string S = it->first;
        std::vector<std::string>* v = &it->second;
        
        for(int i=0; i<it->second.size(); i++)
        {
            br++;
         //   char* s;
           /// s=&v[i][0];
            std::basic_string<char> s;
            int k(0);
             //auto c(v[i][0]);
               // c=v[i][0].c_str();
               // c = const_cast<char*>( v[i][0].c_str() );
           std::basic_string<char> c;
          if(i<it->second.size()) c = v[i][0];
            for(int j=0; j<v[i][0].length()-1; j++)
            {
            //    char* c;
              //  char *p;
              //  
                if(i<it->second.size() && j<v[i][0].length()-1)c = v[i][j];
            //    std::string::iterator c(v[i][j]);
                
                
               
                //std::cout << c;
           /* try
            {
                if(!stoi(c))
                throw std::invalid_argument("");
            }
            catch(std::invalid_argument izuzetak)
            {
                exit(0);
            }*/int f(0);
                while(c[f]!='\0')
                {
                if(c[f]!=' ')
                {
                  //  std::cout << *c;žstd::strcpy(v[i][0],c);
                    // std::strcmp(&s[k++],*c);
                  //  char x(stoi(c));
                    //char(x);
                    s[k++]=c[f];
                }
                else
                {
                    k=0;
                    
                    
                    
                    mapa.insert(std::make_pair(s, std::make_tuple(S,br,j)));
                    
                    s.erase (s.begin(), s.end());
                    
                    // for(auto it = mapa.begin(); it != mapa.end(); it++)std::cout << it->first << std::endl;
                }f++;
            }
            }
            
           // for(int j=0; j<)
        }
        
    }

    
    return mapa;
}

int main ()
{
    Knjiga k;
    int i(1);
    while(1)
    {
        std::cout << "Unesite naziv poglavlja: ";
        std::string s;
       
        std::getline(std::cin,s);
        if(s==".")break;
        
        
        
        
        std::vector<std::string> v;
        /*std::cin.clear();
        std::cin.ignore(10000,'\n');*/
        
        while(1)
        {
            std::cout << "Unesite sadrzaj stranice " << i++ <<": ";
            /*std::cin.clear();
            std::cin.ignore(10000,'\n');*/
            std::string s1;
            std::getline(std::cin,s1);
            if(s1==".")break;
            v.push_back(s1);
            
        }
    
        k.insert(std::make_pair(s,v));
        
    }
    
   // for(auto it = k.begin(); it != k.end(); it++)std::cout << "Poglavlje: " << it->first << std::endl;
   
    std::cout << "Kreirani indeks pojmova: " << std::endl;
    
    std::map<std::string, std::tuple<std::string, int, int>> &x(KreirajIndeksPojmova(k));
    
    for(auto it = x.begin(); it != x.end(); it++)std::cout << it->first << std::endl;
    
	return 0;
}
