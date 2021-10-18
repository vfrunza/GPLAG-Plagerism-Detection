#include <iostream>
#include <string>
#include <vector>

/* Ova funkcija modificira primljeni string, vracajuci njegov polupalindrom.
Npr. za string programirane vrati programargorp */

std::string PoluPalindrom(std::string s)
{
	int i(0);
	int j(s.length()-1);
	while(i<j) {
		s.at(j)=s.at(i);
		i++;
		j--;
	}
	return s;
}

/* Ova funkcija modificira primljeni string, vracajuci njegovu drugu polovinu palindroma.
Npr. za string programirane vrati ejnarimargorp */

std::string Palindrom(std::string s)
{
	std::string pamti(s);
	int i(0);
	int j(s.length()-1);
	while(i<j) {
		char temp(s.at(i));
		s.at(i)=s.at(j);
		s.at(j)=temp;
		i++;
		j--;
	}
	return pamti+s;
}

/* Funkcija NapraviPoluPalindrom kao rezultat vraca modifikovan primljeni string <recenica> u kojem je svaka rijec
koja se poklapa sa nekim od clanova primljenog vektora stringova zamijenjena svojim polupalindromom */

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> vektor)
{
	int razmak(1);
	int k;
	for(int i=0; i<vektor.size(); i++) {
		std::string rijec=vektor.at(i);
		
		for(int j=0; j<recenica.length(); j++) {
			if(recenica.at(j)<'A' || (recenica.at(j)>'Z' && recenica.at(j)<'a') || recenica.at(j)>'z')razmak=1;
			else if(razmak==1) {
				razmak=0;
				k=0;
				int pamti(j);
				while(j!=recenica.length()&& k!=rijec.length() && recenica.at(j)==rijec.at(k)) {
					j++;
					k++;
				}
				if(k==rijec.length() && (j==recenica.length() || recenica.at(j)<'A' || (recenica.at(j)>'Z' && recenica.at(j)<'a') || recenica.at(j)>'z' )) {
					recenica=recenica.substr(0,pamti)+ PoluPalindrom(rijec) +
					         recenica.substr(pamti+rijec.length(),(recenica.length()-(pamti+rijec.length())));
					/* Kada se pronadje podudarna rijec u stringu <recenica> pozivom funkcije PoluPalindrom
					ona se zamijeni svojim polupalindromom. */
				}
             j--;
			}
			
		}
		
	}
	return recenica;
}

/* Funkcija NapraviPalindrom kao rezultat vraca modifikovan primljeni string <recenica> u kojem je svaka rijec
koja se poklapa sa nekim od clanova primljenog vektora stringova zamijenjena svojim palindromom. */

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> vektor)
{
	int razmak(1);
	for(int i=0; i<vektor.size(); i++) {
		std::string rijec=vektor.at(i);
		
		for(int j=0; j<recenica.length(); j++) {
			if(recenica.at(j)<'A'|| (recenica.at(j)>'Z' && recenica.at(j)<'a') || recenica.at(j)>'z') razmak=1;
			else if(razmak==1) {
				razmak=0;
				int k(0);
				int pamti(j);
				while(j!=recenica.length() && k!=rijec.length() && recenica.at(j)==rijec.at(k)) {
					j++;
					k++;
				}
				if(k==rijec.length() && (j==recenica.length() || recenica.at(j)<'A' || (recenica.at(j)>'Z' && recenica.at(j)<'a') || recenica.at(j)>'z' )) {
					recenica=recenica.substr(0,pamti)+Palindrom(rijec) +
					         recenica.substr(pamti + rijec.length(),(recenica.length()-(pamti + rijec.length())));
					/* Kada se pronadje podudarna rijec u stringu <recenica> pozivom funkcije Palindrom
					ona se zamijeni svojim palindromom. */
				}
				j--;
				
			}

		}
	}
	return recenica;
}


int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string> v;
	std::string rijec;
	std::cout<<"Unesite fraze: ";

	do {
		std::string rijec;
		std::getline(std::cin, rijec);
		if(rijec=="") break;
		v.push_back(rijec);
	} while(1);

	std::cout<<"Recenica nakon Palindrom transformacije: "<< NapraviPalindrom(recenica,v) <<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica,v);
	return 0;
}