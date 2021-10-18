#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using namespace std;

template <typename TipElemenata>
 struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
 };

template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi = nullptr;
 }

template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    try {
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        for(int i = 0; i < br_redova; i++)
        mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
 }

template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
        std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
        }
 }

template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
    std::cout << std::endl;
    }
    if(treba_brisati) {
        UnistiMatricu(mat);
    }
 }

 template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i = 0; i < m1.br_redova; i++)
         for(int j = 0; j < m1.br_kolona; j++)
             m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
     return m3;
 }

 template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
     try {
      if(m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
      Matrica<TipElemenata> nova;
     nova=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
     for(int i=0; i<nova.br_redova; i++) {
         for(int j=0; j<nova.br_kolona; j++) {
             nova.elementi[i][j]=0;
         }
     }
     for(int i=0; i<m1.br_redova; i++) {
         for(int j=0; j<m2.br_kolona; j++) {
             for(int k=0; k<m1.br_kolona; k++) {
                 nova.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
             }
         }
     }
     return nova;
     }
     catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
    }
 }

 template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, vector<double> koeficijenti) {
  try {
     if(m.br_kolona!=m.br_redova) throw domain_error("Matrica mora biti kvadratna");
     Matrica<TipElemenata> jedinicina, temp, mnozitelj, povratna;
     jedinicina=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
     temp=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
     povratna=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
     mnozitelj=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
     for(int j=0; j<m.br_redova; j++) {
         for(int k=0; k<m.br_kolona; k++) {
             if(k==j) mnozitelj.elementi[j][k]=1;
             else mnozitelj.elementi[j][k]=0;
         }
     }
     for(int i=0; i<povratna.br_redova; i++) {
         for(int j=0; j<povratna.br_kolona; j++) {
             povratna.elementi[i][j]=0;
             temp.elementi[i][j]=0;
         }
     }
     for(int i=0; i<koeficijenti.size(); i++) {
         for(int j=0; j<m.br_redova; j++) {
             for(int k=0; k<m.br_kolona; k++) {
                if(k==j) jedinicina.elementi[j][k]=koeficijenti[i];
                else jedinicina.elementi[j][k]=0;
             }
         }
         Matrica<TipElemenata> prva(temp), druga(povratna), treca(mnozitelj);
         temp=ProduktMatrica(jedinicina,mnozitelj);
         povratna=ZbirMatrica(povratna, temp);
         mnozitelj=ProduktMatrica(mnozitelj, m);
         UnistiMatricu(prva); UnistiMatricu(druga); UnistiMatricu(treca);
     }
     UnistiMatricu(jedinicina);
     UnistiMatricu(mnozitelj);
     UnistiMatricu(temp);
     return povratna;
  }
  catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
 }
 }

int main() {
 Matrica<double> a, matrica_polinom;
 int m, red_polinoma;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 vector<double> koeficijenti;
 try {
     a = StvoriMatricu<double>(m, m);
     std::cout << "Unesite elemente matrice A: \n";
     UnesiMatricu('A', a);
     cout << "Unesite red polinoma: ";
     cin >> red_polinoma;
     cout << "Unesite koeficijente polinoma: ";
     double koeficijent;
     for(int i=0; i<=red_polinoma; i++) {
        cin >> koeficijent;
        koeficijenti.push_back(koeficijent);
     }
     matrica_polinom=MatricniPolinom<double>(a,koeficijenti);
     IspisiMatricu(matrica_polinom, 10);
 }
 catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
 }
 catch(domain_error ne) {
     cout << ne.what();
 }
 UnistiMatricu(a);
 UnistiMatricu(matrica_polinom);
 return 0;
}