/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <stdexcept>
#include <new>
#include <fstream>

//Kopirano iz predavanja 14, ali ranije vec receno da se moze korititi
template <typename IspisiviTip>
std::string PretvoriUString(const IspisiviTip &nesto) {
	std::ostringstream tok;
	tok << nesto;
	return tok.str();
}

template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	char ime_matrice;
	TipEl **elementi;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
	void ProvjeriFormat(std::ifstream &tok, int &br_redova, int &br_kolona);
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(std::string filename, bool binary);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() {
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);

	Matrica<TipEl>& operator +() {
		return *this;
	}
	Matrica<TipEl>& operator -() {
		for(int i = 0; i < br_redova; i++)
			for(int j = 0; j < br_kolona; j++)
				elementi[i][j] *= -1;
	}

	Matrica<TipEl>& operator +=(const Matrica<TipEl> &m1);
	Matrica<TipEl>& operator -=(const Matrica<TipEl> &m1);
	Matrica<TipEl>& operator *=(const Matrica<TipEl> &m1);

	TipEl*& operator [](int i);
	TipEl& operator ()(int x, int y);
	TipEl* operator [](int i) const;
	TipEl operator ()(int x, int y) const;
	operator std::string () const;

	template <typename Tip2>
	friend std::istream& operator >>(std::istream& tok, Matrica<Tip2> &m);
	template <typename Tip2>
	friend std::ostream& operator <<(std::ostream& tok, const Matrica<Tip2> &m);
	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator *(Matrica<Tip2> m1, double a);
	template <typename Tip2>
	friend Matrica<Tip2> operator *(double a, Matrica<Tip2> m2);
	template <typename Tip2>
	friend Matrica<Tip2>& operator *=(Matrica<Tip2> &m, double a);
	
	//Data
	void SacuvajUTekstualnuDatoteku(std::string filename);
	void SacuvajUBinarnuDatoteku(std::string filename);
	void ObnoviIzTekstualneDatoteke(std::string filename);
	void ObnoviIzBinarneDatoteke(std::string filename);
};


int main() {
	try {
		Matrica<double> a("a.txt", false);
		std::cout << std::setw(5) << a;
	} catch(std::bad_alloc) {
		std::cout << "Nema dovoljno memorije!\n";
	}

	
	return 0;
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(std::string filename) {
    std::ofstream tok(filename);
    
	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < br_kolona-1; j++)
			tok << elementi[i][j] << ",";
		tok << elementi[i][br_kolona-1] << std::endl;
		if(!tok || tok.bad())
		    throw std::logic_error("Problemi sa upisom u datoteku");
	}
	
	tok.close();
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(std::string filename) {
    std::ofstream tok(filename, std::ios::binary);
    tok.seekp(0);
    
    tok.write(reinterpret_cast<char*>(this), sizeof *this);
    
	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < br_kolona; j++)
			tok.write(reinterpret_cast<char*>(&elementi[i][j]), sizeof(elementi[i][j]));
		if(!tok || tok.bad())
		    throw std::logic_error("Problemi sa upisom u datoteku");
	}
	
	tok.close();
}

template<typename TipEl>
void Matrica<TipEl>::ProvjeriFormat(std::ifstream &tok, int &br_redova, int &br_kolona){
	int red = 0, init_kol = -1, kol = 0;
    TipEl temp;
    
    tok.seekg(0);
    
    char fznak = tok.peek();
	if(fznak < '0' || fznak > '9')
		tok.setstate(std::ios::failbit);
    
    while(tok){
    	
    	kol = 0;
    	while(tok >> temp){
    		//Ucitavaju se elementi, ako je znak nakon citanja ',' ili '\n', sve ok, ako ne failbit
    		char znak = tok.peek();
    		if(znak == ','){
    			tok.get();
    			znak = tok.peek();
    			if(znak < '0' || znak > '9'){
    				tok.setstate(std::ios::failbit);
    				break;
    			}
    		}
    		else if(znak == '\n'){
    			tok.get();
    			znak = tok.peek();
    			if(znak < '0' || znak > '9'){
    				tok.setstate(std::ios::failbit);
    				break;
    			}
    			break;
    		}
    		else{
    			if(znak == EOF)
    				red++;
    			tok.setstate(std::ios::failbit);
    			break;
    		}
    		kol++;
    	}
    	
    	if(init_kol == -1)
    		init_kol = kol;
    	
    	if(kol != init_kol)
    		throw std::logic_error("Datoteka sadrzi besmislene podatke");
    	
    	if(!tok)
    		break;
    	
    	red++;
    }
    
    if(tok.eof())
    	red--;
    
    if(tok.eof()){
        tok.clear();
    }
    else if(tok.bad()){
        throw std::logic_error("Problemi pri citanju datoteke");
    }
    else if(!tok){
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    
    br_redova = red+1;
    br_kolona = init_kol+1;
    tok.seekg(0);
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(std::string filename) {
    std::ifstream tok(filename);
    if(!tok)
    	throw std::logic_error("Trazena datoteka ne postoji");
    
    int red = 0, kol = 0;
    //Pise odmah koliko ima redova i kolona
    ProvjeriFormat(tok, red, kol);
    
    DealocirajMemoriju(elementi, br_redova);
    br_redova = red;
    br_kolona = kol;
    
    elementi = AlocirajMemoriju(br_redova, br_kolona);
    
    for(int i = 0; i < br_redova; i++){
    	
    	for(int j = 0; j < br_kolona; j++){
    		//Vec znam da je ispravan format, samo pokupi znak nakon elementa
    		tok >> elementi[i][j];
    		tok.get();
    	}
    	
    	if(!tok)
    		break;
    }
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(std::string filename) {
    std::ifstream tok(filename);
    if(!tok)
    	throw std::logic_error("Trazena datoteka ne postoji");
    
    DealocirajMemoriju(elementi, br_redova);
    
    tok.read(reinterpret_cast<char*>(this), sizeof(*this));
    
    elementi = AlocirajMemoriju(br_redova, br_kolona);
    
    for(int i = 0; i < br_redova; i++){
    	for(int j = 0; j < br_kolona; j++){
    		tok.read(reinterpret_cast<char*>(&elementi[i][j]), sizeof(elementi[i][j]));
    	}
    	if(!tok)
    		throw std::logic_error("Problemi pri citanju datoteke");
    }
}

template<typename TipEl>
Matrica<TipEl>::Matrica(std::string filename, bool binary) : elementi(nullptr), br_redova(0), br_kolona(0){
	if(binary)
		ObnoviIzBinarneDatoteke(filename);
	else
		ObnoviIzTekstualneDatoteke(filename);
}

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi = nullptr;
	elementi = new TipEl*[br_redova] {};
	try {
		for(int i = 0; i < br_redova; i++) {
			elementi[i] = new TipEl[br_kolona];
		}
	} catch(...) {
		DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for(int i = 0; i < br_redova; i++) {
		delete[] elementi[i];
	}
	delete[] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime)
	: br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime), elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++) {
			Matrica::elementi[i][j] = elementi[i][j];
		}
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m)
	: br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
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
		for(int i = m.br_redova; i < br_redova; i++) {
			delete elementi[i];
		}

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
std::istream& operator >>(std::istream& tok, Matrica<TipEl> &m)
{
	for(int i = 0; i < m.br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++) {
			std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> m.elementi[i][j];
		}

	return tok;
}

