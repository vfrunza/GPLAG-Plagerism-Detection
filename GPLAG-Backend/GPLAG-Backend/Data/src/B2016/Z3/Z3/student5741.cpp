/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::bad_alloc;
using std::setw;
using std::vector;
using std::setprecision;

template<typename TipElemenata>
    struct Matrica{
        int br_redova,br_kolona;
        TipElemenata **elementi=nullptr;
    };
    
template<typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat){
        if(!mat.elementi) return;
        for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template<typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova; mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata* [br_redova];
        for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
        try{
            for(int i=0;i<br_redova;i++){
                mat.elementi[i]=new TipElemenata [br_kolona];
                for(int j=0;j<br_kolona;j++){
                    mat.elementi[i][j]=0;
                }
            }
        }
        catch(...){
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
template<typename TipElemenata>
    void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat){
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                cin>>mat.elementi[i][j];
            }
        }
    }

template<typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false){
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                cout<<setw(sirina_ispisa)<<setprecision(preciznost)<<mat.elementi[i][j];
            }
            cout<<endl;
        }
        if(treba_brisati){
            UnistiMatricu(mat);
        }
    }
    
template<typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona){
            throw domain_error("Matrice nemaju jednake dimenzije!");
        }
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        for(int i=0;i<m1.br_redova;i++){
            for(int j=0;j<m1.br_kolona;j++){
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
            }
        }
        return m3;
    }

template<typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
        if(m1.br_kolona!=m2.br_redova){
            throw domain_error("Matrice nisu saglasne za mnozenje");
        }
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
        for(int i=0;i<m1.br_redova;i++){
            for(int j=0;j<m2.br_kolona;j++){
                for(int k=0;k<m1.br_kolona;k++){
                    m3.elementi[i][j]=m3.elementi[i][j]+m1.elementi[i][k]*m2.elementi[k][j];
                }
            }
        }
        return m3;
    }
    
template<typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,vector<double> p){
        if(m1.br_redova!=m1.br_redova){
            throw domain_error("Matrica mora biti kvadratna");
        }
        auto matricni_polinom(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        for(int i=0;i<matricni_polinom.br_redova;i++){
            for(int j=0;j<matricni_polinom.br_kolona;j++){
                matricni_polinom.elementi[i][j]=0;
            }
        }
        if(p.size()==0){
            return matricni_polinom;
        }
        else{
            for(int l=0;l<p.size();l++){
                auto pomocna(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
                for(int i=0;i<m1.br_redova;i++){
                    for(int j=0;j<m1.br_kolona;j++){
                        pomocna.elementi[i][j]=m1.elementi[i][j];
                    }
                }
                if(l==0){
                    for(int i=0;i<m1.br_redova;i++){
                        for(int j=0;j<m1.br_kolona;j++){
                            if(i==j){
                                pomocna.elementi[i][j]=p[l];
                            }
                            else{
                                pomocna.elementi[i][j]=0;
                            }
                        }
                    }
                }
                else{
                    for(int k=0;k<l-1;k++){
                        auto dodatna(ProduktMatrica(pomocna,m1));
                        for(int i=0;i<m1.br_redova;i++){
                            for(int j=0;j<m1.br_kolona;j++){
                                pomocna.elementi[i][j]=dodatna.elementi[i][j];
                            }
                        }
                        UnistiMatricu(dodatna);
                    }
                    for(int i=0;i<pomocna.br_redova;i++){
                        for(int j=0;j<pomocna.br_kolona;j++){
                            pomocna.elementi[i][j]=p[l]*pomocna.elementi[i][j];
                        }
                    }
                }
                for(int i=0;i<pomocna.br_redova;i++){
                    for(int j=0;j<pomocna.br_kolona;j++){
                        matricni_polinom.elementi[i][j]=matricni_polinom.elementi[i][j]+pomocna.elementi[i][j];
                    }
                }
                UnistiMatricu(pomocna);
            }
        }
        return matricni_polinom;
    }
    
int main ()
{
    Matrica<double> a,matricni_polinom;
    int m,n;
    cout<<"Unesite dimenziju kvadratne matrice: ";
    cin>>m;
    n=m;
    try{
        a=StvoriMatricu<double>(m,n);
        cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
        int red_polinoma;
        cout<<"Unesite red polinoma: ";
        cin>>red_polinoma;
        vector<double> p(red_polinoma+1);
        cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=red_polinoma;i++){
            double broj;
            cin>>broj;
            p[i]=broj;
        }
        matricni_polinom=MatricniPolinom(a,p);
        IspisiMatricu(matricni_polinom,10,6,true);
    }
    catch(bad_alloc){
        cout<<"Nema dovoljno memorije!\n";
    }
    catch(domain_error izuzetak){
        cout<<izuzetak.what()<<endl;
    }
    catch(...){
        cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
	return 0;
}