/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <sstream>

template <typename T>
class Matrica
{
    int red,kolona;
    char ime;
    T **pok;
    static T **AlocirajMemoriju(int red, int kolona);
    static void DealocirajMemoriju (T **pok, int red);
    void KopirajElemente (T **pok);
public:
    Matrica (int br_red, int br_kolona, char ime=0);
    Matrica (const Matrica &m);
    Matrica (Matrica &&m);
    ~Matrica () {DealocirajMemoriju(pok,red);}
    Matrica &operator= (const Matrica &m);
    Matrica &operator= (Matrica &&m);
    template <typename T2>
    friend Matrica<T2> operator+ (const Matrica<T2> &m1, const Matrica<T2> &m2);
    template <typename T2>
    friend std::ostream &operator<< (std::ostream &tok, const Matrica<T2> &m);
    template <typename T2>
    friend std::istream &operator>> (std::istream &tok, Matrica<T2> &m);
    template <typename T2>
    friend Matrica<T2> operator- (const Matrica<T2> &m1, const Matrica<T2> &m2);
    template <typename T2>
    friend Matrica<T2> operator* (const Matrica<T2> &m, double x);
    template <typename T2>
    friend Matrica<T2> operator* (double x, const Matrica<T2> &m);
    template <typename T2>
    friend Matrica<T2> operator* (const Matrica<T2> &m1, const Matrica<T2> &m2);
    Matrica &operator+= (const Matrica &m);
    Matrica &operator-= (const Matrica &m);
    Matrica &operator*= (double x);
    Matrica &operator*= (const Matrica &m);
    T *&operator[] (int x) {return pok[x];}
    T *operator[] (int x) const {return pok[x];}
    T &operator() (int x, int y);
    T operator() (int x, int y) const;
    operator std::string() const;
    void SacuvajUTekstualnuDatoteku (std::string ime) const;
    void ObnoviIzTekstualneDatoteke (std::string ime);
    void SacuvajUBinarnuDatoteku (std::string ime) const;
    void ObnoviIzBinarneDatoteke (std::string ime);
    Matrica (std::string ime, bool lv);
};

template <typename T>
Matrica<T>::Matrica (std::string ime, bool lv):pok(nullptr)
{
    if (!lv) ObnoviIzTekstualneDatoteke(ime);
    else ObnoviIzBinarneDatoteke(ime);
}

template <typename T>
void Matrica<T>::ObnoviIzBinarneDatoteke (std::string ime)
{
    std::ifstream tok(ime,std::ios::binary);
    if (!tok) throw std::logic_error ("Trazena datoteka ne postoji");
    Matrica<T> temp(1,1);
    bool obnovi(false);
    if (pok) {
    temp=*this; obnovi=true;
    DealocirajMemoriju(pok,red);}
    tok.read(reinterpret_cast<char *> (this),sizeof *this);
    pok=AlocirajMemoriju(red,kolona);
    for (int i=0;i<red;i++)
        tok.read(reinterpret_cast<char *> (pok[i]),kolona*sizeof (T));
    if (!tok || tok.bad())
    {
        DealocirajMemoriju(pok,red);
        if (obnovi)
        *this=temp;
        throw std::logic_error ("Problemi pri citanju datoteke");
    }
}

template <typename T>
void Matrica<T>::SacuvajUBinarnuDatoteku (std::string ime) const
{
    std::ofstream tok(ime,std::ios::binary);
    tok.write(reinterpret_cast<const char*> (this),sizeof *this);
    for (int i=0;i<red;i++)
        tok.write(reinterpret_cast<char*> (pok[i]), kolona*sizeof (T));
    if (tok.bad() || !tok) throw std::logic_error ("Problemi sa upisom u datoteku");
}

template <typename T>
void Matrica<T>::ObnoviIzTekstualneDatoteke (std::string ime)
{
    std::ifstream tok(ime);
    if (!tok) throw std::logic_error ("Trazena datoteka ne postoji");
    int br_redova(0),br_kolona(0);
    std::vector<int> kolone;
    T temp2;
    while (tok>>temp2)
    {
        char zarez;
        br_kolona++;
        if (tok.peek()==',') tok>>zarez;
        else
        {
            kolone.push_back(br_kolona);
            br_kolona=0;
            br_redova++;
        }
    }
    if (tok.eof()) int x(1);
    else if (tok.bad()) throw std::logic_error ("Problemi pri citanju datoteke");
    else throw std::logic_error ("Datoteka sadrzi besmislene podatke");
    for (int i=0;i<kolone.size();i++)
    {
        for (int j=i+1;j<kolone.size();j++)
        {
            if (kolone[i]!=kolone[j]) throw std::logic_error ("Datoteka sadrzi besmislene podatke");
        }
    }
    tok.close();
    tok.open(ime);
    Matrica<T> temp(1,1);
    bool obnovi(false);
    if (pok) {
    DealocirajMemoriju(pok,red); obnovi=true;
    temp=*this;}
    pok=AlocirajMemoriju(br_redova,kolone[0]); red=br_redova; kolona=kolone[0];
    for (int i=0;i<red;i++)
    {
        for (int j=0;j<kolona;j++)
        {
            tok>>pok[i][j];
            char znak;
            if (j!=kolona-1) tok>>znak;
        }
    }
    if (tok.bad())
    {
        DealocirajMemoriju(pok,red);
        if (obnovi)
        *this=temp;
        throw std::logic_error ("Problemi pri citanju datoteke");
    }
}

