/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using namespace std;

template <typename TipElemenata>

struct Matrica {
    int br_redova;
    TipElemenata**elementi= nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat) {
    if(!mat.elementi) 
        return;

    for(int i = 0; i < mat.br_redova; i++) 
        delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) 
        mat.elementi[i] = nullptr;

    try {
        for(int i = 0; i < br_redova; i++) 
        mat.elementi[i] = new TipElemenata[br_redova];  
        for(int i = 0; i < br_redova; i++) 
            for(int j=0; j<br_redova; j++) mat.elementi[i][j]=0;
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_redova; j++) {
            cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
            cin >> mat.elementi[i][j];
        }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat, int sirina_ispisa) {

    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_redova; j++) 
            cout << setw(sirina_ispisa) << mat.elementi[i][j];
            cout << endl;
        }
}

/*template<typename TipElemenata>Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)throw domain_error("Matrice nemaju jednake dimenzije!");
auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
for(int i = 0; i < m1.br_redova; i++)
for(int j = 0; j < m1.br_kolona; j++)
m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
return m3;
}
*/

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &a, const Matrica<TipElemenata> &b) {

    auto mat(StvoriMatricu<TipElemenata>(a.br_redova));
    if(a.br_redova != b.br_redova )throw domain_error("Matrice nemaju jednake dimenzije!");

    try {
        
        for(int i=0; i<a.br_redova; i++) {
            for(int p=0; p<b.br_redova; p++) {
                int suma=0;
                for(int j=0; j<a.br_redova; j++)
                    suma+=a.elementi[i][j]*b.elementi[j][p];
                mat.elementi[i][p]=suma;
            }
        }
} catch(...) {
    UnistiMatricu(mat);
    throw;
}


return mat;
}


template<typename TipElemenata, typename t>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &a, int n, t p) {
//Ovo int *p ne smije biti int mora primiti genericki kontejner ili iterator tako da bi trebao jos jedan argument uvesti nesto tipa (tip p)
    auto b(StvoriMatricu<TipElemenata>(a.br_redova));
    auto c(StvoriMatricu<TipElemenata>(a.br_redova));
    
    Matrica<TipElemenata> temp;
    int pom=1;
    
    for(int i=0; i<b.br_redova; i++) {
        for(int j=0; j<b.br_redova; j++) {
            if(i==j) 
                b.elementi[i][j] = 1;
            else 
                b.elementi[i][j] = 0;
        }
    }
    
    for(int i=0; i<a.br_redova; i++) 
        for(int j=0; j<a.br_redova; j++)
            c.elementi[i][j] = b.elementi[i][j]*(*p);
    p++;
                
    while(pom<=n+1) {
        int br=pom;
        b=ProduktMatrica(a,temp=b);
        UnistiMatricu(temp);
        for(int i=0; i<a.br_redova; i++) {
            for(int j=0; j<a.br_redova; j++) {
                c.elementi[i][j]+=b.elementi[i][j]*(*p);
            }
        }
    //IspisiMatricu(c,5);
    pom++;
    p++;
    
    }
    UnistiMatricu(b);
    return c;
}


int main() {

    Matrica<double> a, b;

    int n,red;
    cout << "Unesite dimenziju kvadratne matrice: ";
    cin>> n;
    try
    {
        a = StvoriMatricu<double>(n); 
        //b = StvoriMatricu<double>(n);
        cout << "Unesite elemente matrice A:"<<endl;
        UnesiMatricu('A', a);
        //IspisiMatricu(c = ZbirMatrica(a, b), 7);
    }
    catch(bad_alloc &e) {
        cout << "Nema dovoljno memorije!"<<e.what()<<endl;
    }

    cout<<"Unesite red polinoma: ";
    cin>>red;

    vector<int> niz(red+1);

    cout<<"Unesite koeficijente polinoma: ";
    for(int i=0; i<red+1; i++) {
        cin>>niz[i];
    }


    IspisiMatricu(b=MatricniPolinom(a,n,niz.begin()),10);
    UnistiMatricu(a); UnistiMatricu(b); 

    return 0;
}
