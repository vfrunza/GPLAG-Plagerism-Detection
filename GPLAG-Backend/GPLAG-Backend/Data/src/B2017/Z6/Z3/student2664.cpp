/B2017/2018: Zadaća 6, Zadatak 3
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <new> // za bad_alloc
using std::domain_error;
using std::logic_error;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::istream;
using std::getline;
using std::string;
using std::swap;
using std::move;
using std::endl;
using std::cout;
using std::cin;

template <typename TipEl>
    class Matrica{
        int br_redova, br_kolona;
        TipEl **elementi;
        char ime_matrice;
        static void DealocirajMemoriju(TipEl** elementi, int br_redova);
        static TipEl** AlocirajMemoriju(int br_redova, int br_kolona);
        void KopirajElemente(TipEl **elementi);
        void TestIndeksa(int i, int j) const {
            if(i<1 || j<1 || i>br_redova || j>br_kolona) throw std::range_error("Neispravan indeks");
        }
      public:
        Matrica(int br_redova, int br_kolona, char ime = 0);
        Matrica(const Matrica &m);
        Matrica(Matrica &&m);
        ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
        Matrica& operator =(const Matrica &m);
        Matrica& operator =(Matrica &&m);
        
        TipEl* operator [](int indeks) const { return elementi[indeks]; }
        TipEl* &operator [](int indeks) { return elementi[indeks]; }
        TipEl operator ()(int i, int j) const {
            TestIndeksa(i, j);
            return elementi[i-1][j-1];
        }
        TipEl& operator ()(int i, int j) {
            TestIndeksa(i, j);
            return elementi[i-1][j-1];
        }
        operator string() const {
            string s("{");
            for(int i=0; i<br_redova; i++){
                for(int j=0; j<br_kolona; j++){
                    if(j == 0) s += "{";
                    s += std::to_string((int)(elementi[i][j])); // bez konverzije ne bi valjalo !!
                    if(j != br_kolona-1) s += ",";
                    else s += "}";
                }
                if(i != br_redova-1) s += ",";
            }
            return s += "}";
        }
        Matrica operator *=(double x) {
            for(int i=0; i<br_redova; i++)
                for(int j=0; j<br_kolona; j++)
                    elementi[i][j] *= x;
                    
            return *this;
        }
        Matrica operator *(double x) const { 
            Matrica m3(br_redova, br_kolona);
            for(int i=0; i<br_redova; i++)
                for(int j=0; j<br_kolona; j++)
                    m3.elementi[i][j] = x*elementi[i][j];
                    
            return m3;
        }
        template <typename Tip2>
            friend Matrica<Tip2> operator *(double x, const Matrica<Tip2> &m);
        Matrica operator *=(const Matrica &m) {
            if(m.br_redova != br_kolona) throw domain_error("Matrice nisu saglasne za mnozenje");
            Matrica m3(br_redova, m.br_kolona);
            for(int i=0; i<br_redova; i++)
                for(int j=0; j<m.br_kolona; j++){
                    TipEl suma{};
                    for(int k=0; k<m.br_redova; k++) suma += elementi[i][k] * m.elementi[k][j];
                    m3.elementi[i][j] = suma;
                }
                *this = move(m3);
                return *this;
        }
        Matrica operator *(const Matrica &m) const {  
            Matrica m3(*this);
            m3 *= m;
            return m3;
        }
        template <typename Tip2>
            friend istream& operator >>(istream &tok, Matrica<Tip2> &m);
        template <typename Tip2>
            friend ostream& operator <<(ostream &ok, const Matrica<Tip2> &m);
        Matrica& operator +=(const Matrica &m){
            if(br_redova != m.br_redova || br_kolona != m.br_kolona) throw domain_error("Matrice nemaju jednake dimenzije!");
            for(int i=0; i<br_redova; i++)
                for(int j=0; j<br_kolona; j++)
                    elementi[i][j] += m.elementi[i][j];
            return *this;
        }
        Matrica operator +(const Matrica &m) const { 
            Matrica m3(*this);
            return m3 += m;
        }
        Matrica& operator -=(const Matrica &m) {
            if(br_redova != m.br_redova || br_kolona != m.br_kolona) throw domain_error("Matrice nemaju jednake dimenzije!");
            for(int i=0; i<br_redova; i++)
                for(int j=0; j<br_kolona; j++)
                    elementi[i][j] -= m.elementi[i][j];
            return *this;
        }
        Matrica operator -(const Matrica &m) const { 
            Matrica m3(*this);
            return m3 -= m;
        }
        void SacuvajUTekstualnuDatoteku(const char ime_datoteke[]) const {
            ofstream tok(ime_datoteke);
            if(!tok) throw logic_error("Problemi sa upisom u datoteku"); // **
            for(int i=0; i<br_redova; i++){
                for(int j=0; j<br_kolona; j++){
                    tok << elementi[i][j];
                    if(j != br_kolona-1) tok << ",";
                    if(!tok) throw logic_error("Problemi sa upisom u datoteku");
                }
                tok << endl;
            }
            
        }
        void SacuvajUBinarnuDatoteku(const char ime_datoteke[]) const {
            ofstream tok(ime_datoteke, std::ios::binary);
            tok.write(reinterpret_cast<const char*> (this), sizeof *this);
            for(int i=0; i<br_redova; i++){
                for(int j=0; j<br_kolona; j++){
                    tok.write(reinterpret_cast<const char*> (&elementi[i][j]), sizeof elementi[i][j]);
                    if(!tok) throw logic_error("Problemi sa upisom u datoteku");
                }
            }
        }
        void ObnoviIzTekstualneDatoteke(const char ime_datoteke[]) {
            ifstream tok(ime_datoteke);
            if(!tok) throw logic_error("Trazena datoteka ne postoji"); // **??
         
        }
        void ObnoviIzBinarneDatoteke(const char ime_datoteke[]) {
            ifstream tok(ime_datoteke, std::ios::binary);
            if(!tok) throw logic_error("Trazena datoteka ne postoji");
            Matrica pom(*this);
            DealocirajMemoriju(elementi, br_redova);
            tok.read(reinterpret_cast<char*> (this), sizeof *this);
            AlocirajMemoriju(br_redova, br_kolona);
            for(int i=0; i<br_redova; i++){
                for(int j=0; j<br_kolona; j++){
                    tok.read(reinterpret_cast<char*> (&elementi[i][j]), sizeof (TipEl));
                    if(!tok) {
                        DealocirajMemoriju(elementi, br_redova); // **
                        *this = move(pom);
                        throw logic_error("Problemi pri citanju datoteke");
                    }
                }
            }
            
            DealocirajMemoriju(pom.elementi, pom.br_redova);
            
            
        }
        explicit Matrica(const char ime_datoteke[], bool binarna){
            if(binarna){
                ifstream tok(ime_datoteke, std::ios::binary);
                if(!tok) throw logic_error("Trazena datoteka ne postoji");
                tok.read(reinterpret_cast<char*> (this), sizeof *this);
                AlocirajMemoriju(br_redova, br_kolona);
                for(int i=0; i<br_redova; i++){
                    for(int j=0; j<br_kolona; j++){
                        tok.read(reinterpret_cast<char*> (&elementi[i][j]), sizeof (TipEl));
                        if(!tok) throw logic_error("Problemi pri citanju datoteke");
                        
                    }
                }
            }
            else{
                ifstream tok(ime_datoteke);
                if(!tok) throw logic_error("Trazena datoteka ne postoji");
            }
        }
        
        
    };

