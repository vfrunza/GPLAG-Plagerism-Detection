#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include<vector>
using std::cout;
template <typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int &br_redova,int &br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata>&mat)
{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) {
            cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica( Matrica<TipElemenata> m1, Matrica<TipElemenata> m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    auto rez(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona)); 
    for(int p=0; p<m1.br_redova; p++)
        for(int q=0; q<m2.br_kolona; q++)
            rez.elementi[p][q]=0;

    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            for(int k=0; k<m1.br_kolona; k++)
                rez.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];

    return rez; //vraca se re z matrica odnosno pokazivac na nju i ne smijemo ga izgubiti!!!
}
template<typename TipElemenata,typename Tip>
Matrica<TipElemenata> MnozenjeSkalarom( Matrica<TipElemenata> m,Tip skalar)
{
    Matrica<TipElemenata>rez;
    try {
        rez = StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);   //stvara se 1 nova!!
    } catch(...) {
        throw;
    }
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            rez.elementi[i][j]=m.elementi[i][j]*skalar; //PROBLEM
    return rez;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriJedinicnu(int br_redova,int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    for(int i=0; i<br_redova; i++)
        for(int j=0; j<br_kolona; j++) {
            if(i==j) mat.elementi[i][j]=1;
            else mat.elementi[i][j]=0;
        }
    return mat;

}
template<typename TipElemenata>
Matrica<TipElemenata>ZbirMatrica(Matrica<TipElemenata>m1,Matrica<TipElemenata>m2)
{
   
    Matrica<TipElemenata>m3;
    try {
        m3 = StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
    } catch(...) { 
        throw;   
    }
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;

}

template<typename TipElemenata,typename Tip>
Matrica<TipElemenata>MatricniPolinom( Matrica<TipElemenata> m,int n,Tip pok)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
   
    Matrica<TipElemenata> Jedinicna;//umrla
    Jedinicna.elementi = nullptr;
    Matrica<TipElemenata> pomocna;//umrla
    pomocna.elementi = nullptr;
    Matrica<TipElemenata> mn_skalarom1;//umrla
    mn_skalarom1.elementi = nullptr;
    Matrica<TipElemenata> zbir1;
    zbir1.elementi = nullptr;
    Matrica<TipElemenata> zbirZadnji;
    zbirZadnji.elementi = nullptr;
   
    try {
        try {
            Jedinicna=StvoriJedinicnu<TipElemenata>(m.br_redova,m.br_kolona);
        } catch(...) {
            throw;
        }
        for(int i=0; i<=n; i++) {
            if(i==0)  {
                //DA LI TREBA UNISTIT I POMOCNU
                try {
                    pomocna=MnozenjeSkalarom(Jedinicna,*pok);   //cuva pokazivac
                } catch(...) {
                    UnistiMatricu(Jedinicna);
                    throw;
                }
                UnistiMatricu(Jedinicna);
                if(n==0) {
                    return pomocna;
                }
            } else if(i==1) {
                try {
                    mn_skalarom1=MnozenjeSkalarom(m,*pok);
                    zbir1=ZbirMatrica(pomocna,mn_skalarom1);
                    UnistiMatricu(pomocna);
                    UnistiMatricu(mn_skalarom1);
                } catch(...) {
                    UnistiMatricu(pomocna);
                    UnistiMatricu(mn_skalarom1);
                    UnistiMatricu(zbir1);
                    throw;
                }
                if(n==1) return zbir1; //pomocna i mn skalarom su vec unistene
            }
            else {
                try {
                    auto rezultat = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
                    for(int k(0); k < m.br_redova; k++) {
                        for(int l(0); l < m.br_kolona; l++) {
                            rezultat.elementi[k][l] = m.elementi[k][l];
                        }
                    }
                    for(int j(0); j < i - 1; j++) {
                        auto dosadasnji_rez = rezultat;
                        rezultat = ProduktMatrica(dosadasnji_rez, m);
                        UnistiMatricu(dosadasnji_rez);
                    }
                    auto mn_skalarom3(rezultat);
                    rezultat = MnozenjeSkalarom(mn_skalarom3, *pok);
                    UnistiMatricu(mn_skalarom3);
                    zbirZadnji = zbir1;
                    zbir1 = ZbirMatrica(zbirZadnji, rezultat);
                    UnistiMatricu(zbirZadnji);
                    UnistiMatricu(rezultat);
                }
                catch(...) {
                    UnistiMatricu(zbir1);
                    throw;
                }
            }
            pok++;
        }//kraj for
        return zbir1;
    } catch(...) {
        throw;
    }   
}
int main ()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int d;
    std::cin>>d;
    Matrica<int> a;
    a.elementi = nullptr;
    Matrica<int> rez;
    rez.elementi = nullptr;
    try {
        a=StvoriMatricu<int>(d,d);
        cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A',a);
        int p;
        cout<<"Unesite red polinoma: ";
        std::cin>>p;
        std::vector<int> vektor;

        cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<=p; i++) {
            int broj;
            std::cin>>broj;
            vektor.push_back(broj);
        }
        rez=MatricniPolinom(a,p,vektor.begin()); 
    IspisiMatricu(rez,10,6,true);
    } catch(std::bad_alloc) {
        cout<<"Nema dovoljno memorije!\n";
    }catch(std::domain_error e){
        cout<<e.what();
    }
    UnistiMatricu(a);
    UnistiMatricu(rez);
    return 0;
}
