/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <cstring>

using std::cin; using std::cout; using std::endl; using std::string; using std::vector;

string ObrniFraze (string recenica, vector<string> vektor_stringova) {
	string modificirana (recenica);
	if (vektor_stringova.size()==0) return recenica;

	for (int i=0; i<vektor_stringova.size(); i++) { //Prolazimo kroz listu fraza
		for (int j=0; j<modificirana.size(); j++) { //Prolazimo kroz recenicu
	        int poc (j); int k;
			for (k=0; k<vektor_stringova[i].size(); k++) { //prolazimo kroz frazu
				if (modificirana.at(j)!=vektor_stringova.at(i).at(k))
				break; //Nisu iste
				if (j==modificirana.size()-1) {
					//Ako je zadnji char, ostali znakovi su isti
					k++;
					break;
				}
			    j++;
			}
			if (k==vektor_stringova[i].size()) {
			//Pronasli smo rijec koju trebamo zamijeniti
			j=poc;
				for (int k=(vektor_stringova[i].size()-1); k>=0; k--) {
					modificirana.at(j)=vektor_stringova.at(i).at(k);
					j++;
				}
				//cout << modificirana << endl;
			j--; //da provjerimo sljedeci, a ne dva puta povecani!
		    }
	    }
	}
	return modificirana;
}

string IzmijeniUPigLatin (string recenica, vector<string> vektor_stringova) {
	string modificirana(recenica);
	//Ako je vektor stringova prazan mijenjamo sve rijeci
	if (vektor_stringova.size()==0) {
		bool neslovo(true);
		for (int i=0; i<modificirana.size(); i++) {
			if (modificirana.at(i)<'A' || (modificirana.at(i)>'Z' && modificirana.at(i)<'a') || modificirana.at(i)>'z') neslovo=true;
			else if (neslovo==true) {
				//Pronasli smo rijec
				neslovo=false;
				//Pretvorimo je u piglatin¸
				int poc(i); int kraj(i);
				//Pronadjimo kraj rijeci (indeks)
				while (kraj<modificirana.size() && ((modificirana.at(kraj)>='A' && modificirana.at(kraj)<='Z') || (modificirana.at(kraj)>='a' && modificirana.at(kraj)<='z')) ) { //Pazi na prekoracenkraje
					kraj++;
				}
				char prvo=modificirana[poc];
				for (int j=i; j<kraj; j++) {
					modificirana[j]=modificirana[j+1]; //j+1 na zadnje slovo!
				}
				modificirana[kraj-1]=prvo;
				//dodajmo samda ay
				//string pomocna;
				modificirana=modificirana.substr(0,kraj)+"ay"+modificirana.substr(kraj,modificirana.size());
				//modificirana=pomocna;
			}
		}
		return modificirana;
	}

	//Provjerimo da li je ispravan vektor stringova, smiju biti samo slova alfabeta!
	for (int i=0; i<vektor_stringova.size(); i++) {
		for (int j=0; j<vektor_stringova[i].size(); j++) {
			if (vektor_stringova[i][j]<'A' || (vektor_stringova[i][j]>'Z' && vektor_stringova[i][j]<'a') || vektor_stringova[i][j]>'z')
			throw std::domain_error ("Nekorektan izbor rijeci");
		}
	}

	//u PigLatin mijenjamo samo rijeci
	for (int i=0; i<vektor_stringova.size(); i++) { //Prolazimo kroz vektor rijeci koje trebamo zamijeniti
			bool neslovo(true);
			for (int j=0; j<modificirana.size(); j++) { //Prolazimo kroz recenicu
			if (modificirana.at(j)<'A' || (modificirana.at(j)>'Z' && modificirana.at(j)<'a') || modificirana.at(j)>'z') neslovo=true;
			else if (neslovo==true) {
				//Pronasli smo rijec
				neslovo=false;
				//Pretvorimo je u piglatin¸
				int poc(j); int kraj(j); string pomocna;
				//Pronadjimo kraj rijeci (indeks)
				while (kraj<modificirana.size() && ((modificirana.at(kraj)>='A' && modificirana.at(kraj)<='Z') || (modificirana.at(kraj)>='a' && modificirana.at(kraj)<='z')) ) { //Pazi na prekoracenje
				    pomocna.push_back(modificirana[kraj]);
					kraj++; //Pokazuje iza kraja rijeci
				}
				//Provjerimo da li je rijec na spisku
				int k;
				for (k=0; k<vektor_stringova[i].size(); k++) {
					if (k==pomocna.size() || pomocna.at(k)!= vektor_stringova.at(i).at(k))
					break; //nisu iste
				}
				if (k==pomocna.size() && k==vektor_stringova[i].size()) { //Pronasli smo rijec koju treba mijenjati
				    char prvo=modificirana[poc];
				    j=poc;
				    for (int m=j; m<kraj-1  ; m++) {
					modificirana[m]=modificirana[m+1]; //j+1 na zadnje slovo!
					}
					modificirana[kraj-1]=prvo;  //dodajmo samda ay
				    string pomocna;
				    pomocna=modificirana.substr(0,kraj)+"ay"+modificirana.substr(kraj,modificirana.size());
				    modificirana=pomocna;
				}
			}
		}
	}
	return modificirana;
}

int main ()
{
	string recenica, fraza;
	cout << "Unesite recenicu: ";
	std::getline(cin, recenica);
	vector<string> lista;
	cout << "Unesite fraze: ";
    for (int i=0; ; i++) {
    	std::getline(cin, fraza);
    	if (fraza.size()==0) break;
    	lista.resize(i+1);
    	lista[i]=fraza;
    }

    bool ispis(true);
    try {
    	IzmijeniUPigLatin(recenica, lista);
	}
	catch (std::domain_error izuzetak) {
      cout << izuzetak.what() << endl;
      ispis=false;
   }
    if (ispis) cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica, lista) << endl;
	
	cout << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, lista);

	return 0;
}
