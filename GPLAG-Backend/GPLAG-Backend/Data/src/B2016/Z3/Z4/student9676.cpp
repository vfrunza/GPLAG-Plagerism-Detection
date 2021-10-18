/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <stdexcept>
#include <cmath>

bool je_slovo (char x){
    return ((x>='a' && x<='z') ||(x>='A' && x<='Z') || (x>=0 && x<=9));
}

std::list<std::string>::iterator globalni;

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> djeca, int timova){
    if (timova<1 || timova > djeca.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    std::list<std::string> djeca1;
    std::vector<std::set<std::string>> vrati(timova);
        for (int i=0; i<djeca.size(); i++){
            djeca1.push_back(djeca[i]);
        }
        if (djeca.size()%timova != 0) {
     int prvih(djeca.size()%timova);

        for (int i=0; i<prvih; i++){
            
            int br_clanova = std::floor(djeca.size()/timova) + 1;
                auto it(djeca1.begin());
               while (vrati[i].size() != br_clanova){
                   
                   vrati[i].insert(*it);
                   int pomjeri ((*it).length());
                            int brojac(0);
                        for (int k=0; k<(*it).length(); k++){
                            if (!je_slovo((*it).at(k))) brojac++;
                        }
                        pomjeri-=brojac;
                        
                   it = djeca1.erase(it);
                    if (it == djeca1.end()) it = djeca1.begin();
                        for (int j=0; j<pomjeri-1; j++){
                            it++;
                             if (it==djeca1.end()){
                                 it--;
                                 it = djeca1.begin();
                             }
                        }
                    globalni = it;    
               }
        }
        
        for (int i=prvih; i<timova; i++){
            int br_clanova = std::floor(djeca.size()/timova);
            auto it = globalni;
                while (vrati[i].size() != br_clanova){
                    
                    
                   vrati[i].insert(*it);
                   int pomjeri ((*it).length());
                    int brojac(0);
                        for (int k=0; k<(*it).length(); k++){
                            if (!je_slovo((*it).at(k))) brojac++;
                        }
                        pomjeri-=brojac;
                        
                   it = djeca1.erase(it);
                    if (it == djeca1.end()) it = djeca1.begin();
                        for (int j=0; j<pomjeri-1; j++){
                            if (!djeca1.size()) goto a;
                            it++;
                            globalni = it;
                             if (it==djeca1.end()){
                                 it--;
                                 it = djeca1.begin();
                                 globalni = it;
                             }
                        }
               }
            
        }
        
        } else {
             for (int i=0; i<timova; i++){
                 int br_clanova = djeca.size()/timova;
                 auto it = djeca1.begin();
                    while(vrati[i].size() != br_clanova){
                         
                    vrati[i].insert(*it);
                   int pomjeri ((*it).length());
                    int brojac(0);
                        for (int k=0; k<(*it).length(); k++){
                            if (!je_slovo((*it).at(k))) brojac++;
                        }
                        pomjeri-=brojac;
                   it = djeca1.erase(it);
                    if (it == djeca1.end()) it = djeca1.begin();
                        for (int j=0; j<pomjeri-1; j++){
                            if (!djeca1.size()) goto a;
                            it++;
                             if (it==djeca1.end()){
                                 it--;
                                 it = djeca1.begin();
                             }
                        }
               }
                 
             }
        } a:
    
    return vrati;
}



int main ()
{
    try{
    std::cout<<"Unesite broj djece: ";
    int br_djece;
    std::cin>>br_djece;
    std::cin.ignore(10000, '\n');
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string> djeca (br_djece);
    for (int i=0; i<br_djece; i++){
        std::getline(std::cin, djeca[i]);
    }
    std::cout<<"Unesite broj timova: ";
    int timova;
    std::cin>>timova;
    std::vector<std::set<std::string>> timovi(Razvrstavanje(djeca,timova));
        for (int i=0; i<timova; i++){
            std::cout<<"Tim "<<i+1<<": ";
            int j(0);
            for (auto x: timovi[i]) {
                j++;
                if (j==timovi[i].size()) std::cout<<x;
                else std::cout<<x<<", ";
            }
            std::cout<<std::endl;
        }
    } catch (std::logic_error greska){
        std::cout<<greska.what();
    }
    
    
	return 0;
}