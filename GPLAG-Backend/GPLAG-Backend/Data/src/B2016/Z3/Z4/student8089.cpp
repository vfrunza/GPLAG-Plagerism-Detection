#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

int nadjiRazmak (std::string s){
    int brojac(0);
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            brojac++;
        }
    }
    
    return brojac;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imenaDjece, int brojTimova){
    if (brojTimova < 1 || brojTimova > imenaDjece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    int brojac(0);
    //Prvo kopiraj iz vec string -> listu
    std::list<std::string> listaImena;
    for (auto i : imenaDjece) {listaImena.push_back(i); brojac++;}
    
    //Ostatak
    int n(imenaDjece.size()%brojTimova); std::vector<int> brIgracaPoTimu(brojTimova);
    
    //Postavljanje velicine timova
    std::list<std::string>::iterator it(listaImena.begin());
    for (int i = 0; i < brojTimova; i++) {
        brIgracaPoTimu[i] = imenaDjece.size() / brojTimova;
        if (n-- > 0) brIgracaPoTimu[i]++;
    }
        
    std::vector<std::set<std::string>> Timovi(brojTimova); 
    
    //Svrstavanje u timove
    
    int o(0), razmak(0);
    for (auto j : brIgracaPoTimu) {
        std::set<std::string> trenutniTim;
        
        
        for (int i = 0; i < j; i++) {
            advance(it,razmak);
            
            trenutniTim.insert(*it);
            razmak = nadjiRazmak(*it) - 1;
            
            
            
            it = listaImena.erase(it); brojac--;
            if (it == listaImena.end()) it = listaImena.begin();
            
            if (brojac == 0) {
                break;
            }
            
            if (razmak > brojac) razmak = (razmak % brojac);
            
            if (razmak >= std::distance(it, listaImena.end())) {
                razmak = razmak - std::distance(it, listaImena.end());
                it = listaImena.begin();
            }
            
            
        }
        
        Timovi[o++] = trenutniTim;
    }    
        
    return Timovi;
}

int main (){
    
    int n; std::cout << "Unesite broj djece: "; std::cin >> n; std::cin.ignore(10000, '\n'); 
    std::cout << "Unesite imena djece: " << std::endl; 
    std::vector<std::string> imenaDjece(n);//={"Damir", "Ana", "Muhamed", "Marko", "Ivan", "Mirsad", "Nikolina", "Alen", "Jasmina", "Merima"};
    for (int i = 0; i < n; i++) {
        std::string temp; std::getline(std::cin, temp);
        imenaDjece[i]=temp;
    }
    
    
    std::cout << "Unesite broj timova: "; std::cin >> n; std::cin.ignore(10000, '\n');
  
    try{
        std::vector<std::set<std::string>> Timovi(Razvrstavanje(imenaDjece, n)); n=1;
        
        for (auto i : Timovi) {
            int o(0);
            std::cout << "Tim " << n << ": ";
            for (auto j : i) {
                if (o == 0) {
                    std::cout << j; o++;
                }
                else{
                    std::cout << ", " << j;
                }
            }
            std::cout << std::endl;
            n++;
        }
    }
    catch (std::logic_error e){
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
   
	return 0;
}

// AT 2 i 3 su ok