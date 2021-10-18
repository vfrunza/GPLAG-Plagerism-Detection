/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <cstring>
#include <vector>


std::string NapraviPalindrom (const std::string recenica, std::vector <std::string> fraze) {
    
    std::string jedan;
    
    for(int i=0;i<fraze.size();i++) {
        for(int j=0;j<recenica.size();j++){
            if (fraze.at(<std::string>i)==recenica.at(j))
                std::cout << "Radi";
        }
    }
    
    return jedan;
}

int main ()
{
	std::string recenica;
	
	std::cout << "Unesite recenicu: ";
    std::getline(std::cin, recenica);
    
    std::cout<<"Unesite fraze: ";

    std::vector<std::string> fraze;
    std::string rijec;
    while(rijec != "*")
        {
            std::cin >> rijec;
            fraze.push_back(rijec);
        }
    if(rijec == "*")
    {
        for(int i = 0 ; i<(fraze.size() -1);i++)
            std::cout<<fraze.at(i)<<" " ;
    }
    
	return 0;
}