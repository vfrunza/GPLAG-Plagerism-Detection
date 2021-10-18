/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>


template <typename TipEl>
class Matrica
{
    int br_redova, br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    static void DealocirajMemoriju2(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);
public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    Matrica(const char ImeDatoteke[], bool koja)
    {
        if(koja == true) ObnoviIzBinarneDatoteke(ImeDatoteke);
        else ObnoviIzTekstualneDatoteke(ImeDatoteke);
    }
    
    ~Matrica() 
    {
        DealocirajMemoriju(elementi, br_redova);
    }
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);
    TipEl& operator ()(int i, int j);
    TipEl operator ()(int i, int j) const;
    TipEl* operator [](int i);
    TipEl* operator [](int i) const;
    template <typename Tip2>
    friend std::ostream& operator <<(std::ostream& Itok, const Matrica<Tip2>& mat);
    template <typename Tip2>
    friend std::istream& operator >>(std::istream& Utok, Matrica<Tip2>& mat);
    template <typename Tip2>
    friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, int x);
    template <typename Tip2>
    friend Matrica<Tip2> operator *(int x, const Matrica<Tip2> &m1);
    template <typename Tip2>
    friend Matrica<Tip2>& operator +=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2>& operator -=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
    template <typename Tip2>
    friend Matrica<Tip2>& operator *=(Matrica<Tip2> &m1, int x);
    operator std::string () const;
    
    void SacuvajUTekstualnuDatoteku(const char ImeDatoteke[]);
    void SacuvajUBinarnuDatoteku(const char ImeDatoteke[]);
    void ObnoviIzTekstualneDatoteke(const char ImeDatoteke[]);
    void ObnoviIzBinarneDatoteke(const char ImeDatoteke[]);
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
    if(elementi == nullptr)
        return;
    for(int i = 0; i < br_redova; i++) delete[] elementi[i];
    delete[] elementi;
}
template <typename TipEl>



void Matrica<TipEl>::DealocirajMemoriju2(TipEl **elementi, int br_redova)
{
    if(elementi == nullptr)
        return;
    for(int i = 0; i < br_redova; i++) delete[] elementi[i];
    
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime), elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

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
template <typename Tip2>
std::istream& operator >>(std::istream& Utok, Matrica<Tip2>& mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            Utok >> mat.elementi[i][j];
        }
    return Utok;
}
template <typename Tip2>
std::ostream& operator <<(std::ostream& Itok, const Matrica<Tip2>& mat)
{
    auto sirina(Itok.width());
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
           Itok << std::setw(sirina) << mat.elementi[i][j];
        Itok << std::endl;
    }
    return Itok;
}
template <typename Tip1>
Tip1& Matrica<Tip1>::operator ()(int i, int j)
{
    if(i < 1 || j < 1 || i > br_redova || j > br_kolona)
        throw std::range_error("Neispravan indeks");
    return elementi[i-1][j-1];
}
template <typename Tip1>
Tip1 Matrica<Tip1>::operator ()(int i, int j) const
{
    if(i < 1 || j < 1 || i > br_redova || j > br_kolona)
        throw std::range_error("Neispravan indeks");
    return elementi[i-1][j-1];
}
template <typename Tip1>
Tip1* Matrica<Tip1>::operator [](int i)
{
    return elementi[i];
}
template <typename Tip1>
Tip1* Matrica<Tip1>::operator [](int i) const
{
    return elementi[i];
}
template <typename Tip2>
Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2)
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
Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2)
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
Matrica<Tip2> operator *(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2)
{
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<Tip2> m3(m1.br_redova, m2.br_kolona);
    for(int i(0); i < m1.br_redova; i++)
    {
        for(int j(0); j < m2.br_kolona; j++)
        {
            Tip2 s{};
            for(int k(0); k < m1.br_kolona; k++)
                s += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = s;
        }
    }
    return m3;
}
template <typename Tip2>
Matrica<Tip2> operator *(const Matrica<Tip2> &m1, int x)
{
    Matrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] * x;
    return m3;
}
template <typename Tip2>
Matrica<Tip2> operator *(int x, const Matrica<Tip2> &m1)
{
    Matrica<Tip2> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] * x;
    return m3;
}
template <typename Tip2>
Matrica<Tip2>& operator +=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m1;
}
template <typename Tip2>
Matrica<Tip2>& operator -=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m1.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
    return m1;
}
template <typename Tip2>
Matrica<Tip2> operator *=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2){
    return m1 = m1 * m2;
}
template <typename Tip2>
Matrica<Tip2>& operator *=(Matrica<Tip2> &m1, int x)
{
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m1.elementi[i][j] = m1.elementi[i][j] * x;
    return m1;
}
template <typename Tip2>
Matrica<Tip2>::operator std::string () const
{
    std::string s = "{";
    for(int i(0); i < br_redova; i++)
    {
        s += "{";
        for(int j(0); j < br_kolona; j++)
        {
            std::ostringstream ss;
            ss << elementi[i][j];
            s += ss.str();
            if(j != br_kolona - 1)
                s += ",";
        }
        s += "}";
        if(i != br_redova - 1)
                s += ",";
    }
    s += "}";
    return s;
}

