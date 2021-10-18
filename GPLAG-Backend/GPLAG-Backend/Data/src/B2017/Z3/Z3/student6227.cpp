/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

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
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
        std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
    std::cout << std::endl;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
        m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> prva, Matrica<TipElemenata> druga){
    if (prva.br_kolona!=druga.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> produkt;
    TipElemenata suma = 0;
    produkt=StvoriMatricu<TipElemenata>(prva.br_redova,druga.br_kolona);
    for (int i(0);i<produkt.br_redova;i++){
        for(int j(0);j<produkt.br_kolona;j++){
            //suma=0;
            for(int k(0);k<druga.br_redova;k++){
                suma+=(prva.elementi[i][k]*druga.elementi[k][j]);
            }
            produkt.elementi[i][j]=suma;
            suma=0;
        }
    }
    return produkt;
}

template <typename TipElemenata, typename Tip2>
Matrica<TipElemenata> ProduktMatriceSkalarom(Matrica<TipElemenata> A, Tip2 skalar) {
    Matrica<TipElemenata> NovaMatrica;
    NovaMatrica=StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);
    for (int i(0);i<A.br_redova;i++){
        for (int j(0);j<A.br_kolona;j++){
            NovaMatrica.elementi[i][j]=skalar*A.elementi[i][j];
        }
    }
    return NovaMatrica;
}

template <typename TipElemenata>
void Postaje(Matrica<TipElemenata> &a,const Matrica<TipElemenata> &b){
    for (int i(0);i<a.br_redova;i++){
        for (int j(0);j<b.br_kolona;j++){
            a.elementi[i][j]=b.elementi[i][j];
        }
    }
}

template <typename TipElemenata,typename Tip2>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A, std::vector<Tip2> koef) {
    if(A.br_kolona!=A.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    bool nullvektor=false;
    if (koef.size()==0) nullvektor=true;
    Matrica<TipElemenata> suma=StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);
    Matrica<TipElemenata> jedinicna=StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona);
    for (int i(0);i<jedinicna.br_redova;i++){
        for (int j(0);j<jedinicna.br_kolona;j++){
            if (i==j && nullvektor==false) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=0;
        }
    }
    if (nullvektor){
        UnistiMatricu(suma);
        return jedinicna;
    }
    for (int i(0);i<koef.size();i++){
        if (i==0){
            Matrica<TipElemenata> a=ProduktMatriceSkalarom(jedinicna,koef[i]);
            Postaje(suma,a);
            UnistiMatricu(a);
        }
        else if (i==1){
            Matrica<TipElemenata> a=ProduktMatriceSkalarom(A,koef[i]), b=ZbirMatrica(suma,a);
            Postaje(suma,b);
            UnistiMatricu(a);
            UnistiMatricu(b);
        }
        else {
            Matrica<TipElemenata> stepenovana =ProduktMatrica(A,A);
            for (int k(0);k<i-2;k++){
                Matrica<TipElemenata> a=ProduktMatrica(stepenovana,A);
                Postaje(stepenovana,a);
                UnistiMatricu(a);
            }
            Matrica<TipElemenata> b=ProduktMatriceSkalarom(stepenovana,koef[i]);
            Postaje(stepenovana,b);
            Matrica<TipElemenata> c=ZbirMatrica(suma,stepenovana);
            Postaje(suma,c);
            UnistiMatricu(c);
            UnistiMatricu(b);
            UnistiMatricu(stepenovana);
        }
    }
    UnistiMatricu(jedinicna);
    return suma;
}

int main() {
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int m,n,i(0);
    std::cin >> m;
    std::cout << "Unesite elemente matrice A: \n";
    Matrica<double> a=StvoriMatricu<double>(m,m),b;
    UnesiMatricu('A',a);
    std::cout<< "Unesite red polinoma: ";
    std::cin >> n;
    if(n==0) n--;
    std::cout<< "Unesite koeficijente polinoma: ";
    double k;
    std::vector<double> koeficijenti;
    while(i<=n) {
        std::cin >>k;
        koeficijenti.push_back(k);
        i++;
    }
    
    b=MatricniPolinom(a,koeficijenti);
    IspisiMatricu(b,10);
    UnistiMatricu(b);
    UnistiMatricu(a);

return 0;
}


