/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>
using namespace std;
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
    void SacuvajUTekstualnuDatoteku(string s);
    void SacuvajUBinarnuDatoteku(string s);
    void ObnoviIzTekstualneDatoteke(string s);
    void ObnoviIzBinarneDatoteke(string s);
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	Matrica(string s,bool a);
	~Matrica(){
		DealocirajMemoriju(elementi, br_redova);
	}
	operator string()const{
		string pomoc;
		pomoc.push_back('{');
		for(int i=0;i<br_redova;i++){
			pomoc.push_back('{');
			for(int j=0;j<br_kolona;j++){
				pomoc+=to_string(int((*this)[i][j]));
				if(j!=br_kolona-1)
					pomoc+=',';
			}
			pomoc.push_back('}');
			if(i!=br_redova-1)
				pomoc+=',';
		}
		pomoc.push_back('}');
		return pomoc;
	}
	explicit operator string(){
		string pomoc;
		pomoc.push_back('{');
		for(int i=0;i<br_redova;i++){
			pomoc.push_back('{');
			for(int j=0;j<br_kolona;j++){
				pomoc+=to_string(int((*this)[i][j]));
				if(j!=br_kolona-1)
					pomoc+=',';
			}
			pomoc.push_back('}');
			if(i!=br_redova-1)
				pomoc+=',';
		}
		pomoc.push_back('}');
		return pomoc;
	}
	template<typename Tip>
	friend istream &operator >>(istream &tok,Matrica<Tip> &mat);
	template<typename Tip>
	friend ostream &operator <<(ostream &tok,const Matrica<Tip> &mat);
	int DajRed(){return br_redova;}
	int DajKol(){return br_kolona;}
	char DajIme(){return ime_matrice;}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	void Unesi();
	void Ispisi(int sirina_ispisa) const;
	template<typename Tip>
	Matrica<Tip> &operator *=(const Matrica<Tip> &mat2){
		if(br_kolona!=mat2.br_redova)
        	throw domain_error("Matrice nisu saglasne za mnozenje");
	    auto nova(Matrica<Tip>(br_redova,mat2.br_kolona));
	    for(int i=0;i<br_redova;i++)
	        for(int j=0;j<mat2.br_kolona;j++)
	            for(int k=0;k<br_kolona;k++)
	                nova.elementi[i][j]+=elementi[i][k]*mat2.elementi[k][j];
	    *this=nova;
	    return *this;
	}
	Matrica<TipEl> &operator *=(double x) {
		for(int i=0;i<br_redova;i++)
        	for(int j=0;j<br_kolona;j++)
            	(*this)[i][j]*=x;
    	return *this;
	}
	template<typename Tip>
	friend Matrica<Tip> operator -(const Matrica<Tip> &m1,const Matrica<Tip> &m2);
    template<typename Tip>
	Matrica<Tip> &operator -=(const Matrica<Tip> &m2){
		if(br_redova != m2.br_redova || br_kolona != m2.br_kolona)
		throw domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j]-=m2.elementi[i][j];
	return *this;
	}
	template<typename Tip>
	Matrica<Tip> &operator +=(const Matrica<Tip> &m2){
		if(br_redova != m2.br_redova || br_kolona != m2.br_kolona)
		throw domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j]+=m2.elementi[i][j];
	return *this;
	}
	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template<typename Tip2>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &mat1,const Matrica<Tip2> &mat2);
	template <typename Tip>
	friend Matrica<Tip> operator *(Matrica<Tip> mat,double x);
	template <typename Tip>
	friend Matrica<Tip> operator *(double x,Matrica<Tip> mat);
	TipEl *operator [](int indeks){ return elementi[indeks];}
	TipEl *operator [](int indeks)const{ return elementi[indeks];}
	TipEl &operator ()(int i,int j)	{
		if(i<1 or i>br_redova or j<1 or j>br_kolona)
			throw range_error("Neispravan indeks");
		return (*this)[i-1][j-1];
	}
	TipEl operator ()(int i,int j)const{
		if(i<1 or i>br_redova or j<1 or j>br_kolona)
			throw range_error("Neispravan indeks");
		return (*this)[i-1][j-1];
	}
	
};
template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona){
	TipEl **elementi(new TipEl*[br_redova] {});
	try{
		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona]{};
	}
	catch(...)	{
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
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice){
	m.br_redova = 0;
	m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m){
	if(br_redova < m.br_redova || br_kolona < m.br_kolona)	{
		TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	}
	else if(br_redova > m.br_redova)
		for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
template<typename Tip>
void Matrica<Tip>::SacuvajUTekstualnuDatoteku(string s){
    ofstream izlaz(s);
    for(int i=0;i<br_redova;i++)
    {
        int j=0;
        for(;j<br_kolona-1;j++)
            izlaz << elementi[i][j] << ",";
        izlaz << elementi[i][j] << "\n";
        if(!izlaz)
            throw logic_error("Problemi sa upisom u datoteku");
    }
}
template<typename Tip>
void Matrica<Tip>::ObnoviIzTekstualneDatoteke(string s){
    ifstream ulaz(s);
    if(!ulaz)
        throw logic_error("Trazena datoteka ne postoji");
    Tip pomoc;
    char znak;
    vector<vector<Tip>> el;
    for(;;){
        vector<Tip> v;
        for(;;) {
            ulaz >> pomoc;
            if(!ulaz)
                break;
            v.push_back(pomoc);
            if(ulaz.peek() != ',' and ulaz.peek() != '\n'){
                ulaz.setstate(ios::failbit);
                break;
            }
            if(ulaz.peek() != ',')
                break;
            ulaz >> znak;
        }
        if(ulaz.bad())
            throw logic_error("Problemi pri citanju datoteke");
        if(!ulaz and !ulaz.eof())
            throw logic_error("Datoteka sadrzi besmislene podatke");
        el.push_back(v);
        ulaz >> ws;
        if(ulaz.eof())
            break;
    }
    if(el.size() != 0)
        for(int i = 0; i < el.size() - 1; i++)
            if(el[i].size() != el[i+1].size())
                throw logic_error("Datoteka sadrzi besmislene podatke");
    DealocirajMemoriju(elementi,br_redova);
    br_redova=el.size();
    if(br_redova != 0)
        br_kolona=el[0].size();
    elementi=AlocirajMemoriju(br_redova,br_kolona);
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++)
            elementi[i][j] = el[i][j];
    
}
template<typename Tip>
void Matrica<Tip>::ObnoviIzBinarneDatoteke(string s){
    ifstream ulaz(s,ios::binary);
    if(!ulaz)
        throw logic_error("Trazena datoteka ne postoji");
    DealocirajMemoriju(elementi,br_redova);
    ulaz.read(reinterpret_cast<char*> (this),sizeof (*this));
    elementi = AlocirajMemoriju(br_redova,br_kolona);
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++){
            ulaz.read(reinterpret_cast<char*> (&elementi[i][j]), sizeof (elementi[i][j]));
            if(!ulaz)throw logic_error("Problemi pri citanju datoteke");
        }
}
template<typename Tip>
void Matrica<Tip>::SacuvajUBinarnuDatoteku(string s){
    ofstream izlaz(s,ios::binary);
    izlaz.write(reinterpret_cast<char*> (this),sizeof (*this));
    for(int i=0;i<br_redova;i++)
        for(int j=0;j<br_kolona;j++){   
            if(!izlaz) throw logic_error("Problemi sa upisom u datoteku");
            izlaz.write(reinterpret_cast<char*> (&elementi[i][j]),sizeof (elementi[i][j]));
        }
}
template<typename Tip>
Matrica<Tip>::Matrica(string s,bool a){
    br_redova=0;
    br_kolona=0;
    elementi=nullptr;
    if(!a)
        ObnoviIzTekstualneDatoteke(s);
    else
        ObnoviIzBinarneDatoteke(s);
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
	swap(br_redova, m.br_redova);
	swap(br_kolona, m.br_kolona);
	swap(ime_matrice, m.ime_matrice);
	swap(elementi, m.elementi);
	return *this;
}
template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3[i][j]=m1[i][j]+m2[i][j];
	return m3;
}
template <typename TipEl>
istream &operator>> (istream &tok,Matrica<TipEl> &mat)
{
	for(int i = 0; i < mat.DajRed(); i++)
		for(int j = 0; j < mat.DajKol(); j++)
		{
			cout << mat.DajIme() << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> mat.elementi[i][j];
		}
	return tok;
}
template <typename TipEl>
ostream &operator <<(ostream &tok,const Matrica<TipEl> &mat){
	int a=tok.width();
	for(int i = 0; i < mat.br_redova; i++){
		for(int j = 0; j < mat.br_kolona; j++)
			tok << setw(a) << mat.elementi[i][j];
		tok << "\n";
	}
	return tok;
}
template<typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &mat1,const Matrica<TipEl> &mat2){
	if(mat1.br_kolona!=mat2.br_redova)
        throw domain_error("Matrice nisu saglasne za mnozenje");
    auto nova(Matrica<TipEl>(mat1.br_redova,mat2.br_kolona));
    for(int i=0;i<mat1.br_redova;i++)
        for(int j=0;j<mat2.br_kolona;j++)
            for(int k=0;k<mat1.br_kolona;k++)
                nova.elementi[i][j]+=mat1.elementi[i][k]*mat2.elementi[k][j];
    return nova;
}
template <typename Tip>
Matrica<Tip> operator *(Matrica<Tip> mat,double x){
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++)
            mat.elementi[i][j]*=x;
    return mat;
}
template <typename Tip>
Matrica<Tip> operator *(double x,Matrica<Tip> mat){
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++)
            mat.elementi[i][j]*=x;
    return mat;
}
template<typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2){
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
	return m3;
}
int main1(){
  int m,n;
  cout << "Unesi broj redova i kolona za matrice:\n";
  cin >> m >> n;
  try {
    Matrica<double> a(m, n, 'A'), b(m, n, 'B');
    cout << "Unesi matricu A:\n";
    cin >> a;
    cout << "Unesi matricu B:\n";
    cin >> b;
a*=b;
b*=10;
for(int i = 0; i < 2; i++){
      for(int j = 0; j < 2; j++)
      cout << a[i][j] << " ";
      cout << endl;
}
cout << "---------------" << endl;
for(int i = 0; i < 2; i++){
      for(int j = 0; j < 2; j++)
      cout << b[i][j] << " ";
      cout << endl;
}
}
catch(bad_alloc) {
    cout << "Nema dovoljno memorije!\n";
  }
    catch(domain_error e) {
    cout << e.what();
  }
    catch(range_error e) {
    cout << e.what();
  }
	return 0;
}
int main()
{
    Matrica<int> a("binarna.dat",true);
    cout<<a;
	return 0;
}