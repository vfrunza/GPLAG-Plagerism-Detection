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


std::string ObrniFrazu(std::string Fraza)
{

	std::string Obrnuti=Fraza;
	char znak;
	for(int i=0; i<Obrnuti.length()/2; i++) {

		znak=Obrnuti.at(i);
		Obrnuti.at(i)=Obrnuti.at((Obrnuti.length()-1)-i);
		Obrnuti.at((Obrnuti.length()-1)-i)=znak;
	}
	return Obrnuti;

}

bool ProvjeraRubovaRijeci(char RuboviFraze)
{
	if((RuboviFraze>='a' && RuboviFraze<='z') || (RuboviFraze>='A' && RuboviFraze<='Z')) return false;
	return true;
}

std::string NapraviPalindrom(std::string Recenica, std::vector<std::string> Fraze)
{

	std::string Pomoc;

	for(int i=0; i<Fraze.size(); i++) {

		int duzina;
		duzina=Fraze.at(i).size();

		for(int j=0; j<Recenica.length(); j++) {


			Pomoc=Recenica.substr(j,duzina);
			if(Pomoc==Fraze.at(i)) {

				if(j==0 && j+duzina>Recenica.length()-1) { //ako se unese jedna rijec
					Recenica.insert(j+duzina,ObrniFrazu(Pomoc));
					j+=(2*duzina);
				}

				else if(j==0 && ProvjeraRubovaRijeci(Recenica.at(j+duzina))) { //pocetak recenice
					Recenica.insert(j+duzina,ObrniFrazu(Pomoc));
					j+=(2*duzina);
				}

				else if(j+duzina<=Recenica.length()-1 && j!=0 && ProvjeraRubovaRijeci(Recenica.at(j-1)) && ProvjeraRubovaRijeci(Recenica.at(j+duzina))) {
					Recenica.insert(j+duzina,ObrniFrazu(Pomoc));
					j+=(2*duzina);
				}

				else if(j!=0 && ProvjeraRubovaRijeci(Recenica.at(j-1)) && j+duzina==Recenica.length()) {
					Recenica.insert(j+duzina,ObrniFrazu(Pomoc));
					j+=(2*duzina);
				}
			}

		}
	}

	return Recenica;
}

std::string NapraviPoluPalindrom(std::string Recenica, std::vector<std::string> Fraze)
{

	std::string Pomoc;

	for(int i=0; i<Fraze.size(); i++) {

		int duzina;
		duzina=Fraze.at(i).size();

		for(int j=0; j<Recenica.length(); j++) {

			Pomoc=Recenica.substr(j,duzina);
			if(Pomoc==Fraze.at(i)) {


				if(Pomoc.length()%2==0) {

					if(j==0 && j+duzina>Recenica.length()-1) { //ako se unese jedan rijec
						Recenica.erase(j+(duzina/2),Pomoc.length()/2);
						Recenica.insert(j+(duzina/2),ObrniFrazu(Pomoc.substr(0,(duzina/2))));
						j+=(duzina/2);
					}

					else if(j==0 && ProvjeraRubovaRijeci(Recenica.at(j+duzina))) {
						Recenica.erase(j+(duzina/2),Pomoc.length()/2);
						Recenica.insert(j+(duzina/2),ObrniFrazu(Pomoc.substr(0,(duzina/2))));
						j+=(duzina/2);
					}

					else if(j!=0 && j+duzina<=Recenica.length()-1 && ProvjeraRubovaRijeci(Recenica.at(j-1)) && ProvjeraRubovaRijeci(Recenica.at(j+duzina))) {
						Recenica.erase(j+(duzina/2),Pomoc.length()/2);
						Recenica.insert(j+(duzina/2),ObrniFrazu(Pomoc.substr(0,(duzina/2))));
						j+=(duzina/2);
					}

					else if(j!=0 && ProvjeraRubovaRijeci(Recenica.at(j-1)) && j+duzina==Recenica.length()) {
						Recenica.erase(j+(duzina/2),Pomoc.length()/2);
						Recenica.insert(j+(duzina/2),ObrniFrazu(Pomoc.substr(0,(duzina/2))));
						j+=(duzina/2);
					}
				}

				else {
					if(j==0 && j+duzina>Recenica.length()-1) {
						Recenica.erase(j+(1+duzina/2),Pomoc.length()/2);
						Recenica.insert(j+(1+duzina/2),ObrniFrazu(Pomoc.substr(0,(duzina/2))));
						j+=(duzina/2);
					}

					else if(j==0 && ProvjeraRubovaRijeci(Recenica.at(j+duzina))) {
						Recenica.erase(j+(1+duzina/2),Pomoc.length()/2);
						Recenica.insert(j+(1+duzina/2),ObrniFrazu(Pomoc.substr(0,(duzina/2))));
						j+=(duzina/2);
					}

					else if(j!=0 && (j+duzina<=Recenica.length()-1) && ProvjeraRubovaRijeci(Recenica.at(j-1)) && ProvjeraRubovaRijeci(Recenica.at(j+duzina))) {
						Recenica.erase(j+(1+duzina/2),Pomoc.length()/2);
						Recenica.insert(j+(1+duzina/2),ObrniFrazu(Pomoc.substr(0,(duzina/2))));
						j+=(duzina/2);
					}

					else if(j!=0 && ProvjeraRubovaRijeci(Recenica.at(j-1)) && j+duzina==Recenica.length()) {
						Recenica.erase(j+(1+duzina/2),Pomoc.length()/2);
						Recenica.insert(j+(1+duzina/2),ObrniFrazu(Pomoc.substr(0,(duzina/2))));
						j+=(duzina/2);
					}
				}
			}
		}

	}

	return Recenica;
}

int main ()
{
	std::string Recenica;
	std::cout << "Unesite recenicu: " ;
	std::getline(std::cin,Recenica);

	std::vector<std::string> VektorFraza;
	std::string Fraza;

	std::cout << "Unesite fraze: " ;

	while(1) {
		std::getline(std::cin,Fraza);
		if (Fraza=="") break;
		VektorFraza.push_back(Fraza);
	}


	std::cout <<"Recenica nakon Palindrom transformacije: " << NapraviPalindrom(Recenica,VektorFraza) << std::endl;
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(Recenica,VektorFraza);

	return 0;
}