/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>
template <typename TipEl>
class Matrica{
    int br_redova, br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova,int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi,int br_redova);
    void KopirajElemente(TipEl **elementi);
    static bool MoguSeMnoziti(Matrica m1, Matrica m2){
        return m1.br_kolona==m2.br_redova;
    }
    void TestIndeksa(int x, int y)const {
        if(x<1 || x>br_redova || y<1 || y>br_kolona) throw std::range_error("Neispravan indeks");
    }
    void TestIndeksa(int x) const{
        if(x<0 || x>br_redova-1) throw std::range_error("Neispravan indeks");
    }
    public:
    Matrica(int br_redova, int br_kolona, char ime=0);
    Matrica(const char *c, bool x);+
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    ~Matrica(){
        DealocirajMemoriju(elementi,br_redova);
    }
    Matrica &operator=(const Matrica &m);
    Matrica &operator=(Matrica &&m);
    
    template<typename Tip2>
    friend std::ostream &operator<<(std::ostream &tok, const Matrica<Tip2> &m);
    template<typename Tip2>
    friend std::istream &operator>>(std::istream &tok, const Matrica<Tip2> &m);
    template<typename Tip3>
    friend Matrica<Tip3> operator+(const Matrica<Tip3> &m1, const Matrica<Tip3> &m2);
    template<typename Tip3>
    friend Matrica<Tip3> operator-(const Matrica<Tip3> &m1, const Matrica<Tip3> &m2);
    template<typename Tip3>
    friend Matrica<Tip3> operator*(const Matrica<Tip3> &m1, const Matrica<Tip3> &m2);
    template<typename Tip2, typename Tip3>
    friend Matrica<Tip3> operator*(const Matrica<Tip2> &m1, Tip3 skalar);
    template<typename Tip2, typename Tip3>
    friend Matrica<Tip3> operator*(Tip3 skalar, const Matrica<Tip2> &m1);
    
    Matrica<TipEl> &operator+=(const Matrica<TipEl> &m){
        return *this = *this + m;
    }
    Matrica<TipEl> &operator-=(const Matrica<TipEl> &m){
        return *this = *this - m;
    }
    Matrica<TipEl> &operator*=(const Matrica<TipEl> &m){
        return *this = *this * m;
    }
    Matrica<TipEl> &operator*=(TipEl skalar){
        return *this = *this * skalar;
    }
    TipEl* operator[](int indeks){
        TestIndeksa(indeks);
        return elementi[indeks];
    }
    TipEl* operator[](int indeks) const {
        TestIndeksa(indeks);
        return elementi[indeks];
    }
    TipEl &operator() (int red, int kolona){
        TestIndeksa(red,kolona);
        return elementi[red-1][kolona-1];
    }
    TipEl &operator() (int red, int kolona) const {
        TestIndeksa(red,kolona);
        return elementi[red-1][kolona-1];
    }
    operator std::string() const{
        std::string novi("{");
        for(int i=0; i<br_redova; i++){
            novi+="{";
            for(int j=0; j<br_kolona; j++){
                novi+=std::to_string(int(elementi[i][j]));
                if(j!=br_kolona-1) novi+=",";
            }
            novi+="}";
            if(i!=br_redova-1) novi+=",";
        }
    return novi+"}";
   }
   void SacuvajUTekstualnuDatoteku(const char *c);
   void SacuvajUBinarnuDatoteku(const char *c);
   void ObnoviIzTekstualneDatoteke(const char *c);
   void ObnoviIzBinarneDatoteke(const char *c);
};

template <typename TipEl>
TipEl **Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona){
    TipEl **elementi(new TipEl*[br_redova]{});
    try{
        for(int i=0; i<br_redova; i++) elementi[i]=new TipEl[br_kolona];
    } catch(...){
        DealocirajMemoriju(elementi,br_redova);
        throw;
    }
    return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova){
    for(int i=0; i<br_redova; i++) delete [] elementi[i];
    delete[] elementi;
}
template<typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime):br_redova(br_redova),br_kolona(br_kolona), ime_matrice(ime),
elementi(AlocirajMemoriju(br_redova,br_kolona)){}
template<typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi){
    for(int i=0; i<br_redova; i++)
       for(int j=0; j<br_kolona; j++)
          Matrica::elementi[i][j]=elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m): br_redova(m.br_redova),br_kolona(m.br_kolona),ime_matrice(m.ime_matrice),
