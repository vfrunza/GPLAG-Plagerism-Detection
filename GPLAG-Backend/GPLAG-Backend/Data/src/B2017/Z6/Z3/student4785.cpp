#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <fstream>
#include <new>

template <typename TipEl>
class Matrica
{
    int br_redova, br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);
    void Test(int x, int y) const {
        if(x<1 || y<1 || x>br_redova || y>br_kolona ) throw std::range_error("Neispravan indeks");
    }
public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    ~Matrica() {
        DealocirajMemoriju(elementi, br_redova);
    }
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);
    TipEl &operator ()(int i, int j) {
        Test(i,j);
        return elementi[i-1][j-1];
    }
    TipEl operator ()(int i, int j) const {
        Test(i,j);
        return elementi[i-1][j-1];
    }
    TipEl* operator [](int x) const {
        return elementi[x];
    }
    TipEl* &operator [](int x) {
        return elementi[x];
    }
    operator std::string() const {
        std::string matrica;
        matrica+="{";
        for(int i=0; i<br_redova; i++) {
            matrica+="{";
            for(int j=0; j<br_kolona; j++) {
                matrica+=std::to_string(int(elementi[i][j]));
                if(j!=br_kolona-1) matrica+=",";
            }
            matrica+="}";
            if(i!=br_redova-1) matrica+=",";
        }
        matrica+="}";
        return matrica;

    }
    template <typename Tip2>
    friend std::istream &operator >>(std::istream &tok, Matrica<Tip2> &m);
    template <typename Tip2>
    friend std::ostream &operator <<(std::ostream &tok, const Matrica<Tip2> &m);
    template <typename Tip2>
    friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, double n);
    template <typename Tip2>
    friend Matrica<Tip2> operator *(double n, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> &operator +=( Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> &operator -=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> &operator *=( Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> &operator *=( Matrica<Tip2> &m1, double n);
    template <typename Tip2>
    friend Matrica<Tip2> &operator *=( double n,Matrica<Tip2> &m1);
    void SacuvajUTekstualnuDatoteku(std::string datoteka) const {
        std::ofstream izlaz(datoteka);
        for(int i = 0; i <br_redova; i++) {
            for(int j = 0; j < br_kolona; j++) {
                izlaz<<elementi[i][j];
                if(j!=br_kolona-1) izlaz<<",";
            }
            izlaz<<std::endl;
        }
    }
    void SacuvajUBinarnuDatoteku(std::string datoteka) {
        std::ofstream izlaz(datoteka, std::ios::binary);
        izlaz.write(reinterpret_cast<char*>(this),sizeof(*this));
        if(!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
    }
    void ObnoviIzTekstualneDatoteke(std::string datoteka) {
        std::ifstream ulaz(datoteka);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        int br_kolona2=0;
        int br_redova2=0;
        char znak;
        TipEl element;
        int broj(0);
        while(ulaz>>element) {
            if(ulaz.peek()==',') {
                ulaz>>znak;
                if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                broj++;
            } else if(ulaz.peek()=='\n') {
                br_redova2++;
                ulaz.get();
                if(br_kolona2==0) br_kolona2=broj;
                else if(br_kolona2!=broj) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                broj=0;
            }
            else if(!ulaz.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        for(int i=0; i<br_redova; i++) delete[] elementi[i];
        delete[] elementi;
        ulaz.close();
        br_kolona=br_kolona2+1;
        br_redova=br_redova2+1;
        AlocirajMemoriju(br_redova,br_kolona);
        ulaz.open(datoteka);
        for(int i=0; i<br_redova; i++) {
            for(int j=0; j<br_kolona; j++) {
                ulaz>>elementi[i][j];
                if(ulaz.peek()==',') ulaz>>znak;
            }
        }
    }
    void ObnoviIzBinarneDatoteke(std::string datoteka) {
        std::ifstream ulaz(datoteka,std::ios::binary);
        if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        for(int i=0; i<br_redova; i++) delete[] elementi[i];
        delete[] elementi;
        br_kolona=0;
        br_redova=0;
        ulaz.read(reinterpret_cast<char*>(this),sizeof(*this));
    }
    Matrica(std::string datoteka, bool binarna) {
        if(binarna) {
            std::ifstream ulaz(datoteka,std::ios::binary);
            if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
            ulaz.read(reinterpret_cast<char*>(this),sizeof(*this));
        } else {
            std::ifstream ulaz(datoteka);
            br_kolona=br_redova=0;
            if(!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
            char znak;
            TipEl element;
            int broj(0);
            while(ulaz>>element) {
                if(ulaz.peek()==',') {
                    ulaz>>znak;
                    if(!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    broj++;
                } else if(ulaz.peek()=='\n') {
                    br_redova++;
                    ulaz.get();
                    if(br_kolona==0) br_kolona=broj;
                    else if(br_kolona!=broj) {
                        throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    }
                    broj=0;
                }
                else if(!ulaz.eof())throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            ulaz.close();
            br_kolona++;
            br_redova++;
            elementi=AlocirajMemoriju(br_redova,br_kolona);
            std::ifstream ulaz2(datoteka);
            for(int i=0; i<br_redova; i++) {
                for(int j=0; j<br_kolona; j++) {
                    ulaz2>>elementi[i][j];
                    if(ulaz2.peek()==',') ulaz2>>znak;
                }
            }
        }
    }

};

template <typename TipEl>
Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, double n)
{
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m1.elementi[i][j]*=n;
    return m1;
}

template <typename TipEl>
Matrica<TipEl> &operator *=(double n,Matrica<TipEl> &m1)
{
    return m1*=n;
}

template <typename TipEl>
Matrica<TipEl> &operator +=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m1.elementi[i][j] +=m2.elementi[i][j];
    return m1;
}
template <typename TipEl>
Matrica<TipEl> &operator -=( Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m1.elementi[i][j] -=m2.elementi[i][j];
    return m1;
}

template <typename TipEl>
Matrica<TipEl> &operator*=( Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
            m3.elementi[i][j]=TipEl();
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
            for(int k=0; k<m1.br_kolona; k++)
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
    m1=m3;
    return m1;
}

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
    TipEl **elementi(new TipEl*[br_redova] {});
    try {
        for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
    } catch(...) {
        DealocirajMemoriju(elementi, br_redova);
        throw;
    }
    return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
    for(int i = 0; i < br_redova; i++) delete[] elementi[i];
    delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
    br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
    elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
    br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
    elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
    KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
    br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
    m.br_redova = 0;
    m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
    if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
        TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
        DealocirajMemoriju(elementi, br_redova);
        elementi = novi_prostor;
    } else if(br_redova > m.br_redova)
        for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
    br_redova = m.br_redova;
    br_kolona = m.br_kolona;
    ime_matrice = m.ime_matrice;
    KopirajElemente(m.elementi);
    return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
    std::swap(br_redova, m.br_redova);
    std::swap(br_kolona, m.br_kolona);
    std::swap(ime_matrice, m.ime_matrice);
    std::swap(elementi, m.elementi);
    return *this;
}

template <typename TipEl>
std::istream &operator >>(std::istream &tok, Matrica<TipEl> &m)
{
    for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++) {
            std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            tok >> m.elementi[i][j];
        }
    return tok;
}

template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl> &m)
{
    int sirina=tok.width();
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++)
            tok << std::setw(sirina)<< m.elementi[i][j];
        tok << std::endl;
    }
    return tok;
}

template <typename TipEl>
Matrica<TipEl> operator+(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipEl>
Matrica<TipEl> operator-(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
    return m3;
}
template <typename TipEl>
Matrica<TipEl> operator*(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
            m3.elementi[i][j]=TipEl();
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
            for(int k=0; k<m1.br_kolona; k++)
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
    return m3;
}

template <typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1, double n)
{
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] *n;
    return m3;
}
template <typename TipEl>
Matrica<TipEl> operator *(double n,const Matrica<TipEl> &m1)
{
    return m1*n;
}


int main()
{
    
    return 0;
}