/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>


using std::cout;
using std::cin;
using std::endl;

template <typename TipElemenata>   
    struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;    // VEOMA BITNA INICIJALIZACIJA!
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
    mat.elementi = new TipElemenata*[br_redova]{}; // izmjena 1: {} da ne bismo pisali for-petlju za nullptr
   

    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona]{}; //izmjena 2: {} za podrazumijevanu vrijednost TipElemenata ???

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
            std::cout << ime_matrice  << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];

        }

}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<< mat.elementi[i][j];
        std::cout << std::endl;
    }
    
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona)); 
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova)
    throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    
    for(int i=0;i<m1.br_redova;i++){
    for(int j=0;j<m2.br_kolona;j++){
        TipElemenata suma(0);
    for(int k=0;k<m2.br_redova;k++)
    suma+=m1.elementi[i][k]*m2.elementi[k][j];
    m3.elementi[i][j]=suma;
    }
    }
    
    return m3;
}

template <typename TipElemenata>
bool KvadratnaMatrica(const Matrica<TipElemenata> &m){
    return m.br_redova==m.br_kolona;
}

template<typename TipElemenata, typename RealanTip>
void PomnoziMatricuSkalarom (Matrica<TipElemenata> &m, RealanTip a){
    for(int i=0;i<m.br_redova;i++)
    for(int j=0;j<m.br_kolona;j++)
    m.elementi[i][j]=m.elementi[i][j]*a;
}

template <typename TipElemenata, typename IterTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, int n, IterTip p){
    
    if(n<0) throw std::domain_error ("Neispravan stepen polinoma");
    if(!KvadratnaMatrica(m)) throw std::domain_error ("Matrica mora biti kvadratna");
    
    int dimenzija(m.br_redova);
    
    auto Polinom(StvoriMatricu<TipElemenata>(dimenzija,dimenzija));
    
    
    
    for(int i=0;i<dimenzija;i++) Polinom.elementi[i][i]=1;
    
    PomnoziMatricuSkalarom(Polinom,*p);
    p++;
    
    
    auto c(StvoriMatricu<TipElemenata>(dimenzija,dimenzija));
    
    for(int i=0;i<dimenzija;i++)
    for(int j=0;j<dimenzija;j++)
    c.elementi[i][j]=m.elementi[i][j];
    
    for(int i=1;i<=n;i++){
  
        for(int k=0;k<dimenzija;k++)
    for(int l=0;l<dimenzija;l++)
    c.elementi[k][l]=m.elementi[k][l];
        

        for(int j=1;j<i;j++){
        
        Matrica<TipElemenata> kopija(c);
            c=ProduktMatrica(c,m);
            UnistiMatricu(kopija);
        }
        
    
        PomnoziMatricuSkalarom(c,*p);
 
        p++;

        Matrica<TipElemenata> kopija2(Polinom);
        Polinom=ZbirMatrica(Polinom,c);
        UnistiMatricu(kopija2);

    }
    

    UnistiMatricu(c);
    
    return Polinom;
}

int main()
{

    Matrica<double> a, Polinom;   // AUTOMATSKA INICIJALIZACIJA!!!
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    
    try {
        a = StvoriMatricu<double>(n, n);

        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        
        cout<<"Unesite red polinoma: ";
        int red_polinoma;
        cin>>red_polinoma;
        
        cout<<"Unesite koeficijente polinoma: ";
        
        std::vector<double> v;
        
        double koeficijent;
        
        for(int i=0;i<red_polinoma+1;i++){
            cin>>koeficijent;
            v.push_back(koeficijent);
            }
        
        
        Polinom=MatricniPolinom(a,red_polinoma,&v[0]);
        
        
        IspisiMatricu(Polinom,10);
  
        
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    
    UnistiMatricu(a);
    UnistiMatricu(Polinom);
    
    return 0;
}
