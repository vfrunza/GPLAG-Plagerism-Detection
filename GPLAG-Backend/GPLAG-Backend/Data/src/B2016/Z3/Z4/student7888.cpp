#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <algorithm>
#include <stdexcept>
         std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>imena,int broj_timova){
            if ( broj_timova < 1 || imena.size() < broj_timova ) throw std::logic_error("Razvrstavanje nemoguce");
            std::vector<std::set<std::string>> formirani_timovi(broj_timova);         
            std::list<std::string> djeca;
                for ( int i = 0; i < imena.size(); i++) djeca.push_back(imena[i]);
                    int k(0),ime(0);
                    auto it(djeca.begin());
                    int vel(djeca.size());
                  while ( djeca.size() != 0 ) {
                    int pomakni(std::count_if(it->begin(),it->end(),[](char x) {return ((x>='a' && x <= 'z') || (x >= 'A' && x <='Z') || (x>='0' && x<='9'));}));
                    formirani_timovi[k].insert(*it);
                    ime++;
                    if ( ime == int(vel/broj_timova)+1 && k < (vel%broj_timova) && k < broj_timova-1) {
                        k++; ime=0;
                    }
                   if ( ime >= int(vel/broj_timova) && k>=(vel%broj_timova) && k < broj_timova-1 ) {
                        k++; ime=0;
                    }
                    auto help(djeca.end());
                    help--;
                    if ( it == help ) {
                    it = djeca.erase(it);
                    it = djeca.begin();
                    }
                    else  it = djeca.erase(it);
                        while ( (pomakni-1) != 0 ) {
                            pomakni--;
                            it++;
                           if(it == djeca.end()) it = djeca.begin();
                        }
                }
                return formirani_timovi;
            }

int main ()
{
    try {
    std::vector<std::string>imena;
    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite imena djece: "<<std::endl;
    for ( int i = 0 ; i < broj_djece; i++) {
        std::string s;
        std::getline(std::cin,s);
        imena.push_back(s);
    }
    int broj_timova;
    std::cout<<"Unesite broj timova: ";
    std::cin>>broj_timova;
    std::vector<std::set<std::string>> formirani_timovi(Razvrstavanje(imena,broj_timova));
    for(int i = 0 ; i < broj_timova; i++ ) {
            std::cout<<"Tim "<<i+1<<": ";
            auto helpme(formirani_timovi[i].end());
            helpme--;
        for ( auto it = formirani_timovi[i].begin(); it != formirani_timovi[i].end(); it++ ) {
            if(it == helpme) {
                std::cout<<*it;
                break;
            }
            std::cout<<*it<<", ";
        }
            std::cout<<std::endl;
    }
    }
    catch (std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
	return 0;
}