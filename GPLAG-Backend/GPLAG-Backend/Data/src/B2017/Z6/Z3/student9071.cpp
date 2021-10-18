/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
using namespace std; //znam da sam papak, ali previse je previse :D +

//Da pojasnim, copy paste se desio zbog cinjenice sto danas, na dan 30/05/2018 smo imali 
//velike probleme sa C9 IDE, izbacivao je ljude, brisao kod, cekalo se po 10 minuta itd.
//smatram da zbog software-skih problema je bilo opravdano.
template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() {
		DealocirajMemoriju(elementi, br_redova);
	}

	friend istream &operator >>(istream &tok,  Matrica<TipEl> &m) {
		char space;
		for(int i {0}; i<m.br_redova; i++) {
			for(int j {0}; j<m.br_kolona; j++) {
				cout << m.ime_matrice << "(" << i +1<< "," <<j+1<<") = " ;
				tok >> m.elementi[i][j];
			}
		}
		return tok;
	}

	friend ostream &operator <<(ostream &tok, const Matrica<TipEl> &m) {
		int ispis_duzina {(int)tok.width()};
		for(int i {0}; i<m.br_redova; i++) {
			for(int j {0}; j<m.br_kolona; j++) {
				tok << setw(ispis_duzina)<< m.elementi[i][j];
			}
			tok << endl;
		}

		return tok;
	}

	friend Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		return ZbirMatrica(m1,m2);
	}

	friend Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		Matrica<TipEl> pomocna = m2;
		for(int i {0}; i<pomocna.br_redova; i++)
			for(int j {0}; j<pomocna.br_kolona; j++)
				pomocna.elementi[i][j] = -pomocna.elementi[i][j];
		return ZbirMatrica(m1, pomocna);
	}
	friend Matrica<TipEl> &operator +=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		m1 = m1 + m2;
		return m1;
	}
	friend Matrica<TipEl> &operator -=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		return m1 = m1-m2;
	}
	friend Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if(m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
		TipEl umnozak {};
		Matrica<TipEl> pomocna(m1.br_redova, m2.br_kolona);
		for (int i {0}; i<pomocna.br_redova; i++) {
			for(int j {0}; j<pomocna.br_kolona; j++) {
				umnozak=0;
				for(int k {0}; k<m1.br_kolona; k++) {
					umnozak += m1.elementi[i][k]*m2.elementi[k][j];
				}
				pomocna.elementi[i][j] = umnozak;

			}
		}
		return pomocna;
	}
	friend Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		return m1 = m1*m2;
	}
	friend Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, int x) {
		return m1 = m1*x;
	}
	friend Matrica<TipEl> operator *(int x, const Matrica<TipEl> &m2) {
		Matrica<TipEl> pomocna(m2.br_redova, m2.br_kolona);
		for(int i {0}; i<pomocna.br_redova; i++)
			for(int j {0}; j<pomocna.br_kolona; j++)
				pomocna.elementi[i][j]=x*m2.elementi[i][j];
		return pomocna;
	}
	friend Matrica<TipEl> operator *(const Matrica<TipEl> &m2, int x) {
		Matrica<TipEl> pomocna(m2.br_redova, m2.br_kolona);
		for(int i {0}; i<pomocna.br_redova; i++)
			for(int j {0}; j<pomocna.br_kolona; j++)
				pomocna.elementi[i][j]=x*m2.elementi[i][j];
		return pomocna;
	}
	TipEl* &operator [](int x) {
		return elementi[x];
	}
	TipEl &operator [](TipEl *x) {
		return (*elementi)[x];
	}
	TipEl* &operator [](int x)const {
		return elementi[x];
	}
	TipEl &operator [](TipEl *x)const {
		return (*elementi)[x];
	}
	TipEl &operator ()(int x, int y) {
		if(x>sizeof(elementi) || x<1 || y<1 || y>sizeof(*elementi)) throw range_error("Neispravan indeks");
		return elementi[x-1][y-1];
	}
	TipEl  &operator ()(int x, int y) const {
		if(x>sizeof(elementi) || x<1 || y<1 || y>sizeof(*elementi)) throw range_error("Neispravan indeks");
		return elementi[x-1][y-1];
	}

	operator string()const {
		string pomocni;
		pomocni += "{";
		for(int i {0}; i<br_redova; i++) {
			string pomocni_2 = "{";
			for(int j {0}; j<br_kolona; j++) {
				pomocni_2 += to_string((int)elementi[i][j]);
				if(j+1<br_kolona) pomocni_2+= ",";
			}

			pomocni_2 += "}";
			pomocni+=pomocni_2;
			if(i+1<br_redova) pomocni+=",";
		}
		pomocni+="}";
		return pomocni;
	}

	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	void Unesi();
	void Ispisi(int sirina_ispisa) const;
	template <typename Tip2>
	friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1,
	                                 const Matrica<Tip2> &m2);
};
template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi(new TipEl*[br_redova] {});
	try {
		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
	} catch(...) {
		DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
	br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
	m.br_redova = 0;
	m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
	if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
		TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	} else if(br_redova > m.br_redova)
		for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}
template <typename TipEl>
void Matrica<TipEl>::Unesi()
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++) {
			std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			std::cin >> elementi[i][j];
		}
}
template <typename TipEl>
void Matrica<TipEl>::Ispisi(int sirina_ispisa) const
{
	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < br_kolona; j++)
			std::cout << std::setw(sirina_ispisa) << elementi[i][j];
		std::cout << std::endl;
	}
}
template <typename TipEl>
Matrica<TipEl> ZbirMatrica(const Matrica<TipEl> &m1,
                           const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}
int main()
{
	int m, n;
	std::cout << "Unesi broj redova i kolona za matrice:\n";
	std::cin >> m >> n;
	try {
		Matrica<double> a(m, n, 'A'), b(m, n, 'B');
		std::cout << "Unesi matricu A:\n";
		a.Unesi();
		std::cout << "Unesi matricu B:\n";
		b.Unesi();
		std::cout << "Zbir ove dvije matrice je:\n";
		ZbirMatrica(a, b).Ispisi(7);
	} catch(std::bad_alloc) {
		std::cout << "Nema dovoljno memorije!\n";
	}
	return 0;
}