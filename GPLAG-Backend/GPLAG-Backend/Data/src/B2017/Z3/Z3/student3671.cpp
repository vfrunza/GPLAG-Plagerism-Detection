/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <new>
#include <iomanip>
#include <vector>
using namespace std;

template<typename Tip>
struct Matrica {
    int redovi,kolone;
    Tip **elementi=nullptr;
};

template<typename Tip>
void UnistiMatricu(Matrica<Tip>mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.redovi; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template<typename Tip>
Matrica<Tip>StvoriMatricu(int redovi,int kolone)
{
    Matrica<Tip>mat;
    mat.redovi=redovi;
    mat.kolone=kolone;
    mat.elementi=new Tip*[redovi];
    for(int i=0; i<redovi; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<redovi; i++) {
            mat.elementi[i]=new Tip[kolone];
        }
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename Tip>
void UnesiMatricu(char ime,Matrica<Tip>&m)
{
    for(int i=0; i<m.redovi; i++) {
        for(int j=0; j<m.kolone; j++) {
            cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
            cin>>m.elementi[i][j];
        }
    }
}

template<typename Tip>
void IspisiMatricu(const Matrica<Tip>&mat,int sirina_ispisa,int preciznost=6,int treba_brisati=false)
{
    for(int i=0; i<mat.redovi; i++) {
        for(int j=0; j<mat.kolone; j++) {
            cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
        }
        cout<<endl;
    }
}

template<typename Tip>
Matrica<Tip> ZbirMatrica(const Matrica<Tip>&m1,const Matrica<Tip>&m2)
{
    if(m1.redovi!=m2.redovi || m1.kolone!=m2.kolone) {
        throw domain_error("Matrice nemaju jednake dimenzije");
    }
    auto m3(StvoriMatricu<Tip>(m1.redovi,m1.kolone));
    for(int i=0; i<m1.redovi; i++) {
        for(int j=0; j<m1.kolone; j++) {
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template<typename Tip>
Matrica<Tip> ProduktMatrica(const Matrica<Tip>&m1,const Matrica<Tip>&m2)
{
    if(m1.kolone!=m2.redovi) throw domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<Tip>(m1.redovi,m2.kolone));
    for(int i(0); i<m3.redovi; i++) {
        for(int j(0); j<m3.kolone; j++) {
            m3.elementi[i][j]=0;
        }
    }
    for(int i=0; i<m1.redovi; i++) {
        for(int j=0; j<m2.kolone; j++) {
            for(int k=0; k<m1.kolone; k++) {
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template<typename Tip,typename Itertip>
Matrica<Tip>MatricniPolinom(const Matrica<Tip>&a,int n,Itertip it)
{
    if(n<0) {
        throw domain_error("Neispravan stepen polinoma");
    }
    if(a.redovi!=a.kolone) {
        throw domain_error("Matrica mora biti kvadratna");
    }

    auto jed(StvoriMatricu<Tip>(a.redovi,a.kolone));
    for(int i=0; i<a.redovi; i++) {
        for(int j=0; j<a.kolone; j++) {
            if(i==j) jed.elementi[i][j]=1;
            else jed.elementi[i][j]=0;
        }
    }

    auto m3(StvoriMatricu<Tip>(a.redovi,a.kolone));
    for(int i=0; i<a.redovi; i++) {
        for(int j=0; j<a.kolone; j++) {
            m3.elementi[i][j]=0;
        }
    }

    vector<Tip>koef;
    for(int i=0; i<=n; i++) {
        Tip x=*it++;
        koef.push_back(x);
    }

    for(int k=0; k<koef.size(); k++) {
        if(k==0) {
            for(int i=0; i<a.redovi; i++) {
                for(int j=0; j<a.kolone; j++) {
                    m3.elementi[i][j]+=jed.elementi[i][j]*koef[k];
                }
            }
        } else {
            auto matrica(StvoriMatricu<Tip>(a.redovi,a.kolone));
            for(int i=0; i<a.redovi; i++) {
                for(int j=0; j<a.kolone; j++) {
                    matrica.elementi[i][j]=a.elementi[i][j];
                }
            }
            for(int i=1; i<k; i++) {
                auto PomZaBrisanje=matrica;
                matrica=ProduktMatrica(matrica,a);
                UnistiMatricu(PomZaBrisanje);
            }
            for(int i=0; i<a.redovi; i++) {
                for(int j=0; j<a.kolone; j++) {
                    m3.elementi[i][j]+=matrica.elementi[i][j]*koef[k];
                }
            }
            UnistiMatricu(matrica);
        }
    }
    UnistiMatricu(jed);
    return m3;
}

int main ()
{
    Matrica<double>a;
    Matrica<double>b;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    cin>>n;
    try {
        a=StvoriMatricu<double>(n,n);
        cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
        cout<<"Unesite red polinoma: ";
        cin>>n;
        cout<<"Unesite koeficijente polinoma: ";
        vector<double>koeficijenti;
        for(int i=0; i<=n; i++) {
            double k;
            cin>>k;
            koeficijenti.push_back(k);
        }
        double *p=&koeficijenti[0];
        IspisiMatricu(b = MatricniPolinom(a,n,p),10);
    } catch(domain_error x) {
        cout<<x.what()<<endl;
    } catch(bad_alloc) {
        cout<<"Nema dovoljno memorije";
    }

    UnistiMatricu(a);
    UnistiMatricu(b);
    return 0;
}
