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
#include <cstring>

// paziti na razmake 
// paziti na opsege 
// mala velika slova
// prazna recenica
// prazna lista
// tacke i znakovi za razmake -> RIJESENO
// duple rijeci

std::string ObrniString (std::string &rijec, std::string &pom){
	pom = "";
	for(int i=rijec.size()-1; i>=0; --i){
		pom += rijec[i];
	}
	return pom;
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> lista_rijeci){
	// trazimo rijec u stringu
	std::string tmp;
	for(int i=0; i<lista_rijeci.size(); i++){
		ObrniString(lista_rijeci.at(i), tmp);
		for(int j=0; j<recenica.size(); j++){
			if(recenica.substr(j, lista_rijeci.at(i).size()) == lista_rijeci.at(i) && (!(recenica.at(j+lista_rijeci.at(i).size())>='a' && recenica.at(j+lista_rijeci[i].size())<='z') && !(recenica.at(j+lista_rijeci.at(i).size())>='A' && recenica.at(j+lista_rijeci[i].size())<='Z'))){
				recenica = recenica.substr(0,j+lista_rijeci.at(i).size()) + tmp + recenica.substr(j+lista_rijeci[i].size(), recenica.size()-j-lista_rijeci[i].size());
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> lista_rijeci){
	std::string tmp;
	for(int i=0; i<lista_rijeci.size(); i++){
		ObrniString(lista_rijeci.at(i), tmp);
		for(int j=0; j<recenica.size(); j++){
			if(recenica.substr(j, lista_rijeci[i].size()) == lista_rijeci.at(i) && (!(recenica[j+lista_rijeci[i].size()]>='a' && recenica[j+lista_rijeci[i].size()]<='z') && !(recenica[j+lista_rijeci[i].size()]>='A' && recenica[j+lista_rijeci[i].size()]<='Z'))){
				// ako je rijec parna
				if(lista_rijeci[i].size()%2==0){
					recenica = recenica.substr(0,j+lista_rijeci.at(i).size()/2) + tmp.substr(lista_rijeci.at(i).size()/2, lista_rijeci.at(i).size()/2) + recenica.substr(j+lista_rijeci[i].size(), recenica.size()-j-(lista_rijeci[i].size()));
					j++;
				// ako je rijec neparna
				} else {
					recenica = recenica.substr(0,j+(lista_rijeci.at(i).size()/2)) + tmp.substr((lista_rijeci.at(i).size()/2), (lista_rijeci[i].size()/2) + 1) + recenica.substr(j+lista_rijeci[i].size(), recenica.size()-j-(lista_rijeci[i].size()));	
					j++;
				}
				
			}
		}
	}
	return recenica;
}

int main (){
	/* std::vector<std::string> lista_rijeci = {"zadaca", "Tehnike programiranja", "drugih predmeta", "meso od sira"};
	std::string recenica = "Izasla je prva zadaca iz predmeta Tehnike programiranja, a ovih dana ocekujemo i jos zadaca iz drugih predmeta";
	std::string palindrom = NapraviPalindrom(recenica, lista_rijeci);
	std::string polupalindrom = NapraviPoluPalindrom(recenica, lista_rijeci);
	// std::string polupalindrom = NapraviPoluPalindrom(recenica, lista_rijeci);
	for(int i=0; i<palindrom.size(); i++){
		std::cout << palindrom[i];
	}
	std::cout << std::endl;
	for(int i=0; i<polupalindrom.size(); i++){
		std::cout << polupalindrom.at(i);
	} */
	// UNOS RECENICE
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	// UNOS FRAZA
	std::cout << "Unesite fraze: ";
	std::vector<std::string> lista_rijeci;
	while(1){
		std::string tmp;
		std::getline(std::cin, tmp);
		if(tmp.size() == 0){
			break;
		}
		lista_rijeci.push_back(tmp);
	}
	// FCIJE
	std::string palindrom = NapraviPalindrom(recenica, lista_rijeci);
	std::string polupalindrom = NapraviPoluPalindrom(recenica, lista_rijeci);
	// ISPIS
	std::cout << "Recenica nakon Palindrom transformacije: ";
	for(int i=0; i<palindrom.size(); i++){
		std::cout << palindrom.at(i);
	}
	std::cout << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";
	for(int i=0; i<polupalindrom.size(); i++){
		std::cout << polupalindrom.at(i);
	}
	return 0;
}