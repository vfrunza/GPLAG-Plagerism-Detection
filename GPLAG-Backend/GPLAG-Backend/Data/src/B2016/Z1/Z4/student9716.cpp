/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

bool slovo(char c) {
	if( (c>='A' && c<='Z') || (c>='a' && c<='z')) return true;
	return false;
}

std::string ObrniFraze(std::string s, std::vector<std::string> v)
{
	int cp;
	std::string s1;
	int cp1;
	for(int i=0; i<v.size(); i++) {
		s1=v[i];
		for(int j=0; j<s.length(); j++) {
			for( int k=0; k<s1.length(); k++) {
				if(s[j]!=s1[k]) break;
				else if(s[j]==s1[k]) cp1=j;
				cp=j;
				while(s[j]==s1[k]) {
					j++;
					k++;
				}
				j--;
				if(k==s1.size()) {
					char temp;
					while(cp<j) {
						temp=s[cp];
						s[cp]=s[j];
						s[j]=temp;
						cp++;
						j--;
					}
					j=cp1+1;
				} else break;
			}
		}

	}
	return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v)
{
	std::string s1;
	int cp1;
	int cp;
	int br;
	for(int i=0; i<v.size(); i++) {
		s1=v[i];
		for(int j=0; j<s.length(); j++) {
			for(int k=0; k<s1.length(); k++) {
				br=0;
				if(s[j]!=s1[k]) break;
				else if(s[j]==s1[k]) cp1=j;
				cp=j;
				while(s[j]==s1[k]) {
					j++;
					k++;
					br++;
				}
				br--;
				j--;
				if(k==s1.size() && !slovo(s[j+1]) && !slovo(s[cp-1])) {
					// PIG LATIN IZMJENA
					s=s.substr(0, cp)+s.substr(cp+1, br)+s[cp]+"ay"+s.substr(j+1, s.length()-j);
					j=cp+1;
				}  else break;
			}
		}
	}
	return s;
}




int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector<std::string> lista;
	std::cout<<"Unesite fraze: ";
	for(int i=0; i<lista.size()+1; i++) {
		std::string skupfraza;
		std::getline(std::cin, skupfraza);
		if(skupfraza.size()==0) break;
		lista.resize(lista.size()+1);
		lista[i]=skupfraza;
	}
	std::string s1,s2;
	s1=ObrniFraze(s, lista);
	s2=IzmijeniUPigLatin(s, lista);
	std::cout<<"Recenica nakon PigLatin transformacije: "<<s2<<std::endl;
	std::cout<<"Recenica nakon obrtanja fraza: "<<s1;

	return 0;
}