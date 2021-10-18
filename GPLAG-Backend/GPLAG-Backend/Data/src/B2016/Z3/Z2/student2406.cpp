#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <set>
#include <algorithm>
#include <array>
#include <stdexcept> 
#include <utility>

std::map<std:string,std::set<int>> KreirajIndeksPojmova(std::string x)
{
    try{
            std::map<std::string, std::set<int>> pomocna, povratna;       
            for(auto it(x.begin()); it!=x.end()-1;++it)
                {
                   { if(*it>='A' && *it<='Z')
                            *(it-x.begin())+=' ';
                   }
                }
                            std::set<std::string>rijeci; std::set<int> skup;
                            for(auto it1(x.begin()); it1!=x.end()-1;++it1)
                                {
                                 auto temp(it1); std::string strin_g;
                                    if((*it>='a'&&*it<='z')||(*it>='0'&&*it<='9'))                             
                                        do
                                            {
                                                it1++;
                                                strin_g=x.substr(it1,it1-temp);
                                            }                
                                        while(*it!=' ');
                                    rijeci.insert(strin_g);
                                }
                        }
                 for(int i(1);i<rijeci.size();i++){
                                for(int j(i-1);j<rijeci.size()-1;++j){
                                    if(rijeci[i]!=rijeci[j]){
                                          povratna.first.insert(rijec[j]); 
                                }
                                for(auto it(x.begin());it!=x.end();++it){
                                }
                        }
        }
    catch(std::logic_error &x)
        throw;
}
std::set<int> PretraziIndeksPojmova(std::string &s,std::map<std::string,std::set<int>> x)
{
    try{
for(auto it(x.begin());it!=x.end();it++)
     {    
    
     }   
    }
    catch(std::logic_error x)
        {
            throw;
        }
}
void IspisiIndeksPojmova(auto indekspojmova)
{

}
int main ()
{
    try
        {
            std::cout<<"Unesite recenicu: "
            std::string s; std::getline(std::cin,s);
            KreirajIndeksPojmova()
        }
    catch(std::logic_error &x)
        {
            std::cout<<"Pojam nije nadjen!"
        }
    return 0;
}