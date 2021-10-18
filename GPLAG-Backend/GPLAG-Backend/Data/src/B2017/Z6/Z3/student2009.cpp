#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <fstream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::fstream;
using std::ofstream;

template <typename Tip> std::string KonverzijaUString(Tip a)
{
    std::ostringstream s;
    s << a;
    return
        s.str();
}

template <typename TipEl>
class Matrica
{
    int broj_redova=0, broj_kolona=0;
    TipEl **elementi=nullptr;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int broj_redova, int broj_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int broj_redova);
    void KopirajElemente(TipEl **elementi);

public:
    Matrica(): broj_redova(0),broj_kolona(0),elementi(nullptr), ime_matrice(0) {}
    Matrica(const char *c,bool b) {

        b?this->ObnoviIzBinarneDatoteke(c):this->ObnoviIzTekstualneDatoteke(c);
    }
    Matrica(TipEl x);
    Matrica(int broj_redova, int broj_kolona, char ime = 0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    ~Matrica() {
        DealocirajMemoriju(elementi, broj_redova);
    }
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);

    template <typename Tip2>
    friend std::istream &operator >> (std::istream &utok,Matrica<Tip2> &m);

    template <typename Tip2>
    friend std::ostream &operator << (std::ostream &tok, const Matrica<Tip2> &m);

    template <typename Tip2>
    friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);

    template <typename Tip2>
    friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);

    template <typename Tip2>
    friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);

    template <typename Tip2>
    friend Matrica<Tip2> operator *(Matrica<Tip2> &m1,double x);

    template <typename Tip2>
    friend Matrica<Tip2> operator *(double x,Matrica<Tip2> &m1);

    template <typename Tip2>
    friend Matrica<Tip2>& operator +=(Matrica<Tip2> &m1,const Matrica<Tip2> &m2);

    template <typename Tip2>
    friend Matrica<Tip2>& operator -=(Matrica<Tip2> &m1,const Matrica<Tip2> &m2);

    template <typename Tip2>
    friend Matrica<Tip2>& operator *=(Matrica<Tip2> &m1,const Matrica<Tip2> &m2);

    template <typename Tip2>
    friend Matrica<Tip2>& operator +=(Matrica<Tip2> &m1,double x);

    void SacuvajUTekstualnuDatoteku(const char *c) const;
    void SacuvajUBinarnuDatoteku(const char *c) const;
    void ObnoviIzTekstualneDatoteke(const char *c);
    void ObnoviIzBinarneDatoteke(const char *c);

    TipEl* operator [](int i) const {
        return elementi[i];
    }
    TipEl* &operator [](int i) {
        return elementi[i];
    }
    TipEl operator ()(int i, int j) const {
        if (i<1 || i>broj_redova) throw std::range_error("Neispravan indeks");
        if (j<1 || j>broj_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    TipEl &operator ()(int i, int j) {
        if (i-1<0 || i-1>broj_redova) throw std::range_error("Neispravan indeks");
        if (j-1<0 || j-1>broj_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }

    operator std::string() const {
        std::string povratni("{");
        for(int i = 0; i < broj_redova; i++) {
            povratni+='{';
            for(int j = 0; j < broj_kolona; j++) {
                povratni+=KonverzijaUString(elementi[i][j]);
                if (j!=broj_kolona-1)
                    povratni+=",";
            }
            povratni+="}";
            if (i!=broj_redova-1)
                povratni+=",";
        }
        povratni+="}";
        return povratni;
    }
};


template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int broj_redova, int broj_kolona)
{
    TipEl **elementi(new TipEl*[broj_redova] {});
    try {
        for(int i = 0; i < broj_redova; i++) elementi[i] = new TipEl[broj_kolona] {};
    } catch(...) {
        DealocirajMemoriju(elementi, broj_redova);
        throw;
    }
    return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int broj_redova)
{
    if(elementi!=nullptr) {
        for(int i = 0; i < broj_redova; i++) {
            delete[] elementi[i];
            elementi[i]=nullptr;
        }
        delete[] elementi;
        elementi=nullptr;
    }
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int broj_redova, int broj_kolona, char ime) :
    broj_redova(broj_redova), broj_kolona(broj_kolona),
    elementi(AlocirajMemoriju(broj_redova, broj_kolona)),ime_matrice(ime) {}


template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
    for(int i = 0; i < broj_redova; i++)
        for(int j = 0; j < broj_kolona; j++)
            Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : broj_redova(m.broj_redova),
    broj_kolona(m.broj_kolona), elementi(AlocirajMemoriju(m.broj_redova, m.broj_kolona)), ime_matrice(m.ime_matrice)
    
{
    KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : broj_redova(m.broj_redova),
    broj_kolona(m.broj_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
    m.broj_redova = 0;
    m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
    if(broj_redova < m.broj_redova || broj_kolona < m.broj_kolona) {
        TipEl **novi_prostor(AlocirajMemoriju(m.broj_redova, m.broj_kolona));
        DealocirajMemoriju(elementi, broj_redova);
        elementi = novi_prostor;
    } else if(broj_redova > m.broj_redova)
        for(int i = m.broj_redova; i < broj_redova; i++) delete elementi[i];
    broj_redova = m.broj_redova;
    broj_kolona = m.broj_kolona;
    ime_matrice = m.ime_matrice;
    KopirajElemente(m.elementi);
    return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
    std::swap(broj_redova, m.broj_redova);
    std::swap(broj_kolona, m.broj_kolona);
    std::swap(ime_matrice, m.ime_matrice);
    std::swap(elementi, m.elementi);
    return *this;
}

template <typename TipEl>
std::ostream &operator << (std::ostream &tok, const Matrica<TipEl> &m)
{
    int sirina=std::cout.width();
    for(int i = 0; i < m.broj_redova; i++) {
        for(int j = 0; j < m.broj_kolona; j++)
            tok << m.elementi[i][j] << std::setw(sirina);
        tok << std::endl;
    }
    return tok;
}

template <typename TipEl>
std::istream &operator >> (std::istream &utok,Matrica<TipEl> &m)
{
    for(int i = 0; i < m.broj_redova; i++)
        for(int j = 0; j < m.broj_kolona; j++) {
            std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            utok >> m.elementi[i][j];
        }
    return utok;
}

template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
    if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.broj_redova, m1.broj_kolona);
    for(int i = 0; i < m1.broj_redova; i++)
        for(int j = 0; j < m1.broj_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
    if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.broj_redova, m1.broj_kolona);
    for(int i = 0; i < m1.broj_redova; i++)
        for(int j = 0; j < m1.broj_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
    return m3;
}

template <typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
    if(m1.broj_kolona!=m2.broj_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> m3(m1.broj_redova,m2.broj_kolona);
    for(int i=0; i<m1.broj_redova; i++)
        for(int j=0; j<m2.broj_kolona; j++)
            for(int k=0; k<m1.broj_kolona; k++)
                m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
    return m3;
}

template <typename TipEl>
Matrica<TipEl> operator *(Matrica<TipEl> &m,double x)
{
    Matrica<TipEl> povratna(m.broj_redova, m.broj_kolona);
    for (int j=0; j<m.broj_redova; j++) {
        for (int k=0; k<m.broj_kolona; k++) {
            povratna.elementi[j][k]=m.elementi[j][k]*x;
        }
    }
    return povratna;
}

template <typename TipEl>
Matrica<TipEl> operator *(double x,Matrica<TipEl> &m1)
{
    return m1*x;
}

template <typename TipEl>
Matrica<TipEl>& operator +=(Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
    return m1 = m1+m2;
}

template <typename TipEl>
Matrica<TipEl>& operator -=(Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
    return m1 = m1-m2;
}

template <typename TipEl>
Matrica<TipEl>& operator *=(Matrica<TipEl> &m1,const Matrica<TipEl> &m2)
{
    return m1 = m1*m2;
}

template <typename TipEl>
Matrica<TipEl>& operator *=(Matrica<TipEl> &m1,double x)
{
    return m1 = m1*x;
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(const char *c) const
{
    ofstream dat(c);
    if(!dat) throw std::logic_error("Problemi sa upisom u datoteku");
    for(int i=0; i<broj_redova; i++) {
        for(int j=0; j<broj_kolona; j++) {
            dat << elementi[i][j];
            if(j!=broj_kolona-1) dat << ",";
        }
        dat << endl;
        if(dat.fail() ||dat.bad()) throw std::logic_error("Problemi sa upisom u datoteku");
    }
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(const char *c)
{
    ifstream dat(c);
    if(!dat) throw std::logic_error("Trazena datoteka ne postoji");
    int br_redova {}, br_kolona {};
    dat >> std::ws;
    char znak(0);
    while(!(znak=='\n' ||znak==EOF)) {
        TipEl x;
        dat >> x;
        znak=dat.get();
        if((dat.fail() && !dat.eof()) || !(znak==',' || znak==EOF || znak=='\n')) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        if(dat.bad()) throw std::logic_error("Problemi pri citanju datoteke");
        br_kolona++;
    }
    br_redova++;
    
    while(!(dat.eof() || dat.peek()==EOF)) {
        TipEl x;
        int i=br_kolona;
        dat >> std::ws;
        while(i!=0) {
            dat >> x;
            znak=dat.get();
            if((dat.fail() && !dat.eof()) || !(znak==',' || znak==EOF || znak=='\n')) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            if(dat.bad()) throw std::logic_error("Problemi pri citanju datoteke");
            i--;
        }
        if(znak=='\n' || znak==EOF) br_redova++;
        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    if(dat.fail()) dat.clear();
    Matrica<TipEl>temp(br_redova,br_kolona,'t');
    dat.seekg(0,ios::beg);
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++) {
            TipEl x;
            dat >> x;
            temp.elementi[i][j] = x;
            znak = dat.get();
        }
    if(elementi!=nullptr) this->DealocirajMemoriju(elementi,broj_redova);
    broj_kolona=temp.broj_kolona;
    broj_redova=temp.broj_redova;
    ime_matrice=temp.ime_matrice;
    elementi=temp.elementi;
    temp.elementi=nullptr;
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(const char *c) const
{
    std::ofstream bin(c,std::ios::binary);
    if(!bin) throw std::logic_error("Problemi sa upisom u datoteku");
    bin.write(reinterpret_cast<const char*>(this),sizeof *this);
    for(int i=0; i<broj_redova; i++)
        for(int j=0; j<broj_kolona; j++)
            bin.write(reinterpret_cast<char*>(&elementi[i][j]),sizeof(TipEl));
    if(bin.fail() ||bin.bad()) throw std::logic_error("Problem pri upisu u datoteku");
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(const char *c)
{
    std::ifstream bin(c,std::ios::binary);
    if(!bin) throw std::logic_error("Trazena datoteka ne postoji");
    Matrica<TipEl> temp;
    bin.read(reinterpret_cast<char*>(&temp),sizeof (Matrica));
    temp.elementi=nullptr;
    temp.elementi=AlocirajMemoriju(temp.broj_kolona,temp.broj_kolona);
    for(int i=0; i<temp.broj_redova; i++)
        for(int j=0; j<temp.broj_kolona; j++)
            bin.read(reinterpret_cast<char*>(&temp.elementi[i][j]),sizeof (TipEl));
    if(bin.fail() ||bin.bad() ||bin.peek()!=EOF) throw std::logic_error("Problemi pri citanju datoteke");
    if(elementi!=nullptr) this->DealocirajMemoriju(elementi,broj_redova);
    broj_kolona=temp.broj_kolona;
    broj_redova=temp.broj_redova;
    ime_matrice=temp.ime_matrice;
    elementi=temp.elementi;
    temp.elementi=nullptr;
}


int main()
{
    Matrica<double>a(5,5,'A');
    a[0][0]=4520.13; a[0][1]=1.113; a[0][2]=2.412; a[0][3]=3.14159265; a[0][4]=2.7182818;
    a[1][0]=265.18; a[1][1]=12.55; a[1][2]=23.23; a[1][3]=0.001; a[1][4]=436.83;
    a[2][0]=1; a[2][1]=99.3; a[2][2]=-5.55; a[2][3]=81.95; a[2][4]=1865.1;
    a[3][0]=26; a[3][1]=74.88; a[3][2]=-332.005; a[3][3]=72.3; a[3][4]=694.4;
    a[4][0]=8;  a[4][1]=0.01; a[4][2]=-21.42; a[4][3]=1559.39; a[4][4]=434.73;
    a.SacuvajUBinarnuDatoteku("mnd.dat");
    cout << std::setw(10) << a <<endl;
    Matrica<double>b("mnd.dat",true);
    b*=0.15;
    cout << std::setw(11) << b << endl;
    b*=7;
    b.SacuvajUTekstualnuDatoteku("mnd.txt");
    Matrica<double>c("mnd.txt",false);
    cout << std::setw(10) << c << endl;
    Matrica <double> d(c);
    Matrica<double> e(d*3.14);
    try{
        e.ObnoviIzBinarneDatoteke("invalidbin.dat"); // ovo baca izuzetak
        cout << std::setw(15) << e << endl; 
    }
    catch(std::exception &ex){
        cout <<ex.what()<< endl; 
    }
    try{
        e.ObnoviIzTekstualneDatoteke("invalid.txt"); // ovo baca izuzetak
        cout << std::setw(15) << e << endl; 
    }
    catch(std::exception &ex){
        cout <<ex.what()<< endl; 
    }
    
    Matrica<char>H(2,5,'H');
    H[0][0]='M'; H[0][1]='A'; H[0][2]='N'; H[0][3]='D'; H[0][4]='A';
    H[1][0]='D'; H[1][1]='K'; H[1][2]='I'; H[1][3]='N'; H[1][4]='G';
    cout << std::setw(5) << H << endl;
    H.SacuvajUTekstualnuDatoteku("theking.txt");
    Matrica<char>K("theking.txt",false);
    cout <<endl;
    K*=0.6;
    cout << std::setw(5) << K << endl;
    return 0;
}
