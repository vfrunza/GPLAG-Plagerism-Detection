/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
    struct Matrica{
        int br_redova,br_kolona;
        TipElemenata **elementi=nullptr;
    };
    
template <typename TipElemenata>
    void UnistiMatricu(Matrica <TipElemenata> mat){
        if(!mat.elementi) return;
        for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
        Matrica <TipElemenata> mat;
        mat.br_redova=br_redova; mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata*[br_redova];
        for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
        try{
            for(int i=0;i<br_redova;i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
        }
        catch(...){
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template <typename TipElemenata> 
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
        for(int i=0;i<mat.br_redova;i++)
            for(int j=0;j<mat.br_kolona;j++){
                std::cout<<ime_matrice
                << "(" << i+1 <<","<< j+1<< ") = ";
                std::cin>>mat.elementi[i][j];
            }
    }
    
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
        for(int i=0;i<mat.br_redova;i++){
          for(int j=0;j<mat.br_kolona;j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            std::cout<<std::endl;
        }
        if(treba_brisati==true) UnistiMatricu(mat);
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for(int i=0;i<m1.br_redova;i++)
          for(int j=0;j<m1.br_kolona;j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        return m3;
    }
    
template <typename TipElemenata>
    Matrica <TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
        for(int i=0;i<m1.br_redova;i++)
          for(int j=0;j<m2.br_kolona;j++){
            TipElemenata suma=0;
            for(int k=0;k<m2.br_redova;k++)
                suma=suma+m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
          }
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> koeficijenti){
        if(m.br_redova!=m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
        auto m1(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
        auto rez(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
        auto prvi(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
        auto c(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
        for(int i=0;i<m.br_redova;i++){
            for(int j=0;j<m.br_kolona;j++)
            rez.elementi[i][j]=0;
        }
        auto jedinicna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
        for(int i=0;i<m.br_redova;i++){
            for(int j=0;j<m.br_kolona;j++){
                if(i==j) jedinicna.elementi[i][j]=1;
                else jedinicna.elementi[i][j]=0;
            }
        }
        for(int i=0;i<m.br_redova;i++){                          //prvi sabirak polinoma
            for(int j=0;j<m.br_kolona;j++){
                prvi.elementi[i][j]=koeficijenti[0]*jedinicna.elementi[i][j];
            }
        }
        m1=jedinicna;
        for(int i=1;i<koeficijenti.size();i++){
            m1=ProduktMatrica(m1,m);
            for(int j=0;j<m1.br_redova;j++){
                for(int k=0;k<m1.br_kolona;k++){
                    c.elementi[j][k]=koeficijenti[i]*jedinicna.elementi[j][k];
                }
            }
            rez=ZbirMatrica(rez,c);
        }
        rez=ZbirMatrica(rez,prvi);
        return rez;
    }
    
int main ()
{   Matrica <double> a,b;
    std::vector<double> vektor;
    double k;
    int n,m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    try{
      a=StvoriMatricu<double>(n,n);
      b=StvoriMatricu<double>(n,n);
      std::cout<<"Unesite elemente matrice A: ";
      UnesiMatricu('A',a);
      std::cout<<"Unesite red polinoma: ";
      std::cin>>m;
      std::cout<<"Unesite koeficijente polinoma: ";
      for(int i=0;i<=m;i++) {
          std::cin>>k;
          vektor.push_back(k);
      }
      b=MatricniPolinom(a,vektor);
      IspisiMatricu(b,8);
      }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    
    UnistiMatricu(a); UnistiMatricu(b); 
	return 0;
}