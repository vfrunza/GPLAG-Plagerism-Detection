/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <cctype>
#include <stdexcept>

std::map<std::string, std::set<int> > KreirajIndeksPojmova(std::string tekst) {
    tekst.push_back(' ');
//    std::cout << "Usao u funkciju!" << std::endl;
    for(int i = 0; i < tekst.size(); ++i) {
        tekst.at(i) = char(tolower(tekst.at(i))); //Cijeli string pretvorimo u mala slova
  //      std::cout << "Pretvorio " << i + 1 << " u malo slovo!" << std::endl;
    }
    std::map<std::string, std::set<int> > Povratna_mapa;
//    std::cout << "Kreirana povratna mapa!" << std::endl;
    if(tekst.size() == 1) return Povratna_mapa; 
    
    std::string temp;
    for(int i = 0; i < tekst.size(); ++i) {
        if(((tekst.at(i) >= 'a' && tekst.at(i) <= 'z') || (tekst.at(i) >= '0' && tekst.at(i) <= '9'))) {
  //          std::cout << "Dodajem!" << std::endl;
            temp.push_back(tekst.at(i)); //Pravimo rijec koju cemo smjestati u mapu(ako vec postoji, mapa ce rijesiti problem ponavljanja)
        }
        else {
            if(temp.size())
            Povratna_mapa[temp].insert(i - temp.size()); //Ubacujemo rijec u mapu
         //   std::cout << temp << std::endl;
            temp.clear(); 
        }

    }
    
    return Povratna_mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int> > mapa) {
    std::set<int> temp;
    bool nadjen = false;
    for(auto it = mapa.begin(); it != mapa.end(); ++it) 
        if((it -> first) == rijec) {
            nadjen = true;
            temp = (it -> second);
            break;
        }
    if(nadjen == false)
        throw std::logic_error("Unesena rijec nije nadjena!");
    
    return temp;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int> > mapa) {
    for(auto i = mapa.begin(); i != mapa.end(); ++i) {
        int broj_elemenata_skupa = 0;
        std::cout << i -> first << ": ";
        for(auto j = i -> second.begin(); j != i -> second.end(); ++j) {
            broj_elemenata_skupa++;
        }
        
        for(auto j = i -> second.begin(); j != i -> second.end(); ++j) {
            if(broj_elemenata_skupa != 1) {
            std::cout << *j << ",";
            broj_elemenata_skupa--;
        }
            else
            std::cout << *j;
        }
        
        std::cout << std::endl;
    }
}

int main () {
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
//    std::cout << "UNOS USPJESAN!" << std::endl;

    std::map <std::string, std::set<int> > Indeks_pojmova;
    Indeks_pojmova = KreirajIndeksPojmova(tekst);
//    std::cout << "KREIRAN INDEKS POJMOVA!" << std::endl;
    
    IspisiIndeksPojmova(Indeks_pojmova);
    
    while(1) {
        try {
            std::cout << "Unesite rijec: ";
            std::string unos;
            std::cin >> unos;      
            if(unos == ".")
            break;
            
            std::set<int> unos_index;    
            unos_index = PretraziIndeksPojmova(unos, Indeks_pojmova);
            for(int x : unos_index)
            std::cout << x << " ";
            std::cout << std::endl;
        }
        catch(std::logic_error trash) {
            std::cout << trash.what() << std::endl;
        }
    }
    
	return 0;
}