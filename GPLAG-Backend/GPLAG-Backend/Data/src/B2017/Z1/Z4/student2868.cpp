#include <iostream>
#include <string>
#include <vector>

std::vector<int> PronadjiPozStr(std::string v, std::string p, bool fja)
{
	std::vector<int> rez;
	for (int i = 0; i < v.length(); i++) {
		if(v.at(i)==p.at(0) && (i==0 || (!((v.at(i-1)>='A' && v.at(i-1)<='Z')||(v.at(i-1)>='a' && v.at(i-1)<='z'))))) {
			int k(i);
			int j;
			for (j = 1; j < p.length() && k+1 < v.length(); j++) {
				k++;
				if (v.at(k)!=p.at(j))
					break;
			}
			if (j==p.length() && ((k+1==v.length()) || (!((v.at(k+1)>='A' && v.at(k+1)<='Z')||(v.at(k+1)>='a' && v.at(k+1)<='z'))))) {
				if (fja)
					rez.push_back(i+j+(rez.size()*j));
				else {
					if (j%2==0)
						rez.push_back(i+j/2);
					else
						rez.push_back(1+i+j/2);
				}
			}
		}
	}
	return rez;
}

std::string ObrniString(std::string v)
{
	std::string ob_v;
	for (int i = v.length()-1; i >= 0; i--) {
		ob_v.push_back(v.at(i));
	}
	return ob_v;
}

std::string NapraviPalindrom(std::string rec, std::vector<std::string> fraze)
{
	for (int i = 0; i < fraze.size(); i++) {
		std::vector<int> pom=PronadjiPozStr(rec, fraze.at(i), true);
		if (pom.size()==0)
			fraze.erase(fraze.begin()+i);
	}
	for (int i = 0; i < fraze.size(); i++) {
		std::vector<int> pom=PronadjiPozStr(rec, fraze.at(i), true);
		if (pom.size()!=0) {
			std::string obrnut(ObrniString(fraze.at(i)));
			for (int j = 0; j < pom.size(); j++)
				rec.insert(pom.at(j),obrnut);
		}

	}
	return rec;
}

std::string PrepoloviStringiObrni(std::string v)
{
	v.resize(v.length()/2);
	return ObrniString(v);
}

std::string NapraviPoluPalindrom(std::string rec, std::vector<std::string> fraze)
{
	for (int i = 0; i < fraze.size(); i++) {
		std::vector<int> pom=PronadjiPozStr(rec, fraze.at(i), true);
		if (pom.size()==0)
			fraze.erase(fraze.begin()+i);
	}
	for (int i = 0; i < fraze.size(); i++) {
		std::vector<int> pom=PronadjiPozStr(rec, fraze.at(i), false);
		if (pom.size()!=0) {
			std::string obrnut_2(PrepoloviStringiObrni(fraze.at(i)));
			for (int j = 0; j < pom.size(); j++) {
				for (int k = 0; k < obrnut_2.length(); k++) {
					rec.at(pom.at(j)++)=obrnut_2.at(k);
				}
			}
		}

	}
	return rec;
}

int main ()
{
	std::string rec;

	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, rec);

	std::vector<std::string> fraze;
	std::cout << "Unesite fraze: ";
	for (int i = 0; ; i++) {
		fraze.resize(i+1);
		std::getline(std::cin, fraze.at(i));
		if (fraze.at(i).length()==0) {
			fraze.erase(fraze.begin()+i);
			break;
		}
	}

	std::cout << "Recenica nakon Palindrom transformacije: ";
	std::cout << NapraviPalindrom(rec, fraze);

	std::cout << "\nRecenica nakon PoluPalindrom transformacije: ";
	std::cout << NapraviPoluPalindrom(rec, fraze);
	return 0;
}