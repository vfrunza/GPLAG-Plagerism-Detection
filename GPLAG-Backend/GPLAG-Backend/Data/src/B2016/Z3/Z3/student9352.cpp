/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) { delete[] mat.elementi[i];  mat.elementi[i]=nullptr;}
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0; i<br_redova;i++) mat.elementi[i] = nullptr;
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

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat)
{
    for(int i=0;i<mat.br_redova;i++)
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i=0;i<mat.br_redova;i++) 
    {
        for(int j=0;j<mat.br_kolona;j++)
        {
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati)  UnistiMatricu(mat);
}

template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error ("Matrica nemaju jednake dimenzije");
    Matrica<TipElemenata> m3{StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona)};
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
        m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona !=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3{StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona)};
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int k=0;k<m2.br_kolona;k++)
        {
            double suma{0};
            for(int j=0;j<m1.br_kolona;j++)
            {
                suma+=m1.elementi[i][j]*m2.elementi[j][k];
            }
            m3.elementi[i][k]=suma;
        }
    }
    return m3;
}

/*template<typename TipElemenata>
Matrica<TipElemenata> MnozenjeMatriceSkalarom(const Matrica<TipElemenata> &m,double skalar){
    Matrica<TipElemenata> pomocna;
    pomocna =StvoriMatricu<double>(m.br_redova, m.br_kolona);
    for(int i=0;i<m.br_redova;i++)
        for(int j=0;j<m.br_kolona;j++)
        {
            pomocna.elementi[i][j]=skalar*m.elementi[i][j];
        }
    return pomocna;
}
*/
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> v){
    if(m.br_redova != m.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna");
    Matrica<TipElemenata> mat{StvoriMatricu<double>(m.br_redova,m.br_kolona)};
    if(v.size()==0){
        for(int i=0;i<m.br_redova;i++)
            for(int j=0;j<m.br_kolona;j++)
            {
                mat.elementi[i][j]=0;
            }
        return mat;
    }
    //Matrica<TipElemenata> rezultat{StvoriMatricu<double>(m.br_redova,m.br_kolona)};
    Matrica<TipElemenata> rezultat;
    Matrica<TipElemenata> zbir;
    rezultat=StvoriMatricu<double>(m.br_redova,m.br_kolona);
    for(unsigned int i=0;i<v.size();i++)
    {
        if(i==0)
        {
            for(int j=0;j<m.br_redova;j++)
            {
                for(int k=0;k<m.br_kolona;k++)
                {
                    if(j==k) mat.elementi[j][j]=1;
                    else mat.elementi[j][k]=0;
                }
            }    
            for(int i=0;i<m.br_redova;i++)
                 for(int j=0;j<m.br_kolona;j++)
                {
                    rezultat.elementi[i][j]=v[0]*mat.elementi[i][j];
                }
    
        }
        else
        {
            mat=ProduktMatrica(mat,m);
            Matrica<TipElemenata> pomocna{StvoriMatricu<double>(m.br_redova,m.br_kolona)};
            for(int k=0;k<m.br_redova;k++)
                for(int j=0;j<m.br_kolona;j++)
                {
                    pomocna.elementi[k][j]=mat.elementi[k][j]*v[i];
                }
            zbir=ZbirMatrica(rezultat,pomocna);
            
            Matrica<TipElemenata> tmp{zbir};
            zbir = rezultat;
            rezultat = tmp;
            
            UnistiMatricu(zbir);
            UnistiMatricu(pomocna);
        }
    }
    UnistiMatricu(mat);
    return rezultat;
}


int main ()
{
    Matrica<double> a,b;
    int m;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int red_polinoma;
        std::cin>>red_polinoma;
        std::cout<<"Unesite koeficijente polinoma: ";
        std:: vector<double> v;
        for(int i=0;i<=red_polinoma;i++)
        {
            double broj;
            std::cin>>broj;
            v.push_back(broj);
        }
        b=MatricniPolinom(a,v);
        IspisiMatricu(b,10,6);
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    catch(std::domain_error e) {
        std::cout<<e.what();
    }
    UnistiMatricu(a); UnistiMatricu(b);
    
	return 0;
}