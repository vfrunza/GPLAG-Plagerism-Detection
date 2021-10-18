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
     //   for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova; mat.br_kolona=br_kolona;
        mat.elementi= new TipElemenata* [br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
        try{
            for(int i=0; i<br_redova; i++)
                mat.elementi[i]=new TipElemenata[br_kolona];
                
            for(int i=0; i<br_redova; i++){
                for(int j=0; j<br_kolona; j++){
                    mat.elementi[i][j]=0;
                }
            }
        }
        catch(...){
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }

template<typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata>&mat){
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++){
                std::cout << ime_matrice
                << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
        }
    }

template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++){
                std::cout << std::setprecision(preciznost)<< std::setw(sirina_ispisa) << mat.elementi[i][j];
            }
            std::cout  << std::endl;
        }
        
        if(treba_brisati==true){
            UnistiMatricu(mat);
        }
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1,
    const Matrica<TipElemenata> &m2){
        if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error("Matrica nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
    }

template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        
        if(m1.br_kolona!=m2.br_redova){
            throw std::domain_error("Matrice nisu saglasne za mnozenje!");
        }
        
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i=0; i<m1.br_redova; i++){
            for(int j=0; j<m2.br_kolona; j++){
                TipElemenata suma(0);
                for(int k=0; k<m1.br_redova; k++){
                    suma+=m1.elementi[i][k]*m2.elementi[k][j];
                }
                m3.elementi[i][j]=suma;
            }
        }
        return m3;
    }
    
template<typename TipElemenata>
Matrica<TipElemenata> MnozenjeSaKoeficijentom(Matrica<TipElemenata>mat, int p){
    
    Matrica<TipElemenata>povratna;
    povratna=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
    
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            povratna.elementi[i][j]=p*mat.elementi[i][j];
        }
    }
    
    return povratna;
    
}
    
template <typename TipElemenata, typename Tip>
    Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> mat, int n, Tip pok){
        
        if(n<1){
            throw std::domain_error ("Neispravan stepen polinoma");
        }
        
        if(mat.br_redova!=mat.br_kolona){
            throw std::domain_error ("Matrica mora biti kvadratna");
        }
        
        Matrica<TipElemenata>povratna;
        povratna=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
        
        
        Matrica<TipElemenata>pomocna;
        pomocna=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
        
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++){
                mat.elementi[i][j]=0;
            }
        }
        
        for(int i=0; i<mat.br_redova;i++){
            povratna.elementi[i][i]=*pok;
        }
        
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++){
                pomocna.elementi[i][j]=mat.elementi[i][j];
            }
        }
        
        Matrica<TipElemenata>novamat;
       
        
        for(int i=1; i<n; i++){
            
            pok++;
            if(i==1){
               // pok++;
                novamat=MnozenjeSaKoeficijentom(pomocna,*pok);
                auto b(ZbirMatrica(povratna,novamat));
                UnistiMatricu<TipElemenata>(povratna);
                povratna=b;
            }
            
            if(i>1){
                //pok++;
                auto b(ProduktMatrica(mat,pomocna));
                auto c(MnozenjeSaKoeficijentom(b,*pok));
                auto d(ZbirMatrica(povratna,c));
                UnistiMatricu<TipElemenata>(povratna);
                povratna=d;
                UnistiMatricu<TipElemenata>(mat);
                mat=b;
                UnistiMatricu<TipElemenata>(c);
            }
            
        }
        
        UnistiMatricu<TipElemenata>(mat);
        UnistiMatricu<TipElemenata>(novamat);
        UnistiMatricu<TipElemenata>(pomocna);
        
        return povratna;
        
    }

int main ()
{
    Matrica<double> a, mat;
    int m, n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try{
        a=StvoriMatricu<double>(m,m);
        std::cout << "Unesite elemente matrice A:\n" ;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double>koeficijenti(n);
        for(int i=0; i<n; i++){
            std::cin >> koeficijenti[i];
        }
        mat=MatricniPolinom<double>(a,n,koeficijenti.begin());
        IspisiMatricu<double>(mat,10,6,true);
        UnistiMatricu(a);
        UnistiMatricu(mat);
        
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what();
    }
    
    catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!\n";
    }
    
	return 0;
}
