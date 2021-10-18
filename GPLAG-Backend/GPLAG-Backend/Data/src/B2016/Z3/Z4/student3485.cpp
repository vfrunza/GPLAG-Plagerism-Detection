/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <stdexcept>
#include <list>
#include <vector>
#include <iterator>


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v,int n){
    
    std::list<std::string> listaDjece;
   
    std::string s;
    int broj=v.size();
    if(n>broj || n<1) throw  std::logic_error("Izuzetak: Razvrstavanje nemoguce");
    int e=0;
    std::vector<std::set<std::string>> v1;
    v1.resize(n);
   
     
    for(int i=0;i<v.size();i++){
        listaDjece.push_back(v[i]);
    }
     auto it=listaDjece.begin();
     auto kraj=listaDjece.end();
     kraj--;
    int hasan=broj%n;
    for(int i=0;i<hasan;i++){
         
        for(int k=0;k<(int(broj/n)+1);k++){
        
        s="";
        
        s=*it;
      
         v1[e].insert(s);
        
      if(it!=kraj){
         it=listaDjece.erase(it);
         kraj=listaDjece.end();
         kraj--;
          
      }
      else {
          listaDjece.erase(it);
          it=listaDjece.begin();
          kraj=listaDjece.end();
         kraj--;
      }
        int brojac=0;
         for(int z=0;z<s.length();z++){
             if((s[z]>='0' && s[z]<='9') || (s[z]>='a' && s[z]<='z') || (s[z]>='A' && s[z]<='Z')) brojac++;
         }
         for(int j=0;j<brojac-1;j++){
             
             if(it==kraj) it=listaDjece.begin();
             else it++;
         }
        
            
        }
         e++;
    }
        
    
    
    
    for(int i=0;i<n-hasan;i++){
       
     for(int k=0;k<int(broj/n);k++){
        
             s="";
             
             s=*it;
             v1[e].insert(s);
             
            
            if(it!=kraj){
                 it=listaDjece.erase(it);
                 kraj=listaDjece.end();
                 kraj--;
            }
            
            else{
                  listaDjece.erase(it);
                  if(listaDjece.size()==0) goto ja;
                   it=listaDjece.begin();
                    kraj=listaDjece.end();
                 kraj--;
                
            }
            int brojac=0;
         for(int z=0;z<s.length();z++){
             if((s[z]>='0' && s[z]<='9') || (s[z]>='a' && s[z]<='z') || (s[z]>='A' && s[z]<='Z') ) brojac++;
         }
         for(int j=0;j<brojac-1;j++){
            
            if(it==kraj) it=listaDjece.begin();
            
            else it++;
         }
         
    }
    if(e==v1.size())break;
    e++;
}
        ja:
    return v1;
     
}





int main ()
{   std::vector<std::set<std::string>> v;
    int k=1,n,broj; 
    std::string s;
    std::vector<std::string>v1;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<broj;i++){
        s="";
        std::getline(std::cin,s);
      
        v1.push_back(s);
        
    }std::cout<<std::endl;
     
    std::cout<<"Unesite broj timova: ";
    std::cin>>n;
   try{ 
    v=Razvrstavanje(v1,n);
   
    for(int i=0;i<v.size();i++){
        auto it=v[i].begin();
        std::cout<<"Tim "<<k<<": ";
        while(it!=v[i].end()){
            std::cout<<*it++;
           
            if(it==v[i].end()) break;
            std::cout<<", ";
        }std::cout<<std::endl;
        k++;
    }}
    catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}