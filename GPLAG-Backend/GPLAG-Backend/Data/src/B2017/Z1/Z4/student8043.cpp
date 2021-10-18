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

typedef std::vector<std::string> VektorStringova;

std::string ObrniString(std::string s)
{
	std::string obrnuti;
	for(int i(int(s.length())-1) ; i>=0 ; i--) {
		obrnuti.push_back(s.at(i));
	}
	return obrnuti;
}

bool DaLiJeSlovo(char slovo){
	if((slovo>='A' && slovo<='Z') || (slovo>='a' && slovo<='z')) return true;
	return false;
}

std::string NapraviPalindrom(std::string s,VektorStringova VS)
{

	for(int i(0) ; i<VS.size() ; i++) {
		for(int j(0); j<s.length() ; j++) {
			bool podudaranje(false);
			if(s.at(j)==VS.at(i).at(0)) {
				int l=j;
				int k(0);
				while(l<s.size() && k<VS.at(i).size()) {
					if(s.at(l)!=VS.at(i).at(k)) {
						podudaranje=false;
						break;
					}
					l++;
					k++;
					podudaranje=true;
				}
			} // ako je dosao do kraja ili ako nije poslije rijeci neko slovo
			if(podudaranje){
				int n(VS.at(i).size());
				bool lokalna(true);
				if(j+n==s.length()){
					s.insert(j+n,ObrniString(VS.at(i)));
					j+=2*n-1;
					lokalna=false;
				}
				else if(j+n>s.length()){
					lokalna=false;
				}
				if(lokalna){
					if(!(DaLiJeSlovo(s.at(j+n)))){
					s.insert(j+n,ObrniString(VS.at(i)));
					j+=2*n-1;
				}
				}
			}
		}
	}
	return s;
}

// napravi polupalindrom
// |
// V

std::string NapraviPoluString(std::string s){
	int parametar(0);
	if(s.length()%2!=0){
		parametar=1;
	}
	s.erase((s.length()/2)+parametar);
	return s;
}

std::string ObrniPolaStringa(std::string s)
{
	std::string obrnuti;
	for(int i(0) ; i<s.length()/2 ; i++) {
		obrnuti.push_back(s.at(i));
	}
	return ObrniString(obrnuti);
}

std::string NapraviPoluPalindrom(std::string s,VektorStringova VS)
{

	for(int i(0) ; i<VS.size() ; i++) {
		
		for(int j(0); j<s.length() ; j++) {
			bool podudaranje(false);
			if(s.at(j)==VS.at(i).at(0)) {
				int l=j;
				int k(0);
				while(l<s.size() && k<VS.at(i).size()) {
					if(s.at(l)!=VS.at(i).at(k)) {
						podudaranje=false;
						break;
					}
					l++;
					k++;
					podudaranje=true;
				}
			}
			if(podudaranje) {
				bool lokalna(true); // da se ne provjerava da li nije slovo poslije ako je posljednja rijec
				int n(VS.at(i).size());
				if(j+n==s.length()){
					s.erase(j,VS.at(i).size());
					std::string polupali;
					polupali=NapraviPoluString(VS.at(i))+ObrniPolaStringa(VS.at(i));
					s.insert(j,polupali);
					j+=VS.at(i).size();
					lokalna=false;
				}
				else if(j+n>s.length()){
					lokalna=false;
				}
				if(lokalna){ 
					if(!(DaLiJeSlovo(s.at(j+n)))){
					s.erase(j,VS.at(i).size());
					std::string polupali;
					polupali=NapraviPoluString(VS.at(i))+ObrniPolaStringa(VS.at(i));
					s.insert(j,polupali);
					j+=VS.at(i).size();
				}
				}
				}
			}
		}
	
	return s;
}


int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout << "Unesite fraze: ";
	VektorStringova VS;
	for(;;) {
		std::string prazan_string,s;
		std::getline(std::cin,s);
		if(s==prazan_string) {
			break;
		}
		VS.push_back(s);
	}
	std::string pali(NapraviPalindrom(recenica,VS));
	std::cout << "Recenica nakon Palindrom transformacije: "<< pali << std::endl;
	std::string polupali(NapraviPoluPalindrom(recenica,VS));
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << polupali << std::endl;
	
	
	return 0;
}
