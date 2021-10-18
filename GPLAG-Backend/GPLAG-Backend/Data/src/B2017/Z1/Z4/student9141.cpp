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

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> spisak_rijeci){
	std::vector<std::string> spisak_palindroma(spisak_rijeci.size());
	for(int i=0; i<spisak_rijeci.size(); i++){
		for(int j=spisak_rijeci.at(i).size()-1; j>=0; j--){
			spisak_palindroma.at(i).push_back(spisak_rijeci.at(i).at(j));
		}
	}
	
	//prvo napravim vektor ovih rijeci vec uredjenih kopalindrome, ovo iznad gore ...
	
	
	for(int i=0; i<spisak_rijeci.size(); i++){
		for(int j=0; j<recenica.size(); j++){
			if(recenica.at(j)==spisak_rijeci.at(i).at(0)){
				int indeks1(j), br(0), indeks2, pomoc(0);
				if(j==0)pomoc=1;
				while(recenica.at(j)==spisak_rijeci.at(i).at(br)){
					j++;
					br++;
					if(j>=recenica.size() || br>=spisak_rijeci.at(i).size())break;
				} 
				if(br==spisak_rijeci.at(i).size() && ( (j!=recenica.size() && ((recenica.at(j)<'A' || recenica.at(j)>'Z') && ((recenica.at(j)<'a' || recenica.at(j)>'z')) ) || j==recenica.size())  
				&& ((indeks1-1+pomoc!=0 && ((recenica.at(indeks1-1+pomoc)<'A' || recenica.at(indeks1-1+pomoc)>'Z') && (recenica.at(indeks1-1+pomoc)<'a' || recenica.at(indeks1-1+pomoc)>'z')) ) || indeks1-1+pomoc==0))){
					indeks2=indeks1+br-1;
					std::string pomocni(recenica.substr(0, indeks1+1+br-1) + spisak_palindroma.at(i) + recenica.substr(indeks1+1+br+-1, recenica.size()-indeks1-br) );
					recenica=pomocni;
					j=j+spisak_rijeci.at(i).size()-1;
				}
				
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> spisak_rijeci){
	std::vector<std::string> spisak_palindroma(spisak_rijeci.size());
	for(int i=0; i<spisak_rijeci.size(); i++){
		int pomocna_ako_je_neparan_broj_slova(1);
		if(spisak_rijeci.at(i).size()%2!=0)pomocna_ako_je_neparan_broj_slova=0;
		for(int j=0; j<spisak_rijeci.at(i).size()/2; j++){ // mozda razvdojit za neparan  para broj slova;, moram ovo malo rjesit
			spisak_palindroma.at(i).push_back(spisak_rijeci.at(i).at(j));
		}
		for(int j=spisak_rijeci.at(i).size()/2-pomocna_ako_je_neparan_broj_slova; j>=0; j--){
			spisak_palindroma.at(i).push_back(spisak_rijeci.at(i).at(j));
		}
	}
	
	for(int i=0; i<spisak_rijeci.size(); i++){
		for(int j=0; j<recenica.size(); j++){
			if(recenica.at(j)==spisak_rijeci.at(i).at(0)){
				int indeks1(j), br(0), indeks2, pomoc(0);
				if(j==0)pomoc=1;
				while (recenica.at(j)==spisak_rijeci.at(i).at(br)){
					j++;
					br++;
					if(j>=recenica.size() || br>=spisak_rijeci.at(i).size())break;
				}
				if(br==spisak_rijeci.at(i).size() && ( (j!=recenica.size() && ((recenica.at(j)<'A' || recenica.at(j)>'Z') && ((recenica.at(j)<'a' || recenica.at(j)>'z')) ) || j==recenica.size())
				&& ((indeks1-1+pomoc!=0 && ((recenica.at(indeks1-1+pomoc)<'A' || recenica.at(indeks1-1+pomoc)>'Z') && (recenica.at(indeks1-1+pomoc)<'a' || recenica.at(indeks1-1+pomoc)>'z')) ) || indeks1-1+pomoc==0))){
					indeks2=indeks1+br-1;
					std::string pomocni(recenica.substr(0, indeks1) + spisak_palindroma.at(i) + recenica.substr(indeks1+1+br-1, recenica.size()-indeks1-br) );
					recenica=pomocni;
					j=j-1;
				}
			}
		}
	}
	
	
	
	//return spisak_palindroma.at(0);
	return recenica;
}

int main ()
{
	std::string recenica;
	std::vector<std::string> fraze;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	while(1){
		std::string unos;
		std::getline(std::cin , unos);
		//std::cout << "\nunos...." << unos << "...\n";
		if(unos.size()==0)break;
		fraze.push_back(unos);
	}
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze);
	std::cout << "\nRecenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze);
	
	return 0;
}