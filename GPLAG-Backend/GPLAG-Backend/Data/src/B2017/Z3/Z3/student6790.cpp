/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <list>

template <typename TipElementa>
struct Matrica {
    int br_redova, br_kolona;
    TipElementa **elementi=nullptr;
};

template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat) {
    if(!mat.elementi) return;
    for(int i(0);i<mat.br_redova;i++)
        delete[] mat.elementi[i];

    delete [] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElementa>
Matrica <TipElementa> StvoriMatricu(int br_redova=0, int br_kolona=0) {
    Matrica<TipElementa> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi= new TipElementa*[br_redova]{};
    for(int i(0);i<mat.br_redova;i++)
        mat.elementi[i]=nullptr;
    try{
        for(int i(0);i<br_redova;i++)
            mat.elementi[i]=new TipElementa [br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElementa>
void UnesiMatricu (char ime_matrice,Matrica<TipElementa> &mat) {
    for(int i(0);i<mat.br_redova;i++) 
        for(int j(0);j<mat.br_kolona;j++) {
            std::cout<<ime_matrice
                <<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElementa>
void IspisiMatricu(const Matrica<TipElementa> &mat,int sirina_ispisa=10,int preciznost=6,bool treba_brisati=false) {
    for(int i(0);i<mat.br_redova;i++) {
        for(int j(0);j<mat.br_kolona;j++) 
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElementa>
Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa> &m1,const Matrica<TipElementa> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona));
    for(int i(0);i<m1.br_redova;i++) 
        for(int j(0);j<m1.br_kolona;j++) 
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template <typename TipElementa>
Matrica<TipElementa> ProduktMatrica(const Matrica<TipElementa> &m1,const Matrica<TipElementa> &m2) { 
    if(m1.br_kolona!=m2.br_redova) 
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElementa>(m1.br_redova,m2.br_kolona));
    
    for(int i(0);i<m1.br_redova;i++){
        int k(0);
        for(int j(0);j<m3.br_kolona;j++){ 
            double suma(0);
            for(int l(0);l<m2.br_redova;l++) {
                suma+=m1.elementi[i][l]*m2.elementi[l][j];
            }
            k++;
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template <typename TipElementa,typename Iterator>
Matrica<TipElementa> MatricniPolinom(Matrica<TipElementa> mat,int n,Iterator it){
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");

    Matrica<TipElementa> Polinom(StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona));
    
    for(int k(0);k<=n;k++) {
        if (k==0) {
            for(int i(0);i<Polinom.br_redova;i++) {
                for(int j(0);j<Polinom.br_kolona;j++) {
                    if(i==j) Polinom.elementi[i][j]=(*it);
                    else Polinom.elementi[i][j]=0;
                }
            }
            it++;
        }
        if(k==1) {
            for(int i(0);i<Polinom.br_redova;i++) 
                for(int j(0);j<Polinom.br_kolona;j++) 
                    Polinom.elementi[i][j]+=(mat.elementi[i][j]*(*it));
            it++;
        }
        if(k>1) {
            Matrica<TipElementa> StepenaMatrica;
            StepenaMatrica=ProduktMatrica(mat,mat);
            int koliko_puta(k-2);
            
            if(koliko_puta==0) {
                
                for(int i(0);i<Polinom.br_redova;i++) {
                    for(int j(0);j<Polinom.br_kolona;j++){ 
                        Polinom.elementi[i][j]+=(StepenaMatrica.elementi[i][j]*(*it));
                    }
                }
            }
            
            else{
                while (koliko_puta!=0) {

                    Matrica<TipElementa> Radni_prostor;
                    Radni_prostor=ProduktMatrica(StepenaMatrica,mat);
                    
                    for(int i(0);i<StepenaMatrica.br_redova;i++) {
                        for(int j(0);j<StepenaMatrica.br_kolona;j++){ 
                            Polinom.elementi[i][j]+=(Radni_prostor.elementi[i][j]*(*it));
                        }
                    }

                    UnistiMatricu(Radni_prostor);
                    koliko_puta--;
                }
            }
            UnistiMatricu(StepenaMatrica);
            it++;
        }

    }
    return Polinom;
}

int main () {
    Matrica<int> a,mat_polinom;
    int dimenzija;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzija;
    
    try {
        a=StvoriMatricu<int>(dimenzija,dimenzija);
      
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int red_polinoma;
        std::cin>>red_polinoma;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::list<int> polinomi;
        for(int i=0;i<=red_polinoma;i++) {
            int p;
            std::cin>>p;
            polinomi.push_back(p);
        }
        mat_polinom=MatricniPolinom<int>(a,red_polinoma,polinomi.begin());
        IspisiMatricu(mat_polinom);

    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(mat_polinom);

    
	return 0;
}