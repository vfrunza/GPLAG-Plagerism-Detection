/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
template<typename TipElemenata>struct Matrica {
    int br_redova, br_kolona;
    TipElemenata**elementi= nullptr;// VEOMA BITNA INICIJALIZACIJA!
};
template<typename TipElemenata> void UnistiMatricu(Matrica<TipElemenata>mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++)
        delete [] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template<typename TipElemenata> Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_kolona; i++)
            mat.elementi[i] = new TipElemenata[br_redova];
    } catch(...) {
        UnistiMatricu(mat);
        throw;

    }
    return mat;
}
template<typename TipElemenata>void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template<typename TipElemenata> void IspisiMatricu(const Matrica<TipElemenata>&mat, int sirina_ispisa)
{
    for( int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
}
template<typename TipElemenata> Matrica<TipElemenata> ProduktMatrica
( Matrica<TipElemenata>&A, Matrica<TipElemenata>&B)
{
    if(A.br_kolona!=B.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
   Matrica<TipElemenata>produkt;
    try{
    //produkt=StvoriMatricu(br_kolona,br_redova);
   produkt=StvoriMatricu<TipElemenata>(B.br_redova,A.br_kolona);
    
    for(int i=0;i<A.br_redova;i++)
    {
        for(int j=0;j<B.br_kolona;j++)
        {
            TipElemenata suma(0);
            for(int k=0;k<A.br_kolona;k++)
            {
                suma+=A.elementi[i][k]*B.elementi[k][j];
            }
            produkt.elementi[i][j]=suma;
        }
    }
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    return produkt;
}

int main ()
{
    std::cout<<"Unesite dimenzije kvadratne matrice: ";
    int n;
    std::cin>>n;
    Matrica<double> a,b;
    try {
        a = StvoriMatricu<double>(n,n);
        std::cout << "Unesi matricu A:\n";
        UnesiMatricu('A', a);
        //IspisiMatricu(a,n);
        b= StvoriMatricu<double>(n,n);
        std::cout << "Unesi matricu B:\n";
        UnesiMatricu('B', b);
       // IspisiMatricu(b,n);
        Matrica<double> produkt=ProduktMatrica(a,b);
        IspisiMatricu(produkt,5);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what()<<std::endl;
    }
    UnistiMatricu(a);
    return 0;
}
