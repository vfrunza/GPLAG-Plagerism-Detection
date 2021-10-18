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

std::string PoluPalindrom (std::string s) {
	std::string temp;
	int j(1);
	for (int i=0; i<s.length(); i++) {
		if (i<s.length()/2) {
			temp.push_back(s.at(i));
		}
		else {
			if (i==s.length()/2 && s.length()%2!=0) {
				temp.push_back(s.at(i));
				j++;
			}
			else {
				temp.push_back(s.at(i-j));
				j+=2;
			}
		}
	}
	return temp;
}

std::string Palindrom (std::string s) {
	std::string temp;
	for (int i=s.length()-1; i>=0; i--) temp.push_back(s.at(i));
	return temp;
}

std::string NapraviPoluPalindrom (std::string s, std::vector<std::string> v) {
	
	bool razmak(true);
	
	for (std::string fraza: v) {
		if (s.length()<fraza.length() || fraza.length()==0) continue;
		for (int i=0; i<s.length(); i++) {
			
			if (!((s.at(i)>='A' && s.at(i)<='Z') || (s.at(i)>='a' && s.at(i)<='z'))) razmak=true;
			else {
				std::string temp;
				temp=s.substr(i, fraza.length());
				
				if (razmak && fraza==temp) {
					temp=PoluPalindrom(fraza);
					
					if (i+fraza.length()==s.length()) s.replace(i, fraza.length(), temp);
					else if (i+fraza.length()+1<=s.length()) { if (!((s.at(i+fraza.length())>='A' && s.at(i+fraza.length())<='Z') || (s.at(i+fraza.length())>='a' && s.at(i+fraza.length())<='z'))) s.replace(i, fraza.length(), temp); }
				}
				razmak=false;
			}
		}
		razmak=true;
	}
	return s;
}

std::string NapraviPalindrom (std::string s, std::vector<std::string> v) {
	
	bool razmak(true);
	
	for (std::string fraza: v) {
		if (s.length()<fraza.length() || fraza.length()==0) continue;
		for (int i=0; i<=s.length()-fraza.length(); i++) {
			
			if (!((s.at(i)>='A' && s.at(i)<='Z') || (s.at(i)>='a' && s.at(i)<='z'))) razmak=true;
			else {
				std::string temp;
				temp=s.substr(i, fraza.length());
				
				if (razmak && fraza==temp) {
					temp=Palindrom(fraza);
					if (i+fraza.length()==s.length()) s.append(temp);
					else if (i+fraza.length()+1<=s.length()) { if (!((s.at(i+fraza.length())>='A' && s.at(i+fraza.length())<='Z') || (s.at(i+fraza.length())>='a' && s.at(i+fraza.length())<='z'))) s.insert(i+temp.length(), temp); }
				}
				razmak=false;
			}
		}
		razmak=true;
	}
	return s;
}

int main ()
{
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	
	std::vector<std::string> v;

	std::string s1;
	
	std::cout << "Unesite fraze: ";

	while (std::getline(std::cin, s1), s1.length()!=0) v.push_back(s1);

	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(s, v) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(s, v);
	
	return 0;
}