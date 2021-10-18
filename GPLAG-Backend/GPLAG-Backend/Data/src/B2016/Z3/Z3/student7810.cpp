/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;
using std::domain_error;
template <typename NekiTip>
struct Matrica{
    int redovi,kolone;
    NekiTip **elementi=nullptr;
};
template <typename NekiTip>
void UnistiMatricu (Matrica<NekiTip> mat){
    if (!mat.elementi) return;
    for(int i=0;i<mat.redovi;i++) delete[] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
template <typename NekiTip>
Matrica<NekiTip> StvoriMatricu (int redovi,int kolone){
    Matrica<NekiTip> mat;
    mat.redovi=redovi; mat.kolone=kolone;
    mat.elementi=new NekiTip* [redovi];
    for(int i=0;i<redovi;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<redovi;i++){
            mat.elementi[i]=new NekiTip [kolone];
        }
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename NekiTip>
void UnesiMatricu (char ime, Matrica<NekiTip> &mat){
    for(int i=0;i<mat.redovi;i++){
       for(int j=0;j<mat.kolone;j++){
           cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
           cin>>mat.elementi[i][j];
        }
    }
}
template <typename NekiTip>
void IspisiMatricu(const Matrica<NekiTip> &mat, int sirinaispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0; i<mat.redovi; i++){
        for(int j=0; j<mat.kolone; j++){
            cout<<setw(sirinaispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
        }
        cout<<endl;
    }
    if(treba_brisati) UnistiMatricu(mat); 
}
template <typename NekiTip>
Matrica<NekiTip> ZbirMatrica (const Matrica<NekiTip> &mat1, const Matrica<NekiTip> &mat2){
    if((mat1.redovi!=mat2.redovi) || (mat1.kolone!=mat2.kolone)) throw domain_error ("Matrice nemaju jednake dimenzije");
    auto mat3(StvoriMatricu<NekiTip>(mat1.redovi,mat2.kolone));
    for(int i=0;i<mat1.redovi;i++){
        for(int j=0;j<mat1.kolone;j++){
            mat3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
        }
    }
    return mat3;
}
template <typename NekiTip>
Matrica<NekiTip> ProduktMatrica (const Matrica<NekiTip> &mat1, const Matrica<NekiTip> &mat2){
    if(mat1.kolone!=mat2.redovi) throw domain_error ("Matrice nisu saglasne za mnozenje");
    auto mat3(StvoriMatricu<NekiTip>(mat1.redovi,mat2.kolone));
    for(int i=0;i<mat1.redovi;i++){
        for(int j=0;j<mat2.kolone;j++){
            mat3.elementi[i][j]=0;
            for(int k=0;k<mat1.kolone;k++){
                mat3.elementi[i][j]+=(mat1.elementi[i][k]*mat2.elementi[k][j]);
            }
        }
    }
    return mat3;
}
template <typename NekiTip>
Matrica<NekiTip> ProduktMatriceSaSkalarom(Matrica<NekiTip> mat, int n){
    for(int i=0;i<mat.redovi;i++)
        for(int j=0;j<mat.kolone;j++)
        mat.elementi[i][j]*=n;;
        return mat;
}
template <typename NekiTip>
Matrica<NekiTip> MatricniPolinom (const Matrica<NekiTip> &mat, vector<double> v){
    if(mat.redovi!=mat.kolone) throw domain_error ("Matrica mora biti kvadratna");
    try{
    auto polinom(StvoriMatricu<NekiTip>(mat.redovi,mat.kolone));
        for(int i=0;i<mat.redovi;i++)
            for(int j=0;j<mat.kolone;j++)
                polinom.elementi[i][j]=0;
        if(v.size()==0){
            return polinom;
        }
    for(int i=0;i<v.size();i++){
        if(i==0){
            auto jedinicna(StvoriMatricu<NekiTip>(mat.redovi,mat.kolone));
            for(int i=0;i<mat.redovi;i++){
                for(int j=0;j<mat.kolone;j++){
                    if(i==j) jedinicna.elementi[i][j]=1;
                    else jedinicna.elementi[i][j]=0;
                }
            }
            jedinicna=ProduktMatriceSaSkalarom<NekiTip>(jedinicna,v[i]);
            auto matzabrisanje(polinom);
            polinom=ZbirMatrica<NekiTip>(polinom,jedinicna);
            UnistiMatricu<NekiTip>(jedinicna); UnistiMatricu<NekiTip>(matzabrisanje);
        }
        else{
            auto stepen (StvoriMatricu<NekiTip>(mat.redovi,mat.kolone));
            for(int i=0;i<mat.redovi;i++){
                for(int j=0;j<mat.kolone;j++){
                    if(i==j) stepen.elementi[i][j]=1;
                    else stepen.elementi[i][j]=0;
                }
            }auto matzabrisanje(stepen);
            for(int j=0;j<i;j++){
                matzabrisanje=stepen;
                stepen=ProduktMatrica<NekiTip>(stepen,mat);
                UnistiMatricu(matzabrisanje);
            }
            stepen=ProduktMatriceSaSkalarom<double>(stepen,v[i]);
            auto matzabrisanje2(polinom);
            polinom=ZbirMatrica<NekiTip>(polinom,stepen);
            UnistiMatricu<NekiTip>(stepen);UnistiMatricu<NekiTip>(matzabrisanje2);
        }
    }
    return polinom;
    }
    catch(...){
        throw;
    }
}
int main ()
{
    cout<<"Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    cin>>dimenzija;
    Matrica<double>mat,c;
    try{
        mat=(StvoriMatricu<double>(dimenzija,dimenzija));
        cout<<"Unesite elemente matrice A: "<<endl;
        UnesiMatricu<double>('A',mat);
        cout<<"Unesite red polinoma: ";
        int red_polinoma;
        cin>>red_polinoma;
        vector<double> v;
        cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=red_polinoma;i++){
            int x;cin>>x;
            v.push_back(x);
        }
        c = StvoriMatricu<double>(dimenzija,dimenzija);
        c = MatricniPolinom(mat,v);
        IspisiMatricu<double>(c,10);
    }
    catch(...){
        cout<<"Nema dovoljno memorije";
    }
    UnistiMatricu<double>(mat);UnistiMatricu<double>(c);
	return 0;
}