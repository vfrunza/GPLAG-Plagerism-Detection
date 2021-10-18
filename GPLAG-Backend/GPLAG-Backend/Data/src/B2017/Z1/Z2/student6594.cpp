#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;
typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<int> vektor;
/*
bool JeLiGrbava(Matrica m){
     if(m.size()!=0){
     for(int i=0;i<m.size();i++){
          for(int j=0;j<m.at(i).size();j++){
               for(int k=j+1;k<m.at(i).size();k++){
                    if(!(m.at(k).size()==m.at(j).size()))
                    return false;
               }
          }
     }
     
     return true;
     }
}
/*

Matrica KreirajMatricu(int br_redova, int br_kolona){
     return Matrica(br_redova,std::vector<int>(br_kolona));
     
} */

/*

int BrojKolona(Matrica m){
     return m[0].size();
}
int BrojRedova(Matrica m){
     return m.size();
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> m){
     int i,j,k,l;
     int reovi;
     int kolo;
     if(mat.size() != mat[0].size())
       mat.size() = mat[0].size();
     int final_dim1=m.size();
     int final_dim2=0;
     int final_dim3=m[0].size();
     int final_dim4=0;
     int brojac(0);
     int suma1(0);
     int new_suma(0);
     int vrh=0;
          int k(0);
          while(k<m.size()/2){
     for(i=0;i<m.size();i++){
          for(j=0;j<m[i].size();j++){
               if(i==0 || j==0 || i==m.size()-1 || j==m[i].size()-1)
                         {
                              continue;
                         }
               else {
              int old_suma=m[i][j];
                    int dim1=i-k;
                    int dim2=i+k;
                    int dim3=j-k;
                    int dim4=j+k;
                    for(k=dim1;k<=dim2;k++){
                         for(l=dim3;l<=dim4;l++){
                             new_suma=new_suma+m[k][l]-m[i][j];
                         }
                    }

                         if(new_suma<old_suma){
                              new_suma=old_suma;
                            
                             vrh=m[i][j];
                             reovi=i;
                             kolone=j;
                             
                             
                    }
                    else break;
                    /*if(brojac!=0 && dim1<=final_dim1 && dim2>=final_dim2 && 
                    dim3<=final_dim3 && dim4>=final_dim4 &&
                    (dim2-dim1)%2==0 && (dim4-dim3)%2==0){
                         final_dim4=dim4;
                         final_dim3=dim3;
                         final_dim2=dim2;
                         final_dim1=dim1;
                    }
                         }
                         
                    }
                    
     }*//*
               k++;
          }
              // int red=final_dim2-final_dim1;
              // int kolona=final_dim4-final_dim3;
              int a(0);
              std::vector<std::vector<double>> rez(reovi, std::vector<double> ());
             for(i=reovi;i<=final_dim2;i++){
                    for(j=final_dim3;j<=final_dim4;j++){

                rez[a].push_back(m[i][j]);
                                   }
                    a++;
                          }
                    
               std::cout<<final_dim4<<", "<<final_dim3<<", "<<final_dim2<<", "<<final_dim1<<std::endl;
               

                         
                         return rez;

          }
     
     
     



*/
int max(std::vector<std::vector<double>> m){
     int maxi=m.at(0).at(0);
     for(int i=0;i<m.size();i++){
          for(int j=0;j<m.at(i).size();j++){
               if(m.at(i).at(j)>maxi) maxi=m.at(i).at(j);
          }
     }
     return maxi;
}

