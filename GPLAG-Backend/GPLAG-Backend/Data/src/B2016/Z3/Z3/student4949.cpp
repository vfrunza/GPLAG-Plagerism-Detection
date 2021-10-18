/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<new>
#include<vector>
using namespace std;

template<typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;

}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){

    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            cout<<setprecision(preciznost)<<setw(sirina_ispisa)<<mat.elementi[i][j];
        cout<<endl;
    }
    
    if(treba_brisati) UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona != m2.br_kolona) throw domain_error("Matrice nemaju jednake dimenzija!");

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));

    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j] +m2.elementi[i][j];
    return m3;

}


template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2){
    if(m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            m3.elementi[i][j]=0;
        }
    }
    
    for(int k=0;k<m1.br_kolona;k++){
        for(int i=0;i<m1.br_redova;i++){
            for(int j=0;j<m2.br_kolona;j++){
               m3.elementi[i][j]+=(m1.elementi[i][k])*(m2.elementi[k][j]);
               
            }
        }
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> Pomnozi(Matrica<TipElemenata> m, double x){
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_redova;j++){
            m.elementi[i][j]=(m.elementi[i][j])*x;
            
        }

    }
    return m;
}


template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> mat, vector<double> v){
    if(mat.br_redova!=mat.br_kolona) throw domain_error("Matrica mora biti kvadratna");
    auto m(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_redova));
    
    auto konacna(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_redova));
    
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_redova; j++){
            if(i==j) m.elementi[i][j]=1;
            else m.elementi[i][j]=0;
        }
    }

    for(int i=0;i<konacna.br_redova;i++){
        for(int j=0;j<konacna.br_redova;j++){
            konacna.elementi[i][j]=0;
         }
    }
    if(v.size()==0) return konacna;
    
    for(int i=0;i<konacna.br_redova;i++){
        for(int j=0;j<konacna.br_redova;j++){
            konacna.elementi[i][j]=m.elementi[i][j]*v[0];
        }
    }
    
        for(int l=1;l<v.size();l++){
        auto d=m;    
        m=ProduktMatrica(m,mat);
        UnistiMatricu(d);
        for(int i=0;i<m.br_redova;i++){
            for(int j=0;j<m.br_redova;j++){
                konacna.elementi[i][j]=v[l]*m.elementi[i][j]+konacna.elementi[i][j];
            }
        }
        
        }
    UnistiMatricu(m);
    
    return konacna;
}

int main ()
{
    Matrica<double> a,b,c,d;
    int m;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>m;
    
   
    try {
        a=StvoriMatricu<double>(m,m);
        
        cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        
         int n;
    cout<<"Unesite red polinoma: ";
    cin>>n;
    while(n<0) cin>>n;
    
    vector<double> v;
    cout<<"Unesite koeficijente polinoma: ";
    for(int i=0;i<=n;i++){
        double broj;
        cin>>broj;
        v.push_back(broj);
    }
        
        IspisiMatricu(c=MatricniPolinom(a,v),10);
    
    } catch(bad_alloc) {
        cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(c);
   
    return 0;
}