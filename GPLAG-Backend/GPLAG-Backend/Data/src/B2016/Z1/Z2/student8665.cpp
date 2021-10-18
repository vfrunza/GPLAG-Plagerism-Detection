#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>>Matrica;
Matrica OgledaloMatrica(Matrica m){
    Matrica A;
    if(m.size()==0) return A;
    //throw
    for(int i=0; i<m.size(); i++){
        if(m[0].size()!=m[i].size()) throw std::domain_error("Matrica nije korektna!");
    }
    //Horizontalno ogledalo
     Matrica h(m.size(), std::vector<double>(m[0].size()));
     if(m[0].size()==0) return A;
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[i].size(); j++){
            h[i][j] = m[i][j];
        }
    }
    int pomocna1,pomocna2,k;
    for(int i=0; i<h.size(); i++){
        k = h[0].size()-1;
        for(int j=0; j<h[i].size()-1; j++){
        	if(k>=j){
            pomocna1 = h[i][j];
            pomocna2 = h[i][k];
            h[i][k] = pomocna1;
            h[i][j] = pomocna2;
        }
        k--;
    }
 }
    //Vertikalno ogledalo
    Matrica v(m.size(), std::vector<double>(m[0].size()));
     for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[i].size(); j++){
            v[i][j] = m[i][j];
        }
    }
    int pomocna3,pomocna4,g;
    g = v.size()-1;
    for(int i=0; i<v.size()-1; i++){
        for(int j=0; j<v[i].size(); j++){
            if(g>=i){
                pomocna3 = v[i][j];
                pomocna4 = v[g][j];
                v[i][j] = pomocna4;
                v[g][j] = pomocna3;
            }
        }
        g--;
    }
  //Kombinovano ogledalo
  Matrica hv(m.size(), std::vector<double>(m[0].size()));
      for(int i=0; i<m.size(); i++){
            for(int j=0; j<m[i].size(); j++){
            hv[i][j] = m[i][j];
        }
    }
    int pomocna5,pomocna6,f;
    for(int i=0; i<hv.size(); i++){
        f = hv[0].size()-1;
        for(int j=0; j<hv[i].size()-1; j++){
        	if(f>=j){
            pomocna5 = hv[i][j];
            pomocna6 = hv[i][f];
            hv[i][f] = pomocna5;
            hv[i][j] = pomocna6;
        }
        f--;
    }
 } 
    int pomocna7,pomocna8,w;
         w = hv.size()-1;
        for(int i=0; i<hv.size()-1; i++){
            for(int j=0; j<hv[i].size(); j++){
                if(w>=i){
                pomocna7 = hv[i][j];
                pomocna8 = hv[w][j];
                hv[i][j] = pomocna8;
                hv[w][j] = pomocna7;
            }
        }
        w--;
    }
    //Ogledalo matrica
    Matrica M(3*m.size(), std::vector<double>(3*m[0].size()));
        for(int i=0; i<=m.size()+m.size(); i++){
            for(int j=0; j<=M[i].size()-m[0].size(); j++){
                
                 if( j==0 && i==0){
                     for(int k=0; k<m.size(); k++){
                         for(int p=0; p<m[0].size(); p++){
                             M[i+k][j+p] = hv[k][p];
                         }
                     }
                 }
                 else if(i==0 && j==m[0].size() && j<m[0].size() + m[0].size() && j==m[0].size()){
                     for(int k=0; k<m.size(); k++){
                         for(int p=0; p<m[0].size(); p++){
                             M[i+k][j+p] = v[k][p];
                         }
                     }
                 }
                 else if(i==0 && j>=m[0].size()+m[0].size() && j==m[0].size()+m[0].size()){
                     for(int k=0; k<m.size(); k++){
                         for(int p=0; p<m[0].size(); p++){
                             M[i+k][j+p] = hv[k][p];
                         }
                     }
                 }
                 else if(i==m.size() && j==0){
                      for(int k=0; k<m.size(); k++){
                         for(int p=0; p<m[0].size(); p++){
                             M[i+k][j+p] = h[k][p];
                         }
                     }
                 }
                 else if(i==m.size() && j==m[0].size() && j<m[0].size() + m[0].size() && j==m[0].size()){
                     for(int k=0; k<m.size(); k++){
                         for(int p=0; p<m[0].size(); p++){
                             M[i+k][j+p] = m[k][p];
                         }
                     }
                 }
                 else if(i==m.size() && j>=m[0].size()+m[0].size() && j==m[0].size()+m[0].size()){
                     for(int k=0; k<m.size(); k++){
                         for(int p=0; p<m[0].size(); p++){
                             M[i+k][j+p] = h[k][p];
                         }
                     }
                }
                else if(i==m.size()+m.size() && j==0){
                    for(int k=0; k<m.size(); k++){
                         for(int p=0; p<m[0].size(); p++){
                             M[i+k][j+p] = hv[k][p];
                         }
                     }
                }
                else if(i==m.size()+m.size() && j==m[0].size() && j<m[0].size() + m[0].size() && j==m[0].size()){
                     for(int k=0; k<m.size(); k++){
                         for(int p=0; p<m[0].size(); p++){
                             M[i+k][j+p] = v[k][p];
                         }
                     }
                }
                else if(i==m.size()+m.size() && j>=m[0].size()+m[0].size() && j==m[0].size()+m[0].size()){
                     for(int k=0; k<m.size(); k++){
                         for(int p=0; p<m[0].size(); p++){
                             M[i+k][j+p] = hv[k][p];
                         }
                     }
                }
                
            }
        }
    return M;
}
   
    
int main (){
	int m,n;
	    std::cout<<"Unesite dimenzije matrice (m n): ";
	    std::cin>>m>>n;
	    if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	    else{
	    Matrica a(m,std::vector<double>(n));
	    std::cout<<"Unesite elemente matrice: ";
	    std::cout<<std::endl;
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            std::cin>>a[i][j];
	        }
	    }
	Matrica b;
	b = OgledaloMatrica(a);
	std::cout<<"Rezultantna matrica: "<<std::endl;
	for(int i=0; i<b.size(); i++){
	    for(int j=0; j<b[i].size(); j++){
	        std::cout<<std::setw(4)<<b[i][j];
	    }
	    std::cout<<std::endl;
	}
	
	    }
	return 0;
}