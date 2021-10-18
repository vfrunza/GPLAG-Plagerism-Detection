/B2017/2018: Zadaća 6, Zadatak 4
#include <iostream>
#include <string>
#include <vector>


std::vector<int> Funkcija(std::string s)
{
    std::vector<int> v;
    
    std::string pom;
    
    
    std::string::iterator it1; 
    std::string::iterator it2;
    it1=it2=s.begin();
    
    int i(0);
    int cifra(0), broj(0);
    bool razmak, slovo(false);
    
    while(it1!=s.end())
    {
        
        if(*it1>='0' && *it1<='9')
        {
            
            it2=it1;
            
           // 
            it2++;
            while(*it2!=' ' && *it2!='\0')
            {
                if(*it2<'0' || *it2>'9')slovo=true;
                else slovo=false;
                
                
                //std::cout << *it2;
                
                it2++;
                
                
                
            }
            
            if(slovo==false)
            {
                pom[i]=*it1;
                std::cout << pom[i];
                i++;
            }
            
        }
        
        
        
        
        it1++;
    }
    
    
    
    
    return v;
}


int main ()
{
    std::string s;
    std::getline(std::cin, s);
    
    auto v(Funkcija(s));
    
   // for(int x:v)std::cout << x << " ";
    
	return 0;
}
