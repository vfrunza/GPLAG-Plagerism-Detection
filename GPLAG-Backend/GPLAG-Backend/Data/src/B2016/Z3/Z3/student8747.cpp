/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>


    template<typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

    template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete mat.elementi;
    mat.elementi=nullptr;
}

    template<typename TipElemenata>
Matrica<TipElemenata>StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi= new TipElemenata *[br_redova];
    for(int i=0;i<br_redova;i++){
        mat.elementi[i]=nullptr;
    }
    try{
        for(int i=0;i<br_redova;i++){
            mat.elementi[i]=new TipElemenata[br_kolona];
        }
    }catch(...){
        UnistiMatricu<TipElemenata>(mat);
        throw;
    }
    return mat;
}

    template<typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = " ;
            std::cin >> mat.elementi[i][j];
        }
    }
}

    template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<< mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu<TipElemenata>(mat);
}

    template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica <TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

    template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2 ){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> mat(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            mat.elementi[i][j]=0;
            for(int k=0;k<mat.br_redova;k++){
                mat.elementi[i][j]+=(m1.elementi[i][k]*m2.elementi[k][j]);
            }
        }
    }
    return mat;
}

    template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica <TipElemenata> &mat,std::vector<double> v){
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> m(StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_kolona));
    if(v.size()==0) return m;
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            if(i==j) m.elementi[i][j]=v[0];
            else m.elementi[i][j]=0;
        }
    }
    if(v.size()==1) return m;
    for(int i=0;i<m.br_redova;i++){
        for(int j=0;j<m.br_kolona;j++){
            TipElemenata suma=m.elementi[i][j]+v[1]*mat.elementi[i][j];
            m.elementi[i][j]=suma;
        }
    }
    if(v.size()==2) return m;
    for(int i=2;i<v.size();i++){
        auto b=ProduktMatrica<TipElemenata>(mat,mat);
        for(int j=0;j<i-2;i++) {
             b=ProduktMatrica<TipElemenata>(b,m);
        }
        for(int j=0;j<m.br_redova;j++){
            for(int k=0;k<m.br_kolona;k++){
                TipElemenata suma=m.elementi[j][k]+ v[i]*b.elementi[j][k];
                m.elementi[j][k]=suma;
            }
        }
        UnistiMatricu<TipElemenata>(b);
    }
    return m;
}

int main ()
{   
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int broj;
    std::cin>> broj;
    Matrica <double> mat;
        mat=StvoriMatricu<double>(broj,broj);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu<double>('A',mat);
        std::cout << "Unesite red polinoma: ";
        int x;
        std::cin >> x;
        std::vector<double> v;
        std::cout << "Unesite koeficijente polinoma: ";
        double y;
        for(int i=0;i<=x;i++){
                std::cin >> y;
                v.push_back(y);
        }
        IspisiMatricu<double>(MatricniPolinom<double>(mat,v), 10, 6, true);
        UnistiMatricu<double>(mat);
	return 0;
}