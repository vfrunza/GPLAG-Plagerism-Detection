#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<double>> matrica;
matrica horizontalna(matrica m){
    double b,x;
    matrica v=m;
    for(int i=0; i<v.size(); i++){
        b=v[i].size()-1;
        for(int j=0; j<b; j++){
            for(int z=b; z>j; z--){
                x=v[i][j];
                v[i][j]=v[i][z];
                v[i][z]=x;
                b--;
                break;
            }
            
        }
    }
    return v;
}
matrica vertikalna(matrica m){
    matrica v=m;
    std::vector<double> temp;
    int h=v.size()-1;
    for(int i=0; i<h; i++){
        for(int j=h; j>i; j--){
            temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            h--;
            break;
        }
    }
    return v;
}
matrica hv(matrica m){
    matrica v=m;
    matrica a;
    a=vertikalna(v);
    a=horizontalna(a);
    return a;
}
matrica OgledaloMatrica( matrica m){
    int a,b(0),c(0);
    matrica original=m;
    a=m.size();
    if(a<0) throw std::domain_error("Matrica nije korektna");
    matrica konacna(3*a);
    if(a==0 || m[0].size()==0) return konacna;
    std::vector<double>glavni[10];
    std::vector<double>gornji[10];
    std::vector<double>donji[10];
    std::vector<double>zadnji[10];
    std::vector<double>zavrsni[10];
    std::vector<double>drugi[10];
    for(int i=0; i<m.size(); i++){
    int d=m[0].size();
    if(d!=m[i].size()) throw std::domain_error("Matrica nije korektna");
    }
    for(int i=0; i<original.size(); i++){
        for(int j=0; j<original[i].size(); j++){
            glavni[i].push_back(original[i][j]);
        }
    }
    original=hv(m);
    for(int i=0; i<original.size(); i++){
        for(int j=0; j<original[i].size(); j++){
            gornji[i].push_back(original[i][j]);
        }
    }
    original=vertikalna(m);
    for(int i=0; i<original.size(); i++){
        for(int j=0; j<original[i].size(); j++){
            donji[i].push_back(original[i][j]);
        }
    }
    original=horizontalna(m);
for(int i=0; i<original.size(); i++){
        for(int j=0; j<original[i].size(); j++){
            zadnji[i].push_back(original[i][j]);
        }
    }  
 for(int i=0; i<m.size(); i++){
     for(int j=0; j<m[i].size(); j++){
         zavrsni[i].push_back((gornji[i])[j]);
     }
 }   
    for(int i=0; i<m.size(); i++){
     for(int j=0; j<m[i].size(); j++){
         zavrsni[i].push_back((donji[i])[j]);
     }
 }   
 for(int i=0; i<m.size(); i++){
     for(int j=0; j<m[i].size(); j++){
         zavrsni[i].push_back((gornji[i])[j]);
     }
 } 
 for(int i=0; i<m.size(); i++){
     for(int j=0; j<m[i].size(); j++){
         drugi[i].push_back((zadnji[i])[j]);
     }
 }   
 for(int i=0; i<m.size(); i++){
     for(int j=0; j<m[i].size(); j++){
         drugi[i].push_back((glavni[i])[j]);
     }
 } 
 for(int i=0; i<m.size(); i++){
     for(int j=0; j<m[i].size(); j++){
         drugi[i].push_back((zadnji[i])[j]);
     }
 }   
 for(int i=0; i<3*a; i++){
     if(i<a){
     konacna[i]=zavrsni[i];
     } else if(i>=a && i<2*a){
         
         for(int j=b; j<a; j++){
             konacna[i]=drugi[j];
             b++;
             break;
         }
     } else if(i>=2*a && i<3*a){
          for(int j=c; j<a; j++){
             konacna[i]=zavrsni[j];
             c++;
             break;
         }
     }    
 }
 return konacna;
}

int main ()
{
    int m,n;
    try{
 std::cout<<"Unesite dimenzije matrice (m n): ";
 std::cin>>m>>n;
 if(m<0 || n<0){
     std::cout<<"Dimenzije matrice moraju biti nenegativne!";
     return 0;
 }
 matrica ispis;
 matrica prva(m,std::vector<double>(n));
 std::cout<<"Unesite elemente matrice: ";
 for(int i=0; i<m; i++){
     for(int j=0; j<n; j++){
         std::cin>>prva[i][j];
     }
 }
 
 std::cout<<std::endl;
 ispis=OgledaloMatrica(prva);
 std::cout<<"Rezultantna matrica: ";
 std::cout<<std::endl;
 for(int i=0; i<ispis.size(); i++){
     for(int j=0; j<ispis[i].size(); j++){
         std::cout<<std::setw(4)<<ispis[i][j];
     }
     std::cout<<std::endl;
 }
 
    } catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}