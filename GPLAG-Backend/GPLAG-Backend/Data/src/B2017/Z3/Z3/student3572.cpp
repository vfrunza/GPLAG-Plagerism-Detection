/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
template<typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};
template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat){
    if(!mat.elementi)return;
    for(int i=0;i<mat.br_redova;i++)delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template<typename TipElemenata>
Matrica<TipElemenata>StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova;mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++)mat.elementi[i]=nullptr;
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
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jedanke dimanezije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
    for(int j=0;j<m1.br_kolona;j++)
    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
     TipElemenata suma{0};
     for(int k=0;k<m1.br_redova;k++){
    for(int i=0;i<m2.br_kolona;i++){
        for(int j=0;j<m2.br_kolona;j++){
            suma+=m1.elementi[k][j]*m2.elementi[j][i];
        }
         m3.elementi[k][i]=suma;
         suma=0;
    }
}
return m3;//mora se dodati nekoj varijabli i poslije se obrisati
}
template<typename TipElemenata>
void PomnoziSaSkalarom(const Matrica<TipElemenata> &m1, double skalar){
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m1.elementi[i][j]*=skalar;
        }
    }
}//ovo nije kopija sve se desava nad ovom matricom, ona se izmijeni

template<typename TipElemenata>
Matrica<TipElemenata>StvoriJedinicnu(int br_redova, int br_kolona){
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova;mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++)mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
        mat.elementi[i]=new TipElemenata[br_kolona];
        for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++){
            if(i==j)mat.elementi[i][j]=1;
            else mat.elementi[i][j]=0;
        }
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;// ovo vraca matricu koju poslije normalno unistimo
}


template<typename TipElemenata,typename p>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,int n, p koeficijenti){
    if(n<0)throw std::domain_error("Neispravan stepen polinoma");
    if(m1.br_redova!=m1.br_kolona)throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> nula(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
    for(int j=0;j<m1.br_kolona;j++)
    nula.elementi[i][j]=0;//postavila polinom na nula matricu
    Matrica<TipElemenata> polinom;
    auto it(koeficijenti);
    for(int i=0;i<=n;i++){
        if(i==0){
            Matrica<TipElemenata> a(StvoriJedinicnu<TipElemenata>(m1.br_redova,m1.br_kolona));
            PomnoziSaSkalarom(a,*it);
            polinom=ZbirMatrica(nula,a);
            UnistiMatricu(a);UnistiMatricu(nula);
            
            it++;
        }
        else if(i==1){
            PomnoziSaSkalarom(m1,*it);
            Matrica<TipElemenata> b(polinom);
            polinom=ZbirMatrica(polinom,m1);
            UnistiMatricu(b);
            PomnoziSaSkalarom(m1,1./(*it));
             it++;
        }
        else if(i>=2){
            
            Matrica<TipElemenata> nova(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
            for(int i=0;i<m1.br_redova;i++)
            for(int j=0;j<m1.br_kolona;j++)
            nova.elementi[i][j]=m1.elementi[i][j];
            for(int k=1;k<i;k++){
            Matrica<TipElemenata> pomocna(nova);
            nova=ProduktMatrica(nova,m1);
            UnistiMatricu(pomocna);
            }
            PomnoziSaSkalarom(nova,*it);
            Matrica<TipElemenata> c(polinom);
            polinom=ZbirMatrica(polinom,nova);
            UnistiMatricu(c);
            UnistiMatricu(nova);
            it++;
        }
        
    }
    UnistiMatricu(m1);
    return polinom;
   
}

int main ()
{
    Matrica<int>a;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin>>n;
    try{
        a=StvoriMatricu<int>(n,n);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<int> koef;
        int b;
        for(int i=0;i<=red;i++){
            std::cin>>b;
            koef.push_back(b);
        }
       Matrica<int>c(MatricniPolinom(a,red,koef.begin())); 
       IspisiMatricu(c,10,6,true);
       
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
	return 0;
}
