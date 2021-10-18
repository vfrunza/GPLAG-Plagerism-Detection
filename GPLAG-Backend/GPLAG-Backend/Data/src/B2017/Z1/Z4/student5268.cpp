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
#include <cmath>

bool DaLiJeSlovo(char znak)
{
	return ((znak>='A' && znak<='Z') || (znak>='a' && znak<='z'));
}

std::string NapraviPalindrom(std::string recenica,std::vector<std::string>vektor)
{

	std::string pomocna(recenica);

	for(int i=0; i<vektor.size(); i++) {	//spisak fraza
		std::string fraza(vektor.at(i));

		for(int j=0; j<pomocna.length(); j++) {		//recenica

	//provjera opsega i (zadnja rijec ili nije slovo) i da li je fraza=podstringu
			if(j+fraza.length()<=pomocna.length() &&
			        (j+fraza.length()==pomocna.length() ||
			         !DaLiJeSlovo(pomocna.at(j+fraza.length())))
			        && fraza==pomocna.substr(j,fraza.length())) {
				
				std::string obrnuto(fraza.length(),' ');

				int l=0;

				for(int k=(fraza.length()-1); k>=0; k--) {	//obrnuta fraza
					obrnuto.at(l++)=fraza.at(k);

				}

				std::string palindrom;
				palindrom=obrnuto;

				int m=0;

				for(int n=0; n<palindrom.length(); n++) {
					pomocna.insert(pomocna.begin()+fraza.length()+(j++),
					               palindrom.at(m++));	//palindom uz frazu
				}


			}
		}
	}

	return pomocna;

}

std::string NapraviPoluPalindrom(std::string recenica,std::vector<std::string>vektor)
{

	std::string pomocna(recenica);

	for(int i=0; i<vektor.size(); i++) {
		std::string fraza(vektor.at(i));

		for(int j=0; j<pomocna.length(); j++) {

			if(j+fraza.length()<=pomocna.length() &&
			        (j+fraza.length()==pomocna.length()
			         || !DaLiJeSlovo(pomocna.at(j+fraza.length())))
			        && fraza==pomocna.substr(j,fraza.length())) {
			        	
			    //zaokruziti duzinu na vecu vrijednost   	
				std::string obrnuto(ceil((fraza.length())/2.),' ');

				int l=0;
				
				//prva polovina obrnuto
				for(int k=ceil((fraza.length())/2.)-1; k>=0; k--) {
					obrnuto.at(l++)=fraza.at(k);
				}

				std::string polupalindrom;
				polupalindrom=obrnuto;


				int m=0;
				int duzina(0);
				
				//dodajem polupalindrom
				for(int n=0; n<polupalindrom.length(); n++) {
					duzina=floor((fraza.length()/2.))+(j++);
					pomocna.insert(pomocna.begin()+duzina,polupalindrom.at(m++));
				}
				
				//brisem drugi dio fraze
				for(int o=(duzina+ceil((fraza.length())/2.)); o>duzina; o--) {
					pomocna.erase(pomocna.begin()+o);
				}
			}
		}
	}
	return pomocna;
}


int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);

	std::vector<std::string>fraze;
	std::string fraza;
	char znak;

	std::cout << "Unesite fraze: ";

	while((znak=std::cin.get())!='\n') {
		std::getline(std::cin,fraza);
		fraza=znak+fraza;
		fraze.push_back(fraza);
	}

	std::cout << "Recenica nakon Palindrom transformacije: "
	          <<NapraviPalindrom(recenica,fraze);

	std::cout << "\nRecenica nakon PoluPalindrom transformacije: "
	          <<NapraviPoluPalindrom(recenica,fraze);

	return 0;
}