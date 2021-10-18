#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>
template <typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> &mat){
        if(!mat.elementi) return;
        for(int i=0;i<mat.br_redova;i++)delete[]  mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova;
        mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata*[br_redova];
        for(int i=0;i<br_redova;i++)mat.elementi[i]=nullptr;
        try{
            for(int i=0;i<br_redova;i++)mat.elementi[i]=new TipElemenata[br_kolona];
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
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
        }
    }
template <typename TipElemenata>
    void IspisiMatricu(Matrica<TipElemenata> mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false){
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++)
                std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            std::cout<<std::endl;
        }
        if(treba_brisati)UnistiMatricu(mat);
    }
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)throw std::domain_error("Marice nemaju jednake dimenzije");
        auto m3=StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
        for(int i=0;i<m1.br_redova;i++)
            for(int j=0;j<m2.br_kolona;j++)
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        return m3;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> DubokaKopija(Matrica<TipElemenata> m){
        Matrica<TipElemenata> mat=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        for(int i=0;i<mat.br_redova;i++)
            for(int j=0;j<mat.br_kolona;j++)
                mat.elementi[i][j]=m.elementi[i][j];
        return mat;
    }
template <typename TipElemenata>
    void DodijeliDruguMatricu(Matrica<TipElemenata> &m,Matrica<TipElemenata> n){
        UnistiMatricu(m);
        m=DubokaKopija(n);
    }
template <typename TipElemenata>
    Matrica<TipElemenata> PomnoziSkalarom(const Matrica<TipElemenata> &mat,double n){
        auto m=DubokaKopija(mat);
        for(int i=0;i<m.br_redova;i++)
            for(int j=0;j<m.br_kolona;j++)
                m.elementi[i][j]=n*mat.elementi[i][j];
        return m;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &a,const Matrica<TipElemenata> &b){
        if(a.br_kolona!=b.br_redova)throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto produkt(StvoriMatricu<TipElemenata>(a.br_redova,b.br_kolona));
        for(int i=0;i<a.br_redova;i++){
            for(int j=0;j<b.br_kolona;j++){
                produkt.elementi[i][j]=0;
                for(int k=0;k<a.br_kolona;k++)produkt.elementi[i][j]+=a.elementi[i][k]*b.elementi[k][j];
            }
        }
        return produkt;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> JedinicnaMatrica(const Matrica<TipElemenata> &a){
        auto o=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
        for(int i=0;i<o.br_redova;i++)
            for(int j=0;j<o.br_kolona;j++){
                if(i==j)o.elementi[i][j]=1;
                else o.elementi[i][j]=0;
            }
        return o;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> StepenovanjeMatrice(const Matrica<TipElemenata> &mat,int n){
        if(n==0)return JedinicnaMatrica(mat);
        if(n==1)return mat;
        auto stepen=DubokaKopija(mat);
        for(int i=1;i<n;i++){
            auto c=ProduktMatrica(stepen,mat);
            DodijeliDruguMatricu(stepen,c);
            UnistiMatricu(c);
        }
        return stepen;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> NulaMatrica(const Matrica<TipElemenata> &mat){
        auto o=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
        for(int i=0;i<o.br_redova;i++){
            for(int j=0;j<o.br_kolona;j++)o.elementi[i][j]=0;
        }
        return o;
    }
template <typename TipElemenata>
    bool Kvadratna(const Matrica<TipElemenata> &mat){
        return(mat.br_redova==mat.br_kolona);
    }
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat,std::vector<double> v){
        if(!Kvadratna(mat))throw std::domain_error("Matrica mora biti kvadratna");
        auto sum=NulaMatrica(mat);
        if(v.size()==0)return sum;
        for(int i=0;i<v.size();i++){
            auto d=StepenovanjeMatrice(mat,i);
            auto e=PomnoziSkalarom(d,v[i]);
            auto f=ZbirMatrica(sum,e);
            DodijeliDruguMatricu(sum,f);
            UnistiMatricu(d);
            UnistiMatricu(e);
            UnistiMatricu(f);
        }
        return sum;
    }
int main (){
    int n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    auto a=StvoriMatricu<double>(n,n);
    std::cout<<"Unesite elemente matrice A:"<<std::endl;
    UnesiMatricu(65,a);
    std::cout<<"Unesite red polinoma: ";
    std::cin>>n;
    std::vector<double> v(n+1);
    std::cout<<"Unesite koeficijente: ";
    for(int i=0;i<v.size();i++)std::cin>>v[i];
    IspisiMatricu(MatricniPolinom(a,v),10,6,true);
    UnistiMatricu(a);
   
	return 0;
}
