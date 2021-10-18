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

	
	std::string vratiIzvrnuto (std::string recenica){
		std::string vrati="";
		
		for (int i=recenica.size()-1; i>=0; i--){
			vrati+=recenica[i];
		}
		return vrati;
	}
	
	
	std::string poluPalindrom (std::string rijec){
		std::string vrati="";
		if (rijec.size() % 2 == 0){
			int velicinaPolaRijeci=rijec.length()/2;
			
			rijec=rijec.substr(0,velicinaPolaRijeci);
			vrati+=rijec + vratiIzvrnuto(rijec);
		}
		
		else{
			vrati+=rijec.substr(0,(rijec.length()/2)+1)+ vratiIzvrnuto(rijec.substr(0,rijec.length()/2));
		}
		return vrati;
	}
	
	
	
	std::string Palindrom (std::string rijec){
		std::string vrati="";
		vrati+=rijec+vratiIzvrnuto(rijec);
		
		return vrati;
	}
	
	
	bool jelSlovo (char znak){
		if (znak>='A' && znak<='Z') return true;
		if (znak>='a' && znak<='z') return true;
		
		return false;
	}
	
	
	bool jelCijelaFraza (std::string recenica, std::string fraza, int pocetak, int duzina){
		if (pocetak==0) return true;
		
		else if (pocetak+duzina == fraza.size()) return true;
		else if (pocetak>0 && (pocetak+duzina)<recenica.size()){
			if (jelSlovo(recenica.at(pocetak+duzina))) return false;
			
			else if (jelSlovo(recenica.at(pocetak-1))) return false;
			
			else return true;
		}
		else return true;
	}
	
	
	std::string NapraviPalindrom(std::string recenica, std::vector<std::string> listaRijeci){
		std::string vrati="";
		
		for (int j=0; j<recenica.size(); j++){
			bool jelBilaFraza=false;
			
		for (int i=0; i<listaRijeci.size(); i++){
			int velicinaFraze = listaRijeci.at(i).size();
			
			std::string fraza = listaRijeci.at(i);
			
			if (velicinaFraze+j-1>=recenica.size()) continue;
			
			if (recenica.substr(j,velicinaFraze) == fraza && jelCijelaFraza(recenica, fraza, j, velicinaFraze)){
				jelBilaFraza=true;
				vrati+=Palindrom(fraza);
				j+=velicinaFraze-1;
			}
		}
		if (!jelBilaFraza) vrati+=recenica.at(j);
		}
		return vrati;
	}
	
	
	std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> listaRijeci){
		std::string vrati="";
		
		for (int j=0; j<recenica.size(); j++){
			bool jelBilaFraza=false;
			
			for (int i=0; i<listaRijeci.size(); i++){
				int velicinaFraze = listaRijeci.at(i).size();
				std::string fraza = listaRijeci.at(i);
				
				
				if (velicinaFraze+j-1>=recenica.size()) continue;
				
				if (recenica.substr(j,velicinaFraze) == fraza && jelCijelaFraza(recenica, fraza, j, velicinaFraze)){
					jelBilaFraza=true;
					vrati+=poluPalindrom(fraza);
					j+=velicinaFraze-1;
				}
			}
			if (!jelBilaFraza) vrati+=recenica.at(j);
		}
		return vrati;
	}
	
	
	
	
int main ()
{
	std::string recenica, pom;
	std::vector<std::string> listaRijeci;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	
	int brojPraznihZaredom=0;
	
	
	
	while (1){
		std::getline(std::cin, pom);
		if (pom==""){
			brojPraznihZaredom++;
		}
		else {
			brojPraznihZaredom=0;
			listaRijeci.push_back(pom);
		}
		if (brojPraznihZaredom==2) break;
	}
	
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica, listaRijeci)<<std::endl;
	
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica, listaRijeci);
	return 0;
}