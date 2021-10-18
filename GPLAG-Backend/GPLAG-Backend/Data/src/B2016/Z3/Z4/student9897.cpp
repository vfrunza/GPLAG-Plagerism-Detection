/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>
#include <set>
#include <string>

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> djeca, int broj_timova) {
    
    if (broj_timova<1 || broj_timova>djeca.size()) 
    throw (std::logic_error) "Razvrstavanje nemoguce"; 
    
    std::vector<std::set<std::string>> vektor(broj_timova); 
    
    std::list<std::string> lista(djeca.size()); 
    
    for (int i=0; i<djeca.size(); i++) {
        lista.push_back(djeca[i]);
    }
        std::list<std::string>::iterator it(lista.begin()); 
        
        int a; 
        a=(djeca.size()/broj_timova);  
        int b; 
        b=(djeca.size()%broj_timova);  
        
         while (it!=lista.end()) {
             for (int i=0; i<broj_timova; i++) {
             vektor[i].insert(*it); 
             it=lista.erase(it);
             it++;
             }
              
         }

    return vektor; 

}

int main ()
{
    try {
    std::cout << "Unesite broj djece: "; 
    int n; 
    std::cin >> n; 
    
    try {
    
    std::cout << "Unesite imena djece: "; 
    std::vector<std::string> vektor(n); 
    
    std::cin.ignore(1000, '\n');
    
    for (int i=0; i<vektor.size(); i++) {
        std::getline(std::cin, vektor[i]); 
    }

    std::cout << "Unesite broj timova: "; 
    int m; 
    std::cin >> m; 
    
    std::vector<std::set<std::string>> vektor1(m); 
    
    vektor1=Razvrstavanje(vektor,m); 
    
    for (int i=0; i<vektor1.size(); i++) {
        std::cout << "Tim " << i+1 << ":"; 
        for (std::string x : vektor1[i]) {
            std::cout << x << ", " ; 
        }
        std::cout << std::endl; 
    }
    }
    catch (...) {
        throw; 
    }
    
    }
    catch (std::logic_error e) {
        std::cout << e.what() << std::endl; 
    }
	return 0;
}