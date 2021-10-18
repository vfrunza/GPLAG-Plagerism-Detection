/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <new>
#include <fstream>

template <typename Tip>
std::string UString(Tip element)
{
    std::ostringstream s;
    s<<element;
    return s.str();
}

template <typename TipElemenata>
class Matrica
{
    int br_redova, br_kolona;
    TipElemenata **elementi;
    char ime_matrice;
    static TipElemenata **Alociraj(int br_redova, int br_kolona);
    static void Dealociraj(TipElemenata **elementi, int br_redova);
    void Kopiraj(TipElemenata **elementi);
    void TestIndeksa (int red, int kolona) const {
        if(red<1 || kolona<1 || red>br_redova || kolona>br_kolona)
            throw std::range_error("Neispravan indeks");
    }
public:
    Matrica (int br_redova, int br_kolona, char ime=0);
    Matrica (const Matrica &m);
    Matrica (Matrica &&m);
    Matrica (const char *ime, bool binarno);
    ~Matrica () {
        Dealociraj(elementi, br_redova);
    }
    Matrica &operator = (const Matrica &m);
    Matrica &operator = (Matrica &&m);
    TipElemenata *operator [] (int indeks) const {
        return elementi[indeks];
    }
    TipElemenata *operator [] (int indeks) {
        return elementi[indeks];
    }
    TipElemenata &operator() (int i, int j) const {
        TestIndeksa(i, j);
        return elementi[i-1][j-1];
    }
    operator std::string () const;
    Matrica<TipElemenata> operator -(const Matrica m1);
    Matrica<TipElemenata> &operator -=(const Matrica<TipElemenata> m1);
    Matrica<TipElemenata> &operator *=(const Matrica<TipElemenata> &m1);
    Matrica<TipElemenata> &operator *=(double broj);
    Matrica<TipElemenata> &operator +=(const Matrica<TipElemenata> m1);
    friend Matrica<TipElemenata> operator +(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2) {
        auto m(m1);
        return m+=m2;
    }
    void ObnoviIzBinarneDatoteke(const char *ime);
    void ObnoviIzTekstualneDatoteke(const char *ime);
    template <typename TipElemenata1>
    friend std::ostream &operator <<(std::ostream &tok, const Matrica<TipElemenata1> &m);
    template <typename TipElemenata1>
    friend std::istream &operator >>(std::istream &tok, const Matrica<TipElemenata1> &m);
    void SacuvajUTekstualnuDatoteku (const char *ime) const;
    void SacuvajUBinarnuDatoteku (const char *ime) const;
    template <typename TipElemenata1>
    friend Matrica<TipElemenata1> ZbirMatrica (const Matrica<TipElemenata1> &m1, const Matrica<TipElemenata1> &m2);
    template <typename TipElemenata1>
    friend Matrica<TipElemenata1> operator *(const Matrica<TipElemenata1> &m1, const Matrica<TipElemenata1> &m2);
    template <typename TipElemenata1>
    friend Matrica<TipElemenata1> operator *(const Matrica<TipElemenata1> &m1, double broj);
    template <typename TipElemenata1>
    friend Matrica<TipElemenata1> operator *(double broj, const Matrica<TipElemenata1> &m1);
};

template <typename TipElemenata>
Matrica<TipElemenata>::Matrica (const char *ime, bool binarno) : br_redova(0), br_kolona(0),
    elementi(nullptr)
{
    if(binarno) ObnoviIzBinarneDatoteke(ime);
    else ObnoviIzTekstualneDatoteke(ime);
}

template <typename TipElemenata>
TipElemenata **Matrica<TipElemenata>::Alociraj(int br_redova, int br_kolona)
{
    TipElemenata **elementi (new TipElemenata*[br_redova] {});
    try {
        for(int i=0; i<br_redova; i++)
            elementi[i]=new TipElemenata[br_kolona];
    } catch (...) {
        Dealociraj(elementi, br_redova);
        throw;
    }
    return elementi;
}

template <typename TipElemenata>
void Matrica<TipElemenata>::Dealociraj(TipElemenata **elementi, int br_redova)
{
    if(elementi)
        for(int i=0; i<br_redova; i++) delete[] elementi[i];
    delete[] elementi;
}

template <typename TipElemenata>
Matrica<TipElemenata>::Matrica (int br_redova, int br_kolona, char ime) :
    br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime) ,
    elementi (Alociraj(br_redova, br_kolona)) { }

