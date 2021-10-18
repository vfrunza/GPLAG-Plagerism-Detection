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
#include <vector>
#include <algorithm>
#include <string>
using std::cout;
using std::cin;
template<typename CijeliTip> 
int PretvoriUPeriodican(const std::vector<CijeliTip> &Vektor, int &koliko_puta) {
	if (!Vektor.size()) return 0;
	bool periodican(false);
	int period;
	for (int i=1;i<Vektor.size();i++) {
		if (i<=Vektor.size()/2) {
		if (std::equal(Vektor.begin(), Vektor.begin()+i, Vektor.begin()+i)) {
			int j=i;
			periodican=true;
			while (Vektor.begin()+2*i+j<=Vektor.end()) {
				if (std::equal(Vektor.begin(), Vektor.begin()+i, Vektor.begin()+i+j)) {
					periodican=true; j+=i;
				}
				else {
					periodican=false; break;
				}
			}
			if (periodican) {
				period=i;
				int visakelemenata=Vektor.end()-(Vektor.begin()+i+j);
				if (visakelemenata)
					koliko_puta=(Vektor.size()-visakelemenata)/period + 1;
				else
					koliko_puta=Vektor.size()/period;
				break;
			}
		}
		}
		else {
			auto iterator=Vektor.begin()+i;
			int j(0);
			periodican=true;
			while (iterator!=Vektor.end()) {
				if (*(Vektor.begin()+j)!=*iterator) {
					periodican=false;
					break;
				}
				iterator++; j++;
			}
			if (periodican) {
				period=i;
				int visakelemenata=Vektor.end()-(Vektor.begin()+i);
				if (visakelemenata)
					koliko_puta=(Vektor.size()-visakelemenata)/period + 1;
				else
					koliko_puta=Vektor.size()/period;
				break;
			}
		}
	}
	if (!periodican) {
		period=Vektor.size();
		koliko_puta=2;
	}
	return period;
}
template<typename CijeliTip>
int** AlocirajFragmentirano(const std::vector<CijeliTip> &Vektor, int &koliko_puta) {
	int period=PretvoriUPeriodican(Vektor, koliko_puta);
	if (!period) throw std::string("Prazan vektor!");
	for (auto x : Vektor) {
		if (x<=0) throw std::domain_error("Neispravan vektor!");
	}
	CijeliTip max(0);
	int **Matrica=nullptr;
	Matrica=new int*[period*koliko_puta]();
	for (int i=0;i<period*koliko_puta;i++) {
		if (i<Vektor.size()) {
			Matrica[i]=new int[Vektor.at(i)];
			if (Vektor[i]>max) max=Vektor.at(i);
		}
		else {
			Matrica[i]=new int[Vektor.at(i%period)];
		}
	}
	for (int i=0;i<period*koliko_puta;i++) {
		if (i<Vektor.size()) {
			int razlika=max-Vektor.at(i)+1;
			for (int j=0;j<Vektor.at(i);j++) {
				Matrica[i][j]=razlika;
				razlika++;
			}
		}
		else {
			int razlika=max-Vektor.at(i-period)+1;
			for (int j=0;j<Vektor.at(i%period);j++) {
				Matrica[i][j]=razlika;
				razlika++;
			}
		}
	}
	return Matrica;
}
template<typename CijeliTip>
int** AlocirajKontinualno(const std::vector<CijeliTip> &Vektor, int &koliko_puta) {
	int period=PretvoriUPeriodican(Vektor, koliko_puta);
	if (!period) throw std::string("Prazan vektor!");
	for (auto x : Vektor) {
		if (x<=0) throw std::domain_error("Neispravan vektor!");
	}
	CijeliTip suma(0);
	for (int i=0;i<period;i++) 
		suma+=Vektor.at(i);
	suma=suma*koliko_puta;
	int** Matrica=nullptr;
	Matrica=new int*[period*koliko_puta]();
	Matrica[0]=new int[suma];
	for (int i=1;i<koliko_puta*period;i++) {
		if (i<Vektor.size())
			Matrica[i]=Matrica[i-1]+Vektor.at(i-1);
		else {
			if (i%period!=0)
				Matrica[i]=Matrica[i-1]+Vektor.at(i%period-1);
			else
				Matrica[i]=Matrica[i-1]+Vektor.at(i%period+period-1);
		}
	}
	for (int i=0;i<period*koliko_puta;i++) {
		if (i<Vektor.size()) {
			int razlika=Vektor.at(i);
			for (int j=0;j<Vektor.at(i);j++) {
				Matrica[i][j]=razlika;
				razlika--;
			}
		}
		else {
			int razlika=Vektor.at(i%period);
			for (int j=0;j<Vektor.at(i%period);j++) {
				Matrica[i][j]=razlika;
				razlika--;
			}
		}
	}
	return Matrica;
} 
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int brojel;
	cin>>brojel;
	cout<<"Unesite elemente vektora: ";
	std::vector<int> Vektor;
	Vektor.resize(brojel);
	std::for_each(Vektor.begin(),Vektor.end(), [](int &x) { cin>>x; });
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int alokacija, koliko_puta, period;
	cin>>alokacija;
	int** Matrica=nullptr;
	period=PretvoriUPeriodican(Vektor, koliko_puta);
	try {
		if (alokacija)
			Matrica=AlocirajFragmentirano(Vektor, koliko_puta);
		else
			Matrica=AlocirajKontinualno(Vektor, koliko_puta);
	}
	catch(std::domain_error domen) {
		cout<<"Izuzetak: "<<domen.what();
		return 0;
	}
	catch(std::bad_alloc) {
		if (Matrica) {
			if (alokacija) {
				for (int i=0;i<period*koliko_puta;i++)
					delete[] Matrica[i];
			}
			else
				delete[] Matrica[0];
		}
		delete[] Matrica;
		return 0;
	}
	catch(std::string izuzetak) {
		cout<<"Izuzetak: "<<izuzetak;
		return 0;
	}
	cout<<"Dinamicki alocirana matrica: "<<std::endl;
	for (int i=0;i<period*koliko_puta;i++) {
		if (i<Vektor.size()) {
			for (int j=0;j<Vektor[i];j++) {
				cout<<Matrica[i][j]<<"  ";
			}
		}
		else {
			for (int j=0;j<Vektor[i%period];j++)
				cout<<Matrica[i][j]<<"  ";
		}
		cout<<std::endl;
	}
	if (alokacija) {
		for (int i=0;i<period*koliko_puta;i++)
			delete[] Matrica[i];
		delete[] Matrica;
	}
	else {
		delete[] Matrica[0];
		delete[] Matrica;
	}
	return 0;
	 
}