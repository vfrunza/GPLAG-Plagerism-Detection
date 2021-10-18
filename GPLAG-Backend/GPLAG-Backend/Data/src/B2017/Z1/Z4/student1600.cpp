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
#include <vector>
#include <string>

bool slovo (char x)
{
	bool znak(false);
	if((x>='a' && x<='z') || (x>='A' && x<='Z'))
		znak=true;
	return znak;
}

std::string Palindrom (std::string s)
{
	std::string kopija(s);
	char pom;

	for(int i=0; i<s.size()/2; i++) {
		pom=s.at(i);
		s.at(i)=s.at(s.size()-i-1);
		s.at(s.size()-i-1)=pom;
	}
	kopija+=s;
	return kopija;
}

std::string Polupalindrom (std::string s)
{
	if(s.size()%2==0) {

		std::string a;
		for(int i=0; i<s.size()/2; i++) {
			a.push_back(s.at(i));
		}
		std::string b(a);
		for(int i=a.size()-1; i>=0 ; i--) {
			b.push_back(a.at(i));
		}
		return b;
	}

	else {
		std::string c;
		for(int i=0; i<=s.size()/2; i++) {
			c.push_back(s.at(i));
		}

		std::string d(c);
		for(int i=c.size()-2; i>=0 ; i--) {
			d.push_back(c.at(i));
		}
		return d;
	}
}

std::string NapraviPalindrom (std::string s, std::vector<std::string> v)
{
	std::string pomocna(s);
	std::string transformisana;
	pomocna.insert(pomocna.begin()+0,' ');

	for(int i=0; i<v.size(); i++) {
		for(int j=1; j<pomocna.size(); j++) {
			if(v[i]==pomocna.substr(j,v[i].size()) && j<(pomocna.size()+1-v[i].size()) && ((!slovo(pomocna[j-1]) && !slovo(pomocna[j+v[i].size()])) || j==pomocna.size()-v[i].size())) {
				transformisana=Palindrom(v[i]);
				pomocna.resize(pomocna.size()+v[i].size());

				for(int l=pomocna.size()-1; l>=j+v[i].size(); l--) {
					pomocna[l]=pomocna[l-v[i].size()];
				}
				for(int k=0; k<transformisana.size(); k++) {
					pomocna[j]=transformisana[k];
					j++;
				}
				j--;
			}
		}
	}
	pomocna.erase(pomocna.begin()+0);
	return pomocna;
}
std::string NapraviPoluPalindrom (std::string s, std::vector<std::string> v)
{
	std::string pomocna(s);
	std::string transformisana;
	pomocna.insert(pomocna.begin()+0,' ');

	for(int i=0; i<v.size(); i++) {
		for(int j=1; j<pomocna.size(); j++) {
			if(v[i]==pomocna.substr(j,v[i].size()) && j<(pomocna.size()+1-v[i].size()) && ((!slovo(pomocna[j-1]) && !slovo(pomocna[j+v[i].size()])) || j==pomocna.size()-v[i].size())) {
				transformisana=Polupalindrom(v[i]);

				for(int k=0; k<transformisana.size(); k++) {
					pomocna[j]=transformisana[k];
					j++;
				}
				j--;
			}
		}
	}
	pomocna.erase(pomocna.begin()+0);
	return pomocna;
}

int main ()
{
	std::string a;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,a);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> b;
	for(;;) {
		std::string unos;
		std::getline(std::cin,unos);
		if(unos.size()==0) break;
		b.push_back(unos);
	}

	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<NapraviPalindrom(a,b);

	std::cout<<std::endl;

	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<NapraviPoluPalindrom(a,b);

	return 0;
}
