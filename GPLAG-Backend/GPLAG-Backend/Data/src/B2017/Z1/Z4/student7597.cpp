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

using std::string;
using std::vector;

bool NijeSlovo(char znak) {
	if((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak <='9'))
		return false;
	return true;
}

string NapraviPalindrom(string s , vector<string> v ) {

	for(string fraza : v ) {
		for(int i=0;i<s.length();i++) {
			if(i+fraza.length() <= s.length()) {     // Da ne iskoci iz stringa...
				if(fraza == s.substr(i, fraza.length())) { // Ako postoji fraza/rijec u recenici 
					if((i==0 && !(NijeSlovo(s.at(i+fraza.length())))) || (i+fraza.length()==s.length() && !(NijeSlovo(s.at(i-1)))) ) // Specijalni slucaj,provjeravam rubne rijeci
						continue;
					if((i==0 && NijeSlovo(s.at(i+fraza.length()))) || (i+fraza.length()==s.length() && NijeSlovo(s.at(i-1))) || (NijeSlovo(s.at(i+fraza.length())) && NijeSlovo(s.at(i-1))) )  { // Glavni slucaj
						
						for(int j=fraza.length()-1;j>=0;j--) {                 // Ubacivanje palindroma
							s.insert(s.begin()+i+fraza.length() , fraza[j]);
							i++;
						}
					}
				}
			}
		}
	}
	return s;
}
string NapraviPoluPalindrom(string s, vector<string> v) {
	for(string fraza : v ) {
		for(int i=0;i<s.length();i++) {
			if(i+fraza.length() <= s.length()) {     // Da ne iskoci iz stringa...
				if(fraza == s.substr(i, fraza.length())) { // Ako postoji fraza/rijec u recenici 
					if((i==0 && !(NijeSlovo(s.at(i+fraza.length())))) || (i+fraza.length()==s.length() && !(NijeSlovo(s.at(i-1)))) ) // Specijalni slucaj,provjeravam rubne rijeci
						continue;
					if((i==0 && NijeSlovo(s.at(i+fraza.length()))) || (i+fraza.length()==s.length() && NijeSlovo(s.at(i-1))) || (NijeSlovo(s.at(i+fraza.length())) && NijeSlovo(s.at(i-1))) )  { // Glavni slucaj
						i+=fraza.length();                    // Pravljenje palindroma bez dodavanja u string
						for(int j=0;j<fraza.length()/2;j++) 
							s[i-j-1] = fraza[j];
					}
				}	
			}
		}
	}
	return s;
}


int main ()
{
	string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	vector<string> skupFraza;
	std::cout<<"Unesite fraze: ";
	string fraza;
	while(true) {
		std::getline(std::cin,fraza);
		if(fraza.length()==0)
			break;
		skupFraza.push_back(fraza);
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,skupFraza);
	std::cout<<"\nRecenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,skupFraza);
	std::cout<<std::endl;
	std::cout <<  NapraviPalindrom (recenica, {"elementarna   ", "je", "definisana"}) << std::endl;
	return 0;
}
