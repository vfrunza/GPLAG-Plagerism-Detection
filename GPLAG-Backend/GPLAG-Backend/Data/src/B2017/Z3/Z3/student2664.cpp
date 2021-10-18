/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <new> //bad_alloc

using std::domain_error;
using std::setprecision;
using std::vector;
using std::cout;
using std::endl;
using std::setw;
using std::cin;

template <typename Tip>
 struct Matrica{
    int br_redova, br_kolona;
    Tip **elementi = nullptr; //!!
 };

template <typename Tip>
 void UnistiMatricu(Matrica<Tip> mat){
     if(mat.elementi == nullptr) return; 
     for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
     delete[] mat.elementi;
     mat.elementi = nullptr;
 }
template <typename Tip>
 Matrica<Tip> StvoriMatricu(int br_redova, int br_kolona){
     Matrica<Tip> mat;
     mat.br_redova = br_redova;
     mat.br_kolona = br_kolona;
     mat.elementi = new Tip*[br_redova];
     for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
     try{
         for(int i=0; i<br_redova; i++)
            mat.elementi[i] = new Tip[br_kolona];
     }
     catch(...){
         UnistiMatricu(mat);
         throw;
     }
     return mat;
 }
template <typename Tip>
 void UnesiMatricu(char ime_matrice, Matrica<Tip> &mat){
     for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++){
            cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            cin >> mat.elementi[i][j];
        }
 }
template <typename Tip>
 Matrica<Tip> ZbirMatrica(const Matrica<Tip> &m1, const Matrica<Tip> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_redova != m2.br_kolona)
        throw domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<Tip>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
 }
template <typename Tip>
 Matrica<Tip> Saberi(Matrica<Tip> m1, Matrica<Tip> pom){
    for(int i=0; i<m1.br_kolona; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m1.elementi[i][j] += pom.elementi[i][j];
    
    UnistiMatricu(pom);
    return m1;
 }
template <typename Tip>
 Matrica<Tip> Pomnozi(Matrica<Tip> m1, Matrica<Tip> m2){
    auto m3(StvoriMatricu<Tip>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++){
            Tip suma{}; //??
            for(int k=0; k<m2.br_redova; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
        
    UnistiMatricu(m1);
    m1 = m3;
    return m1;
        
 }
template <typename Tip>
 bool MoguSeMnoziti(const Matrica<Tip> &m1, const Matrica<Tip> &m2){
    return m1.br_kolona == m2.br_redova;
}
template <typename Tip>
 Matrica<Tip> ProduktMatrica(const Matrica<Tip> &m1, const Matrica<Tip> &m2){
    if(!MoguSeMnoziti(m1, m2)) throw domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<Tip>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++){
            Tip suma{}; //??
            for(int k=0; k<m2.br_redova; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
        
    return m3;
}
template <typename Tip>
 Matrica<Tip> MatricuPomnoziSkalarom(double x, const Matrica<Tip> &m){
    Matrica<Tip> pom(StvoriMatricu<Tip>(m.br_redova, m.br_kolona));
    for(int i=0; i<m.br_kolona; i++)
        for(int j=0; j<m.br_redova; j++)
            pom.elementi[i][j] = x * m.elementi[i][j];
         
    return pom; 
 }
template <typename Tip>
 Matrica<Tip> StvoriJedinicnu(int br_redova, int br_kolona){
    auto jedinicna(StvoriMatricu<Tip>(br_kolona, br_kolona));
    for(int i=0; i<jedinicna.br_kolona; i++)
        for(int j=0; j<jedinicna.br_kolona; j++){
            if(i==j) jedinicna.elementi[i][i] = 1;
            else jedinicna.elementi[i][j] = 0; //??
        }
    
    return jedinicna;
 }
template <typename Tip>
 Matrica<Tip> DubokaKopija(const Matrica<Tip> &A){
     auto kop(StvoriMatricu<Tip>(A.br_kolona, A.br_kolona));
     for(int i=0; i<kop.br_kolona; i++)
        for(int j=0; j<kop.br_kolona; j++)
            kop.elementi[i][j] = A.elementi[i][j];
     return kop;
 }

template <typename IterTip, typename Tip>
 Matrica<Tip> MatricniPolinom(Matrica<Tip> &A, int n, IterTip it){
    if(n<0) throw domain_error("Neispravan stepen polinoma");
    if(A.br_kolona != A.br_redova) throw domain_error("Matrica mora biti kvadratna");
    
   
    Matrica<Tip> zbir(StvoriMatricu<Tip>(0,0)), A_na_i(DubokaKopija(A));
    for(int i=0; i<=n; i++, it++){
        if(i==0) {
            UnistiMatricu(zbir);
            Matrica<Tip> jedinicna(StvoriJedinicnu<Tip>(A.br_kolona, A.br_redova));
            zbir = MatricuPomnoziSkalarom(*it, jedinicna);
            UnistiMatricu(jedinicna);
        }
        else if(i==1){
            Matrica<Tip> pom(MatricuPomnoziSkalarom(*it, A));
            zbir = Saberi(zbir, pom);
        }
        else{
            A_na_i = Pomnozi(A_na_i, A);
            Matrica<Tip> pom(MatricuPomnoziSkalarom(*it, A_na_i));
            zbir = Saberi(zbir, pom);
        }
    }
    UnistiMatricu(A);
    UnistiMatricu(A_na_i);

    return zbir; 
}

template <typename Tip> //const & ??
 void IspisiMatricu(const Matrica<Tip> &mat, int sirina_ispisa, bool treba_brisati = false, int preciznost = 6){
     for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++)
            cout << setw(sirina_ispisa) << setprecision(preciznost) << mat.elementi[i][j];
        cout << endl;
     }
     if(treba_brisati)  UnistiMatricu(mat);
     
}
    

int main (){
    /*
    int dim, n(0);
    cout << "Unesite dimenziju kvadratne matrice: ";
    cin >> dim;
    auto mat(StvoriMatricu<double>(dim, dim));
    cout << "Unesite elemente matrice A: \n";
    UnesiMatricu('A', mat);
    cout << "Unesite red polinoma: ";
    cin >> n;
    vector<double> koeficijenti(n+1);
    cout << "Unesite koeficijente polinoma: ";
    for(double &x : koeficijenti) cin >> x;
    vector<double>::iterator it(koeficijenti.begin());
    mat = MatricniPolinom(mat, n, it);
    IspisiMatricu(mat, 10, true); 
    */
    
  //AT6- Da li se unistava matrica ako se IspisiMatricu proslijedi true 
    Matrica<double> m1, m2, m3;
    m1 = StvoriMatricu<double>(3,3);
    UnesiMatricu<double>('A', m1);
    IspisiMatricu(m1, 10, 13, true);
   
   
	return 0;
}
