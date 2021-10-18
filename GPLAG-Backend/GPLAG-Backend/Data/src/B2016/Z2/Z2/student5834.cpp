// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<deque>
#include<string>
#include<stdexcept>
enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename tipmat>
auto dijagonala(tipmat mat)->typename std::remove_reference<decltype (mat[0])>::type{
    int k=0,n=1;
    typename std::remove_reference<decltype (mat[0])>::type rez;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            for(int l=0;l<mat[i][j].size();l++){
                if(j==l){
                    rez.resize(n);
                    rez[k].push_back(mat[i][j][l]);
                }
                    
            }
        }
        k++;n++;
    }
    return rez;
}
template <typename tipmat>
auto dijagonalaDLLD(tipmat mat)->typename std::remove_reference<decltype (mat[0])>::type{
    typename std::remove_reference<decltype (mat[0])>::type rez;
    rez.resize(mat[0][0].size());
    if(mat.size()<mat[0].size())
        for(int i=0;i<mat[0][0].size();i++)
            rez[i].resize(mat.size());
    else 
        for(int i=0;i<mat[0][0].size();i++)
            rez[i].resize(mat[0].size());
    int n=0;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            int k=0;
            for(int l=mat[i][j].size()-1;l>=0;l--){
                if(i==j){
                    rez[k][n]=mat[i][j][l];
                }
                k++;
            }
        }
        n++;
    }
    return rez;
}
template <typename tipmat>
auto dijagonalaGDDG(tipmat mat)->typename std::remove_reference<decltype (mat[0])>::type {
    typename std::remove_reference<decltype (mat[0])>::type rez;
    rez.resize(mat[0].size());
        if(mat.size()<mat[0][0].size())
            for(int i=0;i<mat[0].size();i++)
                rez[i].resize(mat.size());
        else 
            for(int i=0;i<mat[0].size();i++)
                rez[i].resize(mat[0][0].size());
        int n=0;
        for(int i=0;i<mat.size();i++){
             int k=0;
            for(int j=0;j<mat[i].size();j++){
                for(int l=0;l<mat[i][j].size();l++){
                    if(i==l){
                        rez[k][n]=mat[i][j][l];
                    }
                }
            k++;
            }
        n++;
        }
        return rez;
}
template <typename tipmat>
auto IzdvojiDijagonale3D(tipmat mat,SmjerKretanja pozicija)->typename std::remove_reference<decltype (mat[0])>::type
{
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size()-1;j++){
            for(int k=j+1;k<mat[0].size();k++){
                if(mat[i][j].size()!=mat[i][k].size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
            }
        }
    }
    for(int i=0;i<mat.size()-1;i++){
        for(int j=i+1;j<mat.size();j++){
            if(mat[i][0].size()!=mat[j][0].size()) throw std::domain_error("Plohe nemaju isti broj redova");
        }
    }
    typename std::remove_reference<decltype (mat[0])>::type rez;
    //NAPRIJED NAZAD
    if(int(pozicija)==0){
     rez=dijagonala(mat);
    }
    //NAZAD NAPRIJED 
    if(int(pozicija)==1){
     for(int i=0;i<mat.size();i++)
        for(int j=0;j<mat[i].size();j++)
            for(int l=0;l<mat[i][j].size()/2;l++)
                std::swap(mat[i][j][l],mat[i][j][mat[i][j].size()-l-1]);
      for(int i=0;i<mat.size()/2;i++)
        std::swap(mat[i],mat[mat.size()-1-i]);
     rez=dijagonala(mat);
    }
    //DESNO LIJEVO
    if(int(pozicija)==5){
        rez=dijagonalaDLLD(mat);
    }

    //LIJEVO DESNO
    if(int(pozicija)==4){
        rez.resize(mat[0][0].size());
    if(mat.size()<mat[0].size())
        {
            for(int i=0;i<mat[0][0].size();i++)
            rez[i].resize(mat.size());
        }
    else 
       {
           for(int i=0;i<mat[0][0].size();i++)
            rez[i].resize(mat[0].size());
           
       }
        int n=0;
    for(int i=mat.size()-1;i>=0;i--){
        for(int j=0;j<mat[i].size();j++){
            int k=0;
            for(int l=0;l<mat[i][j].size();l++){
                if(j==mat.size()-i-1){
                     rez[k][n]=mat[i][j][l];
                }
                k++;  
            }
         }
        n++;
    }
    }
    //GORE DOLE
    if(int(pozicija)==2){
        for(int i=0;i<mat.size()/2;i++)
            std::swap(mat[i],mat[mat.size()-1-i]);
        rez=dijagonalaGDDG(mat);
    }
    //DOLE GORE
    if(int(pozicija)==3){
        for(int i=0;i<mat.size()/2;i++)
            std::swap(mat[i],mat[mat.size()-1-i]);
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[i].size()/2;j++)
                std::swap(mat[i][j],mat[i][mat[i].size()-1-j]);
        for(int i=0;i<mat.size();i++)
           for(int j=0;j<mat[i].size();j++)
                for(int l=0;l<mat[i][j].size()/2;l++)
                    std::swap(mat[i][j][l],mat[i][j][mat[i][j].size()-l-1]);
        rez=dijagonalaGDDG(mat);
    }
    
    
    return rez;

}
int main ()
{
    std::cout<<"Unesite dimenzije (x y z): ";
    int m,n,k;
    std::cin>>m;
    std::cin>>n;
    std::cin>>k;
    if(k<=0 || n<=0 || m<=0){
        std::cout << "Neispravne dimenzije kontejnera!" ;
        return 0;
    }
    std::vector<std::vector<std::vector<int> > > mat;
    mat.resize(m);
    for(int i=0;i<m;i++) {
        mat[i].resize(n);
        for(int j=0;j<n;j++)
            mat[i][j].resize(k);
    }
    std::cout<<"Unesite elemente kontejnera:";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            for(int l=0;l<k;l++){
                std::cin>>mat[i][j][l];
            }
    }

    std::cout  << std::endl;
    std::cout << "Unesite smjer kretanja [0 - 5]: " ;
    int e;
    std::cin>>e;
    if(e>=6 || e<0){
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        return 0;
    }
  
    SmjerKretanja poz;
    poz=SmjerKretanja(e);
    try{
    std::vector<std::vector<int> > rez=IzdvojiDijagonale3D(mat,poz);
    if(e==0)
        std::cout <<"NaprijedNazad: " << std::endl;
    if(e==1)
        std::cout <<"NazadNaprijed: " << std::endl;
    if(e==2)
        std::cout <<"GoreDolje: " << std::endl;
    if(e==3)
        std::cout <<"DoljeGore: " << std::endl;
    if(e==4)
        std::cout <<"LijevoDesno: " << std::endl;
    if(e==5)
        std::cout <<"DesnoLijevo: " << std::endl;
    for(int i=0;i<rez.size();i++){
        for(int j=0;j<rez[i].size();j++)
            std::cout<<std::setw(4)<<rez[i][j];
        std::cout << std::endl;
    }
}
catch (std::domain_error x){
    std::cout<<x.what();
}
	return 0;
}