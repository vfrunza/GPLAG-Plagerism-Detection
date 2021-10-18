/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <deque>


template <typename Tip>
struct Matrica
{
    int br_redova, br_kolona;
    Tip **elementi=nullptr;
};

template <typename Tip>
void UnistiMatricu(Matrica<Tip> m)
{
    if(!m.elementi) return;
    for(int i(0); i<m.br_redova; i++) 
        delete []m.elementi[i];
    delete []m.elementi;
    m.elementi=nullptr;
}

template <typename Tip>
Matrica<Tip> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<Tip> m;
    m.br_redova=br_redova;
    m.br_kolona=br_kolona;
    m.elementi=new Tip *[br_redova];
    for(int i(0); i<m.br_redova; i++)
        m.elementi[i]=nullptr;
    try
    {
        for(int i(0); i<m.br_redova; i++)
            m.elementi[i]=new Tip[br_kolona];
    }
    catch(...)
    {
        UnistiMatricu(m);
        throw;
    }
    return m;
}

template <typename Tip>
void UnesiMatricu(char ime, Matrica<Tip> &m)
{
    for(int i(0); i<m.br_redova; i++)
    {
        for(int j(0); j<m.br_kolona; j++)
        {
            std::cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>m.elementi[i][j];
        }
    }
}

template <typename Tip>
void IspisiMatricu(const Matrica<Tip> &m, int sirina_ispisa, int preciznost=6, bool izbrisi=false)
{
    for(int i(0); i<m.br_redova; i++)
    {
        for(int j(0); j<m.br_kolona; j++)
        {
            std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<m.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(izbrisi) UnistiMatricu(m);
}

template <typename Tip>
Matrica<Tip> ZbirMatrica(const Matrica<Tip> &m1, const Matrica<Tip> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<Tip>(m1.br_redova,m1.br_kolona));
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template <typename Tip>
Matrica<Tip> ProduktMatrica(const Matrica<Tip> &m1, const Matrica<Tip> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<Tip>(m1.br_redova, m2.br_kolona));
    Tip suma;
    for(int i(0); i<m1.br_redova; i++)
    {
        for(int j(0); j<m2.br_kolona; j++)
        {
            suma=0;
            for(int k(0); k<m2.br_redova; k++) 
                suma+=(m1.elementi[i][k]*m2.elementi[k][j]);
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template <typename Tip>
Matrica<Tip> JedinicnaMatrica(int n)
{
    auto m(StvoriMatricu<Tip>(n,n));
    for(int i(0); i<n; i++)
    {
        for(int j(0); j<n; j++)
        {
            if(i==j) m.elementi[i][j]=1;
            else  m.elementi[i][j]=0;
        }
    }
    return m;
}

template <typename Tip>
void Dodijeli(const Matrica<Tip> &m1, Matrica<Tip> &m2)
{
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m2.br_kolona; j++)
            m2.elementi[i][j]=m1.elementi[i][j];
}

template <typename Tip>
Matrica<Tip> Pomnozi(Matrica<Tip> m, Tip n)
{
    auto m1(StvoriMatricu<Tip>(m.br_redova,m.br_kolona));
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m1.br_kolona; j++)
            m1.elementi[i][j]=m.elementi[i][j]*n;
    return m1;
}

template <typename Tip>
Matrica<Tip> MatricniPolinom(const Matrica<Tip> &m, std::vector<Tip> v)
{
    if(m.br_redova!=m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto m1(StvoriMatricu<Tip>(m.br_redova,m.br_redova));
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m1.br_kolona; j++) m1.elementi[i][j]=0;
    if(v.size()==0) return m1;
    int p(m.br_redova);
    
    for(int i(0); i<v.size(); i++)
    {
        Matrica<Tip> m2(JedinicnaMatrica<Tip>(p));
        if(i==0)
        {
            Tip n(v[i]);
            Matrica<Tip> m3(Pomnozi<Tip>(m2,n));
            Matrica<Tip> m4(ZbirMatrica<Tip>(m1,m3));
            UnistiMatricu(m3);
            UnistiMatricu(m1);
            m1=m4;
        }
        else if(i==1)
        {
            Tip n(v[i]);
            Matrica<Tip> m3(Pomnozi<Tip>(m,n));
            Matrica<Tip> m4(ZbirMatrica<Tip>(m1,m3));
            UnistiMatricu(m3);
            UnistiMatricu(m1);
            m1=m4;
        }
        else 
        {
            Matrica<Tip> m3(StvoriMatricu<Tip>(m.br_redova,m.br_redova));
            for(int k(0); k<m.br_redova; k++)
                for(int z(0); z<m.br_redova; z++)
                    m3.elementi[k][z]=m.elementi[k][z];
            for(int j(2); j<=i; j++)
            {
                Matrica<Tip> m4(ProduktMatrica<Tip>(m,m3));
                UnistiMatricu(m3);
                m3=m4;
            }
            Tip n(v[i]);
            Matrica<Tip> m4(Pomnozi(m3,n));
            Matrica<Tip> m5(ZbirMatrica<Tip>(m1,m4));
            UnistiMatricu(m1);
            m1=m5;
            UnistiMatricu(m3);
        }
        UnistiMatricu(m2);
    }
    return m1;
}

template <typename Tip>
void UnosKoeficijenata(std::vector<Tip> &v,int n)
{
    Tip broj;
    for(int i(0); i<n; i++)
    {
        std::cin>>broj;
        v.push_back(broj);
    }
}

int main ()
{
    Matrica<double> m;
    try
    {
        std::cout<<"Unesite dimenziju kvadratne matrice: ";
        int n;
        std::cin>>n;
        std::cin.ignore(100000000,'\n');
        std::cout<<"Unesite elemente matrice A:";
        std::cout<<std::endl;
        m=StvoriMatricu<double>(n,n);
        UnesiMatricu('A',m);
        int p;
        std::vector<double> d;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>p;
        std::cin.ignore(1000000,'\n');
        std::cout<<"Unesite koeficijente polinoma: ";
        UnosKoeficijenata(d,p);
        Matrica<double> m1(MatricniPolinom(m,d));
        IspisiMatricu(m1,10,6,true);
    }
    catch(std::domain_error a)
    {
        std::cout<<a.what();
    }
    UnistiMatricu(m);   
	return 0;
}


















































