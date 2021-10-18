/*B 2017/2018, Zadaća 2, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
int period(const vector<T>& v)
{
	if(v.size()==0) throw "Prazan vektor!";

	int p=0;

	for (int i = 1; i < v.size(); i++) {
		if(v[i]<=0) throw domain_error("Neispravan vektor!");

		if(v[i]==v[0]) {
			p=i;
			bool periodican=true;

			for (int j = 0; j < v.size()-p; j++) {
				if(v[j]!=v[j+p]) {
					periodican=false;
					break;
				}
			}
			if(periodican) break;
			p=0;
		}
	}

	return p;
}


template <typename T>
int** AlocirajFragmentirano(const vector<T>& v,int& koliko_puta)
{
	int element;
	int p = period(v);
	int broj_elemenata;

	if(p==0) {
		koliko_puta=2;
		broj_elemenata = koliko_puta * v.size();
		p=v.size();
	} else {
		int ostatak = v.size()%p;
		koliko_puta = v.size()/p;
		if(ostatak>0) {
			koliko_puta++;
		}
		broj_elemenata = koliko_puta * p;
	}





	int** matrica=nullptr;


	try {
		matrica = new int*[broj_elemenata];
		for (int i = 0; i < broj_elemenata; i++) {
			matrica[i]=nullptr;
		}

		try {
			for (int i = 0; i < broj_elemenata; i++) {
				if(i<v.size())element=v[i];
				else element=v[i-p];
				matrica[i] = new int[element];
			}

		} catch(bad_alloc) {
			for (int i = 0; i < broj_elemenata; i++) {
				delete[] matrica[i];
			}
			delete[] matrica;
			throw;
		}

	} catch(bad_alloc) {
		throw;
	}

	int najveci = v[0];

	for (int i = 0; i < v.size(); i++) {
		if(v[i]>najveci) najveci=v[i];
	}


	for(int i=0; i<broj_elemenata; i++) {
		int k=najveci;
		if(i<v.size())element=v[i];
		else element=v[i-p];
		for(int j=element-1; j>=0; j--) {
			matrica[i][j]=k--;
		}
	}



	return matrica;
}



template <typename T>
int** AlocirajKontinualno(const vector<T>& v,int& koliko_puta)
{
	int element;
	int p = period(v);
	int broj_elemenata;

	if(p==0) {
		koliko_puta=2;
		broj_elemenata = koliko_puta * v.size();
		p=v.size();
	} else {
		int ostatak = v.size()%p;
		koliko_puta = v.size()/p;
		if(ostatak>0) {
			koliko_puta++;
		}
		broj_elemenata = koliko_puta * p;
	}

	int** matrica=nullptr;

	try {
		matrica = new int*[broj_elemenata];

		int ukupno = 0;
		for (int i = 0; i < broj_elemenata; i++) {

			if(i<v.size())element=v[i];
			else element=v[i-p];
			ukupno+=element;
		}
		try {
			matrica[0] = new int[ukupno];

			for (int i = 1; i < broj_elemenata; i++) {
				int prethodni_element;
				if(i-1<v.size())prethodni_element=v[i-1];
				else prethodni_element=v[i-1-p];
				matrica[i] = matrica[i-1]+prethodni_element; //prethodni element
			}
		} catch(bad_alloc) {
			delete[] matrica;
		}

	} catch(bad_alloc) {
		throw;
	}




	for(int i=0; i<broj_elemenata; i++) {
		int k=1;
		if(i<v.size())element=v[i];
		else element=v[i-p];
		for(int j=element-1; j>=0; j--) {
			matrica[i][j]=k++;
		}
	}

	return matrica;
}



int main ()
{
	int n,element;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<int>v(n);
	cout<<"Unesite elemente vektora: ";
	for (int i = 0; i < v.size(); i++) {
		cin>>v[i];
	}

	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int vrsta_alokacije;
	cin>>vrsta_alokacije;

	int **M=nullptr;
	int koliko_puta;
	try {
		if(vrsta_alokacije==1) {
			M=AlocirajFragmentirano(v,koliko_puta);
		} else {
			M = AlocirajKontinualno(v,koliko_puta);
		}

		int p = period(v);

		int broj_elemenata;
		if(p==0){
			broj_elemenata = v.size()*koliko_puta;
			p=v.size();
		}
		else{
			broj_elemenata = p*koliko_puta;
		}
		cout<<"Dinamicki alocirana matrica:"<<endl;
		for (int i = 0; i < broj_elemenata ; i++) {
			if(i<v.size())element=v[i];
			else element=v[i-p];

			for (int j = 0; j < element; j++) {
				cout<<setw(3)<<left<<M[i][j];
			}
			cout<<endl;
		}

		if(vrsta_alokacije==1) {
			for (int i = 0; i < broj_elemenata; i++) {
				delete[] M[i];
			}
			delete[] M;
		} else {
			delete[] M[0];
			delete[] M;
		}
	} catch(domain_error e) {
		cout<<"Izuzetak: "<<e.what()<<endl;
	} catch(bad_alloc e) {
		cout<<"Izuzetak: "<<"Nema memorije!"<<endl;
	} catch(const char poruka[]) {
		cout<<"Izuzetak: "<<poruka<<endl;
	}
	return 0;
}