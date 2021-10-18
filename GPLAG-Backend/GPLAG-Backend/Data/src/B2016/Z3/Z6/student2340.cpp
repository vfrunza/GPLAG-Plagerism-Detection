/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <memory>
#include <stdexcept>

struct Dijete{
  std::string ime;
  std::shared_ptr<Dijete> sljedeci;
};

int Duzinarijeci(std::string s){
    int brojac(0);
    for (int i=0; i<s.size(); i++){
        if((s[i]>='A' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) brojac++;
    }
    return brojac;
}

void Ispisi(std::vector<std::set<std::string>> vektor) {
for(int i=0; i<vektor.size();i++){
           std::cout<<"Tim "<<i+1<<": ";
            for(auto it=vektor[i].begin(); it!=vektor[i].end(); ++it){
               if(it!=vektor[i].begin())
               std::cout<<", "<<*it;
               else std::cout<<*it;
            }
            std::cout<<std::endl;
            
        }
}


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imenadjece, int broj_timova){
std::vector<std::set<std::string>> parovi(broj_timova);

if(broj_timova<=1 || broj_timova>imenadjece.size()) throw std::logic_error("Razvrstavanje nemoguce");

std::shared_ptr<Dijete> pocetak(nullptr);
std::shared_ptr<Dijete> prethodni;
        for(int i=0; i<imenadjece.size();i++){
        std::shared_ptr<Dijete> novi(new Dijete);
            novi->ime=imenadjece[i];
            novi->sljedeci=nullptr;
                if(i==imenadjece.size()-1) novi->sljedeci=pocetak;
                if(!pocetak) pocetak=novi;
                else prethodni->sljedeci=novi;
                prethodni=novi;
        }

    int n=imenadjece.size();
    int b=n%broj_timova;
    auto iter=pocetak;
    std::set<std::string> tim;
    int brTima=0;
            //prolazimo kroz citavu listu
            while(iter!=nullptr){
                std::string temp(iter->ime);
                tim.insert(iter->ime);
                
                    if(iter->sljedeci == prethodni){
                        iter->sljedeci=nullptr;
                        
                            if(tim.size()==int(n/broj_timova)){
                                parovi[brTima]=tim;
                                tim.clear();
                                brTima++;
                            }
                        
                        tim.insert(prethodni->ime);
                        parovi[brTima]=tim;
                        tim.clear();
                    
                     prethodni->sljedeci=nullptr; 
                     iter->sljedeci=nullptr;
                     pocetak=nullptr;
                     break;
                        }
                        
                
                    prethodni->sljedeci=iter->sljedeci;
                    std::shared_ptr<Dijete> temp_dijete=iter;
                    iter=iter->sljedeci;
                
                
                     //provjeravamo ostatke, ukoliko je ostatak veći od nula
                        if(brTima<b){
                            if(tim.size()==int (n/broj_timova)+1) {
                            parovi[brTima]=tim;
                            brTima++;
                            tim.clear();
                        }     
                        }
                        else {
                            if(tim.size()==int (n/broj_timova)){
                                parovi[brTima]=tim;
                                brTima++;
                                tim.clear();
                                
                            }
                            
                        }
                   
                for(int i=1; i<Duzinarijeci(temp); i++){
                    prethodni=iter;
                    iter=iter->sljedeci;
                }
                            
            }
        
    
return parovi;
}

int main ()
{
    try{
    int n(0),br_timova(0);
    std::vector<std::string> v;
    std::string ime;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    std::cout<<"Unesite imena djece: ";
    for(int i=0; i<n; i++){
        std::getline(std::cin,ime);
        if(ime==""){
            i--;
            continue;
        }
        v.push_back(ime);

    }
    
    std::cout<<std::endl<<"Unesite broj timova: ";
    std::cin>>br_timova;
        
        
    auto vektor=Razvrstavanje(v,br_timova);
    
    Ispisi(vektor);
        /*
        
        std::vector<std::string> imena({"Damir","Ana","Muhamed","Marko","Ivan","Mirsad","Nikolina","Alen","Jasmina","Merima"});
        std::vector<std::set<std::string>> timovi =Razvrstavanje(imena,3);
        Ispisi(timovi);
        */
	return 0;
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
}