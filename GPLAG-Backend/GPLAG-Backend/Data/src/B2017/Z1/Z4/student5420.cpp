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

std::string ObrniString (std::string s) {
	std::string o;
	for (int i=s.length()-1; i>=0; i--) o.push_back(s.at(i));
	return o;
}
/*
int PrebrojiRijeci (std::string s) {
	int br(0);
	for (int i=0; i<s.length(); i++) {
		if (s.at(i)>='a' && s.at(i)<='z' || s.at(i)>='A' && s.at(i)<='Z') {
			while ((s.at(i)>='a' && s.at(i)<='z' || s.at(i)>='A' && s.at(i)<='Z') && i<s.length()-1) i++;
			br++;
			if(i==s.length()-1) return br;
		}
	}
	return br;
}
*/
std::string NapraviPalindrom (std::string s, std::vector<std::string> v) {
	if (v.size()==0) return s;
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<s.length(); j++) {
			int r;
			for (int k=s.length()-1; k>0; k--) {
				while (s.at(k)!=' ') k--;
				r=k+1;
				break;
			}
			if (v.at(i)==s.substr(j,v.at(i).length()) && (j==0 || s.at(j-1)==' ') && (j==r && s.at(j+v.at(i).length()-1)==s.at(s.length()-1) || j!=r && s.at(j+v.at(i).length())==' ')) {
				std::string s1(ObrniString(v.at(i)));
				int p=j+v.at(i).length();
				s=s.substr(0,p)+s1+s.substr(p,s.length()-p);
				j=p;
			}
		}
	}
	return s;
}

std::string NapraviPoluPalindrom (std::string s, std::vector<std::string> v) {
	if (v.size()==0) return s;
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<s.length(); j++) {
			int r;
			for (int k=s.length()-1; k>0; k--) {
				while (s.at(k)!=' ')k--;
				r=k+1;
				break;
			}
			if (v.at(i)==s.substr(j,v.at(i).length()) && (j==0 || s.at(j-1)==' ') && (j==r && s.at(j+v.at(i).length()-1)==s.at(s.length()-1) || j!=r && s.at(j+v.at(i).length())==' ') ) {
				std::string s1(ObrniString(v.at(i).substr(0,v.at(i).length()/2)));
				if (v.at(i).length()%2==0) {
					int p=j+v.at(i).length()/2;
					s=s.substr(0,p)+s1+s.substr(p+v.at(i).length()/2,s.length()-p);
				}
				else { 
					int p=j+v.at(i).length()/2+1;
					s=s.substr(0,p)+s1+s.substr(p+v.at(i).length()/2,s.length()-p);
				}
			} 
		}
	}
	return s;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::vector<std::string> fraze;
	std::cout << "Unesite fraze: ";
	
	std::string fraza;
	for (;;) {
		if (std::cin.peek()=='\n') break;
		std::getline(std::cin,fraza);
		fraze.push_back(fraza);

	}
	std::string p(NapraviPalindrom(recenica,fraze));
	std::cout << "Recenica nakon Palindrom transformacije: " << p << std::endl;
	std::string pp(NapraviPoluPalindrom(recenica,fraze));
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << pp;
	return 0;
}