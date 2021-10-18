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


// funkcija za korektnonst alfabeta
bool DaLiJeKorektna (std::string rijec) {
	
	int i=0;
	
	if(rijec[0]=='\n') return true;
	
	while(i<rijec.length()) {
		
		if(!((char(rijec[i])>='a' && (char(rijec[i]))<='z') || (char(rijec[i])>='A' && (char(rijec[i]))<='Z') || rijec[i]==' '))
		throw std::domain_error("Nekorektan izbor rijeci");
		
		i++;
	}
	return true;
}

bool ImaLiRazmakaUFrazi (std::string rijec) {
	
	for(int i=0; i<rijec.length(); i++) {
		if(rijec[i]==' ') throw std::domain_error("Nekorektan izbor rijeci");
	}
	return true;
}


std::string obrni (std::string recenica, std::string rijec) {
	
	std::string rezultat;
	
	std::string obrnuta;                    // novi string koji je obrnuta rijec
	obrnuta = rijec;
	int t(0);
	for(int i=rijec.size()-1; i>=0; i--) {
		obrnuta[t] = rijec[i];
		t++;
	}
	
	for(int i=0; i<recenica.length(); i++) {
		
		int j = i;
		int k = 0;
	
		while (k!=rijec.length() && j!=recenica.length() && rijec[k]==recenica[j]) {
			j++;
			k++;
		}
		
		if(k==rijec.length()) {
			rezultat += obrnuta;
			i = j-1;
		}
		else {
			rezultat.push_back(recenica[i]);
		}
	}
	
	return rezultat;
}

std::string ObrniFraze (std::string recenica, std::vector<std::string> v) {
	
	std::string pom;
	std::string rezultat;
	for(int i=0; i<v.size(); i++) {
		pom = v[i];
		recenica = obrni(recenica,pom);
	}
	
	rezultat = recenica;
	return rezultat;
}


std::string izmjena (std::string recenica, std::string rijec) {
	
	std::string rezultat;
	
	
	std::string zamjenjena = rijec;                     // novi string koji je rijec koju trebamo izmijeniti
	char temp;
	temp = rijec[0];
	for(int i=0; i<zamjenjena.length(); i++) {
		
		if(i!=zamjenjena.length()-1) {
			zamjenjena[i] = zamjenjena[i+1];
		}
		if(i==zamjenjena.length()-1) {
			zamjenjena[i] = temp;
		}
	}
	zamjenjena += "ay";
	
	for(int i=0; i<recenica.length(); i++) {
		
		int j = i;
		int k = 0;
		
		while(k!=rijec.length() && j!=recenica.length() && rijec[k]==recenica[j]) {
			j++;
			k++;
		}
		
		if(k==rijec.length()) {
			rezultat += zamjenjena;
			i = j-1;
		}
		else {
			rezultat.push_back(recenica[i]);
		}
	}
	
	return rezultat;
}

std::vector<std::string> IzdvojiRijeci (std::string recenica) {
	
	std::vector<std::string> v;
	for(int i=0; i<recenica.length(); i++) {
		
		while(i<recenica.length() && recenica[i]==' ') {   // preskoci prazne prostore
			i++;
		}
		
		if(i<recenica.length()) {  // pokupi karaktere
			std::string pom;
			while(i<recenica.length() && recenica[i]!=' ') {
				pom.push_back(recenica[i]);
			}
			
			v.push_back(pom);
		}
	}
	
	return v;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> v) {
	
	std::string pom;
	std::string rezultat;
	std::vector<std::string> rijeci_u_recenici;
	if(v.size()==0) {
		rijeci_u_recenici = IzdvojiRijeci(recenica);
		v = rijeci_u_recenici;
	}
	for(int i=0; i<v.size(); i++) {
		pom = v[i];
		recenica = izmjena(recenica,pom);
	}
	rezultat = recenica;
	return recenica;
}

int main ()
{
	std::vector<std::string> vektor;
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	std::string fraza;
	std::vector<std::string> lista_fraza;
	for(;;) {
		getline(std::cin, fraza);
	
		if(fraza.length()==0) {
			if(fraza[0]!='\n') break;
		}
		
		else if(fraza[fraza.length()-1]!='\n') {
			lista_fraza.push_back(fraza);
		}
	}
	try {
		
		int broj(0);
		for(int i=0; i<lista_fraza.size(); i++) {
		
			if(DaLiJeKorektna(lista_fraza[i]))  broj++;
		}
	
		if(broj==lista_fraza.size()) {
			try {
		
				int brojac(0);
				
				for(int i=0; i<lista_fraza.size(); i++) {
			
					if(ImaLiRazmakaUFrazi(lista_fraza[i]))
						brojac++;
				}
				if(brojac==lista_fraza.size()) {
					std::cout << "Recenica nakon PigLatin transformacije: ";
					std::string piglatin_recenica;
					piglatin_recenica = IzmijeniUPigLatin(recenica,lista_fraza);
					std::cout << piglatin_recenica << std::endl;
				}
			}
		
			catch(std::domain_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
		
			std::string recenica2(recenica);
			std::cout << "Recenica nakon obrtanja fraza: ";
			std::string obrnutefraze_recenica;
			obrnutefraze_recenica = ObrniFraze(recenica2,lista_fraza);
			std::cout << obrnutefraze_recenica;
		}
	}
	catch(std::domain_error izuzetak2) {
		std::cout << izuzetak2.what() << std::endl;
	}
	return 0;
}