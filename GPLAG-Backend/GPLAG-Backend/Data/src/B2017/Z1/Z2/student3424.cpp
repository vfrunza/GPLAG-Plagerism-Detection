PRVII

#include <iostream>
#include <stdexcept>

using namespace std;

class Sat{
	int sati, minute, sekunde;
	
public: 
	Sat (int sati1, int minute1, int sekunde1)
	{
		while(sekunde1>=60) 
		{
			sekunde1-=60;
			minute1++;
		}
		while(sekunde1<0)
		{
			sekunde1+=60;
			minute1--;
		}
		while(minute1>=60)
		{
			minute1-=60;
			sati1++;
		}
		while(minute1<0)
		{
			minute1+=60;
			sati1--;
		}
		
		while(sati1>=24)
			sati1-=24;
		while(sati1<0)
			sati1+=24;
			
		sati=sati1;
		minute=minute1;
		sekunde=sekunde1;
	}
	
	Sat() {
		sati=0;
		minute=0;
		sekunde=0;
	}
	
	void PostaviNormalizirano(int sati, int minute, int sekunde) {
		while(sekunde>=60) 
		{
			sekunde-=60;
			minute++;
		}
		while(sekunde<0)
		{
			sekunde+=60;
			minute--;
		}
		while(minute>=60)
		{
			minute-=60;
			sati++;
		}
		while(minute<0)
		{
			minute+=60;
			sati--;
		}
		
		while(sati>=24)
			sati-=24;
		while(sati<0)
			sati+=24;
			
		Sat::sati=sati;
		Sat::minute=minute;
		Sat::sekunde=sekunde;
	} 
	
	friend std::ostream &operator <<(std::ostream &tok, const Sat &sat)
	{
		if(sat.sati<10 && sat.minute<10  && sat.sekunde<10) return tok<<"0"<<sat.sati<<":0"<<sat.minute<<":0"<<sat.sekunde;
		if(sat.sati>=10 && sat.minute<10  && sat.sekunde>10) return tok<<sat.sati<<":0"<<sat.minute<<":"<<sat.sekunde;
		else if(sat.sati<10 && sat.minute>10  && sat.sekunde>10) return tok<<"0"<<sat.sati<<":"<<sat.minute<<":"<<sat.sekunde;
		else if(sat.sati<10 && sat.minute<10  && sat.sekunde>10) return tok<<"0"<<sat.sati<<":0"<<sat.minute<<":"<<sat.sekunde;
		else if(sat.sati<10 && sat.minute>10  && sat.sekunde<10) return tok<<"0"<<sat.sati<<":"<<sat.minute<<":0"<<sat.sekunde;
		else if(sat.sati>10 && sat.minute<10  && sat.sekunde<10) return tok<<sat.sati<<":0"<<sat.minute<<":0"<<sat.sekunde;
		else if(sat.sati>10 && sat.minute<10  && sat.sekunde>10) return tok<<sat.sati<<":0"<<sat.minute<<":"<<sat.sekunde;
		else if(sat.sati>10 && sat.minute>10  && sat.sekunde<10) return tok<<sat.sati<<":"<<sat.minute<<":0"<<sat.sekunde;
		else  return tok<<sat.sati<<":"<<sat.minute<<":"<<sat.sekunde;
	}
	
	
	static bool DaLiJeIspravno(int sati, int minute, int sekunde);
	void Postavi(int sati, int minute, int sekunde);

	int DajSate() const { return sati; }
	int DajMinute() const { return minute; }
	int DajSekunde() const { return sekunde; }

	//postfiksni
	friend Sat operator ++(Sat &sat, int) { 
		Sat novi(sat);
		sat.sekunde++;
		sat.PostaviNormalizirano(sat.sati, sat.minute, sat.sekunde);
		return novi;
	}
	//prefiksni
	friend Sat &operator ++(Sat &sat) { 
		sat.sekunde++;
		sat.PostaviNormalizirano(sat.sati, sat.minute, sat.sekunde);
		return sat;
	}
	//postfiksni
	friend Sat operator --(Sat &sat, int) { 
		Sat novi(sat);
		sat.sekunde--;
		sat.PostaviNormalizirano(sat.sati, sat.minute, sat.sekunde);
		return novi;
	}
	//prefiksni
	friend Sat &operator --(Sat &sat) { 
		sat.sekunde--;
		sat.PostaviNormalizirano(sat.sati, sat.minute, sat.sekunde);
		return sat;
	}
	
	friend Sat operator +=(Sat &sat, int pomak) {
		sat.sekunde+=pomak; 
		sat.PostaviNormalizirano(sat.sati, sat.minute, sat.sekunde);
		return sat;
	}
	

	
	friend Sat operator -=(Sat &sat, int pomak) {
		sat.sekunde-=pomak;
		sat.PostaviNormalizirano(sat.sati, sat.minute, sat.sekunde);
		return sat;
	}
	

	
	
