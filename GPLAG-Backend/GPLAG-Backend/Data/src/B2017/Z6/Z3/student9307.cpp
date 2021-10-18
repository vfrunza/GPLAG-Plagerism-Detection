// kopirao sam kod iz zadatka 6, tut 12 ovdje jer je dugacak za prepisivanje
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>
#include <vector>

template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	char ime_matrice;
	TipEl **elementi;
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
	
	Matrica &operator =(const Matrica &m);
	
	Matrica &operator =(Matrica &&m);
	
	TipEl* &operator [] (int indeks1) {
		if (indeks1>br_redova) throw std::range_error ("Neispravan indeks");
		return elementi[indeks1];
	}

	TipEl* operator [] (int indeks1) const{
		if (indeks1>br_redova) throw std::range_error ("Neispravan indeks");
		return elementi[indeks1];
	}

	TipEl& operator () (int indeks1,int indeks2) const {
		if (indeks1>br_redova || indeks2>br_kolona || indeks1<=0 || indeks2<=0) throw std::range_error ("Neispravan indeks");
		return elementi[indeks1-1][indeks2-1];
	}
	
	operator std::string () const;
	// PIŠEM KAO PRIJATELJESKE FUNKCIJE JER NEMAM METODA SA KOJIMA PRISTUPAM ELELEMENTIMA
	template<typename Tip>
	friend std::ostream& operator << (std::ostream& tok, Matrica<Tip> &m);
	
	template<typename Tip>
	friend std::istream& operator >> (std::istream& tok,  Matrica<Tip> &m);
	
	template<typename Tip, typename Tip_neki>
	friend Matrica<Tip> operator *= (Matrica<Tip> &m, Tip_neki n);
	
	template<typename Tip, typename Tip_neki>
	friend Matrica<Tip> operator * (Matrica<Tip> m, Tip_neki n);
	
	template <typename Tip, typename Tip_neki>
	friend Matrica<Tip> operator * (Tip_neki n, Matrica<Tip> m);
	
	template<typename Tip>
	friend Matrica<Tip> operator *= (Matrica<Tip> &m1,const Matrica <Tip> &m2);
	
	template<typename Tip>
	friend Matrica<Tip> operator * (const Matrica<Tip> &m1, const Matrica <Tip> &m2);
	
	template <typename Tip>
	friend Matrica<Tip> operator -= (Matrica<Tip> &m1, const Matrica<Tip> &m2);
	
	template <typename Tip>
	friend Matrica<Tip> operator += (Matrica<Tip> &m1, const Matrica<Tip> &m2);
	
	template <typename Tip>
	friend Matrica<Tip> operator + (const Matrica <Tip> &m1, const Matrica<Tip> &m2);

	template <typename Tip>
	friend Matrica<Tip> operator - (const Matrica<Tip> &m1, const Matrica<Tip> &m2);
	

	void SacuvajUTekstualnuDatoteku (std::string ime_dat);
	
	void SacuvajUBinarnuDatoteku (std::string ime_dat);
	
	void ObnoviIzTekstualneDatoteke (std::string ime_dat);
	
	void ObnoviIzBinarneDatoteke (std::string ime_dat);
	
	Matrica (std::string ime_dat, bool dat) : br_redova(0), br_kolona(0), ime_matrice('A'),
	elementi(AlocirajMemoriju(0, 0)) {
		if (dat) {
			std::ifstream tok(ime_dat, std::ios::binary);
		if (!tok) { this->DealocirajMemoriju(elementi,br_redova); throw std::logic_error ("Trazena datoteka ne postoji"); }
		this->ObnoviIzBinarneDatoteke(ime_dat);
			
		}
		else {
			std::ifstream tok(ime_dat);

		if (!tok) { this->DealocirajMemoriju(elementi, br_redova); throw std::logic_error ("Trazena datoteka ne postoji"); }
		this->ObnoviIzTekstualneDatoteke(ime_dat);
	}
	
	}
	
};

template <typename Tip>
void Matrica<Tip>::SacuvajUTekstualnuDatoteku (std::string ime_dat){
	std::ofstream tok;
	tok.open(ime_dat,std::ios::app);
	for (int i = 0; i<br_redova; i++){
		for (int j = 0; j<br_kolona; j++){
			tok<<elementi[i][j];
			if (j<(br_kolona-1)) tok<<",";
		}
		tok<<std::endl;
	}
	if (!tok) throw std::logic_error ("Problemi sa upisom u datoteku");
	tok.close();
}

