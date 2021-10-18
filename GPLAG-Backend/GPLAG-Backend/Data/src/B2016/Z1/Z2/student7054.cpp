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

typedef std::vector<std::vector<double>> Matrica;

int BrojKolona(Matrica m)
{
	return m[0].size();
}
int BrojRedova(Matrica m)
{
	return m.size();
}


bool daLiJeMatricaGrbava(Matrica M)
{
	for(int i=0; i<BrojRedova(M); i++) {
		if(M[i].size() != M[0].size()) {
			return true;
		}
	}
	return false;
}


std::vector<double> izvrniVektor(std::vector<double> v)
{
	std::vector<double>pomocni;

	for(int i=v.size()-1; i>=0; i--) {
		pomocni.push_back(v[i]);
	}

	return pomocni;
}


Matrica Transponuj(Matrica m)
{
	Matrica t(BrojKolona(m));

	for(int j=0; j<BrojKolona(m); j++) {
		for(int i=0; i<BrojRedova(m); i++) {
			t[j].push_back(m[i][j]);
		}
	}
	return t;
}

Matrica h(Matrica m)
{
	Matrica pomocna;
	for(int i=0; i<BrojRedova(m); i++) {
		pomocna.push_back(izvrniVektor(m[i]));
	}
	return pomocna;
}
Matrica v(Matrica m)
{
	return Transponuj(h(Transponuj(m)));
}

Matrica hv(Matrica m)
{
	return h(v(m));
}
Matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return Matrica(br_redova, std::vector<double>(br_kolona));
}

Matrica OgledaloMatrica(Matrica M)
{
	if(M.size()==0) return M;
	if(daLiJeMatricaGrbava(M)) {
		throw std::domain_error("Matrica nije korektna");
	}
	if(M.empty()) return M;
	if(M[0].empty()) return Matrica(KreirajMatricu(3*M.size(), 3*M[0].size()));
	Matrica OM(3*BrojRedova(M),std::vector<double>(3*BrojKolona(M)) );
	Matrica HV=hv(M);
	Matrica H=h(M);
	Matrica V=v(M);
//RED PRVI
	for(int i=0; i<BrojRedova(M); i++) {
		for(int j=0; j<BrojKolona(M); j++) {
			OM[i][j]=HV[i][j];
		}
	}
	for(int i=0; i<BrojRedova(M); i++) {
		for(int j=BrojKolona(M); j<2*BrojKolona(M); j++) {
			OM[i][j]=V[i][j-BrojKolona(M)];
		}
	}
	for(int i=0; i<BrojRedova(M); i++) {
		for(int j=2*BrojKolona(M); j<3*BrojKolona(M); j++) {
			OM[i][j]=HV[i][j-2*BrojKolona(M)];
		}
	}
//RED DRUGI
	for(int i=BrojRedova(M); i<2*BrojRedova(M); i++) {
		for(int j=0; j<BrojKolona(M); j++) {
			OM[i][j]=H[i-BrojRedova(M)][j];
		}
	}
	for(int i=BrojRedova(M); i<2*BrojRedova(M); i++) {
		for(int j=BrojKolona(M); j<2*BrojKolona(M); j++) {
			OM[i][j]=M[i-BrojRedova(M)][j-BrojKolona(M)];
		}
	}
	for(int i=BrojRedova(M); i<2*BrojRedova(M); i++) {
		for(int j=2*BrojKolona(M); j<3*BrojKolona(M); j++) {
			OM[i][j]=H[i-BrojRedova(M)][j-2*BrojKolona(M)];
		}
	}
//RED TRECI
	for(int i=2*BrojRedova(M); i<3*BrojRedova(M); i++) {
		for(int j=0; j<BrojKolona(M); j++) {
			OM[i][j]=HV[i-2*BrojRedova(M)][j];
		}
	}
	for(int i=2*BrojRedova(M); i<3*BrojRedova(M); i++) {
		for(int j=BrojKolona(M); j<2*BrojKolona(M); j++) {
			OM[i][j]=V[i-2*BrojRedova(M)][j-BrojKolona(M)];
		}
	}
	for(int i=2*BrojRedova(M); i<3*BrojRedova(M); i++) {
		for(int j=2*BrojKolona(M); j<3*BrojKolona(M); j++) {
			OM[i][j]=HV[i-2*BrojRedova(M)][j-2*BrojKolona(M)];
		}
	}


	return OM;
}



void IspisiMatricu(Matrica m)
{
	for(int i = 0; i < BrojRedova(m); i++) {
		for(int j = 0; j < BrojKolona(m); j++)
			std::cout << std::setw(4) << m[i][j];
		std::cout << std::endl;
	}
}

Matrica UnesiMatricu(int br_redova, int br_kolona)
{
	auto m(KreirajMatricu(br_redova, br_kolona));
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++) {
			std::cin >> m[i][j];
		}
	return m;
}

int main ()
{
	int m, n;
	try {
	std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
      
		std::cout<<"Unesite elemente matrice:"<<std::endl;
		Matrica M=UnesiMatricu(m,n);
		Matrica H = OgledaloMatrica(M);
		std::cout<<"Rezultantna matrica:"<<std::endl;
		 if(m==0 || n==0) return 0;
		IspisiMatricu(H);
	} catch(std::domain_error e) {
		std::cout<<e.what()<<std::endl;
	}

	return 0;
}