/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>imena, int broj){
    std::vector<std::set<std::string>> rez(broj);
    std::list<std::string> lista;
    std::copy(imena.begin(),imena.end(),back_inserter(lista));
    
    int vel=imena.size()/broj;
    
    while(lista.size()!=0){
      std::set<std::string> skup;
     while(skup.size()!=vel){
    for(auto i=lista.begin();i!=lista.end();){
        skup.insert(*i);
          lista.remove(*i);
      //  i=i+(i.size());
        while(pom!=i->length()){
            i++;
            pom++;
        }
    }
    }
    rez.push_back(skup);
    }
    return rez;
}

int main ()
{
    int n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    
    std::vector<std::string> v;
    std::string ime;
    std::cout<<"Unesite imena djece: \n";
    for(int i=0;i<=n;i++){
        std::getline(std::cin,ime);
        v.push_back(ime);
    }
    
    int br;
    std::cout<<"Unesite broj timova: ";
    std::cin>>br;
    
   std::vector<std::set<std::string>> rez=Razvrstavanje(v,br);
    
    for(int i=0;i<br;i++){
    std::cout<<"Tim "<<i+1<<": ";
 //   for(auto x: )
    
    }
	return 0;
}