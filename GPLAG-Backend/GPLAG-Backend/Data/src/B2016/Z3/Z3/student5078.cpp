/B2016/2017: Zadaća 3, Zadatak 3
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
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout <<std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati){
        UnistiMatricu(mat);
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++){
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];}
    return m3;
}

template<typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2,int koeficijent=1){
    if(m1.br_kolona==m2.br_redova){
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0;i<m3.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            TipElemenata suma=0;
            for(int k=0;k<m2.br_redova;k++){
                suma=suma+m1.elementi[i][k]*m2.elementi[k][j]*koeficijent;
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
    }
    else{
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
}
template<typename TipElemenata>
Matrica <TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &a,std::vector<TipElemenata> koeficijenti){
    if(a.br_redova!=a.br_kolona)throw std::domain_error("Matrica mora biti kvadratna");
    auto nula(StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona));
    if(koeficijenti.size()!=0){
    for(int i=0;i<a.br_kolona;i++){
        for(int j=0;j<a.br_redova;j++){
            if(i==j){nula.elementi[i][j]=1;continue;}
            nula.elementi[i][j]=0;
        }
    }
    }
    if(koeficijenti.size()==0){
    for(int i=0;i<a.br_kolona;i++){
        for(int j=0;j<a.br_redova;j++){
            nula.elementi[i][j]=0;
        }
    }
    return nula;
    }
    auto pomocna(StvoriMatricu<TipElemenata>(a.br_kolona,a.br_kolona));
    for(int i=0;i<a.br_kolona;i++){
        for(int j=0;j<a.br_kolona;j++){
            pomocna.elementi[i][j]=a.elementi[i][j];
        }
    }
    auto suma=nula;
    for(int i=0;i<koeficijenti.size();i++){
        if(i==0){
            suma=ProduktMatrica(nula,nula,koeficijenti[i]);
            continue;
        }
        else if(i==1){
            auto pomocna_s=ProduktMatrica(a,nula,koeficijenti[i]);
            auto kopija_suma=suma;
            suma=ZbirMatrica(pomocna_s,suma);
            UnistiMatricu(pomocna_s);
            UnistiMatricu(kopija_suma);
            UnistiMatricu(nula);
        }
        else{
            auto pomocna_kopija_stepen=pomocna;
            auto pomocna_s=ProduktMatrica(a,pomocna,koeficijenti[i]);
            auto kopija_suma=suma;
            suma=ZbirMatrica(suma,pomocna_s);
            pomocna=ProduktMatrica(pomocna,a);
            UnistiMatricu(pomocna_kopija_stepen);
            UnistiMatricu(pomocna_s);
            UnistiMatricu(kopija_suma);
        }

    }
    UnistiMatricu(pomocna);
return suma;
}

int main()
{
    Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        int br_polinoma;
        std::cout<< "Unesite red polinoma: ";
        std::cin>>br_polinoma;
        std::vector<double> vect;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=br_polinoma;i++){
            int koef;
            std::cin>>koef;
            vect.push_back(koef);
        }
        IspisiMatricu(c = MatricniPolinom( a,vect ),10);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(c);
    return 0;
}
