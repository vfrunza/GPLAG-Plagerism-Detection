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
using std::string;
using std::cin;
using std::cout;
using std::endl;
typedef std::vector<string> strvek;
typedef std::vector<int> intvek;


intvek UpdateLokacija (int duzina, intvek lokacije)
{
	for(int i(0); i<lokacije.size(); i++)
		lokacije.at(i)+=duzina;
	return lokacije;
}

bool JelSlovo (char slovo)
{
	if ((slovo >= 'A' && slovo <='Z') || (slovo >='a' && slovo <= 'z'))
		return true;
	return false;
}

intvek LokacijeRijeci (string rijec, string recenica)
{
	intvek MPRUR; //Mjesta početaka određene riječi u rečenici
	for(int i(0); i<recenica.length(); i++) {
		if(recenica.length() >= rijec.length()+i) {
			if(rijec == recenica.substr(i, rijec.length()))
				if (i==0 || !JelSlovo(recenica.at(i-1)))
					if (rijec.length()+i>=recenica.length() || !JelSlovo(recenica.at(i+rijec.length())))
						MPRUR.push_back(i);
		}
	}
	return MPRUR;
}

string RikvercovanaRijec (string rijec)
{

	string Rikverc;
	for (int i(rijec.length()-1); i>=0; i--)
		Rikverc.push_back(rijec.at(i));

	return Rikverc;
}

string NapraviPalindrom (string Recenica, strvek Rijeci)
{
	for (auto Fraza : Rijeci) {
		intvek Lokacije = LokacijeRijeci(Fraza, Recenica);
		if(Lokacije.size()>=1) {
			for (int i(0); i<Lokacije.size(); i++) {
				int indeks_slova(0);
				string rikverc = RikvercovanaRijec(Fraza);
				for (int j(Fraza.length()+Lokacije.at(i)); j<2*Fraza.length()+Lokacije.at(i); j++) {
					Recenica.insert(j+Recenica.begin(), rikverc.at(indeks_slova));
					indeks_slova++;
				}
				Lokacije = UpdateLokacija(Fraza.length(), Lokacije);
			}
		}
	}

	return Recenica;
}

string PolaURikverc (string rijec)
{

	string stringusa(RikvercovanaRijec(rijec.substr(0, int(rijec.length()/2))));
	return stringusa;
}

string NapraviPoluPalindrom (string Recenica, strvek Rijeci)
{
	for (auto Fraza : Rijeci) {
		intvek Lokacije = LokacijeRijeci(Fraza, Recenica);
		if(Lokacije.size()>=1) {
			for (int i(0); i<Lokacije.size(); i++) {
				int indeks_slova(0);
				string rikverc = PolaURikverc(Fraza);
				int paranneparan;
				if(Fraza.length()%2==1)
					paranneparan = 1;
				else
					paranneparan = 0;
				for (int j(paranneparan+rikverc.length()+Lokacije.at(i)); j<Fraza.length()+Lokacije.at(i); j++) {
					Recenica.at(j) = rikverc.at(indeks_slova);
					indeks_slova++;
				}
			}
		}
	}
	return Recenica;
}


int main ()
{
	string Recenica;
	cout << "Unesite recenicu: " ;
	std::getline(std::cin, Recenica);
	cout << "Unesite fraze: " ;
	strvek Rijeci;
	string nekarijec;
	do {
		std::getline(std::cin, nekarijec);
		if (nekarijec.length()>=1)
			Rijeci.push_back(nekarijec);
	} while(nekarijec.length()!=0);

	cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(Recenica, Rijeci) << endl
	     << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(Recenica, Rijeci) ;

	return 0;
}