template <typename TipEl>
    void Matrica<TipEl>::DealocirajMemoriju(TipEl** elementi, int br_redova) {
        for(int i=0; i<br_redova; i++) delete[] elementi[i];
        delete[] elementi;
    }

template <typename TipEl>
    TipEl** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
        TipEl** elementi(new TipEl*[br_redova]{});
        try{
            for(int i=0; i<br_redova; i++) elementi[i] = new TipEl[br_kolona];
        }
        catch(...){
            DealocirajMemoriju(elementi, br_redova);
            throw;
        }
        return elementi;
    }

template <typename TipEl>
    void Matrica<TipEl>::KopirajElemente(TipEl** elementi) {
        for(int i=0; i<br_redova; i++)  
            std::copy(elementi[i], elementi[i]+br_kolona, Matrica::elementi[i]);
    }

template <typename TipEl>
    Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), 
        br_kolona(br_kolona), elementi(AlocirajMemoriju(br_redova, br_kolona)), ime_matrice(ime) {}

template <typename TipEl>
    Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), 
        elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)), ime_matrice(m.ime_matrice) {
            KopirajElemente(m.elementi);
        }
        
template <typename TipEl>
    Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona), 
        elementi(m.elementi), ime_matrice(m.ime_matrice) {
            m.br_redova = 0; // !!
            m.elementi = nullptr;
        }
   
template <typename TipEl>
    Matrica<TipEl>& Matrica<TipEl>::operator =(const Matrica<TipEl> &m) {
        if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
            TipEl** novi_prostor(AlocirajMemoriju(m.br_kolona, m.br_kolona));
            DealocirajMemoriju(elementi, br_redova);
            elementi = novi_prostor;
        }
        else if(br_redova > m.br_redova)
            for(int i=m.br_redova; i<br_redova; i++) delete elementi[i];
        
        br_redova = m.br_redova;
        br_kolona = m.br_kolona;
        ime_matrice = m.ime_matrice;
        KopirajElemente(m.elementi);
        return *this;
    }

template <typename TipEl>
    Matrica<TipEl>& Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
        swap(br_kolona, m.br_kolona);
        swap(br_redova, m.br_redova);
        swap(ime_matrice, m.ime_matrice);
        swap(elementi, m.elementi);
        return *this;
    }
    
template <typename Tip2>
    Matrica<Tip2> operator *(double x, const Matrica<Tip2> &m) { return m*x; }

template <typename Tip2>
    istream& operator >>(istream &tok, Matrica<Tip2> &m) {
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++) {
                cout << m.ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                tok >> m.elementi[i][j];
            }
        return tok;
    } 

template <typename Tip2>
    ostream& operator <<(ostream &tok, const Matrica<Tip2> &m) {
        int xx(tok.width()); // mora!!
        for(int i=0; i<m.br_redova; i++) {
            for(int j=0; j<m.br_kolona; j++) {
                tok << std::setw(xx) << m.elementi[i][j];
            }
            tok << endl;
        }
        return tok;
    }
        


int main (){
    
	return 0;
}
