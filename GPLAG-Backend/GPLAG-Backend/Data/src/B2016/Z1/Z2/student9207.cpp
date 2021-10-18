//B 2016/2017, Zadaća 1, Zadatak 2
#include <vector>
#include <iostream>
#include<ostream>
#include<iomanip>
#include<stdexcept>
typedef std::vector<std::vector<double> > Matrica;
Matrica(KreirajMatricu(int br_redova,int br_kolona))
{
    //if( br_redova==0 || br_kolona==0 ) return Matrica(0,std::vector<double>(0));
   return Matrica(br_redova,std::vector<double>(br_kolona));
}

int BrojRedova(Matrica m)
{
    return(m.size());
}

int BrojKolona(Matrica m)
{
    if(m.size()==0 ) return 0;
    else return(m[0].size());
}

void IspisiMatricu(Matrica m){
    for(int i=0; i<BrojRedova(m); i++) {
        for(int j=0; j<BrojKolona(m); j++) {
            std::cout<<std::setw(4)<<m[i][j];
        }
        std::cout<<std::endl;
    }
}
Matrica Unesimatricu(int br_redova,int br_kolona)
{
    auto m(KreirajMatricu(br_redova,br_kolona));
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) {
            std::cin>>m[i][j];
        }
    }
    return m;
}

Matrica Horizontalnoogledalo(Matrica m)
{
    Matrica ogledalo(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
    for(int i=0; i<BrojRedova(m); i++) {
        for(int j=0; j<BrojKolona(m); j++)
            ogledalo[i][j]=m[i][BrojKolona(m)-j-1];
    }

    return ogledalo;
}

Matrica Vertikalnoogledalo(Matrica m)
{
    Matrica ogledalo(KreirajMatricu(BrojRedova(m),BrojKolona(m) ));
    for(int i=0; i<BrojRedova(m); i++) {
        for(int j=0; j<BrojKolona(m); j++)
            ogledalo[i][j]=m[BrojRedova(m)-i-1][j];
    }
    return ogledalo;

}
Matrica Kombinovanoogledalo(Matrica m)
{
    Matrica ogledalo(KreirajMatricu(BrojRedova(m),BrojKolona(m) ));
    for(int i=0; i<BrojRedova(m); i++) {
        for(int j=0; j<BrojKolona(m); j++)
            ogledalo[i][j]=m[BrojRedova(m)-i-1][BrojKolona(m)-j-1];
    }
    return ogledalo;
}

Matrica OgledaloMatrica (Matrica m){
    Matrica mat(3*BrojRedova(m),std::vector<double>(0));
         int i;
        for( i=0; i<BrojRedova(m); i++) {
                for(int k=0; k<BrojKolona(m); k++) {
                    mat[i].push_back(Kombinovanoogledalo(m)[i][k]);
                }
                for(int k=0; k<BrojKolona(m); k++) {
                    mat[i].push_back(Vertikalnoogledalo(m)[i][k]);
                }
                for(int k=0; k<BrojKolona(m); k++) {
                    mat[i].push_back(Kombinovanoogledalo(m)[i][k]);
                }
            }
           i=0;
          for(int j=BrojRedova(m);j<2*BrojRedova(m);j++) {
                  for(int k=0; k<BrojKolona(m); k++) {
                      mat[j].push_back(Horizontalnoogledalo(m)[i][k]);
                  }
                  for(int k=0; k<BrojKolona(m); k++) {
                        mat[j].push_back(m[i][k]);
                  }
                 for(int k=0; k<BrojKolona(m); k++) {
                    mat[j].push_back(Horizontalnoogledalo(m)[i][k]);
                 }
                 i++;
             }
          i=0;
            for(int s=2*BrojRedova(m); s<3*BrojRedova(m); s++) {
                for(int k=0; k<BrojKolona(m); k++) {
                    mat[s].push_back(Kombinovanoogledalo(m)[i][k]);
                }
                for(int k=0; k<BrojKolona(m); k++) {
                    mat[s].push_back(Vertikalnoogledalo(m)[i][k]);
                }
                for(int k=0; k<BrojKolona(m); k++) {
                    mat[s].push_back(Kombinovanoogledalo(m)[i][k]);
                }
                i++;
            }
    return mat;
}
/*

typedef std::vector<std::vector<Matrica>> MatricaMatricA;
MatricaMatricA OgledaloMatrica (Matrica m){
//    auto rez=KreirajMatricu(3*BrojRedova(m),3*BrojKolona(m));
 MatricaMatricA ogl(3,std::vector<Matrica>(3,Matrica(3*BrojRedova(m),std::vector<double>(3*BrojKolona(m)))));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if((i==0 ||i==2) && (j==0 || j==2)) ogl[i][j]=Kombinovanoogledalo(m);
            else if(i==1 && j==0 || j==2) ogl[i][j]=Horizontalnoogledalo(m);
            else if((i==0 || i==2) && j==1) ogl[i][j]=Vertikalnoogledalo(m);
            else ogl[i][j]=m;
        }
    }

    return ogl;
}
*/
int main ()
{
    int a,b;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>a>>b;
    if(a<0 || b<0) {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }

    std::cout<<"Unesite elemente matrice: \n";
    auto m=Unesimatricu(a,b);
    auto ogl=OgledaloMatrica(m);
    std::cout<<"Rezultantna matrica: \n";
   IspisiMatricu(ogl);
   /* for(int i=0;i<3;i++){
      for(int k=0;k<BrojRedova(ogl[0][0]);k++){
       for(int j=0;j<3;j++){
               for(int  m=0;m<BrojKolona(ogl[0][0]);m++){
                   auto a =ogl[i][j];
                   std::cout<<std::setw(4)<<a[k][m];
               }
           }
           std::cout<<std::endl;

       }

    }*/


    return 0;
}
