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

std::string NapraviPalindrom (std::string Recenica, std::vector<std::string>Fraze)
{
	std::string pomocna("");
	std::string rijec;
	bool zamijeni;
	int m;
	
	for(int i=0; i<Recenica.size(); i++) {
		for (int j = 0; j < Fraze.size(); j++) {
			if (Recenica.at(i) == Fraze.at(j).at(0)) {
				zamijeni = true;
				m = i;
				for (int k = 0; k < Fraze.at(j).size() && m<Recenica.size(); k++, m++) {
					if (Recenica.at(m) != Fraze.at(j).at(k) ){
						zamijeni = false;
						break;
					}
					if (m+1 == Recenica.size() && k+1 < Fraze.at(j).size()) {
						zamijeni = false;
						break;
					}
				}
				if (zamijeni) {
					if (m<Recenica.size() && Recenica.at(m) != ' ') {
						if(!(Recenica.at(m)=='.' || Recenica.at(m)==',' || Recenica.at(m)==';' || Recenica.at(m)==':' || Recenica.at(m)=='"')) break;
						
					}
					
					for (int k = 0; k < m; k++) { 
						pomocna += Recenica.at(k);
					}
					for (int k = Fraze.at(j).size()-1; k >= 0 ; k--) { 
						pomocna += Fraze.at(j).at(k);
					}
					for (int k = m; k < Recenica.size(); k++) {
						pomocna += Recenica.at(k);
					}
					Recenica = pomocna;
					pomocna = "";
					i += Fraze.at(j).size();

				}
			}
		}
		while (i<Recenica.size() && Recenica.at(i) != ' ') {
			i++;
		}

	}
	return Recenica;
}

std::string NapraviPoluPalindrom(std::string Recenica,std::vector<std::string>Fraze)
{
	std::string pomocna("");
	std::string rijec;
	bool zamijeni;
	int m,l;
	
	for(int i=0; i<Recenica.size(); i++) {
		for(int j=0; j<Fraze.size(); j++) {
			if(Recenica.at(i)==Fraze.at(j).at(0)) {
				zamijeni = true;
				m=i;
				for(int k=0; k < Fraze.at(j).size() && m<Recenica.size(); k++, m++) {
					if(Recenica.at(m)!=Fraze.at(j).at(k)) {
						zamijeni= false;
						break;
					}
					if (m+1 == Recenica.size() && k+1 < Fraze.at(j).size()) {
						zamijeni = false;
						break;
					}
					
				}
				if(zamijeni) {
					if (m<Recenica.size() && Recenica.at(m) != ' ') {
						if(!(Recenica.at(m)=='.' || Recenica.at(m)==',' || Recenica.at(m)==';' || Recenica.at(m)==':' || Recenica.at(m)=='"')) 
							break;
					}
					
					if(Fraze.at(j).size()%2==0) {
						l=(m-(Fraze.at(j).size())/2);
					} else {
						l=(m-(Fraze.at(j).size()/2))-1;
					}
					for(int k=0; k<l ; k++) {
						pomocna+=Recenica.at(k);
					}
					l=(Fraze.at(j).size())/2;
					if(Fraze.at(j).size()%2!=0) {
						l+=1;
					}
					for(int k=l-1; k>=0; k--) {
						pomocna+=Fraze.at(j).at(k);
					}
					if(Fraze.at(j).size()%2==0) {
						pomocna+=' ';
					}
					if(Fraze.at(j).size()%2!=0) {
						m=m-1;
					}
					for(int k=m+1; k<Recenica.size(); k++) {
						pomocna+=Recenica.at(k);
					}
					Recenica=pomocna;
					pomocna="";
					i+=Fraze.at(j).size();
					i--;
				}
			}
		}
		while(i<Recenica.size() && Recenica.at(i)!= ' ') {
			i++;
		}
	}
	return Recenica;
}

int main ()
{
	std::string recenica, fraza;
	std::vector<std::string> fraze;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	do {
		std::cin.clear();
		std::getline(std::cin, fraza);
		if(fraza=="") 
			break;
		fraze.push_back(fraza);
	} while (true);
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica, fraze) << std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<NapraviPoluPalindrom(recenica, fraze) << std::endl;



	return 0;
}