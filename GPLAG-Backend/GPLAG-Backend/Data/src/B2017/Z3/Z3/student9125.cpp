/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElemenata>

struct Matrica {
	int br_redova, br_kolona;
	TipElemenata **elementi = nullptr;  //VEOMA BITNA INCIJALIZACIJA!
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
	if(!mat.elementi) return;
	for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
	delete[] mat.elementi;
	mat.elementi = nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
	Matrica<TipElemenata> mat;
	mat.br_redova = br_redova;
	mat.br_kolona = br_kolona;
	mat.elementi = new TipElemenata*[br_redova];
	for(int i=0; i< br_redova; i++) mat.elementi[i] = nullptr;
	try {
		for(int i=0; i<br_redova; i++)
			mat.elementi[i] = new TipElemenata[br_kolona] {};

	} catch(...) {
		UnistiMatricu(mat);
		throw;
	}
	return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
	for(int i=0; i<mat.br_redova; i++)
		for(int j=0; j<mat.br_kolona; j++) {
			std::cout<<ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
			std::cin>>mat.elementi[i][j];
		}
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool brisanje= false)
{

	for(int i=0; i<mat.br_redova; i++) {
		for(int j=0; j<mat.br_kolona; j++)
			std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
		std::cout<<std::endl;
	}
	if(brisanje) UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
	for(int i=0; i<m1.br_redova; i++)
		for(int j=0; j<m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
	if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
	for(int i=0; i<m1.br_redova; i++)
		for(int j=0; j<m2.br_kolona; j++) {
			for(int k=0; k<m1.br_kolona; k++)
				m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
		}
	return m3;
}

template<typename TipElemenata>
void PomnoziSkalarom(Matrica<TipElemenata> &matr, double pomocna)
{
	for(int i=0; i<matr.br_redova; i++)
		for(int j=0; j<matr.br_kolona; j++)
			matr.elementi[i][j] *= pomocna;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &matr, std::vector<double> vek)
{
	if(matr.br_kolona != matr.br_redova)
		throw std::domain_error("Matrica mora biti kvadratna");
	int x(matr.br_kolona);
	auto I_jed(StvoriMatricu<TipElemenata>(x,x));
	auto nova(StvoriMatricu<TipElemenata>(x,x));
	for(int i=0; i<x; i++)
		for(int j=0; j<x; j++)
			nova.elementi[i][j]=0;
	for(int i=0; i<x; i++)
		for(int j=0; j<x; j++) {
			if(i==j) I_jed.elementi[i][j] = 1;
			else I_jed.elementi[i][j]=0;
		}
	for(int i=0; i<vek.size(); i++) {
		if(i==0) {
			UnistiMatricu(nova);
			nova=I_jed;
			PomnoziSkalarom(nova, vek[0]);
		} else {
			auto pom(StvoriMatricu<TipElemenata>(x,x));
			for(int k=0; k<x; k++)
				for(int j=0; j<x; j++)
					pom.elementi[k][j] = matr.elementi[k][j];
			for(int j=0; j<i-1; j++) {
				auto y(ProduktMatrica(pom,matr));
				UnistiMatricu(pom);
				pom=y;
			}
			PomnoziSkalarom(pom,vek[i]);
			auto z(ZbirMatrica(nova, pom));
			UnistiMatricu(nova);
			UnistiMatricu(pom);
			nova=z;
		}
	}
	return nova;
}

int main()
{
	Matrica<double> a,b;  //AUTOMATSKA INICIJALIZACIJA!!!
	int broj;
	std::cout<<"Unesite dimenziju kvadratne matrice: ";
	std::cin>> broj;
	try {
		a = StvoriMatricu<double>(broj, broj);
		std::cout<<"Unesite elemente matrice A: \n";
		UnesiMatricu('A', a);
		int red_polinoma;
		std::cout<<"Unesite red polinoma: ";
		std::cin>>red_polinoma;
		std::vector<double> v(red_polinoma+1);
		std::cout<<"Unesite koeficijente polinoma: ";
		for(int i=0; i<red_polinoma+1; i++) {
			std::cin>>v[i];
		}
		IspisiMatricu(b = MatricniPolinom(a, v), 10);
	}
	catch(std::bad_alloc) {
		std::cout<<"Nema dovoljno memorije!";
	}
	UnistiMatricu(a);
	UnistiMatricu(b);
	return 0;
}	
