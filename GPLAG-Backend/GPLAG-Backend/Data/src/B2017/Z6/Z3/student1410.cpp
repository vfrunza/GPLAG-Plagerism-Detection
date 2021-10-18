#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
using std::string;
template <typename tip>
std::string to_string(tip x){
 std::ostringstream s; s<<x; return s.str();
}
template <typename TipEl>
 class Matrica {
 int br_redova, br_kolona;
 TipEl **elementi;
 char ime_matrice;
 static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
 static void DealocirajMemoriju(TipEl **elementi, int br_redova);
 void KopirajElemente(TipEl **elementi);
 public:
 void SacuvajUTekstualnuDatoteku(string naziv) const;
 void SacuvajUBinarnuDatoteku(string naziv);
 
 
 Matrica(int br_redova, int br_kolona, char ime = 0);
 Matrica(const Matrica &m);
 Matrica(Matrica &&m);
 ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
 Matrica &operator =(const Matrica &m);
 Matrica &operator =(Matrica &&m);
 //ZAVRSITI
 TipEl* &operator [](int indeks){
  return elementi[indeks]; 
 }
 TipEl* operator [](int indeks)const{
  return elementi[indeks];
 }
 TipEl operator()(int indeks1,int indeks2)const{
  if(indeks1<1 || indeks2<1 ||indeks1>br_redova || indeks2>br_kolona)throw std::range_error("Neispravan indeks");
  return elementi[indeks1-1][indeks2-1];
 }
 TipEl &operator()(int indeks1,int indeks2){
  if(indeks1<1 || indeks2<1 ||indeks1>br_redova || indeks2>br_kolona)throw std::range_error("Neispravan indeks");
  return elementi[indeks1-1][indeks2-1];
 }

 template<typename Tip2>
 friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
 
 friend std::istream &operator>>(std::istream &tok,Matrica<TipEl> &m){
 	for(int i = 0; i < m.br_redova; i++)
 for(int j = 0; j < m.br_kolona; j++) {
 std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
 tok >> m.elementi[i][j];
 }
 return tok;
 }
 
 friend Matrica<TipEl> operator-(const Matrica<TipEl>&m,const Matrica<TipEl> &M){
 //	Matrica<TipEl>rez(m.br_redova,m.br_kolona);
 	if(m.br_redova != M.br_redova || m.br_kolona != M.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 Matrica<TipEl> m3(m.br_redova, m.br_kolona);
 for(int i = 0; i < m.br_redova; i++)
 for(int j = 0; j < m.br_kolona; j++)
 m3.elementi[i][j] = m.elementi[i][j] - M.elementi[i][j];
 return m3;
 }
 template<typename tip>
friend Matrica<tip> operator*(const Matrica<TipEl>&m,tip n){
 	Matrica<TipEl>rez(m.br_redova,m.br_kolona);
 	for(int i(0);i<m.br_redova;i++)
 	for(int j(0);j<m.br_kolona;j++)
 	rez.elementi[i][j]=m.elementi[i][j]*n;
 	return rez;
 }
 template<typename tip>
friend Matrica<TipEl> operator*(tip n,const Matrica<TipEl>&m){
 	Matrica<TipEl>rez(m.br_redova,m.br_kolona);
 	for(int i(0);i<m.br_redova;i++)
 	for(int j(0);j<m.br_kolona;j++)
 	rez.elementi[i][j]=m.elementi[i][j]*n;
 	return rez;
 }
 friend Matrica<TipEl> operator*(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2){
  if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> rez(m1.br_redova,m2.br_kolona);
    for(int p=0; p<m1.br_redova; p++)
        for(int q=0; q<m2.br_kolona; q++)
            rez.elementi[p][q]=0;

    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            for(int k=0; k<m1.br_kolona; k++)
                rez.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];

    return rez;
 }

 friend Matrica &operator*=( Matrica<TipEl> &m1,const Matrica<TipEl> m2){
  if(m1.br_kolona != m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> rez(m1.br_redova,m2.br_kolona);
    for(int p=0; p<m1.br_redova; p++)
        for(int q=0; q<m2.br_kolona; q++)
            rez.elementi[p][q]=0;

    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            for(int k=0; k<m1.br_kolona; k++)
                rez.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
                
          for(int p=0; p<m1.br_redova; p++)
        for(int q=0; q<m1.br_kolona; q++)
            m1.elementi[p][q]=0;      
                
 for(int p=0; p<m1.br_redova; p++)
        for(int q=0; q<m1.br_kolona; q++)
            m1.elementi[p][q]=rez.elementi[p][q];   
    return m1;
 }

friend Matrica<TipEl> &operator-=(Matrica<TipEl> &m,const Matrica<TipEl> &M){
 //	Matrica<TipEl>rez(m.br_redova,m.br_kolona);
 	if(m.br_redova != M.br_redova || m.br_kolona != M.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 //Matrica<TipEl> m3(m.br_redova, m.br_kolona);
 for(int i = 0; i < m.br_redova; i++)
 for(int j = 0; j < m.br_kolona; j++)
 m.elementi[i][j] = m.elementi[i][j] - M.elementi[i][j];
 return m;
 }
 
 friend Matrica<TipEl> &operator*=( Matrica <TipEl>&m,int n){
 	//Matrica<TipEL>rez(m.br_redova,m.br_kolona);
 	for(int i(0);i<m.br_redova;i++)
 	for(int j(0);j<m.br_kolona;j++)
 	m.elementi[i][j]=m.elementi[i][j]*n;
 	return m;
 }
 friend Matrica<TipEl> operator+(const Matrica <TipEl> &m1,const Matrica<TipEl> &m2){
  if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }

 friend Matrica<TipEl> &operator+=(Matrica<TipEl>&m1,const Matrica<TipEl>m2){
  if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 //Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m1;
 }

 
 friend std::ostream &operator<<(std::ostream &tok,const Matrica &m){
 	int s(tok.width());
 	for(int i = 0; i < m.br_redova; i++) {
 for(int j = 0; j < m.br_kolona; j++)
 tok<<std::setw(s)<< m.elementi[i][j];
 tok<< std::endl;
 }
 return tok;
 }
 operator std::string() const{
 std::string s;
 s+="{";
 for(int i(0);i<br_redova;i++)
 for(int j(0);j<br_kolona;j++){
  
  if(j==0) s+="{";
   if(i==br_redova-1 &&j==br_kolona-1) {s=s+to_string(elementi[i][j])+"}"; break;}
  if(j==br_kolona-1) s=s+to_string(elementi[i][j])+"},";
 
  else s=s+to_string(elementi[i][j])+",";
 }
 
 
 s+="}";
 return s;
}
 }; ///kraj
 //SACUVAJ U DATOTEKU
 template <typename TipEl>
 void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(string naziv) const{
  std::ofstream izlazni_tok(naziv);
 for(int i(0);i<br_redova;i++){
 for(int j(0);j<br_kolona;j++)
 {
  if(j==br_kolona-1)
  izlazni_tok<<elementi[i][j];
  else
  izlazni_tok<<elementi[i][j]<<",";
 }
  izlazni_tok<<"\n";
 } 
  
  if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
 }
 
 template<typename TipEl> //VJEROVATNO NIJE OK
 void Matrica<TipEl>::SacuvajUBinarnuDatoteku(string naziv) {
  std::ofstream izlazni_tok(naziv,std::ios::binary);
 izlazni_tok.write(reinterpret_cast<char*>(this),sizeof *this);
// for(int i(0);i<br_redova;i++)
 for(int j(0);j<br_kolona;j++)
 izlazni_tok.write(reinterpret_cast<char*>(elementi[j]),sizeof (elementi[0][j]));
 if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
 }
 
 
 
 
 
 
template <typename TipEl>
 TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
 TipEl **elementi(new TipEl*[br_redova]{});
 try {
 for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
 }
 catch(...) {
 DealocirajMemoriju(elementi, br_redova); throw;
 }
 return elementi;
 }
template <typename TipEl>
 void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
 for(int i = 0; i < br_redova; i++) delete[] elementi[i];
 delete[] elementi;
 }
template <typename TipEl>
 Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
 br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
 elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
 void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++)
 Matrica::elementi[i][j] = elementi[i][j];
 }
template <typename TipEl>
 Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
 br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
 elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
 KopirajElemente(m.elementi);
 }
template <typename TipEl>
 Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
 br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice) {
 m.br_redova = 0; m.elementi = nullptr;
 }
template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m) {
 if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
 TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
 DealocirajMemoriju(elementi, br_redova);
 elementi = novi_prostor;
 }
 else if(br_redova > m.br_redova)
 for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
 br_redova = m.br_redova; br_kolona = m.br_kolona;
 ime_matrice = m.ime_matrice; KopirajElemente(m.elementi);
 return *this;
 }
template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
 std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
 std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
 return *this;
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

int main ()
{
	 try {
Matrica<double> a(2, 2, 'a');
a[0][0] = 10; a[0][1] = 2; 
a[1][0] = 4; a[1][1] = 5; 
a.SacuvajUBinarnuDatoteku("datoteka.dat");
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