template <typename Tip>
void Matrica<Tip>::SacuvajUBinarnuDatoteku (std::string ime_dat){
	std::ofstream tok;
	tok.open(ime_dat, std::ios::app);
	for (int i = 0; i<br_redova; i++){
		for (int j = 0; j<br_kolona; j++){
			char zarez(',');
			tok.write(reinterpret_cast<char*>(&elementi[i][j]), sizeof (elementi[i][j]));
			if (j<(br_kolona-1)) tok.write(reinterpret_cast<char*>(&zarez), sizeof (zarez));
		}
		char novi_red('\n');
		tok.write(reinterpret_cast<char*>(&novi_red), sizeof (novi_red));
	}
	if (!tok) throw std::logic_error ("Problemi sa upisom u datoteku");
	tok.close();
}

template <typename Tip>
void Matrica<Tip>::ObnoviIzTekstualneDatoteke (std::string ime_dat){
	std::ifstream tok(ime_dat);
	if (!tok) throw std::logic_error ("Trazena datoteka ne postoji");
	int redovi(0),kolone(1);
	Tip element;
	char znak;
    while (tok){
    	tok>>element>>znak;
    	if (!tok) throw std::logic_error ("Datoteka sadrzi besmislene podatke");
    	if (znak!=',') break;
    	kolone++;
    }
    tok.close();
    std::ifstream tok2(ime_dat);
    std::string red;
    while (1){
    	std::getline(tok2, red);
    	if (!tok2) break;
    	redovi++;
    }
    tok2.close();
    std::ifstream tok3(ime_dat);
    Matrica<Tip> m(redovi,kolone,ime_matrice);
    for (int i = 0; i<redovi; i++){
    	for (int j = 0; j<kolone; j++){
    		tok3>>m.elementi[i][j];
    		if (j<kolone-1) tok3>>znak;
    		if (!tok3 || znak!=',') {/* m.DealocirajMemoriju (m.elementi, redovi);
    		this->DealocirajMemoriju(elementi, br_redova);*/
    		throw std::logic_error ("Datoteka sadrzi besmislene podatke");}
    	}
    }
    *this=m;
    tok3.close();
}

template <typename Tip>
void Matrica<Tip>::ObnoviIzBinarneDatoteke (std::string ime_dat){
	std::ifstream tok(ime_dat, std::ios::binary);
	if (!tok) throw std::logic_error ("Trazena datoteka ne postoji");
	int redovi(0), kolone(1);
	Tip element;
	char znak;
	while (1){
		tok.read(reinterpret_cast<char*>(&element), sizeof(element));
		tok.read(reinterpret_cast<char*>(&znak), sizeof (znak));
		if (znak!=',') break;
		kolone++;
	}
	tok.seekg(0);
	std::string red;
	while (1){
		std::getline (tok, red);
		if (!tok) break;
		redovi++;
	}
	tok.close();
	std::ifstream tok2(ime_dat, std::ios::binary);
	Matrica<Tip> m(redovi,kolone,ime_matrice);
	
	for (int i = 0; i<redovi; i++){
		for (int j = 0; j<kolone; j++){
			tok2.read(reinterpret_cast<char*>(&m.elementi[i][j]), sizeof (Tip));
			tok2.read(reinterpret_cast<char*>(&znak), sizeof (znak));
			if (!tok2) {/* m.DealocirajMemoriju(m.elementi, redovi);
			this->DealocirajMemoriju(elementi, br_redova);*/
			throw std::logic_error ("Datoteka sadrzi besmislene podatke");
			}
		}
	}
	*this=m;
}



template <typename Tip, typename Tip_neki>
Matrica<Tip> operator * (Tip_neki n, Matrica<Tip> m){
	for (int i = 0; i<m.br_redova; i++)
	for (int j = 0; j<m.br_kolona; j++)
	m.elementi[i][j]=n*m.elementi[i][j];
	return m;
}


template <typename Tip>
Matrica<Tip>::operator std::string () const
{
	std::string s;
	s.push_back('{');
	for (int i = 0; i<br_redova; i++){
		s.push_back('{');
		for (int j = 0; j<br_kolona; j++){
		
	
			s+=std::to_string(int(elementi[i][j]));
			//s.push_back((elementi[i][j])+'0');
			if (br_kolona-1==j) continue;
			s.push_back(',');
		}
		if (br_redova-1==i) continue;
		s.push_back('}');
		s.push_back(',');
	}
	s.push_back('}');
	s.push_back('}');
	return s;
}


template <typename Tip, typename Tip_neki>
Matrica<Tip> operator *= (Matrica <Tip> &m, Tip_neki n){
	for (int i = 0; i<m.br_redova; i++)
	for (int j = 0; j<m.br_kolona; j++)
	m.elementi[i][j]=n*m.elementi[i][j];
	return m;
}


