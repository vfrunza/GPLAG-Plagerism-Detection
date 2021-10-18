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

std::string NapraviPalindrom(std::string s, std::vector<std::string> v)
{
	int br {0},indeks {0};
	for(int i=0; i<s.length(); i++) {
		for(int j=0; j<v.size(); j++) {
			if(s.at(i)==v.at(j).at(br)) {
				indeks=i;
				while(i<s.length() && br<v.at(j).length() && s.at(i)==v.at(j).at(br)) {
					
					i++;
					br++;
				}
				if((br==v.at(j).length() && i==s.length()) || (br==v.at(j).length() && i<s.length() && !((indeks!=0)&&std::isalpha(s.at(indeks-1)) ) && !(std::isalpha(s.at(i)))) ) {
					for(int k=v.at(j).length()-1; k>=0; k--) {
						s.insert(s.begin()+i,v.at(j).at(k));
						i++;
					}
					i--;
					br=0;
				} else {
					br=0;
					i=indeks;
					continue;
				}
			}

			else continue;
		}
	}
	return s;
}

std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> v)
{
	int br {0},indeks {0};
	for(int i=0; i<s.length(); i++) {
		for(int j=0; j<v.size(); j++) {
			if(s.at(i)==v.at(j).at(br)) {
				indeks=i;
				while(i<s.length() && br<v.at(j).length() && s.at(i)==v.at(j).at(br)) {
					
					i++;
					br++;
				}
				if((br==v.at(j).length() && i==s.length()) || (br==v.at(j).length() && i<s.length()  && !((indeks!=0)&&std::isalpha(s.at(indeks-1)))  && !(std::isalpha(s.at(i)))) ) {
					i-=v.at(j).length()/2;
					for(int k=v.at(j).length()/2-1; k>=0; k--) {
						s.at(i)=v.at(j).at(k);
						i++;
					}
					i--;
					br=0;
				} else {
					br=0;
					i=indeks;
					continue;
				}
			}

			else continue;
		}
	}
	return s;
}

int main ()
{
	std::string a,x;
	std::vector<std::string> b;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,a);
	std::cout<<"Unesite fraze: ";
	while(1){
	if(std::cin.peek()=='\n') break;
	std::getline(std::cin,x);
	b.push_back(x);
		}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(a,b)<<std::endl<<"Recenica nakon PoluPalindrom transformacije: "
	<<NapraviPoluPalindrom(a,b);
	return 0;
}