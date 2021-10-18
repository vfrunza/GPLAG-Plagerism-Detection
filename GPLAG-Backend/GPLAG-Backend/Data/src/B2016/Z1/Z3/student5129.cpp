/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

//Fercera
vector<vector<double>> RastuciPodnizovi(vector<double> vek){
	//Vracamo ovaj vektor, u njega upisujemo podnizove kao vektore
	vector<vector<double>> rastuci;
	//Duzina vektora, da kasnije bude jasnije za citati
	unsigned int duzina(vek.size());
	//Ako je unesen prazan vektor, vraca prazan vektor
	if(duzina==0) return rastuci;
	
	//Pomocni vektor u kojeg prikupljamo pojedinacne podnizove i stavljamo kao clanove vektora "RASTUCI"
	vector<double> podniz;
	bool radi(false);
	for(int i=0; i<duzina-1; i++){
		//Ako je prethodnik manji od sljedbenika, tj. ako je niz rastuci
		if(vek[i]<=vek[i+1]){
			podniz.push_back(vek[i]);
			radi=true;
		} else {
			//Ako je niz prethodno bio rastuci, ovo dodaje trenutni vek[i] na njega tako da se zadrzi zadnji clan tog poretka
			if(radi){
				podniz.push_back(vek[i]);
				radi=false;
				//Dodajemo podniz u vektor vektora koji cemo vratiti
				rastuci.push_back(podniz);
				//Cistimo podniz tako da bude spreman za unos sljedeceg podniza
				podniz.resize(0);
			}
		}
		//Za zadnji clan
		if(radi && ((i+1)==(duzina-1))){
			podniz.push_back(vek[i+1]);
			rastuci.push_back(podniz);
		}
	}
	
	return rastuci;
}

vector<vector<double>> OpadajuciPodnizovi(vector<double> vek){
	//Vracamo ovaj vektor, u njega upisujemo podnizove kao vektore
	vector<vector<double>> opadajuci;
	//Duzina vektora, da kasnije bude jasnije za citati
	unsigned int duzina(vek.size());
	//Ako je unesen prazan vektor, vraca prazan vektor
	if(duzina==0) return opadajuci;
	
	//Pomocni vektor u kojeg prikupljamo pojedinacne podnizove i stavljamo kao clanove vektora "OPADAJUCI"
	vector<double> podniz;
	bool radi(false);
	for(int i=0; i<duzina-1; i++){
		//Ako je prethodnik veci od sljedbenika, tj. ako je niz opadajuci
		if(vek[i]>=vek[i+1]){
			podniz.push_back(vek[i]);
			radi=true;
		} else {
			//Ako je niz prethodno bio opadajuci, ovo dodaje trenutni vek[i] na njega tako da se zadrzi zadnji clan tog poretka
			if(radi){
				podniz.push_back(vek[i]);
				radi=false;
				//Dodajemo podniz u vektor vektora koji cemo vratiti
				opadajuci.push_back(podniz);
				//Cistimo podniz tako da bude spreman za unos sljedeceg podniza
				podniz.resize(0);
			}
		}
		//Za zadnji clan
		if(radi && ((i+1)==(duzina-1))){
			podniz.push_back(vek[i+1]);
			opadajuci.push_back(podniz);
		}
	}
	
	return opadajuci;
}

int main (){
	cout << "Unesite broj elemenata vektora: ";
	int brelem;
	cin >> brelem;
	
	cout << "Unesite elemente vektora: ";
	vector<double> v;
	double broj;
	for(int i=0; i<brelem; i++){
		cin >> broj;
		v.push_back(broj);
	}
	
	cout << "Maksimalni rastuci podnizovi: " << std::endl;
	auto rastuci(RastuciPodnizovi(v));
	for(auto x : rastuci){
		for(auto y : x) cout << y << " ";
		cout << std::endl;
	}
	
	
	cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	auto opadajuci(OpadajuciPodnizovi(v));
	for(auto x : opadajuci){
		for(auto y : x) cout << y << " ";
		cout << std::endl;
	}
	
	return 0;
}

// 1 2 3 4 5 4 3 2 1 3 5 7 6 4 3 4 10 15 12 0			20 Clanova
// 1 2 3 4 5 4 3 2 1 3 5 7 6 4 3						15 Clanova
// 1 2 3 4 5 4 3 2 1 3 5 7 6 4 3 15 12 0 4 10			20 Clanova