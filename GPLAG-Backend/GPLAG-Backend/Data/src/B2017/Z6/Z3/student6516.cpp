/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <vector>
#include <fstream>

template<typename TipEl>
class Matrica
{
    int br_redova, br_kolona;
    TipEl **elementi;
    char ime_matrice;
    static TipEl **AlocirajMemoriju (int br_redova, int br_kolona);
    static void DealocirajMemoriju (TipEl **elementi, int br_redova);
    void KopirajElemente (TipEl **elementi);

public:
    operator std::string() const;
    Matrica (int br_redova, int br_kolona, char ime=0);
    Matrica (const Matrica &m);
    Matrica(Matrica &&m);
    ~Matrica() {
        DealocirajMemoriju(elementi, br_redova);
    }
    Matrica &operator =(const Matrica &m);
    Matrica &operator =(Matrica &&m);

    template<typename Tip2>
    friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

    template<typename Tip2>
    friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

    template<typename Tip2>
    friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, const Matrica <Tip2> &m2);

    template<typename Tip2, typename Tip>
    friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, Tip a);

    template <typename Tip2, typename Tip>
    friend Matrica<Tip2> operator *(Tip a, const Matrica<Tip2> &m1);

    TipEl &operator ()(int broj_reda, int broj_kolone);
    TipEl operator ()(int broj_reda, int broj_kolone) const;
    std::vector<TipEl> operator[](int broj) const;

    TipEl* &operator [](int broj) {
        return elementi[broj];
    }

    Matrica<TipEl> &operator +=(const Matrica<TipEl> &m2) {
        return (*this=*this+m2);
    }
    Matrica<TipEl> &operator-=(const Matrica<TipEl> &m2) {
        return (*this=*this-m2);
    }
    Matrica<TipEl> &operator*=(const Matrica<TipEl> &m2) {
        return(*this=*this*m2);
    }
    Matrica<TipEl> &operator*=(TipEl a) {
        return (*this=*this*a);
    }

    template<typename Tip>
    friend std::ostream &operator <<(std::ostream &tok, const Matrica<Tip> &mat);

    template<typename Tip>
    friend std::istream &operator >>(std::istream &tok, Matrica<Tip> &mat);

    void SacuvajUTekstualnuDatoteku(const char ime[]) const;
    void SacuvajUBinarnuDatoteku(const char ime[]) const;
    void ObnoviIzTekstualneDatoteke(const char ime[]);
    void ObnoviIzBinarneDatoteke(const char ime[]);
    Matrica(const char ime[], bool vrijednost):br_redova(0), br_kolona(0) {
        if(!vrijednost) ObnoviIzTekstualneDatoteke(ime);
        else ObnoviIzBinarneDatoteke(ime);
    }
};

template<typename TipEl>
TipEl **Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
    TipEl **elementi(new TipEl*[br_redova] {});
    try {
        for(int i=0; i<br_redova; i++)
            elementi[i]=new TipEl[br_kolona];
    } catch(...) {
        DealocirajMemoriju(elementi, br_redova);
        throw;
    }
    return elementi;
}

template<typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
    for(int i=0; i<br_redova; i++)
        delete [] elementi[i];
    delete [] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime):br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime), elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template<typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++)
            Matrica::elementi[i][j]=elementi[i][j];
}

template<typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m): br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
    KopirajElemente(m.elementi);
}

template<typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m):br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
    m.br_redova=0;
    m.elementi=nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
    if(br_redova<m.br_redova || br_kolona<m.br_kolona) {
        TipEl **novi_prostor (AlocirajMemoriju(m.br_redova, m.br_kolona));
        DealocirajMemoriju(elementi, br_redova);
        elementi=novi_prostor;
    } else if(br_redova>m.br_redova)
        for(int i=m.br_redova; i<br_redova; i++)
            delete elementi[i];
    br_redova=m.br_redova;
    br_kolona=m.br_kolona;
    ime_matrice=m.ime_matrice;
    KopirajElemente(m.elementi);
    return *this;
}

