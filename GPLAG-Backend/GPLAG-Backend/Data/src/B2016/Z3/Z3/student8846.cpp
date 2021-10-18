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
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++){
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try {
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
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++)
    for(int j=0;j<mat.br_kolona;j++){
        std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
        std::cin>>mat.elementi[i][j];
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6,bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
    for(int j=0;j<m1.br_kolona;j++)
    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m2.br_kolona;j++){
            m3.elementi[i][j]=0;
            for(int k=0;k<m1.br_kolona;k++){
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
               
            }
        }
    return m3;
}

/*template<typename TipElemenata>
Matrica<TipElemenata> MaticaPutaBroj(const Matrica<TipElemenata> m1, double d)
{
     auto m2(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i=0;i<m1.br_redova;i++)
     {
        for(int j=0;j<m1.br_kolona;j++)
        {
            m2.elementi[i][j]=m1.elementi[i][j]*d;
        }
     }
     return m2;
}
template<typename TipElemenata>
Matrica<TipElemenata> JedinicnaMatrica(int velicina)
{
    Matrica<TipElemenata> m= StvoriMatricu<TipElemenata>(velicina,velicina);
    for(int i=0;i<velicina;i++)
    {
        m.elementi[i][i]=1;
    }
    return m;
}
template<typename TipElemenata>
Matrica<TipElemenata> NulMatrica(int velicina)
{
    Matrica<TipElemenata> m= StvoriMatricu<TipElemenata>(velicina,velicina);
    for(int i=0;i<velicina;i++)
    {
        for(int j=0;j<velicina;j++)
        {
            m.elementi[i][j]=0;
        }
    }
    return m;
}
template<typename TipElemenata>
Matrica<TipElemenata> StepenMatrice(const Matrica<TipElemenata> m,int stepen)
{
    if(stepen==0) return JedinicnaMatrica<TipElemenata> (m.br_kolona);
    else
    {
    Matrica<TipElemenata> m2=m;
    Matrica<TipElemenata> pom;
    for(int i=0;i<stepen-1;i++)
    {
        pom=ProduktMatrica(m2,m);
        UnistiMatricu(m2);
        m2=pom;
        UnistiMatricu(pom);
    }
    return m2;
    }
}*/


template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> m1,std::vector<double> brojevi )
{
    if(m1.br_kolona!=m1.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
   try
    {
        Matrica<TipElemenata> mat=StvoriMatricu<TipElemenata> (m1.br_kolona,m1.br_kolona);
        for(int i=0;i<m1.br_kolona;i++) for(int j=0;j<m1.br_kolona;j++) mat.elementi[i][j]=0;
        if(brojevi.size()==0) return mat;
        else
        {
            for(int i=0;i<(int)brojevi.size();i++)
            {
                if(i==0)
                {
                    for(int j=0;j<mat.br_kolona;j++)
                    {
                        mat.elementi[j][j]=brojevi[i];
                    }
                }
                else
                {
                    Matrica<TipElemenata> pom2=StvoriMatricu<TipElemenata> (m1.br_kolona,m1.br_kolona);
                    for(int j=0;j<i-1;j++) //Stepenovanje
                    {
                        if(j==0) 
                        {
                            Matrica<TipElemenata> pom1=StvoriMatricu<TipElemenata> (m1.br_kolona,m1.br_kolona);
                            pom1=ProduktMatrica(m1,m1);
                          //  IspisiMatricu(pom1,4);
                            UnistiMatricu(pom2);
                            pom2=pom1;
                            UnistiMatricu(pom1);
                        }
                        else
                        {
                            //IspisiMatricu(pom2,6);
                             Matrica<TipElemenata> pom1=StvoriMatricu<TipElemenata> (m1.br_kolona,m1.br_kolona);
                             pom1=ProduktMatrica(pom2,m1);
                             UnistiMatricu(pom2);
                             pom2=pom1;
                             UnistiMatricu(pom1);
                        }
                    }
                    for(int j=0;j<m1.br_kolona;j++)
                    {
                        for(int k=0;k<m1.br_kolona;k++)
                        {
                            pom2.elementi[j][k]=brojevi[i]*pom2.elementi[j][k];
                        }
                    }
                   // IspisiMatricu(pom2,2);
                    Matrica<TipElemenata> pom3=StvoriMatricu<TipElemenata> (m1.br_kolona,m1.br_kolona);
                    pom3=ZbirMatrica(mat,pom2);
                    mat=pom3;
                   // IspisiMatricu(mat,5);
                    UnistiMatricu(pom3);
                    UnistiMatricu(pom2);
                }
            }
        }
    return mat;
     }

    catch(...)
    {
        throw;
    }
}
int main ()
{
    int n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    int red;
    Matrica <double> a;
    std::vector<double> polinom ;
    try{
        a=StvoriMatricu<double>(n,n);
        std::cout<<"Unesite elemente matrice A: ";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<red;i++)
        {
            double x;
            std::cin>>x;
            polinom.push_back(x);
        }
        Matrica<double> p=StvoriMatricu<double>(n,n);
        p=MatricniPolinom<double>(a,polinom);
        std::cout<<"xx";
        IspisiMatricu(p,6);
        UnistiMatricu(p);
        UnistiMatricu(a);
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
       // UnistiMatricu(p);
        UnistiMatricu(a);
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<"A("<<i+1<<","<<j+1<<") =";
            std::cin>>m[i][j];*/
     
	return 0;
}