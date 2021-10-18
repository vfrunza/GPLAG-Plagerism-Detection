/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i(0);i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_kolona=br_kolona;
    mat.br_redova=br_redova;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i(0);i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i(0);i<br_redova;i++){
            mat.elementi[i]= new TipElemenata[br_kolona];
        }
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, const Matrica<TipElemenata> &mat){
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa){
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++)
            std::cout<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
}   

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i(0);i<m1.br_redova;i++){
        for(int j(0);j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    }
   
}
 return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_redova || m1.br_redova!=m2.br_kolona ) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_redova));
    
    for(int i(0);i<m1.br_redova;i++){
        for(int j(0);j<m1.br_redova;j++){
            TipElemenata suma=0;
            for(int k(0);k<m1.br_redova;k++){
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

/*template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, int n, Tip kon){
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    for(int i(0);i<=n;i++){
        
    }
}*/
    
int main ()
{
   try{
    auto a(StvoriMatricu<double>(2,2));
    auto b(StvoriMatricu<double>(2,2));
    UnesiMatricu('A',a);
    UnesiMatricu('B',b);
    auto c(StvoriMatricu<double>(2,2));
    c=ZbirMatrica(a,b);
    auto d(StvoriMatricu<double>(2,2));
    d=ProduktMatrica(a,b);
    IspisiMatricu(d,5);
    IspisiMatricu(c,6);
    UnistiMatricu(a);
    UnistiMatricu(b);
    UnistiMatricu(c);
    UnistiMatricu(d);
   }
   catch (std::bad_alloc){
       std::cout<<"Nema dovoljno memorije";
   }
	return 0;
}