bool provjera(std::vector<std::vector<double>> m, int size, int i, int j){
     int brojac(1);
     double old_suma=m.at(i).at(j);
     while(brojac<=size/2){
          int dim1=i-brojac;
          
          int dim2=i+brojac;
         
          int dim3=j-brojac;
         
          int dim4=j+brojac;
         
          double new_suma(0);
          for(int k=dim1;k<=dim2;k++){
               for(int l=dim3;l<=dim4;l++){
                    if(j!=dim3 || j!=dim4) continue;
                    new_suma+=m.at(k).at(l);
               }
          }
          if(new_suma> old_suma) return 0;
         
          new_suma=old_suma;
          
          
          brojac++;
     }
     return 1;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> m){
   int vel=m.at(0).size();
     for(int i=0;i<m.size();i++)
     if(m.at(i).size()!=vel) throw domain_error("Matrica nije korektna");
   
   //  if( m.size()==0 || m[0].size()==0){

   //  }

      /* if(m.size()!=0){
        for(int q=0;q<m.size();q++){
               for(int p=0;p<m.at(q).size()-1;p++){
                   for(int w=p+1;w<m.at(q).size();w++){
                         if(m.at(p).size()!=m.at(w).size()) {
                              throw std::domain_error("Matrica nije korektna");
                         }
                    }
               }
              }
       }
         
         /*int visina(m.size()), sirina(0);
         for(int i=0;i<m.size()-1;i++){
              if(Sirina(m,i)!=Sirina(m,i+1)) throw domain_error("Matrica nije korektna");
         }*/
         
        // if(JeLiGrbava(m)) throw std::domain_error("Matrica nije korektna");

     int dim1;
     int dim2;
     int dim3;
     int dim4;
     int final_red(0);
     int final_kolona(0);
     int dim,i,j;
     if(m.size()!=0 && m.size()>m.at(0).size())
     
     dim=m.at(0).size(); else dim=m.size();
     
     //for(dim;dim>2;dim--)
     while(dim>2){    
         
         
          for(i=0;i<m.size();i++){
             
             
               for(j=0;j<m.at(i).size();j++){
                         
                         
                         
                           if(i+dim/2>=m.size() || i-dim/2<0 || j+dim/2>m.at(0).size() || j-dim/2<0) 
                    {
                         continue;
                    }
                    if(provjera(m,dim,i,j)){
                         if(!final_red){
                              final_red=i;
                              final_kolona=j;
                         }else {
                         if(m.at(i).at(j)>m.at(final_red).at(final_kolona)){
                         final_red=i;
                         final_kolona=j;
                         }
                         else if(m.at(i).at(j)==m.at(final_red).at(final_kolona)){
                              if(i<final_red){
                                   final_red=i;
                                   final_kolona=j;
                              }
                              else if(i==final_red){
                                   if(j<final_kolona){
                                        final_kolona=j;
                                        final_red=i;
                                   }
                              }
                         }
                              
                       }
                         
                    }
               }
          }
          
          
          if(final_red!=0) break;
          dim--;
     }
     int k(0);
      dim1=final_red-dim/2;
      dim2=final_red+dim/2;
      dim3=final_kolona-dim/2;
      dim4=final_kolona+dim/2;
     
     Matrica rezultat(dim,std::vector<double>());
     for(int l=dim1;l<=dim2;l++){
          for(int p=dim3;p<=dim4;p++){
               rezultat.at(k).push_back(m.at(l).at(p));
               
          }
          k++;
     }
          return rezultat;
     
}


int main(){
 
     int m,n;
     std::cout<<"Unesite dimenzije matrice (m i n): ";
     std::cin>>m>>n;
     if(m<0 || n<0) {
          std::cout<<"Dimenzije matrice moraju biti nenegativne!";
          return 0;
          std::cin.ignore(1000,'\n');
     }
     
     Matrica mat;
     std::vector<std::vector<double>> o(m,std::vector<double> (n));
     std::cout<<"Unesite elemente matrice: ";
     for(int i=0;i<o.size();i++){
          for(int j=0;j<o.at(i).size();j++){
               std::cin>>o.at(i).at(j);
          }
     }
     std::cout<<std::endl;
   try {
     mat=NajvecaPlaninaMatrice(o);
std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
for(int i=0;i<mat.size();i++){
          for(int j=0;j<mat.at(i).size();j++){
                std::cout<<std::setw(6)<< mat.at(i).at(j) << "";
          }    
     std::cout<<std::endl;
     
     }
} catch(std::domain_error izuzetak){
     std::cout<<izuzetak.what();
     
}
     return 0;
     
}

