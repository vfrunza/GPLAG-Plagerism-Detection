#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>>Matrica;
Matrica Vertikalno(Matrica m){
    int k;
    double tmp;
    k=m.size()-1;
    for(int i=0; i<m.size()/2; i++){
        for(int j=0; j<m[0].size(); j++){
         tmp=m[i][j];
         m[i][j]=m[k][j];
         m[k][j]=tmp;
        }
        k--;
    }
    return m;
}
Matrica Horizontalno(Matrica m){
 int k;
 double tmp;
 for(int i=0; i<m.size(); i++){
     k=m[0].size()-1;
     for(int j=0; j<m[0].size()/2; j++){
      tmp=m[i][j];
      m[i][j]=m[i][k];
      m[i][k]=tmp;
      k--;
     }
 } 
 return m;
}
Matrica OgledaloMatrica(Matrica m){
    int kolona;
    if(m.size()==0) return m;
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[0].size(); j++){
            if(j==0) kolona=m[0].size();
            if(m[i].size()==kolona){}
            else throw std::domain_error("Matrica nije korektna");
        }
    }
    Matrica h{Horizontalno(m)};
    Matrica v{Vertikalno(m)};
    Matrica hv{Horizontalno(v)};
    Matrica s;
    int dim{0};
    dim=3*m.size();
    s.resize(dim);
    for(int i=0; i<dim; i++) s[i].resize(3*m[0].size());
    int k{0};
    for(int i=0; i<hv.size(); i++){
        for(int j=0; j<hv[0].size(); j++){
            s[k][j]=hv[i][j];
        }
        k++;
    }
    for(int i=0; i<h.size(); i++){
        for(int j=0; j<h[0].size(); j++){
            s[k][j]=h[i][j];
        }
        k++;
    }
    for(int i=0; i<hv.size(); i++){
        for(int j=0; j<hv[0].size(); j++){
            s[k][j]=hv[i][j];
        }
        k++;
    }
    k=0;
    int l;
    for(int i=0; i<v.size(); i++){
      l=hv[0].size();    
      for(int j=0; j<v[0].size(); j++){
        s[k][l]=v[i][j];
        l++;
      }  
      k++;
    }
    for(int i=0; i<m.size(); i++){
     l=m[0].size();
     for(int j=0; j<m[0].size(); j++){
         s[k][l]=m[i][j];
         l++;
     }
     k++;
    }
    for(int i=0; i<v.size(); i++){
        l=hv[0].size();
        for(int j=0; j<v[0].size(); j++){
            s[k][l]=v[i][j];
            l++;
        }
        k++;
    }
    k=0;
    for(int i=0; i<hv.size(); i++){
        l=hv[0].size()*2;
        for(int j=0; j<hv[0].size(); j++){
            s[k][l]=hv[i][j];
            l++;
        }
        k++;
    }
    for(int i=0; i<h.size(); i++){
        l=hv[0].size()*2;
        for(int j=0; j<h[0].size(); j++){
            s[k][l]=h[i][j];
            l++;
        }
        k++;
    }
    for(int i=0; i<hv.size(); i++){
        l=hv[0].size()*2;
        for(int j=0; j<hv[0].size(); j++){
            s[k][l]=hv[i][j];
            l++;
        }
        k++;
    }
    return s;
}
Matrica KreirajMatricu(int br_redova, int br_kolona){
    return Matrica(br_redova,std::vector<double>(br_kolona));
}
Matrica UnesiMatricu(int br_redova, int br_kolona){
    auto m(KreirajMatricu(br_redova,br_kolona));
    for(int i=0; i<br_redova; i++){
        for(int j=0; j<br_kolona; j++){
            std::cin>>m[i][j];
        }
    }
    return m;
}
int main ()
{
    try{
        int m, n;
        std::cout <<"Unesite dimenzije matrice (m n): ";
        std::cin >>m>>n;
        if(m==0 && n==0){
            Matrica A;
            std::cout<<"Unesite elemente matrice: ";
            std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
            OgledaloMatrica(A);
            return 0;
        }
        if(m<0 || n<0) throw "Dimenzije matrice moraju biti nenegativne!";
        std::cout <<"Unesite elemente matrice: ";
        auto A(UnesiMatricu(m,n));
        Matrica a(OgledaloMatrica(A));
        std::cout <<std::endl<<"Rezultantna matrica:"<<std::endl;
        for(int i=0; i<a.size(); i++){
            for(int j=0; j<a[0].size(); j++){
                std::cout <<std::setw(4)<<std::right<<a[i][j];
            }
            std::cout <<std::endl;
        }
    }
    catch(std::domain_error izuzetak){
        std::cout <<izuzetak.what()<<std::endl;
    }
    catch(const char poruka[]){
        std::cout <<poruka<<std::endl;
    }
	return 0;
}