template<typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
    std::swap(br_redova, m.br_redova);
    std::swap(br_kolona, m.br_kolona);
    std::swap(ime_matrice, m.ime_matrice);
    std::swap(elementi, m.elementi);
    return *this;
}
template<typename Tip>
std::istream &operator >>(std::istream &tok, Matrica<Tip> &mat)
{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<<mat.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            tok>>mat.elementi[i][j];
        }
    return tok;
}
template<typename Tip>
std::ostream &operator << (std::ostream &tok, const Matrica<Tip> &m)
{
    std::streamsize velicina(tok.width());
    for(int i=0; i<m.br_redova; i++) {
        for(int j=0; j<m.br_kolona; j++)
            tok<<std::setw(velicina)<<m.elementi[i][j];
        tok<<'\n';
    }
    return tok;
}
template<typename TipEl>
Matrica<TipEl> operator+(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template<typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
    return m3;
}

template<typename Tip>
Tip &Matrica<Tip>::operator ()(int broj_reda, int broj_kolone)
{
    broj_reda--;
    broj_kolone--;
    if(broj_reda<0 || broj_reda>=br_redova || broj_kolone<0 || broj_kolone>=br_kolona)
        throw std::range_error("Neispravan indeks");
    return elementi[broj_reda][broj_kolone];
}

template<typename Tip>
Tip Matrica<Tip>::operator ()(int broj_reda, int broj_kolone) const
{
    broj_reda--;
    broj_kolone--;
    if(broj_reda<0 || broj_reda>=br_redova || broj_kolone<0 || broj_kolone>=br_kolona)
        throw std::range_error("Neispravan indeks");
    return elementi[broj_reda][broj_kolone];
}

template<typename Tip>
std::vector<Tip> Matrica<Tip>::operator[](int broj) const
{
    std::vector<Tip> vek;
    for(int i=0; i<(this->br_kolona); i++)
        vek.push_back(elementi[broj][i]);
    return vek;
}

template<typename TipEl>
Matrica<TipEl>::operator std::string() const
{
    std::string pom="{";
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) {
            if(j==0)
                pom.push_back('{');
            char znak;
            long long int pom1=elementi[i][j];
            if(pom1<0) {
                pom.push_back('-');
                pom1*=-1;
            }
            std::vector<int> vek;
            while(pom1>0) {
                int pom3;
                pom3=(pom1%10);
                vek.push_back(pom3);
                pom1/=10;
            }
            for(int k=vek.size()-1; k>=0; k--) {
                znak=vek[k]+'0';
                pom.push_back(znak);
            }
            if(j==br_kolona-1) {
                pom.push_back('}');
                if(i!=br_redova-1)
                    pom.push_back(',');
            } else pom.push_back(',');
        }
    }
    pom.push_back('}');
    return pom;
}

template<typename Tip, typename Tip2>
Matrica<Tip> operator *(const Matrica<Tip> &m1, Tip2 x)
{
    Matrica<Tip> m2(m1);
    if(m2.br_redova==0 || m2.br_kolona==0)
        return m2;
    for(int i=0; i<m2.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            m2.elementi[i][j]*=x;
    return m2;
}
template<typename Tip, typename Tip2>
Matrica<Tip> operator *(Tip2 x, const Matrica<Tip> &m1)
{
    Matrica<Tip> m2(m1);
    if(m2.br_redova==0 || m2.br_kolona==0)
        return m2;
    for(int i=0; i<m2.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            m2.elementi[i][j]*=x;
    return m2;
}

template<typename Tip>
Matrica<Tip> operator *(const Matrica<Tip> &m1, const Matrica<Tip> &m2)
{
    if(m1.br_kolona!=m2.br_redova)
        throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica<Tip> m3(m1.br_redova, m2.br_kolona);
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            Tip suma=Tip();
            for(int k=0; k<m2.br_redova; k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
                m3.elementi[i][j]=suma;
            }
        }
    }
    return m3;
}