elementi(AlocirajMemoriju(m.br_redova,m.br_kolona)){
    KopirajElemente(m.elementi);
}
template<typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m):br_redova(m.br_redova),br_kolona(m.br_kolona),elementi(m.elementi),ime_matrice(m.ime_matrice){
    m.br_redova=0;
    m.elementi=nullptr;
}
template<typename TipEl>
Matrica<TipEl>::Matrica(const char *c, bool x){
    if(x){
        std::string s(c);
        std::ifstream ulazni_tok(s, std::ios::binary);
        if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        
    }
    else{
        std::string s(c);
        std::ifstream ulazni_tok(s);
        if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    }
}
template<typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m){
    if(br_redova<m.br_redova || br_kolona<m.br_kolona){
        TipEl **novi_prostor(AlocirajMemoriju(m.br_redova,m.br_kolona));
        DealocirajMemoriju(elementi,br_redova);
        elementi=novi_prostor;
    }else if(br_redova>m.br_redova)
    for(int i=m.br_redova; i<br_redova; i++) delete elementi[i];
    br_redova=m.br_redova;
    br_kolona=m.br_kolona;
    ime_matrice=m.ime_matrice;
    KopirajElemente(m.elementi);
    return *this;
}
template<typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator=(Matrica<TipEl> &&m){
    std::swap(br_redova,m.br_redova);
    std::swap(br_kolona,m.br_kolona);
    std::swap(ime_matrice,m.ime_matrice);
    std::swap(elementi,m.elementi);
    return *this;
}
template<typename Tip2>
std::ostream &operator<<(std::ostream &tok, const Matrica<Tip2> &m){
    auto velicina(tok.width());
    for(int i=0; i<m.br_redova; i++){
        for(int j=0; j<m.br_kolona; j++)
        tok<<std::setw(velicina)<<m.elementi[i][j];
        tok<<std::endl;
    }
    return tok;
}
template<typename Tip2>
std::istream &operator>>(std::istream &tok, Matrica<Tip2> &m){
    for(int i=0; i<m.br_redova; i++)
       for(int j=0; j<m.br_kolona; j++){
           std::cout<<m.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
           tok>>m.elementi[i][j];
       }
       return tok;
}
template<typename Tip3>
Matrica<Tip3> operator+(const Matrica<Tip3> &m1, const Matrica<Tip3> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije");
    Matrica<Tip3> m3(m1.br_redova,m1.br_kolona);
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++)
    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template<typename Tip3>
Matrica<Tip3> operator-(const Matrica<Tip3> &m1, const Matrica<Tip3> &m2){
   if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije");
   Matrica<Tip3> m3(m1.br_redova,m1.br_kolona);
   for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++)
    m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
    return m3;
}
template<typename Tip3>
Matrica<Tip3> operator*(const Matrica<Tip3> &m1, const Matrica<Tip3> &m2){
   if(!MoguSeMnoziti(m1,m2)) throw std::domain_error("Matrice nisu saglasne za mnozenje");
   Matrica<Tip3> m3(m1.br_redova,m2.br_kolona);
   for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++){
        double suma(0);
        for(int k=0; k<m2.br_redova; k++)
        suma+=m1.elementi[i][k]*m2.elementi[k][j];
        m3.elementi[i][j]=suma;
    }
    return m3;
}   
template<typename Tip2, typename Tip3>
Matrica<Tip3> operator*(const Matrica<Tip2> &m1, Tip3 skalar){
    Matrica<Tip3> m3(m1.br_redova,m1.br_kolona);
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
        m3.elementi[i][j]=m1.elementi[i][j]*skalar;
    return m3;
}
template<typename Tip2, typename Tip3>
Matrica<Tip3> operator*(Tip3 skalar, const Matrica<Tip2> &m1){
    Matrica<Tip3> m3(m1.br_redova,m1.br_kolona);
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
        m3.elementi[i][j]=m1.elementi[i][j]*skalar;
    return m3;
}
template<typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(const char *c){
    
}
template<typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(const char *c){
    
}
template<typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(const char *c){
    std::string s(c);
    std::ifstream ulazni_tok(s);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
}
template<typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(const char *c){
    std::string s(c);
    std::ifstream ulazni_tok(s, std::ios::binary);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    
}
int main ()
{
	return 0;
}
