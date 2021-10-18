/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string>v) {
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<s.length(); j++) {
			if ((v[i]==s.substr(j, v[i].size()))) {
				for (int k=0; k<v[i].size()/2; k++) {
					char pomocni(s[j+k]);
					s[j+k]=s[j+v[i].size()-k-1];
					s[j+v[i].size()-k-1]=pomocni;
				}
			}
			else continue;
		}
	}

	return s;
}
std::string IzmijeniUPigLatin (std::string s, std::vector<std::string>v) {
	if (v.size()==0) {
		int i, j;
		for (i=0; i<s.length(); i++) {
			while (i<s.length()) {
				if ((s[i]>='A' && s[i]<='Z')||(s[i]>='a' &&s[i]<='z'))
				break;
				i++;
				}
			if (i==s.length()) break;
			j=i;
			while (j<s.length()) {
				if((s[j]<'A' || (s[j]>'Z' && s[j]<'a') || s[j]>'z')) break;
					j++;
			}
			s.insert(s.begin()+j, s[i]);
			s.erase(s.begin()+i);
			s.insert(s.begin()+j, 'a');
			s.insert(s.begin()+j+1, 'y');
			i=j+2;
		}
	}
	else {
		for (int i=0; i<v.size(); i++) {
			for (int j=0; j<v[i].length(); j++) {
				if ((v[i][j]<'A' || v[i][j]>'Z') && (v[i][j]<'a' || v[i][j]>'z'))
					throw std::domain_error ("Nekorektan izbor rijeci");
			}
		}
		for (int i=0; i<v.size(); i++) {
			for (int j=0; j<s.length(); j++) {
				if (v[i]==s.substr(j, v[i].size())) {
					bool ista=false;
					if (j==0){
						if (s[v[i].length()]==' ') ista=true;
					}
					else if (s[j-1]==' ' && s[v[i].length()+j]==' ') ista=true;
					else if (v[i].length()+j==s.length()) {
						if (s[j-1]==' ') ista=true;
					}
					if (ista) {
						s.insert(s.begin()+j+v[i].length(), s[j]);
						s.erase(s.begin()+j);
						s.insert(s.begin()+j+v[i].length(), 'a');
						s.insert(s.begin()+j+v[i].length()+1, 'y');
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
	std::string s;
	std::getline(std::cin, s);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string>v; 
	int brojac(0);
	while (std::cin.peek()!='\n') {
		v.resize(v.size()+1);
		std::getline(std::cin, v[brojac]);
		brojac++;
	}
	try {
		std::string a(IzmijeniUPigLatin(s,v));
		std::cout<<"Recenica nakon PigLatin transformacije: "<<a<<std::endl;
	}catch (std::domain_error a) {
		std::cout<<"Izuzetak: "<<a.what()<<std::endl;
	}
	std::string x(ObrniFraze(s,v));
	std::cout<<"Recenica nakon obrtanja fraza: "<<x<<std::endl;
	return 0;
}