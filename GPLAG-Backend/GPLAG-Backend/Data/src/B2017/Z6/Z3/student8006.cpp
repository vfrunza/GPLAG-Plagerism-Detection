#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <string>
#include <new>
#include <fstream>
#include <sstream>

template <typename TipEl>
class Matrica {
    int br_redova, br_kolona;
    char ime_matrice;
    TipEl **elementi;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);
public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    Matrica(const char ime[], bool bitek);
    ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
    Matrica &operator = (const Matrica &m);
    Matrica &operator = (Matrica &&m);
    template <typename Tip2>
    friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    Matrica &operator += (const Matrica &m);
    Matrica &operator -= (const Matrica &m);
    Matrica &operator *= (const Matrica &m);
    Matrica &operator *= (double x);
    TipEl *operator [] (int x) const;
    TipEl *operator [] (int x);
    TipEl &operator () (int x, int y);
    TipEl operator () (int x, int y) const;
    operator std::string() const;
    template <typename Tip2>
    friend std::istream &operator >> (std::istream &tok, Matrica<Tip2> &m);
    template <typename Tip2>
    friend std::ostream &operator << (std::ostream &tok, const Matrica<Tip2> &m);
    template <typename Tip2>
    friend Matrica<Tip2> operator + (const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator - (const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator * (const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator * (const Matrica<Tip2> &m, double x);
    template <typename Tip2>
    friend Matrica<Tip2> operator * (double x, const Matrica<Tip2> &m);
    void SacuvajUTekstualnuDatoteku(const char ime[]) const;
    void ObnoviIzTekstualneDatoteke(const char ime[]);
    void SacuvajUBinarnuDatoteku(const char ime[]);
    void ObnoviIzBinarneDatoteke(const char ime[]);
};

template <typename TipEl>
TipEl **Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
    TipEl **elementi(new TipEl*[br_redova]{});
    try {
        for (int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona]{};
    }
    catch(...) {
        DealocirajMemoriju(elementi, br_redova); throw;
    }
    return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
    for (int i = 0; i < br_redova; i++) delete [] elementi[i];
    delete [] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
    br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
    elementi(AlocirajMemoriju(br_redova,br_kolona)) {}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
    for (int i = 0; i < br_redova; i++)
        for (int j = 0; j < br_kolona; j++)
            Matrica::elementi[i][j] = elementi[i][j];
}
    
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica &m) : br_redova(m.br_redova),
    br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), 
    elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
        KopirajElemente(m.elementi);
    }
    
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
    br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(m.elementi) {
        m.br_redova = 0; m.elementi = nullptr;
    }
    