template <typename TipElemenata>
Matrica<TipElemenata>::Matrica (const Matrica<TipElemenata> &m) : br_redova(m.br_redova),
    br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
    elementi(Alociraj(m.br_redova, m.br_kolona))
{
    Kopiraj(m.elementi);
}

template <typename TipElemenata>
Matrica<TipElemenata>::Matrica (Matrica<TipElemenata> &&m) : br_redova(m.br_redova),
    br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi (m.elementi)
{
    m.elementi=nullptr;
    m.br_redova=0;
    m.br_kolona=0;
}

template <typename TipElemenata>
Matrica<TipElemenata> &Matrica<TipElemenata>::operator = (const Matrica<TipElemenata> &m)
{
    if(br_redova<m.br_redova || br_kolona<m.br_kolona) {
        TipElemenata **pomocni(Alociraj(m.br_redova, m.br_kolona));
        Dealociraj(elementi, br_redova);
        elementi=pomocni;
    } else if(br_redova>m.br_redova)
        for(int i= m.br_redova; i<br_redova; i++) delete elementi[i];
    br_kolona=m.br_kolona;
    br_redova=m.br_redova;
    ime_matrice=m.ime_matrice;
    Kopiraj(m.elementi);
    return *this;
}

template <typename TipElemenata>
Matrica<TipElemenata> &Matrica<TipElemenata>::operator = (Matrica<TipElemenata> &&m)
{
    std::swap(br_kolona, m.br_kolona);
    std::swap(br_redova, m.br_redova);
    std::swap(ime_matrice, m.ime_matrice);
    std::swap(elementi, m.elementi);
    return *this;
}

template <typename TipElemenata>
Matrica<TipElemenata>::operator std::string() const
{
    std::string rezultat("{");
    for(int i=0; i<br_redova; i++) {
        rezultat+="{";
        for(int j=0; j<br_kolona; j++) {
            rezultat+=UString(elementi[i][j]);
            if(j!=br_kolona-1) rezultat+=",";
        }
        rezultat+="}";
        if(i!=br_redova-1) rezultat+=",";
    }
    rezultat+="}";
    return rezultat;
}

template <typename TipElemenata>
Matrica<TipElemenata> Matrica<TipElemenata>::operator -(const Matrica<TipElemenata> m1)
{
    auto m(*this);
    return m-=m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> &Matrica<TipElemenata>::operator -=(const Matrica<TipElemenata> m1)
{
    if(br_redova!=m1.br_redova || br_kolona!=m1.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++)
            elementi[i][j]-=m1.elementi[i][j];
    return *this;
}

template <typename TipElemenata>
Matrica<TipElemenata> &Matrica<TipElemenata>::operator *=(const Matrica<TipElemenata> &m1)
{
    auto m(*this);
    if(br_kolona!=m1.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<m1.br_kolona; j++) {
            TipElemenata suma(0);
            for(int k=0; k<br_kolona; k++) suma+=elementi[i][k]*m1[k][j];
            m[i][j]=suma;
        }
    }
    *this=m;
    return *this;
}

template <typename TipElemenata>
Matrica<TipElemenata> &Matrica<TipElemenata>::operator *=(double broj)
{
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++)
            elementi[i][j]*=broj;
    return *this;
}

template <typename TipElemenata>
void Matrica<TipElemenata>::Kopiraj(TipElemenata **elementi)
{
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++)
            Matrica::elementi[i][j]=elementi[i][j];
}

template <typename TipElemenata>
Matrica<TipElemenata> &Matrica<TipElemenata>::operator +=(const Matrica<TipElemenata> m1)
{
    if(br_redova!=m1.br_redova || br_kolona!=m1.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++)
            elementi[i][j]+=m1[i][j];
    return *this;
}

template <typename TipElemenata>
void Matrica<TipElemenata>::ObnoviIzBinarneDatoteke(const char *ime)
{
    std::ifstream ulazni_tok(ime, std::ios::binary);
    if(!ulazni_tok)
        throw std::logic_error("Trazena datoteka ne postoji");
    TipElemenata **m_elementi=elementi;
    int m_br_redova=br_redova, m_br_kolona=br_kolona;
    ulazni_tok.read((char*) this, sizeof *this);
    elementi=Alociraj(br_redova, br_kolona);
    for(int i=0; i<br_redova; i++)
        ulazni_tok.read((char*) elementi[i], br_kolona *sizeof(TipElemenata));
    if(!ulazni_tok) {
        elementi=m_elementi;
        br_kolona=m_br_kolona;
        br_redova=m_br_redova;
        Dealociraj(m_elementi, br_redova);
        throw std::logic_error("Problem pri citanju datoteke");
    }
    Dealociraj(m_elementi, m_br_redova);
}

