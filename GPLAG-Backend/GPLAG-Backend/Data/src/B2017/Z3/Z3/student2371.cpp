/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<vector>
#include<new>
#include<stdexcept>
#include<functional>

using namespace std;


template<typename TipElemenata>
struct Matrica
{
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_kolona=br_kolona;
    mat.br_redova=br_redova;
    try{
        mat.elementi= new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
        try{
            for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
            return mat;
        }
        catch(...) { throw;}
    } catch(...) { UnistiMatricu(mat); throw;}    
    
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++)
            {
                cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                cin>>mat.elementi[i][j];
            }
            
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
    auto m3(StvoriMatricu<TipElemenata>(mat1.br_redova, mat1.br_kolona));
    for(int i=0; i<mat1.br_redova; i++)
        for(int j=0; j<mat2.br_kolona; j++)
            m3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
    return m3;
}


 template<typename TipElemenata>
 Matrica<TipElemenata>nule(int a,int b)
 {
     auto r=StvoriMatricu<TipElemenata>(a,b);
     for(int i=0;i<a;i++)
     for(int j=0;j<b;j++)
     r.elementi[i][j]=0;
     return r;
 }
 
 template<typename TipElemenata>
 Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
 {
     if(m1.br_redova!=m1.br_kolona) throw domain_error("Matrice nisu saglasne za mnozenje!");
     auto r=nule<TipElemenata>(m1.br_redova,m1.br_kolona);
     for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++)
            for(int k=0;k<m2.br_redova;k++)
                r.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][k];
     return r;
 }
 

template<typename TipElemenata, typename t1>
Matrica<TipElemenata>MatricniPolinom(const Matrica<TipElemenata> &m,int n,t1 p)
{
     if(m.br_kolona!=m.br_redova)throw domain_error("Matrica mora biti kvadratna!");
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=0)
{
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<right<<mat.elementi[i][j];
        cout<<endl;
    }
    if(treba_brisati) UnistiMatricu(mat)
;}
int main ()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    cin>>n;
    try{
        auto mat=StvoriMatricu<int>(n,n);
        cout<<"Unesite elemente matrice A: "<<endl;
        UnesiMatricu('A',mat);
        cout<<"Unesite red polinoma: ";
        int r; cin>>r;
	     vector<int> v;
	     cout<<"Unesite koeficijente polinoma: ";
	     for(int i=0; i<r+1; i++){
	         double df;cin>>df;
	         v.at(i)=df;
	     } 
	     try{
	          auto m2=MatricniPolinom<int>(mat,r,v.begin());
	          IspisiMatricu(m2,10);
	         UnistiMatricu(mat);
	         UnistiMatricu(m2);
	     } catch(...) 
	     {UnistiMatricu(mat);throw;}
    }
    catch(domain_error iz) { cout<<"Izuzetak: "<<iz.what();}
	catch(...) {}
	return 0;
}
