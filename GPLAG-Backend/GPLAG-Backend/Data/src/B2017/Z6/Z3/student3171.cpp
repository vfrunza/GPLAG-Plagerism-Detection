/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>

template <typename TipEl>
class Matrica
{
	int br_redova=0, br_kolona=0;
	TipEl **elementi=nullptr;
	char ime_matrice=0;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
public: 
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(std::string, bool);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() {
		DealocirajMemoriju(elementi, br_redova);
	}
	void SacuvajUBinarnuDatoteku(std::string);
	void ObnoviIzBinarneDatoteke(std::string);
	void SacuvajUTekstualnuDatoteku(std::string);
	void ObnoviIzTekstualneDatoteke(std::string);
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	void Unesi();
	void Ispisi(int sirina_ispisa) const;
	template <typename Tip2>
	friend Matrica<Tip2> operator+(const Matrica<Tip2> &m1,
	                               const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2>& operator+=(Matrica<Tip2> &m1,
	                                 const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator-(const Matrica<Tip2> &m1,
	                               const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2>& operator-=(Matrica<Tip2> &m1,
	                                 const Matrica<Tip2> &m2);
	operator std::string()const;
	template <typename Tip2>
	friend std::istream& operator >>(std::istream& tok, Matrica<Tip2> &m);

	template <typename Tip2>
	friend std::ostream& operator <<(std::ostream& tok, const Matrica<Tip2> &m);

	template <typename Tip2>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1,
	                                const Matrica<Tip2> &m2);
	template <typename Tip2,typename broj>
	friend Matrica<Tip2> operator *(broj x, Matrica<Tip2> m2);

	template <typename Tip2,typename broj>
	friend Matrica<Tip2> operator *(Matrica<Tip2> m2, broj x);

	template <typename Tip2,typename broj>
	friend Matrica<Tip2>& operator *=(Matrica<Tip2> &m2, broj x);

	template <typename Tip2>
	friend Matrica<Tip2>& operator *=(Matrica<Tip2> &m1,
	                                  const Matrica<Tip2> &m2);

	TipEl* operator[](int i) {
		return this->elementi[i];
	}

	const TipEl* operator[](int i)const {
		return this->elementi[i];
	}



	TipEl& operator ()(int i,int j) {
		if(i<1 || j<1 || j-1>br_kolona || i-1>br_redova)throw std::range_error("Neispravan indeks");
		return elementi[i-1][j-1];
	}

	const TipEl& operator ()(int i,int j)const {
		if(i<1 || j<1 || j-1>br_kolona || i-1>br_redova)throw std::range_error("Neispravan indeks");
		return elementi[i-1][j-1];
	}
};

template<typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(std::string name){
	std::ofstream tok(name);
	if(!tok)throw std::logic_error("Problemi s upisom u datoteku");
	for(int i=0;i<br_redova;i++)
	{
		for(int j=0;j<br_kolona;j++)
		{
			tok<<elementi[i][j];
			if(!tok)throw std::logic_error("Problemi s upisom u datoteku");
			if(j==br_kolona-1)tok<<std::endl;
			else
			{
				tok<<",";
			}
			if(!tok)throw std::logic_error("Problemi s upisom u datoteku");
		}
	}
}

template<typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(std::string name)
{
	std::ifstream tok(name);
	if(!tok)throw std::logic_error("Trazena datoteka ne postoji");
	int red(0),kolona(0);
	TipEl x;
	char znak;
	while(true)
	{
		tok>>x;
		znak=tok.get();
		if(znak!='\n' && znak!=',' && znak!=EOF)throw std::logic_error("Datoteka sadrzi besmislene podatke");
		kolona++;
		if(znak=='\n'|| tok.eof())red++;
		if(!tok && tok.eof() && znak=='\n')red--;
		if(!tok)break;
	}
	if(!tok.eof())
	{
		throw std::logic_error("Datoteka sadrzi besmislene podatke");
	}
	if(elementi)
	{
		DealocirajMemoriju(elementi,br_redova);
	}
	br_kolona=kolona;
	br_redova=red;
	br_kolona/=br_redova;
	elementi=AlocirajMemoriju(br_redova,br_kolona);
	tok.close();
	tok.open(name);
	for(int i=0;i<br_redova;i++)
	{
		for(int j=0;j<br_kolona;j++)
		{
			tok>>elementi[i][j];
			znak=tok.get();
		}
	}
	znak=tok.get();
	if(tok.eof())return;
	if(tok.bad())throw std::logic_error("Problemi pri citanju datoteke");
	else throw std::logic_error("Datoteka sadrzi besmislene podatke");
}

template<typename TipEl>
Matrica<TipEl>::Matrica(std::string name , bool binarna_ili_ne)
{
	if(binarna_ili_ne)
	{
		this->ObnoviIzBinarneDatoteke(name);
	}
	else
	{
		this->ObnoviIzTekstualneDatoteke(name);
	}
	ime_matrice=0;
}
template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(std::string name)
{
	std::ofstream tok(name,std::ios::binary | std::ios::out);
	if(!tok.is_open())throw std::logic_error("Problemi sa upisom u datoteku");
	tok.seekp(0);
	tok.write(reinterpret_cast<char*>(&br_redova),sizeof(int));
	if(!tok)throw std::logic_error("Problemi sa upisom u datoteku");
	tok.write(reinterpret_cast<char*>(&br_kolona),sizeof(int));
	if(!tok)throw std::logic_error("Problemi sa upisom u datoteku");
	for(int i=0;i<br_redova;i++)
	{
		for(int j=0;j<br_kolona;j++)
		{
			tok.write(reinterpret_cast<char*>(&(elementi[i][j])),sizeof(TipEl));
			if(!tok)throw std::logic_error("Problemi sa upisom u datoteku");
		}
	}
}
template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(std::string name)
{
	int red,kolona;
	std::ifstream tok(name,std::ios::binary | std::ios::in);
	if(!tok.is_open())throw std::logic_error("Trazena datoteka ne postoji");
	if(elementi)DealocirajMemoriju(elementi,br_redova);
	tok.seekg(0);
	tok.read(reinterpret_cast<char*>(&red),sizeof(int));
			if(tok.fail())throw std::logic_error("Problemi pri citanju datoteke");
	tok.read(reinterpret_cast<char*>(&kolona),sizeof(int));
			if(tok.fail())throw std::logic_error("Problemi pri citanju datoteke");
	br_kolona=kolona;
	br_redova=red;
	elementi=AlocirajMemoriju(br_redova,br_kolona);
	for(int i=0;i<br_redova;i++)
	{
		for(int j=0;j<br_kolona;j++)
		{
			tok.read(reinterpret_cast<char*>(&(elementi[i][j])),sizeof(TipEl));
			if(tok.fail())throw std::logic_error("Problemi pri citanju datoteke");
		}
	}
}
template <typename Tip2>
Matrica<Tip2> operator-(const Matrica<Tip2> &m1,
                        const Matrica<Tip2> &m2)
{
	return (m1+(-1*m2));
}

template <typename Tip2>
Matrica<Tip2>& operator-=(Matrica<Tip2> &m1,
                          const Matrica<Tip2> &m2)
{
	m1=m1-m2;
	return m1;
}
template <typename Tip2,typename broj>
Matrica<Tip2>& operator *=(Matrica<Tip2> &m2, broj x)
{
	for(int i=0; i<m2.br_redova; i++) {
		for(int j=0; j<m2.br_kolona; j++) {
			m2.elementi[i][j]*=x;
		}
	}
	return m2;

}

template <typename Tip2,typename broj>
Matrica<Tip2> operator *(Matrica<Tip2> m2, broj x)
{

	for(int i=0; i<m2.br_redova; i++) {
		for(int j=0; j<m2.br_kolona; j++) {
			m2.elementi[i][j]*=x;
		}
	}
	return m2;
}
template <typename Tip2,typename broj>
Matrica<Tip2> operator *(broj x,
                         Matrica<Tip2> m2)
{
	for(int i=0; i<m2.br_redova; i++) {
		for(int j=0; j<m2.br_kolona; j++) {
			m2.elementi[i][j]*=x;
		}
	}
	return m2;
}

template <typename Tip2>
Matrica<Tip2>& operator *=(Matrica<Tip2> &m1,
                           const Matrica<Tip2> &m2)
{
	m1=m1*m2;
	return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator *(const Matrica<TipElemenata> &m1,
                                 const Matrica<TipElemenata> &m2)
{
	if(m1.br_redova != m2.br_kolona)throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipElemenata> m(m1.br_redova,m2.br_kolona,'x');
	for(int i=0; i<m1.br_redova; i++) {
		for(int j=0; j<m2.br_kolona; j++) {
			m.elementi[i][j]=0;
		}
	}
	for(int i=0; i<m1.br_redova; i++) {
		for(int j=0; j<m2.br_kolona; j++) {
			for(int k=0; k<m1.br_redova; k++) {
				m.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
			}
		}
	}
	return m;
}
template <typename TipEl>
std::ostream& operator <<(std::ostream& tok,const  Matrica<TipEl> &m)
{
	int sirina_ispisa=tok.width();
	for(int i = 0; i < m.br_redova; i++) {
		for(int j = 0; j < m.br_kolona; j++)
			tok << std::setw(sirina_ispisa) << m.elementi[i][j];
		tok << std::endl;
	}
	return tok;
}



template <typename TipEl>
std::istream &operator >>(std::istream& tok, Matrica<TipEl>& m)
{

	for(int i = 0; i < m.br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++) {
			std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> m.elementi[i][j];
		}
	return tok;
}

template <typename TipEl>
Matrica<TipEl>::operator std::string()const
{
	std::string matrica,temp;
	matrica+="{";
	for(int i=0; i<br_redova; i++) {
		matrica+="{";
		for(int j=0; j<br_kolona; j++) {
			temp=std::to_string(elementi[i][j]);;
			for(int k=temp.length()-1; k>0; k--) {
				if(temp[k]=='0') {
					if(temp[k-1]=='.') {
						temp.resize(k-1);
						break;
					}
					temp.resize(k);
				}
			}
			matrica+=temp;
			if(j!=br_kolona-1)matrica+=",";
		}
		matrica+="}";
		if(i!=br_redova-1)matrica+=",";
	}
	matrica+="}";
	return matrica;
}

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi(new TipEl*[br_redova] {});
	try {
		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona]{};
	} catch(...) {
	if(elementi)DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	if(elementi){
	for(int i = 0; i < br_redova; i++) if(elementi[i])delete[] elementi[i];
	delete[] elementi;}
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
Matrica<TipEl> operator+(const Matrica<TipEl> &m1,
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

template <typename TipEl>
Matrica<TipEl>& operator+=( Matrica<TipEl> &m1,
                            const Matrica<TipEl> &m2)
{
	m1=m1+m2;
	return m1;
}

int main ()
{
std::cout<<"Danas je divann dan\n";
// try
//     {
//         Matrica<int> m1("datoteka.DAT", true);
//     }
//     catch (const std::logic_error& e)
//     {
//         std::cout << "Izuzetak: " << e.what() << std::endl;
//     }
    
//     try
//     {
//         Matrica<int> m1("datoteka.txt", false);
//     }
//     catch (const std::logic_error& e)
//     {
//         std::cout << "Izuzetak: " << e.what() << std::endl;
//     }
    try
    {
        Matrica<int> m1(2,2);
        m1.ObnoviIzBinarneDatoteke("datoteka.DAT");
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
    try
    {
        Matrica<int> m1(2,2);
        m1.ObnoviIzTekstualneDatoteke("datoteka.txt");
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
	return 0;
}
