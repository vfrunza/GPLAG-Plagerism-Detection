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

typedef std::vector<std::string> Vektor_string;

std::string Obrni_rijec(std::string rijec){
	std::string naopaka;
	for (int i = rijec.length()-1; i>=0; i--) {
		naopaka=naopaka+rijec.at(i);
	}
	return naopaka;
}

std::string NapraviPalindrom(std::string recenica,Vektor_string spisak){
	for(int i = 0; i<spisak.size(); i++){
		int duzina_fraze = spisak.at(i).length();
		for(int j= 0; j<= (recenica.length()-duzina_fraze);j++){
			std::string testni_substring=recenica.substr(j, duzina_fraze);
			if(spisak.at(i) == testni_substring){
				int pozicija_Zadnjeg=j+duzina_fraze;
				int preostala_duzina = recenica.length() - pozicija_Zadnjeg + 1;
				std::string za_upis=Obrni_rijec(spisak.at(i));
				std::string drugi_dio=recenica.substr(pozicija_Zadnjeg,preostala_duzina);
				std::string prvi_dio=recenica.substr(0,(pozicija_Zadnjeg));
				std::string rezultat = prvi_dio + za_upis + drugi_dio;
				//std::cout<<rezultat<<std::endl;
				recenica=rezultat;
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom(std::string recenica, Vektor_string spisak){
	for(int i = 0; i<spisak.size();i++){
		int duzina_fraze = spisak.at(i).length();
		for(int j = 0; j <= (recenica.length()-duzina_fraze);j++){
			std::string testni_substring = recenica.substr(j, duzina_fraze);
			if(spisak.at(i)==testni_substring){
				int pozicija_Zadnjeg = j+duzina_fraze;
				int preostala_duzina = recenica.length()-pozicija_Zadnjeg+1;
				std::string za_upis = Obrni_rijec(spisak.at(i));
				std::string prvi_dio = recenica.substr(0,(pozicija_Zadnjeg));
				std::string drugi_dio = recenica.substr(pozicija_Zadnjeg, preostala_duzina);
				
				if(za_upis.length()%2==0){
					std::string privremeni = za_upis.substr((za_upis.length()/2), (za_upis.length()/2));
					za_upis = privremeni;
				}
				else{
					std::string privremeni = za_upis.substr(((za_upis.length()/2)+1),(za_upis.length()/2));
					za_upis=privremeni;
				}
				
				std::string privremeni_veliki = prvi_dio.substr(0,(prvi_dio.length() - za_upis.length()));
				prvi_dio=privremeni_veliki;
				
				std::string rezultat = prvi_dio + za_upis + drugi_dio;
				recenica = rezultat;
			}
		}
	}
	return recenica;
}

int main ()
{
	Vektor_string fraze;
	std::string recenica;
	std::string pomocni=" ";
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout << "Unesite fraze: ";
	while (pomocni.length()>0) {
	std::getline(std::cin,pomocni);
	fraze.push_back(pomocni);
	}
	std::cout << "Recenica nakon Palindrom transformacije: ";
	std::string rez=NapraviPalindrom(recenica, fraze);
	std::cout<<rez<<std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: ";
	std::string rez_polu = NapraviPoluPalindrom(recenica, fraze);
	std::cout<<rez_polu<<std::endl;
	return 0;
}