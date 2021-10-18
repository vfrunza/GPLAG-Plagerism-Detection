/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <fstream>

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
	Matrica(char ime_datoteke, bool v);
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);

	void Unesi();
	void Ispisi(int sirina_ispisa) const;
	
	void SacuvajUTekstualnuDatoteku(char ime_datoteke);
	void SacuvajUBinarnuDatoteku(char ime_datoteke);
	
	
	template <typename Tip2>
	friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1,  const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2, typename Tip>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, Tip n);
	template <typename Tip2, typename Tip>
	friend Matrica<Tip2> operator *(Tip n, const Matrica<Tip2> &m1);
	template <typename Tip2>
	friend	std::istream &operator >>(std::istream &tok, Matrica<Tip2> &mat);
	template <typename Tip2>
	friend Matrica<Tip2> &operator +=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> &operator-=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2); 
	TipEl &operator () (int i, int j) const {
		if(i<1 || j<1 || i>br_redova || j>br_kolona) throw std::range_error("Neispravan indeks");
		return elementi[i-1][j-1];
	}
	TipEl *&operator [] (int i) { return elementi[i]; }
	template <typename Tip2>
	friend	std::ostream &operator << (std::ostream &tok, const Matrica<Tip2> &m) ;
	template <typename Tip2>
	friend Matrica<Tip2> &operator *=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2, typename Tip>
	friend Matrica<Tip2> &operator *=(Matrica<Tip2> &m1, Tip n);
};

template <typename TipEl>
Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2){
	if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
		Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
		for(int i=0; i<m3.br_redova; i++)
			for(int j=0; j<m3.br_kolona; j++) m3.elementi[i][j]=0; 
			
			
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m2.br_kolona; j++)
				for(int k=0; k<m1.br_kolona; k++) m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
				m1=m3;
				return m1;
}

template <typename TipEl, typename Tip>
Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, Tip n){
	for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++) m1.elementi[i][j]*=n;
	return m1;
}

template <typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
		Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
		for(int i=0; i<m3.br_redova; i++)
			for(int j=0; j<m3.br_kolona; j++) m3.elementi[i][j]=0; 
			
			
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m2.br_kolona; j++)
				for(int k=0; k<m1.br_kolona; k++) m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
				return m3;
	}

template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
	if(m1.br_redova!=m2.br_redova || m1.br_kolona !=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++) m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
			return m3;
	} 

template <typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++) 
				m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
				return m3;
	}

template <typename TipEl, typename Tip>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1, Tip n){
		Matrica<TipEl> m2(m1.br_redova, m1.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++) m2.elementi[i][j]=m1.elementi[i][j]*n;
			return m2;
	}

template <typename TipEl, typename Tip>
Matrica<TipEl> operator *(Tip n, const Matrica<TipEl> &m1) {
		Matrica<TipEl> m2(m1.br_redova, m1.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++)
				m2.elementi[i][j]=m1.elementi[i][j]*n;
				return m2;
	}

template <typename TipEl>
std::istream &operator >>(std::istream &tok, Matrica<TipEl> &mat) {
		for(int i=0; i<mat.br_redova; i++) 
			for(int j=0; j<mat.br_kolona; j++) { std::cout<<mat.ime_matrice<<"("<<i+1<<","<<j+1<<") = "; std::cin>>mat.elementi[i][j]; }
			return tok;
	}

template <typename TipEl>
Matrica<TipEl> &operator +=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i=0; i<m1.br_redova; i++) 
			for(int j=0; j<m1.br_kolona; j++) m1.elementi[i][j]+=m2.elementi[i][j];
			return m1;
	}

template <typename TipEl>
Matrica<TipEl> &operator-=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
				if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++) m1.elementi[i][j]-=m2.elementi[i][j];
			return m1;
	}

template <typename TipEl>
std::ostream &operator << (std::ostream &tok, const Matrica<TipEl> &m) {
		int sirina=tok.width();
		for(int i=0; i<m.br_redova; i++) {
			for(int j=0; j<m.br_kolona; j++) tok << std::setw(sirina) << m.elementi[i][j]; 
			tok << std::endl; }
			return tok;
	}
	