template <typename T>
void Matrica<T>::SacuvajUTekstualnuDatoteku (std::string ime) const
{
    std::ofstream tok(ime);
    if (!tok) throw std::logic_error ("Problemi sa upisom u datoteku");
    for (int i=0;i<red;i++)
    {
        for (int j=0;j<kolona;j++)
        {
            tok<<pok[i][j];
            if (j!=kolona-1) tok<<",";
        }
        if (i!=red-1)
        tok<<std::endl;
    }
    if (tok.bad() || !tok) throw std::logic_error ("Problemi sa upisom u datoteku");
}

template <typename T>
Matrica<T>::operator std::string () const
{
    std::ostringstream tok;
    tok<<"{";
    for (int i=0;i<red;i++)
    {
        tok<<"{";
        for (int j=0;j<kolona;j++)
        {
            tok<<pok[i][j];
            if (j!=kolona-1) tok<<",";
        }
        tok<<"}";
        if (i!=red-1) tok<<",";
    }
    tok<<"}";
    return tok.str();
}

template <typename T>
T Matrica<T>::operator() (int x, int y) const
{
    if (x<1 || y<1 || x>red || y>kolona) throw std::range_error ("Neispravan indeks");
    return pok[x-1][y-1];
}

template <typename T>
T &Matrica<T>::operator() (int x, int y)
{
    if (x<1 || y<1 || x>red || y>kolona) throw std::range_error ("Neispravan indeks");
    return pok[x-1][y-1];
}

template<typename T>
Matrica<T> &Matrica<T>::operator*= (const Matrica &m)
{
    if (kolona!=m.red) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto temp(*this*m);
    *this=std::move(temp);
    return *this;
}

template<typename T>
Matrica<T> &Matrica<T>::operator*= (double x)
{
    for (int i=0;i<red;i++)
    {
        for (int j=0;j<kolona;j++)
            pok[i][j]*=x;
    }
    return *this;
}

