#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template<typename TipElemenata>
struct Matrica {
int br_redova, br_kolona;
TipElemenata **elementi= nullptr; // VEOMA BITNA INICIJALIZACIJA!
};
template<typename TipElemenata>
void UnistiMatricu(Matrica <TipElemenata> mat) {
if(!mat.elementi) return;
for(int i = 0; i < mat.br_redova; i++)
    delete[] mat.elementi[i];

delete[] mat.elementi;
mat.elementi = nullptr;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
Matrica<TipElemenata> mat;
mat.br_redova = br_redova;
mat.br_kolona = br_kolona;


mat.elementi = new TipElemenata *[br_redova];
for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
try {
for(int i = 0; i < br_redova; i++)
mat.elementi[i] = new TipElemenata [br_kolona];
}
catch (...) {
UnistiMatricu(mat);
throw;
}
return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
for (int i = 0; i < mat.br_redova; i++)
for (int j = 0; j < mat.br_kolona; j++) {
std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
std::cin >> mat.elementi[i][j];
}
}
template<typename TipElemenata>
void
IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,
              int preciznost=6, bool treba_brisati=false )
{
for(int i = 0; i < mat.br_redova; i++) {
for(int j = 0; j < mat.br_kolona; j++)
std::cout << std::setw(sirina_ispisa) <<std::setprecision(6) << mat.elementi[i][j];
std::cout << std::endl;
}
if (treba_brisati) UnistiMatricu(mat);
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
throw std::domain_error("Matrice nemaju jednake dimenzije!");
auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
for(int i = 0; i < m1.br_redova; i++)
for(int j = 0; j < m1.br_kolona; j++)
m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
return
m3;
}
template <typename T>
 Matrica<T> ProduktMatrica (Matrica<T> a, Matrica<T> b){
     if (a.br_kolona != b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
     int n(a.br_kolona), q(b.br_kolona);
     auto c(StvoriMatricu<T>(n,q));
     for (int i=0; i<n; i++)
        for (int j = 0; j<q; j++)
            {
                T produkt(0);
                for (int k=0; k<n; k++){
                    produkt+=a.elementi[i][k]*b.elementi[k][j];
                }
                c.elementi[i][j]=produkt;
            }
    return c;
 }
 template <typename T>
    Matrica<T> skaliraj (double x, Matrica<T> m){

        for(int i=0; i<m.br_redova; i++)
            for (int j=0; j<m.br_kolona; j++)
                m.elementi[i][j]*=x;

        return m;
    }



template <typename T, typename t>
Matrica<T>  MatricniPolinom (Matrica<T> m, int n, t iterator){
     if (n<0) throw std::domain_error ("Neispravan stepen polinoma");
     if (m.br_redova!=m.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna");
     auto I(StvoriMatricu<T>(m.br_redova, m.br_redova));
     for (int i=0; i<m.br_redova; i++)
        for (int j=0; j<m.br_redova; j++){
            if (i==j) I.elementi[i][j] = 1; else I.elementi[i][j]=0;
        }
     auto zbir(StvoriMatricu<T>(m.br_redova, m.br_redova));
     for (int i=0; i<m.br_redova; i++) {
        for (int j=0; j<m.br_redova; j++) {
            zbir.elementi[i][j]=0;
        }
     }

       Matrica<T> p;
    for (int k=0; k<=n; k++) {
        if (k==0) p=I;
        else if (k==1) p=m;
        else {
         auto pomoca (p);
            p = ProduktMatrica(p, m);
        if (k!=2) {UnistiMatricu(pomoca); }
        }
        if ((*iterator)!=0){
        auto pzbir (zbir);
        zbir = ZbirMatrica (zbir, skaliraj ((*iterator), p));
        skaliraj (1./(*iterator), p);
        UnistiMatricu(pzbir);
        }
        iterator++;

    }
    UnistiMatricu(I);
    UnistiMatricu(p);

     return zbir;
 }


int main() {

// AUTOMATSKA INICIJALIZACIJA!!!
int m;
  Matrica<double> a;
std::cout << "Unesite dimenziju kvadratne matrice: ";
std::cin >> m;
try
{
  
a = StvoriMatricu<double>(m, m);
std::cout << "Unesite elemente matrice A:\n";
UnesiMatricu('A', a);
int r;
std::cout<<"Unesite red polinoma: ";
std::cin>>r;
std::vector<int> v;
std::cout<<"Unesite koeficijente polinoma: ";
for (int i=0; i<=r; i++){
    int x;
    std::cin>>x;
    v.push_back(x);
}

IspisiMatricu(MatricniPolinom(a, r, std::begin(v)), 10, 6, true );

}
catch(std::bad_alloc) {
std::cout << "Nema dovoljno memorije!\n";
}
UnistiMatricu(a);
return 0;
}
