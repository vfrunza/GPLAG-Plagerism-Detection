#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<vector>

template<typename tip>

struct Matrica{
    int br_redova, br_kolona;
    tip **pok=nullptr;
};

template<typename tip>
void UnistiMatricu(Matrica<tip>mat){
    if(!mat.pok) return;
    for(int i=0;i<mat.br_redova;i++) delete [] mat.pok[i];
    delete [] mat.pok;
    mat.pok=nullptr;
}

template<typename tip>

Matrica<tip>StvoriMatricu (int m, int n=0){
    if(n==0) n=m;
    Matrica <tip> mat;
    mat.br_redova=m;
    mat.br_kolona=n;
    try{
        mat.pok=new tip *[m];
      for(int i=0;i<m;i++) mat.pok[i]=nullptr;
        try{
            for(int i=0;i<m;i++) mat.pok[i]=new tip[n]; //svi elementi na nulu
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++)
                    mat.pok[i][j]=0;
            }
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
      }
    }
    catch(...){
        delete [] mat.pok;
        throw;
    }
    return mat;
}

template<typename tip>
void UnesiMatricu(char ime, Matrica<tip>&mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime<<"("<<i+1<<","<<j+1<<")"<<" = ";
            std::cin>>mat.pok[i][j];
        }
    }
}

template<typename tip>
void IspisiMatricu(const Matrica<tip>&mat, int sirina_ispisa, int preciznost=6, bool treba_brisat=false){
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.pok[i][j];
            }
        std::cout<<std::endl;
        }
        
    if(treba_brisat) UnistiMatricu(mat);
}

template<typename tip>
Matrica<tip>ZbirMatrica(const Matrica<tip>&mat1, const Matrica<tip>&mat2){
    if(mat1.br_kolona!=mat2.br_kolona || mat1.br_redova!=mat2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto mat=StvoriMatricu<tip>(mat1.br_redova,mat1.br_kolona);
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
           mat.pok[i][j]=mat1.pok[i][j]+mat2.pok[i][j];
    }
    return mat;
}

template<typename tip>
Matrica<tip> ProduktMatrica(Matrica<tip>a, Matrica<tip>b){
    if(a.br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<tip>mat;
    mat=StvoriMatricu<tip>(a.br_redova,b.br_kolona);
    for(int i=0;i<a.br_redova;i++){
        for(int j=0;j<b.br_kolona;j++){
            for(int k=0;k<b.br_redova;k++){
                mat.pok[i][j]+=a.pok[i][k]*b.pok[k][j];
            }
        }
    }
   
   return mat; 
}

template <typename tip>
Matrica<tip>KopijaMatrice (Matrica<tip>a){
    Matrica <tip>mat=StvoriMatricu<tip>(a.br_redova,a.br_kolona);
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++)
            mat.pok[i][j]=a.pok[i][j];
    }
    return mat;
}

template<typename tip>
void Curenje(Matrica <tip>&a, Matrica <tip>b){
    UnistiMatricu(a);
    a=KopijaMatrice<tip>(b);
}

template <typename tip>
Matrica<tip> Stepen (Matrica <tip>a, int b){
    Matrica <tip>mat=KopijaMatrice<tip>(a);
    if(b>=2){
        for(int i=0;i<b-1;i++){
            Matrica <tip>mat1=ProduktMatrica(mat,a);
            Curenje(mat,mat1);
            UnistiMatricu(mat1);
        }
    }
    else if(b==1) return mat;
    else{
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++){
                if(i==j) mat.pok[i][j]=1;
                else mat.pok[i][j]=0;
            }
        }
    }
    return mat;
}

template<typename tip>
Matrica<tip>ProduktSaSkalarom(Matrica<tip>mat, double n){
    Matrica <tip>mat1=KopijaMatrice<tip>(mat);
    for(int i=0;i<mat1.br_redova;i++){
        for(int j=0;j<mat1.br_kolona;j++){
            mat1.pok[i][j]=n*mat.pok[i][j];
        }
    }
    return mat1;
}

template<typename tip>
Matrica <tip> MatricniPolinom (Matrica<tip>a, std::vector<double>v){
    if (a.br_kolona!=a.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica <tip>mat=StvoriMatricu<tip>(a.br_redova,a.br_kolona);
    if(v.size()==0) {
        for(int i=0;i<mat.br_redova;i++)
            for(int j=0;j<mat.br_kolona;j++)
                mat.pok[i][j]=0;
      return mat;
    }
    
    for(int i=0;i<v.size();i++){
        Matrica <tip>mat1=Stepen<tip>(a,i);
        Matrica <tip>mat2=ProduktSaSkalarom<tip>(mat1,v[i]);
        Matrica<tip> mat3=ZbirMatrica(mat,mat2);
        Curenje(mat,mat3);
       // Curenje(mat,ZbirMatrica(mat,mat2));
        UnistiMatricu(mat1);
        UnistiMatricu(mat2);
        UnistiMatricu(mat3);
    }
    return mat;
}

int main (){
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin>>n;
    Matrica<int>mat,mat1;
    try{
        std::cout<<"Unesite elemente matrice A:\n";
        mat=StvoriMatricu<int>(n);
        UnesiMatricu('A',mat);
        std::cout<<"Unesite red polinoma: ";
        int a;
        std::cin>>a;
        std::vector<double>v ;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=a;i++){
            int b;
            std::cin>>b;
            v.push_back(b);
        }
      
        mat1=MatricniPolinom<int>(mat,v);
        IspisiMatricu(mat1,10,6,true);
    }
    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije";
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
	return 0;
}