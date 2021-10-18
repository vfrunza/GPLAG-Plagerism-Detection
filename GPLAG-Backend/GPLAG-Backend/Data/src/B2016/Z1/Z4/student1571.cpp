#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string obrni_rijec (std::string s) {
	std::string pomocni;
	for (int i=s.length() - 1; i>=0; i--)
		pomocni += s[i];
	s = pomocni;
	return pomocni;
}
int broj_rijeci (std::string s) {
	int broj(0);
	bool neslovo (true);
	for (int i=0; i<s.length(); i++) {
		if (!(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z'))
			neslovo = true;
		else if (neslovo) {
			neslovo = false;
			broj++;
		}
	}
	return broj;
}
std::string pig_latin (std::string s) {
	
	std::string prvo_slovo (s.substr(0, 1));
	std::cout << s;
	std::string ostatak_rijeci (s.substr (1, s.size()-1));
	std::string rijec_pig_latin (ostatak_rijeci + prvo_slovo + "ay");
	
	return rijec_pig_latin;
}

std::string IzmijeniUPigLatin (std::string s, std::vector<std::string> v1) {
	if (s.length() == 0)
		return s;
		
	std::string recenica_pig_latin;
	std::vector<std::string> v (broj_rijeci(s));
	int brojac(0);
	char znak;
	
	for (int i=0; i<v1.size(); i++) {
		if (broj_rijeci (v1[i]) > 1)
			throw ("Izuzetak: Nekorektan izbor rijeci");
	}
	for (int i=0; i<s.length(); i++) { 
		if ((s[i] < 'A') || (s[i] >'Z' && s[i] < 'a') || (s[i] >'z')) {
			brojac++;
			znak = s[i];
		}
		else
		 v[brojac] += s[i];
	}
	
	if (v1.size() == 0) {
		for (int i=0; i<v.size(); i++) {
			recenica_pig_latin += pig_latin(v[i]);
		}
		return recenica_pig_latin;
	}
	
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v1.size(); j++) {
			if (v[i] == v1[j])
				v[i] = pig_latin(v[i]);
		}
	}
	
	/*for (int i=0; i<v.size(); i++) {
		for (int j=0; j<s.length(); j++) {
			std::string pomocni (s.substr(j, v[i].size()));
			if (pomocni == v[i]) {
				pomocni = pig_latin(pomocni);
				int index (0);
				int pocetni (j);
				while (index != pomocni.length()) {
					s [pocetni] = pomocni [index];
					pocetni++;
					index++;
				}
			}
		}
	}*/
	for (int i=0; i<v.size(); i++)
		recenica_pig_latin += v[i] + " ";
		
	return recenica_pig_latin;
	//return s;
}

std::string ObrniFraze (std::string s, std::vector<std::string> v) {
	if (s.length() == 0)
		return s;
	
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<s.length(); j++) {
			std::string pomocni (s.substr (j, v[i].size()));
			if (pomocni == v[i]) {
				pomocni = obrni_rijec(pomocni);
				int index (0);
				int pocetni (j);
				while (index != pomocni.length()) {
					s[pocetni] = pomocni[index];
					pocetni++;
					index++;
				}
			}
		}
	}
	return s;
}

int main ()
{
	std::string s;
	std::string a;
	std::vector<std::string> v;
	std::cout << "Unesite recenicu: ";
	std::getline (std::cin, s);
	std::cout << "Unesite fraze: ";
	
	try {
		for (;;) {
			std::getline (std::cin,a);
			if (!a.length())
				break;
			v.push_back(a);
		}
		for (int i=0; i<v.size(); i++) {
			for (int j=0; j<v[i].size(); j++) {
				if ((v[i][j] > 'Z' && v[i][j] < 'a') || ( v[i][j] < 'A' && v[i][j] != ' ') || v[i][j] > 'z')
					throw std::domain_error ("Nekorektan izbor rijeci");
			}
		}
		try {
			std::string pomocni (IzmijeniUPigLatin(s, v));
			std::cout << "Recenica nakon PigLatin transformacije: " << pomocni;
		}
		catch (const char poruka[]) {
			std::cout << poruka;
		}
		std::cout << std::endl << "Recenica nakon obrtanja fraza: ";
		std::cout << ObrniFraze(s, v);
	}
	catch (std::domain_error poruka) {
		std::cout << poruka.what() << std::endl;
	}
	return 0;
}