	friend int operator -(const Sat &sat1, const Sat &sat2) {
	return (sat1.sati*3600+sat1.minute*60+sat1.sekunde)-(sat2.sati*3600+sat2.minute*60+sat2.sekunde);
	}
	
	
	friend Sat operator +(Sat &sat1, int n) {
		Sat novi;
		novi.sekunde=sat1.sekunde+n;
		novi.minute=sat1.minute;
		novi.sati=sat1.sati;
		novi.PostaviNormalizirano(novi.sati, novi.minute, novi.sekunde);
		return novi;
	}
	
	friend Sat operator -(Sat &sat1, int n) {
		Sat novi;
		novi.sekunde=sat1.sekunde-n;
		novi.minute=sat1.minute;
		novi.sati=sat1.sati;
		novi.PostaviNormalizirano(novi.sati, novi.minute, novi.sekunde);
		return novi;
	}
	
};

bool Sat::DaLiJeIspravno(int sati, int minute, int sekunde)
{
	bool tacno(1);
	if(sati<0 || sati>=24 || minute<0 || minute>=60 || sekunde>=60 || sekunde<0)
		tacno=0;
	return tacno;
}

void Sat::Postavi(int sati, int minute, int sekunde)
{
	Sat::sati=sati;
	Sat::minute=minute;
	Sat::sekunde=sekunde;
	
	if(DaLiJeIspravno(sati, minute, sekunde)==false)
		throw std::domain_error("Neispravno vrijeme");
}


int main ()
{
	return 0;
}




DRUGIII
#include <iostream>
#include <set>
#include <string>

using std:: set;
using std:: cout;
using std:: cin;
using std:: endl;
using std:: string;

template <typename nekitip>
set<nekitip> operator +(set<nekitip>&set1, set<nekitip>&set2)
{
	set<nekitip>novi;
	novi=set1;
	novi.insert(set2.begin(), set2.end());
	return novi;
}

template <typename nekitip>
std::ostream operator <<(std::ostream &tok, set<nekitip> &nekiset)
{
	
	return tok<<
}


template <typename nekitip>
set<nekitip> operator *(set<nekitip> &set1, set<nekitip> &set2)
{
	set<nekitip>novi;
	for(nekitip x : set1)
	{
		for(nekitip y : set2)
		{
			if(x==y)
			{
				novi.insert(x);
			}
		}
	}
	return novi;
}

template <typename nekitip>
std::ostream &operator <<(std::ostream &tok ,const set<nekitip> &set)
{
	tok<<
	return tok;
}

int main()
{
	cout<<"Koliko elemenata ima prvi skup: ";
	int br_el1;
	cin>>br_el1;
	cout<<"Unesite elemente prvog skupa: ";
	set<string> set1;
	string clan1;
	for(int i=0; i<br_el1; i++)
	{
		std:: getline(cin, clan1);
		set1.insert(clan1);
		
	}
	
	cout<<"Koliko elemenata ima drugi skup: ";
	int br_el2;
	cin>>br_el2;
	cout<<"Unesite elemente drugog skupa: ";
	set<string> set2;
	string clan2;
	for(int i=0; i<br_el2; i++)
	{
		std:: getline(cin, clan2);
		set1.insert(clan2);
	}
	
	
	return 0;
}



SESTIIII
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>

