/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <string>

enum class Boje {Pik, Tref, Herc, Karo};
std::string  s  {'2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'};

std:: list<std::pair<Boje, std::string>> KreirajSpil (){
    
    std:: list<std::pair<Boje, std::string>> spil;
    auto index= spil.begin();
    for(int i(0); i<spil.size(); i++){
    
     spil=std::make_pair (Boje, s[index]); 
    }
     return spil;
}

int main ()
{
	return 0;
}
