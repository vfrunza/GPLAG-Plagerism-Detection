/B2017/2018: Zadaća 6, Zadatak 3

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;


template <typename TipEl>

 class Matrica {
  
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
 ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
 Matrica &operator =(const Matrica &m);
 Matrica &operator =(Matrica &&m);
 
 template <typename Tip1>
 friend std::istream &operator>>(std::istream &tok, Matrica<Tip1> &mat);
 
 template <typename Tip1>
 friend std::ostream &operator<<(std::ostream &tok, const Matrica<Tip1> &mat);
 
 template <typename Tip1>
 friend Matrica<Tip1> operator +(const Matrica<Tip1> &m1, const Matrica<Tip1> &m2);
 
 template <typename Tip1>
 friend Matrica<Tip1> operator -(const Matrica<Tip1> &m1, const Matrica<Tip1> &m2);
 
 TipEl *operator [](int i) const;
 
 TipEl operator ()(int i, int j) const; // za konstantne matrice ne vracamo referencu
 
 TipEl &operator ()(int i, int j);
 
 operator std::string () const;
 

 Matrica<TipEl> &operator -=(const Matrica <TipEl> &m2);
 
 Matrica<TipEl> &operator +=(const Matrica <TipEl> &m2);
 
 Matrica<TipEl> &operator *=(const Matrica <TipEl> &m2);
 
 Matrica<TipEl> &operator *=(double skalar);
 
 template <typename Tip1>
 friend Matrica<Tip1> operator *(const Matrica<Tip1> &m1, const Matrica<Tip1> &m2);
 
 template <typename Tip1>
 friend Matrica <Tip1> operator *(const Matrica <Tip1> &m, double a);
 
 //nove metode...
 void SacuvajUTekstualnuDatoteku(const std::string &ime_datoteke) const;
 void SacuvajUBinarnuDatoteku(const std::string &ime_datoteke) const;
 void ObnoviIzTekstualneDatoteke(const std::string &ime_datoteke);
 void ObnoviIzBinarneDatoteke(const std::string &ime_datoteke);
 
 Matrica(const std::string &ime_datoteke, bool iz_binarne);
 
 
 };
 
//..............................................................................

template<typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(const std::string &ime_datoteke) const{
    
    std::ofstream izlazni_tok(ime_datoteke);
    if(!izlazni_tok) throw std::logic_error ("Datoteka ne postoji");
    
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            if(j!=br_kolona-1)
            izlazni_tok<<elementi[i][j]<<",";
            else izlazni_tok<<elementi[i][j]<<endl;//da li nakon posljednjeg elementa ide novi red???
            if(!izlazni_tok) break;
        }
        if(!izlazni_tok) break;
    }
    
    if(!izlazni_tok) { izlazni_tok.close(); throw std::logic_error("Problemi sa upisom u datoteku"); }
        izlazni_tok.close();
    
}

template<typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(const std::string &ime_datoteke) const{
 
 std::ofstream izlazni_tok (ime_datoteke, std::ios::binary);
 if(!izlazni_tok) { izlazni_tok.close(); throw std::logic_error ("Datoteka ne postoji");}
 
 izlazni_tok.write(reinterpret_cast<const char*> (this), sizeof *this);
  if(!izlazni_tok) { izlazni_tok.close(); throw std::logic_error("Problemi sa upisom u datoteku"); }
 
 for(int i=0;i<br_redova;i++){
 //while(izlazni_tok)
  izlazni_tok.write(reinterpret_cast<char*>(elementi[i]),br_kolona*sizeof(TipEl));
 }
  
  
  if(!izlazni_tok) { izlazni_tok.close(); throw std::logic_error("Problemi sa upisom u datoteku"); }
 
 izlazni_tok.close();
 
}

