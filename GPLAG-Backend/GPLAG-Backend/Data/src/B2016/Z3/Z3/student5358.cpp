/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename TipElementa>
struct Matrica{
    int br_redova,br_kolona;
    TipElementa **elementi=nullptr;
};
template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa>mat){
    if(!mat.elementi)return;
    for(int i=0;i<mat.br_redova;i++)delete []mat.elementi[i];
    delete[]mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
 Matrica<TipElemenata> mat;
 mat.br_redova = br_redova; mat.br_kolona = br_kolona;
 //mat.elementi=nullptr;
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
template <typename TipElementa>
void UnesiMatricu(char ime_matrice,Matrica<TipElementa>&mat){
    for(int i=0;i<mat.br_redova;i++)
    for(int j=0;j<mat.br_kolona;j++){
        std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
        std::cin>>mat.elementi[i][j];
    }
}
template <typename TipElementa>
void IspisiMatricu(const Matrica<TipElementa>&mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati){
        UnistiMatricu(mat);
    }
}
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
    if(m1.br_redova==m2.br_kolona||m1.br_kolona==m2.br_redova) {
        Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i(0); i<m1.br_redova; i++)
            for(int j(0); j<m2.br_kolona; j++) {
                TipElemenata suma(0);
                for(int k(0); k<m2.br_redova; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
                m3.elementi[i][j]=suma;
            }
        return m3;
    } else throw std::domain_error("Matrice nisu saglasne za mnozenje");
}
template <typename TipElemenata>
void DubokoKopiranje(Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m1.br_kolona; j++) m1.elementi[i][j]=m2.elementi[i][j];
}
template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSaSkalarom(const Matrica<TipElemenata> &m, double k) {
    Matrica<TipElemenata> m1(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m1.br_kolona; j++) m1.elementi[i][j]=k*m.elementi[i][j];
    return m1;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A , std::vector<double>v) {
    //IspisiMatricu(A,9,5,true);
    if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");

    Matrica<TipElemenata> expA(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    Matrica<TipElemenata> m1(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    Matrica<TipElemenata> m2 ,m3 ,m4 ,m5;  // pomocne matrice

    for(int i(0); i<A.br_redova; i++) // kreiranje jedinicnih matrica
        for(int j(0); j<A.br_kolona; j++) {
            if(i==j) {
                m1.elementi[i][j]=1;
                expA.elementi[i][j]=1;
            } else {
                m1.elementi[i][j]=0;
                expA.elementi[i][j]=0;
            }
        }
       /* std::cout<<"jedincna:"<<std::endl;
        IspisiMatricu(m1,9,5);*/
        //expA=PomnoziSaSkalarom(m1,v[0]);
        DubokoKopiranje(expA,m5=PomnoziSaSkalarom(m1,v[0]));
        UnistiMatricu(m5);
    for(int i(1); i<v.size(); i++) {
        DubokoKopiranje(m1,m2=ProduktMatrica(m1,A));
        DubokoKopiranje(expA,m3=ZbirMatrica(expA,m4=PomnoziSaSkalarom(m1,v[i])));
        UnistiMatricu(m2);
        UnistiMatricu(m3);
        UnistiMatricu(m4);
        //UnistiMatricu(A);
    }
    //DubokoKopiranje(m1,m2=ProduktMatrica(m1,A));
    //m2=m1;
   /* m1=PomnoziSaSkalarom(m1,v[0]);
    for(int i=1;i<v.size();i++){
        auto m2=A;
        //std::cout<<"hrke"<<std::endl;
        //IspisiMatricu(m2,9,5);
        //std::cout<<"konjo"<<i<<std::endl;
        for(int j=i;j>1;j--){
            m2=ProduktMatrica(m2,A);
        }
        m2=PomnoziSaSkalarom(m2,v[i]);
        std::cout<<"nakon mnozenja"<<std::endl;
        IspisiMatricu(m2,9,5);
        m1=ZbirMatrica(m1,m2);
        UnistiMatricu(m2);
    }
    return m1;*/
    UnistiMatricu(m1);
    //UnistiMatricu(A);
    return expA;
}
int main ()
{
    Matrica<double> a, b, c,d; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 try {
        a = StvoriMatricu<double>(m, m);
        //b = StvoriMatricu<double>(m, n);
        std::cout << "Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A', a);
        //std::cout << "Unesi matricu B:\n";
        //UnesiMatricu('B', b);
        int n;
        std::cout << "Unesite red polinoma: ";
        
        std::cin >> n;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double>v(n+1);
        for(int i=0;i<=n;i++)
            std::cin>>v[i];
        //std::cout << "Zbir ove dvije matrice je:\n";
        //IspisiMatricu(c = ZbirMatrica(a, b), 7);
        //std::cout << std::endl << "Produkt ove dvije matrice: " << std::endl;
        //IspisiMatricu(d = ProduktMatrica(a,b),7,5);
        //std::cout << std::endl << "Matricni Eksponencijalni Polinom:" << std::endl;
        IspisiMatricu(MatricniPolinom(a,v),10,5,true);

    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!";
    }
    catch(std::domain_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    UnistiMatricu(a);
    /*UnistiMatricu(b);
    UnistiMatricu(c);*/
    //UnistiMatricu(d);
    //AT3 (c9) - funkcija MatricniPolinom
	return 0;
}