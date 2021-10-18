/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica m;
	int duzina(v.size()), i(1), podnizovi(0);
	//koristimo while petlju zbog vece fleksibilnosti, koja uvjetuje efikasniji rad funckije
	// i je inicijalizovan na 1
	while(i<duzina){
		std::vector<double> pomocni;
		//if uslov kojim utvrdjujemo da li je ispunjen prvi uslov za rastuci podniz(da je trenutni clan veci od prethodnog)
		if(v[i]>=v[i-1]){
			//while petlja koja sprema rastuce elemente iz zadanog vektora u vektor zvani "pomocni"
			while(i<duzina && v[i]>=v[i-1]){
				pomocni.push_back(v[i-1]);
				i++;
			}
			//sljedeca linija je potrebna zato sto zbog uslova while petlje ona nece spremiti posljednji rastuci element,stoga ga "rucno" spremamo
			pomocni.push_back(v[i-1]);
			//povecavamo broj otkrivenih podnizova, te nakon toga povecavamo i velicinu matrice u koju se oni spremaju
			podnizovi++;
			m.resize(podnizovi);
			int duzina_pomocnog(pomocni.size());
			m[podnizovi-1].resize(duzina_pomocnog);
			//for petlja koja kopira elemente iz vektora "pomocni" u novododani red matrice
			for(int k=0; k<duzina_pomocnog; k++){
				m[podnizovi-1][k]=pomocni[k];
			}
		}
		i++;
	}
	return m;
}
Matrica OpadajuciPodnizovi(std::vector<double> v){
	//princip rada ove funkcije je potpuno identicna prosloj, samo sto se znak ">=" mijenja sa "<=" u skladu sa zahtjevom funkcije
	Matrica m;
	int duzina(v.size()), i(1), podnizovi(0);
	while(i<duzina){
		std::vector<double> pomocni;
		//if uslov kojim utvrdjujemo da li je ispunjen prvi uslov za opadajuci podniz(da je trenutni clan manji od prethodnog)
		if(v[i]<=v[i-1]){
			while(i<duzina && v[i]<=v[i-1]){
				pomocni.push_back(v[i-1]);
				i++;
			}
			//spremanje clana opadajuceg niza u vektor "pomocni", jer to while petlja ne obavlja
			pomocni.push_back(v[i-1]);
			//povecanje broja redova matrice
			podnizovi++;
			m.resize(podnizovi);
			int duzina_pomocnog(pomocni.size());
			m[podnizovi-1].resize(duzina_pomocnog);
			//kopiranje elemenata vektora u matricu
			for(int k=0; k<duzina_pomocnog; k++){
				m[podnizovi-1][k]=pomocni[k];
			}
		}
		i++;
	}
	return m;
}

int main ()
{	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<double>v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
		std::cin>>v[i];
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	Matrica a(RastuciPodnizovi(v));
	for(int i=0; i<a.size(); i++){
		int brojkolona=a[i].size();
		for(int j=0; j<brojkolona; j++){
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica b(OpadajuciPodnizovi(v));
	for(int i=0; i<b.size(); i++){
		int brojkolona=b[i].size();
		for(int j=0; j<brojkolona; j++){
			std::cout<<b[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}