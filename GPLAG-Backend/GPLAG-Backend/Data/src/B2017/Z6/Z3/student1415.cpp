/B2017/2018: Zadaća 6, Zadatak 3
/*
   B16/17 (Tutorijal 12, Zadatak 6)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>

template <typename TipEl>
class Matrica
{
    int br_redova = 0, br_kolona = 0;
    TipEl **elementi = nullptr;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);

    static 	bool MoguSeMnoziti(Matrica m1, Matrica m2) {
        return (m1.br_kolona) == (m2.br_redova);
    }

    void ProvjeraIndexa (int x, int y ) const {
        if(x < 1 || x > br_redova || y < 1 || y > br_kolona ) throw std::range_error ("Neispravan indeks");
    }
    void ProvjeraIndexa(int x) const {
        if(x < 0 || x > br_redova - 1)throw std::range_error ("Neispravan indeks");
    }
    int BrojRedova(std::string ime_datoteke);
    int BrojKolona(std::string ime_datoteke);

public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(std::string ime_datoteke, bool iz_dat) {
        if(iz_dat)
            ObnoviIzBinarneDatoteke(ime_datoteke);
        else
            ObnoviIzTekstualneDatoteke(ime_datoteke);
    }
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    ~Matrica() {
        DealocirajMemoriju(elementi, br_redova);
    }
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);

    template <typename Tip3>
    friend std::ostream &operator<< (std::ostream &tok, const Matrica<Tip3> &mat);

    template <typename Tip3>
    friend std::istream &operator>> (std::istream &mecanje, Matrica<Tip3> &mat);

    template <typename Tip2>
    friend Matrica<Tip2> operator+ (const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

    template <typename Tip2>
    friend Matrica<Tip2> operator- (const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

    template <typename Tip2>
    friend Matrica<Tip2> operator* (const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

    template <typename Tip2, typename Tip3>
    friend Matrica<Tip2> operator* (const Matrica<Tip2> &m1, Tip3 skalar);

    template<typename Tip2, typename Tip3>
    friend Matrica<Tip2> operator* (Tip3 skalar, const Matrica<Tip2> &m1);


    Matrica<TipEl> &operator += (const Matrica<TipEl> &mat) {
        return *this = *this + mat;
    }
    Matrica<TipEl> &operator -= (const Matrica<TipEl> &mat) {
        return *this = *this - mat;
    }
    Matrica<TipEl> &operator *=(const Matrica<TipEl> &mat) {
        return *this = *this * mat;
    }
    Matrica<TipEl> &operator *=(TipEl skalar) {
        return *this = *this * skalar;
    }
    TipEl* &operator [] (int index) {
        ProvjeraIndexa(index);
        return elementi[index];
    }
    TipEl* operator [] (int index) const {
        ProvjeraIndexa(index);
        return elementi[index];
    }
    TipEl &operator () (int red, int kolona) {
        ProvjeraIndexa(red, kolona);
        return elementi[red - 1][kolona - 1];
    }
    TipEl operator () (int red, int kolona) const {
        ProvjeraIndexa(red,kolona);
        return elementi[red - 1][kolona - 1];
    }
    operator std::string() const {
        std::string novi("{");

        for(int i = 0; i < br_redova; i++) {
            novi += "{";
            for(int j = 0; j < br_kolona; j++) {
                novi += std::to_string(int(elementi[i][j]));
                if(j != br_kolona - 1) novi += ",";

            }
            novi += "}";
            if(i != br_redova - 1) novi+= ",";
        }
        return novi + "}";
    }
    void SacuvajUTekstualnuDatoteku(std::string ime_datoteke);
    void SacuvajUBinarnuDatoteku(std::string ime_datoteke);
    void ObnoviIzTekstualneDatoteke(std::string ime_datoteke);
    void ObnoviIzBinarneDatoteke (std::string ime_datoteke);

};
template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
    TipEl **elementi(new TipEl*[br_redova] {});
    try {
        for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona] {};
    } catch(...) {
        DealocirajMemoriju(elementi, br_redova);
        throw;
    }
    return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
    for(int i = 0; i < br_redova; i++) {
        delete[] elementi[i];
        elementi[i] = nullptr;
    };
    delete[] elementi;
    elementi = nullptr;;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime):
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

template <typename Tip3>
std::ostream &operator<< (std::ostream &tok, const Matrica<Tip3> &mat)
{

    auto velicina (tok.width());
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            tok << std::setw(velicina) << mat.elementi[i][j];
        tok << std::endl;
    }
    return tok;
}

template < typename Tip3>
std::istream &operator>> (std::istream &mecanje, Matrica<Tip3> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            mecanje >> mat.elementi[i][j];
        }
    return mecanje;
}

template <typename Tip2>
Matrica<Tip2> operator+ (const Matrica<Tip2> &m1, const Matrica<Tip2> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");

    Matrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}


template <typename Tip2>
Matrica<Tip2> operator- (const Matrica<Tip2> &m1, const Matrica<Tip2> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");

    Matrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
    return m3;
}

template <typename Tip2>
Matrica<Tip2> operator* (const Matrica<Tip2> &m1, const Matrica<Tip2> &m2)
{
    if(!m1.MoguSeMnoziti(m1,m2)) throw std::domain_error("Matrice nisu saglasne za mnozenje");

    Matrica<Tip2> m3(m1.br_redova, m2.br_redova);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++) {
            double suma(0);
            for(int k = 0; k < m2.br_redova; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    return m3;
}

template <typename Tip2, typename Tip3>
Matrica<Tip2> operator* (const Matrica<Tip2> &m1, Tip3 skalar)
{

    Matrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] * skalar;
    return m3;
}

template<typename Tip2, typename Tip3>
Matrica<Tip2> operator* (Tip3 skalar, const Matrica<Tip2> &m1)
{

    Matrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] * skalar;
    return m3;
}
template<typename Tip2>
void Matrica<Tip2>::SacuvajUTekstualnuDatoteku(std::string ime_datoteke)
{
    std::ofstream izlazni_tok (ime_datoteke);
    if(!izlazni_tok) throw std::logic_error("Trazena datoteka ne postoji");


    for(int i = 0; i < br_redova; i++) {
        for(int j = 0; j < br_kolona; j++) {

            izlazni_tok << elementi[i][j];
            if(j != br_kolona - 1) izlazni_tok << ",";

            if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
        }
        izlazni_tok << '\n';
    }
}

template<typename Tip2>
void Matrica<Tip2>::SacuvajUBinarnuDatoteku(std::string ime_datoteke)
{
    std::ofstream izlazni_tok(ime_datoteke, std::ios::binary);
    izlazni_tok.write(reinterpret_cast<const char*>(this), sizeof *this);
    for(int i = 0; i < br_redova; i++)
        izlazni_tok.write(reinterpret_cast<char*>(elementi[i]), (sizeof *elementi[i] * br_kolona));
    if(!izlazni_tok)
        throw std::logic_error("Problemi sa upisom u datoteku");


}
template <typename Tip2>
int Matrica<Tip2>::BrojRedova(std::string ime_datoteke)
{
    std::ifstream ulazni_tok(ime_datoteke);
    std::string kupi;
    int brojac(0);

    while(std::getline(ulazni_tok, kupi)) {
        if(kupi == "\n") continue;
        brojac++;
    }

    return brojac;
}
template <typename Tip2>
int Matrica<Tip2>::BrojKolona(std::string ime_datoteke)
{
    std::ifstream ulazni_tok(ime_datoteke);
    int broj_redova(BrojRedova(ime_datoteke)), testni(0);
    Tip2 kupi;
    for(int i = 0; i < broj_redova; i++) {
        int brojac(0);
        char znak;
        bool zarez_na_kraju(false);                     //"1.4{2.54@3.7*-4.7";
        while(ulazni_tok >> kupi) {

            brojac++;
            if(ulazni_tok.peek() != ',') break;
            else {
                ulazni_tok >> znak;
                ulazni_tok >> std::ws;
                if(znak == ',' && ulazni_tok.peek() == EOF && i == br_redova - 1) zarez_na_kraju = true;
            }
        }

        ulazni_tok >> std::ws;
        if(zarez_na_kraju)
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
        if(i == broj_redova - 1 && !ulazni_tok.eof()) {
            ulazni_tok >> znak;
            if(znak != EOF)  throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        if(i != 0 && testni != brojac)
            throw std::logic_error("Datoteka sadrzi besmislene podatke");

        testni = brojac;
        ulazni_tok.clear();
    }
    return testni;
}


template<typename Tip2>
void Matrica<Tip2>::ObnoviIzTekstualneDatoteke(std::string ime_datoteke)
{


    std::ifstream ulazni_tok(ime_datoteke);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    try {

        int redovi(BrojRedova(ime_datoteke)), kolone(BrojKolona(ime_datoteke));

        br_kolona = kolone;
        br_redova = redovi;

        if(elementi) DealocirajMemoriju(elementi, br_redova);
        elementi = AlocirajMemoriju(br_redova, br_kolona);

        char znak;
        Tip2 probni;


        for(int i = 0; i < br_redova; i++) {
            for(int j = 0; j < br_kolona; j++) {
                ulazni_tok >>  probni >> std::ws;
                if(i == br_redova - 1 && j == br_kolona - 1 && ulazni_tok.peek() == ',')
                    throw std::logic_error("Datoteka sadrzi besmislene podatke");

                if(ulazni_tok.peek() == ',') ulazni_tok >> znak;
                elementi[i][j] = probni;
            }
        }
    } catch(...) {
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    if(ulazni_tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");

}

template <typename Tip2>
void Matrica<Tip2>::ObnoviIzBinarneDatoteke (std::string ime_datoteke)
{

    std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    if(elementi) DealocirajMemoriju(elementi, br_redova);

    ulazni_tok.read(reinterpret_cast<char*>(this), sizeof *this);
    elementi = new Tip2*[br_redova];
    for(int i = 0; i < br_redova; i++) elementi[i] = nullptr;
    for(int i = 0; i < br_redova; i++) {
        elementi[i] = new Tip2[br_kolona];
        ulazni_tok.read(reinterpret_cast<char*>(elementi[i]), (sizeof *elementi[i] * br_kolona));
    }
    if(!ulazni_tok) {
        for(int i = 0; i < br_redova; i++) delete elementi[i];
        delete[] elementi;
        throw std::logic_error("Problemi pri citanju datoteke");
    }


}


int main()
{


    std::cout << "------------------------------" << std::endl;
    try {

        Matrica<char> b("testna", false);

        std::cout << std::setw(5) << b << std::endl;
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;

}