template <typename TipElemenata>
void Matrica<TipElemenata>::ObnoviIzTekstualneDatoteke(const char *ime)
{
    std::ifstream ulazni_tok(ime);
    if(!ulazni_tok)
        throw std::logic_error("Trazena datoteka ne postoji");
    std::string red, tmp;
    int redovi(0), kolone(0);
    getline(ulazni_tok,red);
    kolone=std::count_if(red.begin(), red.end(), [] (char x) {
        return x==',';
    });
    while(!ulazni_tok.eof()) {
        getline(ulazni_tok, tmp);
        int tmp_k=std::count_if(tmp.begin(), tmp.end(), [] (char x) {
            return x==',';
        });
        if(tmp_k!=kolone)
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        redovi++;
    }
    int t_br_redova=redovi+1, t_br_kolona=kolone+1;
    TipElemenata **t_elementi=Alociraj(t_br_redova, t_br_kolona);
    if(!ulazni_tok && !ulazni_tok.eof())
        throw std::logic_error("Problemi pri citanju datoteke");
    ulazni_tok.close();
    ulazni_tok.open(ime, std::ios::in);
    while(ulazni_tok) {
        char znak(',');
        for(int i=0; i<t_br_redova; i++)
            for(int j=0; j<t_br_kolona; j++) {
                ulazni_tok>>t_elementi[i][j]>>std::ws;
                if(j!=t_br_kolona-1) ulazni_tok>>znak>>std::ws;
                if(!ulazni_tok && !ulazni_tok.eof() || znak!=',' && j!=t_br_kolona-1) {
                    Dealociraj(t_elementi, t_br_redova);
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");
                }
            }
    }
    if(ulazni_tok.bad())
        throw std::logic_error("Problemi pri citanju datoteke");
    Dealociraj(elementi, br_redova);
    br_kolona=t_br_kolona;
    br_redova=t_br_redova;
    elementi=t_elementi;
    t_elementi=nullptr;
}

template <typename TipElemenata>
std::ostream &operator <<(std::ostream &tok, const Matrica<TipElemenata> &m)
{
    int pomocna(tok.width());
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++)
            tok<<std::setw(pomocna)<<m.elementi[i][j];
        tok<<std::endl;
    }
    return tok;
}

template <typename TipElemenata>
std::istream &operator >>(std::istream &tok, const Matrica<TipElemenata> &m)
{
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++) {
            std::cout<<m.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            tok>>m.elementi[i][j];
        }
    return tok;
}

template <typename TipElemenata>
void Matrica<TipElemenata>::SacuvajUTekstualnuDatoteku (const char *ime) const
{
    std::ofstream izlazni_tok(ime);
    if(!izlazni_tok)
        throw std::logic_error("Problemi sa upisom u datoteku");
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) {
            izlazni_tok<<elementi[i][j];
            if(j!=br_kolona-1) izlazni_tok<<",";
        }
        izlazni_tok<<std::endl;
    }
    if(!izlazni_tok)
        throw std::logic_error("Problemi sa upisom u datoteku");
}

template <typename TipElemenata>
void Matrica<TipElemenata>::SacuvajUBinarnuDatoteku (const char *ime) const
{
    std::ofstream izlazni_tok(ime, std::ios::binary);
    izlazni_tok.write((char*) this, sizeof *this);
    for(int i=0; i<br_redova; i++)
        izlazni_tok.write((char *) elementi[i], br_kolona*sizeof(TipElemenata));
    if(!izlazni_tok)
        throw std::logic_error("Problemi sa upisom u datoteku");
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije");
    Matrica<TipElemenata> zbir(m1.br_redova, m1.br_kolona);
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            zbir.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return zbir;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator *(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    Matrica<TipElemenata> proizvod(m1);
    return proizvod*=m2;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator *(const Matrica<TipElemenata> &m1, double broj)
{
    return broj*m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator *(double broj, const Matrica<TipElemenata> &m1)
{
    auto rezultat(m1);
    for(int i=0; i<rezultat.br_redova; i++)
        for(int j=0; j<rezultat.br_kolona; j++)
            rezultat[i][j]*=broj;
    return rezultat;
}

int main ()
{
    try {
        Matrica<double> matrica {2,2};
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                matrica[i][j]=i+j+0.5;
        std::cout<<std::setw(6)<<matrica;
        matrica.ObnoviIzTekstualneDatoteke("TEST.txt");
    } catch (std::logic_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}
