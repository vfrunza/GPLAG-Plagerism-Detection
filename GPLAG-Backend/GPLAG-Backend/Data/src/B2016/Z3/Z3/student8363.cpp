/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::cin;
using std::cout;
template <typename TipElemenata>
    struct Matrica{
        int br_redova,br_kolona;
        TipElemenata **elementi = nullptr;
    };
template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat){
        if(!mat.elementi)return;
        for (int i = 0; i < mat.br_redova; i++) {
            delete[] mat.elementi[i];
            mat.elementi[i]=nullptr;
        }
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova;
        mat.br_kolona = br_kolona;
        try{
            mat.elementi = new TipElemenata *[br_redova];
        }catch(...){
            throw;
        }
        try {
            for (int i = 0; i < br_redova; i++) {
                mat.elementi[i] = new TipElemenata[br_kolona];
            }
        }catch(...){
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
        for (int i = 0; i < mat.br_redova; i++) {
            for(int j=0; j<mat.br_kolona; j++){
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
        }
    }
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati= false){
            if(mat.elementi!=nullptr)
            for (int i = 0; i < mat.br_redova; i++) {
                for(int j=0; j<mat.br_kolona; j++){
                    std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
                }
                std::cout<<std::endl;
            }
            if(treba_brisati)UnistiMatricu(mat);
    }
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_redova != m2.br_redova || m1.br_kolona!=m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
        for (int i = 0; i < m1.br_redova; i++) {
            for(int j=0; j<m1.br_kolona; j++)
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
        return m3;
    }
template<typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1,Matrica<TipElemenata> m2){
        if(m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto rez = StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
        for (int i = 0; i < rez.br_redova; i++) {
            for(int j=0; j< rez.br_kolona; j++){
                rez.elementi[i][j]=0;
                for(int k=0;k<m1.br_kolona;k++){
                   // cout<<"ProduktMatrica "<<i<<k<<'\n';
                    rez.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
                }
            }
        }
        //cout<<"Vracam rez\n";
        return rez;
    }
template<typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> a,std::vector<double> ko){
        if(a.br_kolona!=a.br_redova)
            throw std::domain_error("Matrica nije kvadratna");
        if(!ko.size()){
            auto izlaz = StvoriMatricu<TipElemenata>(a.br_kolona,a.br_redova);
            for (int i = 0; i < a.br_kolona; i++) {
                for(int j=0; j<a.br_kolona; j++)
                    izlaz.elementi[i][j]=0;
            }
            return izlaz;
        }
        Matrica<TipElemenata> izlaz;
        for(int k = 0 ; k<ko.size(); k++){
                auto tmp = StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona);
                for (int i = 0; i < a.br_kolona; i++) {
                    for (int j = 0; j < a.br_redova; j++) {
                        if(i==j)
                        tmp.elementi[i][j]=1;
                        else 
                        tmp.elementi[i][j]=0;
                    }
                }
                try{
                    //ovdje mozda curi
                    for (int i = 0; i < k; i++) {
                        auto b = tmp;
                        try{
                            tmp = ProduktMatrica(a,tmp);
                        }catch(...){
                            UnistiMatricu(b);
                            tmp.elementi= nullptr;
                            b.elementi=nullptr;
                            throw;
                        }
                        UnistiMatricu(b);
                    }
                    for (int i = 0; i < a.br_kolona; i++) {
                        for (int j = 0; j < a.br_kolona; j++) {
                            tmp.elementi[i][j] = ko[k]*tmp.elementi[i][j];
                        }
                    }
                    //moguce da curi
                    if(k==0){
                        UnistiMatricu(izlaz);
                        izlaz=tmp;
                    }
                    else {
                        auto b = izlaz;
                        auto tt = tmp;
                        izlaz = ZbirMatrica(izlaz,tmp);
                        UnistiMatricu(b);
                        UnistiMatricu(tt);
                    }
            }catch(...){
                UnistiMatricu(tmp);
                UnistiMatricu(izlaz);
                throw;
            }
        }
        return izlaz;
    }
int main ()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    std::vector<double> k;
    cin>>n;
    try{
        auto A = StvoriMatricu<double>(n,n);
        cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',A);
        std::cout << "Unesite red polinoma: ";
        cin>>n;
        if(n<0)return 0;
        cout<<"Unesite koeficijente polinoma: ";
        for (int i = 0; i <= n; i++) {
            double a;
            std::cin >> a;
            k.push_back(a);
        }
        IspisiMatricu(MatricniPolinom(A,k),10,6,true);
        UnistiMatricu(A);
    }catch(std::domain_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}