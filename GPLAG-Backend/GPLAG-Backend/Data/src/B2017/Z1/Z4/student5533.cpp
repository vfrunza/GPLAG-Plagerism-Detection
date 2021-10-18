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
#include <cctype>
std::string ObrniString (std::string s)
{
	int c(0);
	for (int i=0; i<s.length(); i++) {
		if (i==s.length()-1) {
			int k=i+1;
			char pom;
			for (int j=0; j<(k-c)/2; j++) {
				pom= (s.at(c+j));
				s.at(c+j)=s.at(k-1-j);
				s.at(k-1-j)=pom;
			}
			c=k+1;
		}
	}
	return s;
}

std::string PoluPal (std::string s)
{
	for (int i=0; i<s.length(); i++) {
		if (s.length()%2==0) {
			if (i==(s.length())/2) {
				s=s.substr(0,i)+ObrniString(s.substr(0,i));
			}
		}
		else {
			if (i==(((s.length())/2)+1)) {
				s=s.substr (0, i) + ObrniString (s.substr (0,i-1));
			}
			
		}
	}
	return s;
}

std::string NapraviPalindrom (std::string s, std::vector <std::string> v)
{
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v.at(i).size(); j++) {
			for (int k=0; k<s.size(); k++) {
				if ( (s.at(k)==v.at(i).at(j)) && (k==0 || s.at(k-1)==' ')) {
					int p(0);
					while ((s.at(k)==v.at(i).at(p)) && (p!=v.at(i).size())) {
						k++;
						p++;
						if(p==v.at(i).size() || k==s.size()-1)break;
					}
					if ((p==v.at(i).size() && (toupper(s.at(k))<'A' || toupper(s.at(k))>'Z')) || (k==s.size()-1 && p==v.at(i).size()-1)) {
						if(k==s.size()-1) k++;
						s=s.substr (0,k) + ObrniString (v.at(i)) + s.substr (k, s.size()-k);
					}
				}
			}
			break;
		}
    }
	return s;
}

std::string NapraviPoluPalindrom (std::string s, std::vector <std::string> v) {
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v.at(i).size(); j++) {
			for (int k=0; k<s.size(); k++) {
				if ( (s.at(k)==v.at(i).at(j)) && (k==0 || s.at(k-1)==' ')) {
					int c=k;
					int p(0);
					while ((s.at(k)==v.at(i).at(p)) && (p!=v.at(i).size())) {
						k++;
						p++;
						if(p==v.at(i).size() || k==s.size()-1)break;
					}
					if ((p==v.at(i).size() && (toupper(s.at(k))<'A' || toupper(s.at(k))>'Z')) || (k==s.size()-1 && p==v.at(i).size()-1)) {
						if(k==s.size()-1)k++;
						s=s.substr (0,c) + PoluPal(v.at(i)) + s.substr (k, s.size()-k);
					}
				}
			}
			break;
		}
    }
	return s;
}

int main ()
{
    std::vector<std::string> v;
	std::string rijec;
	std::string s;
	std::cout << "Unesite recenicu: ";
	std::getline (std::cin, s);
	std::string s1=s;
	std::cout << "Unesite fraze: ";
	std::getline (std::cin, rijec);
	while (1) {
		if (rijec.size()==0) break;
		v.push_back (rijec);
		std::getline (std::cin, rijec);
	}
	
	std::cout <<"Recenica nakon Palindrom transformacije: ";
	s=NapraviPalindrom(s,v);
    std::cout<<s<<std::endl;
    std::cout <<"Recenica nakon PoluPalindrom transformacije: ";
    s=NapraviPoluPalindrom(s1,v);
    std::cout<<s<<std::endl;
	return 0;
}