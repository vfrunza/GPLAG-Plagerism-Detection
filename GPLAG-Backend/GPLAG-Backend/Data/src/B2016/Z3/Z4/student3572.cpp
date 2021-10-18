/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stdexcept>
#include <list>

typedef std::vector<std::set<std::string>> vektor_skupova;
typedef std::list<std::string> list;

int Pomocna (std::string a){
  int  brojac {0};
  for(int i=0;i<a.length();i++)
   if((a[i] >='A' && a[i] <='Z') || (a[i] >='a' && a[i] <='z') || (a[i] >='0' && a[i] <='9')) brojac++;
   return brojac;
}

vektor_skupova Razvrstavanje(std::vector<std::string> djeca, int k){
    list lista;
    int n= djeca.size();
    if(k<1||k>n) throw std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    std::vector<int> timovi;
    for(int i=0;i<n%k;i++) timovi.push_back(n/k+1);
    for(int i=n%k;i<k;i++) timovi.push_back(n/k);
    for(auto x: djeca) lista.push_back(x);
    vektor_skupova d;
    auto it=lista.begin();
    int brojac{0};
   
    for(int i=0;i<timovi.size();i++){
        std::set<std::string> skup;
        for(int j=0;j<timovi[i];j++){
        
        for(int s=0;s<brojac;s++){
             it++;
           if(it==lista.end()) it=lista.begin();
        }
            brojac=Pomocna(*it);
            skup.insert(*it);
            it=lista.erase(it);
            if(it==lista.end()) it=lista.begin();
            
            brojac--;
          }
 d.push_back(skup);   
}
return d;
}

int main ()
{
     std::vector<std::string> djeca;
    int k,n;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cin.clear();
    std::cin.ignore(100000, '\n');
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0;i<n;i++){
        std::string x;
        std::getline(std::cin,x);
        djeca.push_back(x);
    }
    std::cout<<"Unesite broj timova: ";
    std::cin>>k;
    try{
    vektor_skupova d=Razvrstavanje(djeca,k);
    for(int i=0;i<d.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto it=d[i].begin(); it!=d[i].end();it++){
            std::cout<<*it;
            if(it!=--d[i].end()) std::cout<<", ";
        }
        std::cout<<std::endl;
     
    }
    }
    catch(std::logic_error e){
        std::cout<<e.what();
        return 0;
    }
    
	return 0;
}