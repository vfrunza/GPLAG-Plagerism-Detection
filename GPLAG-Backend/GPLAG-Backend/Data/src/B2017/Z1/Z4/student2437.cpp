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
#include <vector>
#include <string>



std::string NapraviPalindrom (std::string s, std::vector<std::string> v) {
	
	for (int i(0); i<v.size(); i++) {
		for (int j(0); j<s.length(); j++) {
			
			int d(j+v.at(i).length());
			
			if (d<=s.length() && (j==0 || !((s.at(j-1)>='a' && s.at(j-1)<='z') || (s.at(j-1)>='A' && s.at(j-1)<='Z'))) &&
			(d==s.length() || !((s.at(d)>='a' && s.at(d)<='z') || (s.at(d)>='A' && s.at(d)<='Z')))) {
				
				std::string rijec (s.substr(j,v.at(i).length()));
				if (rijec==v.at(i)) {
					for (int k(0); k<v.at(i).length(); k++) {
						s.insert(s.begin()+j+v.at(i).length(), v.at(i).at(k));
					}
				}
			}
		}
	}
return s;
}


std::string NapraviPoluPalindrom (std::string s, std::vector<std::string> v) {
	for (int i(0); i<v.size(); i++) {
		for (int j(0); j<s.length(); j++) {
			
			int d(j+v.at(i).length());
			if (d<=s.length() && (j==0 || !((s.at(j-1)>='a' && s.at(j-1)<='z') || (s.at(j-1)>='A' && s.at(j-1)<='Z'))) &&
			(d==s.length() || !((s.at(d)>='a' && s.at(d)<='z') || (s.at(d)>='A' && s.at(d)<='Z')))) {
				
				std::string rijec(s.substr(j,v.at(i).length()));
				if (rijec==v.at(i)) {
					
					if (v.at(i).length()%2==0) {
						for (int k(0); k<v.at(i).length()/2; k++)
						s.erase(s.begin()+j+(v.at(i).length()/2));
						
						for (int k(0); k<v.at(i).length()/2; k++)
					    s.insert(s.begin()+j+(v.at(i).length()/2), v.at(i).at(k));
					}
					
					else {
						for(int k(0); k<v.at(i).length()/2; k++)
						s.erase(s.begin()+j+1+(v.at(i).length()/2));
						
						for (int k(0); k<v.at(i).length()/2; k++)
					    s.insert(s.begin()+j+(v.at(i).length()/2)+1, v.at(i).at(k));
					}
					
					
				}
			}
			
		}
	}
return s;
}


int main()
{

	
	std::string s,rijec; 
	std::cout << "Unesite recenicu: ";
	std::getline (std::cin, s);
	std::vector<std::string> v; 
	std::cout << "Unesite fraze: ";
	
	for (;;) {
		std::getline (std::cin, rijec);
		if (rijec.length()==0) break;
		else v.push_back(rijec);
	}
	
	std::cout << "Recenica nakon Palindrom transformacije: "<< NapraviPalindrom(s,v) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(s,v);
	
	return 0;
}