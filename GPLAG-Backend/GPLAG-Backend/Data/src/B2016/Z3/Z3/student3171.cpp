/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElemenata>
struct Matrica {
  int br_redova, br_kolona;
  TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    try{
    mat.elementi= new TipElemenata*[br_redova]; 
    }
    catch(...)
    {
        delete[] mat.elementi;
        mat.elementi=nullptr;
        throw;
    }

    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
    } 
    catch(...)
    {
        UnistiMatricu(mat);
        throw;
    }
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) mat.elementi[i][j]=0;
    }
    
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1<<"," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) 
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata>&m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova;i++ ) {
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+ m2.elementi[i][j];
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica( Matrica<TipElemenata> m1,Matrica<TipElemenata> m2)
{
    if( m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            double suma(0);
            for(int k=0; k<m2.br_redova; k++) suma=suma+m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata>MatricniPolinom(const Matrica<TipElemenata> &mat, std::vector<double> koeficijenti)
{
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto m(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    if(koeficijenti.size()==0) return m;
    
    auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            if(i==j) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=0;
        }
    }
    auto proizvod(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) proizvod.elementi[i][j]=mat.elementi[i][j];
    }
    
    for(int i=0; i<=koeficijenti.size(); i++){
        
        if(i==0) {
            for(int j=0; j<mat.br_redova; j++) {
                for(int k=0; k<mat.br_kolona; k++) m.elementi[j][k]=koeficijenti[0]*jedinicna.elementi[j][k];
            }
        }
        
        if(i==1) {
            auto pr(ProduktMatrica(proizvod, mat));
            for(int j=0; j<mat.br_redova; j++) {
                for(int k=0; k<mat.br_kolona; k++) pr.elementi[j][k]=koeficijenti[1]*proizvod.elementi[j][k];
            }
            for(int j=0; j<mat.br_redova; j++) {
                for(int k=0; k<mat.br_kolona; k++) m.elementi[j][k]+=pr.elementi[j][k];
            }
            UnistiMatricu(pr);
        }
        
        else {
            auto pr(ProduktMatrica(proizvod, mat));
            for(int j=0; j<mat.br_redova; j++) {
                for(int k=0; k<mat.br_redova; k++) pr.elementi[j][k]=koeficijenti[i]*proizvod.elementi[j][k];
            }
            for(int j=0; j<mat.br_redova; j++) {
                for(int k=0; k<mat.br_kolona; k++) m.elementi[j][k]+=pr.elementi[j][k];
            }
            for(int j=0; j<proizvod.br_redova; j++) {
                for(int k=0; k<mat.br_kolona; k++) {
                    double suma(0);
                    for(int l=0; l<mat.br_redova; l++) {suma+=proizvod.elementi[j][l]*mat.elementi[l][k];}
                    proizvod.elementi[j][k]=suma;
                }
            }
            UnistiMatricu(pr); 
        }
        
    }
    UnistiMatricu(jedinicna); UnistiMatricu(proizvod);
    return m;
}


int main ()
{
    Matrica<double> a;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try{
        a=StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu<double>('A', a);
        std::cout << "Unesite red polinoma: ";
        int n;
        std::cin >> n;
        std::vector<double>v;
        double broj;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i=0; i<=n; i++) {
            std::cin >> broj;
            v.push_back(broj);
        }
        Matrica<double> mat(StvoriMatricu<double>(m,m));
         mat=MatricniPolinom<double>(a, v);
        IspisiMatricu(mat, 10, 6);
        UnistiMatricu(mat); UnistiMatricu(a);
        
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch(std::domain_error tekst)
    {
        std::cout << tekst.what() << std::endl;
    }
	return 0;
}