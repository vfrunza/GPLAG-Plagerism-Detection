#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include<sstream>
#include<fstream>
#include<vector> 
template<typename Tip>
std::string Pretvori(Tip x){
 std::ostringstream s;
 s<<x;
 return s.str();
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
Matrica(int br_redova, int br_kolona, char ime = 0);
Matrica(const Matrica &m);
Matrica(Matrica &&m);
Matrica(std::string ime_dat,bool bin_tek){
    
    if(bin_tek==false){
       std::ifstream citaj_iz_dat(ime_dat,std::ios::in);
    if(!citaj_iz_dat) throw std::logic_error("Trazena datoteka ne postoji");
    //throw std::logic_error("Datoteka sadrzi besmislene podatke");
    br_redova=0;
    br_kolona=0;
    char znak;

    TipEl e;
    std::vector<std::vector<TipEl>> v;
    int i=0,j=0;
    for(i=0;;i++){
        v.resize(i+1);
        for(j=0;;j++){
        citaj_iz_dat>>e;
        if(!citaj_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        v.at(i).push_back(e);
        if(citaj_iz_dat.eof()) break;
        if(citaj_iz_dat.peek()!=',') break;
            citaj_iz_dat>>znak;
            if(!citaj_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
          if(citaj_iz_dat.eof()) break;
        }
        if(citaj_iz_dat.eof()) break;
    }
    br_kolona=j+1;
    br_redova=i+1;
    elementi=AlocirajMemoriju(br_redova,br_kolona);
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            elementi[i][j]=v[i][j];
        }
    }
    }
    if(bin_tek==true){
        std::ifstream citaj_iz_dat(ime_dat,std::ios::in | std::ios::binary);
    if(!citaj_iz_dat) throw std::logic_error("Trazena datoteka ne postoji");
    
    br_redova=0;
    br_kolona=0;
    char znak;
    TipEl e;
    std::vector<std::vector<TipEl>> v;
    int i=0,j=0;
    for(i=0;;i++){
        v.resize(i+1);
        for(j=0;;j++){
            
        citaj_iz_dat.read(reinterpret_cast<char*>(&e),sizeof e);
        if(!citaj_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        
        v.at(i).push_back(e);
        if(citaj_iz_dat.peek()!=',') break;
            citaj_iz_dat.read(reinterpret_cast<char*>(&znak),sizeof znak);
            if(!citaj_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
    }
    br_kolona=j+1;
    br_redova=i+1;
    elementi=AlocirajMemoriju(br_redova,br_kolona);
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            elementi[i][j]=v[i][j];
        }
    }
    }
}
~Matrica() { DealocirajMemoriju(elementi, br_redova); }
Matrica &operator =(const Matrica &m);
Matrica &operator =(Matrica &&m);
template <typename Tip2>
friend std::istream&  operator>> (std:: istream& tok,const Matrica<Tip2> &m1);

template <typename Tip2>
friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1,
const Matrica<Tip2> &m2);
template <typename Tip2>
friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);

