#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata** elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat) {
    if(!mat.elementi) return;
    for ( int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for ( int i = 0 ; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0 ; i < br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata>&mat) {
    for (int i = 0 ; i < mat.br_redova; i++) {
        for ( int j = 0 ; j < mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
Matrica<TipElemenata>ZbirMatrica(const Matrica<TipElemenata>&m1,const Matrica<TipElemenata>&m2 ) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for ( int i = 0 ; i < m1.br_redova; i++) {
        for ( int j = 0; j < m1.br_kolona; j++) m3.elementi[i][j] = m1.elementi[i][j]+m2.elementi[i][j];
    }   
    return m3;
}


       template <typename TipElemenata>
        Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2){
            if ( m1.br_kolona != m2.br_redova ) throw std::domain_error("Matrice nisu saglasne za množenje");
            auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
            NulMatrica(m3);
            for ( int i = 0; i < m1.br_redova; i++ ) 
                for ( int j = 0; j < m2.br_kolona; j++ ) 
                    for ( int k = 0 ; k < m1.br_kolona; k++) m3.elementi[i][j]+= m1.elementi[i][k]*m2.elementi[k][j];
                return m3;    
            }
            
            template<typename TipElemenata>
            void NulMatrica(Matrica<TipElemenata>matrica) {
                for ( int i = 0 ; i < matrica.br_redova; i++) 
                    for ( int j = 0; j < matrica.br_kolona; j++ ) matrica.elementi[i][j]=0;
            }
            
            template<typename TipElemenata>
           Matrica<TipElemenata> SkalarSMatricom(double a, const Matrica<TipElemenata>&m1) {
                 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
                 for ( int i = 0; i < m1.br_redova; i++ ) {
                     for ( int j = 0; j < m1.br_kolona; j++ ) m3.elementi[i][j]=m1.elementi[i][j]*a;
                 }
                 return m3;
             }
            
            
            template <typename TipElemenata>
            Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata>&m1, const std::vector<double> &v1) {
                if ( m1.br_redova != m1.br_kolona ) throw std::domain_error("Matrica mora biti kvadratna");
                        Matrica<TipElemenata> MatPolinom;
                        
              try {
                     MatPolinom = StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
                auto m2(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
                NulMatrica(m2); 

                if ( v1.size() == 0 )    return m2;
                NulMatrica(MatPolinom);
                for ( int i = 0; i < m2.br_redova; i++ ) {
                    for( int j = 0; j < m2.br_kolona; j++ ) if ( i == j ) m2.elementi[i][j] = 1;
                }
                    
                    for(int i = 0; i < v1.size(); i++){
                        if( i==0 ) {
                             auto pomocni(MatPolinom);
                             auto skalarna(SkalarSMatricom(v1[i],m2));
                            MatPolinom = ZbirMatrica(MatPolinom, skalarna);
                            UnistiMatricu(pomocni);
                            UnistiMatricu(skalarna);
                            continue;
                        }
                        else if ( i==1 ) {
                             auto pomocni(MatPolinom);     
                             auto skalarna(SkalarSMatricom(v1[i],m1));
                            MatPolinom = ZbirMatrica(MatPolinom,skalarna);
                            UnistiMatricu(pomocni);
                            UnistiMatricu(skalarna);
                            continue;
                         }
                         auto produktna(ProduktMatrica(m2,m1));
                         for ( int j = 1; j < i ; j++ ) {
                               auto help2(produktna);
                               produktna = ProduktMatrica(produktna,m1);
                               UnistiMatricu(help2);
                         }
                         auto pomocni(MatPolinom);
                         auto skalarna(SkalarSMatricom(v1[i],produktna));
                            MatPolinom = ZbirMatrica(MatPolinom,skalarna);
                            UnistiMatricu(pomocni);
                            UnistiMatricu(skalarna);
                            UnistiMatricu(produktna);
                         
                }
                            UnistiMatricu(m2);
              }
              catch(...) {
                  throw;
              }
                
                return MatPolinom;
                
            }
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false){

    for(int i = 0; i < mat.br_redova; i++) {
        for ( int j=0; j <mat.br_kolona; j++) std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
         if ( treba_brisati == true ) UnistiMatricu(mat);

}

int main ()
{
    Matrica<double> a,b;
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try {
        a = StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int r;
        std::cin>>r;
        std::vector<double>v;
        std::cout<<"Unesite koeficijente polinoma: ";
        for ( int i = 0; i < r+1; i++ ) {
            double lol;
            std::cin>>lol;
            v.push_back(lol);
        }
        b = MatricniPolinom(a,v);
        IspisiMatricu(b,10);
    }
    catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
        UnistiMatricu(a);
        UnistiMatricu(b);
	return 0;
}