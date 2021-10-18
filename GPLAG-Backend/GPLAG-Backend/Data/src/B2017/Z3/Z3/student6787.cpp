#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<vector>
#include <cmath>

template<typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};
//Unisti matricu
template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat){
    if(!mat.elementi)return;
    for(int i(0);i<mat.br_redova;i++){
        delete[] mat.elementi[i];
    }
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
//Stvori matricu
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova;mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata *[br_redova];
    for(int i(0);i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i(0);i<br_redova;i++)
        mat.elementi[i]=new TipElemenata[br_kolona]{};
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

//Stvori jedinicnu matricu

template<typename TipElemenata>
Matrica<TipElemenata>StvoriJedinicnuMatricu(int br_redova,int br_kolona){
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata *[br_redova];
    for(int i(0);i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for (int i(0);i<br_redova;i++)
        mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    for (int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            if(i==j){
                mat.elementi[i][j]=1;
            }
            else mat.elementi[i][j]=0;
        }
    }
    return mat;
}
//Pomnozi skalarom

template<typename TipElemenata>
Matrica<TipElemenata>PomnoziSkalarom(Matrica<TipElemenata>m2,double x){
    Matrica<TipElemenata>nova;
    try{
        nova=StvoriMatricu<TipElemenata>(m2.br_redova,m2.br_kolona);
    }
    catch(std::bad_alloc){
        throw;
    }
    for(int i(0);i<nova.br_redova;i++){
        for(int j(0);j<nova.br_kolona;j++){
        nova.elementi[i][j]=m2.elementi[i][j];
            nova.elementi[i][j]*=x;
        }
    }
    return nova;
}
//Unesi matricu
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata>&mat){
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
            }
    }
}

//Ispisi matricu

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat,int sirina_ispisa, int preciznost=6,bool treba_brisati=false){
    for(int i(0);i<mat.br_redova;i++){
        for(int j(0);j<mat.br_kolona;j++)
        std::cout<< std::setw(sirina_ispisa)<< std:: setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
        }
        if(treba_brisati==true)UnistiMatricu(mat);
        }
        
      //Zbir matrica 
        template<typename TipElemenata>
        Matrica<TipElemenata>ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
            if(m1.br_redova!= m2.br_redova || m1.br_kolona!=m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
            auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_redova));
            for(int i(0);i<m1.br_redova;i++){
                for (int j(0);j<m1.br_kolona;j++){
                    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
                }
            }
            return m3;
        }
        
//produkt
template<typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata>&m1,const Matrica<TipElemenata>&m2){
    if(m1.br_kolona!=m2.br_redova) 
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for (int i(0);i<m1.br_redova;i++){
        for (int j(0);j<m2.br_kolona;j++){
            TipElemenata pomocna(0);
            for(int k(0);k<m1.br_kolona;k++){
                pomocna+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=pomocna;
        }
    }
    return m3;
}

//Stepenuj
template<typename TipElemenata>
Matrica<TipElemenata> Stepenuj(Matrica<TipElemenata> m1, int stepen){
    Matrica<TipElemenata>m2;
    if(stepen==0){
        try{
    m2=StvoriJedinicnuMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
    }
    catch(std::bad_alloc){throw;}
    return m2;
    }
    else if(stepen==1) {
        try{ m2=StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
        for(int i(0);i<m1.br_redova;i++){
            for(int j(0);j<m1.br_kolona;j++){
                m2.elementi[i][j]=m1.elementi[i][j];
            }
        }
        }
            catch(std::bad_alloc){
                throw;
            }
            return m2;
        
    }
    else{
        try{
            m2=StvoriJedinicnuMatricu<TipElemenata>(m1.br_redova,m1.br_kolona);
        }
        catch(std::bad_alloc){
            throw;
        }
        for(int i(0);i<stepen;i++) {
            auto dosadasnja=m2;
            m2=ProduktMatrica(m1,m2);
            UnistiMatricu(dosadasnja);
        }
    }
    return m2;
} 
//Matricni polinom

template<typename TipElemenata, typename IterTip>
Matrica<TipElemenata>MatricniPolinom(const Matrica<TipElemenata> &m, int n, IterTip p){
    Matrica<TipElemenata>pn,I,pomocna;
    
    if(m.br_kolona!=m.br_redova)
    throw std::domain_error("Matrica mora biti kvadratna");
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    try{
        pn=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        I=StvoriJedinicnuMatricu<TipElemenata>(m.br_redova,m.br_kolona);
        pomocna=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
            for(int i(0);i<=n;i++){
                if(i==0){
                    for(int ii=0;ii<m.br_redova;ii++){
                        for(int jj=0;jj<m.br_kolona;jj++){
                            pomocna.elementi[ii][jj]=*p*I.elementi[ii][jj];
                        }
                    }
                }
                
            else if(i==1){
                for(int ii(0);ii<m.br_redova;ii++){
                    for(int jj(0);jj<m.br_kolona;jj++){
                        pomocna.elementi[ii][jj]=*p*m.elementi[ii][jj];
                    }
                }
            }
            else{
                UnistiMatricu(pomocna);
                pomocna = Stepenuj(m,i);
                for(int ii(0); ii < m.br_redova; ii++) {
                    for(int jj(0); jj < m.br_kolona; jj++) {
                        pomocna.elementi[ii][jj]*=*p;
                    }
                }
            }
            auto g=ZbirMatrica<TipElemenata>(pomocna,pn);
            for(int ii(0);ii<pn.br_kolona;ii++){
                for(int jj(0);jj<pn.br_kolona;jj++){
                    pn.elementi[ii][jj]=g.elementi[ii][jj];
                }
            }
            UnistiMatricu(g);
            p++;
        }
        UnistiMatricu(pomocna);
        UnistiMatricu(I);
        return pn;
    }
    catch(std::bad_alloc) {
        UnistiMatricu(pn);
        UnistiMatricu(pomocna);
        UnistiMatricu(I);
        throw;
    }
}
    
    int main(){
    Matrica<double>a;
    int m,n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    
    std::vector<double> v;
    try{
        a=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A:"<<std::endl;
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::cout<< "Unesite koeficijente polinoma: ";
        for(int i(0);i<=n;i++){
            double k;
            std::cin>>k;
            v.push_back(k);
            }
            auto x=MatricniPolinom(a,n,v.begin());
            IspisiMatricu(x,10);
            UnistiMatricu(x);
            }
            catch(std::bad_alloc){
                std::cout<<"Nema dovoljno memorije!"<<std::endl;
            }
            UnistiMatricu(a);
            return 0;
}