template<typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(const std::string &ime_datoteke){
 
 std::ifstream ulazni_tok(ime_datoteke);// citamo iz datoteke i provjeravamo je li sve OK
 
 if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");

 char znak;// moze biti zarez, novi red, razmak ili EOF
 TipEl clan;
 int br_redova(0),br_kolona(0),konst_br_kolona(0);
 
 
 while(ulazni_tok>>clan){
 
  if((znak=ulazni_tok.get())!=EOF){
   if(znak!=',' && znak!='\n') { ulazni_tok.setstate(std::ios_base::failbit); break; }  // moze biti razmak izmedju brojeva
   
   //if(znak==',' && novi_znak!='\n') { ulazni_tok.setstate(std::ios_base::failbit); break; }
   br_kolona++;
   if(br_redova==0) konst_br_kolona++;
   
  }
  else if(znak==EOF) { 
   br_kolona++; 
   if(br_redova==0) konst_br_kolona++; 
   if(br_kolona!=konst_br_kolona){  ulazni_tok.setstate(std::ios_base::failbit); break; }
  br_redova++; break; 
   
  }
  if(znak=='\n' && br_kolona!=konst_br_kolona){ ulazni_tok.setstate(std::ios_base::failbit); break; }
  if(znak=='\n') { br_redova++; br_kolona=0;}
 }
 
 if(!ulazni_tok && !ulazni_tok.eof() && !ulazni_tok.bad())  { ulazni_tok.close(); throw std::logic_error("Datoteka sadrzi besmislene podatke");}
 if(ulazni_tok.bad()) { ulazni_tok.close(); throw std::logic_error("Problemi pri citanju datoteke");}
 
 ulazni_tok.close();
 
 //sve je OK sa datotekom, brisemo stari sadrzaj...
  
  for(int i=0;i<br_redova;i++) delete[] elementi[i]; 
  delete[] elementi;
  
  //i pravimo mjesto za novi...
  
  this->br_redova=br_redova;
  this->br_kolona=konst_br_kolona;
  
  elementi = new TipEl*[br_redova];
  for(int i=0;i<br_redova;i++) elementi[i]=new TipEl[konst_br_kolona];
  
 //ponovo citamo iz datoteke...
 
 ulazni_tok.open(ime_datoteke);
 
 int i(0),j(0);
 
 while(ulazni_tok>>clan){
  
  if((znak=ulazni_tok.get())!=EOF){
   if(znak==','){
   elementi[i][j]=clan;
   j++;
   }
   else if(znak=='\n') {
    elementi[i][j]=clan;
    i++;
    j=0;
  }
  }
  else if(znak==EOF) { elementi[i][j]=clan;}
  
  //if(znak=='\n') { br_redova++; br_kolona=0; }
 }
  
 ulazni_tok.close();
 
 
 
}

template<typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(const std::string &ime_datoteke){
 
 std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
  if(!ulazni_tok) throw std::logic_error ("Trazena datoteka ne postoji");
  
  for(int i=0;i<br_redova;i++)
   delete[] elementi[i];
  
  delete[] elementi;
  
  ulazni_tok.read(reinterpret_cast<char*>(this),sizeof *this);
  if(!ulazni_tok) { ulazni_tok.close(); throw std::logic_error("Problemi pri citanju datoteke"); }
  
  elementi=new TipEl*[br_redova];
  
  for(int i=0;i<br_redova;i++) elementi[i]=nullptr;
  
  for(int i=0;i<br_redova;i++) {
  elementi[i]=new TipEl[br_kolona];
  ulazni_tok.read(reinterpret_cast<char*>(elementi[i]),br_kolona*sizeof(TipEl));
  if(!ulazni_tok) break;
  }
  
  if(!ulazni_tok) {
   
   for(int i=0;i<br_redova;i++)
   delete[] elementi[i];
  
  delete[] elementi;
   ulazni_tok.close(); 
   throw std::logic_error("Problemi pri citanju datoteke");
   
  }
  
  ulazni_tok.close();
 
}

