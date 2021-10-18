/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cmath>

using std::cin; using std::cout; using std::endl;

int SumaCifara (long long int broj) {
	int suma(0);
	do {
		int cifra(fabs(broj%10));
		suma+=cifra;
		broj/=10;
	}
	while (broj!=0);
	return suma;
}

int SumaDjelilaca(long long int broj) {
	int suma(0); 
	long long int br(fabs(broj));
	for (int i=1; i<=br; i++) { //Ubaci za prekoracenje
		if (br%i==0)
		suma+=i;
	}
	return suma;
}

int BrojProstihFaktora (long long int broj) {
	//Nadjimo prvo faktore broja, a zatim izbacimo proste
	std::vector<int> vek; //Vektor prostih faktora
	long long int n(broj);
	for (int i=2; i<=n; i++) { //Long long?
		while(n%i==0) {
			vek.push_back(i);
			n/=i;
		}
	}
	return vek.size();
}

int BrojSavrsenihDjelilaca (long long int broj) {
	long long int n(fabs(broj));
	int brojac(0);
	for (int i=2; i<=n; i++) {
		if (n%i==0) {
			if (i==(SumaDjelilaca(i)-i)) brojac++; 
		}
	}
	return brojac;
}

template <typename Kontejner1, typename Kontejner2, typename NekiTip1, typename NekiTip2>
auto UvrnutiPresjek(Kontejner1 poc1, Kontejner1 iza_k1, Kontejner2 poc2, Kontejner2 iza_k2, NekiTip2 funkcija(NekiTip1)) -> typename std::vector<std::vector<decltype(*poc1+*poc1)>> {
	typedef decltype(*poc1+*poc1) Tip;
	int brojac(0);
	std::vector<Tip> vek;
	for (int i=0; i<(iza_k1-poc1); i++) {
		for (int j=0; j<(iza_k2-poc2); j++) {
			if (funkcija(poc1[i])==funkcija(poc2[j])) {
				vek.push_back(poc1[i]); vek.push_back(poc2[j]); vek.push_back(funkcija(poc1[i]));
				brojac++; //Broj elemenata u presjeku
			}
		}
	}
	std::vector<std::vector<Tip>> matrica(brojac, std::vector<Tip>(3)); //Matrica formata br.elx3
	int k(0);
	for (int i=0; i<brojac; i++) {
		for (int j=0; j<3; j++) {
			matrica[i][j]=vek[k];
			k++;
		}
	}
	//Prije vracanja sortirajmo 
	sort(matrica.begin(), matrica.end());
		/*Sortirajmo potrebno je njene redove sortirati u rastući poredak po vrijednosti treće koordinate, tj. po vrijednosti
funkcije . Ukoliko dva reda imaju istu vrijednost f, tada ih treba sortirati po vrijednosti x, a
ukoliko se i vrijednoti x poklapaju, onda po vrijednosti y. Za sortiranje obavezno koristite
funkciju “sort” iz biblioteke “algorithm” uz prikladnu funkciju kriterija implementiranu kao
lambda funkcija.*/
	sort (matrica.begin(), matrica.end(), [] (std::vector<Tip> v1, std::vector<Tip> v2) {
		if (v1[2]==v2[2]) { //Ako su iste vrijednosti funkcije, tj. trece koordinate
			if (v1[0]==v2[0]) { //Ako je isto x
				return v1[1]<v2[1]; //Opadajuci
			}
			return v1[0]<v2[0];
		}
		return v1[2]<v2[2]; //Rastuci kriterij
	});
	return matrica;
}

