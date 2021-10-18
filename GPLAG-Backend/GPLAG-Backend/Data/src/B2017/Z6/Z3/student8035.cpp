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
    int br_redova, br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl **elementi, int br_redova);
    void KopirajElemente(TipEl **elementi);
    void TestIndeksa(int indeks1, int indeks2) const
    {
        if(indeks1<1 || indeks2<1 || indeks1>br_redova || indeks2>br_kolona) throw std::range_error("Neispravan indeks");
    }
public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const Matrica &m);
    Matrica(Matrica &&m);
    Matrica(const char ime[], bool binarna) : elementi(nullptr)
    {
        if(binarna) ObnoviIzBinarneDatoteke(ime);
        else ObnoviIzTekstualneDatoteke(ime);
    }
    ~Matrica()
    { DealocirajMemoriju(elementi, br_redova); }
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);
    TipEl &operator()(int a, int b)
    {
        TestIndeksa(a,b);
        return elementi[a-1][b-1];
    }
    TipEl operator()(int a, int b) const
    {
        TestIndeksa(a,b);
        return elementi[a-1][b-1];
    }
    friend std::istream &operator>>(std::istream &tok, const Matrica &m)
    {
        for(int i = 0; i < m.br_redova; i++)
        for(int j = 0; j < m.br_kolona; j++)
        {
            std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> m.elementi[i][j];
        }
        return tok;
    }
    friend std::ostream &operator<<(std::ostream &tok, const Matrica &m)
    {
        int sirina(tok.width());
        for(int i = 0; i < m.br_redova; i++)
        {
            for(int j = 0; j < m.br_kolona; j++)
            tok << std::setw(sirina) << m.elementi[i][j];
            tok << std::endl;
        }
        return tok;
    }
    friend Matrica operator+(const Matrica &m1, const Matrica &m2)
    {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
    Matrica operator+=(const Matrica &m1)
    {
        if(m1.br_redova != br_redova || m1.br_kolona != br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + elementi[i][j];
        *this=m3;
        return *this;
    }
    Matrica operator-=(const Matrica &m1)
    {
        if(m1.br_redova != br_redova || m1.br_kolona != br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = elementi[i][j] - m1.elementi[i][j];
        *this=m3;
        return *this;
    }
    friend Matrica operator-(const Matrica &m1, const Matrica &m2)
    {
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
        return m3;
    }
    operator std::string() const
    {
        std::string s;
        s.push_back('{');
        std::string ns;
        for(int i=0;i<br_redova;i++)
        {
            s.push_back('{');
            for(int j=0;j<br_kolona;j++)
            {
                if(j==br_kolona-1)
                {
                    s+=std::to_string(int(elementi[i][j]));
                    s.push_back('}');
                    break;
                }
                s+=std::to_string(int(elementi[i][j]));
                s.push_back(',');
            }
            if(i==br_redova-1)
            {
                s.push_back('}'); break;
            }
        s.push_back(',');
        }
        return s;   
    }
    friend Matrica operator*(double broj, const Matrica &m2)
    {
        Matrica<TipEl> m3(m2.br_redova, m2.br_kolona);
        for(int i = 0; i < m2.br_redova; i++)
            for(int j = 0; j < m2.br_kolona; j++)
                m3.elementi[i][j] = m2.elementi[i][j] * broj;
        return m3;
    }
    friend Matrica operator*(const Matrica &m2, double broj)
    {
        Matrica<TipEl> m3(m2.br_redova, m2.br_kolona);
        for(int i = 0; i < m2.br_redova; i++)
            for(int j = 0; j < m2.br_kolona; j++)
                m3.elementi[i][j] = m2.elementi[i][j] * broj;
        return m3;
    }
    friend Matrica operator*(const Matrica &m1, const Matrica &m2)
    {
        if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        
        Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
        
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m2.br_kolona; j++)
            {
                double suma(0);
                for(int k = 0; k < m2.br_redova; k++)
                {
                    suma+=m1.elementi[i][k]*m2.elementi[k][j];
                }
                m3.elementi[i][j] = suma;
            }
        
        return m3;
        
    }
    Matrica operator *=(const Matrica &m2)
    {
        if(br_kolona != m2.br_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        Matrica <TipEl> m3(br_redova,m2.br_kolona);
        for(int i = 0; i < br_redova; i++)
            for(int j = 0; j < m2.br_kolona; j++)
            {
                double suma(0);
                for(int k = 0; k < m2.br_redova; k++)
                {
                    suma+=elementi[i][k]*m2.elementi[k][j];
                }
                m3.elementi[i][j] = suma;
            }
        *this=m3;
        return *this;
    }
    Matrica operator *=(double broj)
    {
        Matrica <TipEl> m3(br_redova,br_kolona);
        for(int i = 0; i < br_redova; i++)
            for(int j = 0; j < br_kolona; j++)
            {
                
                m3.elementi[i][j] = elementi[i][j]*broj;
            }
        *this=m3;
        return *this;
    }
    TipEl* &operator[](int indeks)
    {
        return elementi[indeks];
    }
    TipEl* operator[](int indeks) const
    {
        return elementi[indeks];
    }
    
    void SacuvajUTekstualnuDatoteku(const char ime[]) const;
    void SacuvajUBinarnuDatoteku(const char ime[]) const;
    void ObnoviIzTekstualneDatoteke(const char ime[]);
    void ObnoviIzBinarneDatoteke(const char ime[]);
    
};

template <typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(const char ime[]) const
{
    std::ofstream dat(ime);
    for(int i=0;i<br_redova;i++)
    {
        for(int j=0;j<br_kolona;j++)
        {
            dat<<elementi[i][j];
            if(j!=br_kolona-1) dat<<",";
            if(!dat || dat.bad()) throw std::logic_error("Problemi sa upisom u datoteku");
        }
        dat<<std::endl;
    }
    if(!dat || dat.bad()) throw std::logic_error("Problemi sa upisom u datoteku");
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(const char ime[])
{
    std::fstream dat(ime, std::ios::in);
    if(!dat) throw std::logic_error("Trazena datoteka ne postoji");
    int broj1(0),broj2(0);
    int broj3(0);
    while(true)
    {
        char c=dat.get();
        if(c==',') broj2++;
        else if(c=='\n')
        {
            dat>>std::ws;
            broj1++;
            while(dat.peek()=='\n') dat.get();
            if(broj1>1 && broj3!=broj2 ) 
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            broj3=broj2;
            broj2=0;
        }
        if(dat.eof()) break;
        if(!dat) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        if(dat.bad()) throw std::logic_error("Problemi pri citanju datoteke");
    }
    broj3++;
    broj1++;
    dat.close();
    dat.open(ime,std::ios::in);
    TipEl **novielementi(new TipEl*[broj1]{});
    for(int i=0;i<broj1;i++)
    {
        novielementi[i] = new TipEl[broj3];
        for(int j=0;j<broj3;j++)
        {
            TipEl unos;
            dat>>unos;
            char c=dat.get();
            if(dat.bad())
            {
                for(int k=0;k<=i;k++) delete[] novielementi[k];
                delete[] novielementi;
                throw std::logic_error("Problemi pri citanju datoteke");
            }
            if(((c!=',' && c!='\n') || !dat) && !dat.eof())
            {
                for(int k=0;k<=i;k++) delete[] novielementi[k];
                delete[] novielementi;
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            novielementi[i][j]=unos;
        }
    }
    if((!dat || dat.bad()) && !dat.eof())
    {
        for(int k=0;k<broj1;k++) delete[] novielementi[k];
        delete[] novielementi;
        throw std::logic_error("Problemi pri citanju datoteke");
    }
    if(elementi) DealocirajMemoriju(elementi,br_redova);
    std::swap(elementi,novielementi);
    br_redova=broj1;
    br_kolona=broj3;
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(const char ime[]) const
{
    
    std::ofstream izlazni_tok(ime, std::ios::binary);
    izlazni_tok.write(reinterpret_cast<const char*>(this), sizeof *this);
    for(int i=0;i<br_redova;i++) izlazni_tok.write(reinterpret_cast<char*>(elementi[i]),sizeof(TipEl)*br_kolona);
    if(!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(const char ime[])
{
    std::ifstream ulazni_tok(ime, std::ios::binary);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    if(elementi)
    {
        for(int i=0;i<br_redova;i++) delete elementi[i];
        delete[] elementi;
    }
    ulazni_tok.read(reinterpret_cast<char*>(this), sizeof *this);
    elementi = new TipEl*[br_redova];
    for(int i=0;i<br_redova;i++) elementi[i] = nullptr;
    for(int i=0;i<br_redova;i++)
    {
        elementi[i] = new TipEl[br_kolona];
        ulazni_tok.read(reinterpret_cast<char*>(elementi[i]), sizeof(TipEl)*br_kolona);
    }
    if(!ulazni_tok)
    {
        for(int i=0;i<br_redova;i++) delete elementi[i];
        delete[] elementi;
        throw std::logic_error("Problemi pri citanju datoteke");
    }
}

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
    TipEl **elementi(new TipEl*[br_redova]{});
    try
    {
        for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
    }
    catch(...)
    {
        DealocirajMemoriju(elementi, br_redova); throw;
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
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), 
br_kolona(br_kolona), elementi(AlocirajMemoriju(br_redova, br_kolona)), ime_matrice(ime)
{}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
    for(int i = 0; i < br_redova; i++)
    for(int j = 0; j < br_kolona; j++)
    Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
    KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
    m.br_redova = 0; m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
    if(br_redova < m.br_redova || br_kolona < m.br_kolona)
    {
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
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
    std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
    std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
    return *this;
}
int main()
{
    Matrica<int> m2(2,2);
    
    {
    Matrica<int> m1(2,2);
    std::cin>>m1;
    m1.SacuvajUBinarnuDatoteku("mat.dat");
    }
    m2.ObnoviIzBinarneDatoteke("mat.dat");
    return 0;
} 