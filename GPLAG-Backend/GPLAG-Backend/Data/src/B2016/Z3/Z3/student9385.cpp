/B2016/2017: Zadaća 3, Zadatak 3

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include<vector>

using namespace std;

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return; //ako mi je nullptr ne mora nista da radi
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
        for( int i=0; i<br_redova; i++) {
            for( int j=0; j<br_kolona; j++) {
                mat.elementi[i][j]=0;
            }
        }
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }

    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> NapraviKopiju(Matrica<TipElemenata> a)
{
    Matrica<TipElemenata> nova;
    int br_kolona=a.br_kolona;
    int br_redova=a.br_redova;
    try {
        nova=StvoriMatricu<TipElemenata>(br_redova,br_kolona);
    } catch(std::bad_alloc) {
        UnistiMatricu(nova);
        throw;
    }
    for(int i=0; i<a.br_redova; i++) {
        for(int j=0; j<a.br_kolona; j++) {
            nova.elementi[i][j]=a.elementi[i][j];
        }
    }

    return nova;
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6 ,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<< mat.elementi[i][j];
        std::cout << std::endl;
    }

    if(treba_brisati==true) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipElemenata> m3;
    try {
        m3=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    } catch(std::bad_alloc) {
        UnistiMatricu(m3);
        throw;
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &a,const Matrica<TipElemenata> &b)
{
    if(a.br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu  saglasne za mnozenje");
    Matrica<TipElemenata>c;
    try {
        c=StvoriMatricu<TipElemenata>(a.br_redova, b.br_kolona);
    } catch(std::bad_alloc) {
        UnistiMatricu(c);
        throw;
    }
    for(int i=0; i<a.br_redova; i++) {
        for(int j=0; j<b.br_kolona; j++) {
            for(int k=0; k<b.br_redova; k++) {
                c.elementi[i][j]+=a.elementi[i][k]*b.elementi[k][j];
            }
        }
    }

    return c;
}

template<typename TipElemenata>
void PostaviNa(Matrica<TipElemenata> &b, Matrica<TipElemenata> a)
{
    UnistiMatricu(b);
    b=NapraviKopiju(a);
}

template<typename TipElemenata>
Matrica<TipElemenata> Stepenuj(Matrica<TipElemenata> a, int n)
{
    Matrica<TipElemenata> nova;
    nova=NapraviKopiju(a);
    Matrica<TipElemenata> tmp;

    try {
        tmp=StvoriMatricu<TipElemenata> (nova.br_redova, nova.br_kolona);
    } catch(...) {
        UnistiMatricu<TipElemenata> (tmp);
        throw;
    }

    if(n>=2) {
        UnistiMatricu(tmp);
        for(int i=0; i<n-1; i++) {
            tmp=ProduktMatrica(nova,a);
            PostaviNa(nova,tmp);
            UnistiMatricu(tmp);
        }
        return nova;
    }

    if(n==1) {
        UnistiMatricu(tmp);
        return nova;
    }

    if(n==0) {
        UnistiMatricu(tmp);
        for(int i=0; i<nova.br_redova; i++) {
            for(int j=0; j<nova.br_redova; j++) {
                if(i==j) nova.elementi[i][j]=1;
                else nova.elementi[i][j]=0;
            }
        }
        return nova;
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> PomnoziSkalarom(Matrica<TipElemenata> a, double broj)
{
    Matrica<TipElemenata> nova;

    try {
        nova= StvoriMatricu<TipElemenata> (a.br_redova, a.br_kolona);
    } catch(std::bad_alloc) {
        UnistiMatricu<TipElemenata> (nova);
        throw;
    }

    for(int i=0; i<a.br_redova; i++) {
        for(int j=0; j<a.br_kolona; j++) {
            nova.elementi[i][j]=a.elementi[i][j]*broj;
        }
    }
    return nova;
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> a, vector<double> v)
{
    if(a.br_redova!=a.br_kolona) throw domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> suma;

    try {
        suma=StvoriMatricu<TipElemenata> (a.br_redova, a.br_kolona);
    } catch(bad_alloc) {
        UnistiMatricu<TipElemenata>(suma);
        throw;
    }
    for(int i=0; i<v.size(); i++) {
        Matrica<TipElemenata> d=Stepenuj(a,i);
//       cout<<"Stepenovana: "<<endl;
//       IspisiMatricu<TipElemenata>(d,10,6,true);
        Matrica<TipElemenata> e=PomnoziSkalarom(d,v[i]);
//       cout<<"PomnoziSkalarom: "<<endl;
//       IspisiMatricu<TipElemenata>(e,10,6,true);

        Matrica<TipElemenata> f;
        f=ZbirMatrica(suma,e);
        UnistiMatricu(suma);
        suma=f;

        UnistiMatricu(d);
        UnistiMatricu(e);
    }
    return suma;
}

int main()
{
    Matrica<double> a, b, c,nova; // AUTOMATSKA INICIJALIZACIJA!!!
    int n, red_polinoma;
    double koeficijent_polinoma;
    vector<double> v;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n,n);
    } catch(std::domain_error greska) {
        UnistiMatricu<double> (a);
        UnistiMatricu<double> (nova);
        cout<<greska.what()<<endl;
        return 0;
    } catch(std::bad_alloc greska2) {
        UnistiMatricu<double> (a);
        UnistiMatricu<double> (nova);
        cout<<"Nema dovoljno memorije!";
        return 0;
    }
    std::cout << "Unesite elemente matrice A:\n";
    UnesiMatricu('A', a);
    cout<<"Unesite red polinoma: ";
    cin>>red_polinoma;
    cout<<"Unesite koeficijente polinoma: ";
    for(int i=0; i<=red_polinoma; i++) {
        cin>>koeficijent_polinoma;
        v.push_back(koeficijent_polinoma);
    }

    try {
        nova=MatricniPolinom<double> (a,v);
        IspisiMatricu<double> (nova,10,6,true);

    } catch(std::domain_error a) {
        UnistiMatricu<double> (nova);
        cout<<a.what()<<endl;
        return 0;
    } catch(std::bad_alloc b) {
        UnistiMatricu<double> (nova);

        cout<<"Nema dovoljno memorije!";
        return 0;
    }

    UnistiMatricu(a);
    return 0;
}