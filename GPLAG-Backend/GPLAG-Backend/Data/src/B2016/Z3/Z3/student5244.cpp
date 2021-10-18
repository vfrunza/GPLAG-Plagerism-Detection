/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <cmath>

template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica <TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
   /* for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            mat[i][j]=0;
        }
    }*/
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++){
        mat.elementi[i]=nullptr;
    }
    try{
        for(int i=0;i<br_redova;i++){
            mat.elementi[i]=new TipElemenata[br_kolona];
        }
        for(int i=0;i<br_redova;i++){
            for(int j=0;j<br_kolona;j++){
                mat.elementi[i][j]=0;
            }
        }
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(treba_brisati){
        UnistiMatricu(mat);
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica  (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (Matrica<TipElemenata> m1, Matrica<TipElemenata> m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            for(int k=0;k<m1.br_kolona;k++){
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
        
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> A, std::vector<double> koeficijenti){
    if(A.br_kolona!=A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    if(koeficijenti.size()==0){
        return StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    }
    auto P=StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);
    Matrica<TipElemenata> zaBrisanja;
    for(int k=0;k<koeficijenti.size();k++){
        auto temp=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        
        for(int i=0;i<temp.br_redova;i++){
            for(int j=0;j<temp.br_kolona;j++){
                if(i==j) temp.elementi[i][j]=1;
                else temp.elementi[i][j]=0;
            }
        }
        
        if (k != 0) {
            for(int i=0;i<k;i++){
                zaBrisanja = temp;
                temp=ProduktMatrica(temp, A);
                UnistiMatricu(zaBrisanja);
            }
        }
        for(int i=0;i<temp.br_redova;i++){
            for(int j=0;j<temp.br_kolona;j++){
                temp.elementi[i][j]*=koeficijenti[k];
            }
        }
        zaBrisanja = P;
        P = ZbirMatrica(P,temp);
        UnistiMatricu(zaBrisanja);
        UnistiMatricu(temp);
    }
    return P;
}

int main ()
{
    try{
        
        std::cout<<"Unesite dimenziju kvadratne matrice: ";
        int m;
        std::cin>>m;
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        auto mat=StvoriMatricu<int> (m,m);
        UnesiMatricu('A',mat);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> koef;
        for(int i=0;i<=red;i++){
            int x;
            std::cin>>x;
            koef.push_back(x);
        }
        IspisiMatricu(MatricniPolinom(mat,koef),10, 6, true);
        UnistiMatricu(mat);
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    
	return 0;
}