template <typename Kontejner, typename Kontejner2>
auto UvrnutiPresjek (Kontejner poc1, Kontejner iza_k1, Kontejner2 poc2, Kontejner2 iza_k2) -> typename std::vector<std::vector<decltype(*poc1+*poc1)>> {
	typedef decltype(*poc1+*poc1) Tip;
	std::vector<Tip> vek; 
	int brojac(0);
	for (int i=0; i<(iza_k1-poc1); i++) {
		for (int j=0; j<(iza_k2-poc2); j++) {
			if (poc1[i]==poc2[j]) {
				//Provjerimo da li se element vec javlja u vektoru
				int k(0);
				for (k=0; k<vek.size(); k++) {
					if (poc1[i]==vek[k]) break;
				}
				if (k==vek.size()) {
					vek.push_back(poc1[i]);	//Pronasli smo element presjeka
					brojac++;
				}
			}
		}
	}
	std::vector<std::vector<Tip>> matrica (brojac, std::vector<Tip>(3));
	for (int i=0; i<brojac; i++) {
		for (int j=0; j<3; j++) {
			matrica[i][0]=vek[i];
			if (j!=0) {
				matrica[i][j]=0;    
			}
		}
	}
	//Prije vracanja sortirajmo
	sort(matrica.begin(), matrica.end());
	return matrica;
}

template <typename Kontejner1, typename Kontejner2, typename NekiTip1, typename NekiTip2>
auto UvrnutaRazlika(Kontejner1 poc1, Kontejner1 iza_k1, Kontejner2 poc2, Kontejner2 iza_k2, NekiTip2 funkcija(NekiTip1)) -> typename std::vector<std::vector<decltype(*poc1+*poc1)>> {
	int brojac(0);
	typedef decltype(*poc1+*poc1) Tip;
	std::vector<Tip> vek;
	//Razlika kont1 i kont2
	for (int i=0; i<(iza_k1-poc1); i++) {
		int j(0);
		for (j=0; j<(iza_k2-poc2); j++) {
			if (funkcija(poc1[i])==funkcija(poc2[j])) break; 
		}
		//Ako nismo pronasli ni jednu vrijednost, pronasli smo razliku
		if (j==iza_k2-poc2) { //Provjerimo da li se nalazi vec u vektoru
			int k(0);
			for (k=0; k<vek.size(); k++) {
				if (poc1[i]==vek[k]) break;
			}
			if (k==vek.size()) { //Nije doslo de prekida
				vek.push_back(poc1[i]); vek.push_back(funkcija(poc1[i]));
				brojac++; //Broj elemenata u presjeku
				}
		}
	}
	//Razlika kont2 i kont1
	for (int j=0; j<(iza_k2-poc2); j++) {
		int i(0);
		for (i=0; i<(iza_k1-poc1); i++) {
			if (funkcija(poc1[i])==funkcija(poc2[j])) break; 
		}
		//Ako nismo pronasli ni jednu vrijednost jednaku, pronasli smo razliku
		if (i==iza_k1-poc1) { //Provjerimo da li se nalazi vec u vektoru
			int k(0);
			for (k=0; k<vek.size(); k++) {
				if (poc2[j]==vek[k]) break;
			}
			if (k==vek.size()) { //Nije doslo de prekida
				vek.push_back(poc2[j]); vek.push_back(funkcija(poc2[j]));
				brojac++; //Broj elemenata u presjeku
				}
		}
	}
	
	std::vector<std::vector<Tip>> matrica(brojac, std::vector<Tip>(2)); //Matrica formata br.elx2
	int k(0);
	for (int i=0; i<brojac; i++) {
		for (int j=0; j<2; j++) {
			matrica[i][j]=vek[k];
			k++;
		}
	}
	//Konacno, sortirajmo matricu
	sort (matrica.begin(), matrica.end(), [] (std::vector<Tip> v1, std::vector<Tip> v2) {
		if (v1[0]==v2[0]) return v1[1]>v2[1];
		return v1[0]>v2[0];
	});
	
	return matrica;
}

