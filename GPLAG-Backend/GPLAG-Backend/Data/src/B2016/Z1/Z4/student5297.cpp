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

std::string obrni (std::string recenica, std::string fraza, int mjesto_promjene) {
	int j(0);
	while(j<fraza.length()/2) {
		char pomocni=recenica[mjesto_promjene+j];
		recenica[mjesto_promjene+j]=recenica[mjesto_promjene+fraza.length()-1-j];
		recenica[mjesto_promjene+fraza.length()-1-j]=pomocni;
		j++;
	}
	return recenica;
}

std::string ObrniFraze (std::string recenica, std::vector<std::string> vektor) {
	for(int i(0); i<vektor.size(); i++) {
		if(vektor[i].size()==0) continue;
		std::string fraza=vektor[i];
		int j(0);
		while(j<recenica.length()) {
			if(recenica[j]==fraza[0]) {
				int mjesto_promjene=j; 
				int mjesto=mjesto_promjene;
				int s(0);
				while(recenica[mjesto_promjene]==fraza[s] && mjesto_promjene<recenica.length() && s<fraza.length()) {
					mjesto_promjene++;
					s++;
				}
				if(s==fraza.length()) recenica=obrni(recenica, fraza, mjesto);
				j+=fraza.length()/2-1;
			}
			j++;
		}
	}
	return recenica;
}

std::string obrnipig (std::string recenica, std::string rijec, int mjesto_promjene) {
	int j(0);
	char pomocni=recenica[mjesto_promjene+0];
	while(j<rijec.length()-1) {
		recenica[mjesto_promjene+j]=recenica[mjesto_promjene+j+1];
		j++;
	}
	recenica[mjesto_promjene+j]=pomocni;
	j++;
	return recenica.substr(0, mjesto_promjene+j) + "ay" + recenica.substr(mjesto_promjene+j, recenica.length());
}

std::vector<std::string> sveizmijeni (std::string recenica) {
	std::vector<std::string> vektor;
	int i(0);
	while(i<recenica.length()) {
		while(!((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && i<recenica.length()) i++;
		std::string rijec;
		if((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) {
			while(((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z')) && i<recenica.length()) {
			rijec.push_back(recenica[i]);
			i++;
			}
			vektor.push_back(rijec);
		}
		if(i==recenica.length()) break;
		i++;
	}
	return vektor;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> vektor) {
	if(vektor.size()==1 && vektor[0].length()==0) {
		vektor=sveizmijeni(recenica);
	}
	for(int i(0); i<vektor.size(); i++) {
		if(vektor[i].size()==0) continue;
		std::string rijec=vektor[i];
		int j(0);
		while(j<recenica.length()) {
			if(j==0) {
				if(recenica[j]==rijec[0] && (j+rijec.length()<=recenica.length() && !((recenica[j+rijec.length()]>='A' && recenica[j+rijec.length()]<='Z') || (recenica[j+rijec.length()]>='a' && recenica[j+rijec.length()]<='z')))) {
					int mjesto_promjene=j;
					int mjesto=mjesto_promjene;
					int s(0);
					while(recenica[mjesto_promjene]==rijec[s] && mjesto_promjene<recenica.length() && s<rijec.length()) {
						mjesto_promjene++;
						s++;
					}
					if(s==rijec.length()) recenica=obrnipig(recenica, rijec, mjesto);
					j+=rijec.length()+2;
				}
			} else {
				if(recenica[j]==rijec[0] && !((recenica[j-1]>='A' && recenica[j-1]<='Z') || (recenica[j-1]>='a' && recenica[j-1]<='z'))  && (j+rijec.length()<=recenica.length() && !((recenica[j+rijec.length()]>='A' && recenica[j+rijec.length()]<='Z') || (recenica[j+rijec.length()]>='a' && recenica[j+rijec.length()]<='z')))) {
					int mjesto_promjene=j;
					int mjesto=mjesto_promjene;
					int s(0);
					while(recenica[mjesto_promjene]==rijec[s] && mjesto_promjene<recenica.length() && s<rijec.length()) {
						mjesto_promjene++;
						s++;
					}
					if(s==rijec.length()) recenica=obrnipig(recenica, rijec, mjesto);
					j+=rijec.length()+2;
				}
			}
			j++;
		}
	}
	return recenica;
}

bool Slova (std::vector<std::string> vektor) {
	for(int i(0); i<vektor.size(); i++) {
		std::string rijec=vektor[i];
		for(int j(0); j<rijec.length(); j++) {
			if(!((rijec[j]>='A' && rijec[j]<='Z') || (rijec[j]>='a' && rijec[j]<='z'))) {
				throw std::domain_error ("Izuzetak: Nekorektan izbor rijeci");
			}
		}
	}
	return true;
}

int main () {
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string> rijeci;
	std::cout << "Unesite fraze: ";
	for(;;) {
		std::string rijec;
		std::getline(std::cin, rijec);
		rijeci.push_back(rijec);
		if(std::cin.peek()=='\n') break;
	}
	try {
		bool tacnost;
		std::string recenica1=recenica;
		tacnost=Slova(rijeci);
		if(tacnost) {
			recenica1=IzmijeniUPigLatin(recenica1, rijeci);
			std::cout << "Recenica nakon PigLatin transformacije: ";
			std::cout << recenica1 << std::endl;
		}
	} 
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	std::cout << "Recenica nakon obrtanja fraza: ";
	recenica=ObrniFraze(recenica, rijeci);
	std::cout << recenica << std::endl;
	return 0;
} 