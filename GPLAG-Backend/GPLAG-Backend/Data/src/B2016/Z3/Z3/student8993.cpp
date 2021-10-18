/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <new>
template <typename TipElemenata>
    struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
    };
    
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
    }
    
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
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
        for(int j = 0; j < mat.br_kolona; j++){
            std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
        if(treba_brisati){
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
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica <TipElemenata> rezultat;
    try{
        rezultat=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
        for(int i=0; i<rezultat.br_redova; i++){
            for(int j=0; j<rezultat.br_kolona; j++){
                TipElemenata suma{};
                for(int k=0; k<m1.br_kolona; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
                rezultat.elementi[i][j]=suma;
            }
        }
    }
    catch(...){
        throw;
    }
    return rezultat;
}

template <typename TipElemenata>
void MnozenjeBrojem ( Matrica<TipElemenata> &m, double b){
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++) m.elementi[i][j]*=b;
    }

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &m, std::vector<double> v){
    if(m.br_kolona!=m.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    Matrica<TipElemenata> rezultat;
    try {
        rezultat=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
        for(int i=0; i<m.br_kolona; i++){ //stvaranje jedinicne kao rezultata
            for(int j=0; j<m.br_redova; j++) {
                if(i==j) rezultat.elementi[i][i]=(TipElemenata)1;
                else rezultat.elementi[i][j]=(TipElemenata)0;
            }
        }
        if(v.size()==0) { MnozenjeBrojem(rezultat, (TipElemenata)0); return rezultat;} //ako je prazan vektor
        else{ //ako nije
            for(int k=0; k<v.size(); k++){
                Matrica<TipElemenata> stepenovana(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
                for(int i=0; i<m.br_kolona; i++){
                    for(int j=0; j<m.br_redova; j++) stepenovana.elementi[i][j]=m.elementi[i][j];
                }
                for(int j=2; j<=k; j++) { 
                    Matrica<TipElemenata> p(ProduktMatrica(stepenovana,m));
                    UnistiMatricu(stepenovana); 
                    stepenovana.br_kolona=p.br_kolona; stepenovana.br_redova=p.br_redova; 
                    stepenovana.elementi=p.elementi;
                    p.elementi=nullptr; 
                }
                if(k==0){ MnozenjeBrojem(rezultat,v[k]); UnistiMatricu(stepenovana);} // za nulti stepen
                else{
                    MnozenjeBrojem(stepenovana,v[k]); 
                    Matrica<TipElemenata> zbir(ZbirMatrica(rezultat,stepenovana));
                    UnistiMatricu(rezultat); UnistiMatricu(stepenovana);
                    rezultat.br_kolona=zbir.br_kolona; rezultat.br_redova=zbir.br_redova; 
                    rezultat=zbir;
                    zbir.elementi=nullptr;
                }
            }
        }
    }
    catch (std::domain_error iz) {
        std::cout << iz.what() << std::endl;
    }
    catch(std::bad_alloc){
        throw;
    }
    return rezultat;
}


int main() {
 Matrica<double> a,b; //b, c;  AUTOMATSKA INICIJALIZACIJA!!!
 int m;// n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m ;//>> n;
 //samo da testiram
 try {
    a = StvoriMatricu<double>(m, m);
    std::cout << "Unesite elemente matrice A: "<<std::endl;
    UnesiMatricu('A', a);
    int red;
    std::cout << "Unesite red polinoma: ";
    std::cin >> red;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> koef(red+1);
    for(int i=0; i<=red; i++) std::cin >> koef[i];
    b=MatricniPolinom(a,koef);
    IspisiMatricu(b,10);
 }
 catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
 }
 catch(std::domain_error i){
     std::cout << i.what() << std::endl;
 }
 UnistiMatricu(a); UnistiMatricu(b); //UnistiMatricu(c);
 return 0;
}
