#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

typedef std::deque<std::vector<int>> Matrica;
typedef std::vector<int> Vector;

using std::cout;
using std::cin;

enum Smjer {Rastuci , Opadajuci };

//Funkcija koja vraca broj redova matrice
int broj_redova(Matrica m)
{
	return m.size();
}

//Funkcija koja vraca duzinu kolone u nekome redu
int broj_kolona(Matrica m, int red)
{
	return m.at(red).size();
}

//Funkcija za upis vektora u novi red matrice
Matrica Upis (Matrica matrix, int red, Vector v)
{
	matrix.resize(red + 1);
	matrix.at(red).resize(v.size());
	for(int i(0); i<v.size(); i++) matrix.at(red).at(i) = v.at(i);

	return matrix;
}

//Funkcija za ispitivanje da li je broj stepen dvojke
bool stepen_dvojke(int n)
{
	int stepen;
	for(int i(0); i<n; i++) {
		stepen = pow(2,i);
		if(stepen == n) return true;
	}
	return false;
}

bool NijeUMatrici (Matrica m, Vector v)
{
	Vector poredi;


	for(int i(0); i<broj_redova(m); i++) {
		for(int j(0); j<broj_kolona(m,i); j++) {
			if(broj_kolona(m,i) == v.size()) {

				for(int x(0); x<broj_kolona(m, i); x++) poredi.push_back(m.at(i).at(x));
				if(poredi == v) return false;
			}
		}
	}

	return true;
}


//Funkcija iz Zadatka
Matrica MaksimalniPodnizoviStepenaDvojke(Vector v, enum Smjer smjer)
{
	Matrica Podnizovi;
	Vector niz;

	//RASTUCI
	if(smjer == Rastuci) {
		int red(0), brojac(0);
		for(int i(0); i<v.size(); i++) {

			if(i<v.size())
				while(1) {
					if(i<v.size() - 1) {
						if(v.at(i) > v.at(i + 1) || (stepen_dvojke(v.at(i)) == false)) {
							if(stepen_dvojke(v.at(i))) niz.push_back(v.at(i));
							break; //break-a petlju ako je sljedbenik manji ili ako broj nije stepen dvojke
						}
						if(v.at(i) <= v.at(i + 1) && stepen_dvojke(v.at(i))) niz.push_back(v.at(i));
						i++;
					} else if(i == v.size() - 1) {
						if(v.at(i) >= v.at(i - 1) && stepen_dvojke(v.at(i))) niz.push_back(v.at(i));
						break;
					}
				}

			//UPIS RASTUCEG PODNIZA
			if(niz.size()>1 && NijeUMatrici(Podnizovi, niz)) {
				Podnizovi = Upis(Podnizovi, red, niz);
				red++;
			}
			//KRAJ UPISA RASTUCEG PODNIZA U MATRICU
			brojac = 0;
			niz.resize(0);
			if(i==v.size() - 1 ) {
				break;
			}
		}
	}
	//OPADAJUCI
	else if(smjer == Opadajuci) {
		int red(0), brojac(0);
		for(int i(0); i<v.size(); i++) {

			if(i<v.size())
				while(1) {
					if(i<v.size() - 1) {
						if(v.at(i) < v.at(i + 1) || (stepen_dvojke(v.at(i)) == false)) {
							if(stepen_dvojke(v.at(i))) niz.push_back(v.at(i));
							break; //break-a petlju ako je sljedbenik veci ili ako broj nije stepen dvojke
						}
						if(v.at(i) >= v.at(i + 1) && stepen_dvojke(v.at(i))) niz.push_back(v.at(i));
						i++;
					} else if(i == v.size() - 1) {
						if(v.at(i) <= v.at(i - 1) && stepen_dvojke(v.at(i))) niz.push_back(v.at(i));
						break;
					}
				}

			//UPIS RASTUCEG PODNIZA
			if(niz.size() > 1 && NijeUMatrici(Podnizovi, niz)) {
				Podnizovi = Upis(Podnizovi, red, niz);
				red++;
			}
			//KRAJ UPISA RASTUCEG PODNIZA U MATRICU
			brojac = 0;
			niz.resize(0);
			if(i==v.size() - 1 ) {
				break;
			}
		}
	}

	return Podnizovi;
}

//Main Funkcija
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int e;
	cin>> e;
	Vector v;
	cout<<"Unesite elemente vektora: ";
	int unos;
	for(int i(0); i<e; i++) {
		cin>>unos;
		v.push_back(unos);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int smjer;
	cin>>smjer;
	Matrica Podnizovi;
	if(smjer == 1) {
		cout<<"Maksimalni rastuci podnizovi: \n";
		Podnizovi = (MaksimalniPodnizoviStepenaDvojke(v, Rastuci));
	} else if(smjer == 2) {
		cout<<"Maksimalni opadajuci podnizovi: \n";
		Podnizovi = (MaksimalniPodnizoviStepenaDvojke(v, Opadajuci));
	}
	for(int i(0); i<broj_redova(Podnizovi); i++) {
		for(int j(0); j<broj_kolona(Podnizovi,i); j++) {
			cout<<Podnizovi.at(i).at(j)<<" ";
		}
		cout<<"\n";
	}

	return 0;
}