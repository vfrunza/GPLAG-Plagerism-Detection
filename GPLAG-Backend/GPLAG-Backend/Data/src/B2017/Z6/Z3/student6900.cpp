#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <cmath>
#include <fstream>

template <typename TipEl>
class Matrica
{
    int br_redova, br_kolona;
    char ime_matrice;
    TipEl **elementi;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);
    void TestIndeksa(const int i, const int j) const {
        if (i<1 || i>br_redova || j<1 || j>br_kolona)
            throw std::range_error("Neispravan indeks");
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

    template <typename TipEl2>
    friend Matrica<TipEl2> ZbirMatrica(const Matrica<TipEl2> &m1,const Matrica<TipEl2> &m2);

    template <typename TipEl2>
    friend std::istream& operator >>(std::istream& tok, Matrica<TipEl2> &mat);

    template <typename TipEl2>
    friend std::ostream& operator <<(std::ostream &tok, const Matrica<TipEl2> &mat);

    template <typename TipEl2>
    friend Matrica<TipEl2> operator +(const Matrica<TipEl2> &m1, const Matrica<TipEl2> &m2);

    template <typename TipEl2>
    friend Matrica<TipEl2> operator -(const Matrica<TipEl2> &m1, const Matrica<TipEl2> &m2);

    template <typename TipEl2>
    friend Matrica<TipEl2> operator *(const Matrica<TipEl2> &m1, const Matrica<TipEl2> &m2);

    template <typename TipEl2>
    friend Matrica<TipEl2> operator *(Matrica<TipEl2> m, double x);

    template <typename TipEl2>
    friend Matrica<TipEl2> operator *(double x, Matrica<TipEl2> m);

    template <typename TipEl2>
    Matrica<TipEl2>& operator +=(const Matrica<TipEl2> &m) {
        return *this = *this + m;
    }

    template <typename TipEl2>
    Matrica<TipEl2>& operator -=(const Matrica<TipEl2> &m) {
        return *this = *this - m;
    }

    template <typename TipEl2>
    Matrica<TipEl2>& operator *=(const Matrica<TipEl2> &m) {
        return *this = *this * m;
    }

    auto operator *=(double x) -> decltype(*this) {
        return *this = *this * x;
    }

    auto operator [](int i) const -> typename std::remove_reference<decltype(*elementi)>::type {
        return elementi[i];
    }

    auto operator [](int i) -> decltype(*elementi) {
        return elementi[i];
    }

    auto operator ()(int i, int j) const -> typename std::remove_reference<decltype(**elementi)>::type {
        TestIndeksa(i, j);
        return elementi[i-1][j-1];
    }

    auto operator ()(int i, int j) -> decltype(**elementi) {
        TestIndeksa(i, j);
        return elementi[i-1][j-1];
    }

    operator std::string() const;

    void SacuvajUTekstualnuDatoteku(std::string ime_datoteke) const {
        std::ofstream izlazni_tok(ime_datoteke);
        for (int i = 0; i < br_redova; i++) {
            for (int j = 0; j < br_kolona; j++) {
                if (j!=br_kolona-1)
                    izlazni_tok << elementi[i][j] << ",";
                else
                    izlazni_tok << elementi[i][j];
                if (!izlazni_tok)
                    throw std::logic_error("Problemi sa upisom u datoteku");
            }
            izlazni_tok << std::endl;
        }
    }
    
    void SacuvajUBinarnuDatoteku(std::string ime_datoteke) const {
        std::ofstream izlazni_tok(ime_datoteke, std::ios::binary);
        izlazni_tok.write(reinterpret_cast<const char*>(this), sizeof *this);
        for (int i = 0; i < br_redova; i++) {
            for (int j = 0; j < br_kolona; j++) {
                izlazni_tok.write(reinterpret_cast<char*>(elementi[i][j]), sizeof(elementi[i][j]));
                if (!izlazni_tok)
                    throw std::logic_error("Problemi sa upisom u datoteku");
            }
        }
    }

    void ObnoviIzTekstualneDatoteke(std::string ime_datoteke) {
        std::ifstream ulazni_tok(ime_datoteke);
        if (!ulazni_tok)
            throw std::logic_error("Trazena datoteka ne postoji");
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }

    void ObnoviIzBinarneDatoteke(std::string ime_datoteke) {
        std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
        if (!ulazni_tok)
            throw std::logic_error("Trazena datoteka ne postoji");
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }

    Matrica(std::string ime_datoteke, bool var) {
        if (var) {
            std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
            if (!ulazni_tok)
                throw std::logic_error("Trazena datoteka ne postoji");
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        } else {
            std::ifstream ulazni_tok(ime_datoteke);
            if (!ulazni_tok)
                throw std::logic_error("Trazena datoteka ne postoji");
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
    }
};


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
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
    for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)
            Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
    KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(m.elementi)
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
std::istream& operator >>(std::istream& tok, Matrica<TipEl> &mat)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            tok >> mat.elementi[i][j];
        }
    }
    return tok;
}

template <typename TipEl>
std::ostream& operator <<(std::ostream &tok, const Matrica<TipEl> &mat)
{
    int sirina_ispisa(tok.width());
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            tok << std::setw(sirina_ispisa) << mat.elementi[i][j];
        tok << std::endl;
    }
    return tok;
}

template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
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
Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
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
Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if (m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m2.br_kolona; j++) {
            TipEl suma {};
            for (int k = 0; k < m1.br_kolona; k++)
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template <typename TipEl>
Matrica<TipEl> operator *(Matrica<TipEl> m, double x)
{
    for (int i = 0; i < m.br_redova; i++)
        for (int j = 0; j < m.br_kolona; j++)
            m.elementi[i][j]*=x;
    return m;
}

template <typename TipEl>
Matrica<TipEl> operator *(double x, Matrica<TipEl> m)
{
    for (int i = 0; i < m.br_redova; i++)
        for (int j = 0; j < m.br_kolona; j++)
            m.elementi[i][j]*=x;
    return m;
}

template <typename TipEl>
Matrica<TipEl>::operator std::string() const
{
    std::string rez("{");
    for (int i = 0; i < br_redova; i++) {
        rez+="{";
        for (int j = 0; j < br_kolona; j++) {
            rez+=std::to_string(int(elementi[i][j]));
            if (j!=br_kolona-1)
                rez+=",";
        }
        rez+="}";
        if (i!=br_redova-1)
            rez+=",";
    }
    rez+="}";
    return rez;
}

int main()
{
    return 0;
}