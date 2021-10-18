/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

typedef std::vector<std::string> VektorStringova;

bool Alfabet(const char slovo) {
	return((slovo >= 'A' && slovo <= 'Z') || (slovo >= 'a' && slovo <= 'z'));
}

bool NisuSlova(VektorStringova popis) {
	for(int i=0; i<popis.size(); i++) 
		for(int j=0; j<popis[i].size(); j++)
			if(!(Alfabet(popis[i][j])))
				return true;
	return false;
}

std::string ObrniSlova(std::string s1) {
	std::string s2;
	for(int i=s1.size()-1; i>=0; i--)
		s2.push_back(s1[i]);
	return s2;
}

std::string ObrniFraze(std::string s, VektorStringova popis) {
	for(int i=0; i<popis.size(); i++) {
		if(popis[i].size() == 1) continue;
		std::string fraza(popis[i]);
			for(int k=0; k<s.size(); k++) 
				if(s[k] == fraza[0]) {
					int poc(k), r(0);
					while(r<fraza.size() && k<s.size() && s[k] == fraza[r]) {
						k++; r++; 
					}
					if(r == fraza.size())
						s = s.substr(0, poc) + ObrniSlova(s.substr(poc, k-poc)) + s.substr(k, s.size()-k);
					k--;
				}
	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, VektorStringova popis) {
	if(NisuSlova(popis)) throw std::domain_error("Nekorektan izbor rijeci");
	
	int vel(popis.size());
	if(popis.size() == 0) 
		vel++;
		
	for(int i=0; i<vel; i++) {
		std::string iz_popisa;
		if(popis.size() == 0) iz_popisa = "\n"; 
		else iz_popisa = popis[i];
		
		int poc(0);
		for(int j=0; j<s.size(); j++) 
			if(Alfabet(s[j])) {
				poc = j;
				break;
			}
		for(int j=poc; j<s.size(); j++) {
			if(j == s.size()-1 || !(Alfabet(s[j]))) { 
				int k(j); 
				if(j == s.size()-1 && Alfabet(s[j])) k++;  
				while(j < s.size() && !(Alfabet(s[j]))) j++;   
				
				std::string rijec(s.substr(poc, k-poc));
				if(iz_popisa == "\n" || iz_popisa == rijec) { 
					s = s.substr(0, poc) + rijec.substr(1, k-poc-1) + rijec[0] + "ay" + s.substr(k, s.size()-k);

					nije_pomjeren = true;
					while(j < s.size() && Alfabet(s[j])) j++;
					
					for(int r=j+1; r<s.size(); r++) {
						if(Alfabet(s[r])) {
							nije_pomjeren = false;
							poc = r;
							break;
						}
					}
					if(iz_popisa == "\n") {
						while(poc < s.size() && Alfabet(s[poc])) poc++;
						while(poc < s.size() && !(Alfabet(s[poc]))) poc++;
						if(poc >= s.size()) break;
					}
				}
				else poc = j;
			}
		}
		if(Alfabet(s[s.size()-1]) && (s.substr(s.size()-1, 1) == iz_popisa || iz_popisa == "\n")) {
			s += "ay";
			break;
		}
	}
	return s;
}

/*std::string ObrniFraze(std::string s, VektorStringova popis) {
	std::string recenica;
	int poc(0), br_slova(0);
	bool jok(true);
	for(int i=0; i<=s.size(); i++) {
		if(i == s.size() || s[i] == ' ') {
			if(poc != 0) recenica.push_back(' ');
			std::string rijec(s.substr(poc, br_slova));
			jok = true;
			for(int j=0; j<popis.size(); j++)  
				if(rijec == popis[j]) { 
					recenica += ObrniSlova(rijec);
					jok = false;
					break;
				}
			if(jok) recenica += rijec;
			poc = i+1;
			br_slova = 0;
		}
		else br_slova++;
			
	}
	return recenica;
} */

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	VektorStringova popis;
	std::cout << "Unesite fraze: ";
	for(int i=0; i<popis.size()+1; i++) {
		std::string fraza;
		std::getline(std::cin, fraza);
		if(fraza.size() == 0) break;
		popis.push_back(fraza);
	}
	try {
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, popis) << std::endl;
	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, popis);
	return 0;
}