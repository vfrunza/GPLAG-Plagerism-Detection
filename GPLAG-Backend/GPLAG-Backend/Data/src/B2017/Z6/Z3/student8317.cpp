/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include<fstream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include<string>


template <typename TipEl>

 class Matrica {
 int br_redova, br_kolona;
 TipEl **elementi;
 char ime_matrice;
 static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
 static void DealocirajMemoriju(TipEl **elementi, int br_redova);
 void KopirajElemente(TipEl **elementi);
 void Test(int i,int j) const{
  if(i<=0 || j<=0 || i>br_redova || j>br_kolona)
  throw std::range_error("Neispravan indeks");
 }
 public:
 Matrica(int br_redova, int br_kolona, char ime = 0);
 Matrica(const Matrica &m);
 Matrica(Matrica &&m);
 Matrica(std::string ime,bool logvrijednost);
 ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
 Matrica &operator =(const Matrica &m);
 Matrica &operator =(Matrica &&m);
 int DajBrojRedova() const{return br_redova;}
 int DajBrojKolona() const{return br_kolona;}
 TipEl**DajElemente() const{return this->elementi;}
 char DajImeMatrice() const{return this->ime_matrice;}
void SacuvajUTekstualnuDatoteku(std::string ime) const;
void SacuvajUBinarnuDatoteku(std::string ime) const;
void ObnoviIzTekstualneDatoteke(std::string ime);
void ObnoviIzBinarneDatoteke(std::string ime);
 TipEl &operator()(int i,int j){Test(i,j); return elementi[i-1][j-1];}
 TipEl operator() (int i,int j) const {Test(i,j); return elementi[i-1][j-1];}
 operator std::string() const;
 const TipEl*  operator[](int j) const {return elementi[j];}
 TipEl* operator[](int j){return elementi[j];}
 };
template <typename TipEl>
Matrica<TipEl>::operator std::string() const{
 std::string s;
 auto elementi=DajElemente();
 s='{'; //jednostruki
 for(int i=0;i<DajBrojRedova();i++)
 {
  s+='{';
  for(int j=0;j<DajBrojKolona();j++)
  {
   s+=std::to_string(int(elementi[i][j]));
   if(j==DajBrojKolona()-1) s+="}";
   if(j!=DajBrojKolona()-1) s+=',';
  }
  if(i!=DajBrojRedova()-1) s+=",";
 }
 s.push_back('}');
 return s;
}
template<typename TipEl>
std::istream &operator >>(std::istream &unesi,Matrica<TipEl> &m)
{
 auto elementi=m.DajElemente();
 for(int i=0;i<m.DajBrojRedova();i++)
 {
  for(int j=0;j<m.DajBrojKolona();j++)
  {
   std::cout<<m.DajImeMatrice()<<"("<<i+1<<","<<j+1<<") = ";
   unesi>>elementi[i][j];
  }
 }
 return unesi;
}
template<typename TipEl>
std::ostream &operator <<(std::ostream &tok,const Matrica<TipEl> &m)
{
 int sirina_ispisa=tok.width();
 auto elementi=m.DajElemente();
 for(int i=0;i<m.DajBrojRedova();i++)
 {
  for(int j=0;j<m.DajBrojKolona();j++)
  tok<<std::setw(sirina_ispisa)<<elementi[i][j];
  tok<<std::endl;
 }
 return tok;
}
template<typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
 if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 Matrica<TipEl>m3(m1.DajBrojRedova(),m1.DajBrojKolona());
 auto elementi3=m3.DajElemente();
 auto elementi2=m2.DajElemente();
 auto elementi1=m1.DajElemente();
 for(int i=0;i<m1.DajBrojRedova();i++)
 for(int j=0;j<m1.DajBrojKolona();j++)
 elementi3[i][j]=elementi1[i][j]+elementi2[i][j];
 return m3;
}
template<typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
 if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 Matrica<TipEl>m3(m1.DajBrojRedova(),m1.DajBrojKolona());
 auto elementi3=m3.DajElemente();
 auto elementi2=m2.DajElemente();
 auto elementi1=m1.DajElemente();
 for(int i=0;i<m1.DajBrojRedova();i++)
 for(int j=0;j<m1.DajBrojKolona();j++)
 elementi3[i][j]=elementi1[i][j]-elementi2[i][j];
 return m3;
}
template<typename TipEl>
Matrica<TipEl> operator -=(Matrica<TipEl> &m1,const Matrica<TipEl>&m2)
{
 if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 m1=m1-m2;
 return m1;
}
template<typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
 if(m1.DajBrojRedova()!=m2.DajBrojKolona())
 throw std::domain_error("Matrice nisu saglasne za mnozenje");
 Matrica<TipEl>m3(m1.DajBrojRedova(),m2.DajBrojKolona());
auto elementi3=m3.DajElemente();
auto elementi2=m2.DajElemente();
 auto elementi1=m1.DajElemente();
 for(int i=0;i<m1.DajBrojRedova();i++)
 {
  for(int j=0;j<m2.DajBrojKolona();j++)
  {
   elementi3[i][j]=0;
   for(int k=0;k<m1.DajBrojRedova();k++)
   {
    elementi3[i][j]=elementi3[i][j]+(elementi1[i][k]*elementi2[k][j]);
   }
   
  }
 }
 return m3;
}