using std:: cin;
using std:: cout;


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

	//UNOS 
	friend std::istream &operator >>(std::istream &tok, Matrica &m )
	{
		for(int i = 0; i < m.br_redova; i++)
			for(int j = 0; j < m.br_kolona; j++) {
				cout<<m.ime_matrice;
				cout<<"("<<i+1<<","<<j+1<<") = ";
				tok>>m.elementi[i][j];
			}
			return tok;
	}

	//ispis
	friend std::ostream &operator <<(std::ostream &tok, Matrica &m )
	{
		int sirina=tok.width();
		for(int i = 0; i < m.br_redova; i++)
		{
			for(int j = 0; j < m.br_kolona; j++)
			{
				tok<<std::setw(sirina)<<m.elementi[i][j];
				
			}
			tok<<std::endl;
		}	
			return tok;
	}
	

    friend Matrica operator +(const Matrica &m1, const Matrica &m2)
	{
		if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
		for(int i = 0; i < m1.br_redova; i++)
			for(int j = 0; j < m1.br_kolona; j++)
				m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
		return m3;
	}
	
	
	
	friend Matrica operator -(const Matrica&m1, const Matrica<TipEl> &m2)
	{
		if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
		for(int i = 0; i < m1.br_redova; i++)
			for(int j = 0; j < m1.br_kolona; j++)
				m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
		return m3;
	}
	
	friend Matrica operator +=(Matrica &m1, const Matrica &m2)
	{
		if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i = 0; i < m1.br_redova; i++)
			for(int j = 0; j < m1.br_kolona; j++)
				m1.elementi[i][j] += m2.elementi[i][j];
		return m1;
	}
	
	friend Matrica operator -=(Matrica &m1, const Matrica &m2)
	{
		if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i = 0; i < m1.br_redova; i++)
			for(int j = 0; j < m1.br_kolona; j++)
				m1.elementi[i][j] -= m2.elementi[i][j];
		return m1;
	}
	
	friend Matrica operator *=(Matrica &m1, const Matrica &m2)
	{
		if(m1.br_kolona != m2.br_redova)
			throw std::domain_error("Matrice nisu saglasne za mnozenje");
		Matrica m3(m1.br_redova, m2.br_kolona);
		for(int i=0; i<m1.br_redova; i++)
	    {
	        for(int j=0; j<m1.br_kolona;j++)
	        {
	            TipEl tmp = TipEl();
	            for(int k=0;k<m1.br_kolona;k++)
	                tmp += m1.elementi[i][k] * m2.elementi[k][j];
	            m3.elementi[i][j] = tmp;
	        }
	    }
	    m1 = m3;
		return m1;
	
	}
	friend Matrica operator *= (const Matrica &m1, double n)
	{
		for(int i = 0; i < m1.br_redova; i++)
			for(int j = 0; j < m1.br_kolona; j++)
				m1.elementi[i][j] *= n;
		return m1;
	}
	
	inline friend Matrica operator *= ( double n, const Matrica &m1)
	{
		return m1*=n;
	}
	friend Matrica operator * (const Matrica &m1, double n)
	{
		for(int i = 0; i < m1.br_redova; i++)
			for(int j = 0; j < m1.br_kolona; j++)
				m1.elementi[i][j] = m1.elementi[i][j] *n;
		return m1;
	}
	inline friend Matrica operator * ( double n, const Matrica &m1)
	{
		return m1*n;
	}
	friend Matrica operator *(const Matrica &m1, const Matrica &m2)
	{
		if(m1.br_kolona!=m2.br_redova)
		throw std::domain_error("Matrice nisu saglasne za mnozenje");
		Matrica m3(m1.br_redova, m2.br_kolona);
		for(int i=0; i<m3.br_redova; i++)
	    {
	        for(int j=0; j<m3.br_kolona;j++)
	        {
	            TipEl tmp = TipEl();
	            for(int k=0;k<m1.br_kolona;k++)
	                tmp += m1.elementi[i][k] * m2.elementi[k][j];
	            m3.elementi[i][j] = tmp;
	        }
	    }
		return m3;
	}
	
	TipEl &operator () (int prvi, int drugi)
	{
		try{
			TestIndeksa(prvi-1);
			TestIndeksa(drugi-1);
		}
		catch(std::range_error izuzetak)
		{	throw izuzetak;}
		return elementi[prvi-1][drugi-1];
	}
	
	TipEl operator () (int prvi, int drugi) const
	{
		try{
			TestIndeksa(prvi-1);
			TestIndeksa(drugi-1);
		}
		catch(std::range_error izuzetak)
			{throw izuzetak;}
		return elementi[prvi-1][drugi-1];
	}
	 
	TipEl *operator [] (int indeks)
	{
		try{
			TestIndeksa(indeks);
		}
		catch(std::range_error izuzetak)
			{throw izuzetak;}
		return elementi[indeks];
	}
	
	TipEl *operator [] (int indeks) const
	{
		try{
			TestIndeksa(indeks);
		}
		catch(std::range_error izuzetak)
			{throw izuzetak;}
		return elementi[indeks];
	}
	
	operator std::string() {
		std::string ret = "{";
		for(int i=0;i<br_redova;i++) {
			ret +="{";
			for(int j=0;j<br_kolona;j++) {
				if(j!=br_kolona-1)
					ret= ret + std::to_string(static_cast<int> (elementi[i][j])) +",";
				else ret = ret + std::to_string(static_cast<int> (elementi[i][j]));
			}
			if(i!=br_redova-1)
				ret +="},";
			else ret +="}";
		}
		ret +="}";
		return ret;//
	}
	
	operator std::string() const {
		std::string ret = "{";
		for(int i=0;i<br_redova;i++) {
			ret +="{";
			for(int j=0;j<br_kolona;j++) {
				if(j!=br_kolona-1)
					ret= ret + std::to_string(static_cast<int> (elementi[i][j])) +",";
				else ret = ret + std::to_string(static_cast<int> (elementi[i][j]));
			}
			if(i!=br_redova-1)
				ret +="},";
			else ret +="}";
		}
		ret +="}";
		return ret;
	}
	
	void TestIndeksa (int indeks) const
	{
		if(indeks<0 || indeks>br_redova) throw std:: range_error("Neispravan indeks");
	}
	
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


int main()
{
//AT 5 testiranje izraza koji kombinuje više operatora, unosa i ispisa
  int m,n;
  std::cout << "Unesi broj redova i kolona za matrice:\n";
  std::cin >> m >> n;
  try {
    Matrica<double> a(m, n, 'A'), b(m, n, 'B');
    std::cout << "Unesi matricu A:\n";
    std::cin >> a;
    std::cout << "Unesi matricu B:\n";
    std::cin >> b;
    a = (a + b) * (3 * a - b);
std::cout << std::setw(4) << a;
  }
catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
  }
    catch(std::domain_error e) {
    std::cout << e.what();
  }
    catch(std::range_error e) {
    std::cout << e.what();
  }
	return 0;
}


