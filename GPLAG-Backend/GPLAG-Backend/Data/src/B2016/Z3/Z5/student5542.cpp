#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <iomanip>
#include <stdexcept>
#include <new>

struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

Dijete *napraviListu(std::vector<std::string> &vektor){
    Dijete *prvi = nullptr;
    Dijete *trenutni ;
    
    for(int i(0); i < vektor.size(); i++){
        
        Dijete *tmp(new Dijete);
        tmp->ime = vektor[i];
        tmp->sljedeci = nullptr;
        
        if(prvi == nullptr) prvi = tmp;
        else trenutni->sljedeci = tmp;
        trenutni = tmp;
        
    }
    trenutni->sljedeci = prvi;
    
    return prvi;
}

int brojElemenata(Dijete *prviCvor){
    if(prviCvor == nullptr) return 0;
    
    int brojac(0);
    Dijete *tmp = prviCvor->sljedeci;
    while(tmp != prviCvor){
        tmp = tmp->sljedeci;
        brojac++;
    }
    brojac++;
    return brojac;
}

Dijete *deleteCvor(Dijete *tekuci, Dijete *&prvi){
    if(tekuci == tekuci->sljedeci){
        delete tekuci;
        prvi = nullptr;
        return nullptr;
    }
    
    Dijete *tmp =prvi;
    bool a(prvi==tekuci);
    while( tmp->sljedeci != tekuci ){
        tmp =tmp->sljedeci;
    }
    
    tmp->sljedeci=tekuci->sljedeci;
    tekuci->sljedeci=nullptr;
    delete tekuci;
    tekuci=nullptr;
    if(a) prvi=tmp->sljedeci;
    return tmp->sljedeci;
    
}



std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int br) {
    if(br<1 || br>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    int velicina;
    
    
    Dijete *prviElement = napraviListu(imena);
    
    std::vector<std::set<std::string>> timovi;
    timovi.resize(1);
    
    int brojac;
    std::string s;
    
    Dijete *tmp = prviElement;
    while(brojElemenata(prviElement)!=0) {
        velicina=0;
        brojac=1;
        
        for(int i=0; i<(tmp->ime).length(); i++) { 
            s=tmp->ime;
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
        
        
        
        tmp = deleteCvor(tmp, prviElement);
        
        while(brojac<velicina) {
            
            if(tmp != nullptr)tmp=tmp->sljedeci;
           
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