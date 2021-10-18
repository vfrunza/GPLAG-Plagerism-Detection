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

std::vector<std::vector<double>> KreirajMatricu(int br_redova,int br_kolona)
{
	if(br_redova<0 || br_kolona<0)throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	return std::vector<std::vector<double>>(br_redova,std::vector<double>(br_kolona));
}
std::vector<std::vector<double>> UnesiMatricu(int br_redova,int br_kolona)
{
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++) {
			std::cin>>m[i][j];
		}
	}
	return m;
}
int BrojRedova(std::vector<std::vector<double>> m)
{
	return m.size();
}
int BrojKolona(std::vector<std::vector<double>> m)
{
	return m[0].size();
}
void IspisiMatricu(std::vector<std::vector<double>> m)
{
	for(int i=0; i<BrojRedova(m); i++) {
		for(int j=0; j<BrojKolona(m); j++) {
			std::cout<<std::setw(4)<<m[i][j];
		}
		std::cout<<std::endl;
	}
}
std::vector<std::vector<double>> HorizontalnoOgledalo(std::vector<std::vector<double>> m)
{
	std::vector<std::vector<double>> m1;
	std::vector<double>v1;
	for(int i=0; i<BrojRedova(m); i++) {
		for(int j=BrojKolona(m)-1; j>=0; j--) {
			v1.push_back(m[i][j]);
		}
		m1.push_back(v1);
		v1.clear();

	}
	return m1;
}
std::vector<std::vector<double>> VertikalnoOgledalo(std::vector<std::vector<double>>m)
{
	std::vector<std::vector<double>> m1;
	std::vector<double> v1;
	for(int i=BrojRedova(m)-1; i>=0; i--) {
		for(int j=0; j<BrojKolona(m); j++) {
			v1.push_back(m[i][j]);
		}
		m1.push_back(v1);
		v1.clear();
	}
	return m1;
}
std::vector<std::vector<double>> KombinovanoOgledalo(std::vector<std::vector<double>> m)
{
	std::vector<std::vector<double>> m1;
	std::vector<double> v1;
	for(int i=BrojRedova(m)-1; i>=0; i--) {
		for(int j=BrojKolona(m)-1; j>=0; j--) {
			v1.push_back(m[i][j]);
		}
		m1.push_back(v1);
		v1.clear();
	}
	return m1;
}
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> m)
{
	std::vector<std::vector<double>> ogl;
	std::vector<std::vector<double>> m1;
	m1=KombinovanoOgledalo(m);
	std::vector<std::vector<double>> m2;
	m2=VertikalnoOgledalo(m);
	std::vector<std::vector<double>> m3;
	m3=HorizontalnoOgledalo(m);
	std::vector<double> v1;
	for(int i=0; i<BrojRedova(m); i++) {
		for(int j=0; j<BrojKolona(m); j++) {
			v1.push_back(m1[i][j]);
		}
		for(int k=0; k<BrojKolona(m); k++) {
			v1.push_back(m2[i][k]);
		}
		for(int p=0; p<BrojKolona(m); p++) {
			v1.push_back(m1[i][p]);
		}
		ogl.push_back(v1);
		v1.clear();
	}
	for(int i=0; i<BrojRedova(m); i++) {
		for(int z=0; z<BrojKolona(m); z++) {
			v1.push_back(m3[i][z]);
		}
		for(int l=0; l<BrojKolona(m); l++) {
			v1.push_back(m[i][l]);
		}
		for(int f=0; f<BrojKolona(m); f++) {
			v1.push_back(m3[i][f]);
		}
		ogl.push_back(v1);
		v1.clear();
	}
	for(int i=0; i<BrojRedova(m); i++) {
		for(int d=0; d<BrojKolona(m); d++) {
			v1.push_back(m1[i][d]);
		}
		for(int s=0; s<BrojKolona(m); s++) {
			v1.push_back(m2[i][s]);
		}
		for(int v=0; v<BrojKolona(m); v++) {
			v1.push_back(m1[i][v]);
		}
		ogl.push_back(v1);
		v1.clear();
	}

	return ogl;
}
int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	try {
		std::vector<std::vector<double>> M1;
		M1=KreirajMatricu(m,n);
		std::cout<<"Unesite elemente matrice:\n";
		auto M(UnesiMatricu(m,n));
		std::cout<<"Rezultantna matrica:\n";
		auto M4(OgledaloMatrica(M));
		IspisiMatricu(M4);
	} catch(std::domain_error IZUZETAK) {
		std::cout<<IZUZETAK.what();
	}

	return 0;
}