template<typename Tip>
void Matrica<Tip>::ObnoviIzBinarneDatoteke(const char ime[])
{
    std::ifstream dat(ime, std::ios::binary | std::ios::in);
    if(!dat) throw std::logic_error ("Trazena datoteka ne postoji");
    int pom1, pom2;
    dat.read((char*)(&pom1), sizeof(int));
    if(dat.bad() || pom1<0) {
        dat.clear();
        dat.close();
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    dat.read((char*)(&pom2), sizeof (int));
    if(dat.bad() || pom2<0) {
        dat.clear();
        dat.close();
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    dat.seekg(0, std::ios::end);
    int duzina(dat.tellg());
    int velicina=sizeof(Tip);
    duzina-=(2*sizeof(int));
    if((duzina/velicina)!=(pom1*pom2) || dat.bad()) {
        dat.clear();
        dat.close();
        throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }
    dat.seekg(0, std::ios::beg);
    if(br_redova!=0)
        DealocirajMemoriju(elementi, br_redova);
    dat.read((char*)(&br_redova), sizeof(int));
    dat.read((char*)(&br_kolona), sizeof(int));
    elementi=AlocirajMemoriju(br_redova, br_kolona);
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++) {
            dat.read((char*)(&elementi[i][j]), sizeof(Tip));
            if(dat.bad() || !dat) {
                dat.clear();
                DealocirajMemoriju(elementi, br_redova);
                dat.close();
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
        }
    dat.close();
}

template<typename Tip>
void Matrica<Tip>::SacuvajUBinarnuDatoteku(const char ime[]) const
{
    std::ofstream dat(ime, std::ios::binary);
    dat.write((char*)(&br_redova), sizeof(int));
    dat.write((char*)(&br_kolona), sizeof(int));
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++)
            dat.write((char*)(&elementi[i][j]), sizeof(Tip));
    }
    if(dat.bad()) {
        dat.clear();
        dat.close();
        throw std::logic_error("Problemi sa upisom u datoteku");
    }
    dat.close();
}

template<typename Tip>
void Matrica<Tip>::SacuvajUTekstualnuDatoteku(const char ime[]) const
{
    std::ofstream dat(ime);
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++) {
            dat<<elementi[i][j];
            if(dat.bad()) {
                dat.clear();
                dat.close();
                throw std::logic_error("Problemi sa upisom u datoteku");
            }
            if(j==br_kolona-1)
                dat<<'\n';
            else dat<<',';
            if(dat.bad()) {
                dat.clear();
                dat.close();
                throw std::logic_error("Problemi sa upisom u datoteku");
            }
        }
    dat.close();
}

template<typename Tip>
void Matrica<Tip>::ObnoviIzTekstualneDatoteke(const char ime[])
{
    std::ifstream dat(ime, std::ios::in);
    if(!dat)
        throw std::logic_error("Trazena datoteka ne postoji");
    char znak;
    int redova(1), kolona(1);
    std::vector<int> vek;
    while((znak=dat.get())!=EOF) {
        if(znak=='\n' &&(znak=dat.get())!=EOF) {
            redova++;
            vek.push_back(kolona);
            kolona=1;
        }
        if(znak==',') kolona++;
        else if((znak=='$' || znak=='*' || (znak>=33 && znak<=47)) && znak!='\n' && znak!='t' && znak!='-' || znak!='.')
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }

    for(int i=0; i<vek.size(); i++)
        if(vek[i]!=vek[0])
            throw std::logic_error("Datoteka sadrzi besmislene podatke");
    if(br_redova!=0)
        DealocirajMemoriju(elementi, br_redova);
    elementi=AlocirajMemoriju(redova, kolona);
    dat.close();
    dat.open(ime);
    for(int i=0; i<redova; i++) {
        Tip broj;
        znak=',';
        for(int j=0; j<kolona; j++) {
            if(j!=kolona-1)
                dat>>broj>>znak;
            else dat>>broj;
            if(dat.bad() && !dat.eof()) {
                dat.clear();
                dat.close();
                DealocirajMemoriju(elementi, br_redova);
                throw std::logic_error("Problemi pri citanju datoteke");
            }
            if((znak!=',' && znak!='\n')) {
                DealocirajMemoriju(elementi, br_redova);
                dat.clear();
                dat.close();
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            elementi[i][j]=broj;
        }
    }
    br_redova=redova;
    br_kolona=kolona;
    dat.close();
}

int main ()
{
    try {
        Matrica<double> a(2,1,'A'), b(2,1,'B');

        std::cout<<"Unesi matricu A: \n";
        std::cin>>a;

        std::cout<<"Unesi matricu B: \n";
        std::cin>>b;

        std::cout<<"Zbir ove dvije matrice je: \n";
        std::cout<<std::endl<<std::string(a);
    } catch(...) {
        std::cout<<"izuzetak";
    }
    return 0;
}
