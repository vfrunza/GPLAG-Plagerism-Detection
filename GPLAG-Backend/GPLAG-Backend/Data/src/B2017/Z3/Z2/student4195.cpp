/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>



bool Prekid (char c)
{
    int a = int(c);
    return 
    !(
     (a >= 48 && a <= 57)
     ||
     (a >= 65 && a <= 90)
     ||
     (a >= 97 && a <= 122)
    );
}
               //poglavlje                 //sadrzaj
typedef std::map<std::string , std::vector<std::string>> Knjiga;

                                        //poglavlje    //brstr //pozicija               //mozda ref
std::map<std::string,std::set<std::tuple< std::string, int, int>>> KreirajIndeksPojmova (Knjiga k)
{


    std::map<std::string, std::set<std::tuple <std::string , int, int >>> m;

    std::set<std::tuple <std::string , int, int >> mt;
         
         
    for(auto it=k.begin();it!=k.end();it++){
        
        for(int vi=0; vi < (it->second).size(); vi++){
            
            std:: string s = " " + (it->second).at(vi) + " ";
            std:: string w = "";
            int wi;
            
            for(int i=0; i<s.size(); i++){
              s.at(i) =  std::tolower(s.at(i));
                if (Prekid(s.at(i))) {
                    if (w!="") {
                        mt = m[w];
                        mt.insert(std::make_tuple(it->first, vi+1, wi-1) );
                        m[w] = mt;
                        w = "";
                    }
                    
                }
                else {
                    if (w=="") {
                        wi = i;
                    }
                    
                    w = w + s.at(i);
                }
            }
        }
        
        
        
    }      
        
    return m;   
        
}




std::set<std::tuple <std::string , int, int >>  PretraziIndeksPojmova(std::string s,  std::map<std::string,std::set<std::tuple< std::string, int, int>>>L)

{
    if(!L.count(s)) throw std::logic_error ("Unesena rijec nije nadjena");

    else return L[s];
    
}




void IspisiIndeksPojmova (std::map<std::string,std::set<std::tuple< std::string, int, int>>> M)

{
    
 std::set<std::tuple <std::string, int,int >> mt;

 for(auto it=M.begin(); it!=M.end();it++){
    mt = it->second;
    std::cout<<it ->first <<": ";
    for(auto iter=mt.begin();iter!=mt.end();){
        std::cout<<std::get<0>(*iter)<<"/"<<std::get<1>(*iter)<<"/"<<std::get<2>(*iter);
        iter++;
        if (iter != mt.end()) std::cout<<", ";
        else std::cout<<std::endl;
    }
 }

}


void Test3 (std::set<std::tuple <std::string, int,int >> mt)

{
    
    for(auto iter=mt.begin();iter!=mt.end();){
        std::cout<<std::get<0>(*iter)<<"/"<<std::get<1>(*iter)<<"/"<<std::get<2>(*iter);
        iter++;
        if (iter != mt.end()) std::cout<<", ";
        else std::cout<<std::endl;
    }

}



int main ()
{
    
    //try{
    Knjiga k;
    std::vector<std::string> vek;
    std::string stranica;
    while(1){
        int i=1;
    std::string pog;
    
    std::cout<<"Unesite naziv poglavlja: ";
    std::getline(std::cin,pog);
    
    if(pog==".") break;
            do {
                
                
                std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
                
                std::getline(std::cin,stranica);
                if(stranica==".") break;
                vek.push_back(stranica);
                i++;
                
                
            }while(1);
            
        k[pog]=vek;
    
    }
    
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    
    
    //std::map<std::string,std::set<std::tuple< std::string, int, int>>> rez=KreirajIndeksPojmova(vek);
    IspisiIndeksPojmova(KreirajIndeksPojmova(k));
    std::cout<<std::endl;
    
    
    do {
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec=="." ) break;
        
        
         try {
        
     auto   rez=PretraziIndeksPojmova(rijec,KreirajIndeksPojmova(k));
        for(auto it=rez.begin(); it!= rez.end();it++)
        {
            
            
             std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it);
            if((it)!=rez.end()) std::cout<<" ";     
             
        }
        std::cout<<std::endl;
        
        
        
        
        }
        catch(std::logic_error){
            
            
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
}while(1);
  
  
    
    
   
	return 0;
}
