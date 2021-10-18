/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <iterator>
#include <stdexcept>
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> dijete ,int broj_timova)
{
    
    if (broj_timova<1 || broj_timova>dijete.size()) throw std::logic_error ("Razvrstavanje nemoguce");

    std::list<std::string> imena;
    
    for (int i=1; i<dijete.size(); i++) 
    {
       imena.push_back(dijete[i]);
    }

    std::vector<std::set<std::string>> timovi (broj_timova);

   


    int broj_djece(dijete.size());
    int prvi (broj_djece%broj_timova);
    int clanovi (prvi+1);
    int preostali (prvi);
    int broj_koraka(0);
    std::string koraci;
  
    std::list<std::string>::iterator ite(imena.begin());
    std::list<std::string>::iterator pomocni(ite);
    for (int k=0;k<broj_timova; k++) {

        std::set<std::string>  tim;
         if (k==0) {tim.insert(dijete[0]);}
        if (k<prvi && prvi!=0 ) { 
            
            for (int i=0; i<broj_djece/broj_timova+1; i++) {
                if (imena.empty()) break;
              
            
              if (i==0 && k==0) continue;
              if (i==1 && k==0) {broj_koraka=dijete[0].length();}

                for (int j=1; j<broj_koraka; j++) {
                    if (ite!=imena.end())
                    {
                        ite++;
                        if (ite==imena.end()) j--;
                        
                    }
                    else {ite=imena.begin();}
                }
                koraci=*ite; // greška
                broj_koraka=koraci.length();
                for (int i=0;i<koraci.size();i++)
                {
                    if (koraci[i]==' ') broj_koraka--;
                }
                tim.insert(*ite);
                pomocni=ite;
               
                if (ite==imena.end()) ite=imena.begin();
                ite=imena.erase(pomocni);
                if (ite==imena.end()) ite=imena.begin();
            }
            timovi[k]=tim;
        } else {
            for (int i=0; i<broj_djece/broj_timova; i++) { 
             if (i==0 && prvi==0 && k==0) continue;
             if (i==1 && prvi==0 && k==0) {broj_koraka=dijete[0].length();}
              
                for (int j=1; j<broj_koraka; j++) { 
                    if (ite!=imena.end()) {
                        ite++;  
                        if (ite==imena.end()){ j--;} 
                        
                    } 
                    else ite=imena.begin();
                  }
                koraci=*ite; // greška
                broj_koraka=koraci.length();
                for (int i=0;i<koraci.length();i++)
                {
                    if (koraci[i]==' ') broj_koraka--;
                }
                tim.insert(*ite);
                pomocni=ite;
                
                if (ite==imena.end()) ite=imena.begin();
                ite=imena.erase(pomocni);
                if (ite==imena.end()) ite=imena.begin();
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
   std::vector<std::string> djeca(broj_djece); 
    std::cout << "Unesite imena djece: "<< std::endl;
    std::string ime;
for (int i=-1;i<broj_djece;i++)
    { 
        std::getline(std::cin,ime);
        if (i==-1) continue;
        djeca[i]=ime;
    }
    
    std::cout << "Unesite broj timova: ";
    std::cin >> broj_timova;
    
    std::vector<std::set<std::string>> timovi (Razvrstavanje(djeca,broj_timova));
    
    for (int i=0;i<broj_timova;i++)
    {
        std::cout << "Tim " << i+1 << ": ";
        
        for (auto it=timovi[i].begin();it!=timovi[i].end();it++){
            auto p(timovi[i].end());
            p--;
            if (it==p)std::cout << *it;
            else std::cout << *it << ", ";
        } std::cout << std::endl;
    }
       
        
    }
catch (std::logic_error izuzetak)
{
    std::cout << izuzetak.what() << std::endl;
}
    
    return 0;
}