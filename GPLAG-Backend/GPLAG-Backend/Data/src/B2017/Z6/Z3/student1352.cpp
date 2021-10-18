/*
   B16/17 (Tutorijal 12, Zadatak 6)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <sstream>
#include <string>
#include <fstream>

using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::cout;
using std::cin;
using std::endl;

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
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	void Unesi();
	void Ispisi(int sirina_ispisa) const;
	template <typename Tip2>
	friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1,  const Matrica<Tip2> &m2);
	
	friend Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
		Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
		for(int i=0; i<m3.br_redova; i++)
			for(int j=0; j<m3.br_kolona; j++) m3.elementi[i][j]=0; 
			
			
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m2.br_kolona; j++)
				for(int k=0; k<m1.br_kolona; k++) m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
				return m3;
	}
	
	friend Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
	if(m1.br_redova!=m2.br_redova || m1.br_kolona !=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++) m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
			return m3;
	} 
	
	friend Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++) 
				m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
				return m3;
	}
	
	template <typename TIP>
	friend Matrica<TipEl> operator *(const Matrica<TipEl> &m1, TIP n){
		Matrica<TipEl> m2(m1.br_redova, m1.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++) m2.elementi[i][j]=m1.elementi[i][j]*n;
			return m2;
	}
	template <typename TIP>
	friend Matrica<TipEl> operator *(TIP n, const Matrica<TipEl> &m1) {
		Matrica<TipEl> m2(m1.br_redova, m1.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++)
				m2.elementi[i][j]=m1.elementi[i][j]*n;
				return m2;
	}
	
	friend	std::istream &operator >>(std::istream &tok, Matrica<TipEl> &mat) {
		
		for(int i=0; i<mat.br_redova; i++) 
			for(int j=0; j<mat.br_kolona; j++) { std::cout<<mat.ime_matrice<<"("<<i+1<<","<<j+1<<") = "; std::cin>>mat.elementi[i][j]; }
			return tok;
	}
	 
	friend Matrica<TipEl> &operator +=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i=0; i<m1.br_redova; i++) 
			for(int j=0; j<m1.br_kolona; j++) m1.elementi[i][j]+=m2.elementi[i][j];
			return m1;
	}
	
	friend Matrica<TipEl> &operator-=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
				if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i=0; i<m1.br_redova; i++)
			for(int j=0; j<m1.br_kolona; j++) m1.elementi[i][j]-=m2.elementi[i][j];
			return m1;
	}

	TipEl &operator () (int i, int j) const {
		if(i<1 || j<1 || i>br_redova || j>br_kolona) throw std::range_error("Neispravan indeks");
		return elementi[i-1][j-1];
	}
	
	TipEl *operator [] (int i) const{
		return elementi[i];
	}
	
	friend Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2){
		m1=m1*m2;
		return m1;
	}
	
	friend Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, double koef){
		m1=m1*koef;
		return m1;
	}
	
	
	friend	std::ostream &operator << (std::ostream &tok, const Matrica<TipEl> &m) {
		int sirina=tok.width();
		for(int i=0; i<m.br_redova; i++) {
			for(int j=0; j<m.br_kolona; j++) tok << std::setw(sirina) << m.elementi[i][j]; 
			tok << std::endl; }
			return tok;
	}
	
	operator string() const;
	
	
	//NOVE METODE za zadacu
	void SacuvajUTekstualnuDatoteku(string ime);
	void SacuvajUBinarnuDatoteku(string ime);
	void ObnoviIzTekstualneDatoteke(string ime);
	void ObnoviIzBinarneDatoteke(string ime);
	
	//novi konstruktor
	Matrica(string ime, bool binarna);
	
	
	
};

template <typename TipEl>
Matrica<TipEl>::Matrica(string ime, bool binarna): br_kolona(0), br_redova(0), elementi(nullptr){
    if(binarna)
        ObnoviIzBinarneDatoteke(ime);
     else
        ObnoviIzTekstualneDatoteke(ime);
}

template<typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(string ime){
    ofstream datoteka(ime);
    if(!datoteka and !datoteka.eof())
        throw std::logic_error("Trazena datoteka ne postoji");
    for(int i=0; i<br_redova; i++){
        for(int j=0; j<br_kolona; j++){
            datoteka<<elementi[i][j];
            if(j!=br_kolona-1) datoteka<<",";
            else if(i!=br_redova-1) datoteka<<std::endl;
            
            
        }
    }
    datoteka.close();
}

template<typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(string ime){
    ofstream datoteka(ime,ios::binary);
    datoteka.write(reinterpret_cast<char*>(this),sizeof(*this));
    for(int i=0; i<br_redova; i++){
        datoteka.write(reinterpret_cast<char*>(elementi[i]),sizeof(TipEl)*br_kolona);
    }
    if(!datoteka and !datoteka.eof())
        throw std::logic_error("Problemi sa upisom u datoteku");
    datoteka.close();
}

template<typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(string ime){
    ifstream datoteka(ime);
    if(!datoteka)
        throw std::logic_error("Trazena datoteka ne postoji");
    int redovi(0),kolone(0),kolone2(-1);
    TipEl element{};
    char znak;
    while(!datoteka.eof()){
        datoteka>>element;
        kolone++;
        if(datoteka.eof()){
            redovi++;
            break;
        }
        znak=datoteka.get();
        if(znak=='\n'){
            redovi++;
            if(kolone2==-1)
                kolone2=kolone;
            else if(kolone!=kolone2)
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            kolone=0;
            
            
        }
        else if(znak!=',' and !datoteka.eof())
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        else if(!datoteka.eof() and !datoteka)
            throw std::logic_error("Problemi pri citanju datoteke");
    }
    
    DealocirajMemoriju(elementi,br_redova);
    if(kolone2!=-1){
        elementi=AlocirajMemoriju(redovi,kolone);
    }
    
    
    else return;
    
    br_redova=redovi;
    br_kolona=kolone;
    datoteka.close();
    datoteka.open(ime);
    while(!datoteka.eof()){
        for(int i=0; i<redovi; i++){
            for(int j=0; j<kolone; j++){
                datoteka>>elementi[i][j];
                datoteka.get();
            }
        }
    }
    
    datoteka.close();
    
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(string ime){
    ifstream binarna(ime,ios::binary);
    if(!binarna)
        throw std::logic_error("Trazena datoteka ne postoji");
    DealocirajMemoriju(elementi,br_redova);
    binarna.read(reinterpret_cast<char*>(this),sizeof(*this));
    elementi=AlocirajMemoriju(br_redova,br_kolona);
    for(int i=0; i<br_redova; i++){
        for(int j=0; j<br_kolona; j++){
            binarna.read(reinterpret_cast<char*>(&elementi[i][j]),sizeof(TipEl));
        }
        
    }
    if(!binarna and !binarna.eof()){
        throw std::logic_error("Problemi pri citanju datoteke");
    }
    binarna.close();
}

template <typename T> std::string PretvoriUString(T x){
	std::ostringstream s;
	s<<x;
	return s.str();
	
}


template<typename TipEl>
Matrica<TipEl>::operator string() const{
	string rez;
	rez.push_back('{');
	for(int i=0; i<br_redova; i++){
		rez.push_back('{');
		for(int j=0; j<br_kolona; j++){
			rez+=PretvoriUString(elementi[i][j]);
			if(j!=br_kolona-1) rez.push_back(',');
			
		}
		rez.push_back('}');
		if(i!=br_redova-1) rez.push_back(',');
	}
	rez.push_back('}');
	return rez;
	
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
		
		std::cin>>a;
		std::cout << "Unesi matricu B:\n";
		std::cin>>b;
		std::cout << "Razlika ove dvije matrice je:\n";
	
		Matrica<double> c(m, n, 'C');
		c=a-b; c.Ispisi(7);
		std::cout<<std::endl;
		c+=a; c.Ispisi(7);
		std::cout<<std::endl<<"Proizvod matrica je: "<<std::endl;
		c=a*b; c.Ispisi(7);
		std::cout<<std::endl; 
	
	std::cout<<c(1,2);
	std::cout<<std::endl;
	std::cout<<std::setw(5)<<c;
	std::cout<<std::endl<<c[1][1]<<endl;
	
	
	a.SacuvajUTekstualnuDatoteku("matricaA");
	b.SacuvajUBinarnuDatoteku("matricaB");
	
	Matrica<double> novaA("matricaA",false);
	Matrica<double> novaB("matricaB",true);
	
	cout<<"Obnovljena iz tekstualne matrica A:"<<endl;
	cout<<std::setw(4)<<novaA;
	
	cout<<endl;
	
	cout<<"Obnovljena iz binarne matrica B:"<<endl;
	cout<<std::setw(4)<<novaB;
	
	} catch(std::bad_alloc) {
		std::cout << "Nema dovoljno memorije!\n";
	}
	
	
	
	
	
	
	return 0;
	
	

	
}