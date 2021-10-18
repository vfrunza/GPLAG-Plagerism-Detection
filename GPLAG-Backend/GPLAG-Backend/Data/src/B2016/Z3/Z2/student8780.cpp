/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <iterator>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>

// Ako se pojavljuje rijec više od jedanput - nije OK !

std::set<int> NadjiPoziciju (std::string tekst,std::string rijec)
{
    int pozicija;
    bool isti (false);
    auto itrijec(rijec.begin());
    std::set<int> pozicije;
    auto iterat(tekst.begin());
    auto rj(rijec.end());
    rj--;
    
    
    if (*rj==' ') rijec.erase(rijec.begin()+(rijec.size()-1));
    for (auto it= tekst.begin();it!=tekst.end();it++)
    {
        bool isti=false;
        pozicija=0;
        itrijec=rijec.begin();
    
         
          if (*itrijec==*it)
        {
      
          pozicija=it-iterat;
            isti=true;
            
            if (rijec.size()==1)
            {
                it--;
                if ((*it>=32 && *it<=47) || (*it>=58 && *it<=64) || *it==' ') 
                {
                    pozicije.insert(pozicija);
                    isti=false;
                }
            }
          
            for (int i=0;i<rijec.size();i++)
            {
                
                if (rijec.size()==1) break;
            
                if (*itrijec!=*it) 
                {
                    
                    isti=false;
                    break; 
                    
                }
                itrijec++;
                 it++;
                 
            }
            if (rijec.size()==1) {it++;}
            
        }
        if (isti) {if (*it<'A' || (*it<'a' && *it>'Z')|| (*it>'z')) pozicije.insert(pozicija);}
        if (*it=='\0') break;
   
        
    }
    
    return pozicije; 
}

std::vector <std::string> NadjiRijeci(std::string tekst)
{
    std::string rijec;
    std::string razmak(" ");
    std::vector<std::string> rijeci;
    bool kraj (false);
    int broj_rijeci(1);
    int broj_slova(0);
    
   for (int i=0;i<tekst.size();i++)
   {
       if ((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>=48 && tekst[i]<=57)){
           kraj=true;
       }
       else if (kraj==true)
       {
           kraj=false;
           broj_rijeci++;
       }
   }
   
   
       for (int j=0;j<=tekst.size();j++)
       {
           if ((tekst[j]>='a' && tekst[j]<='z') || (tekst[j]>=48 && tekst[j]<=57))
           {
               rijec.push_back(tekst[j]);
               kraj=true;
           }
           else if (kraj==true)
           {
               kraj=false;
               rijeci.push_back(rijec);
               rijec.resize(0);
           }
       }
       

    return rijeci;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string tekst)
{
   std::map<std::string,std::set<int>> Indeks_pojmova;
  
  std::set<int> pozicije;
  std::vector<std::string>rijeci ;
  
         rijeci=NadjiRijeci(tekst);
         
          for (int i=0;i<tekst.length();i++)
          {
              if(tekst[i]<'a' && tekst[i]>'A') tekst[i]+='a'-'A'; 
          }
          rijeci=NadjiRijeci(tekst);
           
           for (int i=0;i<rijeci.size();i++)
           { if (i==rijeci.size()-1) break;
               for (int j=i+1;j<rijeci.size();j++)
               {
                   if (rijeci[i]==rijeci[j])    
                   {
                       rijeci.erase(rijeci.begin()+j);
                       if (i!=0) i--;
                   }
               }
           }
           
             for (int i=0;i<rijeci.size();i++)
             {
                 pozicije=NadjiPoziciju(tekst,rijeci[i]);
                 Indeks_pojmova.insert(std::make_pair(rijeci[i],pozicije));
             }
  
  
  
  
  return Indeks_pojmova;
}

std::set<int> PretraziIndeksPojmova (std::string rijec,std::map<std::string,std::set<int>> indekspojmova)
{
    
    std::set<int> pozicije ;
   auto it (indekspojmova.begin()); // ovdje dolazi do greške
    it=indekspojmova.find(rijec);
    if (it==indekspojmova.end()) throw std::logic_error ("Unesena rijec nije nadjena!");     // pri drugom pozivu funkcije it ne pokazuje na rijec u indeksu, iako postoji
    else         for(int a: it->second) pozicije.insert(a);
    
    return  pozicije;
}

void IspisiIndeksPojmova (std::map<std::string,std::set<int>> indekspojmova){

   for (auto it = indekspojmova.begin();it!=indekspojmova.end();it++)
   {
       std::cout << it->first << ": " ;
       for (auto p=it->second.begin();p!=it->second.end();p++){
        auto po (it->second.end()); 
        po--;
      
         if (p==po) std::cout << *p;
         else   std::cout << *p<< ",";   
      
      
   } std::cout << std::endl;
    
}
}



int main (){
    
    try{
        std::cout << "Unesite tekst: ";
        std::string tekst;
        std::getline (std::cin,tekst);
        
        std::map<std::string,std::set<int>> indekspojmova(KreirajIndeksPojmova(tekst));
         IspisiIndeksPojmova(indekspojmova);  
         std::string rijec;
         std::set<int> pozicija;
         
        do{
          std::cout << "Unesite rijec: ";
          std::getline(std::cin,rijec);
          if (rijec==".") break; 
          pozicija=PretraziIndeksPojmova(rijec,indekspojmova);
          for (auto x: pozicija) std::cout << x << " " ;
          std::cout << std::endl;
        }while(rijec!=".");
     }catch (std::logic_error izuzetak){
        std::cout <<izuzetak.what()<< std::endl;
        std::cout<<"Unesite rijec: ";
    }        
	return 0;
}