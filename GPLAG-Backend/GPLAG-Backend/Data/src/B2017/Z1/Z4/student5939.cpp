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
#include <cstring>

std::string VratiPalindrom (std::string s) {
	
	std::string palindrom;
	
	for (int i=s.length()-1; i>=0; i--) {
		
		palindrom.push_back(s[i]);
		
	}
	
	return palindrom;
	
}
std::string Pronadji (std::string r, std::string s) {
	
	bool nasao(false);
	int j(0);
	
	for(int i=0; i<r.length(); i++) {
		while (i<r.length() && j<s.length() && r[i]==s[j]) {
			i++;
			j++;
		}
		
		bool slovo_poslije(false);
		if ((r[i] >= 'A' && r[i] <= 'Z') || (r[i] >= 'a' && r[i] <= 'z')) slovo_poslije = true;
		if (j==s.length() && (i==r.length() || slovo_poslije == false)) nasao = true;
		
		if(nasao) {
			nasao = false;
			std::string novi;
			novi = VratiPalindrom(s);
			std::string poslije_rijeci, prije_rijeci;
			poslije_rijeci = r.substr(i, r.length());
			prije_rijeci = r.substr(0,i);
			r=prije_rijeci+novi+poslije_rijeci;
			i+=novi.length()-1;
			//break;
		}
		j=0;
	}
	return r;
	
}
std::string NapraviPalindrom(std::string r, std::vector<std::string> v) {
	
	std::string rez(r);
	for (int i=0; i<v.size(); i++) {
		
		rez=Pronadji(rez,v[i]);
		
	}
	
	return rez;
	
}
std::string PronadjiPolu (std::string r, std::string s) {
	
	bool nasao(false);
	int j(0);
	
	for (int i=0; i<r.length(); i++) {
		j=0;
		nasao=false;
		while (i<r.length() && j<s.length() && r[i] == s[j]) {
			i++;
			j++;
		}
		
		bool slovo_poslije(false);
		if ((r[i] >= 'A' && r[i] <= 'Z') || (r[i] >= 'a' && r[i] <= 'z')) slovo_poslije = true;
		if (j==s.length() && (i==r.length() || slovo_poslije == false)) nasao = true;
		
		if (nasao) {
			std::string polu_novi;
			for (int t=(s.length()/2)-1; t >= 0; t--) {
				polu_novi.push_back(s[t]);
			}
			std::string poslije_rijeci, prije_rijeci;
			poslije_rijeci = r.substr(i, r.length());
			prije_rijeci = r.substr(0, i-polu_novi.length());
			r = prije_rijeci + polu_novi + poslije_rijeci;
		}
	}
	return r;
}
std::string NapraviPoluPalindrom(std::string r, std::vector<std::string> v) {
	
	
	std::string rez(r);
	for (int i=0; i<v.size(); i++) {
		
		rez = PronadjiPolu(rez,v[i]);
		
	}
	
	return rez;
}
int main ()
{
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	std::string fr;
	std::vector<std::string> v;
	for (int i=0;;i++) {
			std::getline(std::cin, fr);
			if(fr.length()==0 || fr.length()==1) break;
			v.push_back(fr);
	}
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(s, v) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(s, v);
	return 0;
}