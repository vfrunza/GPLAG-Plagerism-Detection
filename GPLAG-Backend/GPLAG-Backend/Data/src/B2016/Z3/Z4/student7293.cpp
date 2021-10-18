/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::vector<std::string> Razvrstavanje (std::vector<std::string> djeca, int br_timova) {
    if (br_timova<1 || br_timova>djeca.size()) throw std::logic_error ("Razvrstavanje nemoguce.");
    return djeca;
    
}

int main ()
{
    try {
        int br_djece;
        std::cout << "Unesite broj djece: ";
        std::cin >> br_djece;
        std::cout << std::endl;
        std::string ime;
        std::vector<std::string> djeca(br_djece);
        std::cout << "Unesite imena djece: ";
        while (djeca.size() < br_djece)
        {
            std::getline(std::cin, ime);
            djeca.push_back(ime);
        }
        
        int br_timova;
        std::cout << "Unesite broj timova: ";
        std::cin >> br_timova;
        
    	return 0;
    }
    catch (std::logic_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
}