/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

bool DaLiJeRazmak (char znak)
{
	if(znak==' ')return true;
	return false;
}

bool NestoNekorektnoPigRecenica (string provjera)
{
	for(int i=0; i<provjera.size(); i++) {

		if( provjera.at(i) == ' ' or provjera.at(i)=='.' or provjera.at(i)=='!' or provjera.at(i)=='?') continue;
		if( provjera.at(i)> 'z' or provjera.at(i)< 'A') return true;

	}

	return false;
}

bool NestoNekorektnoPigFraze (string provjera)
{
	for(int i=0; i<provjera.size(); i++) {
		if( provjera.at(i)> 'z' or provjera.at(i)< 'A') return true;

	}

	return false;
}

int BrojRijeci(string recenica)
{
	int rijeci(0);
	unsigned int i(0);

	for ( i = 0; i < recenica.size(); i ++ ) {
		//skip spaces
		while ( i != recenica.size() && DaLiJeRazmak(recenica[i]) ) i++;
		if ( recenica.size() == i ) break;

		rijeci++;

		//skip characters
		while ( i != recenica.size() && !DaLiJeRazmak(recenica[i])) i++;

	}
	return rijeci;
}

vector <string> JednaPoJedna (vector<string> fraze)
{
	string probna_rijec;
	for(int i=0; i<fraze.size(); i++) {
		string probna_fraza(fraze.at(i));
		if(BrojRijeci(probna_fraza)==1) continue;

		for(int j=0; j<probna_fraza.size(); j++) {
			while(j not_eq probna_fraza.size() and DaLiJeRazmak(probna_fraza.at(j)))
				j++;

			while(j not_eq probna_fraza.size() and !DaLiJeRazmak(probna_fraza.at(j))) { //naisli smo na slovo
				probna_rijec+=probna_fraza.at(j);
				j++;
			}

			fraze.push_back(probna_rijec);
			probna_rijec="";
		}
	}
	return fraze;
}

//pomocna funkcija koja mi daje podstring koji se sastoji od
//karaktera od str[pocetak] do str[pocetak+duzina] (ne ukljucujuci str[pocetak+duzina)
string podstring(string str, int pocetak, int duzina) {
	string rezultat = "";
	for ( int i = 0; i < duzina; i ++ ) {
		if ( pocetak + duzina >= str.size() ) break;
		rezultat += str[ pocetak + i ];
	}
	return rezultat;
}

//funkcija koja u str obrce podstring na lokaciji str[pocetak] do str[kraj] ( ne ukljucujuci str[kraj] )
string obrni(string recenica, int pocetak, int kraj) {
	int i = kraj - 1;
	
	for ( int k = pocetak; k < pocetak + (kraj - pocetak) / 2; k ++ ) {
		char c = recenica.at(k);
		recenica.at(k) = recenica.at(i);
		recenica.at(i) = c;
		
		i--;
	}
	
	return recenica;
}


string ObrniFraze(string recenica, vector<string> rijeci)
{

	rijeci=JednaPoJedna(rijeci);
	string probna_rijec;
	vector <int> lokacijerijeci;
	if(rijeci.empty()) return recenica;

	for(int i=0; i < rijeci.size(); i++) {
		string fraza = rijeci.at(i);
		int duzina_fraze = fraza.size();
		
		for (int j = 0; j < int(recenica.size()) - duzina_fraze; j ++ ) {
			string pstring = podstring(recenica, j, duzina_fraze);
			
			if ( pstring == fraza ) {
				//nasli smo podfrazu, i ona pocinje na recenica[j] i duga je duzina_fraze karaktera
				//sada jos samo to obrnuti...
				recenica = obrni(recenica, j, j + duzina_fraze);
			}
		}
	}

	return recenica;
}


string IzmijeniUPigLatin ( string recenica, vector<string> rijeci)
{

	for(int i=0; i<rijeci.size(); i++)
		if(NestoNekorektnoPigRecenica(recenica) or NestoNekorektnoPigFraze(rijeci.at(i))) throw domain_error("Nekorektan izbor rijeci");

	string probna_rijec;
	vector <int> lokacijerijeci;
	if(rijeci.empty()) return recenica;

	for(int i=0; i<recenica.size(); i++) {
		while(i not_eq recenica.size() and DaLiJeRazmak(recenica.at(i))) i++;  //preskace spaceove
		if(i==recenica.size()) break;

		bool rijec=true;
		probna_rijec = "";
		while(i not_eq recenica.size() and !DaLiJeRazmak(recenica.at(i))) { //naisli smo na slovo
			if(rijec) lokacijerijeci.push_back(i);
			rijec=false;
			probna_rijec+=recenica.at(i);
			i++;
		}

		for(int j=0; j<rijeci.size(); j++) {
			if(probna_rijec == rijeci.at(j)) {
				int a=lokacijerijeci.at(lokacijerijeci.size()-1);  // pocetak probne rijeci za koju smo ustanovili da je ista kao neka od trazenih
				probna_rijec = probna_rijec + probna_rijec[0]; //prvo slovo na kraj
				probna_rijec.erase(probna_rijec.begin()); //obrisi prvo slovo
				probna_rijec += "ay"; //dodaj "ay"

				//posto ubacujem 2 nova slova, treba shiftati string za 2 mjesta...
				recenica += "  "; //najlaksi nacin da povecam string za 2 mjesta
				for (int k = int(recenica.size()) - 1; k >= a; k -- ) {
					recenica[k] = recenica[k - 2];
				}

				for(int i=0; i<probna_rijec.size(); i++) {
					recenica.at(a)=probna_rijec.at(i);
					a++;
				}
			}
		}

	}





	return recenica;
}

bool ImalFrazeURecenici (string fraza, string recenica)
{


	if(recenica.find(fraza)!= string::npos) return true;  // promijeni ovo !!

	return false;
}

vector <string> FrazeURecenici (vector <string> fraze, string recenica)
{
	vector<string> pronadenefraze;

	for(int i=0; i<fraze.size(); i++) {
		if(ImalFrazeURecenici(fraze.at(i), recenica))
			pronadenefraze.push_back(fraze.at(i));
	}
	return pronadenefraze;
}


int main ()
{
	try {
		string recenica,rijec;
		vector <string> fraze;
		cout << "Unesite recenicu: ";
		getline(cin, recenica);
		cout << "Unesite fraze: ";
		while(true) {
			getline(cin, rijec);
			fraze.push_back(rijec);
			if(cin.peek()=='\n') break;
		}

		fraze=FrazeURecenici(fraze, recenica);

		cout << "Recenica nakon PigLatin transformacije: " << IzmijeniUPigLatin(recenica,fraze) << endl ;
		cout << "Recenica nakon obrtanja fraza: "<< ObrniFraze(recenica,fraze);
	} catch(domain_error izuzetak) {
		cout << izuzetak.what() << endl;
	}
	return 0;
}