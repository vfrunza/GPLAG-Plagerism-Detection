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

std::string obrnislova(std::string s1){
	std::string s2;
	for(int i=s1.length()-1; i>=0; i++) s2.push_back(s1[i]);
	return s2;
}

std::string Sastavi(std::string s1, std::string s2){
	std::string s3;
	for(int i=0; i<s1.length(); i++) s3.push_back(s1[i]);
	for(int i=0; i<s2.length(); i++) s3.push_back(s2[i]);
	return s3;
	
}
std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraza){
	std::string nova_rijec; std::string help;
	std::string izabrana_fraza; int stara_duzina;
	
	for(int i=0; i<fraza.size(); i++){
		izabrana_fraza=fraza.at(i);
		for(int j=0; j<=recenica.length()-izabrana_fraza.length(); j++){
			int tmp1(j);
			help=recenica.substr(tmp1,izabrana_fraza.length());
			if(izabrana_fraza==help && recenica.at(tmp1+izabrana_fraza.length())==' ' && recenica.length()>tmp1+izabrana_fraza.length()) {
				stara_duzina = recenica.length();
				recenica.resize(stara_duzina+fraza.at(i).length());
				int tmp2=stara_duzina-1;
				int kraj(recenica.length()-1);
				while (tmp2 >= tmp1){
					recenica.at(kraj) = recenica.at(tmp2);
					if (tmp2 > tmp1) {kraj--; tmp2--;}
					else { kraj--; break; }
				}
				int brojac=izabrana_fraza.length()-1;
				int tmp1=j+izabrana_fraza.length();
				for (int k=0; k<izabrana_fraza.length(); k++) {
					recenica.at(tmp1)=izabrana_fraza.at(brojac);
					tmp1++; brojac--;
				}
				j += izabrana_fraza.length()*2-1;
			}
		}
	}
	return recenica;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraza){
	std::string pomoc, izabrana_fraza, help;

	for(int i=0; i<fraza.size(); i++){
		izabrana_fraza = fraza.at(i);
		for(int j=0; j<=recenica.length()-izabrana_fraza.length(); j++){
			int pocetak(j);
			help=recenica.substr(pocetak,izabrana_fraza.length());
			if(izabrana_fraza==help && recenica.at(pocetak+izabrana_fraza.length())==' ' && recenica.length()>pocetak+izabrana_fraza.length()){
				int kraj=pocetak+izabrana_fraza.length(); //
				int duzina = izabrana_fraza.length()/2;
				pomoc.resize(izabrana_fraza.length());
				for(int k=0; k<duzina; k++) pomoc.at(k) = izabrana_fraza.at(k);
				int brojac=duzina-1;
				if(izabrana_fraza.length()%2 == 0){
					for(int k=duzina; k<izabrana_fraza.length(); k++){
						pomoc.at(k)=izabrana_fraza.at(brojac);
						brojac--;
					}
				}
				else {
					pomoc.at(duzina)=izabrana_fraza.at(duzina);
					for(int k=duzina+1; k<izabrana_fraza.length(); k++){
						pomoc.at(k)=izabrana_fraza.at(brojac); brojac--;
					}
				}
				int brojac1=0;
				for (int k=pocetak; k<kraj; k++) {
					recenica[k]=pomoc[brojac1]; brojac1++;
				}
			}
		}
	}
return recenica;
}


int main ()
{
	std::vector<std::string> fraza;
	std::string recenica;
	std::string rijec;
	std::cout << "Unesite recenicu: ";
	if (std::cin.peek()!='\n') std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	while(1) {
		if(std::cin.peek()=='\n') break;
		else {
		std::getline(std::cin,rijec);
		fraza.push_back(rijec);
		}
	}
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraza) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraza);
	return 0;
}