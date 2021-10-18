/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::vector<std::string> VektorStringova;

bool DaLiJeSlovo(char slovo) {
	if ((slovo>='a' && slovo <='z') || (slovo>='A' && slovo<='Z')) return true;
	return false;
}

std::string ObrniFraze(std::string izvorna_recenica, VektorStringova spisak_fraza) {
	std::string pomocni_string1;
	for (int i=0; i<spisak_fraza.size(); i++) {
		pomocni_string1=spisak_fraza[i];
		if (pomocni_string1.size()<=izvorna_recenica.size()) {
			std::string pomocni_string2;
			for (int j=0; j<=izvorna_recenica.size()-pomocni_string1.size(); j++) {
				pomocni_string2=izvorna_recenica.substr(j,spisak_fraza[i].size());
				if (pomocni_string1==pomocni_string2) {
					int duzina=spisak_fraza[i].size();
					for (int k=0; k<duzina/2; k++) {
						char pomocno_slovo(izvorna_recenica[j+k]);
						izvorna_recenica[j+k]=izvorna_recenica[j+duzina-1-k];
						izvorna_recenica[j+duzina-1-k]=pomocno_slovo;
					}
				}
			}
		}
	}
	return izvorna_recenica;
}

std::string IzmijeniUPigLatin(std::string izvorna_recenica, VektorStringova spisak_fraza) {
	for (int i=0; i<spisak_fraza.size(); i++)
		for (int j=0; j<spisak_fraza[i].size(); j++)
			if (!DaLiJeSlovo(spisak_fraza[i][j])) throw std::domain_error("Nekorektan izbor rijeci");
	if (spisak_fraza.size()==0) {
		for (int i=0; i<izvorna_recenica.size(); i++) {
			char pomocno_slovo;
			int brojac{};
			if (DaLiJeSlovo(izvorna_recenica[i])) {
				pomocno_slovo=izvorna_recenica[i];
				brojac++;
				for (int j=i+1; j<izvorna_recenica.size(); j++)
					if (DaLiJeSlovo(izvorna_recenica[j])) brojac++;
					else break;
				for (int k=0; k<brojac-1; k++)
					izvorna_recenica[i+k]=izvorna_recenica[i+k+1];
				izvorna_recenica[i+brojac-1]=pomocno_slovo;
				i=i+brojac;
				izvorna_recenica.insert(izvorna_recenica.begin()+i,'a');
				izvorna_recenica.insert(izvorna_recenica.begin()+i+1,'y');
				i++;
			}
		}
	}
	else {
		for (int i=0; i<izvorna_recenica.size(); i++) {
			std::string pomocni_string;
			int brojac{}, j{};
			char pomocno_slovo;
			if (DaLiJeSlovo(izvorna_recenica[i])) {
				pomocno_slovo=izvorna_recenica[i];
				pomocni_string.push_back(izvorna_recenica[i]);
				brojac++;
				for (j=i+1; j<izvorna_recenica.size(); j++) {
					if (DaLiJeSlovo(izvorna_recenica[j])) {
						pomocni_string.push_back(izvorna_recenica[j]);
						brojac++;
					}
					else break;
				}
				bool pronadjen(false);
				for (int k=0; k<spisak_fraza.size(); k++)
					if (pomocni_string==spisak_fraza[k] && 
					(i==0 || (!DaLiJeSlovo(izvorna_recenica[i-1]))) && 
					((!DaLiJeSlovo(izvorna_recenica[j])) || j+1==izvorna_recenica.size())) {
						pronadjen=true;
						break;
					}
				if (pronadjen) {
					for (int l=0; l<brojac-1; l++)
						izvorna_recenica[i+l]=izvorna_recenica[i+l+1];
					izvorna_recenica[i+brojac-1]=pomocno_slovo;
					i=i+brojac;
					izvorna_recenica.insert(izvorna_recenica.begin()+i,'a');
					izvorna_recenica.insert(izvorna_recenica.begin()+i+1,'y');
					i++;
				}
			}
		}
	}
	return izvorna_recenica;
}

int main () {
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout << "Unesite fraze: ";
	VektorStringova spisak_fraza;
	std::string fraza;
	while(1) {
		std::getline(std::cin, fraza);
		if (fraza.size()!=0) spisak_fraza.push_back(fraza);
		else break;
	}
	std::string zapamti=recenica;
	try {
		recenica=IzmijeniUPigLatin(recenica,spisak_fraza);
		std::cout << "Recenica nakon PigLatin transformacije: " << recenica;
	}
	catch(std::domain_error izuzetak) {
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	recenica=ObrniFraze(zapamti,spisak_fraza);
	std::cout << std::endl << "Recenica nakon obrtanja fraza: " << recenica;
	return 0;
}