template<typename TipEl>
Matrica<TipEl> operator *=(Matrica<TipEl> &m1,const Matrica<TipEl>&m2)
{
 if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 m1=m1*m2;
 return m1;}
template<typename TipEl>
Matrica<TipEl> operator +=(Matrica<TipEl> &m1,const Matrica<TipEl>&m2)
{
 if(m1.DajBrojRedova()!=m2.DajBrojRedova() || m1.DajBrojKolona()!=m2.DajBrojKolona())
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 m1=m1+m2;
 return m1;
}
template<typename TipEl>
Matrica<TipEl> operator *(int n,const Matrica<TipEl>&m1)
{
 Matrica<TipEl>m3(m1.DajBrojRedova(),m1.DajBrojKolona());
 auto elementi3=m3.DajElemente();
 auto elementi1=m1.DajElemente();
 for(int i=0;i<m1.DajBrojRedova();i++)
 for(int j=0;j<m1.DajBrojKolona();j++)
 elementi3[i][j]=n*elementi1[i][j];
 return m3;
}
template<typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl>&m1,int n)
{
 Matrica<TipEl>m3(m1.DajBrojRedova(),m1.DajBrojKolona());
 auto elementi3=m3.DajElemente();
 auto elementi1=m1.DajElemente();
 for(int i=0;i<m1.DajBrojRedova();i++)
 for(int j=0;j<m1.DajBrojKolona();j++)
 elementi3[i][j]=n*elementi1[i][j];
 return m3;
}
template<typename TipEl>
Matrica<TipEl> operator *=(int n,Matrica<TipEl> &m1)
{
 m1=n*m1;
 return m1;
}
template<typename TipEl>
Matrica<TipEl> operator *=(Matrica<TipEl> &m1,int n)
{
 m1=n*m1;
 return m1;
}


//konstruktor

template<typename TipEl>
Matrica<TipEl>::Matrica(std::string ime,bool logvrijednost)
{
 if(logvrijednost==true) //za binarnu
 {
  std::ifstream tok(ime,std::ios::binary);
  if(!tok) 
  throw std::logic_error("Trazena datoteka ne postoji");
  tok.read(reinterpret_cast<char*>(this),sizeof *this);
  elementi=new TipEl* [br_redova];
  for(int i=0;i<br_redova;i++)
  elementi[i]=nullptr;
  for(int j=0;j<br_redova;j++)
  {
   elementi[j]=new TipEl[br_kolona];
   tok.read(reinterpret_cast<char*>(elementi[j]),br_kolona*sizeof(TipEl));
  }
  if(!tok)
  {
   for(int i=0;i<br_redova;i++)
   delete [] elementi[i];
   delete [] elementi;
   throw std::logic_error("Problemi pri citanju datoteke");
  }
 }
 else //za tekstualnu
 {
  std::ifstream tok(ime);
  if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
  int redovi(0);
  int kolone(0);
  int brojk;
  char znak;
  bool prvi(true);
  TipEl vrijednost;
  for(;;)
  {
   if(!tok)
   break;
   for(;;)
   {
    if(!tok)
    break;
    tok>>vrijednost;
    if(tok.peek()==',')
    {
     tok.get();
     kolone++;
    }
    else if(tok.peek()=='\n')
    {
     kolone++; break;
    }
   }
   if(!tok) break;
   redovi++;
   if(prvi==true)
   {
    brojk=kolone;
    kolone=0;
    prvi=false;
   }
   else
   {
    if(kolone!=brojk)
    throw std::logic_error("Datoteka sadrzi besmislene podatke");
    kolone=0;
   }
  }
  if(!tok && tok.bad())
  throw std::logic_error("Problem pri citanju datoteke");
  if(!tok && !tok.eof())
  throw std::logic_error("Datoteka sadrzi besmislene podatke");
  else if(!tok && tok.eof())
  tok.clear();
  tok.close();
  tok.open(ime);
  
  //kolone i redovi
br_kolona=brojk;
br_redova=redovi+1;

  
  //alociranje
  elementi=new TipEl*[br_redova];
  for(int i=0;i<br_redova;i++)
  elementi[i]=new TipEl[br_kolona];
  for(int i=0;i<br_redova;i++)
  {
   for(int j=0;j<br_kolona;j++)
   {
    tok>>elementi[i][j];
    if(j<br_kolona-1) tok.get();
   }
  }
 }
}

