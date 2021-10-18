/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector> 
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        
        for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0; i<mat.br_redova;i++)
    for(int j=0; j<mat.br_kolona;j++){
    std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
    std::cin>>mat.elementi[i][j];
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false){
    for(int i=0; i<mat.br_redova;i++){
        for(int j=0; j<mat.br_kolona;j++){
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            }
    std::cout<<std::endl;
        
    }
    if(treba_brisati==true) {
        UnistiMatricu(mat);
        
    }
    
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2){
    if(mat1.br_redova!=mat2.br_redova || mat1.br_kolona!=mat2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(mat1.br_redova,mat1.br_kolona));
    for(int i=0; i<mat1.br_redova;i++)
    for(int j=0; j<mat1.br_kolona;j++)
        m3.elementi[i][j]=mat1.elementi[i][j]+mat2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2){
    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
    for(int i=0; i<mat1.br_redova;i++){
        for(int j=0; j<mat2.br_kolona;j++){
            TipElemenata suma=0;
            for(int k=0; k<mat2.br_redova;k++){//m1 broj kolona
               suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
                
            }
               
                m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, std::vector<double> v){
    if(mat.br_redova!=mat.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna");
    if(v.size()==0) {
       auto m3(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
        for(int i=0; i<m3.br_redova;i++)
        for(int j=0; j<m3.br_kolona;j++)
            m3.elementi[i][j]=0;
            return m3;
    }
    Matrica<TipElemenata> vrati(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i=0; i<mat.br_redova;i++)
    for(int j=0; j<mat.br_kolona;j++) vrati.elementi[i][j]=0;
    //ova jedinicna je samo na pocetku jednicna a kasnije sluzi da se matrica mnozi sa samom sobom
    //pravim jedinucnu
    auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i=0; i<jedinicna.br_redova;i++){
        for(int j=0; j<jedinicna.br_kolona;j++){
            if(i==j) jedinicna.elementi[i][j]=1;
            else jedinicna.elementi[i][j]=0;
        }
    }
    
    
    
    for(int i=0; i<v.size(); i++){
        if(i!=0){//znaci nije prvi element pa matricu A dizemo na visi stepen svakim prolazom, prvi put je samo pomnozimo sa jedinicnom, a ostalih puta sa samom sobom
            
            auto pom=(ProduktMatrica<TipElemenata>(jedinicna,mat));//ovo dodala
            UnistiMatricu(jedinicna);
            jedinicna=StvoriMatricu<TipElemenata>(pom.br_redova,pom.br_kolona);
            for(int h=0; h<pom.br_redova;h++)
            for(int g=0; g<pom.br_kolona;g++)
            jedinicna.elementi[h][g]=pom.elementi[h][g];
            UnistiMatricu(pom);
           
        }
        Matrica<TipElemenata> nova(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));//jedinicna.br
        for(int j=0; j<jedinicna.br_redova; j++)
        for(int k=0; k<jedinicna.br_kolona;k++)
        nova.elementi[j][k]=v[i]*jedinicna.elementi[j][k];
        
        
        auto pom=ZbirMatrica(vrati,nova);
        UnistiMatricu(nova);
        for(int h=0; h<pom.br_redova;h++)
            for(int g=0; g<pom.br_kolona;g++)
            vrati.elementi[h][g]=pom.elementi[h][g];
            UnistiMatricu(pom);
        
       
    }
    
    UnistiMatricu(jedinicna);
    return vrati;
    

}
int main ()
{
    Matrica<double> a,b;
    int m,n;
    std::vector<double> v;
    double pom;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a=StvoriMatricu<double>(m,m);
      
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<=n;i++){
            
            std::cin>>pom;
            v.push_back(pom);
        }
        b=MatricniPolinom<double>(a,v);
        IspisiMatricu(b,10);
        
    }
    catch(std::exception e){
        std::cout<<e.what();
        
    }
    UnistiMatricu(a);UnistiMatricu(b);
	return 0;
}