#include<iostream>
#include<iomanip>
#include<vector>
#include<stdexcept>
typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int br_redova,int br_kolona){
    return Matrica(br_redova,std::vector<double>(br_kolona));}
    
 Matrica UnesiMatricu(int br_redova,int br_kolona){
     auto m(KreirajMatricu(br_redova,br_kolona));
     for(int i=0;i<br_redova;i++){
         for(int j=0;j<br_kolona;j++){
            std::cin>>m[i][j];
         }
     }
     return m;
 }   
 void IspisiMatricu(Matrica m){
     for(std::vector<double>red:m){
         for(double x:red) std::cout<<std::setw(4)<<x;
         std::cout<<std::endl;
     }
 }
 
 Matrica HorizontalnaMatrica(Matrica m){
     double pomocni;
     for(int i=0;i<m[0].size()/2;i++){
         for(int j=0;j<m.size();j++){
             pomocni=std::move(m[j][i]);
             m[j][i]=std::move(m[j][m[0].size()-1-i]);
             m[j][m[0].size()-1-i]=std::move(pomocni);
         }
     }
     return m;
 }
 
 Matrica VertikalnaMatrica(Matrica m){
     std::vector<double>pomocni;
     for(int j=0;j<m.size()/2;j++){
         pomocni=std::move(m[j]);
         m[j]=std::move(m[m.size()-1-j]);
         m[m.size()-1-j]=std::move(pomocni);
         
     }
     return m;
 }
 Matrica VHMatrica(Matrica m){
     m=VertikalnaMatrica(m);
     m=HorizontalnaMatrica(m);
     return m;
 }
 
 Matrica OgledaloMatrica(Matrica m){
     for(int i=0;i<m.size();i++){
         if(m[0].size()!=m[i].size())
         throw std::domain_error("Matrica nije korektna");
     }
     if(m.size()==0)
     return m;
     Matrica OM(3*m.size(),std::vector<double>(3*m[0].size()));
     Matrica h=HorizontalnaMatrica(m);
     Matrica v=VertikalnaMatrica(m);
     Matrica hv=VHMatrica(m);
     for(int i=0;i<m.size();i++){
         for(int j=0;j<m[0].size();j++){
             OM[i][j]=std::move(hv[i][j]);
             OM[i][j+2*m[0].size()]=std::move(hv[i][j]);
             OM[i][j+m[0].size()]=std::move(v[i][j]);
             OM[i+m.size()][j]=std::move(h[i][j]);
             OM[i+m.size()][j+m[0].size()]=std::move(m[i][j]);
             OM[i+m.size()][j+2*m[0].size()]=std::move(h[i][j]);
             OM[i+2*m.size()][j]=std::move(hv[i][j]);
             OM[i+2*m.size()][j+m[0].size()]=std::move(v[i][j]);
             OM[i+2*m.size()][j+2*m[0].size()]=std::move(hv[i][j]);
         }
     }
     return OM;
 }
int main ()
{
    std::cout<<"Unesite dimenzije matrice (m n): ";
    int m,n;
    std::cin>>m>>n;
     if(m<0||n<0){
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::cout<<"Unesite elemente matrice: \n";
    Matrica M=UnesiMatricu(m,n);
    try{
    M=OgledaloMatrica(M);
    std::cout<<"Rezultantna matrica: \n";
    IspisiMatricu(M);
    }
     catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    
    
    
	return 0;
}