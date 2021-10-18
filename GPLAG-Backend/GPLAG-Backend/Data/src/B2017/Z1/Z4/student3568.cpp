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

typedef std::vector<std::string> VektorStringova;

//Vraća string koji je jednak stringu koji je proslijedjen kao parametar okrenutom naopacke
std::string OkreniString (std::string s)
{
	int duzina(s.length());
	std::string tmp(s);

	for(int i=0; i<duzina/2; i++) {
		char tmp_c(tmp.at(i));
		tmp.at(i)=tmp.at(duzina-i-1);
		tmp.at(duzina-i-1)=tmp_c;
	}

	return tmp;
}

//Vraća string koji je polovina stringa proslijedjenog kao parametar
std::string PrepoloviString (std::string s)
{
	int duzina(s.length());
	if(duzina%2==1) duzina++;
	std::string tmp(duzina/2, ' ');

	for(unsigned int i=0; i<duzina/2; i++) {
		tmp.at(i)=s.at(i);
	}

	return tmp;
}

//pronalazi string (prvi parametar) u stringu (drugi parametar) od pozicije pa nadalje (treci parametar)
//vraca indeks prvog slova pronadjenog podstringa, -1 ako nije pronadjen
int NadjiPodstring (std::string s1, std::string s2, int pocetna_pozicija)
{
	//s1 se trazi u stringu s2

	int duzina1(s1.length()), duzina2(s2.length());

	for(int i=pocetna_pozicija; i<duzina2; i++) {
		if(s2.at(i)==s1.at(0)) {
			int k=i, j;
			for(j=0; j<duzina1; j++) {
				if(s2.at(k)!=s1.at(j)) break;
				if(k<duzina2-1) k++;
			}
			if(j==duzina1 && (!(('a'<=s2.at(k) && s2.at(k)<='z') || ('A'<=s2.at(k) && s2.at(k)<='Z')) || k==duzina2-1) ) return i;
		}
	}
 
	return -1;

}

std::string NapraviPalindrom (std::string recenica, VektorStringova rijeci)
{

	for(unsigned int i=0; i<rijeci.size(); i++) {
		int k(0);
		do {
			int pozicija(NadjiPodstring(rijeci.at(i), recenica, k));
			if(pozicija==-1) break;

			int duzina(rijeci.at(i).length());

			recenica=recenica.substr(0, pozicija+duzina) + OkreniString(rijeci.at(i)) +
			         recenica.substr(pozicija+duzina, recenica.length());

			k+=duzina*2;
		} while (k<recenica.length());
	}

	return recenica;
}

std::string NapraviPoluPalindrom (std::string recenica, VektorStringova rijeci)
{
	int k(0);
	for(unsigned int i=0; i<rijeci.size(); i++) {

		do {
			int pozicija(NadjiPodstring(rijeci.at(i), recenica, k));
			if(pozicija==-1) break;
			int duzina(rijeci.at(i).length());
			recenica=recenica.substr(0, pozicija+duzina/2) + OkreniString(PrepoloviString((rijeci.at(i))))
			         + recenica.substr(pozicija+duzina, recenica.length());
			k+=duzina/2;
		} while (k<recenica.length());
	}

	return recenica;
}


int main ()
{
 
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);

	std::cout << "Unesite fraze: ";
	VektorStringova rijeci;
	std::string tmp;
	for(;;) {
		getline(std::cin, tmp);
		if(tmp == "") break;
		rijeci.push_back(tmp); 
	}

	std::cout << "Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica, rijeci)<<std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " <<NapraviPoluPalindrom(recenica, rijeci);

	return 0;
}