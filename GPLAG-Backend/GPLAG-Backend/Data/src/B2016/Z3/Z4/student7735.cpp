#include <iostream>
#include <iterator>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

int Duzina(std::string ime){
    int brojac=0;
    for(int i=0;i<ime.size();i++){
        if ( ime[i]<'0' || (ime[i]>'9' && ime[i]<'A') || (ime[i]>'Z' && ime[i]<'a') || ime[i]>'z' )brojac++;
    }
    return ime.length()-brojac;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> &djeca,int br_timova){
    if(br_timova<1 || br_timova>djeca.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::list<std::string> imena_djece;
    std::vector<std::set<std::string>> v1;
    auto it1(imena_djece.begin());
    for(int j=0;j<djeca.size();j++) {imena_djece.insert(it1,djeca[j]);}
    auto it2(imena_djece.begin());
    int duz(0);
    int n(0);
    int prvi_timovi=(djeca.size()%br_timova);
    for(int j=0;j<br_timova;j++){
           n=djeca.size()/br_timova;
           if(j<prvi_timovi) n=(djeca.size()/br_timova+1);
           std::set<std::string> s1;
                for(int i=0;i<n;i++){
                s1.insert(*it2);
                duz=Duzina(*it2);
                if(it2==imena_djece.begin() && it2==imena_djece.end())break;
                it2=imena_djece.erase(it2);
                if(it2==imena_djece.end())it2=imena_djece.begin();
                for(int k=0;k<duz-1;k++){
                    it2++;
                    if(it2==imena_djece.end())it2=imena_djece.begin();
                }
        } 
       v1.push_back(s1);
      }
    return v1;
}
int main ()
{ 
   try{
   int n;
  std::vector<std::string> djeca {};
   std::cout << "Unesite broj djece: ";
   std::cin >> n;
   std::cin.clear();
   std::cin.ignore(100,'\n');
   std::cout << "Unesite imena djece: ";
   for(int i=0;i<n;i++){
       std::string s;
       std::getline(std::cin,s);
       while(s=="")std::getline(std::cin,s);
       djeca.push_back(s);
    }
   std::cout  << std::endl;
   int k;
   std::cout << "Unesite broj timova: ";
   std::cin >> k;
   std::vector<std::set<std::string>> v;
   std::set<std::string>ss;
   v=Razvrstavanje(djeca,k);
   int br=0;
   for(int i=0;i<v.size();i++){
       std::cout << "Tim "<<i+1<<": ";
       ss=v[i];
       br=0;
       for(auto x:ss){
           br++;
               if (ss.size()==br){
               std::cout<<x;
               break;
               }
           std::cout << x <<", "; 
       }
       std::cout << std::endl;
   }}
   catch(std::logic_error e){
       std::cout<<"Izuzetak: "<<e.what();
   }
   return 0;
}
