/*B 2017/2018, Zadaća 1, Zadatak 2*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica;
using std::cout;
using std::cin;
using std::endl;


double SumaKoncentricnogKvadrata(Matrica m){ //format matrice je obavezno NxN
	double suma(0);
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m.size(); j++)
			if(i==0 || j==0 || i==m.size() || j==m.size()) suma += m.at(i).at(j);
	}
	return suma;
}

Matrica NadjiNajveci(Matrica m){//za koju se pretp da je jedna od dim = 2 ili dim = 1, i obje pozitivne
	double max(m.at(0).at(0));
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m.at(i).size(); j++){
			if(m.at(i).at(j) > max) max = m.at(i).at(j);
		}
	}
	return Matrica(1, Vektor(1, max));
}

bool GrBaVa(Matrica m) {
	for(int i=1; i<m.size(); i++){
		if(m.at(0).size() != m.at(i).size()) return true;
	}
	return false;
}

int ManjiIndeks(int i, int j){
	if(i<j) return i;
	return j;
}

Matrica DajPotencijalnu(int min, int i, int j, const Matrica &m){ //min daje moguce sirenje
	Matrica pl_potencijalna(min*2 + 1);
	for(int k=min, k2=0; k>=-min; k--, k2++){
		for(int l=min; l>=-min; l--){
			double x(m.at(i-k).at(j-l));
			pl_potencijalna.at(k2).push_back(x);
		}
	}
	return pl_potencijalna;
}

Matrica NajvecaPlaninaMatrice(Matrica m){
	if(GrBaVa(m)) throw std::domain_error("Matrica nije korektna");
												
	if(m.size() == 0 || m.at(0).size() == 0) return Matrica();
	int visina(m.size()), sirina(m.at(0).size());
	if(visina == 1 || sirina == 1 || visina == 2 || sirina == 2) return NadjiNajveci(m);
	
	Matrica planina; 			
	for(int i=0; i<visina; i++){
		for(int j=0; j<sirina; j++){
			//traženje vrha
			if(i==0 || i==visina-1 || j==0 || j==sirina-1) continue;
			double vrh_potencijalni(m.at(i).at(j));
			
			int min(1);
			//startna potencijalna matrica
			Matrica pl_potencijalna(DajPotencijalnu(min, i, j, m)); //ako je prog došao do ove linije koda
														//znači da su dimenzije garantirano minimalno = 3 tj po 1 proširenje
			int dim_planine(planina.size()); //obe su sigurno sad dimenzije 3 ili više
			if((pl_potencijalna.size() == dim_planine && vrh_potencijalni > planina.at(planina.size()/2).at(planina.size()/2)) || (planina.size() < pl_potencijalna.size()))
				planina = pl_potencijalna;
			
			int prosirenje(ManjiIndeks(ManjiIndeks(i, j), ManjiIndeks(visina-1-i, sirina-1-j)));
			int tmp(0);
			if(prosirenje > 1) tmp=1;
			while(tmp>0){
				double suma1(SumaKoncentricnogKvadrata(pl_potencijalna));
				pl_potencijalna = DajPotencijalnu(min+tmp, i, j, m);
				double suma2(SumaKoncentricnogKvadrata(pl_potencijalna));
				if(suma2 < suma1) planina=pl_potencijalna;
				tmp++;
				if(prosirenje-tmp == 0) break;
			}
			
			
			
		}
	}
	
	
	return planina;
}

int main (){
	cout << "Unesite dimenzije matrice (m i n): ";
	int r(0), k(0); //redovi, kolone
	cin >> r >> k;
	if(r < 0 || k < 0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica m(r);
	cout << "Unesite elemente matrice:";
	for(int i=0; i<r; i++){
		for(int j=0; j<k; j++){
			double x;
			cin >> x;
			m.at(i).push_back(x);
		}
	}

	cout << endl << "Najveca planina unesene matrice je:" << endl;
	try{
		m = NajvecaPlaninaMatrice(m);
	}
	catch(std::domain_error IZUZETAK){
		cout << "Izuzetak: " << IZUZETAK.what() << endl;
	}
	
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m.at(i).size(); j++){
			cout << std::setw(6) << m.at(i).at(j);
		}
		cout << endl;
	}
	
	
	return 0;
}