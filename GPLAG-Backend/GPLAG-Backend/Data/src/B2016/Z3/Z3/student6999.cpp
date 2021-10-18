#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template <typename lopata>
struct Matrica{
    int br_redova,br_kolona;
    lopata **elementi = nullptr;
};
template <typename lopata>
void UnistiMatricu(Matrica<lopata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename lopata>
Matrica<lopata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<lopata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi  = new lopata*[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i] = nullptr;
    try{
        for(int i=0;i<br_redova;i++)
            mat.elementi[i] = new lopata[br_kolona];
        
    }catch(...){UnistiMatricu(mat);throw;}
return mat;
}
template <typename lopata>
void UnesiMatricu(char ime_matrice, Matrica<lopata> &mat){
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}
template <typename lopata>
void IspisiMatricu(const Matrica<lopata> mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
        std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename lopata>
Matrica<lopata> ZbirMatrica(const Matrica<lopata> &m1, const Matrica<lopata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)throw std::domain_error("Matrice nemaju jednake dimenzije!");
auto m3(StvoriMatricu<lopata>(m1.br_redova,m1.br_kolona));
for(int i=0;i<m1.br_redova;i++)
    for(int j=0;j<m1.br_kolona;j++){
        m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    }
    return m3;
}
template <typename lopata>
Matrica<lopata> ProduktMatrica(const Matrica<lopata> &m1,const Matrica<lopata> &m2);
template <typename lopata>
Matrica<lopata> MatricniPolinom(const Matrica<lopata> &metrice_hehe,const std::vector<double> &peovi);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main (){
Matrica<double> a; int m;
std::cout<<"Unesite dimenziju kvadratne matrice: ";    
std::cin>>m;
try{
   a=StvoriMatricu<double>(m,m);
    std::cout<<"Unesite elemente matrice A: \n"; UnesiMatricu('A',a);
    std::cout<<"Unesite red polinoma: "; unsigned red; std::cin>>red;
    std::vector<double> vektory; double temp;
    std::cout<<"Unesite koeficijente polinoma: ";
    for(unsigned i=0;i<red+1;i++) {std::cin>>temp; vektory.push_back(temp);}
    auto polinom=MatricniPolinom(a,vektory);
    IspisiMatricu(polinom,10,6);UnistiMatricu(polinom);
}catch(std::bad_alloc){std::cout<<"Nema dovoljno memorije!\n";}
catch(std::domain_error &ex){std::cout<<ex.what();}
catch(std::logic_error &ex){std::cout<<ex.what();}
UnistiMatricu(a);
return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename lopata>
Matrica<lopata> ProduktMatrica(const Matrica<lopata> &m1,const Matrica<lopata> &m2){
if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
try{
    auto izlazna = StvoriMatricu<lopata>(m1.br_redova,m2.br_kolona);UnistiMatricu(izlazna);}catch(std::bad_alloc){throw;}
auto izlazna = StvoriMatricu<lopata>(m1.br_redova,m2.br_kolona);
for(unsigned i=0;i<izlazna.br_redova;i++){
    for(unsigned j=0;j<izlazna.br_kolona;j++){
        lopata suma{};
        for(int k=0;k<m1.br_kolona;k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
        izlazna.elementi[i][j]=suma;
    }
}
return izlazna;
}
template<typename lopata>
void SkalarniProdukt(Matrica<lopata>&m, double skalar){
    for(unsigned i=0;i<m.br_redova;i++)
    for(unsigned j=0;j<m.br_kolona;j++)
        m.elementi[i][j]*=skalar;
}
template<typename lopata>
void KopirajDruguUPrvu(Matrica<lopata> m1,const Matrica<lopata> &m2){
    for(unsigned i=0;i<m1.br_redova;i++)
    for(unsigned j=0;j<m2.br_kolona;j++)
        m1.elementi[i][j]=m2.elementi[i][j];
}
template <typename lopata>
Matrica<lopata> MatricniPolinom(const Matrica<lopata> &mat,const std::vector<double> &peovi){
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
if(!peovi.size()){
    for(unsigned i=0;i<mat.br_redova;i++)
    for(unsigned j=0;j<mat.br_kolona;j++)
        mat.elementi[i][j]=0;
return mat;
}
    Matrica<lopata> priv1,priv2,polinom,stepen;
try{
 priv1=StvoriMatricu<lopata>(mat.br_redova,mat.br_kolona);
 polinom=StvoriMatricu<lopata>(mat.br_redova,mat.br_kolona);  
 stepen=StvoriMatricu<lopata>(mat.br_redova,mat.br_kolona);
KopirajDruguUPrvu(stepen,mat);
KopirajDruguUPrvu(priv1,mat);
for(unsigned i=0;i<polinom.br_redova;i++)
for(unsigned j=0;j<polinom.br_kolona;j++)
    if(j==i) polinom.elementi[i][j]= peovi[0];
    else polinom.elementi[i][j] = 0;
for(unsigned n=1;n<peovi.size();n++){
    SkalarniProdukt(priv1,peovi[n]);
    priv2=ZbirMatrica(polinom,priv1);
    //sad ima n-ti stepen
    KopirajDruguUPrvu(polinom,priv2);
    //sad ima polinom dignut na odg. stepen
    UnistiMatricu(priv2);
    priv2=ProduktMatrica(stepen,mat);
    KopirajDruguUPrvu(stepen,priv2);
    UnistiMatricu(priv2);
    KopirajDruguUPrvu(priv1,stepen);
}
    UnistiMatricu(priv1);UnistiMatricu(stepen);
return polinom;
}catch(std::bad_alloc){UnistiMatricu(priv1);UnistiMatricu(stepen);UnistiMatricu(polinom);throw;}
}