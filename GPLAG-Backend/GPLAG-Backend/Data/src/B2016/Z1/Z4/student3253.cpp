/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniString(std::string ulaz) {
    std::string rezultat;
    long idx_kraj = ulaz.size() - 1;
    for (long i = idx_kraj; i>=0; i--) {
        rezultat.push_back(ulaz[i]);
    }
    return rezultat;
}

int PronadjiRijec(std::string recenica, std::string rijec, int pocetak)
{
    int duzina_recenice = recenica.length();
    int duzina_rijeci = rijec.length();
    for (int i = pocetak; i <= duzina_recenice - duzina_rijeci; i++) {
        int j = 0;
        while (j < duzina_rijeci && recenica[i+j] == rijec[j]) {
            j++;
            
        }
        if (j == duzina_rijeci) { 
            return i;
    }
}
 
 return -1;
}

std::string ZamijeniRijecURecenici(std::string recenica, std::string rijec, int pozicija, int duzina) {
    for (int i=0; i<duzina; i++) {
        recenica[pozicija+i] = rijec[i];
    }
    return recenica;
}

bool PronadjiUVektoru(std::string rijec, std::vector<std::string> rijeci) {
    for (int i=0; i<rijeci.size(); i++) {
        if (PronadjiRijec(rijeci[i], rijec, 0) != -1 && rijeci[i].size() == rijec.size()) {
            return true;
        }
    }
    return false;
}

std::string ObrniFrazu(std::string fraza) {
    std::string obrnuto(fraza);
    obrnuto = ObrniString(fraza);
    return obrnuto;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze) {
    for (int i=0; i<fraze.size(); i++) {
        std::string obrnuta = ObrniFrazu(fraze[i]);
        
        size_t index = 0;
        while (true) {
            index = PronadjiRijec(recenica, fraze[i], index);
            if (index == -1) break;
            recenica = ZamijeniRijecURecenici(recenica, obrnuta, index, obrnuta.size());
            index += obrnuta.size();
            
        }
    }
    return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci) {
    std::string rezultat = "";
    std::string rijec = "";
    bool izmijeniSve = false;
    if (rijeci.size() == 0) {
        izmijeniSve = true;
    } else {
        for (int i=0; i<rijeci.size(); i++) {
            rijec = rijeci[i];
            for (int j=0; j<rijec.size(); j++) {
                if ( !((rijec[j] >= 'a' && rijec[j] <= 'z') || (rijec[j] >= 'A' && rijec[j] <= 'Z'))) {
                    throw std::domain_error("Pogresan argument!");
                }
            }
        }
    }
    
    recenica = recenica + " ";
    size_t index = 0;
    while ( recenica[index] != '\0' ) {
        if ( PronadjiRijec(recenica, " ", index) != -1 ) {
            int iducirazmak = PronadjiRijec(recenica, " ", index);
            int duzinarijeci = iducirazmak - index;
            std::string rijec = recenica.substr(index, duzinarijeci);
            if ( izmijeniSve == true || (izmijeniSve == false && PronadjiUVektoru(rijec, rijeci))) 
            {
                std::string rijecbezprvog = rijec.substr(1, rijec.size()-1);
                rijec = rijecbezprvog + rijec[0] + "ay";
            }
            
            rezultat = rezultat + rijec + " ";
            index = iducirazmak + 1;
        }
        else {
            index++;
        }
    }
    return rezultat;
}

int main ()
{
    std::string recenica = "";
    std::vector<std::string> rijeci;
    std::cin.clear();
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, recenica);
    std::cout << "Unesite fraze: ";
    std::string rijec;
    while ( getline(std::cin, rijec), !rijec.empty()) {
        rijeci.push_back(rijec);
    }
    
    std::cout << "Recenica nakon PigLatin transformacije: ";
    try {
        std::cout << IzmijeniUPigLatin(recenica, rijeci);
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Recenica nakon obrtanja fraza: ";
    std::cout << ObrniFraze(recenica, rijeci);
    std::cout << std::endl;
}