template <typename Tip, typename Tip_neki>
Matrica<Tip> operator *(Matrica <Tip> m, Tip_neki n){
	for (int i = 0; i<m.br_redova; i++)
	for (int j = 0; j<m.br_kolona; j++)
	m.elementi[i][j]=n*m.elementi[i][j];
	return m;
}


template <typename Tip>
Matrica<Tip> operator *= (Matrica <Tip> &m1, const Matrica <Tip> &m2){
	m1=m1*m2;
	return m1;
}


template <typename Tip>
Matrica<Tip> operator -= (Matrica <Tip> &m1,const Matrica <Tip> &m2){
	m1=m1-m2;
	return m1;
}

template <typename Tip>
Matrica<Tip> operator += (Matrica <Tip> &m1, const Matrica <Tip> &m2){
	m1=m1+m2;
	return m1;
}


template <typename Tip>
Matrica<Tip> operator *(const Matrica <Tip> &m1,const Matrica <Tip> &m2){
	if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica <Tip> m3(m1.br_redova,m2.br_kolona);
    for (int i = 0; i<m1.br_redova; i++)
        for (int j = 0; j<m2.br_kolona; j++) {
            Tip suma(0);
            for (int k = 0; k < m2.br_redova; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }
    return m3;
}


template <typename Tip>
Matrica<Tip> operator +(const Matrica <Tip> &m1,const  Matrica <Tip> &m2){
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<Tip> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}

template <typename Tip>
Matrica<Tip> operator -(const Matrica <Tip> &m1,const  Matrica <Tip> &m2){
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<Tip> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
	return m3;
}

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

// kopirajuci konstruktor
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}

//pomjerajuci konstruktor
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(m.elementi)
{
	m.br_redova = 0;
	m.elementi = nullptr;
}

//operator dodjele
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator = (const Matrica<TipEl> &m)
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

//pomjerajuci operator dodjele
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator = (Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}

template <typename Tip>
std::istream &operator >> (std::istream &tok, Matrica <Tip> &m){
	for (int i = 0; i<m.br_redova; i++)
	for (int j = 0; j<m.br_kolona; j++){
		std::cout<<m.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
		tok>>m.elementi[i][j];
	}
	return tok;
}

template <typename Tip> 
std::ostream &operator << (std::ostream &tok,Matrica <Tip> &m){
	int a(tok.width());
	for (int i = 0; i<m.br_redova; i++){
	for (int j = 0; j<m.br_kolona; j++){
		tok<<std::setw(a);
	tok<<m.elementi[i][j];
  
	}
	std::cout<<std::endl;
	}
	return tok;
}

int main()
{
	int m, n;
	std::cout << "Unesi broj redova i kolona za matrice:\n";
	std::cin >> m >> n;
	try {
		
		Matrica<int> a(m, n, 'A'), b(m, n, 'B');
		std::cout << "Unesi matricu A:\n";
		std::cin>>a;
	//	a.SacuvajUTekstualnuDatoteku("mat.txt");
	//	a.SacuvajUBinarnuDatoteku("mat.dat");
		std::ofstream tok("nova.txt");
		tok<<("1,2,3,8\n4,2,5,9");
		tok.close();
		std::ofstream tok2("bin.dat", std::ios::binary);
		std::vector<std::vector<int>> c{{1,2},{3,4},{5,6}};
		char zarez(',');
		for (int i = 0; i<3; i++){
			for (int j = 0; j<2; j++){
				tok2.write(reinterpret_cast<char*>(&c.at(i).at(j)), sizeof (int));
				if (j<1) tok2.write(reinterpret_cast<char*>(&zarez), sizeof zarez);
			}
			char novi_red('\n');
			tok2.write(reinterpret_cast<char*>(&novi_red), sizeof (novi_red));
		}
		tok2.close();
		a.ObnoviIzBinarneDatoteke("bin.dat");
		Matrica<int> m("nova.txt", false);
		std::cout<<std::setw(4)<<m<<std::endl;
	//	a.ObnoviIzTekstualneDatoteke("nova.txt");
	//	std::cout << "Unesi matricu B:\n";
	//	std::cin>>b;
	//	std::cout << "Zbir ove dvije matrice je:\n";
	//	a*=2;
	//	a*=b;
	//	a=a*2;
	//	std::cout<<std::setw(4)<<a<<std::endl;
	//	a=2*a;
	//	std::cout<<std::setw(4)<<a<<std::endl;
	//	a= (a + b) * (3 * a - b);
	//	std::cout<<b[1][1];
	//	std::cout<<std::setw(4)<<a;
	} catch(std::bad_alloc) {
		std::cout << "Nema dovoljno memorije!\n";
	} catch(std::range_error iz){
		std::cout<<iz.what();
	} catch(std::logic_error iz){
		std::cout<<iz.what();
	}
	return 0;
}
