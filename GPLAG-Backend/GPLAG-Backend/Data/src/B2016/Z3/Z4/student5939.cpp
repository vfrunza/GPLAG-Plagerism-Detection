/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int duzina__rijeci(std::string s){
    int brojac = 0;
    for(auto c: s){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') )brojac++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    
    if(k<1 || k>v.size())throw std::logic_error("Razvrstavanje nemoguce");
    
    int vel = v.size();                               //23 i 3
    int br_prvih_timova = vel%k;                     //2
    int br_clanova1 = vel/k+1;                       //8
    int br_clanova2 = vel/k;                         //7
    
    std::list<std::string> lista;
    lista.insert(lista.begin(),v.begin(),v.end());
   // for(auto p: lista)std::cout<<p<<" ";
   
    std::vector<std::set<std::string>> t;
    t.resize(k);
    

    int tr_vel = 0;
    auto p = lista.begin();
    /*
        for(int i=0;i<br_prvih_timova;i++){
            for(int j=0;j<br_clanova1;j++){
                
                if(i==0 && j==0){
                t[i].insert(*lista.begin());
                tr_vel = (*lista.begin()).length();
                lista.erase(lista.begin());
                p = lista.begin();
                }else{
                   // advance(p,brojac);
                for(k=0;k<tr_vel-1;k++){
                    if(p == lista.end())p=lista.begin();
                    p++;
                    if(p == lista.end())p=lista.begin();
                }
                //std::cout<<tr_vel<<" "<<*p<<std::endl;
                t[i].insert(*p);
                tr_vel = (*p).size();
                int brojac = distance(lista.begin(),p);
                lista.erase(p);
                p = lista.begin();
                advance(p,brojac);
                }
            }
    }*/

    
    //>SVE 2
    for(int i=0;i<k;i++){
            for(int j=0;(i>=br_prvih_timova) ? (j<br_clanova2) : (j<br_clanova1);j++){
                
                if(i==0 && j==0){
                t[i].insert(*lista.begin());
                //tr_vel = (*p).size();
                tr_vel = duzina__rijeci(*p);
                p = lista.erase(lista.begin());
                
                
                }else{
                    
                for(int h=0;h<tr_vel-1;h++){
                    if(p == lista.end())p=lista.begin();
                    p++;
                    if(p == lista.end())p=lista.begin();
                }
                t[i].insert(*p);
                //tr_vel = (*p).size();
                tr_vel = duzina__rijeci(*p);
                p = lista.erase(p);
                
                }
            }
    }
    
    return t;
}


int main ()
{
  std::cout<<"Unesite broj djece: ";
  int br;
  std::cin>>br;
  std::cin.ignore(1,'\n');
  if(br<0)return 0;
  std::cout<<"Unesite imena djece: \n";
  
  std::vector<std::string> v(br);
  for(int i=0;i<br;i++){
      std::getline(std::cin,v[i]);
      
  }
   //std::cin.ignore(1000,'\n');
  int k;
  std::cout<<"Unesite broj timova: ";
  std::cin>>k;
 
  
  std::vector<std::set<std::string>> t;
  try{
       t = Razvrstavanje(v,k);
  }catch(std::logic_error temp){
      std::cout<<"Izuzetak: "<<temp.what()<<std::endl;
      return 0;
  }
  
  
  for(int i=0;i<k;i++){
      std::cout<<"Tim "<<i+1<<": ";
      auto q = t[i].begin();
      int vel = t[i].size();
      for(int j=0;j<vel-1;j++)q++;
      
      for(auto p = t[i].begin();p!=t[i].end();p++){
          if(p != q)std::cout<<*p<<", ";
          else std::cout<<*p<<std::endl;
      }
  }
	return 0;
}