template<typename T>
Matrica<T> &Matrica<T>::operator-= (const Matrica &m)
{
    if (m.red!=red || m.kolona!=kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije");
    for (int i=0;i<red;i++)
    {
        for (int j=0;j<kolona;j++)
            pok[i][j]-=m.pok[i][j];
    }
    return *this;
}

template<typename T>
Matrica<T> &Matrica<T>::operator+= (const Matrica &m)
{
    if (red!=m.red || kolona!=m.kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije");
    for (int i=0;i<red;i++)
    {
        for (int j=0;j<kolona;j++)
            pok[i][j]+=m.pok[i][j];
    }
    return *this;
}

template<typename T>
Matrica<T> operator* (const Matrica<T> &m1, const Matrica<T> &m2)
{
    if (m1.kolona!=m2.red) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica<T> temp(m1.red,m2.kolona);
    for (int i=0;i<m1.red;i++)
    {
        for (int j=0;j<m2.kolona;j++)
        {
            temp.pok[i][j]=0;
            for (int k=0;k<m1.kolona;k++)
            temp.pok[i][j]+=m1.pok[i][k]*m2.pok[k][j];
        }
    }
    return temp;
}

template<typename T>
Matrica<T> operator* (const Matrica<T> &m, double x)
{
    Matrica<T> temp(m.red,m.kolona);
    for (int i=0;i<m.red;i++)
    {
        for (int j=0;j<m.kolona;j++)
            temp.pok[i][j]=x*m.pok[i][j];
    }
    return temp;
}

template<typename T>
inline Matrica<T> operator* (double x, const Matrica<T> &m)
{
    return m*x;
}

template<typename T>
Matrica<T> operator- (const Matrica<T> &m1, const Matrica<T> &m2)
{
    if (m1.red!=m2.red || m1.kolona!=m2.kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije");
    Matrica<T> temp(m1.red,m1.kolona);
    for (int i=0;i<m1.red;i++)
    {
        for (int j=0;j<m1.kolona;j++)
            temp.pok[i][j]=m1.pok[i][j]-m2.pok[i][j];
    }
    return temp;
}

template<typename T>
std::istream &operator>> (std::istream &tok, Matrica<T> &m)
{
    for (int i=0;i<m.red;i++)
    {
        for (int j=0;j<m.kolona;j++)
        {
            std::cout<<m.ime<<"("<<i+1<<","<<j+1<<") = ";
            tok>>m.pok[i][j];
        }
    }
    return tok;
}

template<typename T>
std::ostream &operator<< (std::ostream &tok, const Matrica<T> &m)
{
    int x(tok.width());
    for (int i=0;i<m.red;i++)
    {
        for (int j=0;j<m.kolona;j++)
            tok<<std::setw(x)<<m.pok[i][j];
        tok<<std::endl;
    }
    return tok;
}

template<typename T>
Matrica<T> operator+ (const Matrica<T> &m1, const Matrica<T> &m2)
{
    if (m1.red!=m2.red || m1.kolona!=m2.kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije");
    Matrica<T> temp(m1.red,m1.kolona);
    for (int i=0;i<m1.red;i++)
    {
        for (int j=0;j<m1.kolona;j++)
            temp.pok[i][j]=m1.pok[i][j]+m2.pok[i][j];
    }
    return temp;
}

template<typename T>
T **Matrica<T>::AlocirajMemoriju (int red, int kolona)
{
    T **pok(new T*[red]{});
    try 
    {
        for (int i=0;i<red;i++) pok[i]=new T[kolona];
    }
    catch(std::bad_alloc)
    {
        DealocirajMemoriju(pok,red); throw;
    }
    return pok;
}

template<typename T>
void Matrica<T>::DealocirajMemoriju (T **pok, int broj)
{
    if (!pok) return;
    for (int i=0;i<broj;i++) delete[] pok[i];
    delete[] pok;
}

template<typename T>
Matrica<T>::Matrica (int br_red, int br_kol, char ime):red(br_red),kolona(br_kol),ime(ime),pok(AlocirajMemoriju(br_red,br_kol)) {}

template<typename T>
void Matrica<T>::KopirajElemente (T **el)
{
    for (int i=0;i<red;i++)
    {
        for (int j=0;j<kolona;j++)
            pok[i][j]=el[i][j];
    }
}

template<typename T>
Matrica<T>::Matrica (const Matrica<T> &m):red(m.red),kolona(m.kolona),ime(m.ime),pok(AlocirajMemoriju(m.red,m.kolona))
{
    KopirajElemente(m.pok);
}

template<typename T>
Matrica<T>::Matrica (Matrica<T> &&m):red(m.red),kolona(m.kolona),ime(m.ime),pok(m.pok)
{
    m.red=0; m.pok=nullptr;
}

template<typename T>
Matrica<T> &Matrica<T>::operator= (const Matrica<T> &m)
{
    if (red<m.red || kolona<m.kolona)
    {
        T **novi(AlocirajMemoriju(m.red,m.kolona));
        DealocirajMemoriju(pok,red);
        pok=novi;
        KopirajElemente(m.pok);
        red=m.red; kolona=m.kolona; ime=m.ime;
    }
    else
    {
        for (int i=m.red;i<red;i++) delete [] pok[i];
        red=m.red; kolona=m.kolona; ime=m.ime;
        KopirajElemente(m.pok);
    }
    return *this;
}

template<typename T>
Matrica<T> &Matrica<T>::operator= (Matrica<T> &&m)
{
    std::swap(red,m.red); std::swap(kolona,m.kolona); std::swap(ime,m.ime);
    std::swap(pok,m.pok);
    return *this;
}

int main ()
{
    try
    {
        Matrica<double> m1(3,3),m2(3,3);
        std::cout<<"Unesite matricu m1: ";
        std::cin>>m1;
        std::cout<<"Unesite matricu m2: ";
        std::cin>>m2;
        m1.SacuvajUTekstualnuDatoteku("proba.txt");
        m2.SacuvajUBinarnuDatoteku("PROBA.DAT");
        try{
        Matrica <double> m3("proba.txt",false),m4("PROBA.DAT",true);
        m1.ObnoviIzBinarneDatoteke("PROBA.DAT");
        m2.ObnoviIzTekstualneDatoteke("proba.txt");
        std::cout<<"Matrica m1: "<<std::endl;
        std::cout<<std::setw(6)<<m1<<std::endl;
        std::cout<<"Matrica m2: "<<std::endl;
        std::cout<<std::setw(6)<<m2<<std::endl;
        std::cout<<"Matrica m3: "<<std::endl;
        std::cout<<std::setw(6)<<m3<<std::endl;
        std::cout<<"Matrica m4: "<<std::endl;
        std::cout<<std::setw(6)<<m4<<std::endl;}
        catch(std::logic_error e) {
            std::cout<<e.what()<<std::endl;
        }
    }
    catch(std::bad_alloc)
    {
        std::cout<<"Nedovoljno memorije"<<std::endl;
    }
	return 0;
}
