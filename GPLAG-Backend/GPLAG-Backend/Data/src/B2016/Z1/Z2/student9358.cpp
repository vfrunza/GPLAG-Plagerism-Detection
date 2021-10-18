/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica mat){
  Matrica novamat;
  for(int i=0;i<mat.size();i++){
      if(mat[0].size()!=mat[i].size()) throw std::domain_error("Matrica nije korektna");   //provjeravanje je li matrica "grbava"
  }
  novamat.resize(3*mat.size());
  for(int i=0;i<3*mat.size();i++){                                                            
      novamat[i].resize(3*(mat[0].size()));
  }
  for(int i=0;i<mat.size();i++){                              //prvih m redova//
    for(int a=0;a<mat[0].size();a++){
        novamat[i][a]=mat[mat.size()-(1+i)][mat[0].size()-1-a];
    }
    for(int a=0;a<mat[0].size();a++){
        novamat[i][mat[0].size()+a]=mat[mat.size()-(1+i)][a];
    }
    for(int a=0;a<mat[0].size();a++){
        novamat[i][2*mat[0].size()+a]=mat[mat.size()-(1+i)][mat[0].size()-1-a];
    }
  }
  
  for(int i=0;i<mat.size();i++){                               //drugih m redova//
    for(int a=0;a<mat[0].size();a++){
        novamat[mat.size()+i][a]=mat[i][mat[0].size()-1-a];
    }
    for(int a=0;a<mat[0].size();a++){
        novamat[mat.size()+i][mat[0].size()+a]=mat[i][a];
    }
    for(int a=0;a<mat[0].size();a++){
        novamat[mat.size()+i][2*mat[0].size()+a]=mat[i][mat[0].size()-1-a];
    }
  } 
  
  for(int i=0;i<mat.size();i++){                                    //trecih m redova//
     for(int a=0;a<mat[0].size();a++){
        novamat[2*(mat.size())+i][a]=mat[mat.size()-(1+i)][mat[0].size()-1-a];
     }
     for(int a=0;a<mat[0].size();a++){
        novamat[2*(mat.size())+i][mat[0].size()+a]=mat[mat.size()-(1+i)][a];
     }
     for(int a=0;a<mat[0].size();a++){
        novamat[2*(mat.size())+i][2*(mat[0].size())+a]=mat[mat.size()-(1+i)][mat[0].size()-1-a];
     }
  }
  
  return novamat;
}

int main ()
{   int m,n;
    Matrica mat;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    if(m<0 || n<0) {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;
    }
    mat.resize(m);
    for(int i=0;i<m;i++){
        mat[i].resize(n);
    }
    std::cout<<"Unesite elemente matrice: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            std::cin>>mat[i][j];
        }
    }
    try{
        Matrica novamat=OgledaloMatrica(mat);
        std::cout<<std::endl;
        std::cout<<"Rezultantna matrica: ";
        std::cout<<std::endl;
        for(int i=0;i<3*m;i++){
            for(int j=0;j<3*n;j++){
            std::cout<<std::setw(4)<<novamat[i][j];
            }
        std::cout<<std::endl;
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    
    
	return 0;
}