template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona){
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
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova){
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
	br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi){
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}


template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)){
	KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice){
	m.br_redova = 0;
	m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m){
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
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m){
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}

template <typename TipEl>
void Matrica<TipEl>::Unesi(){
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++) {
			std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			std::cin >> elementi[i][j];
		}
}

template <typename TipEl>
void Matrica<TipEl>::Ispisi(int sirina_ispisa) const{
	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < br_kolona; j++)
			std::cout << std::setw(sirina_ispisa) << elementi[i][j];
		std::cout << std::endl;
	}
}

template <typename TipEl>
Matrica<TipEl> ZbirMatrica(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2){
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(char ime_datoteke){
	std::ofstream datoteka(ime_datoteke);
	if(!datoteka) throw std::logic_error("Problemi sa upisom u datoteku");
	for(int i(0); i<br_redova; i++){
		datoteka<<elementi[i][0];
	   for(int j(1); j<br_kolona; j++){
	   	datoteka<<",";
	   	datoteka<<elementi[i][j];
	   }
	   datoteka<<std::endl;
	}
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(char ime_datoteke){
	std::ofstream datoteka(ime_datoteke, std::ios::out | std::ios::binary);
	if(!datoteka) throw std::logic_error("Problemi sa upisom u datoteku");
	datoteka.seekp(0, std::ios::beg);
	char znak(','), znak1('\n');
	for(int i(0); i<br_redova; i++){
		datoteka.write(reinterpret_cast<char*>(&elementi[i][0]), sizeof elementi[i][0]);
	   for(int j(1); j<br_kolona; j++){
	   	datoteka.write(reinterpret_cast<char*>(&znak), sizeof znak);
	    datoteka.write(reinterpret_cast<char*>(&elementi[i][j]), sizeof elementi[i][j]);
	   }
	    datoteka.write(reinterpret_cast<char*>(&znak1), sizeof znak1);
	}
}

template <typename TipEl>
Matrica<TipEl>::Matrica(char ime_datoteke, bool v){
	if(v){
	std::ifstream datoteka(ime_datoteke, std::ios::binary);
	if(!datoteka.is_open()) throw std::
	char znak(' ');
	int i(0);
	TipEl el;
	datoteka.seekg(0, std::ios::beg);
	while(znak!='\n'){
		datoteka.read(reinterpret_cast<char*>(&el), sizeof(TipEl));
		datoteka.read(reinterpret_cast<char*>(&znak), sizeof(znak));
		i++;
	}
	datoteka.seekg(0, std::ios::end);
	int vel(datoteka.tellg());
	int br_el(vel/sizeof(TipEl));
	int j(br_el/i);
	Matrica m(i, j, 'm');
	datoteka.seekg(0, std::ios::beg);
	
	for(int i1(0); i1<i; i1++){
		for(int j1(0); j1<j; j1++){
			datoteka.read(reinterpret_cast<char*>(&el), sizeof (TipEl));
		    datoteka.read(reinterpret_cast<char*>(&znak), sizeof (znak));
		    m.elementi[i1][j1]=el;
		}
	}
	}
	
	else{
		std::ifstream datoteka;
	    datoteka.open(ime_datoteke);
	    if(!datoteka.is_open()) throw std::logic_error("")
		char znak(' ');
	    int i(0);
	    TipEl el;
	    while (znak!='\n') {
	    	datoteka>>el>>znak;
	    	i++;
	    }
	    datoteka.seekg(0, std::ios::end);
	    int vel(datoteka.tellg());
	    int br_el(vel/sizeof(TipEl));
	    int j(br_el/i);
	    Matrica m(i, j, 'm');
	    for(int i1(0); i1<i; i1++){
	    	for(int j1(0); j1<j; j1++){
	    		if(!datoteka>>el>>znak) throw std::domain_error("");
	    		m.elementi[i1][j1]=el;
	    	}
	    }
	}
}
int main()
{
	return 0;
}
