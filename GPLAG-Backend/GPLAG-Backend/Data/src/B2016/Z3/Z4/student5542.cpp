#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <iomanip>
#include <stdexcept>
#include <new>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int br) {
    if(br<1 || br>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> lista;
    int velicina;
    
    for(int i=0; i<imena.size(); i++) {
        lista.push_back(imena[i]);
    }
    
    std::vector<std::set<std::string>> timovi;
    timovi.resize(1);
    
    int brojac;
    std::string s;
    auto it=lista.begin();
    while(lista.size()!=0) {
        
        velicina=0;
        brojac=1;
        
        for(int i=0; i<it->length(); i++) {
            s=*it;
            if((s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))
                velicina++;
        }
        
        
        if(timovi.size()<=(imena.size())%br) {
            
            if(timovi[timovi.size()-1].size()<imena.size()/br +1) {
                timovi[timovi.size()-1].insert(s);
            }
            else {
                timovi.resize(timovi.size()+1);
                timovi[timovi.size()-1].insert(s);
            }
        }
        else {
            if(timovi[timovi.size()-1].size()<imena.size()/br)
             timovi[timovi.size()-1].insert(s);
            else {
                timovi.resize(timovi.size()+1);
                timovi[timovi.size()-1].insert(s);
            }
        }
        
        
        it=lista.erase(it);
        if(it==lista.end()) it=lista.begin();
        
        while(brojac<velicina) {
            it++;
            if(it==lista.end()) it=lista.begin();
            brojac++;
            
        }
        
    }
    
    
    return timovi;
}

int main ()
{
    int n;
    std::string ime;
    std::vector<std::string> imena;
    
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::cout << "Unesite imena djece: " << std::endl;
    std::cin.ignore(1000, '\n');
    
    for(int i=0; i<n; i++) {
        std::getline(std::cin, ime);
        imena.push_back(ime);
    }
    std::cout << "Unesite broj timova: ";
    std::cin >> n;
    
    std::vector<std::set<std::string>> skupovi;
    try {
    skupovi=Razvrstavanje(imena, n);
    
    for(int i=0; i<n; i++) {
        std::cout << "Tim " << i+1 << ": ";
        for(auto it=skupovi[i].begin(); it!=skupovi[i].end(); it++) {
            std::cout << *it;
            if(it!=--skupovi[i].end()) std::cout << ", ";
        }   
        std::cout << std::endl;
    }
    }
    catch(std::logic_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
	return 0;
}