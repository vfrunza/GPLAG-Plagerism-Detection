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
#include <vector>
#include <string>

std::string IzokrenutaRijec (std::string rijec)
{

	std::string obrnuti;
	for(int i = rijec.length() - 1; i >= 0;  i--) {
		obrnuti.push_back(rijec.at(i));
	}
	return obrnuti;
}

bool DaLiJeSlovo(char znak)
{
	if((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z')) return true;
	return false;
}

std::string NapraviPalindrom (std::string recenica, std::vector<std::string> fraze)
{

	for(int i = 0; i < fraze.size(); i++) {

		for(int j = 0; j < recenica.size(); j++) {

			if(fraze.at(i).length() == 0) break;

			if(recenica.at(j) == fraze.at(i).at(0)) {

				for(int k = 0; j < recenica.size() ; k++) {

					if(fraze.at(i).size() - 1 == k &&  recenica.at(j) == fraze.at(i).at(k)
					        && (j == k || !DaLiJeSlovo(recenica.at(j - k - 1))) && (j == recenica.length()-1 || !DaLiJeSlovo(recenica.at(j+1)))) {

						std::string izokrenuta = IzokrenutaRijec(fraze.at(i));

						for(int l = 0; l < izokrenuta.length(); l++) {
							recenica.insert(recenica.begin() + j + l + 1, izokrenuta.at(l));
						}
						k = 0;
						continue;

					}

					if(k >= fraze.at(i).length() -1 || recenica.at(j) != fraze.at(i).at(k)) {
						k = 0;
						break;
					}

					j++;
				}

			}
		}
	}
	return recenica;

}


std::string PoluPalindrom (std::string rijec)

{
	std::string polu;

	for(int i = (rijec.length()-1)/2; i >= 0 ; i--)
		polu.push_back(rijec.at(i));

	return polu;
}

std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> fraze)
{

	for(int i = 0; i < fraze.size(); i++) {

		for(int j = 0; j < recenica.size(); j++) {

			if(recenica.at(j) == fraze.at(i).at(0)) {

				int k (0);

				for(; j < recenica.size() ; k++) {

					if(fraze.at(i).size() - 1 == k && recenica.at(j) == fraze.at(i).at(k)
					        && (j == k || !DaLiJeSlovo(recenica.at(j-k-1))) && (j == recenica.length()-1 || !DaLiJeSlovo(recenica.at(j+1)))) {


						std::string polupalindrom = PoluPalindrom(fraze.at(i));
						j -= polupalindrom.length() - 1;

						for(int l = 0; l < polupalindrom.length(); l++) {
							recenica.at(j++) =  polupalindrom.at(l); //proveriti ovaj uslov
						}

						k = 0;
						continue;
					}
					if(k >=fraze.at(i).length() -1 || recenica.at(j) != fraze.at(i).at(k)) {
						k = 0;
						break;
					}

					j++;
				}
			}
		}
	}

	return recenica;
}

int main ()
{

	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);

	std::cout << "Unesite fraze: ";

	std::vector<std::string> fraze;

	for(;;) {

		std::string trenutna;
		std::getline(std::cin, trenutna);
		if(trenutna.length() == 0) break;
		fraze.push_back(trenutna);

	}

	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze);

	std::cout << std::endl << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze);



	return 0;
}