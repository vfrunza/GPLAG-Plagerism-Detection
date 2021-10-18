#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using namespace std;
template <typename Tip>
    struct Matrica{
        int redovi,kolone;
        Tip **elementi = nullptr;
    };
 
template <typename Tip>
    Matrica<Tip> StvoriMatricu(int redovi,int kolone){
        Matrica<Tip> prim;
        prim.redovi = redovi;prim.kolone = kolone;
        prim.elementi = new Tip*[redovi];
        for(int i=0;i<redovi;i++) prim.elementi[i] = nullptr;
        try{
            for(int i=0;i<redovi;i++)
                prim.elementi[i] = new Tip[kolone];
        }catch(...){
            UnistiMatricu(prim);
            throw;
        }
        return prim;
    } 
template <typename Tip>
    void UnesiMatricu(char ime, Matrica<Tip> &prim){
        for(int i=0;i<prim.redovi;i++)
            for(int j=0;j<prim.kolone;j++){
                cout << ime << "(" << i + 1 << "," << j+1 << ") = ";
                cin >> prim.elementi[i][j];
            }
    }
    
template <typename Tip>
    void IspisiMatricu(const Matrica<Tip> &prim,int sirina_ispisa,int preciznost = 6,bool treba_bristati = false){
        for(int i=0;i<prim.redovi;i++){
            for(int j=0;j<prim.kolone;j++)
                cout << setw(sirina_ispisa) << setprecision(preciznost) << prim.elementi[i][j];
            cout << endl;
        }
        if(treba_bristati)UnistiMatricu(prim);
    }    
    
    
template <typename Tip>
    void UnistiMatricu(Matrica<Tip> prim){
        if(!prim.elementi)return;
        for(int i=0;i<prim.redovi;i++) delete[] prim.elementi[i];
        delete[] prim.elementi;
        prim.elementi = nullptr;
    }


template <typename Tip>
    Matrica<Tip> ZbirMatrica(const Matrica<Tip> &prva,const Matrica<Tip> &druga){
        if(prva.redovi != druga.redovi || prva.kolone != druga.kolone)
            throw domain_error("Matrice nemaju jednake dimenzije!");
            auto kraj(StvoriMatricu<Tip>(prva.redovi,prva.kolone));
            for(int i=0;i<prva.redovi;i++)
                for(int j=0;j<prva.kolone;j++)
                    kraj.elementi[i][j] = prva.elementi[i][j] + druga.elementi[i][j];
        return kraj;
    }
    
template<typename Tip>
void PomnoziSaSkalarom(Matrica<Tip> prim,double skalar){
    for(int i=0;i<prim.redovi;i++)
        for(int j=0;j<prim.kolone;j++)prim.elementi[i][j]*=skalar;
}    
 
template<typename Tip>
Matrica<Tip> ProduktMatrica(const Matrica<Tip> &prva,const Matrica<Tip> &druga){
    if(prva.kolone != druga.redovi) throw domain_error("Matrice nisu saglasne za mnozenje");
    auto kraj(StvoriMatricu<Tip>(prva.redovi,druga.kolone));
    for(int i=0;i<prva.redovi;i++)
        for(int j=0;j<druga.kolone;j++){
            Tip suma=0;
            for(int k=0;k<druga.redovi;k++)suma+=prva.elementi[i][k]*druga.elementi[k][j];
            kraj.elementi[i][j]=suma;
        }
    return kraj;
}

template <typename Tip>
Matrica<Tip> MatricniPolinom(Matrica<Tip> prim,vector<double> v){
    if(prim.kolone != prim.redovi)throw domain_error("Matrica mora biti kvadratna");
    auto prim_polinom(StvoriMatricu<Tip>(prim.kolone,prim.kolone));
    for(int i=0;i<prim.redovi;i++)
        for(int j=0;j<prim.kolone;j++)prim_polinom.elementi[i][j]=0;
    for(int i=0;i < v.size();i++){
        if(v[i]==0)continue;
       try{
           auto jed_matrica(StvoriMatricu<Tip>(prim.redovi,prim.kolone));
            for(int i=0;i<prim.redovi;i++)
                for(int j=0;j<prim.kolone;j++){
                    if(i == j)jed_matrica.elementi[i][j]=1;
                    else jed_matrica.elementi[i][j]=0;
                }
            for(int j=0;j<i;j++){
                auto tmp(jed_matrica);
                try{
                    jed_matrica = ProduktMatrica(prim,jed_matrica);
                    UnistiMatricu(tmp);
                }catch(...){
                    UnistiMatricu(jed_matrica);
                    throw;
                }
            }
            PomnoziSaSkalarom(jed_matrica,v[i]);
            try{
                auto tmp(prim_polinom);
                prim_polinom=ZbirMatrica(prim_polinom,jed_matrica);
                UnistiMatricu(jed_matrica);
                UnistiMatricu(tmp);
            }catch(...){
                UnistiMatricu(jed_matrica);
                throw;
            }
       }catch(...){
           UnistiMatricu(prim_polinom);
           throw;
       }
    }
    return prim_polinom;
}
int main ()
{
    Matrica<double> matrica;
    vector<double> tmp;
    int a,b;
    cout << "Unesite dimenziju kvadratne matrice: ";
    cin >> a;
   
    try{
        matrica = StvoriMatricu<double>(a,a);
        cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A',matrica);
        cout << "Unesite red polinoma: ";
        cin >> b;
        cout << "Unesite koeficijente polinoma: ";
        for(int i=0;i<=b;i++){
            double x;
            cin >> x;
            tmp.push_back(x);
        }
        IspisiMatricu(MatricniPolinom(matrica,tmp),10,6,true);
        UnistiMatricu(matrica);
    }catch(...){
        UnistiMatricu(matrica);
    }
   
    return 0;
}