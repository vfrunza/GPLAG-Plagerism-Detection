/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int broj_timova) {
    if(broj_timova<=0 || broj_timova>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi;
    std::list<std::string> lista_djece;
    
    for(int i=0; i<djeca.size(); i++) {
        lista_djece.push_back(djeca[i]);
    }
    
    std::vector<int> broj_ljudi_po_timu(broj_timova);
    
    int ost=djeca.size()%broj_timova;
    for(int i=0; i<broj_timova; i++) {
        if(ost>0) { broj_ljudi_po_timu[i]=djeca.size()/broj_timova+1; ost--; }
        else broj_ljudi_po_timu[i]=djeca.size()/broj_timova;
    }
    
    int broj=djeca.size();
    std::set<std::string> skup, a;
    int i=0, k=0;
    
    for(auto it=lista_djece.begin(); it!=lista_djece.end(); it++) {
        if(i==broj_ljudi_po_timu[k]) {
           timovi.push_back(skup);
            i=0; k++; 
            skup=a;
        }
        
        if(broj==0) break;
        skup.insert(*it);
        std::string rijec=*it;
        
        int broj_rijeci(rijec.length());
        //provjera ima li razmaka
        for(int i=0; i<rijec.length(); i++) {
            if(!((rijec[i]>='a' && rijec[i]<='z') || (rijec[i]>='A' && rijec[i]<='Z') || (rijec[i]>='0' && rijec[i]<='9'))) broj_rijeci--;
        }
        
        it=lista_djece.erase(it); broj--;
        
        if(it==lista_djece.end() && broj>0) it=lista_djece.begin();
        
        while(broj_rijeci-2) {
            it++;
            if(it==lista_djece.end() && broj>0) it=lista_djece.begin(); 
            broj_rijeci--;
        }
        
        it++;
        if(it==lista_djece.end() && broj>0) { it=lista_djece.begin(); }
        it--;
        
        i++;
    }
    timovi.push_back(skup);
    return timovi;
}

int main ()
{
    
    std::vector<std::string> lista;
    int broj_timova, broj_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cin.clear();std::cin.ignore(1000000, '\n');
    std::cout << "Unesite imena djece: " << std::endl;
    while(broj_djece) {
        //std::cin.clear(); std::cin.ignore(100000, '\n');
        std::string s;
        getline(std::cin, s);
        lista.push_back(s);
        broj_djece--;
    }
    
    std::cout << "Unesite broj timova: ";
    std::cin >> broj_timova;
    try{
        std::vector<std::set<std::string>> timovi = Razvrstavanje(lista, broj_timova);
        for(int i=0; i<timovi.size(); i++) {
            std::cout << "Tim " << i+1 <<": ";
            int brojac(0);
            for(auto it : timovi[i]) {
                std::cout <<  it; brojac++;
                if(brojac!=timovi[i].size()) std::cout << ", ";
                
            }
            std::cout << std::endl; 
        }
    }   catch(std::logic_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what(); }
    catch(...) { std::cout << "ne valja"; }
	return 0;
}