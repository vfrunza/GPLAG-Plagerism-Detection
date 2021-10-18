/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <new>
#include <iomanip>
#include <stdexcept>
#include <vector>
template <typename NekiTip>
struct Matrica{      //Kreiramo strukturu Matrice
    int br_redova, br_kolona;
    NekiTip **elementi=nullptr;
};
template <typename NekiTip>
void UnistiMatricu(Matrica<NekiTip> Mat){
    if(!Mat.elementi) return;
    for(int i=0; i<Mat.br_redova; i++)
    delete [] Mat.elementi[i];
    delete [] Mat.elementi;
    Mat.elementi=nullptr;
}
template <typename NekiTip>
Matrica<NekiTip> StvoriMatricu(int m, int n){
    Matrica<NekiTip> Mat;
    Mat.br_redova = m;
    Mat.br_kolona = n;
    Mat.elementi= new NekiTip*[m];
    for(int i=0; i<m; i++) 
    Mat.elementi[i]= nullptr;
    try{
        for(int i=0; i<m; i++)
        Mat.elementi[i]= new NekiTip[n];
        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++){
            Mat.elementi[i][j]=0;
        }
        
    }
    catch(...){
        UnistiMatricu(Mat); 
        throw;
    }
    return Mat;
}
template <typename NekiTip>
void UnesiMatricu(char ime_matrice, Matrica<NekiTip> &Mat){
    for(int i=0; i<Mat.br_redova; i++)
        for(int j=0; j<Mat.br_kolona; j++){
        std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
        std::cin>>Mat.elementi[i][j];
    }
}
template <typename NekiTip>
Matrica<NekiTip> NapraviKopiju(Matrica<NekiTip> Mat){
  Matrica<NekiTip> copy;
  copy.br_redova=Mat.br_redova;
  copy.br_kolona=Mat.br_kolona;
  copy.elementi=new NekiTip*[copy.br_redova];
  for(int i=0; i<copy.br_redova; i++)
  copy.elementi[i]=new NekiTip [copy.br_kolona];
  for(int i=0; i<copy.br_redova; i++)
  for(int j=0; j<copy.br_kolona; j++)
  copy.elementi[i][j]=Mat.elementi[i][j];
  return copy;
}
template <typename NekiTip>
void PKopija(Matrica<NekiTip> &m2, Matrica<NekiTip> m1){   //"Plitka kopija" matrice m2 u m1
    UnistiMatricu(m2);
    m2=NapraviKopiju(m1);
}
template<typename NekiTip>
Matrica<NekiTip> Saberi(Matrica<NekiTip> &a, Matrica<NekiTip> &b){ 
    if(a.br_redova!=b.br_redova || a.br_kolona!=b.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto suma(StvoriMatricu<NekiTip>(a.br_kolona, a.br_redova));
    for(int i=0; i<suma.br_redova; i++)
    for(int j=0; j<suma.br_kolona; j++)
    suma.elementi[i][j]=a.elementi[i][j]+b.elementi[i][j];
    return suma;
}
template <typename NekiTip>
Matrica<NekiTip> PomnoziSkalarom(Matrica<NekiTip> a, double n){
    Matrica<NekiTip> produkt=NapraviKopiju(a);
    for(int i=0; i<a.br_redova; i++)
    for(int j=0; j<a.br_kolona; j++)
    produkt.elementi[i][j]=n*a.elementi[i][j];
    return produkt;
}
template <typename NekiTip>
Matrica<NekiTip> ProduktMatrica(Matrica<NekiTip> a, Matrica<NekiTip> b){
    if(a.br_redova!=b.br_kolona) throw std::domain_error ("Matrice nisu saglasne za mnozenje!");
    auto  c (StvoriMatricu<NekiTip>(a.br_redova,b.br_kolona)); 
    for(int i=0; i<c.br_redova; i++){
        for(int j=0; j<c.br_kolona; j++){
            for(int k=0; k<c.br_redova; k++)
            c.elementi[i][j]+=a.elementi[i][k]*b.elementi[k][j];
        }
    }
    return c;
}
template<typename NekiTip>
Matrica<NekiTip> Stepenuj(const Matrica<NekiTip> &a, int stepen){  
    Matrica<NekiTip> c=NapraviKopiju(a);
    if(stepen>=2){
        for(int i=1; i<stepen; i++)
        PKopija(c, ProduktMatrica(c,a));
        return c;
    }
    if(stepen==1) {return c;}
    if(stepen==0) { 
        for(int i=0; i<c.br_redova; i++)
        for(int j=0; j<c.br_kolona; j++){
            if(i==j) c.elementi[i][j]=1;
            else c.elementi[i][j]=0;
        }
        return c;
    }
}
template<typename NekiTip>
Matrica<NekiTip> MatricniPolinom(Matrica<NekiTip> mat, std::vector<double> v){
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error ("Matrica nije kvadratna!");
    auto sum (StvoriMatricu<NekiTip>(mat.br_redova, mat.br_kolona));
    for(int i=0; i<v.size(); i++){
       Matrica<NekiTip> d=Stepenuj(mat,i);
       Matrica<NekiTip> e=PomnoziSkalarom(d,v[i]);
       PKopija(sum, Saberi(sum,e));
       UnistiMatricu(d);
       UnistiMatricu(e);
    }
    return sum;
}
template<typename NekiTip>
void IspisiMatricu(const Matrica<NekiTip> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false ){
    for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
int main ()
{
    Matrica<double> a,b; //Incijalizacija matrica;
    int m,n,x;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::vector<double> v1(n+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<v1.size(); i++)
        {std::cin>>x;
        v1[i]=x;}
        IspisiMatricu(b=MatricniPolinom(a,v1),10, 7, true);
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
	return 0;
}







