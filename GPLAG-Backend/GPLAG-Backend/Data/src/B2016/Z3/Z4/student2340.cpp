/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <cmath>
#include <stdexcept>

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

int DuzinaImena(std::string ime){
    
    int broj_slova(0);
    for(int i=0; i<ime.size();i++)
        if((ime[i]>='A' && ime[i]<='z') || (ime [i]>='0' && ime[i]<='9')) broj_slova++;
        return broj_slova;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imenadjece, int broj_timova){
std::vector<std::set<std::string>> parovi(broj_timova);
std::list<std::string> lista;
std::copy(imenadjece.begin(), imenadjece.end(), std::back_inserter(lista));
//std::cout<<broj_timova;
if(broj_timova<=1 || broj_timova>imenadjece.size()) throw std::logic_error("Razvrstavanje nemoguce");

    int n=imenadjece.size();
    int b(n%broj_timova);
    auto iter=lista.begin();
    std::set<std::string> tim;
    int brTima=0;
            //prolazimo kroz citavu listu
            while(lista.begin()!=lista.end()){
                std::string temp(*iter);
                tim.insert(*iter);
                 //ako dodjemo do kraja, vracamo iterator na pocetak
                if(iter==lista.end()) {
                    iter=lista.begin();
                }
                  iter=lista.erase(iter);
                if(iter==lista.end()) {
                    iter=lista.begin();
                }
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
                        
                for(int i=1; i<DuzinaImena(temp);i++){
                    iter++;
                    if(iter==lista.end()) {
                        iter=lista.begin();
                    }
                    if(lista.size()==0) break;
                }
                            
            }
        
    
return parovi;
}

int main ()
{ try{
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
    
    //std::cout<<br_timova;
    Ispisi(vektor);
        
        
        /*
        std::vector<std::string> imena({"Damir","Ana","Muhamed","Marko","Ivan","Mirsad","Nikolina","Alen","Jasmina","Merima"});
        std::vector<std::set<std::string>> timovi =Razvrstavanje(imena,3);
        Ispisi(timovi);*/
        
        
	return 0;
}
catch(std::logic_error e){
    std::cout<<"Izuzetak: "<<e.what();
}
}