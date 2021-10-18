#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

using namespace std;

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> matrica) {
    if(!matrica.elementi) return;
    for(int i=0;i<matrica.br_redova;i++) delete[] matrica.elementi[i];
    delete [] matrica.elementi;
    matrica.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> matrica;
    matrica.br_redova=br_redova;
    matrica.br_kolona=br_kolona;
    matrica.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) matrica.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++) matrica.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(matrica);
        throw;
    }
    return matrica;
}

template <typename TipElemenata>
void UnesiMatricu (char ime, Matrica <TipElemenata> &matrica) {
    for(int i=0;i<matrica.br_redova;i++)
    for(int j=0;j<matrica.br_kolona;j++) {
        cout<< ime <<"(" << i+1<<","<<j+1<<") = ";
        cin>>matrica.elementi[i][j];
    }
}

template <typename TipElemenata>
void IspisiMatricu (Matrica<TipElemenata> &matrica,int sirina, int preciznost=6, bool treba_brisati=true) {
    for(int i=0;i<matrica.br_redova;i++) {
        for(int j=0;j<matrica.br_kolona;j++) cout<<setprecision(preciznost)<<setw(sirina)<<matrica.elementi[i][j];
        cout<<"\n";
    }
    if(treba_brisati) UnistiMatricu(matrica);
}

template <typename TipElemenata>
Matrica<TipElemenata>ZbirMatrica(Matrica<TipElemenata> &A, Matrica<TipElemenata> &B) {
    if(A.br_redova != B.br_redova || A.br_kolona != B.br_kolona) throw domain_error("Matrice nemaju jednake dimenzije!");
    auto C=StvoriMatricu<TipElemenata>(A.br_redova, B.br_kolona);
    for(int i=0;i<A.br_redova;i++)
    for(int j=0;j<A.br_kolona;j++) 
    C.elementi[i][j]=A.elementi[i][j]+B.elementi[i][j];
    return C;
}

template <typename TipElemenata>
void SaberiSa(Matrica<TipElemenata> &A, Matrica<TipElemenata> &B) {
    for(int i=0;i<A.br_redova;i++)
    for(int j=0;j<A.br_kolona;j++)
    A.elementi[i][j] += B.elementi[i][j];
}
template<typename TipElemenata> 
void PomnoziSaSkalarom(Matrica<TipElemenata> &A, double x) {
    for(int i=0;i<A.br_redova;i++) 
    for(int j=0;j<A.br_kolona;j++)
    A.elementi[i][j] *=x;
}

template<typename TipElemenata> 
void KopirajMatricu(Matrica <TipElemenata> &A, Matrica <TipElemenata> &B) {
    for(int i=0;i<A.br_redova;i++)
    for(int j=0;j<A.br_kolona;j++)
    B.elementi[i][j]=A.elementi[i][j];
}

template<typename TipElemenata> 
Matrica<TipElemenata>ProduktMatrica(Matrica <TipElemenata> &A, Matrica <TipElemenata> &B) {
    Matrica<TipElemenata>C;
    try{
        C=StvoriMatricu<TipElemenata>(A.br_redova,B.br_kolona);
    }
    catch (bad_alloc) {
        throw;
    }
    for(int i=0;i<A.br_redova;i++) {
        for(int j=0;j<B.br_kolona;j++) {
            TipElemenata suma{};
            for(int k=0;k<A.br_kolona;k++) {
                suma+= A.elementi[i][k] * B.elementi[k][j];
            }
            C.elementi[i][j] = suma;
        }
    }
    return C;
}

template <typename TipElemenata>
Matrica<TipElemenata> Jedinicna(int br_redova, int br_kolona){
    auto matrica = StvoriMatricu<TipElemenata>(br_redova,br_kolona);
    
    for(int i=0; i<br_redova; i++)
    for(int j=0; j<br_kolona;j++){
        if(i==j) matrica.elementi[i][j]=1;
        else matrica.elementi[i][j]=0;
    }
    return matrica;
}

template <typename TipElemenata>
void Anuliraj(Matrica<TipElemenata> &matrica) {
    for(int i=0;i<matrica.br_redova;i++)
    for(int j=0;j<matrica.br_kolona;j++) {
        matrica.elementi[i][j]=0;
    }
}

template<typename TipElemenata>

void PomnoziSa (Matrica <TipElemenata> &A, Matrica <TipElemenata> &B) {
    auto nova(StvoriMatricu<TipElemenata>(A.br_redova, B.br_kolona));
        Anuliraj(nova);
        for(int i=0;i<A.br_redova;i++){
            for(int j=0;j<B.br_kolona;j++){
                for(int k=0;k<A.br_kolona;k++){
                    nova.elementi[i][j] += A.elementi[i][k]*B.elementi[k][j];
                }
            }
        }
        for(int i=0;i<nova.br_redova;i++){
            for(int j=0;j<nova.br_kolona;j++){
                A.elementi[i][j]=nova.elementi[i][j];
            }
        }
        UnistiMatricu(nova);
}

template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata>&matrica, vector<double>skalari) {
    int br_skalara = skalari.size();
    auto polinom(StvoriMatricu<TipElemenata>(matrica.br_redova,matrica.br_kolona));
    auto kvadrat(StvoriMatricu<TipElemenata>(matrica.br_redova,matrica.br_kolona));
    Matrica<TipElemenata> nova;
    Anuliraj(polinom);
    KopirajMatricu(matrica,kvadrat); 
  
    for(int q=0;q<br_skalara;q++){
        if(q==0) Matrica <TipElemenata> Jedinicna(kvadrat);
        else{
            KopirajMatricu(matrica, kvadrat);
            for(int i(1);i<q;i++) {
            nova=ProduktMatrica(kvadrat,matrica);
            UnistiMatricu(kvadrat);
            kvadrat=nova;
            }
        PomnoziSa(kvadrat, skalari[q]);
        SaberiSa(polinom,kvadrat);
    
        }
 
    }

        UnistiMatricu(nova);
        UnistiMatricu(kvadrat);
        return polinom;
}


int main() {
    Matrica<double>a,b,c;
    int n;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>n;
    try {
        a=StvoriMatricu<double>(n,n);
 
        cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
 
    int r;
    cout<<"Unesite red polinoma: ";
    cin>>r;
 
    vector<double> skalari;
    double skalar;
    cout<<"Unesite koeficijente polinoma: ";
    for(int i=0;i<r+1;i++){
        cin>>skalar;
        skalari.push_back(skalar);
    }
    IspisiMatricu<double>(c = MatricniPolinom<double>(a, skalari), 10, 6, false);
    }
    catch(bad_alloc) {
        cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);UnistiMatricu(c);
    return 0;
}