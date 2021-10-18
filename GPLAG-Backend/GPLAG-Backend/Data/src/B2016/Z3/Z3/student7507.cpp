/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cmath>

template<typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++){
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi= nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++){
            mat.elementi[i]=nullptr;
    }
    try{
        for(int i=0; i<br_redova; i++){
            mat.elementi[i]= new TipElemenata [br_kolona];
        }
    }
    catch(...){ //Ako ne uspije alokacija redova matrice
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
    }
    if(treba_brisati==true){
        UnistiMatricu(mat);
    }
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatirca(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipElemenata> a,m3;
    m3=(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m1.br_kolona; j++){
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    /*for(int i=0; i<m3.br_redova; i++){
         for(int j=0; j<m3.br_kolona; j++){
              std::cout<<m3.elementi[i][j]<<" ";
         }
         std::cout<<std::endl;
    }*/
    //UnistiMatricu(a);
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica( Matrica<TipElemenata> &m1,  Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> a,m3;
    m3=(StvoriMatricu<TipElemenata>(m1.br_redova,  m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m2.br_kolona; j++){
            m3.elementi[i][j]=0;
            for(int k=0; k<m2.br_redova; k++){
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    //UnistiMatricu(a);
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> SkalarniProizvod(Matrica<TipElemenata> mat, TipElemenata broj){
    Matrica<TipElemenata> a,m2;
    m2=(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            m2.elementi[i][j]=mat.elementi[i][j]*broj;
            //std::cout<<"mat= "<<m2.elementi[i][j]<<std::endl;
        }
    }
    //UnistiMatricu(a);
    return m2;
}
template<typename TipElemenata>
Matrica<TipElemenata> Stepenuj(Matrica<TipElemenata> m1, int stepen){
    Matrica<TipElemenata> a,b,m2;
    m2=(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++){
        for(int j=0; j<m1.br_redova; j++){
            if(i==j)m2.elementi[i][j]=1;
        }
    }
    for(int i=0; i<stepen; i++){
        m2=(a=ProduktMatrica(m2,m1));
        UnistiMatricu(a);
    }
    //UnistiMatricu(b);
    return m2;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> A, std::vector<double> v){
        int n=v.size();
        Matrica<TipElemenata> a,b,m3,polinom;
        m3=(a=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
        for(int i=0;i< A.br_redova; i++){
            for(int j=0; j<A.br_kolona; j++){
                if(i==j)m3.elementi[i][j]=1;
            }
        }
        if(v.size()==0) { // Prazan vektor, vraca nul-matricu
            for(int i=0; i<m3.br_redova; i++){
                for(int j=0; j<m3.br_kolona; j++){
                    m3.elementi[i][j]=0;
                }
            }
            return m3;
        }
        polinom=(b=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
       /* for(int i=0; i<A.br_redova; i++){
            for(int j=0; j<A.br_kolona; j++){
                if(i==j)polinom.elementi[i][j]=1;
            }
        }*/
        Matrica<TipElemenata> c,d,e,f,g;
        for(int k=0; k<n; k++){
            if(k==0){ // Jedinicna matrica,samo za k==0, specifican slucaj.
                m3=(e=SkalarniProizvod<TipElemenata>(m3,v[k]));
            }
            else {
                m3=(e=SkalarniProizvod<TipElemenata>(c=Stepenuj(A,k), v[k]));
            }
            polinom=(d=ZbirMatirca<TipElemenata>(polinom, m3));
            UnistiMatricu(a);UnistiMatricu(b); UnistiMatricu(c);UnistiMatricu(d); UnistiMatricu(e); /* UnistiMatricu(f); */
        }
    return polinom;
}
int main ()
{
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    std::cin>>dimenzija;
    Matrica<int> A,polinom,b,c,d;
    try{
        A=(StvoriMatricu<int>(dimenzija,dimenzija));
        try{
            polinom=(StvoriMatricu<int>(dimenzija,dimenzija));
            std::cout<<"Unesite elemente matrice A: \n";
            UnesiMatricu('A',A);
            std::cout<<"Unesite red polinoma: ";
            int n;
            std::cin>>n;
            std::cout<<"Unesite koeficijente polinoma: ";
            std::vector<double> v(n+1);
            for(int i=0; i<=n; i++){
                std::cin>>v[i];
            }
            try{
                polinom=(b=MatricniPolinom(A,v));
                IspisiMatricu(polinom,10,6,true);
                UnistiMatricu(A); UnistiMatricu(polinom); UnistiMatricu(b); 
            }
            catch(std::domain_error izuzetak){
                std::cout<<izuzetak.what();
                UnistiMatricu(A);  UnistiMatricu(b); 
            }
        }
        catch(std::bad_alloc){
            std::cout<<"Nema dovoljno memorije";
            UnistiMatricu(A); 
        }
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije";
        UnistiMatricu(A); UnistiMatricu(c);
    }
	return 0;
}