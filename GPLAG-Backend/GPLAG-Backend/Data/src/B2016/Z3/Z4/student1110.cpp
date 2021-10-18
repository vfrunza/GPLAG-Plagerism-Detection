/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <stdexcept>

int BrojSlovaIBrojeva(std::string ime){
    int brojac(0);
    for(int i=0; i<ime.size(); i++){
        if((ime[i]>='a' && ime[i]<='z') || (ime[i]>='A' && ime[i]<='Z') || (ime[i]>='0' && ime[i]<='9'))brojac++;
    }
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> ImenaDjece, int BrojTimova){
    if(BrojTimova<1 || BrojTimova>ImenaDjece.size())throw std::logic_error("Razvrstavanje nemoguce");
    
    
    std::vector<std::set<std::string>> timovi;
    std::list<std::string> ListaImena;
    for(int i=0; i<ImenaDjece.size(); i++){
        ListaImena.push_back(ImenaDjece[i]);
    }
    std::list<std::string>::iterator it(ListaImena.begin());
    int BrojKoraka(BrojSlovaIBrojeva(*it));
  
    for(int i=0; i<BrojTimova; i++){
        
       // std::cout << "djece ima " << ImenaDjece.size() << " a timova  " << BrojTimova << "a njihov mod je " << ImenaDjece.size()/BrojTimova << "\n";
        
        int VelicinaTima(int(ImenaDjece.size()/BrojTimova)); // cijeli dio broja djece mod broj timova
        if(i<ImenaDjece.size()%BrojTimova)VelicinaTima++; // prvih (broj djece mod broj timova) timova ima veličinu za jedan vecu 
        std::set<std::string> tim; //skup koji predstavlja tim
       // tim.insert(*it); //ubacimo ovaj prvi odma i sad ga moramo obrisati
        
        //int BrojKoraka((*it).size()); // broj slova ovo se mroa doraditi poslije
        //std::cout << "Broj slova je __ " << BrojKoraka << "\n";
        
        //std::cout << "i=" << i << " tim.size= " <<tim.size() << " velicinatima= " << VelicinaTima << "---\n";
        while(tim.size()<VelicinaTima){
          //  std::cout << "Udje ovde.. tim.size=" << tim.size() <<" \n";
            tim.insert(*it);
            it=ListaImena.erase(it); //brisemo ovo dodano ime
            if(it==ListaImena.end())it=ListaImena.begin();
            while(BrojKoraka-1>0){
                it++;
                if(it==ListaImena.end())it=ListaImena.begin();
                BrojKoraka--;
            }
            //std::advance(it, BrojKoraka-1);//-1 jer erase vec pomjeri jendo mjesto naprijed
            //tim.insert(*it);
            if(it!=ListaImena.end())BrojKoraka=BrojSlovaIBrojeva(*it);
            
        }
       // it=ListaImena.erase(it);
        //if(it==ListaImena.end())it=ListaImena.begin;
        timovi.push_back(tim);
        
        
    }
    
    //for(std::string x : ListaImena) std::cout << "hahaha  .... " << x << " ";
    
    return timovi;
}

int main ()
{
    int n;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::cout << "Unesite imena djece: ";
    std::vector<std::string> imena;
    std::cin.ignore(10000, '\n');
    for(int i=0; i<n; i++){
        std::string ime;
        std::getline(std::cin, ime);
        imena.push_back(ime);
    }
    std::cout << "\nUnesite broj timova: ";
    std::cin >> n;
    try{
        std::vector<std::set<std::string>> timovi (Razvrstavanje(imena, n));
    
        // std::cout << "\n";
    
        for(int i=0; i<timovi.size(); i++){
            std::cout << "Tim " << i+1 << ": ";
            for(auto x : timovi[i]){
                if(timovi[i].find(x)==--(timovi[i].end())) std::cout << x;
                else std::cout << x << ", ";
            }
            std::cout << "\n";
        }
        /* for(int i=0; i<n; i++){
            std::cout << imena[i] << "\n";
        } */
    } catch (const std::logic_error& e){
        std::cout << "Izuzetak: " << e.what();
    }
    
    
    
    return 0;
}