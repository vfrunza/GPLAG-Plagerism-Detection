/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>
#include <iterator>
#include <string>


struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> dijete,int broj_timova)
 {
     if (broj_timova<1 || broj_timova>dijete.size()) throw std::logic_error ("Razvrstavanje nemoguce");
     std::vector<std::set<std::string>> timovi;
     int broj_djece(dijete.size());
     int prvi(broj_djece%broj_timova);
     int clanovi (prvi+1);
     
  
     
     
     // kreiranje liste
     Dijete *imena (new Dijete[dijete.size()]);
    for (int i=0;i<dijete.size() ;i++)
    {
  
     if (i==dijete.size()-1) imena[i].sljedeci=&imena[0];
     else imena[i].sljedeci=&imena[i+1];
    }
    
    std::set<std::string>::iterator it;
    Dijete *pocetak (nullptr);
    Dijete *prethodni; 
      for (int k=0;k<broj_timova;k++)
      {
          std::set<std::string> tim;
          tim.insert (dijete[0]);
           Dijete *pokazivac;
           pokazivac[k].sljedeci=&imena[0]; 
          if (k<prvi)
          {
              for (int i=0;i<(broj_djece/broj_timova)+1;i++)
              {
                 Dijete *novi=nullptr;
                 novi = new Dijete;
                 novi->ime=imena[i];
                 novi->sljedeci=nullptr;
                 if (!pocetak) pocetak=novi;
                 prethodni->sljedeci=novi;
                 prethodni=novi;
                 
                  /*// gdje pokazuje sljedeci ubaci u set
                  
                 tim.push_back((pokazivac[i].sljedeci));         // GREŠKA !
                  
                  // sljedeci se preusmjerava tako da ne pokazuje na to mjesto nego na sljedeci
                  
                 pokazivac[i].sljedeci=pokazivac[i+1].sljedeci;
                  
                  // delete sljedeci
                  
                  delete pokazivac; */
              }
                
                
          timovi[k]=tim;
              
          }
          
          else
          {
                 for (int i=0;i<(broj_djece/broj_timova);i++)
              {
                  // gdje pokazuje sljedeci ubaci u set
                  
                       // GREŠKA !
                  
                  // sljedeci se preusmjerava tako da ne pokazuje na to mjesto nego na sljedeci
                  
                 pokazivac[i].sljedeci=pokazivac[i+1].sljedeci;
                  
                  // delete sljedeci
                  
                  delete pokazivac;
              }
                
                
              timovi[k]=tim;
          }
          
      }
      
      return timovi;
      
 }





int main ()
{
    try
{
   int broj_djece;
   int broj_timova;
   std::cout << "Unesite broj djece: ";
   std::cin >> broj_djece;
   std::vector<std::string> djeca;
   
   std::cout << "Unesite imena djece: ";
   
   for (int i=0;i<broj_djece;i++)
   {
       std::string ime;
       std::getline(std::cin,ime);
       djeca.push_back(ime);
    }
   
   std::cout << "Unesite broj timova: ";
   std::cin >> broj_timova;
   
    std::vector<std::set<std::string>> timovi(Razvrstavanje(djeca,broj_timova));
    
    for (int i=0;i<broj_timova;i++)
    {
        std::cout << "Tim "<< i+1 << ": ";
        for (auto x:timovi[i]) std::cout << x << ", ";
        std::cout << std::endl;
        
    }
}
   catch(std::logic_error izuzetak)
   {
       std::cout << izuzetak.what() << std::endl;
   }
   
	return 0;
}