template <typename TipEl>
Matrica<TipEl>::Matrica(const char ime[], bool bitek) : br_redova(1), 
    br_kolona(1), ime_matrice(0), elementi(AlocirajMemoriju(1,1)) {
    try {
        if (bitek) this->ObnoviIzBinarneDatoteke(ime);
        else this->ObnoviIzTekstualneDatoteke(ime);
    }
    catch (...) {
        DealocirajMemoriju(elementi,br_redova); throw;
    }
    
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator = (const Matrica<TipEl> &m) {
    if (br_redova < m.br_redova || br_kolona < m.br_kolona) {
        TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
        DealocirajMemoriju(elementi, br_redova);
        elementi = novi_prostor;
    }
    else if (br_redova > m.br_redova)
        for (int i = m.br_redova; i < br_redova; i++) delete elementi[i];
    br_redova = m.br_redova; br_kolona = m.br_kolona;
    ime_matrice = m.ime_matrice; KopirajElemente(m.elementi);
    return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator = (Matrica<TipEl> &&m) {
    std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
    std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
    return *this;
}

template <typename TipEl>
std::ostream &operator << (std::ostream &tok, const Matrica<TipEl> &m) {
    int sirina(tok.width());
    for (int i = 0; i < m.br_redova; i++) {
        for (int j = 0; j < m.br_kolona; j++) 
            tok << std::setw(sirina) << m.elementi[i][j];
        tok << std::endl;
    }
    return tok;
}

template <typename TipEl>
std::istream &operator >> (std::istream &tok, Matrica<TipEl> &m) {
    for (int i = 0; i < m.br_redova; i++)
        for (int j = 0; j < m.br_kolona; j++) {
            std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> m.elementi[i][j];
        }
    return tok;
}

template <typename TipEl>
Matrica<TipEl> operator + (const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
    auto m3(m1); return m3 += m2;
}

template <typename TipEl>
Matrica<TipEl> operator - (const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
    auto m3(m1); return m3 -= m2;
}

template <typename TipEl>
Matrica<TipEl> operator * (const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
    auto m3(m1); return m3 *= m2;
}

template <typename TipEl>
Matrica<TipEl> operator * (const Matrica<TipEl> &m, double x) {
    return Matrica<TipEl>(m) *= x;
}

template <typename TipEl>
Matrica<TipEl> operator * (double x, const Matrica<TipEl> &m) {
    return Matrica<TipEl>(m) *= x;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator += (const Matrica<TipEl> &m) {
    if (br_redova != m.br_redova || br_kolona != m.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for (int i = 0; i < br_redova; i++)
        for (int j = 0; j < br_kolona; j++)
            elementi[i][j] += m.elementi[i][j];
    return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator -= (const Matrica<TipEl> &m) {
    if (br_redova != m.br_redova || br_kolona != m.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for (int i = 0; i < br_redova; i++)
        for (int j = 0; j < br_kolona; j++)
            elementi[i][j] -= m.elementi[i][j];
    return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator *= (const Matrica<TipEl> &m) {
    if (br_kolona != m.br_redova) 
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> nova(br_redova, m.br_kolona);
    for (int i = 0; i < nova.br_redova; i++)
        for (int j = 0; j < nova.br_kolona; j++)
            for (int k = 0; k < br_kolona; k++)
                nova.elementi[i][j] += this->elementi[i][k] * m.elementi[k][j];
    return *this = nova;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator *= (double x) {
    for (int i = 0; i < br_redova; i++)
        for (int j = 0; j < br_kolona; j++)
            elementi[i][j] *= x;
    return *this;
}

template <typename TipEl>
TipEl *Matrica<TipEl>::operator [] (int x) const {
    return elementi[x];
}

template <typename TipEl>
TipEl *Matrica<TipEl>::operator [] (int x) {
    return elementi[x];
}

template <typename TipEl>
TipEl &Matrica<TipEl>::operator () (int x, int y) {
    if (x < 1 || x > br_redova || y < 1 || y > br_kolona)
        throw std::range_error("Neispravan indeks");
    return elementi[x-1][y-1];
}

template <typename TipEl>
TipEl Matrica<TipEl>::operator () (int x, int y) const {
    if (x < 1 || x > br_redova || y < 1 || y > br_kolona)
        throw std::range_error("Neispravan indeks");
    return elementi[x-1][y-1];
}

template <typename TipEl>
Matrica<TipEl>::operator std::string() const {
    std::string s;
    s += "{";
    for (int i = 0; i < br_redova; i++) {
        s += "{";
        for (int j = 0; j < br_kolona; j++) {
            std::ostringstream str;
            str << elementi[i][j];
            s += str.str();
            if (j != br_kolona - 1) s += ",";
        }
        s += "}";
        if (i != br_redova - 1) s += ",";
    }
    s += "}";
    return s;
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(const char ime[]) const {
    std::ofstream dat(ime);
    for (int i = 0; i < br_redova; i++) {
        for (int j = 0; j < br_kolona; j++) {
            dat << elementi[i][j];
            if (j != br_kolona - 1) dat << ",";
        }
        dat << std::endl;
    }
    if (!dat) throw std::logic_error("Problemi sa upisom u datoteku");
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(const char ime[]) {
    std::ofstream dat(ime, std::ios::binary);
    dat.write(reinterpret_cast<char*>(&br_redova), sizeof(br_redova));
    dat.write(reinterpret_cast<char*>(&br_kolona), sizeof(br_kolona));
    for (int i = 0; i < br_redova; i++)
        dat.write(reinterpret_cast<char*>(elementi[i]), sizeof(TipEl) * br_kolona);
    if (!dat) throw std::logic_error("Problemi sa upisom u datoteku");
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(const char ime[]) {
    std::ifstream dat(ime, std::ios::binary);
    if (!dat) throw std::logic_error("Trazena datoteka ne postoji");
    int x,y;
    if (!dat.read(reinterpret_cast<char*>(&x), sizeof(int)) || !dat.read(reinterpret_cast<char*>(&y), sizeof(int)))
        throw std::logic_error("Problemi pri citanju datoteke");
    Matrica<TipEl> nova(x,y,ime_matrice);
    for(int i = 0; i < x; i++) 
        if (!dat.read(reinterpret_cast<char*>(nova.elementi[i]), sizeof(TipEl) * y))
            throw std::logic_error("Problemi pri citanju datoteke");
    if(dat.tellg() != dat.seekg(0, std::ios::end).tellg()) throw std::logic_error("Problemi pri citanju datoteke");
    *this = nova;
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(const char ime[]) {
    std::ifstream dat(ime);
    if (!dat) throw std::logic_error("Trazena datoteka ne postoji");
    int x(0), y(-1), j(0);
    double z;
    char znak;
    for(;;) {
        if (dat.peek() == '-') dat >> znak;
        if (!(dat >> z)) break;
        j++;
        if (dat.peek() == '\n' || dat.peek() == EOF) {
            if (y == -1) y = j;
            else if (y != j) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            j = 0; x++; znak = ',';
        }
        else if (dat.peek() == ',') dat >> znak;
        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    if (!dat.eof() || (znak == '-' && j == 0)) throw std::logic_error("Datoteka sadrzi besmislene podatke");
    dat.close(); dat.open(ime);
    Matrica<TipEl> nova(x,y,ime_matrice);
    for (int i = 0; i < x; i++) 
        for (int j = 0; j < y; j++) {
            if (dat.peek() == '-') dat >> znak;
            dat >> nova.elementi[i][j];
            if (znak == '-') { nova.elementi[i][j] *= -1; znak = ','; }
            if (j != y - 1) dat >> znak;
        }
 //   if (!dat && !dat.eof()) throw std::logic_error("Problemi pri citanju datoteke");
    *this = nova;
}

int main ()
{
    int m, n;
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
        Matrica<double> c(m, n, 'C');
        std::cin >> c;
        c.SacuvajUBinarnuDatoteku("MATRICA.DAT");
        Matrica<double> d("MATRICA.DAT", true);
        std::cout << std::setw(7) << d;
        b.SacuvajUTekstualnuDatoteku("MATRICA.TXT");
        Matrica<double> e("MATRICA.TXT", false);
        std::cout << std::endl << std::setw(7) << e;
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
	return 0;
}