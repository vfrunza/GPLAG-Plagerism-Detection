/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>

std::vector<std::string> Razvrstavanje(std::vector<std::string>s,int m){
     

  std::list<std::vector<std::string>> novi;
   novi.push_back(s);

/*std::list<std::vector<std::string>>::iterator it(novi.begin());
for(int i = 0; i<novi.size(); i++, it++)
{
     std::vector<std::string> test = *it;
     for(int j = 0; j<test.size(); j++)
          std::cout << test[j] << std::endl;
}
     */
     auto broj_djece=(s.size()/m);
     std::vector<std::string>tim;
     std::vector<std::string> naj;
     for(int i=0 ; i<m ; i++){
          
          std::list<std::vector<std::string>>::iterator it(novi.begin());
          for(int j=0 ; j<novi.size(); j++,it++){
               std::vector<std::string>neki=*it;
               int br(0);
               for(int k=0; k<neki.size(); k++){
                    br=neki[k].size();
                    tim=std::move(neki);
                   
               }
               j+=br;
               
               
          }
     }
     return tim;
     
}
int main ()
{
     std::vector<std::string>s;
     int n;
     
     std::cout<<"Unesite broj djece: ";
     std::cin>>n;
     
     
     std::string imena;
     std::cout<<"Unesite imena djece: ";
     std::getline(std::cin,imena);
     s.push_back(imena);
     for(int i=0;i<n;i++){
          std::getline(std::cin,imena);
          s.push_back(imena);
     }
     int m;
     std::cout<<"Unesite broj timova: ";
     std::cin>>m;
     
     std::vector<std::string> r;
     r=Razvrstavanje(s,m);
     
     for(int i=0;i<r.size();i++){
          std::cout<<r[i]<<" ";
     }
     
	return 0;
}