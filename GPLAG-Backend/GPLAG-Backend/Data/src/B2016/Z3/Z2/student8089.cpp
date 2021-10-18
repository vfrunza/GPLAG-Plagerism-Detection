#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

void Umanji (std::string &s){
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string recenica){
    std::map<std::string, std::set<int>> IndeksPojmova;
    Umanji(recenica);
    
    bool nadjenaRijec(false); int index;
    for (int i = 0; i < recenica.length(); i++) {
        
            //Ako je odabrani znak slovo                ili     ako je cifra                               String na pocetku ili ako nije slovo ili cifra
        if (((recenica[i] >= 'a' && recenica[i]<= 'z') || (recenica[i]>= '0' && recenica[i] <= '9')) && (i==0 || !((recenica[i-1] >= 'a' && recenica[i-1]<= 'z') || (recenica[i-1]>= '0' && recenica[i-1] <= '9'))) && !nadjenaRijec) {
            index = i;
            nadjenaRijec = true;
        }
        if (nadjenaRijec && (!((recenica[i] >= 'a' && recenica[i]<= 'z') || (recenica[i]>= '0' && recenica[i] <= '9')) || i+1 == recenica.length())){
            nadjenaRijec = false; if(i+1 == recenica.length()) i++;
            bool Hi(false);
            for (auto l : IndeksPojmova) {
                if (recenica.substr(index, i - index) == l.first) {
                    std::set<int> B (l.second);
                    B.insert(index);
                    IndeksPojmova[recenica.substr(index, i - index)] = B;
                    Hi = true;
                    
                }
            }
            
            
            if (!Hi) {
                      IndeksPojmova[recenica.substr(index, i - index)] = {index};
            }
      
           
        }
        
    }
    return IndeksPojmova;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> IndeksPojmova){
 
    for (auto i : IndeksPojmova) {
        if (rijec == i.first) {
            return i.second;
        }
    }
    
    throw std::logic_error ("Pojam nije nadjen");
    
}

void IspisiIndeksPojmova (const std::map<std::string, std::set<int>> IndeksPojmova){
    for (auto i : IndeksPojmova) {
        std::cout << i.first << ": ";
        
        int k(0);
        
        for (auto j : i.second) {
            if (k == 0) {
                std::cout << j; k++;
            }
            else{
                std::cout << "," << j;
            }
            
        }
        
        std::cout << std::endl;
    }
}

int main (){
	
	
	std::cout << "Unesite tekst: "; std::string recenica; std::getline(std::cin, recenica);
	std::map<std::string, std::set<int>> Mapa(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(Mapa);
	
	
	std::cout << "Unesite rijec: ";
	std::string rijec;
	while (std::getline(std::cin, rijec), rijec != ".") {
	    try{
    	    std::set<int> Set = PretraziIndeksPojmova(rijec, Mapa);
    	    int k(0);
    	    for (auto i : Set) {
    	        if (k == 0) {
                    std::cout << i; k++;
                }
                else{
                    std::cout << " " << i;
                }
    	    }
    	    std::cout << std::endl;
    	    std::cout << "Unesite rijec: ";
	    }
	    catch(std::logic_error e) {
	        std::cout << "Unesena rijec nije nadjena!" << std::endl;
	        std::cout << "Unesite rijec: ";
	    }
	}
	
	return 0;
}