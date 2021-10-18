/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata>mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata>StvoriMatricu(int br_redova, int br_kolona) {
    Matrica <TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi= new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
        mat.elementi[i]= new TipElemenata[br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica <TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++)
    for(int j=0; j<mat.br_kolona; j++) {
        std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
        std::cin >> mat.elementi[i][j];
    }
}

template <typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
        std::cout << std::setw (sirina_ispisa) << mat.elementi[i][j] << std::setprecision(preciznost);
        std::cout << std::endl;
    }
    if(treba_brisati)UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica < TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!= m2.br_kolona)
    throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3 (StvoriMatricu <TipElemenata> (m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1. br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++)
    m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica <TipElemenata> ProduktMatrica (const Matrica <TipElemenata>&m1, const Matrica<TipElemenata>&m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3 (StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            double suma=0;
            for(int k=0; k<m2.br_redova; k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template <typename TipElemenata, typename Tip2>
Matrica<TipElemenata> Pomnozi(Matrica<TipElemenata>&m ,Tip2 alfa){
    auto rez(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i=0; i<rez.br_redova; i++)
        for(int j=0; j<rez.br_kolona;j++)
            rez.elementi[i][j]=m.elementi[i][j]*alfa;
    return rez;
}
template< typename TipElemenata>
void KopirajMatricu(Matrica<TipElemenata> &m1,Matrica <TipElemenata> &m2){
    
    for(int i=0; i<m1.br_redova;i++)
        for(int j=0; j<m1.br_kolona;j++)
            m1.elementi[i][j]=m2.elementi[i][j];
}
template <typename TipElemenata, typename Tip1>
Matrica<TipElemenata> MatricniPolinom( const Matrica <TipElemenata>&m1, int n,Tip1 it){
    
    Matrica<TipElemenata> mat(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    Matrica<TipElemenata> pomocna(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    
    Matrica<TipElemenata> pomocna1;
    Matrica<TipElemenata> pomocna2;
    for(int i=0; i<m1.br_kolona;i++)
        for(int j=0; j<m1.br_kolona;j++)
            pomocna.elementi[i][j]=m1.elementi[i][j];
            
    
    if(n<0) throw std::domain_error ("Neispravan stepen polinoma");
    if(m1.br_kolona!= m1.br_redova) throw std:: domain_error ("Matrica mora biti kvadratna");
   
   
    for(int i=0; i<=n;i++){
        if(i==0){
            for(int j=0; j<m1.br_kolona;j++)
                for(int k=0; k<m1.br_kolona;k++)
                    if(j==k)mat.elementi[j][k]=*it;
                    else mat.elementi[j][k]=0;
        }else if(i==1){
            //UnistiMatricu(pomocna1);
            pomocna1=Pomnozi(pomocna,*it);
            
            //UnistiMatricu(pomocna2);
            pomocna2=ZbirMatrica(mat,pomocna1);
            KopirajMatricu(mat,pomocna2);
            UnistiMatricu(pomocna2);
            
            UnistiMatricu(pomocna1);
        }else{
            
           // UnistiMatricu(pomocna2);
            pomocna2=ProduktMatrica(pomocna,m1);
           // UnistiMatricu(pomocna);
            KopirajMatricu(pomocna,pomocna2);
            UnistiMatricu(pomocna2);
            //UnistiMatricu(pomocna1);
            
            pomocna1=Pomnozi(pomocna,*it);
            pomocna2=ZbirMatrica(mat,pomocna1);
            UnistiMatricu(pomocna1);
            KopirajMatricu(mat,pomocna2);
            
            UnistiMatricu(pomocna2);
        }
        it++;
        if(n+1<0)break;
    }
    
   // UnistiMatricu(pomocna1);
    UnistiMatricu(pomocna);
    return mat;
}


int main () {
    Matrica<double> a;
    std::vector<double> vektor;
    
    int n, stepen_polinoma;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >>n;
    std::cout << "Unesite elemente matrice A:\n";
    try {
        a=StvoriMatricu<double>(n,n);
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> stepen_polinoma;
        std::cout << "Unesite koeficijente polinoma: ";
        int ta;
        
        for(int i=0; i<=stepen_polinoma;i++){
            
            std::cin>>ta;
            vektor.push_back(ta);
        }
        auto o=MatricniPolinom(a,stepen_polinoma,vektor.begin());
        IspisiMatricu(o,10,6,true);
 
    }catch(...){}
    UnistiMatricu(a);
	return 0;
}
