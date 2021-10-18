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
std::string obrni(std::string s)
{
	for(int i=0; i<s.length()/2; i++) {
		char temp;
		temp=s.at(s.length()-(i+1));
		s.at(s.length()-(i+1))=s.at(i);
		s.at(i)=temp;
	}
	return s;
}
bool slovo(char k)
{
	if((k>='a' && k<='z' )|| (k>='A' && k<='Z')) return true;
	return false;
}
std::string NapraviPalindrom(std::string s, std::vector<std::string> s1)
{
	int brojac(0);
	if(s1.size()==0) return s;
	if(s.size()==0) return {};
	for(int i=0; i<s1.size(); i++) {
		for(int j=0; j<s1.at(i).size(); j++) {
			for(int k=0; k<s.size(); k++) {
				if(s.at(k)!=s1.at(i).at(j)) continue;
				brojac=0;
				int f(j);
				int m(k);
				while(s1.at(i).at(f)==s.at(k) && k<s.size() && f<s1.at(i).size()) {
					brojac++;
					if(k==s.size()-1 || f==s1.at(i).size()-1)	break;
					k++;
					f++;
				}
				if(s1.at(i).length()==brojac && (k==s.size()-1 || !slovo(s.at(k+1))) && (m==0 || !slovo(s.at(m-1)))){
						std::string pomocni(s1.at(i));
						for(int n=0;n<pomocni.size();n++)
							s.insert(s.begin()+(k+1),pomocni.at(n));
				}
			}
		}
	}
	return s;
}
std::string NapraviPoluPalindrom(std::string s, std::vector<std::string> s1)
{
	int brojac(0);
	if(s.size()==0) return {};
	if(s1.size()==0) return s;
	for(int i=0; i<s1.size(); i++) {
		for(int j=0; j<s1.at(i).size(); j++) {
			for(int k=0; k<s.size(); k++) {
				if(s.at(k)!=s1.at(i).at(j)) continue;
				brojac=0;
				int f(j);
				int m(k);
				while(s1.at(i).at(f)==s.at(k) && k<s.size() && f<s1.at(i).size()) {
					brojac++;
					if(k==s.size()-1 || f==s1.at(i).size()-1)	break;
					k++;
					f++;
				}
				if(s1.at(i).length()==brojac && (k==s.size()-1 || !slovo(s.at(k+1))) && (m==0 || !slovo(s.at(m-1)))){
					std::string pomocni(s1.at(i));
					for(int n=0; n<pomocni.length()/2; n++){
						s.at(k)=pomocni.at(n);
						k--;
					}
				}
				
			}
		}
	}
	return s;
}
int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	bool ovajzadatakmesatrao(true);
	while(ovajzadatakmesatrao) {
		std::string unos;
		std::getline(std::cin,unos);
		if(!unos.empty()) 	fraze.push_back(unos);
		else break;
	}
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,fraze)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica,fraze);
	return 0;
}