//Uvrnuta razlika sa cetiri parametra
template <typename Kontejner, typename Kontejner2>
auto UvrnutaRazlika (Kontejner poc1, Kontejner iza_k1, Kontejner2 poc2, Kontejner2 iza_k2) -> typename std::vector<std::vector<decltype(*poc1+*poc1)>> {
	typedef decltype(*poc1+*poc1) Tip;
	int brojac(0);
	std::vector<Tip> vek;
	//Razlika kont1 i kont2
	for (int i=0; i<(iza_k1-poc1); i++) {
		int j(0);
		for (j=0; j<(iza_k2-poc2); j++) {
			if (poc1[i]==poc2[j]) break; 
		}
		//Ako nismo pronasli ni jednu vrijednost, pronasli smo razliku
		if (j==iza_k2-poc2) { //Provjerimo da li se nalazi vec u vektoru
			int k(0);
			for (k=0; k<vek.size(); k++) {
				if (poc1[i]==vek[k]) break;
			}
			if (k==vek.size()) { //Nije doslo de prekida
				vek.push_back(poc1[i]); vek.push_back(0);
				brojac++; //Broj elemenata u presjeku
				}
		}
	}
	//Razlika kont2 i kont1
	for (int j=0; j<(iza_k2-poc2); j++) {
		int i(0);
		for (i=0; i<(iza_k1-poc1); i++) {
			if (poc1[i]==poc2[j]) break; 
		}
		//Ako nismo pronasli ni jednu vrijednost jednaku, pronasli smo razliku
		if (i==iza_k1-poc1) { //Provjerimo da li se nalazi vec u vektoru
			int k(0);
			for (k=0; k<vek.size(); k++) {
				if (poc2[j]==vek[k]) break;
			}
			if (k==vek.size()) { //Nije doslo de prekida
				vek.push_back(poc2[j]); vek.push_back(0);
				brojac++; //Broj elemenata u presjeku
				}
		}
	}
	std::vector<std::vector<Tip>> matrica (brojac, std::vector<Tip>(2));
	int k(0);
	for (int i=0; i<brojac; i++) {
		for (int j=0; j<2; j++) {
			matrica[i][j]=vek[k];
			k++;
		}
	}
	//Prije vracanja sortirajmo
	sort(matrica.begin(), matrica.end(), [] (std::vector<int> v1, std::vector<Tip> v2) {
		return v1[0]>v2[0];
	});
	return matrica;
}

int main ()
{
	std::deque<int> dek1, dek2;
	//cout << BrojProstihFaktora(5) << endl;
	//cout << BrojSavrsenihDjelilaca(168);
	cout << "Unesite broj elemenata prvog kontejnera: ";
	int br1, br2;
	cin >> br1;
	//Pri unosu treba obezbijediti da se ponavljanje već unesenog elementa ignorira, tako da oba deka sigurno imaju sve različite elemente prije poziva funkcija
	cout << "Unesite elemente prvog kontejnera: ";
	for (int i=0; i<br1; i++) {
		int broj; 
		cin >> broj;
		for (int i=0; i<dek1.size(); i++) {
			while (dek1[i]==broj)  {
				cin>> broj; i=0; 
			}
		}
		dek1.push_back(broj);
	}
	cout << "Unesite broj elemenata drugog kontejnera: ";
	cin >> br2; //Ispravi unos!!!!
	cout << "Unesite elemente drugog kontejnera: ";
	for (int i=0; i<br2; i++) {
		int broj;
		cin >> broj; //Provjerimo je li vec unesen
		for (int i=0; i<dek2.size(); i++) {
			while (dek2[i]==broj) {
				cin>> broj; i=0; 
			}
		}
		dek2.push_back(broj);
	}
	auto matrica=UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara);
	cout << "Uvrnuti presjek kontejnera: " << endl;
	for (int i=0; i<matrica.size(); i++) {
		for (int j=0; j<3; j++) {
			cout << std::setw(6) <<matrica[i][j] << " " ;
		}
		cout << endl;
	}
	auto matrica1=UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	
	cout << "Uvrnuta razlika kontejnera: " << endl;
	for (int i=0; i<matrica1.size(); i++) {
		for (int j=0; j<2; j++) {
			cout << std::setw(6) <<matrica1[i][j] << " " ;
		}
		cout << endl;
	}
	cout << "Dovidjenja!";
	return 0;
}