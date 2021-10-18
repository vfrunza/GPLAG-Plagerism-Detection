/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int n)
{
   if(n < 1 || n > v.size())   throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
   std::vector<std::set<std::string>> tim(n); 
   std::vector<int> v1(n);
   if(v.size() % n == 0)
   {
       std::fill(v1.begin(), v1.end(), v.size() / n);
   }
   else
   {
       int pom(v.size() % n);
       for(int i=0; i<pom; i++) v1[i]= (v.size() / n) +1;
       for(int i=pom; i<v1.size(); i++) v1[i]= v.size() / n;
   }
   
   std::list<std::string> l;
   for(int i = 0; i < v.size(); i++)l.push_back(v[i]);
   auto it = l.begin();
   int k=0,j=0;
   for(int i = 0; i < (*it).size(); i++)
       if((*it)[i] >= 'A' && (*it)[i] <= 'Z' || (*it)[i] >= 'a' && (*it)[i] <= 'z' || (*it)[i] >= '0' && (*it)[i] <= '9') j++;
       
    tim[k].insert(*it);
    it = l.erase(it);
    int brojac(l.size());
    
    while (brojac) {
       for(int m = 0; m < j - 1 ; m++){
           it++;
           if(it  == l.end()) it = l.begin();
       }
       
       int br = 0;
       for(int i = 0; i < (*it).size(); i++)
           if((*it)[i] >= 'A' && (*it)[i] <= 'Z' || (*it)[i] >= 'a' && (*it)[i] <= 'z' || (*it)[i] >= '0' && (*it)[i] <= '9') br++;
        
           if(tim[k].size() < v1[k] ) {tim[k].insert(*it);    it = l.erase(it); brojac--;}
           if(tim[k].size() == v1[k])k++;
           j = br;
       if(it == l.end())it = l.begin();
    }
    return tim;
}

int main ()
{
    try{
    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::vector<std::string>v(broj_djece);
    std::cin.ignore (10000, '\n');
    std::cout<<"Unesite imena djece: ";
    for(int i=0; i<broj_djece; i++)
    {
        std::getline(std::cin, v[i]);
    }
    int broj_timova;
    std::cout<<std::endl;
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;

    auto tim = Razvrstavanje(v,broj_timova);
    
    for(int i = 0; i < tim.size(); i++){
        std::cout<<"Tim "<< i + 1<<": ";
        int br(tim[i]. size());
        int j=0;
        for(auto it : tim[i])
        {
            if(j < br -1) std::cout<<it<<", ";
            else std::cout<<it;
            j++;
        }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error e){
        std::cout<<e.what();
    }
	return 0;
}