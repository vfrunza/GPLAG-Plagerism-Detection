#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <cctype>
#include <fstream>
template <typename TipEl>
 class Matrica {
 int br_redova, br_kolona;
 char ime_matrice;
 TipEl **elementi;
 
 static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
 static void DealocirajMemoriju(TipEl **elementi, int br_redova);
 void KopirajElemente(TipEl **elementi);
  void TestIndeks(int indeks1, int indeks2) const {
  if(indeks1<1 || indeks2<1 || indeks1>br_redova || indeks2>br_kolona) throw std::range_error("Neispravan indeks");
 }
 public:
 Matrica(int br_redova, int br_kolona, char ime = 0);
 Matrica(std::string ime, bool vrsta){
  br_kolona=0;br_redova=0;
  if(vrsta) ObnoviIzBinarneDatoteke(ime);
  else ObnoviIzTekstualneDatoteke(ime);
  
 }
 Matrica(const Matrica &m);
 Matrica(Matrica &&m);
 ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
 Matrica &operator =(const Matrica &m);
 Matrica &operator =(Matrica &&m);
 Matrica &operator *=(const Matrica &m1);
 Matrica &operator *=(TipEl broj);
 void SacuvajUTekstualnuDatoteku(std::string ime);
 void SacuvajUBinarnuDatoteku(std::string ime);
 void ObnoviIzTekstualneDatoteke(std::string ime);
 void ObnoviIzBinarneDatoteke(std::string ime);
 
 
 Matrica &operator +=(const Matrica &m1);
 Matrica &operator -=(const Matrica &m1);
 std::string&  operator=(std::string& s);
 TipEl* &operator [] (int indeks){
  return elementi[indeks];
 }
 TipEl* operator [] (int indeks) const {
  return elementi[indeks];
 }
 
 
 TipEl operator ()(int indeks1, int indeks2) const {
  Matrica<TipEl>::TestIndeks(indeks1, indeks2);
  return elementi[indeks1-1] [indeks2-1];
  Matrica<TipEl>::TestIndeks(indeks1, indeks2);
 }
 TipEl& operator ()(int indeks1, int indeks2)  {
  Matrica<TipEl>::TestIndeks(indeks1, indeks2);
  return elementi[indeks1-1] [indeks2-1];
 }
  operator std::string () const;
  
 template <typename Tip3>
 friend std::istream& operator >> (std::istream &tok, Matrica<Tip3> & d);
 template <typename Tip4>
 friend std::ostream& operator << (std::ostream &tok,const  Matrica<Tip4> & d);
 void Ispisi(int sirina_ispisa) const;
 template <typename Tip2>
 friend Matrica<Tip2> operator+(const Matrica<Tip2> &m1,
 const Matrica<Tip2> &m2);
  template <typename Tip4, typename Tip2>
 friend Matrica<Tip4> operator*(Tip2 broj,
 const Matrica<Tip4> &m2);
   template <typename Tip4,typename Tip2>
 friend Matrica<Tip4> operator*(
 const Matrica<Tip4> &m2,Tip2 broj);
 
 
 template <typename Tip4>
 friend Matrica<Tip4> operator-(const Matrica<Tip4> &m1,
 const Matrica<Tip4> &m2);
 template <typename Tip4>
 friend Matrica<Tip4> operator*(const Matrica<Tip4> &m1,
 const Matrica<Tip4> &m2);
 };
 template<typename Tip4, typename Tip2>
  Matrica<Tip4> operator*(Tip2 broj,
 const Matrica<Tip4> &m2){
  Matrica<Tip4> m3(m2.br_redova,m2.br_kolona);
  for(int i = 0; i < m2.br_redova; i++)
 for(int j = 0; j < m2.br_kolona; j++)
 m3.elementi[i][j] = m2.elementi[i][j] *broj;
 return m3;
 }
 template<typename Tip4, typename Tip2>
  Matrica<Tip4> operator*(
 const Matrica<Tip4> &m2,Tip2 broj){
  return broj*m2;
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
 Matrica<TipEl> & Matrica<TipEl>:: operator *=(const Matrica<TipEl>& m1){
  if(br_kolona!=m1.br_kolona || br_kolona!=m1.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  *this=(*this)*m1;
  return *this;
  
  
 }
  template <typename TipEl>
 Matrica<TipEl> & Matrica<TipEl>:: operator +=(const Matrica<TipEl>& m1){
  if(br_kolona!=m1.br_kolona || br_redova!=m1.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
  *this=(*this)+m1;
  return *this;
  }
  template <typename TipEl>
 Matrica<TipEl> & Matrica<TipEl>:: operator -=(const Matrica<TipEl>& m1){
  if(br_kolona!=m1.br_kolona || br_redova!=m1.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
  *this=(*this)-m1;
  return *this;
  
  
 }
 template <typename TipEl>
Matrica<TipEl> & Matrica<TipEl>:: operator *=(TipEl broj){
  *this=broj*(*this);
  return *this;
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
 br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(m.elementi) {
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
std:: istream &  operator>>(std::istream &tok, Matrica<TipEl> &d) {
 for(int i = 0; i < d.br_redova; i++)
 for(int j = 0; j < d.br_kolona; j++) {
 std::cout << d.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
tok>> d.elementi[i][j];
 }
 return tok;
 }
template <typename TipEl>
 std:: ostream &  operator<<(std::ostream &tok, const Matrica<TipEl> &d) {
 	int razmak(tok.width());
 for(int i = 0; i < d.br_redova; i++) {
 for(int j = 0; j < d.br_kolona; j++)
 tok <<std::setw(razmak) << d.elementi[i][j];
tok << std::endl;
 }
 return tok;
 }
template <typename TipEl>
 Matrica<TipEl> operator+(const Matrica<TipEl> &m1,
 const Matrica<TipEl> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
 template <typename TipEl>
 Matrica<TipEl> operator-(const Matrica<TipEl> &m1,
 const Matrica<TipEl> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
 return m3;
 }
 template <typename TipEl>
 Matrica<TipEl> operator*(const Matrica<TipEl> &m1,
 const Matrica<TipEl> &m2){
  if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> mat3(m1.br_redova,m2.br_kolona);
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            TipEl suma=TipEl();
            for(int k=0;k<m1.br_kolona;k++){
                suma=suma+m1.elementi[i][k]*m2.elementi[k][j];
            }
            mat3.elementi[i][j]=suma;
        }
    }
    return mat3;
 }
 template <typename TipEl>
 std::string& Matrica<TipEl>:: operator=(std::string& s){
  
  s.push_back('{');
  for(int i=0;i<br_redova;i++){
   s.push_back('{');
   for(int j=0;j<br_kolona;j++){
    s+=std::to_string(int(elementi[i][j]));
    if(j!=br_kolona-1) s.push_back(',');
   }
   s.push_back('}');
   if(i!=br_redova-1) s.push_back(',');
  }
  return s;
 }
 template<typename TipEl>
  Matrica <TipEl>:: operator std::string() const {
   
  std::string s;
   s.push_back('{');
  for(int i=0;i<br_redova;i++){
   s.push_back('{');
   for(int j=0;j<br_kolona;j++){
    
    
 s+=std::to_string(int(elementi[i][j]));
    if(j!=br_kolona-1) s.push_back(',');
   }
   s.push_back('}');
   if(i!=br_redova-1) s.push_back(',');
  
  
 } s.push_back('}');
  return s;
 }
 template <typename TipEl>
 void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(std::string ime){
  std::ofstream izlazni_tok(ime);
  //if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
  for(int i=0;i<br_redova;i++){
   for(int j=0;j<br_kolona;j++){
   if(j!=br_kolona-1) izlazni_tok<<elementi[i][j]<<",";
   else izlazni_tok<<elementi[i][j]<<std::endl;
 if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
   }
  }
 }
 template <typename TipEl>
 void Matrica<TipEl>::SacuvajUBinarnuDatoteku(std::string ime){
  std::ofstream izlazni_tok(ime, std::ios::binary);
  izlazni_tok.write(reinterpret_cast<char*>(this), sizeof (*this));
  for(int i=0;i<br_redova;i++){

    izlazni_tok.write(reinterpret_cast<char*>(elementi[i]), sizeof(TipEl)*br_kolona);
   if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
  }
  
  
 }
 
 template <typename TipEl>
 void Matrica<TipEl>::ObnoviIzBinarneDatoteke(std::string ime){
  std::ifstream ulazni_tok(ime, std::ios::binary);
  if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
  int stvarni=br_redova,stvarni2=br_kolona;
  ulazni_tok.read(reinterpret_cast<char*>(this), sizeof *this);
  int pocetni(ulazni_tok.tellg());
  ulazni_tok.seekg(0, std::ios::end);
  int velicina(ulazni_tok.tellg());
  velicina=(velicina-pocetni)/sizeof(TipEl);
  
  if(velicina!=br_kolona*br_redova) { br_kolona=stvarni2;br_redova=stvarni;
   throw std::logic_error("Datoteka sadrzi besmislene podatke");}
   
  ulazni_tok.seekg(pocetni, std::ios::beg);
  
  for(int i=0;i<stvarni;i++) { delete[] elementi[i] ; elementi[i]=nullptr;}
  if(stvarni) {delete[] elementi; elementi=nullptr;}
 
  
  try{
   elementi=new TipEl*[br_redova]{};
   for(int i=0;i<br_redova;i++) elementi[i]=new TipEl[br_kolona];
   for(int i=0;i<br_redova;i++){
    for(int j=0;j<br_kolona;j++)
    ulazni_tok.read(reinterpret_cast<char*>(&elementi[i][j]), sizeof(TipEl));
   }
   
   
   
  }
  catch(...){
   for(int i=0;i<br_redova;i++) { delete [] elementi[i]; elementi[i]=nullptr;}
   delete [] elementi; elementi=nullptr; br_redova=0;
  }
  
 }
 template <typename TipEl>
 void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(std::string ime){
   
  std::ifstream ulazni_tok(ime);
  if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
  int broj_kolona(0), brojac(0),brojac2(1);
  TipEl pomocna;
  char znak;
ulazni_tok.seekg(0);
  
   for(;;){
     ulazni_tok>>pomocna;
    broj_kolona++;
    if(ulazni_tok.peek()!=',') break;
    else ulazni_tok>>znak;
    if(!ulazni_tok) break;
   
    
   }
 
   while(true){
     
    brojac=0;
    for(;;){
      
    ulazni_tok>>pomocna;
  if( (!ulazni_tok && !ulazni_tok.eof())) throw std::logic_error("Datoteka sadrzi besmislene podatke");
  else if(!ulazni_tok && ulazni_tok.eof()) {brojac2--; brojac=broj_kolona;break;}
    
     brojac++;
   
    if(ulazni_tok.peek()!=','){  break;}
   else ulazni_tok>>znak;
   if(znak!=',') throw std::logic_error("Datoteka sadrzi besmislene podatke");
   
   }
  
   brojac2++;
    if( (!ulazni_tok && !ulazni_tok.eof()) || brojac!=broj_kolona) throw std::logic_error("Datoteka sadrzi besmislene podatke");
    if(ulazni_tok.eof()) break;
   }
  ulazni_tok.clear();
  ulazni_tok.seekg(0);
  br_kolona=brojac;
  br_redova=brojac2;
   try{
   elementi=new TipEl*[br_redova]{};
   for(int i=0;i<br_redova;i++) elementi[i]=new TipEl[br_kolona];
    }
  catch(...){
   for(int i=0;i<br_redova;i++) delete [] elementi[i];
   delete [] elementi;
  }
  int i(0),j(0);
  while(true){
  j=0;
    for(;;){
    ulazni_tok>>elementi[i][j];
    
    
    j++;
    if(ulazni_tok.peek()!=',') break;
    ulazni_tok>>znak;
    if(!ulazni_tok) break;
    
   }i++;
   if(ulazni_tok.eof()) break;
   }
  
  }
  
 
int main() {
 
 int m, n;
 std::cout << "Unesi broj redova i kolona za matrice:\n";
 std::cin >> m >> n;
 try {
 Matrica<double> a(m, n, 'A'), b(m, n, 'B');
 std::cout << "Unesi matricu A:\n";
 std::cin>>a;
 std::cout << "Unesi matricu B:\n";
 std::cin>>b;
 a.SacuvajUTekstualnuDatoteku("Matrica.txt");
 b.ObnoviIzTekstualneDatoteke("Matrica.txt");
 std::cout<<"B matrica: "<<std::setw(5)<<b;
 
 std::cout << "Zbir ove dvije matrice je:\n";
 std::cout<<std::setw(5)<<a+b;
  std::cout << "Razlika ove dvije matrice je:\n";
 std::cout<<std::setw(5)<<a-b;
 try{
 std::cout << "Produkt ove dvije matrice je:\n";
 std::cout<<std::setw(5)<<a*b;}
 catch(...){};

 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 catch(std::logic_error){}
 
 try {
Matrica<double> a(2, 2, 'a');
a[0][0] = 10; a[0][1] = 2; 
a[1][0] = 4; a[1][1] = 5; 
std::cout<<std::setw(5)<<a;
std::string s; 
s = a; 

std::cout<<std::setw(5)<<a;
std::cout << s << std::endl;
const Matrica<double> b(a);
s=a;
std::cout << s << std::endl;
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
