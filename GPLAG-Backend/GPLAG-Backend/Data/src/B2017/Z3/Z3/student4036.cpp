/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
    struct Matrica{
        int br_redova, br_kolona;
        TipElemenata **elementi=nullptr;
    };

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
    
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona){
        throw std::domain_error("Matrica nemaju jednake dimenzije!");
    }
    //auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m1.elementi[i][j]=m1.elementi[i][j] + m2.elementi[i][j];
    return m1;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> a, const Matrica<TipElemenata> b){
    if(a.br_kolona != b.br_redova)
        throw std::domain_error ("Matrice nisu saglasne za mnozenja");
    auto c(StvoriMatricu<TipElemenata>(a.br_redova, b.br_kolona));
    for(int i=0; i<c.br_redova; i++){
        for(int j=0; j<c.br_kolona; j++){
            c.elementi[i][j]={};
        }
    }
    int k(0);
    for(int i=0; i<a.br_redova; i++){
        //TipElemenata suma{};
        for(int j=0; j<b.br_kolona; j++){
            TipElemenata suma{};
            for(int l=0; l<a.br_kolona; l++)
                suma+=a.elementi[i][l]*b.elementi[l][j];
                c.elementi[i][k]=suma;
                k++;
        }
        k=0;
    }
    return c;
}

template <typename TipElemenata>
Matrica<TipElemenata> MnozenjeSkalarom(Matrica<TipElemenata> &a, double b){
    for(int i=0; i<a.br_redova; i++){
        for(int j=0; j<a.br_kolona; j++){
            a.elementi[i][j] *= b;
        }
    }
    return a;
}

template<typename TipElemenata, typename NekiTip>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> m1, int n, NekiTip pk){
    if(n<0) throw std::domain_error("Neispravan stepen polonoma");
    if(m1.br_kolona != m1.br_redova) {
        UnistiMatricu(m1);
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    
   /* auto b(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    for(int i=0; i<b.br_redova; i++){
        for(int j=0; j<b.br_kolona; j++){
            b.elementi[i][j]=0;
        }
    }
    
    bool logicka(false);
    auto pom(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    auto c(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    for(int k=0; k<c.br_redova; k++)
        for(int j=0; j<c.br_kolona; j++){
            c.elementi[k][j]=a.elementi[k][j];
        }
        
    
    int i=0;
    while (i<=n) {
        if(i==0){
            for(int k=0; k<b.br_redova; k++)
                for(int j=0; j<b.br_kolona; j++)
                    if(k==j){
                        b.elementi[k][j]=*pk;
                        pk++;}
                        i++;
        }
        else{
            if(logicka){
                auto pom2=c;
                c=ProduktMatrica(c,a);
                UnistiMatricu(pom2);
            }
            for(int k=0; k<c.br_redova; k++)
                for(int j=0; j<c.br_kolona; j++)
                    pom.elementi[k][j] = c.elementi[k][j];
            ZbirMatrica(b, MnozenjeSkalarom(pom,*pk));
            logicka = true;
        }
       
    }
    
    UnistiMatricu(c);
    UnistiMatricu(pom);
     return b;*/
     
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    auto jedinicna(StvoriMatricu<TipElemenata>(m1.br_kolona, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            if(i==j) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=0;
    
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=jedinicna.elementi[i][j];
            
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++){
            m3.elementi[i][j] *= *pk;
            }
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            jedinicna.elementi[i][j]=m1.elementi[i][j];
            
    auto jedinicna2(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++){
            jedinicna2.elementi[i][j]=jedinicna.elementi[i][j];
        }
    
    int k=1;
    while (k<n) {
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++){
                m3.elementi[i][j]+=(jedinicna.elementi[i][j] * (*pk));
                }
        pk++;
        
        auto jedinicna3(ProduktMatrica(jedinicna, jedinicna2));
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                jedinicna.elementi[i][j]= jedinicna3.elementi[i][j];
                UnistiMatricu(jedinicna3);
        k++;
    }
    UnistiMatricu(jedinicna);
    UnistiMatricu(jedinicna2);
    return m3;
}



int main ()
{
    std::cout << "Unesite dimenziju kvadratne matrice: " ;
    int n;
    std::cin >> n;
    try{
        auto a(StvoriMatricu<double>(n,n));
        std::cout << "Unesite elementi matrice A: " << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: " ;
        int red;
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: " ;
        std::vector<double>koeficijenti;
        for(int i=0; i<=red; i++){
            int broj;
            std::cin >> broj;
            koeficijenti.push_back(broj);
            
        }
        auto pok(koeficijenti.begin());
       
        IspisiMatricu(MatricniPolinom(a,red, pok),10,6,true);
        UnistiMatricu(a);
    }
    catch(...){
        std::cout << "Greska" << std::endl;
    }
	return 0;
}
