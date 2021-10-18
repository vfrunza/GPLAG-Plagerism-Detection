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
#include <string>
#include <vector>



std::string NapraviPalindrom(std::string s, std::vector<std::string> rijeci){
	
	for(int i(0);i<rijeci.size();i++){
		for(int j(0);i<s.length()-rijeci.at(i).length();j++){
			
			if(rijeci.at(i) == s.substr(j,j+rijeci.at(i).length() ) ){
				
				s.insert(s.begin()+j,' ');	
			
				for(int k(rijeci.at(i).length()-1);k>=0;k--)
					s.insert(s.begin()+j+k+1,rijeci.at(i).at(k));
			}
		}
	}
	
	return s;
}


int main ()
{
	std::string s("Danas je lijep dan.");
    std::vector<std::string> v{"lijep","dan"};
    auto konj(NapraviPalindrom(s,v));
    std::cout<<konj;
    return 0;
}