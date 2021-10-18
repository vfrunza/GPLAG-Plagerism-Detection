/*B 2017/2018, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <string>
#include <iostream>
#include <vector>

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze)
{
	std::string privremeni, palindromisana;
	for(int i=0; i<recenica.length(); i++) palindromisana.push_back(recenica.at(i));
	bool razmak(false), rijec(true), palindromisi(false);

	for(int l=0; l<fraze.size(); l++) {

		bool razmakUFrazi(false);
		for(int k=0; k<fraze.at(l).size(); k++) {
			if(fraze.at(l).at(k)==' ') {
				razmakUFrazi=true;
				break;
			}
		}

		bool pricekaj(false);
		std::string prijeRazmaka;

		if(razmakUFrazi) {
			for(int k=0; k<fraze.at(l).size(); k++) {
				if(fraze.at(l).at(k)==' ') break;
				else prijeRazmaka.push_back(fraze.at(l).at(k));
			}
		}

		for(int i=0; i<palindromisana.length(); i++) {
			if(palindromisana.at(i) == ' ') {
				razmak=true;
				rijec=false;
			}
			if(razmakUFrazi && prijeRazmaka==privremeni) {
				razmak=false;
				rijec=true;
				pricekaj=true;
			}
			if(!razmak && rijec) {
				privremeni.push_back(palindromisana.at(i));
				if(privremeni==fraze.at(l)){
					if(i+1 < palindromisana.length()){
						if((palindromisana.at(i+1)<= 'z' && palindromisana.at(i+1)>='a' )
						|| (palindromisana.at(i+1)<='Z' && palindromisana.at(i+1)>='A')) palindromisi=false;
						else palindromisi = true;
					}
					
					else palindromisi = true;
				} 
			}

			if(palindromisi) {
				std::string naopakPrivremeni;
				for(int j=privremeni.length()-1; j>=0; j--) naopakPrivremeni.push_back(privremeni.at(j));
				palindromisana = palindromisana.substr(0,i+1)+naopakPrivremeni+palindromisana.substr(i+1,palindromisana.length());
			}

			if(razmak && !pricekaj) {
				privremeni.clear();
			}
			pricekaj=false;
			razmak=false;
			palindromisi=false;
			rijec=true;
		}
	}
	return palindromisana;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze)
{
	std::string polupalindromisana, privremeni;
	for(int i=0; i<recenica.length(); i++)polupalindromisana.push_back(recenica.at(i));
	bool razmak(false), rijec(true), polupalindromisi(false);
	for(int l=0; l<fraze.size(); l++) {

		bool razmakUFrazi(false);
		for(int k=0; k<fraze.at(l).size(); k++) {
			if(fraze.at(l).at(k)==' ') {
				razmakUFrazi=true;
				break;
			}
		}

		bool pricekaj(false);
		std::string prijeRazmaka;

		if(razmakUFrazi) {
			for(int k=0; k<fraze.at(l).size(); k++) {
				if(fraze.at(l).at(k)==' ') break;
				else prijeRazmaka.push_back(fraze.at(l).at(k));
			}
		}

		int stani;
		if(fraze.at(l).size()%2==0) stani=fraze.at(l).size()/2;
		if(fraze.at(l).size()%2==1) stani=fraze.at(l).size()/2 + 1;

		for(int i=0; i<polupalindromisana.length(); i++) {
			if(polupalindromisana.at(i) == ' ') {
				razmak=true;
				rijec=false;
			}
			if(razmakUFrazi && prijeRazmaka==privremeni) {
				razmak=false;
				rijec=true;
				pricekaj=true;
			}
			if(!razmak && rijec) {
				privremeni.push_back(polupalindromisana.at(i));
				if(privremeni==fraze.at(l)){
					if(i+1 < polupalindromisana.length()){
						if((polupalindromisana.at(i+1)<= 'z' && polupalindromisana.at(i+1)>='a' )
						|| (polupalindromisana.at(i+1)<='Z' && polupalindromisana.at(i+1)>='A')) polupalindromisi=false;
						else polupalindromisi = true;
					}
					
					else polupalindromisi = true;
				} 
			}
			if(polupalindromisi) {
				std::string naopakPrivremeni;
				for(int j=stani-1; j>=0; j--) naopakPrivremeni.push_back(privremeni.at(j));
				polupalindromisana = polupalindromisana.substr(0,i+1-stani)+naopakPrivremeni+polupalindromisana.substr(i+1,polupalindromisana.length());
			}
			rijec=true;

			if(razmak && !pricekaj) {
				privremeni.clear();
			}
			razmak=false;
			pricekaj=false;
			polupalindromisi=false;
		}
	}
	return polupalindromisana;
}


int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);


	std::vector<std::string> fraze;
	std::cout<<"Unesite fraze: ";


	std::string String;
	bool pamti(false);

	while(std::getline(std::cin, String)) {
		if(std::cin.peek()=='\n')pamti=true;
		fraze.push_back(String);
		if(pamti)break;
	}

	/*for(int i=0; i<fraze.size(); i++) std::cout<<fraze.at(i)<<" ";*/
	std::string recenicaPalindroma(NapraviPalindrom(recenica, fraze));
	std::cout<<"Recenica nakon Palindrom transformacije: "<<recenicaPalindroma<<std::endl;
	std::string recenicaPolupalindroma(NapraviPoluPalindrom(recenica, fraze));
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<recenicaPolupalindroma;
	return 0;
}