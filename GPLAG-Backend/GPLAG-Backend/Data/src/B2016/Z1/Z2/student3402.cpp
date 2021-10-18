/*B 2016/2017, Zadaća 1, Zadatak 2
	
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

using namespace std;
typedef vector<vector<double>> Vektor_vektora;

Vektor_vektora VertikalnaMatrica(Vektor_vektora matrica){
	Vektor_vektora okrenuta = matrica;
	int k(0);

	for(int i(0); i < matrica[0].size(); i++){
		for(int j(matrica.size()-1); j >= 0; j--){
			okrenuta[k++][i] = matrica[j][i];
		}
		k = 0;
	}
	
	return okrenuta;
}

Vektor_vektora HorizontalnaMatrica(Vektor_vektora matrica){
	Vektor_vektora okrenuta = matrica;
	int k(0);
	for(int i(0); i < matrica.size(); i++){
		for(int j = matrica[0].size() - 1; j >= 0; j--){
			okrenuta[i][k++] = matrica[i][j];
		}
		k = 0;
	}
	
	return okrenuta;
}

bool Testiraj(Vektor_vektora matrica){
	for(int i(0); i < matrica.size(); i++){
		if(matrica[i].size() != matrica[0].size())
			return false;
	}
	
	return true;
}

Vektor_vektora risajz(Vektor_vektora matrica){
	matrica.resize(3*matrica.size());
	int k = matrica.size() - 1;
	for(int i(0); i < matrica.size(); i++){
		matrica[k--].resize(3*matrica[0].size());
	}
	
	return matrica;
}

Vektor_vektora PopuniHV(Vektor_vektora ogledalo, int redovi_pocetak, int redovi_kraj, int kolone_pocetak, int kolone_kraj, Vektor_vektora hv){
	int k(0), l(0);
	for(int i(redovi_pocetak); i < redovi_kraj; i++){
		for(int j(kolone_pocetak); j < kolone_kraj; j++){
			ogledalo[i][j] = hv[k][l++];
		}
		l = 0;
		k++;
	}
	
	return ogledalo;
}

Vektor_vektora OgledaloMatrica(Vektor_vektora matrica){
	if(!Testiraj(matrica)){
		throw domain_error("Matrica nije korektna");
	}
	
	if(matrica.size() == 0){
		return matrica;
	}
	else if(matrica[0].size() == 0){
		matrica.resize(3*matrica.size());
		return matrica;
	}
	
	Vektor_vektora horizontalna = HorizontalnaMatrica(matrica);
	Vektor_vektora vertikalna = VertikalnaMatrica(matrica);
	Vektor_vektora hv = HorizontalnaMatrica(VertikalnaMatrica(matrica));
	Vektor_vektora ogledalo = risajz(matrica);
	
	ogledalo = PopuniHV(ogledalo, 0, matrica.size(), 0, matrica[0].size(), hv);
	ogledalo = PopuniHV(ogledalo, 2*matrica.size(), 3*matrica.size(), 0, matrica[0].size(), hv);
	ogledalo = PopuniHV(ogledalo, 0, matrica.size(), 2*matrica[0].size(), 3*matrica[0].size(), hv);
	ogledalo = PopuniHV(ogledalo, 2*matrica.size(), 3*matrica.size(), 2*matrica[0].size(), 3*matrica[0].size(), hv);
	
	ogledalo = PopuniHV(ogledalo, 0, matrica.size(), matrica[0].size(), 2*matrica[0].size(), vertikalna);
	ogledalo = PopuniHV(ogledalo, 2*matrica.size(), 3*matrica.size(), matrica[0].size(), 2*matrica[0].size(), vertikalna);
	
	ogledalo = PopuniHV(ogledalo, matrica.size(), 2*matrica.size(), 0, matrica[0].size(), horizontalna);
	ogledalo = PopuniHV(ogledalo, matrica.size(), 2*matrica.size(), 2*matrica[0].size(), 3*matrica[0].size(), horizontalna);
	
	ogledalo = PopuniHV(ogledalo, matrica.size(), 2*matrica.size(), matrica[0].size(), 2*matrica[0].size(), matrica);
	
	return ogledalo;
}

bool TestirajRedoveIKolone(int redovi, int kolone){
	if(redovi == 0 || kolone == 0)
		return false;
	return true;
}

Vektor_vektora KreirajMatricu(int redovi, int kolone){
	return Vektor_vektora(redovi, vector<double>(kolone));
}

int main ()
{
	cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	cin >> m >> n;
	if(m < 0 || n < 0){
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
		
	Vektor_vektora matrica(KreirajMatricu(m, n));
	cout << "Unesite elemente matrice:" << endl;
	
	if(m == 0 && n == 0){
		cout << "Rezultantna matrica: ";
		return 0;
	}
	
	for(int i(0); i < m; i++){
		for(int j(0); j < n; j++){
			cin >> matrica[i][j];
		}
	}
	
	try{
		Vektor_vektora vracena = OgledaloMatrica(matrica);

		cout << "Rezultantna matrica: " << endl;
		
		for(int i(0); i < vracena.size(); i++){
			for(int j(0); j < vracena[i].size(); j++){
				if(i == vracena.size() - 1 && j == vracena[0].size()-1)
					cout << setw(4) << vracena[i][j];
				else if(j == vracena[0].size() - 1)
					cout << setw(4) << vracena[i][j];
				else if(j == 0)
					cout << setw(4) << vracena[i][j];
				else
					cout << setw(4) << vracena[i][j];
			}
			cout << endl;
		}
	}
	catch(domain_error err) {
		cout << err.what();
	}
	
	return 0;
}