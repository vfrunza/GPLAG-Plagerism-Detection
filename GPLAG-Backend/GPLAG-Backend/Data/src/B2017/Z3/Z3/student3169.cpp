/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <deque>
#include <list>

template<typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi)return;
    for(int i(0);i<mat.br_redova;i++)delete[]mat.elementi[i];
    delete[]mat.elementi;
    mat.elementi=nullptr;
}//UREDU

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata* [br_redova];
    for(int i(0);i<br_redova;i++)mat.elementi[i]=nullptr;
    try{
        for(int i(0);i<br_redova;i++)mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata>&mat){
    for(int i(0);i<mat.br_redova;i++)
        for(int j(0);j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati){
       // UnistiMatricu(mat);
    for(int i(0);i<mat.br_redova;i++)delete[]mat.elementi[i];
    delete[]mat.elementi;
    }
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i(0);i<m1.br_redova;i++)
    for(int j(0);j<m1.br_kolona;j++)
    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
    
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata>&mat1, const Matrica<TipElemenata>&mat2){
    if(mat1.br_kolona!=mat2.br_redova)throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata>mat(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
    for(int i(0);i<mat1.br_redova;i++)
    for(int j(0);j<mat2.br_kolona;j++){
        TipElemenata suma{};
        for(int k(0);k<mat2.br_redova;k++)suma+=mat1.elementi[i][k] * mat2.elementi[k][j];
        mat.elementi[i][j]=suma;
    }
    return mat;
}

template<typename TipElemenata, typename Elem>
void Proizvod(Matrica<TipElemenata>&mat, Elem n){
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            mat.elementi[i][j]*=n;
        }
    }
}
template<typename TipElemenata>
void Kopiraj_Matrice(const Matrica<TipElemenata>&mat1, Matrica<TipElemenata>&mat2)
{
    for(int i(0);i<mat2.br_redova;i++){
        for(int j(0);j<mat2.br_kolona;j++){
            mat2.elementi[i][j]=mat1.elementi[i][j];
        }
    }
}

template<typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, int n, IterTip it){
    if(n<0)throw std::domain_error("Neispravan stepen polinoma");
    if(mat.br_kolona!=mat.br_redova)throw std::domain_error("Matrica mora biti kvadratna");
    
    //za prazan vektor mozda treba vratiti sve 0 
    Matrica<TipElemenata>matrica,temp,mnozac;
    try
    {
    matrica=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    mnozac=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    temp=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    }
    catch(...){
        UnistiMatricu(matrica);
        UnistiMatricu(mnozac);
        UnistiMatricu(temp);
        throw;
    }
    for(int i(0);i<matrica.br_redova;i++){
        for(int j(0);j<matrica.br_kolona;j++){
            if(i==j)matrica.elementi[i][j]=1;
            else matrica.elementi[i][j]=0;
        }
    }
    try{
    Kopiraj_Matrice(matrica,mnozac);
    Proizvod(matrica,*it);
    it++;
    Matrica<TipElemenata> temp2;
    for(int i(1);i<=n;i++){
        temp2=ProduktMatrica(mnozac,mat);
        Kopiraj_Matrice(temp2, mnozac);
        UnistiMatricu(temp2);
        Kopiraj_Matrice(mnozac,temp);
        Proizvod(temp,*it);
        temp2=ZbirMatrica(matrica,temp);
        Kopiraj_Matrice(temp2,matrica);
        UnistiMatricu(temp2);
        it++;
        
    }}
    catch(...){
        UnistiMatricu(matrica);
        UnistiMatricu(mnozac);
        UnistiMatricu(temp);
        throw;
    }
    UnistiMatricu(temp);
    UnistiMatricu(mnozac);
    return matrica;
    
}
    


int main ()
{
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int a;
    std::cin>>a;
    Matrica<double> matrica,nova;
    try{
    matrica=StvoriMatricu<double>(a,a);
    std::cout<<"Unesite elemente matrice A:"<<std::endl;
    UnesiMatricu<double>('A',matrica);
    std::cout<<"Unesite red polinoma: ";
    int b;
    std::cin>>b;
    std::vector<double>v(b+1);
    std::cout<<"Unesite koeficijente polinoma: ";
    for(int i(0);i<v.size();i++){
        double c;
        std::cin>>c;
        v.at(i)=c;
    }
    nova=MatricniPolinom(matrica,b,v.begin());
    IspisiMatricu(nova,10);
    }
    catch(std::domain_error Izuzetak){
        std::cout<<Izuzetak.what();
    }
    catch(std::bad_alloc){
        std::cout<<"Nedovoljno memorije! ";
    }
    UnistiMatricu(matrica);
    UnistiMatricu(nova);
    return 0;
}