template <typename Tip2>
void Matrica<Tip2>::SacuvajUTekstualnuDatoteku(const char ImeDatoteke[])
{
    std::ofstream izlazni_tok(ImeDatoteke);
    if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
    else
    {
        for(int i=0; i<br_redova; i++)
        {
            for(int j=0; j<br_kolona; j++)
            {
                izlazni_tok << elementi[i][j];
                if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
                if(j != br_kolona-1)
                {
                    izlazni_tok << ",";
                    if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
                }
            }
            if(i != br_redova-1)
            {
                izlazni_tok << std::endl;
                if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
            }
        }
    }
}

template <typename Tip2>
void Matrica<Tip2>::SacuvajUBinarnuDatoteku(const char ImeDatoteke[])
{
    std::ofstream izlazni_tok(ImeDatoteke, std::ios::binary | std::ios::out);
    if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
    else
    {
        izlazni_tok.write((char*)&br_redova, sizeof(int));
        
        if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
        
        izlazni_tok.seekp(sizeof(int));
        izlazni_tok.write((char*)&br_kolona, sizeof(int));
        
        if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
        
        int pozicija = 2*sizeof(int);
        
        for(int i=0; i<br_redova; i++)
        {
            for(int j=0; j<br_kolona; j++)
            {
                izlazni_tok.seekp(pozicija);
                izlazni_tok.write((char*)&elementi[i][j], sizeof(Tip2));
                
                if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
                pozicija = pozicija + sizeof(Tip2);
            }
        }
    }
}

template <typename Tip2>
void Matrica<Tip2>::ObnoviIzBinarneDatoteke(const char ImeDatoteke[])
{
    std::ifstream ulazni_tok(ImeDatoteke, std::ios::binary | std::ios::in);
    
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    
    DealocirajMemoriju2(elementi, br_redova);
    
    int redovi, kolone;
    ulazni_tok.read((char*)&redovi, sizeof(int));
    
    if(!ulazni_tok) throw std::logic_error("Problemi pri citanju datoteke");
    
    ulazni_tok.seekg(sizeof(int));
    ulazni_tok.read((char*)&kolone, sizeof(int));
    
    if(!ulazni_tok) throw std::logic_error("Problemi pri citanju datoteke");
    int pozicija = 2*sizeof(int);
    
    this -> elementi = AlocirajMemoriju(redovi, kolone);
    
    for(int i=0; i<redovi; i++)
    {
        for(int j=0; i<kolone; j++)
        {
            ulazni_tok.seekg(pozicija);
            ulazni_tok.read((char*) &(this -> elementi[i][j]), sizeof(Tip2));
            
            if(!ulazni_tok) throw std::logic_error("Problemi pri citanju datoteke");
            
            pozicija = pozicija + sizeof(Tip2);
        }
    }
}

template <typename Tip2>
void Matrica<Tip2>::ObnoviIzTekstualneDatoteke(const char ImeDatoteke[])
{
    std::ifstream ulazni_tok(ImeDatoteke);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    
    else
    {
        DealocirajMemoriju2(elementi, br_redova);
        std::vector<std::vector<Tip2>> v;
        std::vector<Tip2> pomocni;
        Tip2 element;
        char c;
        
        while(ulazni_tok >> element)
        {
            pomocni.push_back(element);
            if(ulazni_tok.peek() == ',')
            {
                ulazni_tok >> c;
                continue;
            }
            else if(ulazni_tok.peek() == '\n')
            {
                v.push_back(pomocni);
                pomocni.resize(0);
                continue;
            }
            else if(ulazni_tok.eof())
            {
                v.push_back(pomocni);
                break;
            }
            
            if(!ulazni_tok.good()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            
        }
        if(ulazni_tok.eof());
        else 
        
       throw std::logic_error("Datoteka sadrzi besmislene podatke");
        //throw std::logic_error("Problemi pri citanju datoteke");
        elementi = AlocirajMemoriju(v.size(), v[0].size());
        
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[0].size(); j++)
            {
                if(v[0].size() != v[i].size())
                    if(!ulazni_tok.good()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                    
                    elementi[i][j] = v[i][j];
            }
        }
    }
}



int main()
{
    int m, n;
    std::cout << "Unesi broj redova i kolona za matrice:\n";
    std::cin >> m >> n;
    try 
    {
        Matrica<double> a(m, n, 'A'), b(m, n, 'B');
    std::cout << "Unesi matricu A:\n";
    std::cin >> a;
    std::string s = a;
    std::cout << s;
    std::cout << "Unesi matricu B:\n";
    std::cin >> b;
    std::cout << "Zbir ove dvije matrice je:\n";
    std::cout << std::setw(7) << a + b;
    
    
    }
    catch(std::bad_alloc) 
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return 0;
}