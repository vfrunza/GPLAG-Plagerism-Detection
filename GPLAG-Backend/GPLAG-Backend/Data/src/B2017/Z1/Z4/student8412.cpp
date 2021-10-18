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
#include<string>
#include<vector>
typedef std::vector<std::string> Vekstr;
std::string izokreni(std::string s)
{
	std::string a;
	for(int i=s.size()-1; i>=0; i--) {
		a.push_back(s.at(i));
	}
	return a;
}
bool NeSlovo(char a)
{
	if(!((a>='A' and a<='Z') or(a>='a' and a<='z'))) return 1;
	return 0;
}
std::string NapraviPalindrom(std::string a,Vekstr b)
{

	for(int i=0; i<b.size(); i++) {
		for(int j=0; j<a.size(); j++) {
			if((a.at(j)>='A' and a.at(j)<='Z') or(a.at(j)>='a' and a.at(j)<='z')) {
					if(a.substr(j,b.at(i).size())==b.at(i) && ((j==0 or NeSlovo(a.at(j-1))) && (j+b.at(i).size()==a.size() or NeSlovo(a.at(j+b.at(i).size()))))) {
					a.insert(j+b.at(i).size(),izokreni(b.at(i)));
				}
			}
		}

	}

	return a;
}

std::string NapraviPoluPalindrom(std::string a,Vekstr b)
{
	for(int i=0; i<b.size(); i++) {
		for(int j=0; j<a.size(); j++) {

			if((a.at(j)>='A' and a.at(j)<='Z') or(a.at(j)>='a' and a.at(j)<='z')) {
				if(a.substr(j,b.at(i).size())==b.at(i) && ((j==0 or NeSlovo(a.at(j-1))) && (j+b.at(i).size()==a.size() or NeSlovo(a.at(j+b.at(i).size()))))) {
					if(b.at(i).size()%2==0) {
						int n=j+b.at(i).size()/2;
						for(int k=0; k<b.at(i).size()/2; k++) {
							a.erase(a.begin()+n);

						}
						a.insert(j+b.at(i).size()/2,izokreni(a.substr(j,b.at(i).size()/2)));
					} else {

					int n=j+b.at(i).size()/2+1;
					for(int k=0; k<b.at(i).size()/2; k++) {
						a.erase(a.begin()+n);

					}
					a.insert(j+b.at(i).size()/2+1,izokreni(a.substr(j,b.at(i).size()/2)));
				}

			}
		}


	}

}

return a;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin,s);
	std::string p;
	Vekstr b;
	std::cout<<"Unesite fraze: ";
	for(int i=0; ; i++) {
		std::getline(std::cin,p);
		if(p.size()==0) break;
		b.push_back(p);


	}
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<NapraviPalindrom(s,b);


	std::cout<<std::endl<<"Recenica nakon PoluPalindrom transformacije: ";
	std::cout<<NapraviPoluPalindrom(s,b);
//Recenica nakon PoluPalindrom transformacije:


	return 0;
}