/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata** elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
        mat.elementi[i]=new TipElemenata[br_kolona];
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                mat.elementi[i][j]=0;
            }
        }
    }
    catch(std::bad_alloc){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++){
            cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            cin>>mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
            cout<<endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> &mat1, Matrica<TipElemenata> &mat2){
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto mat3(StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona));
    for(int i=0;i<mat1.br_redova;i++){
        for(int j=0;j<mat2.br_kolona;j++){
           for(int k=0;k<mat1.br_kolona;k++){
               mat3.elementi[i][j]+=mat1.elementi[i][k]*mat2.elementi[k][j];
           }
        }
    }
    return mat3;
}
template <typename TipElemenata>
Matrica<TipElemenata> MnozenjeSkalarom(Matrica<TipElemenata> &mat, double skalar){
    auto mat1(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i=0;i<mat1.br_redova;i++){
        for(int j=0;j<mat1.br_kolona;j++){
            mat1.elementi[i][j]=skalar*mat.elementi[i][j];
        }
    }
    return mat1;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &mat, std::vector<double> v){
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata>nova, s, proizvod, kvadratna, zbir;
    if(v.size()==0){
        auto mat1(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        for(int i=0;i<mat1.br_redova;i++){
            for(int j=0;j<mat1.br_kolona;j++){
                mat1.elementi[i][j]=0;
            }
        }
        return mat1;
    }
    else{
        Matrica<TipElemenata>nova,s;
        auto I(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        for(int i=0;i<I.br_redova;i++){
            for(int j=0;j<I.br_kolona;j++){
                if(i==j) I.elementi[i][j]=1;
            }
        }
        s=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
        for(int i=0;i<s.br_redova;i++){
            for(int j=0;j<s.br_kolona;j++){
                s.elementi[i][j]=0;
            }
        }
        for(int k=0;k<v.size();k++){
            if(k==0){
                auto rez(MnozenjeSkalarom<TipElemenata>(I, v[k]));
                zbir=ZbirMatrica<TipElemenata>(s, rez);
                auto brisanje(s);
                s=zbir;
                UnistiMatricu(rez);
                UnistiMatricu(brisanje);
                UnistiMatricu(I);
            }
            else if(k==1){
                auto rez(MnozenjeSkalarom<TipElemenata>(mat, v[k]));
                zbir=ZbirMatrica<TipElemenata>(s, rez);
                auto brisanje(s);
                s=zbir;
                UnistiMatricu(rez);
                UnistiMatricu(brisanje);
            }
            else if(k==2){
                try{
                    kvadratna=ProduktMatrica<TipElemenata>(mat, mat);
                    auto rez(MnozenjeSkalarom<TipElemenata>(kvadratna, v[k]));
                    zbir=ZbirMatrica<TipElemenata>(s, rez);
                    auto brisanje(s);
                    s=zbir;
                    UnistiMatricu(rez);
                    UnistiMatricu(brisanje);
                }
                catch(std::domain_error){
                    throw;
                }
            }
            else{
                try{
                    proizvod=ProduktMatrica<TipElemenata>(kvadratna, mat);
                    auto rez(MnozenjeSkalarom<TipElemenata>(proizvod, v[k]));
                    zbir=ZbirMatrica<TipElemenata>(s, rez);
                    auto brisanje(s);
                    auto brisanje1(kvadratna);
                    s=zbir;
                    kvadratna=proizvod;
                    UnistiMatricu(rez);
                    UnistiMatricu(brisanje);
                    UnistiMatricu(brisanje1);
                }
                catch(std::domain_error){
                    throw;
                }
            }
            if(k==v.size()-1) {
                UnistiMatricu(kvadratna);
                return s;
            }
        }
        if(v.size()>2) UnistiMatricu(kvadratna);
    }
    return s;
}
int main ()
{
    Matrica<double> a;
    int m, red;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>m;
    try {
        a=StvoriMatricu<double>(m, m);
        cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        cout<<"Unesite red polinoma: ";
        cin>>red;
        cout<<"Unesite koeficijente polinoma: ";
        std::vector<double>v;
        for(int i=0;i<=red;i++){
            double el;
            cin>>el;
            v.push_back(el);
        }
        IspisiMatricu(MatricniPolinom<double>(a, v), 10, 6, true);
    }
    catch(std::domain_error iz){
        cout<<iz.what()<<endl;
    }
    catch (std::bad_alloc) {
        cout <<"Nema dovoljno memorije!"<<endl;
    }
    UnistiMatricu(a); 
    return 0;
}