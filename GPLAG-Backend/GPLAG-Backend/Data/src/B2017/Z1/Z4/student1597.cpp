/*#include <iostream>
#include <vector>
#include <string>

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze) {
	for (std::string s : fraze) {
		std:: size_t pos = 0;
		while ((pos = recenica.find(s, pos)) != std::string::npos) {
			pos += s.length();
			std::string pomocni; // obrnuti
			for(int i(s.length() - 1); i >= 0; i--) 
				pomocni += s.at(i);
			recenica.insert(pos, pomocni);
		}
	}
	
	return recenica;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraze) {
	for (std::string s : fraze) {
		int pos = 0;
		while ((pos = recenica.find(s, pos)) != std::string::npos) {
			int temp = pos + s.size();
			pos += s.size() / 2;
			std::string pomocni; // obrnuti
			for(int i(s.size() / 2  - 1); i >= 0; i--) 
				pomocni += s.at(i);
			if (s.size() % 2 != 0) {
				recenica.replace(pos + 1, s.size() / 2, pomocni);
			} else {
				recenica.replace(pos, s.size() / 2, pomocni);
			}
			// std::cout << "pomocni: " << pomocni << std::endl;
			pos = temp;
		}
	}
	// std::cout << recenica;
	return recenica;
}*/

#include <iostream>
#include <vector>
#include <string>

bool Neslovo(char znak) {
	if ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z')) return false;
	else return true;
}

int PronadjiFrazu(std::string recenica, std::string fraza, int poc) {
	for (int i=poc; i<recenica.length(); i++) {
		int prvi(i);
		int drugi(0);
		while (prvi<recenica.length() && (recenica.at(prvi)==fraza.at(drugi))) {
			prvi++;
			drugi++;
			if (drugi==fraza.length()) return i;
		}
	}
	return -1;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> vektor) {
	for (std::string fraza : vektor) {
		int poc(0);
		while (PronadjiFrazu(recenica, fraza, poc)>=0) {
			if ((PronadjiFrazu(recenica, fraza, poc)==0 || Neslovo(recenica.at(PronadjiFrazu(recenica, fraza, poc)-1))) && 
			(PronadjiFrazu(recenica, fraza, poc)+fraza.length()>=recenica.length() || 
			Neslovo(recenica.at(PronadjiFrazu(recenica, fraza, poc)+fraza.length())))) {
				int pocetak=PronadjiFrazu(recenica, fraza, poc);
				pocetak+=fraza.length();
				for (int i=fraza.length()-1; i>=0; i--) {
					recenica.insert(recenica.begin()+pocetak, fraza.at(i));
					pocetak++;
					poc++;
				}
			}
			poc+=fraza.length();
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> vektor) {
	for (std::string fraza : vektor) {
		int poc(0);
		while (PronadjiFrazu(recenica, fraza, poc)>=0) {
			if ((PronadjiFrazu(recenica, fraza, poc)==0 || Neslovo(recenica.at(PronadjiFrazu(recenica, fraza, poc)-1))) && 
			(PronadjiFrazu(recenica, fraza, poc)+fraza.length()>=recenica.length() || 
			Neslovo(recenica.at(PronadjiFrazu(recenica, fraza, poc)+fraza.length())))) {
				int pocetak=PronadjiFrazu(recenica, fraza, poc);
				int duzina=fraza.length();
				if (duzina%2==0) {
					pocetak+=duzina/2;
				}
				else {
					pocetak+=(duzina/2)+1;
				}
				for (int i=duzina/2-1; i>=0; i--) {
					recenica.at(pocetak)=fraza.at(i);
					pocetak++;
				}
			}
			poc+=fraza.length();
		}
	}
	return recenica;
}


int main ()
{
	std::string recenica, fraza;
	std::vector<std::string> vektor;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	while (std::getline(std::cin, fraza) && fraza!="") {
		vektor.push_back(fraza);
	}
	
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, vektor) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, vektor);
	
	return 0;
}