TipEl *operator [](int i) const{
return elementi[i];
}
TipEl &operator ()(int i,int j) const{
 if(i<1 or j<1) throw std::range_error("Neispravan indeks");
return elementi[i-1][j-1];
}

 Matrica<TipEl> operator *(const Matrica<TipEl> &b)
 {
  if(br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  int m=br_redova,n=b.br_kolona;
  Matrica<TipEl> c(m,n,'c');
   for(int i=0;i<m;i++)
  {
   for(int j=0;j<n;j++)
   c.elementi[i][j]=0;
  }
  for(int i=0;i<br_redova;i++)
  {
   for(int j=0;j<b.br_kolona;j++)
   {
    
    for(int l=0;l<br_kolona;l++)
    {
     c.elementi[i][j]+=elementi[i][l]*b.elementi[l][j];
    }
    
   }
  }
  return c;
 }
 Matrica<TipEl> operator *=(const Matrica<TipEl> &b)
 {
  if(br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  int m=br_redova,n=b.br_kolona;
    Matrica<TipEl> c(m,n,'c');
   for(int i=0;i<m;i++)
  {
   for(int j=0;j<n;j++)
   c.elementi[i][j]=0;
  }
  for(int i=0;i<br_redova;i++)
  {
   for(int j=0;j<b.br_kolona;j++)
   {
    
    for(int l=0;l<br_kolona;l++)
    {
     c.elementi[i][j]+=elementi[i][l]*b.elementi[l][j];
    }
    
   }
  }
  *this=c;
  return *this;
 }
 template<typename Tipk>
friend Matrica<Tipk> operator *(const Matrica<Tipk> &a,int b);
template<typename Tip>
friend Matrica<Tip> operator *(int b,const Matrica<Tip> &a);
template<typename Tip>
friend Matrica<Tip> operator *=(int b, Matrica<Tip> &a);
template<typename Tip>
friend Matrica<Tip> operator *=(Matrica<Tip> &a,int b);
 template <typename Tip>
friend Matrica<Tip> operator +=(const Matrica<Tip> &m1,const Matrica<Tip> &m2);
 template <typename Tip2>
friend Matrica<Tip2> operator -=(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
 template <typename Tip2>
friend std::ostream& operator<<(std::ostream& tok,const Matrica<Tip2> &m1);
operator std::string() const{
 std::string s; 
 s+="{";
 for(int i = 0; i < br_redova; i++){
  if(i!=0)
  s+=",{";
  else 
  s+="{";
for(int j = 0; j < br_kolona; j++){
 if(j!=0) s+=",";
 s+=Pretvori(elementi[i][j]);
}
s+="}";
}
s+="}";
return s;
}
void SacuvajUTekstualnuDatoteku(std::string ime_dat){
    std::ofstream pisi_u_dat(ime_dat,std::ios::app);
    int m=br_redova,n=br_kolona;
   for(int i=0;i<m;i++)
  {
      pisi_u_dat<<elementi[i][0];
   for(int j=1;j<n;j++)
   {
       pisi_u_dat<<','<<elementi[i][j];
   }
   pisi_u_dat<<std::endl;
  }
}
void SacuvajUBinarnuDatoteku(std::string ime_dat){
      std::ofstream pisi_u_dat(ime_dat,std::ios::app);
    int m=br_redova,n=br_kolona;
   for(int i=0;i<m;i++)
  {
      pisi_u_dat<<elementi[i][0];
   for(int j=1;j<n;j++)
   {
       pisi_u_dat<<' '<<elementi[i][j];
   }
   pisi_u_dat<<std::endl;
  }
}
void ObnoviIzBinarneDatoteke(std::string ime_dat){
    std::ifstream citaj_iz_dat(ime_dat,std::ios::in | std::ios::binary);
    if(!citaj_iz_dat) throw std::logic_error("Trazena datoteka ne postoji");
    
    std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
if(!ulazni_tok) throw std::logic_error("Datoteka ne postoji!\");
for(int i = 0; i < broj_studenata; i++) delete studenti[i];
delete[] studenti;
ulazni_tok.read(reinterpret_cast<char*>(this), sizeof *this);
studenti = new Student*[MaxBrojStudenata];
for(int i = 0; i < broj_studenata; i++) studenti[i] = nullptr;
for(int i = 0; i < broj_studenata; i++) {
studenti[i] = new Student;
ulazni_tok.read(reinterpret_cast<char*>(studenti[i]), sizeof(Student));
}
if(!ulazni_tok) {
for(int i = 0; i < broj_studenata; i++) delete studenti[i];
delete[] studenti;
throw std::logic_error("Nešto nije u redu sa čitanjem!");
}
    
}
void ObnoviIzTekstualneDatoteke(std::string ime_dat){
     std::ifstream citaj_iz_dat(ime_dat,std::ios::in);
    if(!citaj_iz_dat) throw std::logic_error("Trazena datoteka ne postoji");
    
    char znak;
    TipEl e;
    std::vector<std::vector<TipEl>> v;
    int i=0,j=0;
    for(i=0;;i++){
        v.resize(i+1);
        for(j=0;;j++){
        citaj_iz_dat>>e;
        if(!citaj_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        v.at(i).push_back(e);
        if(citaj_iz_dat.eof()) break;
        if(citaj_iz_dat.peek()!=',') break;
            citaj_iz_dat>>znak;
            if(!citaj_iz_dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
          if(citaj_iz_dat.eof()) break;
        }
        if(citaj_iz_dat.eof()) break;
    }
    DealocirajMemoriju(elementi,br_redova);
    br_redova=0;
    br_kolona=0;
    br_kolona=j+1;
    br_redova=i+1;
    elementi=AlocirajMemoriju(br_redova,br_kolona);
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            elementi[i][j]=v[i][j];
        }
    }
}

};

//ZAVRSETAK KLASE
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
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
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
template <typename Tip2>
std:: istream&  operator>>(std:: istream& tok,const Matrica<Tip2> &m1) {
for(int i = 0; i < m1.br_redova; i++)
for(int j = 0; j < m1.br_kolona; j++) {
std::cout << m1.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
std::cin >> m1.elementi[i][j];
}
return tok;
}
template <typename Tip2>
std::ostream& operator <<(std::ostream& tok,const Matrica<Tip2> &m1)  {
 int sirina=tok.width();
for(int i = 0; i < m1.br_redova; i++) {
for(int j = 0; j < m1.br_kolona; j++)
tok<< std::setw(sirina) << m1.elementi[i][j];
tok << std::endl;
}
return tok;
}
template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1,
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
Matrica<TipEl> operator -(const Matrica<TipEl> &m1,
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
Matrica<TipEl> operator +=(const Matrica<TipEl> &m1,
const Matrica<TipEl> &m2) {
if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
throw std::domain_error("Matrice nemaju jednake dimenzije!");
//Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
for(int i = 0; i < m1.br_redova; i++)
for(int j = 0; j < m1.br_kolona; j++)
m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
return m1;
}
template <typename Tip2>
Matrica<Tip2> operator -=(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2) {
if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
throw std::domain_error("Matrice nemaju jednake dimenzije!");
//Matrica<Tip2> m3(m1.br_redova, m1.br_kolona);
for(int i = 0; i < m1.br_redova; i++)
for(int j = 0; j < m1.br_kolona; j++)
m1.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
return m1;
}
template<typename Tipk>
Matrica<Tipk> operator *(const Matrica<Tipk> &a,int b){
 Matrica<Tipk> c(a.br_redova,a.br_kolona);

 for(int i=0;i<c.br_redova;i++){
  for(int j=0;j<c.br_kolona;j++){
   c.elementi[i][j]=a.elementi[i][j]*b;
  }
 }
 return c;
}

template<typename Tip>
Matrica<Tip> operator *(int b,const Matrica<Tip> &a){
  Matrica<Tip> c(a.br_redova,a.br_kolona);
 for(int i=0;i<a.br_redova;i++){
  for(int j=0;j<a.br_kolona;j++){
   c.elementi[i][j]=a.elementi[i][j]*b;
  }
 }
 return c;
}
template<typename Tip>
Matrica<Tip> operator *=(int b, Matrica<Tip> &a){
  
 for(int i=0;i<a.br_redova;i++){
  for(int j=0;j<a.br_kolona;j++){
   a.elementi[i][j]=a.elementi[i][j]*b;
  }
 }
 return a;
}
template<typename Tipk>
Matrica<Tipk> operator *=( Matrica<Tipk> &a,int b){
 //Matrica<Tipk> c(a.br_redova,a.br_kolona);

 for(int i=0;i<a.br_redova;i++){
  for(int j=0;j<a.br_kolona;j++){
   a.elementi[i][j]=a.elementi[i][j]*b;
  }
 }
 return a;
}

int main(){
    return 0;
}