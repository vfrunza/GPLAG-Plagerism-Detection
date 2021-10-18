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
#include<stdexcept>

typedef std::vector<double> vektor;

using std::cout;
using std::cin;

std::string ObrniFraze (std::string s, std::vector<std::string> fraze)
{
	for(int i=0; i<fraze.size(); i++) {
		for(char x: fraze[i]) {
			if((x<'A' or (x>'Z' and x<'a') or x>'z') and x!=' ') throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	for(int i=0; i<fraze.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(fraze.at(i)==s.substr(j, fraze.at(i).length())) {
				for(int k=j; k<j+fraze.at(i).length()/2; k++) {
					char temp;
					temp=s[k];
					s[k]=s[j+fraze.at(i).length()-1-(k-j)];
					s[j+fraze.at(i).length()-1-(k-j)]=temp;
				}
			}
		}
	}
	return s;
}

std::string IzmijeniUPigLatin (std::string s, std::vector<std::string> rijeci)
{
	if(s.length()==0)return s;
	for(int i=0; i<rijeci.size(); i++) {
		for(char x: rijeci[i]) {
			if(x<'A' or (x>'Z' and x<'a') or x>'z') throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}
	for(int i=0; i<rijeci.size(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(rijeci.at(i)==s.substr(j, rijeci.at(i).length())) {
				if(j!=0 and ((s.at(j-1)>'A' and s.at(j-1)<'Z') or (s.at(j-1)>'a' and s.at(j-1)<'z'))) continue;
				char temp(s.at(j+rijeci.at(i).length()-1));
				s.at(j+rijeci.at(i).length()-1)=s.at(j);
				for(int k=j; k<j+rijeci.at(i).length(); k++) {
					if(k==j+rijeci.at(i).length()-2) {
						s.at(k)=temp;
						break;
					}
					s.at(k)=s.at(k+1);
				}
				s.insert(s.begin()+j+rijeci.at(i).length(), 'y');
				s.insert(s.begin()+j+rijeci.at(i).length(), 'a');
			}
		}
	}
	if(rijeci.size()==0) {
		for(int i=0; i<s.length(); i++) {
			int j(i);
			if(s.at(i)==' ') continue;
			while(j<int(s.length()) and ((s.at(j)>='A' and s.at(j)<='Z') or (s.at(j)>='a' and s.at(j)<='z'))) j++;
			int duzina(j-i);
			j--;
			char temp(s.at(j));
			s.at(j)=s.at(i);
			for(int k=i; k<i+duzina; k++) {
				if(k==i+duzina-2) {
					s.at(k)=temp;
					break;
				}
				s.at(k)=s.at(k+1);
			}
			s.insert(s.begin()+i+duzina, 'y');
			s.insert(s.begin()+i+duzina, 'a');
		}
	}

	return s;
}

int main ()
{
	/*cout << "Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	cin.ignore(100, '\n');
	cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string temp;
	for(;;){
		std::getline(std::cin, temp);
		if(temp.length()==0) break;
		else fraze.push_back(temp);
	}*/
	std::string s {"esma se zovem"};
	std::vector<std::string> fraze;
	try {
		cout << "Recenica nakon PigLatin transformacije: " <<  IzmijeniUPigLatin(s, fraze) << std::endl;
	} catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	try {
		cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(s, fraze);
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}