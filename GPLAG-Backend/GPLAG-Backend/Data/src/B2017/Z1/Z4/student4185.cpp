#include <iostream>
#include <vector>
#include <string>

typedef std::string string;
typedef std::vector<std::string> vekstring;

string NapraviPalindrom(string s, vekstring vs)
{
	int brojac(0), k(0);
	while(k < vs.size()) {
		if(s.size() < vs.at(brojac).length()) {
			k++;
			brojac ++;
			continue;
		}
	for(int i = 0; i < s.size(); i++) {
		if(s.at(i) == vs.at(brojac).at(0)) {
			int duzina(vs.at(brojac).length());
			if((s.substr(i, duzina) == vs.at(brojac)) && (i + duzina == s.length() || !((s.at(i + duzina) >= 'a' && s.at(i + duzina) <= 'z') || (s.at(i + duzina) >= 'A' && s.at(i + duzina) <= 'Z')))) {
			if(i == 0 || !((s.at(i - 1) >= 'a' && s.at(i - 1) <= 'z') || (s.at(i - 1) >= 'A' && s.at(i - 1) <= 'Z'))) {
				string s1;
				for(int j = vs.at(brojac).length()-1; j >= 0; j--) {
					s1.push_back(vs.at(brojac).at(j));
					}
					s.insert(i + vs.at(brojac).length(), s1);
					i += 2*vs.at(brojac).length();
					}
				}
			
			}
			
		}
		k++;
		brojac++;
	}
	return s;
}

string NapraviPoluPalindrom(string s, vekstring vs)
{
	int brojac(0), k(0);
	while(k < vs.size()) {
		if(s.size() < vs.at(brojac).length()) {
			k++;
			brojac ++;
			continue;
		}
		
	for(int i = 0; i < s.size(); i++) {
		if(s.at(i) == vs.at(brojac).at(0)) {
			int duzina(vs.at(brojac).length());
			if((s.substr(i, duzina) == vs.at(brojac)) && ((i + duzina == s.length()) || !((s.at(i + duzina) >= 'a' && s.at(i + duzina) <= 'z') || (s.at(i + duzina) >= 'A' && s.at(i + duzina) <= 'Z')))) {
				if(i == 0 || !((s.at(i - 1) >= 'a' && s.at(i - 1) <= 'z') || (s.at(i - 1) >= 'A' && s.at(i - 1) <= 'Z'))) {
				if(vs.at(brojac).size()%2 == 0) {
				int d(vs.at(brojac).size()/2);
				for(int j = i + (vs.at(brojac).size()/2 - 1); j >= i; j--) {
					s.at(i + d) = s.at(j);
					d++;
					}
				} else {
				int d(vs.at(brojac).size()/2 + 1);
				for(int j = i + (vs.at(brojac).size()/2 - 1); j >= i; j--) {
					s.at(i + d) = s.at(j);
					d++;
						}
					}
					i += vs.at(brojac).length();
				}
			   }
			}
			
		}
		k++;
		brojac++;
	}
	return s;
}


int main ()
{ 
	string s;
	vekstring v_s;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	int brojac(0);
	for(;;) {
		string s1;
		std::getline(std::cin, s1);
		v_s.push_back(s1);
		if(v_s.at(brojac).size() == 0) {
			v_s.erase(v_s.begin() + brojac + 1);
			break;
		}
		brojac++;
	}
	string s2 = NapraviPalindrom(s,v_s);
	std::cout << "Recenica nakon Palindrom transformacije: " << s2 << std::endl;
	s2 = NapraviPoluPalindrom(s,v_s);
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << s2;
	
	
	return 0;
}