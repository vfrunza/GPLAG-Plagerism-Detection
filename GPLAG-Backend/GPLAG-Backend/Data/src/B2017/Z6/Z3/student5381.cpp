/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include<fstream>

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
    TipEl* operator[](int index)const{  return elementi[index]; }
    TipEl* &operator[] (int index){  return elementi[index]; }
    template <typename TipEl2> friend std::istream& operator>>(std::istream &tok, Matrica<TipEl2> &m);
    template <typename TipEl2> friend std::ostream& operator <<(std::ostream &tok, const Matrica<TipEl2> &m);
    template <typename Tip2>
    friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1,
                const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1,
                const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> &operator -=( Matrica<Tip2> &m1,
                const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> &operator +=( Matrica<Tip2> &m1,
                const Matrica<Tip2> &m2);

    TipEl &operator()(int a, int b) {
        if(a-1<0 || a>br_redova || b>br_kolona || b-1<0) throw std::range_error("Neispravan indeks");
    return elementi[a-1][b-1];
     }
    TipEl operator()(int a,int b) const{
        if(a-1<0 || a>br_redova || b>br_kolona || b-1<0) throw std::range_error("Neispravan indeks");
    return elementi[a-1][b-1];
    }

    operator std::string()const;
  
    template <typename Tip2>
    friend Matrica<Tip2> operator *( const Matrica<Tip2> &m1,  const Matrica<Tip2> &m2);
     template <typename Tip2, typename skalar>
 friend Matrica<Tip2> operator *( const Matrica<Tip2> &m1,  skalar n);
    template <typename Tip2, typename skalar>
 friend Matrica<Tip2> operator *( skalar n,  const Matrica<Tip2> &m1);
    template <typename Tip2, typename skalar>
 friend Matrica<Tip2> &operator *=(  Matrica<Tip2> &m1, skalar n);
    template <typename Tip2>
 friend Matrica<Tip2> &operator *=( Matrica<Tip2> &m1,  const Matrica<Tip2> &m2);
    template <typename Tip2, typename skalar> friend
 Matrica<Tip2> operator *(skalar n, const Matrica<Tip2> &m1);
 
 void SacuvajUTekstualnuDatoteku(const char ime_datoteke[]);
 void SacuvajUBinarnuDatoteku(const char ime_datoteke[]);
 void ObnoviIzTekstualneDatoteke(const char ime_datoteke[]);
 void ObnoviIzBinarneDatoteke(const char ime_datoteke[]);
 Matrica(const char ime_datoteke[], bool tip_datoteke);
};

    template <typename TipEl> void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(const char ime_datoteke[]){
     std::ofstream izlaz(ime_datoteke);
      for(int i(0);i<br_redova;i++){
          for(int j(0);j<br_kolona;j++){
           if(j<br_kolona-1) izlaz<<elementi[i][j]<<",";
           else izlaz<<elementi[i][j]<<std::endl;
          }
        if(!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
      }
   }
   
     template <typename TipEl> void Matrica<TipEl>::SacuvajUBinarnuDatoteku(const char ime_datoteke[]){
     std::ofstream izlaz(ime_datoteke, std::ios::binary);
      if(!izlaz) throw std::logic_error("Trazena datoteka ne postoji");
      if(!izlaz.write(reinterpret_cast<const char*>(&br_redova), sizeof(int)))
              throw std::logic_error("Problemi sa upisom u datoteku");
      if(!izlaz.write(reinterpret_cast<const char*>(&br_kolona), sizeof(int)))
              throw std::logic_error("Problemi sa upisom u datoteku");
      for(int i(0);i<br_redova;i++){
       for(int j(0);j<br_kolona;j++){
        if(!izlaz.write(reinterpret_cast<const char*>(&elementi[i][j]), sizeof(TipEl)))
              throw std::logic_error("Problemi sa upisom u datoteku");
       }
      }

   }
     template <typename TipEl> void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(const char ime_datoteke[]){
      std::ifstream ulaz(ime_datoteke);
      if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
      TipEl pomoc; char znak;
      int br_r(0), br_k(0);
      for(;;){
       ulaz>>pomoc;
       znak=ulaz.get();
       br_k++;
       if(znak=='\n' || ulaz.eof()) br_r++;
       if((znak!=',' && znak!='\n') && !ulaz.eof()) {
       //  DealocirajMemoriju(elementi, br_redova);
         throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
       if(!ulaz) break;
      }
      if (ulaz.eof()){
       double provjera(br_k/double(br_r));
       if(provjera-(br_k/br_r)!=0) br_r--;
       br_k/=br_r;
      }else throw std::logic_error("Datoteka sadrzi besmislene podatke");
      if(elementi!=nullptr){
          DealocirajMemoriju(elementi, br_redova);
      }
      br_kolona=br_k;   br_redova=br_r;
      elementi=AlocirajMemoriju(br_r, br_k);
      ulaz.close();
      ulaz.open(ime_datoteke);
      for(int i(0);i<br_r;i++){
       for(int j(0);j<br_k;j++){
        ulaz>>elementi[i][j];
        znak=ulaz.get();
       }
      }
      znak=ulaz.get();
      if(ulaz.eof()) return;
      if(ulaz.bad()) { 
       DealocirajMemoriju(elementi, br_redova);
      throw std::logic_error("Problemi pri citanju datoteke");
      }
      else {DealocirajMemoriju(elementi, br_redova);
      throw  std::logic_error("Datoteka sadrzi besmislene podatke");
      }
   }
   
     template <typename TipEl> void Matrica<TipEl>::ObnoviIzBinarneDatoteke(const char ime_datoteke[]){
      std::ifstream ulaz(ime_datoteke, std::ios::binary);
      if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
      if(elementi!=nullptr){
       DealocirajMemoriju(elementi, br_redova);
      }
      if(!ulaz.read(reinterpret_cast<char*>(&br_redova), sizeof(int))) throw std::logic_error("Problemi pri citanju datoteke");
      if(!ulaz.read(reinterpret_cast<char*>(&br_kolona), sizeof(int))) throw std::logic_error("Problemi pri citanju datoteke");
      elementi=AlocirajMemoriju(br_redova,br_kolona);
      
      for(int i(0);i<br_redova;i++)
         for(int j(0);j<br_kolona;j++){
          if(!ulaz.read(reinterpret_cast<char*>(&elementi[i][j]), sizeof(TipEl))){
           DealocirajMemoriju(elementi,br_redova);
           throw std::logic_error("Problemi pri citanju datoteke");
          } 
         }
         
   }
   
    template <typename TipEl>
        Matrica<TipEl>::Matrica(const char ime_datoteke[], bool tip_datoteke){
         if(tip_datoteke){
          std::ifstream ulaz(ime_datoteke, std::ios::binary);
      if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
      if(!ulaz.read(reinterpret_cast<char*>(&br_redova), sizeof(int))) throw std::logic_error("Problemi pri citanju datoteke");
      if(!ulaz.read(reinterpret_cast<char*>(&br_kolona), sizeof(int))) throw std::logic_error("Problemi pri citanju datoteke");
      elementi=AlocirajMemoriju(br_redova,br_kolona);
      
      for(int i(0);i<br_redova;i++)
         for(int j(0);j<br_kolona;j++){
            if(!ulaz.read(reinterpret_cast<char*>(&elementi[i][j]), sizeof(TipEl))){
              DealocirajMemoriju(elementi, br_redova);
              throw std::logic_error("Problemi pri citanju datoteke");
             }
         }  
         }else{
           std::ifstream ulaz(ime_datoteke);
      if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
      TipEl pomoc; char znak;
      int br_r(0), br_k(0);
      for(;;){
       ulaz>>pomoc; znak=ulaz.get();
       br_k++;
       if(znak=='\n' || ulaz.eof()) br_r++;
        if((znak!=',' && znak!='\n') && !ulaz.eof()) {
         throw std::logic_error("Datoteka sadrzi besmislene podatke");
       }
       if(!ulaz) break;
      }
      if (ulaz.eof()){
       double provjera(br_k/double(br_r));
       if(provjera-(br_k/br_r)!=0) br_r--;
       br_k/=br_r;
      }else throw std::logic_error("Datoteka sadrzi besmislene podatke");
      
      br_kolona=br_k; br_redova=br_r;
      elementi=AlocirajMemoriju(br_r, br_k);
      ulaz.close(); ulaz.open(ime_datoteke);
      for(int i(0);i<br_r;i++){
       for(int j(0);j<br_k;j++){
        ulaz>>elementi[i][j];
        znak=ulaz.get();
       }
      }
      znak=ulaz.get();  if(ulaz.eof()) return;
      if(ulaz.bad()) {
       DealocirajMemoriju(elementi, br_redova);
       throw std::logic_error("Problemi pri citanju datoteke");}
      else  {       
       DealocirajMemoriju(elementi, br_redova);
       throw std::logic_error("Datoteka sadrzi besmislene podatke");
     }}}


 template<typename TipEl> Matrica<TipEl>::operator std::string() const{
   std::string s;
    s+="{";
  for(int i=0;i<br_redova;i++){
   s+="{";
    for(int j=0;j<br_kolona;j++){
    s+=std::to_string(int(elementi[i][j]));
     if(j<br_kolona-1) s+=","; 
    }
   s+="}";
   if(i<br_redova-1) s+=",";
  }
  s+="}";
    return s;
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
 
 template <typename TipEl> std::istream& operator>>(std::istream &tok, Matrica<TipEl> &m) {
 for(int i = 0; i < m.br_redova; i++)
 	for(int j = 0; j < m.br_kolona; j++) {
 		std::cout<< m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
 			tok >> m.elementi[i][j];
 }
 return tok;
 }
 
 template <typename TipEl> std::ostream& operator<<(std::ostream &tok, const Matrica<TipEl> &m) {
  int ispis(tok.width());
 for(int i = 0; i < m.br_redova; i++) {
 	for(int j = 0; j < m.br_kolona; j++)
 		tok << std::setw(ispis) << m.elementi[i][j];
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
 for(int i = 0; i < m1.br_redova; i++)
 	for(int j = 0; j < m1.br_kolona; j++)
		 m1.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
 return m1;
 }
 
 template <typename TipEl>
 Matrica<TipEl> &operator-=( Matrica<TipEl> &m1,
 const Matrica<TipEl> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
  for(int i = 0; i < m1.br_redova; i++)
 	for(int j = 0; j < m1.br_kolona; j++)
		 m1.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
 return m1;
 }
 
 template <typename TipEl>
 Matrica<TipEl> &operator+=( Matrica<TipEl> &m1,
 const Matrica<TipEl> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
         throw std::domain_error("Matrice nemaju jednake dimenzije!");
  for(int i = 0; i < m1.br_redova; i++)
 	for(int j = 0; j < m1.br_kolona; j++)
		 m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m1;
 }
 
 template <typename Tip2> 
 Matrica<Tip2> operator *( const Matrica<Tip2> &m1, const Matrica<Tip2> &m2){
    if(m1.br_redova != m2.br_kolona)
         throw std::domain_error("Matrice nisu saglasne za mnozenje");
     Matrica<Tip2> m3(m1.br_redova, m2.br_kolona);
    for(int i=0;i<m1.br_redova;i++){
     for(int j=0;j<m2.br_kolona;j++){
             m3.elementi[i][j]=0;
     for(int k=0;k<m1.br_kolona;k++)
         m3.elementi[i][j]+=(m1.elementi[i][k]*m2.elementi[k][j]);
    }
 }
 return m3;
 }

 template <typename Tip2, typename skalar>
  Matrica<Tip2> operator *( const Matrica<Tip2> &m, skalar n){
     Matrica<Tip2> m3(m.br_redova, m.br_kolona);
    for(int i(0);i<m.br_redova;i++){
        for(int j(0);j<m.br_kolona;j++){
            m3.elementi[i][j]=m.elementi[i][j]*n;
    }
  }
  return m3;
 }
 
 template <typename Tip2, typename skalar>
  Matrica<Tip2> operator *(skalar n, const Matrica<Tip2> &m){
     Matrica<Tip2> m3(m.br_redova, m.br_kolona);
        for(int i(0);i<m.br_redova;i++){
            for(int j(0);j<m.br_kolona;j++){
                m3.elementi[i][j]=m.elementi[i][j]*n;
   }
  }
  return m3;
 }
 
  template <typename Tip2, typename skalar>
 Matrica<Tip2> &operator *=(  Matrica<Tip2> &m1, skalar n){
     m1=m1*n;
  return m1;
 }
 
 template <typename Tip2>
 Matrica<Tip2> &operator *=( Matrica<Tip2> &m1,  const Matrica<Tip2> &m2){
     m1=m1*m2;
  return m1;
 }
 
int main(){
 try{
  Matrica<int> m(2,3);
  std::cin >> m;
  std::cout <<"Matrica za upis u txt:"<<std::endl<< m << std::endl<<"............"<< std::endl;
  m.SacuvajUTekstualnuDatoteku("pocetna_matrica.txt");
  Matrica<int> m2("pocetna_matrica.txt",false);
   std::cout <<"Obnovljena kopija iz tekstualne datoteke:"<<std::endl<< m2 << std::endl<<"............"<< std::endl;
  Matrica<int> n(2,2);
  std::cin >> n;
   std::cout <<"Matrica za upis u binarnu:"<<std::endl<< n << std::endl<<"............"<< std::endl;
  n.SacuvajUBinarnuDatoteku("nova_binarna.dat");
  m2.ObnoviIzBinarneDatoteke("nova_binarna.dat");
     std::cout <<"Obnovljena kopija (stare kopije) iz binarne datoteke:"<<std::endl<< m2 << std::endl<<"............"<< std::endl;
 } catch(std::logic_error gr){
  std::cout << gr.what() << std::endl;
 } 
 return 0;
}