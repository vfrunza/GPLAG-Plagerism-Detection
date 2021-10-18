/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using namespace std;

template <typename TipElementa>
struct Matrica {
    int br_redova,br_kolona;
    TipElementa **elementi=nullptr;
};
template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa>mat)
{
    if(!mat.elementi) return ;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova,int br_kolona)
{
    Matrica<TipElementa>mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    try {
        mat.elementi=new TipElementa*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
        try {
            for(int i=0; i<br_redova; i++)
                mat.elementi[i]=new TipElementa[br_kolona];
        }

        catch (...) {
            UnistiMatricu(mat);
            throw;
        }

    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;

}
template <typename TipElementa>
void UnesiMatricu(char ime_matrice,Matrica<TipElementa>&mat)
{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) {
            cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
        }
}

template <typename TipElementa>
void IspisiMatricu(const Matrica<TipElementa>&mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
        cout<<endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElementa>
Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa>&mat1,const Matrica<TipElementa>&mat2)
{
    if(mat1.br_redova!=mat2.br_redova || mat1.br_kolona!=mat2.br_kolona)
        throw domain_error("Matrice nemaju jednake dimenzije!");
    auto mat3(StvoriMatricu<TipElementa>(mat1.br_redova,mat1.br_kolona));
    try{
    for(int i=0; i<mat1.br_redova; i++)
        for(int j=0; j<mat1.br_kolona; j++)
            mat3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
    }
    catch(...){UnistiMatricu(mat3);throw;}

    return mat3;
}
template <typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa>&mat1,const Matrica<TipElementa>&mat2)
{
    if(mat1.br_kolona!=mat2.br_redova) throw("Matrice nisu saglasne za mnozenje");
    auto mat3(StvoriMatricu<TipElementa>(mat1.br_redova,mat2.br_kolona));
   
    for(int i=0; i<mat1.br_redova; i++)
        for(int j=0; j<mat2.br_kolona; j++)
            mat3.elementi[i][j]=0;
    for(int i=0; i<mat1.br_redova; i++) {
        for(int j=0; j<mat2.br_kolona; j++) {
            for(int k=0; k<mat2.br_redova; k++)
                mat3.elementi[i][j]+=(mat1.elementi[i][k]*mat2.elementi[k][j]);
        }
    }
    
    
    return mat3;
}
template <typename TipElementa>
Matrica<TipElementa> ProduktSaSkalarom(TipElementa n,const Matrica<TipElementa>&mat)
{
    auto mat2(StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona));
    
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++)
            mat2.elementi[i][j]=0;

    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++)
            mat2.elementi[i][j]=n*mat.elementi[i][j];
    
    

    return mat2;
}
template<typename TipElementa>
Matrica<TipElementa> StepenMatrice(const Matrica<TipElementa>&mat,int n)
{
    auto mat2(StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona));
    try{
    if(n==0) {
        for(int i=0; i<mat.br_redova; i++) {
            for(int j=0; j<mat.br_kolona; j++) {
                if(i==j) mat2.elementi[i][j]=1;
                else mat2.elementi[i][j]=0;
            }
        }
        return mat2;
    } else if(n==1) {
        return mat;

    }

    else {
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++)
                mat2.elementi[i][j]=mat.elementi[i][j];
        int i=1;
        while (i<n) {
            mat2=ProduktMatrica(mat,mat2);
            i++;
        }
    }
    }
    catch(...) {UnistiMatricu(mat2); throw;}
    return mat2;
}
template <typename TipElementa>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa>&mat,vector<double>v)
{
    
    auto mat2(StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona));
try{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++)
            mat2.elementi[i][j]=0;
    
    int  i=0;
    while(i<v.size()) {
        mat2=ZbirMatrica(mat2,ProduktSaSkalarom(v[i],StepenMatrice(mat,i)));
        i++;
    }
}
catch(...){UnistiMatricu(mat2); throw;}
    
    
    return mat2;
}


int main ()
{
    vector<double>v;
    Matrica<double>a,c;
    int n;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>n;
    bool k=true;
    try {
        a=StvoriMatricu<double>(n,n);
        cout<<"Unesite elemente matrice A:"<<endl;
        UnesiMatricu('A',a);
        int b;
        cout<<"Unesite red polinoma: ";
        cin>>b;
        cout<<"Unesite koeficijente polinoma: ";
        v.resize(b+1);
        for(int i=0; i<v.size(); i++)
            cin>>v[i];
        IspisiMatricu(c=MatricniPolinom(a,v),10,6,k);



    } catch(bad_alloc) {
        cout<<"Nema dovoljno memorije!";

    }
    UnistiMatricu(a);
    UnistiMatricu(c);













    return 0;
}
