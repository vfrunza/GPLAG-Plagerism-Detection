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
typedef std::vector<std::string> vektor;

std::string NapraviPalindrom(std::string s, vektor v)
{
	int i=0;
	while(i<v.size()) {
		std::string f(v.at(i));
		int d(f.length()), j(0), k(0), br(0);
		while(j<s.length()) {
			while(k<d) {
				if(s.at(j)==f.at(k)) {
					k++;
					br++;
					break;
				}

				if(s.at(j)!=f.at(k)) {
					k=0;
					br=0;
					break;
				}
			}
			if(br==d && ((j==d-1 && s.at(j+1)<'A') || (j==s.length()-1 && s.at(j-d)<'A') || (j>d-1 && j<s.length()-1 && s.at(j+1)<'A' && s.at(j-d)<'A'))) {


				s.resize(s.length()+d);

				for(int x=int(s.length())-1; x>j+d ; x--) s.at(x)=s.at(x-d);
				j++;
				for(int y=d-1 ; y>=0 ; y--) {
					s.at(j)=f.at(y);
					j++;
				}
				br=0;
				k=0;
			}


			j++;
		}
		i++;
	}
	return s;
}
std::string NapraviPoluPalindrom(std::string s, vektor v)
{
	int i=0;
	while(i<v.size()) {
		std::string f(v.at(i));
		int d(f.length()), j(0), k(0), br(0);
		while(j<s.length()) {
			while(k<d) {
				if(s.at(j)==f.at(k)) {
					k++;
					br++;
					break;
				}

				if(s.at(j)!=f.at(k)) {
					k=0;
					br=0;
					break;
				}
			}
			if(br==d && ((j==d-1 && s.at(j+1)<'A') || (j==s.length()-1 && s.at(j-d)<'A') || (j>d-1 && j<s.length()-1 && s.at(j+1)<'A' && s.at(j-d)<'A'))) {
				int a(0);

				for(int x=j ; x>j-d/2 ; x--) {
					s.at(x)=f.at(a);
					a++;
				}
				br=0;
				k=0;
			}


			j++;
		}
		i++;
	}
	return s;
}
int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	vektor v;
	for( ; ; ) {
		std::string s1;
		std::getline(std::cin, s1);
		if(s1=="") break;
		v.push_back(s1);

	}
	std::string p(NapraviPalindrom(s,v));
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	for(int i=0 ; i<p.length() ; i++) std::cout<<p.at(i);
	std::cout<<std::endl;
	std::string pp(NapraviPoluPalindrom(s,v));
	std::cout<<"Recenica nakon PoluPalindrom transformacije: ";
	for(int i=0 ; i<pp.length() ; i++) std::cout<<pp.at(i);
	return 0;

}