/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <new>
template <typename TipElementa>
struct Matrica{
    int br_redova, br_kolona;
    TipElementa **elementi=nullptr;
};
//Funkcija za unistavanje matrice
template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat){
    if(!mat.elementi) return;
    for(int i=0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
//Funkcija za stvaranje matrice
template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElementa> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi = new TipElementa *[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0; i<br_redova; i++) 
        mat.elementi[i] = new TipElementa[br_kolona];
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
//Funkcija za unos matrice
template <typename TipElementa>
void UnesiMatricu(char ime_matrice, Matrica<TipElementa> &mat){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout<<ime_matrice
            <<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
//Funkcija za ispis matrice
template <typename TipElementa>
void IspisiMatricu(const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(treba_brisati == true) UnistiMatricu(mat);
}
//Funkcija saglasnosti funkcija
template <typename TipElementa>
bool MoguSeMnoziti(Matrica<TipElementa> m1, Matrica<TipElementa> m2){
    return m1.br_kolona==m2.br_redova;
}
//Funkcija Produkt matrice
template <typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2){
    if(!MoguSeMnoziti(m1,m2)) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m2.br_kolona; j++){
            TipElementa Suma(0);
            for(int k=0; k<m1.br_kolona; k++){
                Suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=Suma;
        }
    }
    return m3;
}
//Funkcija za sabiranje matrica
template <typename TipElementa>
Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m1.br_kolona; j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}
//Funkcija za sklarno mnozenje
template <typename TipElementa, typename tip>
Matrica<TipElementa> SkalarnoMnozenje(const Matrica<TipElementa> &mat, tip n){
    auto skalarniprodukt(StvoriMatricu<TipElementa> (mat.br_redova, mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            skalarniprodukt.elementi[i][j]=mat.elementi[i][j]*n;
        }
    }
    return skalarniprodukt;
}
//Funkcija Matricni Polinom
template <typename TipElementa, typename tip>
Matrica<TipElementa> MatricniPolinom(const Matrica<TipElementa> &mat, tip v){
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto Polinom=StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona);
    auto it=v.begin();
    if(v.size()==0){
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++){
                Polinom.elementi[i][j]=0;
            }
        }
        return Polinom;
    }
    auto temp=StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona);
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            if(i==j) Polinom.elementi[i][j]=1*(*it);
            else Polinom.elementi[i][j]=0;
        }
    }
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            temp.elementi[i][j]=mat.elementi[i][j];
        }
    }
    for(auto it=v.begin()+1; it!=v.end(); it++){
        if(it==v.begin()+1){
            auto temp1=SkalarnoMnozenje(mat, *it);
            auto temp2=ZbirMatrica(temp1,Polinom);
            for(int i=0; i<mat.br_redova; i++){
                for(int j=0; j<mat.br_kolona; j++){
                    Polinom.elementi[i][j]=temp2.elementi[i][j];
                }
            }
            UnistiMatricu(temp1);
            UnistiMatricu(temp2);
        }
        else{
            auto temp1=ProduktMatrica(mat, temp);
            auto temp2=SkalarnoMnozenje(temp1,*it);
            auto temp3=ZbirMatrica(temp2,Polinom);
            for(int i=0; i<mat.br_redova; i++){
                for(int j=0; j<mat.br_kolona; j++){
                    Polinom.elementi[i][j]=temp3.elementi[i][j];
                }
            }
            UnistiMatricu(temp1);
            UnistiMatricu(temp2);
            UnistiMatricu(temp3);
            auto temp4=ProduktMatrica(mat,temp);
            for(int i=0; i<mat.br_redova; i++){
                for(int j=0; j<mat.br_kolona; j++){
                    temp.elementi[i][j]=temp4.elementi[i][j];
                }
            }
            UnistiMatricu(temp4);
        }
    }
    UnistiMatricu(temp);
    return Polinom;
}
int main ()
{
    
    Matrica <int> a, b;
    int m, n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a=StvoriMatricu<int>(m,m);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> v(n+1);
        for(int i=0; i<v.size(); i++) std::cin>>v.at(i);
        IspisiMatricu(b=MatricniPolinom(a,v),10);
    }catch(std::domain_error Izuzetak){
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
    }catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(b);
	return 0;
}