template<typename TipEl>
Matrica<TipEl>::Matrica(const std::string &ime_datoteke, bool iz_binarne){
  
  if(iz_binarne){
   
  std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
  if(!ulazni_tok) throw std::logic_error ("Trazena datoteka ne postoji");
  //...........
  
 ulazni_tok.read(reinterpret_cast<char*>(this),sizeof *this);
  if(!ulazni_tok) { ulazni_tok.close(); throw std::logic_error("Problemi pri citanju datoteke"); }
  
  elementi=new TipEl*[br_redova];
  
  for(int i=0;i<br_redova;i++) elementi[i]=nullptr;
  
  for(int i=0;i<br_redova;i++) {
  elementi[i]=new TipEl[br_kolona];
  ulazni_tok.read(reinterpret_cast<char*>(elementi[i]),br_kolona*sizeof(TipEl));
  if(!ulazni_tok) break;
  }
  
  if(!ulazni_tok) {
   
   for(int i=0;i<br_redova;i++)
   delete[] elementi[i];
  
  delete[] elementi;
   ulazni_tok.close(); 
   throw std::logic_error("Problemi pri citanju datoteke");
   
  }
  
  ulazni_tok.close();
  
  }
  
  else{
   
   std::ifstream ulazni_tok(ime_datoteke);// citamo iz datoteke i provjeravamo je li sve OK
 
 if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");

 char znak;
 TipEl clan;
 int br_redova(0),br_kolona(0),konst_br_kolona(0);
 
 
 while(ulazni_tok>>clan){
 
  if((znak=ulazni_tok.get())!=EOF){
   if(znak!=',' && znak!='\n') { ulazni_tok.setstate(std::ios_base::failbit); break; }  // moze biti razmak izmedju brojeva
   
   //if(znak==',' && novi_znak!='\n') { ulazni_tok.setstate(std::ios_base::failbit); break; }
   br_kolona++;
   if(br_redova==0) konst_br_kolona++;
   
  }
  else if(znak==EOF) { 
   br_kolona++; 
   if(br_redova==0) konst_br_kolona++; 
   if(br_kolona!=konst_br_kolona){  ulazni_tok.setstate(std::ios_base::failbit); break; }
  br_redova++; break; 
   
  }
  if(znak=='\n' && br_kolona!=konst_br_kolona){ ulazni_tok.setstate(std::ios_base::failbit); break; }
  if(znak=='\n') { br_redova++; br_kolona=0;}
 }
 
 if(!ulazni_tok && !ulazni_tok.eof() && !ulazni_tok.bad())  { ulazni_tok.close(); throw std::logic_error("Datoteka sadrzi besmislene podatke");}
 if(ulazni_tok.bad()) { ulazni_tok.close(); throw std::logic_error("Problemi pri citanju datoteke");}
 
 ulazni_tok.close();  
 
 this->br_redova=br_redova;
 this->br_kolona=konst_br_kolona;
 
 elementi = new TipEl*[br_redova];
  for(int i=0;i<br_redova;i++) elementi[i]=new TipEl[konst_br_kolona];
  
 //ponovo citamo iz datoteke...
 
 ulazni_tok.open(ime_datoteke);
 
 int i(0),j(0);
 
 while(ulazni_tok>>clan){
  
  if((znak=ulazni_tok.get())!=EOF){
   if(znak==','){
   elementi[i][j]=clan;
   j++;
   }
   else if(znak=='\n') {
    elementi[i][j]=clan;
    i++;
    j=0;
  }
  }
  else if(znak==EOF) { elementi[i][j]=clan; break;}
  
  //if(znak=='\n') { br_redova++; br_kolona=0; }
 }
  
 ulazni_tok.close();
 
 
 
   
  }
  
 }
 
//------------------------------------------------------------------------------


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
 void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) { //!!!!
 for(int i = 0; i < br_redova; i++) delete[] elementi[i];
 delete[] elementi;
 }
 
  
template <typename TipEl>
 void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++)
 Matrica::elementi[i][j] = elementi[i][j];
 }
 
 
template <typename TipEl>
 Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : // konstruktor
 br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
 elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
 

 
template <typename TipEl>
 Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), //kopirajuci konstruktor
 br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
 elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) { KopirajElemente(m.elementi); }
 
 
template <typename TipEl>
 Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), // pomjerajuci konstruktor
 br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice) { m.br_redova = 0; m.elementi = nullptr; }
 
 
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
 } // kopirajuci operator dodjele
 
 
template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
 std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
 std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
 return *this;
 } // pomjerajuci operator dodjele
 
 //..............................
 
 
 
template <typename TipEl>
 std::istream &operator >>(std::istream &tok, Matrica<TipEl> &mat) {
 for(int i = 0; i < mat.br_redova; i++){
 for(int j = 0; j < mat.br_kolona; j++) {
 std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
 tok>> mat.elementi[i][j];
 }
 }
 return tok;
 }
 
 
