#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>
using namespace std;
template <typename TipElemenata>
struct Matrica{
    int broj_redova, broj_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.broj_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int broj_redova, int broj_kolona){
    Matrica<TipElemenata> mat;
    mat.broj_redova=broj_redova;
    mat.broj_kolona=broj_kolona;
    mat.elementi=new TipElemenata*[broj_redova];
    for(int i=0;i<broj_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<broj_redova;i++) mat.elementi[i]=new TipElemenata[broj_kolona];
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, const Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.broj_redova;i++){
        for(int j=0;j<mat.broj_kolona;j++){
            cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.broj_redova;i++){
        for(int j=0;j<mat.broj_kolona;j++){
            cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
        }
        cout<<endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2){
    if(mat1.broj_redova!=mat2.broj_redova || mat1.broj_kolona!=mat2.broj_kolona)
    throw domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(mat1.broj_redova,mat1.broj_kolona));
     for(int i=0;i<mat1.broj_redova;i++){
        for(int j=0;j<mat1.broj_kolona;j++){
            m3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.broj_kolona!=m2.broj_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.broj_redova,m2.broj_kolona));
    for(int i=0;i<m1.broj_redova;i++){
        for(int j=0;j<m2.broj_kolona;j++){
             TipElemenata suma{};
             for(int k=0;k<m1.broj_kolona;k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
             m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriJedinicnu(int broj_redova){
    Matrica<TipElemenata> mat;
    mat.broj_redova=broj_redova;
    mat.broj_kolona=broj_redova;
    mat.elementi=new TipElemenata*[broj_redova];
    for(int i=0;i<broj_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<broj_redova;i++) mat.elementi[i]=new TipElemenata[broj_redova];
        for(int i=0;i<broj_redova;i++){
            for(int j=0;j<broj_redova;j++){
                if(i==j) mat.elementi[i][j]=static_cast<TipElemenata>(1);
                else mat.elementi[i][j]=static_cast<TipElemenata>(0);
            }
        } 
        
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void PomnoziSkalarom(const Matrica<TipElemenata> &mat, double skalar){
    for(int i=0;i<mat.broj_redova;i++){
        for(int j=0;j<mat.broj_kolona;j++){
           mat.elementi[i][j]*=skalar;
        }
    }
}
template <typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, int n, IterTip it){
    if(n<0) throw domain_error("Neispravan stepen polinoma");
    if(mat.broj_redova!=mat.broj_kolona) throw domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> a,b,pomocna1,pomocna2,zbir;
    a=StvoriJedinicnu<double>(mat.broj_redova);
    PomnoziSkalarom(a,*it);
    pomocna1=StvoriJedinicnu<double>(mat.broj_redova);
    pomocna2=ProduktMatrica(pomocna1,mat);
    it++;
    for(int i=1;i<n;i++){
        b=ProduktMatrica(pomocna1,mat);
        PomnoziSkalarom(b,*it);
        it++;
        zbir=ZbirMatrica(a,b);
        UnistiMatricu(a);
        a=zbir;
        UnistiMatricu(b);
        UnistiMatricu(pomocna1);
        pomocna1=pomocna2;
        pomocna2=ProduktMatrica(pomocna1,mat);
    }
    UnistiMatricu(pomocna1);
    UnistiMatricu(pomocna2);
    return a;
}
int main ()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    cin>>n;
    Matrica<double> a,b;
    a=StvoriMatricu<double>(n,n);
    cout<<"Unesite elemente matrice A:"<<endl;
    UnesiMatricu('A',a);
    cout<<"Unesite red polinoma: ";
    cin>>n;
    vector<double> v(n+1);
    cout<<"Unesite koeficijente polinoma: ";
    for(double &x:v) cin>>x;
    //b=MatricniPolinom(a,v.size(),v.begin());
    IspisiMatricu(MatricniPolinom(a,v.size(),v.begin()),10,6,true);
    UnistiMatricu(a);
    //UnistiMatricu(b);
	return 0;
}
