#include <iostream>
#include<set>
#include<string>
#include<list>
#include<vector>
#include<iterator>
#include<stdexcept>

int broj_znakova (std::string s){
    int broj=0;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) broj++;
    }
    return broj;
}


std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string>v, int broj_timova){
    std::list<std::string> l;
    for(int i=0;i<v.size();i++){
        std::string ime;
        for(int j=0;j<v[i].size();j++)
           ime.push_back(v[i][j]);
       l.push_back(ime);
    }
    
    if(broj_timova<1 || broj_timova>l.size()) throw std::logic_error("Razvrstavanje nemoguce");
   std::vector<std::set<std::string> > vrati;
   vrati.resize(broj_timova);
   int mod=l.size()%broj_timova;
   int n=l.size();
   auto it=l.begin();
   int limit;
   for(int i=0;i<broj_timova;i++){
       if(i<mod) limit=(int) n/broj_timova+1;
       else limit=(int) n/broj_timova;
         std::set<std::string>s;
         for(int k=0;k<limit;k++){
             s.insert(*it);
             int brojac=1;
             int j=broj_znakova(*it);
             it=l.erase(it);
             if(it==l.end() && l.size()!=0) it=l.begin();
             while(brojac<j){ //za jedno mjesto vise
                 it++;
                 if(it==l.end() && l.size()!=0) it=l.begin();
                 brojac++;
             }
         }
          vrati[i]=s;
         
       }
   
  
   
   
   
   return vrati;
}

int main ()
{
    try{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece:\n";
    std::vector<std::string>v;
    v.resize(n);
    std::cin.ignore(1000,'\n');
    for(int i=0;i<n;i++){
        std::string s;
        std::getline(std::cin,s);
        v[i]=s;
    }
    
    std::cout<<"Unesite broj timova: ";
    int br;
    std::cin>>br;
    std::vector<std::set<std::string>> vrati=Razvrstavanje(v,br);
    for(int i=0;i<vrati.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
         auto zadnji=vrati[i].end();
            zadnji--;
        for(auto it=vrati[i].begin(); it!=vrati[i].end(); it++){
               if(it!=zadnji) std::cout<<*it<<", ";
               else std::cout<<*it;
            }
        std::cout<<std::endl;
    }
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    
	return 0;
}