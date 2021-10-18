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

typedef std::vector<std::string> strniz;

bool jeLiSlovo(char a) {
	return ((a>='A' && a<='Z') || (a>='a' && a<='z'));
}

std::string IzmijeniUPigLatin(std::string s, strniz niyy){
	if(niyy.empty()){
		for(int i(0); i<s.length(); i++){
			while(s[i]==' ') i++;
			int x=i;
			while ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) i++;
			int y=i;
			char temp = s[x];
			s.erase(s.begin() + x);
			s.insert(s.begin() + y - 1, temp);
			s.insert(s.begin() + y, 'a');
			s.insert(s.begin() + y + 1, 'y');
			i+=2;
		}
	}
	for(int i(0); i<niyy.size(); i++){
		std::string temp(niyy[i]);
		for(int j(0); j<temp.length(); j++)
			if(!jeLiSlovo(temp[j])) throw std::domain_error("Nekorektan izbor rijeci");
	}
	for(int i(0); i<niyy.size(); i++)
		for(int j(0); j<s.length(); j++)
			if(s.substr(j, niyy[i].size()) == niyy[i]){
				if(s[j]==s[0] && (s[j+niyy[i].size()]==' ' || (s[j+niyy[i].size()-1]==s[s.length()-1] && int(niyy[i].size()-s.length()) )==0)){
					char temp = s[j];
					s.erase(s.begin() + j);
					s.insert(s.begin() + j + niyy[i].size() - 1, temp);
					s.insert(s.begin() + j + niyy[i].size(), 'a');
					s.insert(s.begin() + j + niyy[i].size() + 1, 'y');
				}
				if(s[j-1]==' ' && (s[j+niyy[i].size()]==' ' || (s[j+niyy[i].size()-1]==s[s.length()-1] && int(j+niyy[i].size()-1 -(s.length()-1) )==0))){
					char temp = s[j];
					s.erase(s.begin() + j);
					s.insert(s.begin() + j + niyy[i].size() - 1, temp);
					s.insert(s.begin() + j + niyy[i].size(), 'a');
					s.insert(s.begin() + j + niyy[i].size() + 1, 'y');
				}
			}
	return s;
}

std::string ObrniFraze(std::string s, strniz niyy){
	for(int i(0); i<int(niyy.size()); i++)
		for(int j(0); j<int(s.length()); j++)
			if(s.substr(j, niyy[i].size()) == niyy[i] && int(niyy[i].size())>1){
				char temp;
				for(int x(j), y(j+niyy[i].size()-1); x<y; x++, y--){
					temp = s[x];
					s[x] = s[y];
					s[y] = temp;
				}
				j=0;
			}
	return s;
}

int main (){
	std::string s;
	strniz niz;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	while(true){
		std::string temp;
		std::getline(std::cin, temp);
		if(temp.empty()) break;
		niz.push_back(temp);
	}
	try{
		std::string plat = IzmijeniUPigLatin(s, niz);
		std::cout << "Recenica nakon PigLatin transformacije: " << plat << std::endl;
		std::string obrni = ObrniFraze(s, niz);
		std::cout << "Recenica nakon obrtanja fraza: " << obrni;
	}
	catch(std::domain_error belaj){
		std::cout << "Izuzetak: " << belaj.what() << std::endl;
		std::string obrni = ObrniFraze(s, niz);
		std::cout << "Recenica nakon obrtanja fraza: " << obrni;
	}
	return 0;
}