template<typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(std::string ime)const
{
 std::ofstream tok(ime);
 if(!tok) 
 throw std::logic_error("Problem sa upisom u datoteku");
 for(int i=0;i<br_redova;i++)
 {
  for(int j=0;j<br_kolona;j++)
  {
   if(j==br_kolona-1) 
   //zadni element
   tok<<elementi[i][j];
   else
   tok<<elementi[i][j]<<",";
   if(!tok)
   throw std::logic_error("Problemi sa upisom u datoteku");
  }
  tok<<std::endl;
 }
}
template<typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(std::string ime)
{
 std::ifstream tok(ime);
 if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
 //for(int i=0;i<br_redova;i++)
/* delete [] elementi[i];
 delete [] elementi;*/
 
 int redovi(0);
  int kolone(0);
  int brojk;
  char znak;
  bool prvi(true);
  TipEl vrijednost;
  
  for(;;)
  {
   if(!tok)
   break;
   for(;;)
   {
    tok>>vrijednost;
    if(!tok)
    break;
    if(tok.peek()==',')
    {
     tok.get();
     kolone++;
    }
    else if(tok.peek()=='\n')
    {
     kolone++; 
     
     break;
    }
   }
   if(!tok) break;
   redovi++;
   if(prvi==true)
   {
    brojk=kolone;
    kolone=0;
    prvi=false;
   }
   else
   {
    if(kolone!=brojk)
    throw std::logic_error("Datoteka sadrzi besmislene podatke");
    kolone=0;
   }
  }
  if(!tok && tok.bad())
  throw std::logic_error("Problem pri citanju datoteke");
  if(!tok && !tok.eof())
  throw std::logic_error("Datoteka sadrzi besmislene podatke");
  else if(!tok && tok.eof())
  tok.clear();
  tok.close();
  tok.open(ime);
  
  //kolone i redovi
br_kolona=brojk;
br_redova=redovi+1;

  
  //alociranje
  elementi=new TipEl*[br_redova];
  for(int i=0;i<br_redova;i++)
  elementi[i]=new TipEl[br_kolona];
  for(int i=0;i<br_redova;i++)
  {
   for(int j=0;j<br_kolona;j++)
   {
    tok>>elementi[i][j];
}
}
}
template<typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(std::string ime)const
{
 std::ofstream tok(ime,std::ios::binary);
 tok.write((char*)this,sizeof(*this));
 for(int i=0;i<br_redova;i++)
 tok.write((char*)elementi[i],br_kolona*sizeof(TipEl));
 if(!tok) throw std::logic_error("Problemi sa upisom u datoteku");
}
template<typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(std::string ime)
{
 std::ifstream tok(ime,std::ios::binary);
 if(!tok)
 throw std::logic_error("Trazena datoteka ne postoji");
 //oslobadjanje
 for(int i=0;i<br_redova;i++)
 delete [] elementi[i];
 delete [] elementi;
 
  tok.read(reinterpret_cast<char*>(this),sizeof *this);
  elementi=new TipEl* [br_redova];
  for(int i=0;i<br_redova;i++)
  elementi[i]=nullptr;
  for(int j=0;j<br_redova;j++)
  {
   elementi[j]=new TipEl[br_kolona];
   tok.read(reinterpret_cast<char*>(elementi[j]),br_kolona*sizeof(TipEl));
  }
  if(!tok)
  {
   for(int i=0;i<br_redova;i++)
   delete [] elementi[i];
   delete [] elementi;
   throw std::logic_error("Problemi pri citanju datoteke");
}
}
template<typename TipEl>
 TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
 TipEl **elementi(new TipEl*[br_redova+1]{});
 try {
 for(int i = 0; i < br_redova; i++) 
 elementi[i] = new TipEl[br_kolona] {};
 }
 catch(...) {
 DealocirajMemoriju(elementi, br_redova); 
 throw;
 }
 return elementi;
 }
template <typename TipEl>
 void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
 for(int i = 0; i < br_redova; i++) 
 delete[] elementi[i];
 delete[] elementi;
 }
template <typename TipEl>
 Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
 
template <typename TipEl>
 void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
 for(int i = 0; i < br_redova; i++)
 for(int j = 0; j < br_kolona; j++)
 Matrica::elementi[i][j] = elementi[i][j];
 }
template <typename TipEl>
 Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
 KopirajElemente(m.elementi);
 }
template <typename TipEl>
 Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice) {
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
 br_redova = m.br_redova; 
 br_kolona = m.br_kolona;
 ime_matrice = m.ime_matrice;
 KopirajElemente(m.elementi);
 return *this;
 }
template <typename TipEl>
 Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
 std::swap(br_redova, m.br_redova);
 std::swap(br_kolona, m.br_kolona);
 std::swap(ime_matrice, m.ime_matrice); 
 std::swap(elementi, m.elementi);
 return *this;
 }

int main() {
 Matrica<int>m(2,3);
 for(int i=0;i<2;i++)
 for(int j=0;j<3;j++)
 m[i][j]=1;
 
 m.SacuvajUBinarnuDatoteku("MATRICA.TXT");
 Matrica<int>mat(2,2);
 mat.ObnoviIzBinarneDatoteke("MATRICA.TXT");
 std::cout<<mat;
 /*int m, n;
 std::cout << "Unesi broj redova i kolona za matrice:\n";
 std::cin >> m >> n;
 try {
Matrica<double> a(m, n, 'A'), b(m, n, 'B');
std::cout << "Unesi matricu A:\n";
std::cin >> a;
std::cout << "Unesi matricu B:\n";
std::cin >> b;
std::cout << "Zbir ove dvije matrice je:\n";
std::cout << std::setw(7) << a + b;

 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }*/
 return 0;
}
