/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
        if(!mat.elementi)return;
        for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona=br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i=0;i<br_redova;i++) mat.elementi[i]= nullptr;
        try{
        for(int i=0;i<br_redova;i++) mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, const Matrica<TipElemenata> &mat){
        for(int i=0;i<mat.br_redova;i++)
            for(int j=0;j<mat.br_kolona;j++){
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa=10,int preciznost=6,bool brisanje=false) {
    for(int i=0;i<mat.br_redova; i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(brisanje==true) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++) 
        m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> mat1, Matrica<TipElemenata> mat2){
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> p;
    TipElemenata suma(0);
    p=StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona);
    for(int k=0;k<p.br_redova;k++){
        for(int i=0;i<p.br_kolona;i++){
            for(int j=0;j<mat1.br_kolona;j++){
                suma=suma+mat1.elementi[k][j]*mat2.elementi[j][i];
            } p.elementi[k][i]=suma;suma=0;
        }
    }
    return p;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> mat, std::vector<double> v){
    if(mat.br_kolona!=mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");

    auto Mat_pol=StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_kolona);
    for(int i=0;i<mat.br_kolona;i++){
                for(int j=0;j<mat.br_kolona;j++){
                    Mat_pol.elementi[i][j]=0;
            }
        }
    if(v.size()==0)
        return Mat_pol;
    
       auto jedinicna=StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_kolona);
        for(int i=0;i<mat.br_kolona;i++){
                for(int j=0;j<mat.br_kolona;j++){
                    if(i!=j) jedinicna.elementi[i][j]=0;
                    else jedinicna.elementi[i][j]=1;
            }
        }
    auto stepen_matrice=StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_kolona);
    for(int i=0;i<mat.br_kolona;i++){
        for(int j=0;j<mat.br_kolona;j++){
            stepen_matrice.elementi[i][j]=mat.elementi[i][j];
        }
    }
    auto pomocna=StvoriMatricu<TipElemenata>(mat.br_kolona,mat.br_kolona);
    for(int i=0;i<v.size();i++){
        if(i==0){
            for(int j=0;j<mat.br_kolona;j++){
                for(int k=0;k<mat.br_kolona;k++){
                    pomocna.elementi[j][k]=v[i]*jedinicna.elementi[j][k];
                }
            }
        }
        else{
            for(int j=0;j<mat.br_kolona;j++){
                for(int k=0;k<mat.br_kolona;k++){
                    pomocna.elementi[j][k]=v[i]*stepen_matrice.elementi[j][k];
                }
            }
            auto brisanje(stepen_matrice);
            stepen_matrice=ProduktMatrica(stepen_matrice,mat);
            UnistiMatricu(brisanje);
        }
        auto brisanje2(Mat_pol);
        Mat_pol=ZbirMatrica(Mat_pol,pomocna);
        UnistiMatricu(brisanje2);
    }
    UnistiMatricu(jedinicna); UnistiMatricu(pomocna); UnistiMatricu(stepen_matrice);
    return Mat_pol;
}
int main()
{
    Matrica<double> a,b;
    int m,red_pol;
    double p;
    std::vector<double> polinom;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a = StvoriMatricu<double>(m,m);
        //b= StvoriMatricu<double>(3,5);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        //UnesiMatricu('B',b);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red_pol;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=red_pol;i++){
            std::cin>>p;
            polinom.push_back(p);
        }
        try{
        //b=ProduktMatrica(a,b);    
        b=MatricniPolinom(a,polinom);
        }catch(std::domain_error c){
            std::cout<<c.what();
        }
        IspisiMatricu(b,10,6,false);
        UnistiMatricu(a); UnistiMatricu(b);
    } catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
    //UnistiMatricu(a);UnistiMatricu(b);
	return 0;
}