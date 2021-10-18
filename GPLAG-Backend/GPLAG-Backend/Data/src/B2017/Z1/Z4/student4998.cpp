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
std::string NapraviPalindrom(std::string recenica,std::vector<std::string>v)
{
	if(recenica.length()==0) return recenica;
	if(v.size()==0) return recenica;
	for(int i=0; i<v.size(); i++) {
		std::string fraza = v.at(i);
		bool vecbio(false);
		//provjeravamo da li se u vektoru stringova nalaze isti elementi kako ne bismo ponovo ubacivali frazu u recenicu
		for(int j=0; j<i; j++) {
			if(v.at(j)==fraza) vecbio=true;
		}
		if(vecbio==false) {
			for(int k=0; k<recenica.length(); k++) {
				if(recenica.at(k)==fraza.at(0)) {
					//	int zapamti(k);//pamtimo pocetak rijeci u recenici
					//provjeravamo je li fraza podstring recenice
					std::string obrnuta_fraza;
					int duzfraze(fraza.size());
					for(int j=duzfraze-1; j>=0; j--) obrnuta_fraza.push_back(fraza.at(j)); //OK RADI
					std::string pom(recenica.substr(k,duzfraze));//OK IZDVOJI
					//k+duzfraze je prvi indeks iza fraze
					//provjeravamo znak iza je li neslovo
					if(pom==fraza) {
						//rijec na pocetku recenica i iza nje ima neki znak
						if(k==0 && k+duzfraze<recenica.length()) {
							auto iza(recenica.at(k+duzfraze));//znak iza
							bool neslovo(true);
							if(iza>='A' && iza<='z') neslovo=false;
							if(neslovo) {

								recenica=recenica.substr(0,k+duzfraze)+obrnuta_fraza+recenica.substr(k+duzfraze,recenica.length()-k-duzfraze);
								k=k+2*duzfraze;//pomjeramo k da bude indeks prvog znaka iza fraze

							}
						}
						//jedna rijec u recenici
						else if(k==0 && k+duzfraze==recenica.length()) {
							recenica+=obrnuta_fraza;//samo dodamo na kraj te rijeci obrnutu rijec
							return recenica;
						}
						// rijec u sredini
						else if(k-1>=0 && k+duzfraze<recenica.length()) {
							bool ispredneslovo(true),izaneslovo(true);
							auto iza(recenica.at(k+duzfraze));//znak iza
							auto ispred(recenica.at(k-1));
							if(iza>='A' && iza<='z') izaneslovo=false;
							if(ispred>='A' && ispred<='z') ispredneslovo=false;
							if(izaneslovo && ispredneslovo) {
								recenica=recenica.substr(0,k+duzfraze)+obrnuta_fraza+recenica.substr(k+duzfraze,recenica.length()-k-duzfraze);
								k=k+2*duzfraze;
							}

						}
						//rijec na kraju
						else if(k-1>=0 && recenica.length()==k+duzfraze) {
							bool ispredneslovo(true);
							auto ispred(recenica.at(k-1));
							if(ispred>='A' && ispred<='z') ispredneslovo=false;
							if(ispredneslovo) {
								recenica=recenica.substr(0,k+duzfraze)+obrnuta_fraza;
								return recenica;
							}
						}


					}

				}


			}
		}
	}
	return recenica;

}
std::string NapraviPoluPalindrom(std::string recenica,std::vector<std::string>v)
{
	if(recenica.length()==0) return recenica;
	if(v.size()==0) return recenica;
	for(int i=0; i<v.size(); i++) {
		//ovdje ako je duzina fraze neparna treba taj znak na kojem se lomi polovina ostaviti na sredini i nadovezat na njeg polovinu fraze
		//zato se dodaje +1 prilikom izdvajanja i kad se k povecava
		std::string fraza = v.at(i);
		bool vecbio(false);
		//provjeravamo da li se u vektoru stringova nalaze isti elementi kako ne bismo ponovo ubacivali frazu u recenicu
		for(int j=0; j<i; j++) {
			if(v.at(j)==fraza) vecbio=true;
		}
		if(vecbio==false) {
			for(int k=0; k<recenica.length(); k++) {
				if(recenica.at(k)==fraza.at(0)) {
					//	int zapamti(k);//pamtimo pocetak rijeci u recenici
					//provjeravamo je li fraza podstring recenice
					std::string obrnuta_fraza;
					int duzfraze(fraza.size());
					/*int polfraze;
					if(duzfraze%2==0) polfraze=duzfraze/2;
					else polfraze=(duzfraze+1)/2;*/
					int polfraze(duzfraze/2);
					for(int j=polfraze-1; j>=0; j--) obrnuta_fraza.push_back(fraza.at(j));//OK RADI
					std::string pom(recenica.substr(k,duzfraze));//OK IZDVOJI
					//k+duzfraze je prvi indeks iza fraze
					//provjeravamo znak iza je li neslovo
					if(pom==fraza) {
						//rijec na pocetku recenica i iza nje ima neki znak
						if(k==0 && k+duzfraze<recenica.length()) {
							auto iza(recenica.at(k+duzfraze));//znak iza
							bool neslovo(true);
							if(iza>='A' && iza<='z') neslovo=false;
							if(neslovo) {
								if(duzfraze%2==0) {
									recenica=recenica.substr(0,k+polfraze)+obrnuta_fraza+recenica.substr(k+duzfraze,recenica.length()-k-polfraze);
									k=k+2*polfraze;//pomjeramo k da bude indeks prvog znaka iza fraze
								} else {
									recenica=recenica.substr(0,k+polfraze+1)+obrnuta_fraza+recenica.substr(k+duzfraze,recenica.length()-k-polfraze);
									k=k+2*polfraze+1;
								}

							}
						}
						//jedna rijec u recenici
						else if(k==0 && k+duzfraze==recenica.length()) {
							recenica=recenica.substr(0,polfraze)+obrnuta_fraza;//samo dodamo na kraj te rijeci obrnutu rijec
							return recenica;
						}
						// rijec u sredini
						else if(k-1>=0 && k+duzfraze<recenica.length()) {
							bool ispredneslovo(true),izaneslovo(true);
							auto iza(recenica.at(k+duzfraze));//znak iza
							auto ispred(recenica.at(k-1));
							if(iza>='A' && iza<='z') izaneslovo=false;
							if(ispred>='A' && ispred<='z') ispredneslovo=false;
							if(izaneslovo && ispredneslovo) {
								if(duzfraze%2==0) {
									recenica=recenica.substr(0,k+polfraze)+obrnuta_fraza+recenica.substr(k+duzfraze,recenica.length()-k-polfraze);
									k=k+2*polfraze;
								} else {
									recenica=recenica.substr(0,k+polfraze+1)+obrnuta_fraza+recenica.substr(k+duzfraze,recenica.length()-k-polfraze);
									k=k+2*polfraze+1;

								}
							}

						}
						//rijec na kraju
						else if(k-1>=0 && recenica.length()==k+duzfraze) {
							bool ispredneslovo(true);
							auto ispred(recenica.at(k-1));
							if(ispred>='A' && ispred<='z') ispredneslovo=false;
							if(ispredneslovo) {
								recenica=recenica.substr(0,k+polfraze+1)+obrnuta_fraza;
								return recenica;
							}
						}


					}

				}


			}
		}
	}
	return recenica;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string>vektor;
	std::string fraza;
	for(;;) {

		std::getline(std::cin,fraza);
		if(fraza.length()!=0)
			vektor.push_back(fraza);

		else break;

	}
	std::string novarecenica(NapraviPalindrom(recenica,vektor));
	std::cout<<"Recenica nakon Palindrom transformacije: "<<novarecenica<<std::endl;
	novarecenica=NapraviPoluPalindrom(recenica,vektor);
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<<novarecenica;
	return 0;
}