template <typename TipEl>
std::ostream& operator <<(std::ostream& tok, const Matrica<TipEl> &m)
{
	int tw = tok.width();
	for(int i = 0; i < m.br_redova; i++) {
		for(int j = 0; j < m.br_kolona; j++)
			tok << std::setw(tw) << m.elementi[i][j];
		tok << std::endl;
	}

	return tok;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator +=(const Matrica<TipEl> &m1)
{
	if(br_redova != m1.br_redova || br_kolona != m1.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");

	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j] += m1.elementi[i][j];

	return *this;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator -=(const Matrica<TipEl> &m1)
{
	if(br_redova != m1.br_redova || br_kolona != m1.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");

	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j] -= m1.elementi[i][j];

	return *this;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator *=(const Matrica<TipEl> &m2)
{
	if(br_kolona != m2.br_redova)
		throw std::domain_error("Matrice nisu saglasne za mnozenje");

	Matrica<TipEl> m3(m2.br_kolona, br_kolona);

	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < m2.br_kolona; j++)
			for(int k = 0; k < br_kolona; k++)
				m3.elementi[i][j] += elementi[i][k] * m2.elementi[k][j];

	return *this = m3;
}

template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	Matrica<TipEl> temp(m1);
	return temp += m2;
}

template <typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	Matrica<TipEl> temp(m1);
	return temp -= m2;
}

template <typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	Matrica<TipEl> temp(m1);
	return temp *= m2;
}

template <typename Tip2>
Matrica<Tip2>& operator *=(Matrica<Tip2> &m, double a)
{
	for(int i = 0; i < m.br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++)
			m.elementi[i][j] *= a;
	
	return m;
}

template <typename Tip2>
Matrica<Tip2> operator *(Matrica<Tip2> m1, double a)
{
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m1.elementi[i][j] *= a;
	
	return m1;
}

template <typename Tip2>
Matrica<Tip2> operator *(double a, Matrica<Tip2> m2)
{
	return m2 * a;
}

template <typename TipEl>
TipEl*& Matrica<TipEl>::operator [](int i)
{
	return elementi[i];
}

template <typename TipEl>
TipEl* Matrica<TipEl>::operator [](int i) const
{
	return elementi[i];
}

template <typename TipEl>
TipEl& Matrica<TipEl>::operator ()(int x, int y)
{
	if(x <= 0 || y <= 0 || x > br_redova || y > br_kolona)
		throw std::range_error("Neispravan indeks");
	return elementi[x-1][y-1];
}

template <typename TipEl>
TipEl Matrica<TipEl>::operator ()(int x, int y) const
{
	if(x <= 0 || y <= 0 || x > br_redova || y > br_kolona)
		throw std::range_error("Neispravan indeks");
	return elementi[x-1][y-1];
}

template <typename TipEl>
Matrica<TipEl>::operator std::string () const{
	std::string toRet = "{";
	for(int i = 0; i < br_redova-1; i++){
		std::string row = "{";
		for(int j = 0; j < br_kolona-1; j++){
			row += PretvoriUString<double>(elementi[i][j]) + ",";
		}
		row += PretvoriUString<double>(elementi[i][br_kolona-1]) + "},";
		toRet += row;
	}
	
	std::string row = "{";
	for(int j = 0; j < br_kolona-1; j++){
		row += PretvoriUString<double>(elementi[br_redova-1][j]) + ",";
	}
	row += PretvoriUString<double>(elementi[br_redova-1][br_kolona-1]) + "}";
	toRet += row + "}";
	
	return toRet;
}