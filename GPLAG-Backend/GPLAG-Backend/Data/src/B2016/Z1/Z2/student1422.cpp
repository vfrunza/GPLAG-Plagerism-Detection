#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> Vektor;

Matrica KreirajMatricu(int broj_redova, int broj_kolona){
    return Matrica(broj_redova, std::vector<double>(broj_kolona));
}

int BrojRedova(Matrica M){
    return M.size();
}

int BrojKolona(Matrica M){
    if(M.size()==0) return 0;
    return M[0].size();
}

Matrica UnesiMatricu(int m, int n){
    auto M(KreirajMatricu(m,n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            std::cin>>M[i][j];
        }
    }
    return M;
}

void IspisiMatricu(Matrica M){
    for(int i=0; i<BrojRedova(M);i++) {
        for(int j=0; j<BrojKolona(M);j++)
            std::cout<<std::setw(4)<<M[i][j];
            std::cout<<std::endl;
    }
}

Matrica HorizontalnoOgledalo(Matrica M){
    int m(BrojRedova(M)),n(BrojKolona(M));
    auto nova(KreirajMatricu(m,n));
    int k(0),l(0);
    for(int i=0;i<m;i++){
        l=0;
        for(int j=n-1;j>=0;j--){
            nova[k][l]=M[i][j];
            l++;
        }
        k++;
    }
    return nova;
}

Matrica VertikalnoOgledalo(Matrica M){
    int m(BrojRedova(M)),n(BrojKolona(M));
    auto nova(KreirajMatricu(m,n));
    int k(0),l(0);
    for(int i=m-1;i>=0;i--){
        l=0;
        for(int j=0;j<n;j++){
            nova[k][l]=M[i][j];
            l++;
        }
        k++;
    }
    return nova;
}

Matrica KombinovanoOgledalo(Matrica M){
    int m(BrojRedova(M)),n(BrojKolona(M));
    auto nova1(KreirajMatricu(m,n)), nova2(KreirajMatricu(m,n));
    nova1=HorizontalnoOgledalo(M);
    nova2=VertikalnoOgledalo(nova1);
    return nova2;
}

bool DaLiJeGrbava(Matrica M){
    int m(M[0].size());
    for(int i=1;i<M.size();i++){
        if(M[i].size()!=m)
        return true;
    }
    return false;
}

Matrica OgledaloMatrica(Matrica M){
    int m(BrojRedova(M)),n(BrojKolona(M));
    auto konacna(KreirajMatricu(3*m,3*n));
    if (m==0 && n==0) return konacna;
    else if(m==0) return(KreirajMatricu(0,3*m));
    else if(n==0) return(KreirajMatricu(3*m,0));
    else if(DaLiJeGrbava(M)) throw std::domain_error("Matrica nije korektna");
    auto pom1(HorizontalnoOgledalo(M));
    auto pom2(VertikalnoOgledalo(M));
    auto pom3(KombinovanoOgledalo(M));
    //prvih m redova i n kolona - ok
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            konacna[i][j]=pom3[i][j];
            
            //drugih m redova i n kolona -ok
    int k(0);
    for(int i=m;i<2*m;i++){
    int j(0),l(0);
    do{
        konacna[i][j]=pom1[k][l];
        j++;
        l++;
    }while(j<n && l<n);
    k++;
    }
       
        //posljednjih m redova i n kolona
        k=0;
    for(int i=2*m;i<3*m;i++){
    int j(0),l(0);
    do{
        konacna[i][j]=pom3[k][l];
        j++;
        l++;
    }while(j<n && l<n);
    k++;
    }
        
        //sredina
        k=0;
    for(int i=0;i<m;i++){
    int j(n),l(0);
    do{
        konacna[i][j]=pom2[k][l];
        j++;
        l++;
    }while(j<2*n && l<n);
    k++;
    }
    
    k=0;
    for(int i=m;i<2*m;i++){
    int j(n),l(0);
    do{
        konacna[i][j]=M[k][l];
        j++;
        l++;
    }while(j<2*n && l<n);
    k++;
    }
    
    k=0;
    for(int i=2*m;i<3*m;i++){
    int j(n),l(0);
    do{
        konacna[i][j]=pom2[k][l];
        j++;
        l++;
    }while(j<2*n && l<n);
    k++;
    }
    
    //posljednje kolone
    k=0;
    for(int i=0;i<m;i++){
    int j(2*n),l(0);
    do{
        konacna[i][j]=pom3[k][l];
        j++;
        l++;
    }while(j<3*n && l<n);
    k++;
    }
    
    k=0;
    for(int i=m;i<2*m;i++){
    int j(2*n),l(0);
    do{
        konacna[i][j]=pom1[k][l];
        j++;
        l++;
    }while(j<3*n && l<n);
    k++;
    }
    
    k=0;
    for(int i=2*m;i<3*m;i++){
    int j(2*n),l(0);
    do{
        konacna[i][j]=pom3[k][l];
        j++;
        l++;
    }while(j<3*n && l<n);
    k++;
    }
    
    return konacna;
}

int main(){
    int m,n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    do{
    std::cin>>m>>n;
    if(m>=0 && n>=0) break;
    else if(m<0 || n<0){
    std::cout<<"Dimenzije matrice moraju biti nenegativne!";
    return 0;
    }
    }while(1);
    std::cout<<"Unesite elemente matrice: "<<std::endl;
    auto M(UnesiMatricu(m,n));
    try{
    std::cout<<"Rezultantna matrica: "<<std::endl;
    auto kon(OgledaloMatrica(M));
    IspisiMatricu(kon);
    } 
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}