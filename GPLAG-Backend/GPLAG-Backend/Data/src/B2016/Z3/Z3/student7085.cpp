/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <vector>


template <typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> mat){
    if(!mat.elementi)return;
    for(int i=0;i<mat.br_redova;i++)delete[] mat.elementi[i];
    delete[]mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    //if(br_kolona==0)br_kolona=br_redova;
    Matrica<TipElemenata>mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata* [br_redova];
    for(int i=0;i<br_redova;i++)
    mat.elementi[i]= nullptr;
    try{
        for(int i=0;i<br_redova;i++)
        mat.elementi[i]= new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}


template <typename TipElemenata> 
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){ 
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice<< "("<<i+1<<","<< j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template< typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<std::right<<mat.elementi[i][j];
        std::cout<<std::endl;
        
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica <TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
    for(int j=0;j<m1.br_kolona;j++)
    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona!=m2.br_redova)
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
     for(int i=0;i<m1.br_redova;i++)
     for(int j=0;j<m2.br_kolona;j++)
      m3.elementi[i][j]=0;
    for(int i=0;i<m1.br_redova;i++)
    for(int j=0;j<m2.br_kolona;j++)
    for(int k=0;k<m1.br_kolona;k++)
    m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
    return m3;
}

std::vector<double> KoeficijentiPolinoma(int n){
    std:: vector<double> v;
    for(int i=0;i<n+1;i++){
        double x;
        std::cin>>x;
        v.push_back(x);
    }
    return v;
}

template<typename TipElemenata, typename T>
Matrica<TipElemenata> PomnoziSaSkalarom( Matrica<TipElemenata> m1, T skalar){
    Matrica<TipElemenata> c=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    for(int i=0;i<m1.br_redova;i++){
    for(int j=0;j<m1.br_kolona;j++)
    c.elementi[i][j]=skalar*(m1.elementi[i][j]);
    }
    
    return c;
}


template<typename TipElemenata, typename T>
void JedinicnaSaPrvimIzVektora(const Matrica<TipElemenata> &m, T n){
    for(int i=0;i<m.br_redova;i++)
     for(int j=0;j<m.br_kolona;j++)
     if(i==j)
     m.elementi[i][j]=n;
     else if(i!=j)
     m.elementi[i][j]=0; 
     
     
     
     
}

template<typename TipElemenata, typename T>
void PravljenjeZaKeca( Matrica<TipElemenata> a, Matrica<TipElemenata>&e, T n){
    auto pom=PomnoziSaSkalarom(a,n);
    auto e1=ZbirMatrica(e,pom);
    UnistiMatricu(pom);
    UnistiMatricu(e);
    e=StvoriMatricu<TipElemenata>(e1.br_redova ,e1.br_kolona);
    for(int i=0;i<e1.br_redova;i++)
    for(int j=0;j<e1.br_kolona;j++)
    e.elementi[i][j]=e1.elementi[i][j];
    UnistiMatricu(e1);
    
   
}

template<typename TipElemenata, typename T>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<T>v){
     if(m.br_redova!=m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
     Matrica<TipElemenata> a=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
     for(int i=0;i<m.br_redova;i++)
     for(int j=0;j<m.br_kolona;j++)
     a.elementi[i][j]=m.elementi[i][j];  //ovde a
     Matrica<TipElemenata> e=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);  //ovde e
     JedinicnaSaPrvimIzVektora(e,v[0]); //ovde
     for(int i=1;i<v.size();i++){
         if(i==1){
            
             PravljenjeZaKeca(a,e,v[i]); //ovde
             
         }
         else{
             auto pom=ProduktMatrica(a,m);  //ovde
             auto pom1=PomnoziSaSkalarom(pom,v[i]); //ovde
             auto e1=ZbirMatrica(e,pom1); //ovde
             UnistiMatricu(a);
             a=StvoriMatricu<TipElemenata>(e.br_redova,e.br_kolona);
             for(int i=0;i<e.br_redova;i++)
             for(int j=0;j<e.br_kolona;j++)
             a.elementi[i][j]=pom.elementi[i][j];
             UnistiMatricu(pom);
             UnistiMatricu(e);
             e=StvoriMatricu<TipElemenata>(e1.br_redova,e1.br_kolona);
             for(int i=0;i<e1.br_redova;i++)
             for(int j=0;j<e1.br_kolona;j++)
             e.elementi[i][j]=e1.elementi[i][j];
             UnistiMatricu(e1);
             UnistiMatricu(pom1);
         }
     }
     UnistiMatricu(a);
     return e;
}



int main ()
{
 
    Matrica<double> a,b,c;
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a=StvoriMatricu<double>(m,m);
        //b=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A: ";
        std::cout<<std::endl;
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int red_polinoma;
        std::cin>>red_polinoma;
       // std::vector<double>v;
        //v.resize(red_polinoma+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        /*for(int i=0;i<red_polinoma+1;i++)
        std::cin>>v[i];*/
        std::vector<double>v(KoeficijentiPolinoma(red_polinoma));
        auto c=MatricniPolinom<double>(a,v);
        IspisiMatricu(c,10);
        UnistiMatricu(c);
        UnistiMatricu(a);
        
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    catch(...){
        std::cout<<"Nema dovoljno memorije!\n";
    }
     	return 0;
}