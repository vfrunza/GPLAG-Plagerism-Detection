#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <iterator>
enum class Boje
{
    Pik, Tref, Herc, Karo
};

void DaLiJeIspravna(std::list<std::pair<Boje,std::string>> lista)
{
    if(lista.size()>52) {
        throw std::logic_error("Neispravna lista!");

    }
 auto it(lista.begin());
    auto it_prije(it) ;
    it++;
    while(it!=lista.end()) {
        if(it_prije->first!=Boje::Pik && it_prije->first!=Boje::Tref && it_prije->first!=Boje::Herc && it_prije->first!=Boje::Karo) {
            throw std::logic_error("Neispravna lista!");
        }

        if(it_prije->second!="2" && it_prije->second!="3" && it_prije->second!="4" && it_prije->second!="5" && it_prije->second!="6" && it_prije->second!="7" && it_prije->second!="8" &&
                it->second!="9" && it_prije->second!="10" && it_prije->second!="J" && it_prije->second!="Q" && it_prije->second!="K" && it_prije->second!="A") {

            throw std::logic_error("Neispravna lista!");

        }

        if((it->first)<(it_prije->first)) {
            throw std::logic_error("Neispravna lista!");

        }

        if((it_prije->second=="J" || it_prije->second=="Q" || it_prije->second=="K" || it_prije->second=="A") && (it->second=="J" || it->second=="Q" || it->second=="K" || it->second=="A")) {
            if(it->second=="J" && (it_prije->second=="K" || it_prije->second=="Q" || it_prije->second=="A")) {
                throw std::logic_error("Neispravna lista!");
            } else if(it->second=="Q" && (it_prije->second=="K" || it_prije->second=="A")) {
                throw std::logic_error("Neispravna lista!");
            } else if(it->second=="K" && (it_prije->second=="A")) {
                throw std::logic_error("Neispravna lista!");
            }

        }

        else {
            if(it->second<it_prije->second) {
                throw std::logic_error("Neispravna lista!");

            }



        }
        it++;
        it_prije++;
    }
    
}

std::list<std::pair<Boje,std::string>> KreirajSpil()
{
    return {{Boje::Pik,"2"},{Boje::Pik,"3"},{Boje::Pik,"4"},{Boje::Pik,"5"},{Boje::Pik,"6"},{Boje::Pik,"7"},{Boje::Pik,"8"},{Boje::Pik,"9"},{Boje::Pik,"10"},{Boje::Pik,"J"},{Boje::Pik,"Q"},{Boje::Pik,"A"},{Boje::Tref,"2"},{Boje::Tref,"3"},{Boje::Tref,"4"},{Boje::Tref,"5"},{Boje::Tref,"6"},{Boje::Tref,"7"},{Boje::Tref,"8"},{Boje::Tref,"9"},{Boje::Tref,"10"},{Boje::Tref,"J"},{Boje::Tref,"Q"},{Boje::Tref,"A"},{Boje::Herc,"2"},{Boje::Herc,"3"},{Boje::Herc,"4"},{Boje::Herc,"5"},{Boje::Herc,"6"},{Boje::Herc,"7"},{Boje::Herc,"8"},{Boje::Herc,"9"},{Boje::Herc,"10"},{Boje::Herc,"J"},{Boje::Herc,"Q"},{Boje::Herc,"A"},{Boje::Karo,"2"},{Boje::Karo,"3"},{Boje::Karo,"4"},{Boje::Karo,"5"},{Boje::Karo,"6"},{Boje::Karo,"7"},{Boje::Karo,"8"},{Boje::Karo,"9"},{Boje::Karo,"10"},{Boje::Karo,"J"},{Boje::Karo,"Q"},{Boje::Karo,"A"}};
}


void IzbaciKarte(std::list<std::pair<Boje,std::string>> &lista,std::multimap<Boje,std::string> &mapa)
{
  DaLiJeIspravna(lista);

    auto it(lista.begin());
    
while(it!=lista.end()) {

       
        std::multimap<Boje,std::string>::iterator it1=std::find_if(mapa.begin(),mapa.end(),[it](std::pair<Boje,std::string> par1) {
            return (par1.first==it->first && par1.second==it->second);
        });
        if(it1!=mapa.end()) {
            mapa.erase(it1);
            it=lista.erase(it);
            
        } else {
           
            it++;
            
        }

    }
}

std::queue<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &lista,short int &r,int &b)
{


    if(r<1 || r>52) {
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    }
    if(b<1) {
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    }

    DaLiJeIspravna(lista);
    std::queue<std::pair<std::string,std::string>> red;
    it=lista.begin();

    for(int i=0; i<b; i++) {
      if(lista.size()==0)
      {
          break;
      }
        
        for(int j=0;j<r-1;j++)
        {
            if(it==lista.end())
            {
                it=lista.begin();
                
            }
            
        it++;
          
            
        }
        
    if(it->first==Boje::Pik) {
            red.push_back(std::make_pair("Pik",it->second));
        } else if(it->first==Boje::Tref) {
            red.push_back(std::make_pair("Tref",it->second));

        } else if(it->first==Boje::Herc) {
            red.push_back(std::make_pair("Herc",it->second));

        } else if(it->first==Boje::Karo) {
            red.push(std::make_pair("Karo",it->second));

        }
        it=lista.erase(it);

    }

}


 void VratiPrvihNKarata(std::list<std::pair<Boje,std::string>> &lista,std::queue<std::pair<std::string,std::string>> &red,int n)
     {
         DaLiJeIspravna(lista);
         std::string pomocna;
    auto it(lista.begin());
    for(int i=0;i<n;i++)
    {
        auto it(lista.begin());
        if(red.front().first=="Pik")
        pomocna=Boje::Pik;
        else if(red.front().first=="Tref")
        pomocna=Boje::Tref;
        else if(red.front().first=="Herc")
        pomocna=Boje::Herc;
        if(red.front().first=="Karo")
        pomocna=Boje::Karo;
        
      
      while(it->first<pomocna)
      {
          it++;
      }
      if(it->second<"J")
      {
         while(it->second<)
      
      
      }
      
      
      
        
        
        
    }
    
    
         
         
         
         
    
    
    
    
         
         
    }




















int main()
{

try{


std::pair<double,double> par1{2,1};
std::pair<double,double> par2{1,1};

std::cout<< par1<par2;












}
catch(std::logic_error izuzetak)
{
    std::cout<<izuzetak.what();
}








    return 0;
}



























