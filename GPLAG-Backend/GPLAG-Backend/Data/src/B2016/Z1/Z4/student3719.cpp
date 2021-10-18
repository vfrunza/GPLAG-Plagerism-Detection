/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze(std::string recenica, std::vector<std::string> v) {
	
	int vel=v.size();
	for(int i(0); i<vel; i++) {
		for(int j(0); j<(int)recenica.size(); j++) {
			if(recenica.substr(j, v[i].size())==v[i]) {
					std::string nova_recenica=recenica.substr(j, v[i].size());
					int k=v[i].size()-1;
					int b=0;
					while(b<v[i].size()) {
						char slovo=v[i][k];
						recenica[j++]=slovo;
						k--;
						b++;
					}
			}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> v) {
	
	for(auto x : v) {
	for(int s(0); s<x.size(); s++) 
		if(!((x[s]>='a' && x[s]<='z') || (x[s]>='A' && x[s]<='Z')))
			throw std::domain_error("Nekorektan izbor rijeci");
	}
		for(int i(0); i<(int)v.size(); i++) {
			for(int j(0); j<(int)recenica.size(); j++) {
				if(recenica.substr(j, v[i].size())==v[i]) {
					std::string slovo;
					slovo=recenica[j];
					recenica.erase(j, 1);
					recenica.insert(j+v[i].size()-1, slovo + "ay");
	
				}
			}
		}
	return recenica;
}

int main ()
{
	try {
		std::string recenica;
		std::cout << "Unesite recenicu: ";
		std::getline(std::cin, recenica);
		
		std::vector<std::string> v;
		std::cout << "Unesite fraze: ";
			
		while(3) {
			std::string fraza;
			std::getline(std::cin, fraza);
			v.push_back(fraza);
			if(fraza.size()=='\n') break;
			if(std::cin.peek()=='\n') break;
		}
		
		std::cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, v) << std::endl;
		
		std::cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, v) << std::endl;
		
	}
	catch(std::domain_error e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}