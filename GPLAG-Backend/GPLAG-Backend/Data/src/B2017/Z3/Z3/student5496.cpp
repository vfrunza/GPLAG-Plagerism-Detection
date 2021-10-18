/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <iterator>
template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> m){
    if(!m.elementi) return;
    for(int i(0); i<m.br_redova; i++) delete [] m.elementi[i];
    delete [] m.elementi;
    m.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> m;
    m.br_redova=br_redova;
    m.br_kolona=br_kolona;
    m.elementi=new TipElemenata*[br_redova];
    for(int i(0); i<br_redova; i++)
    m.elementi[i]=nullptr;
    try{
        for(int i(0); i<br_redova; i++)
        m.elementi[i]=new TipElemenata[br_kolona];
    } catch(...){
        UnistiMatricu(m);
        throw;
    }
    return m;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &m){
    for(int i(0); i<m.br_redova; i++)
       for(int j(0); j<m.br_kolona; j++){
           std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
           std::cin>>m.elementi[i][j];
       }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &m, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i(0); i<m.br_redova; i++){
        for(int j(0); j<m.br_kolona; j++)
           std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<m.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(m);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije");
    Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i(0); i<m1.br_redova; i++)
        for(int j(0); j<m2.br_kolona; j++)
           m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i(0); i<m1.br_redova; i++)
       for(int j(0); j<m2.br_kolona; j++){
           TipElemenata suma(0);
           for(int k(0); k<m2.br_redova; k++)
           suma+=m1.elementi[i][k]*m2.elementi[k][j];
        m3.elementi[i][j]=suma;
       }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSaSkalarom(const Matrica<TipElemenata> m, double n){
    Matrica<TipElemenata> rezultat(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
    for(int i(0); i<rezultat.br_redova; i++)
       for(int j(0); j<rezultat.br_kolona; j++)
       rezultat.elementi[i][j]=m.elementi[i][j]*n;
    return rezultat;
}
template <typename TipElemenata>
void KopirajElemente(const Matrica<TipElemenata> &m, TipElemenata **Elementi){
    for(int i(0); i<m.br_redova; i++)
       for(int j(0); j<m.br_kolona; j++)
       Elementi[i][j]=m.elementi[i][j];
}

template <typename TipElemenata>
Matrica<TipElemenata> Stepenuj(const Matrica<TipElemenata> &m, int stepen){
    Matrica<TipElemenata> stepenovano;
    try{
        stepenovano=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        if(stepen==0){
            for(int i(0); i<stepenovano.br_redova; i++)
               for(int j(0); j<stepenovano.br_kolona; j++){
                   if(i==j) stepenovano.elementi[i][j]=1;
                   else stepenovano.elementi[i][j]=0;
                }
            return stepenovano;
        }
        else {
            if(stepen==1){
                KopirajElemente(m,stepenovano.elementi);
                return stepenovano;
            }
            if(stepen>=2){
                for(int i=1; i<stepen; i++){
                    stepenovano=ProduktMatrica(m,m);
                    return stepenovano;
                }
            }
    }
    }catch(...){
        UnistiMatricu(stepenovano); 
        throw;
    }
}
template <typename TipElemenata, typename Tip1>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &m, int n, Tip1 poc_bloka){
    if(n<=0) throw std::domain_error("Neispravan stepen polinoma");
    Matrica<TipElemenata> step,pom,sum;
    int br=0;
    
    try{
        step=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        pom=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        sum=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        for(auto i=poc_bloka; i!=(poc_bloka+n+1); i++){
        step=Stepenuj(m,br); br++;    //u f-ji Stepenuj koristim f-ju ProduktMatrica
        pom=PomnoziSaSkalarom(step,*i);
        sum=ZbirMatrica(sum,pom);
        }
    }catch(...){
        UnistiMatricu(step);
        UnistiMatricu(pom);
    }
    UnistiMatricu(step);
    UnistiMatricu(pom);
    return sum;
}
int main(){
    int dimenzija,n,x;
    Matrica<double> a;
    try{
        std::cout<<"Unesite dimenziju kvadratne matrice: ";
        std::cin>>dimenzija;
        std::cout<<"Unesite elemente matrice A:\n";
        a=StvoriMatricu<double>(dimenzija,dimenzija);
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<int> v(n+1);
        for(int i=0; i<v.size(); i++){
            std::cin>>x;
            v[i]=x;
        }
        IspisiMatricu(MatricniPolinom(a,n,v.begin()),10,6,true);
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }catch(std::bad_alloc){
        std::cout<<"Problemi s memorijom!";
    }
    UnistiMatricu(a);
    return 0;
}