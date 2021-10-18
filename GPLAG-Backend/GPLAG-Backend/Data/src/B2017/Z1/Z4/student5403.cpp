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
#include <stdexcept>

bool daLiSadrziPolup (std::string recenica, std::string fraza, bool cijelaRijec, int &pocetak){
	bool flag=false;
	if(fraza == " ") return false;
	int j=0;
	pocetak=0;
	int s=fraza.length();
	for(int i(0);i<recenica.length();i++){
		if(j<fraza.length()){
			if(recenica.at(i)==fraza.at(j) || flag){
				if (cijelaRijec && j==0 && i>0 && recenica.at(i-1) != ' '){
					j=0;
					pocetak=i+1;
				}
				else{
					flag=recenica.at(i)==fraza.at(j);
					if ((!(recenica[i+1] >='A' && recenica[i+1] <='Z') || (recenica[i+1] <='z' && recenica[i+1] >='a'))  && (s==j+1 && !flag)){ //Problem .at(i+1) ??
						j=0;
						pocetak=i+1;
					}
					else {
						j++;
					}
				}
			}
			else{
				j=0;
				pocetak=i+1;
			}
		}
	}
	if(j<fraza.length()) return false;
	return flag;
}
bool daLiSadrziPal (std::string recenica, std::string fraza, bool cijelaRijec, int &pocetak){
	bool flag=false;
	if(fraza == " ") return false;
	int j=0;
	pocetak=0;
	int s=fraza.length();
	for(int i(0);i<recenica.length();i++){
		if(j<fraza.length()){
			if(recenica.at(i)==fraza.at(j) || flag){
				if (cijelaRijec && j==0 && i>0 && recenica.at(i-1) != ' '){
					j=0;
					pocetak=i+1;
				}
				else{
					flag=recenica.at(i)==fraza.at(j);
					if (((recenica[i+1] >='A' && recenica[i+1] <='Z') || (recenica[i+1] <='z' && recenica[i+1] >='a'))  && (s==j+1 || !flag)){ //Problem .at(i+1) ??
						j=0;
						pocetak=i+1;
					}
					else {
						j++;
					}
				}
			}
			else{
				j=0;
				pocetak=i+1;
			}
		}
	}
	if(j<fraza.length()) return false;
	return flag;
}
std::string okrenislova (std::string fraza){
	if(fraza.length()==1) return fraza;
	std::string rezultat;
	for(int i=fraza.length()-1;i>=0;i--){
		rezultat+=fraza.at(i);
	}
	return rezultat;
}
std::vector<std::string> OcistiRijeci(std::vector<std::string> rijeci, bool tretirajObrnuteRijeci){
	std::vector<std::string> cisteRijeci;
	for (auto rijec:rijeci){
		bool rijecPostoji=false;
		for(auto cistaRijec:cisteRijeci){
			if (cistaRijec==rijec || (tretirajObrnuteRijeci && cistaRijec ==okrenislova(rijec))){
				rijecPostoji=true;
				break;
			}
		}
	if(rijecPostoji==false) cisteRijeci.push_back (rijec);
	}
	return cisteRijeci;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraze){
	fraze=OcistiRijeci(fraze,true);
	int pocetak =-1,p=0;
	for(auto fraza:fraze){
		while (daLiSadrziPolup(recenica,fraza,false,pocetak)){
			std::string pola;
			std::string pola1;
			p=0;
			for(char k:fraza){
				if (p==int(fraza.length()/2) && fraza.length()%2==0) break;
				pola+=k;
				if (p==int(fraza.length()/2) && fraza.length()%2!=0) break;
				pola1+=k;
				p++;
			}	
		recenica=recenica.substr(0,pocetak)+pola+okrenislova(pola1)+recenica.substr(pocetak+fraza.length(),recenica.length());
		if (recenica==fraza) break;
		}
	}
	return recenica;
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze){
	fraze=OcistiRijeci(fraze,true);
	int pocetak=-1;
	for(auto fraza:fraze){
		while (daLiSadrziPal(recenica,fraza,false,pocetak)){
			recenica=recenica.substr(0,pocetak)+fraza+okrenislova(fraza)+recenica.substr(pocetak+fraza.length(),recenica.length());
			if (recenica==fraza+okrenislova(fraza)) break;
		}
	}
	return recenica;
}


int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	getline (std::cin,recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string rijec;
	getline (std::cin,rijec);
	while(rijec != ""){
		fraze.push_back (rijec);
		getline (std::cin,rijec);
	}
	std::string rezultat = NapraviPalindrom(recenica,fraze);
	std::cout << "Recenica nakon Palindrom transformacije: " << rezultat << std::endl;

	std::string rezultat1 = NapraviPoluPalindrom(recenica,fraze);
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << rezultat1;

return 0;
}