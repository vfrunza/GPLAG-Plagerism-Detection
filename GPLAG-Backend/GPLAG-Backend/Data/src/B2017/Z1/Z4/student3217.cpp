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
#include <deque>

std::vector<int> NadjiPozicije (std::string recenica, std::string fraza)
{
	std::vector<int> rezultat;
	int pozicija(recenica.find(fraza, 0));
	while (pozicija != std::string::npos) {
		rezultat.push_back(pozicija);
		pozicija = recenica.find(fraza, pozicija + 1);
	}
	return rezultat;
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze)
{

	std::string rezultat(recenica);

	for (int i(0) ; i < fraze.size() ; i++) {
		std::vector<int> pozicije (NadjiPozicije(rezultat, fraze.at(i)));
		int duzina_fraze (fraze.at(i).length());
		for (int j(0) ; j < pozicije.size() ; j++)
			pozicije.at(j) += duzina_fraze;
		std::string fraza_naopako;
		for (int j(duzina_fraze - 1) ; j >= 0 ; j--)
			fraza_naopako.push_back(fraze.at(i).at(j));
		for (int j(0) ; j < pozicije.size() ; j++) {
			std::string temp(rezultat.substr(pozicije.at(j), 1));
			if (!(temp >= "A" && temp <= "Z" || temp >= "a" && temp <= "z")) {
				rezultat.insert(pozicije.at(j), fraza_naopako);
				pozicije = NadjiPozicije(rezultat, fraze.at(i));
				for (int k(j) ; k < pozicije.size() ; k++)
					pozicije.at(k) += duzina_fraze;
			}
		}
	}
	return rezultat;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraze)
{

	std::string rezultat(recenica);

	for (int i(0) ; i < fraze.size() ; i++) {
		std::vector<int> pozicije (NadjiPozicije(rezultat, fraze.at(i)));
		int duzina_fraze (fraze.at(i).length());
		std::string prvi_dio_naopako;
		for (int j((duzina_fraze - 1) / 2) ; j >= 0 ; j--)
			prvi_dio_naopako.push_back(fraze.at(i).at(j));

		for (int j(0) ; j < pozicije.size() ; j++) {
			std::string temp(rezultat.substr(pozicije.at(j) + duzina_fraze, 1));
			if (!(temp >= "A" && temp <= "Z" || temp >= "a" && temp <= "z")) {
				int sredina = pozicije.at(j) + duzina_fraze / 2;
				rezultat.replace(sredina, prvi_dio_naopako.length(), prvi_dio_naopako);
			}
		}
	}
	return rezultat;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline (std::cin , recenica);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze;
	std::string fraza;
	std::getline(std::cin, fraza);
	while (fraza != "") {
		fraze.push_back(fraza);
		std::getline(std::cin, fraza);
	}
	std::cout << "Recenica nakon Palindrom transformacije: ";
	std::string palindrom_rec;
	palindrom_rec = NapraviPalindrom(recenica, fraze);
	std::cout << palindrom_rec;
	std::cout << std::endl << "Recenica nakon PoluPalindrom transformacije: ";
	std::string polu_pal_rec;
	polu_pal_rec = NapraviPoluPalindrom(recenica, fraze);
	std::cout << polu_pal_rec;

	return 0;
}