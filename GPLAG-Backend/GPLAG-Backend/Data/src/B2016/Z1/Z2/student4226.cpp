/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> matrica;

matrica KreirajMatricu(int br_redova, int br_kolona){
	return matrica(br_redova, std::vector<double>(br_kolona));
}

std::vector<double> Prevrni(std::vector<double> niz){
	double temp, kraj(niz.size()-1), pocetak(0);
	while(pocetak<kraj){
		temp=niz[pocetak];
		niz[pocetak]=niz[kraj];
		niz[kraj]=temp;
		pocetak++;
		kraj--;
	}
	return niz;
}

matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova, br_kolona));
	for(int i(0); i<br_redova; i++){
		for(int j(0); j<br_kolona; j++){
			std::cin >> m[i][j];
		}
	}
	return m;
}

matrica horizontalno(matrica a){
	auto b(KreirajMatricu(a.size(), a[0].size()));
	for(int i(0); i<a.size(); i++)
		b[i] = Prevrni(a[i]);
	return b;
}

matrica vertikalno(matrica a){
	auto b(KreirajMatricu(a.size(), a[0].size()));
	for(int i(a.size()-1); i>=0; i--)
		for(int j(0); j<a[0].size(); j++)
			b[a.size()-1-i][j] = a[i][j];
	return b;
}

matrica kombinovano(matrica a){
	auto b = KreirajMatricu(a.size(), a[0].size());
	b = (horizontalno(a));
	auto c = KreirajMatricu(a.size(), a[0].size());
	c=vertikalno(b);
	return c;
}

matrica OgledaloMatrica(matrica pocetna){
	if(pocetna.empty()){
		return pocetna;
	}
	if(pocetna[0].empty()) {
		auto ogledalce(KreirajMatricu(3*pocetna.size(), 3*pocetna[0].size()));
		return ogledalce;
	}
	
	int br_redova = pocetna.size();
	int br_kolona = pocetna[0].size();
	for(int i(1); i<br_redova; i++)
		if(pocetna[0].size()!=pocetna[i].size()) throw std::domain_error("Matrica nije korektna");
	matrica V = vertikalno(pocetna);
	matrica H = horizontalno(pocetna);
	matrica K = kombinovano(pocetna);
	auto ogledalo(KreirajMatricu(3*br_redova, 3*br_kolona));
	//std::cout << ogledalo.size();
	//std::fill(ogledalo.begin(), ogledalo.end(), 0);
	for(int i(0); i<ogledalo.size(); i++){
		for(int j(0); j<ogledalo[0].size(); j++){
			if((i<br_redova || i>=2*br_redova) && (j<br_kolona || j>=2*br_kolona)) ogledalo[i][j] = K[i%br_redova][j%br_kolona];
			else if(i>=br_redova && i<2*br_redova && (j<br_kolona || j>=2*br_kolona)) ogledalo[i][j] = H[i%br_redova][j%br_kolona];
			else if((i<br_redova || i>=2*br_redova) && j>=br_kolona && j<2*br_kolona) ogledalo[i][j] = V[i%br_redova][j%br_kolona];
			else ogledalo[i][j] = pocetna[i%br_redova][j%br_kolona];
			continue;
		}
	}
	return ogledalo;
}

int main ()
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	auto keanu(UnesiMatricu(m, n));
	try{
		auto neo = OgledaloMatrica(keanu);
		std::cout << std::endl << "Rezultantna matrica: " << std::endl;
		if(neo.size()==0 || neo[0].size()==0) return 0;
		for(int i(0); i<3*m; i++){
			for(int j(0); j<3*n; j++)
				std::cout << std::setw(4) << neo[i][j];
			std::cout << std::endl;
		}
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what();
	}
	return 0;
}