template <typename TipEl>
 std::ostream &operator <<(std::ostream &tok,const Matrica<TipEl> &mat) {
  
  int sirina_ispisa=tok.width();
  
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 tok << std::setw(sirina_ispisa) << mat.elementi[i][j];
 tok << std::endl;
 }
 return tok;
 }
 
  
 template <typename TipEl>
 TipEl *Matrica<TipEl>:: operator [](int i) const{
  
  if(i<0 || i>=br_redova) throw std::range_error("Neispravan indeks");
  
  return elementi[i];

 }
 
 
 template <typename TipEl>
 TipEl Matrica<TipEl>:: operator ()(int i, int j) const{
  
  if( (i-1)<0 || (j-1)<0 || (j-1)>=br_kolona || (i-1)>= br_redova) throw std::range_error("Neispravan indeks");
  
  return elementi[i-1][j-1];
  
 }
 
  
 template <typename TipEl>
 TipEl &Matrica<TipEl>:: operator ()(int i, int j) {
  
  if( (i-1)<0 || (j-1)<0 || (j-1)>=br_kolona || (i-1)>= br_redova) throw std::range_error("Neispravan indeks");
  
  return elementi[i-1][j-1];
  
 }
 
 template <typename TipEl>
 Matrica<TipEl>::operator std::string () const
 {
  std::string pretvoreno_u_string;
  
  pretvoreno_u_string="{"; // bez+=
  
  for(int i=0;i<br_redova;i++){
   pretvoreno_u_string+="{";
   
   for(int j=0;j<br_kolona;j++){
    if(j+1!=br_kolona) pretvoreno_u_string+=std::to_string(int(elementi[i][j]))+",";
    else pretvoreno_u_string+=std::to_string(int(elementi[i][j]));
    
   }
   if(i+1!=br_redova) pretvoreno_u_string+="},";
   else pretvoreno_u_string+="}";
  }
  
  pretvoreno_u_string+="}";
  
  return pretvoreno_u_string;
 }
 
 template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>:: operator -=(const Matrica <TipEl> &m2){
  
  if(br_redova!=m2.br_redova || br_kolona!= m2.br_kolona) 
  throw std::domain_error("Matrice nemaju jednake dimenzije!");
  
  for(int i=0;i<br_redova;i++)
  for(int j=0;j<br_kolona;j++)
  elementi[i][j]-=m2.elementi[i][j];
  
  return *this;
 }
 
 template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>::operator +=(const Matrica<TipEl> &m2){
  
  if(br_redova!=m2.br_redova || br_kolona!=m2.br_kolona)
  throw std::domain_error("Matrice nemaju jednake dimenzije!");
  

  for(int i=0;i<br_redova;i++)
  for(int j=0;j<br_kolona;j++)
  elementi[i][j]+=m2.elementi[i][j];
  
  return *this;
  
 }
 
 template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>::operator *=(const Matrica<TipEl> &m2){
 
 if(br_kolona!=m2.br_redova)
  throw std::domain_error("Matrice nisu saglasne za mnozenje!");
  
  auto pom(*this);
  
  
  for(int i=0;i<br_redova;i++){
   for(int j=0;j<m2.br_kolona;j++){
    double suma(0); 
    
    for(int k=0;k<m2.br_kolona;k++)
     suma=suma+(pom.elementi[i][k] * m2.elementi[k][j]);
    
    elementi[i][j]=suma;
   }
   
  }
 
  
  
  return *this;
  
 }
 
 template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>::operator *=(double skalar){
  
  for(int i=0;i<br_redova;i++)
  for(int j=0;j<br_kolona;j++)
  elementi[i][j]*=skalar;
  
  return*this;
  
 }
 
  
template <typename TipEl>
 Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 
 auto pom(m1);
 pom+=m2;
 return pom;
 }
 
 template <typename Tip2>
 Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2){
  
  if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
  throw std::domain_error("Matrice nemaju jednake dimenzije!");
 
  auto pom(m1);
  pom-=m2;
  return pom;
  
 }
 
 template <typename TipEl>
 Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2){
  
   if(m1.br_kolona!=m2.br_redova)
  throw std::domain_error("Matrice nisu saglasne za mnozenje");
  
  auto pom_matrica(m1);
  
  pom_matrica*=m2;
  
  return pom_matrica;
 
  
 }
 
  
 template <typename TipEl>
 Matrica <TipEl> operator *(const Matrica <TipEl> &m, double a){
  
  Matrica <TipEl> pom(m);
  
  pom*=a;
  
  return pom;
 }
 
 template <typename TipEl>
 Matrica <TipEl> operator *(double a, const Matrica <TipEl> &m ){
  
  Matrica <TipEl> pom(m);
  
  pom*=a;
  
  return pom;
  
 }

int main ()
{
 
 //AT4 - testiranje konstruktora za učitavanje iz binarne datoteke
    
    try
    {
        Matrica<int> m0{2, 2};
        for (int i{0}; i < 2; i++)
            for (int j{0}; j < 2; j++)
                m0[i][j] = i + j;
        m0.SacuvajUBinarnuDatoteku("matrica1.DAT");
        Matrica<int> m1("matrica1.DAT", true);
        std::cout << std::setw(6) << m1;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
    std::cout << std::endl << std::endl;
    
    try
    {
        Matrica<double> m0{2, 2};
        for (int i{0}; i < 2; i++)
            for (int j{0}; j < 2; j++)
                m0[i][j] = i + j + 0.5;
        m0.SacuvajUBinarnuDatoteku("matrica2.DAT");
        Matrica<double> m1("matrica2.DAT", true);
        std::cout << std::setw(6) << m1;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    
 
	return 0;
}
