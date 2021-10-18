#include <iostream>
#include <vector>
#include <iomanip>   
#include <stdexcept>

typedef std::vector<double> vektor;
typedef std::vector<std::vector<double>> matrica;

vektor Obrni(vektor v){
    vektor povratni(v.size());
    for(int i(0); i<v.size(); i++){
        povratni[i]=v[v.size()-i-1];
    }
    return povratni;
}

matrica Hmat(matrica M){
    int ra;
    ra=M[0].size();
    matrica h(M.size(),vektor(ra)); 
    
    vektor temp;
    for(int i(0); i<M.size();i++){
        temp=Obrni(M[i]);
        for(int j(0);j<ra;j++){
            h[i][j]=temp[j];
        }                                                       
    }
    return h;
}

matrica Vmat(matrica M){
    matrica v(M.size(), vektor(M[0].size()));
    for(int i(0);i<M.size();i++){
         for(int j(0);j<M[0].size();j++){                             
             v[i][j]=M[M.size()-i-1][j];
         }                                                          
    }
    return v;
}
bool grbava(matrica M){
    for(int i(0);i<M.size()-1;i++){
        if(M[i].size()!=M[i+1].size()) return true;
    }
    return false;
}

matrica OgledaloMatrica(matrica M){   
    if(grbava(M)) throw std::domain_error("Matrica nije korektna");                    
    if(M[0].size()==0){
        matrica L(3*M.size(), vektor());
        return L;
    }
    matrica H, V, HV;
    H=Hmat(M);
    V=Vmat(M);
    HV=Hmat(Vmat(M));
    int m, n;
    m=M.size();
    n=M[0].size();                                         
    matrica O(3*m, vektor (3*n));                        
    for(int i(0);i<3*m;i++){                             
        for(int j(0);j<3*n;j++){
            if((i<m)&&(j<n)){                               
                O[i][j]=HV[i][j];
            }
            else if((i<m)&&(j<2*n)&&(j>=n)){                
                O[i][j]=V[i][j-n];
            }
            else if((i<m)&&(j<3*n)&&(j>=2*n)){              
                O[i][j]=HV[i][j-2*n];
            }
            else if((i<2*m)&&(i>=m)&&(j<n)){                
                O[i][j]=H[i-m][j];
            }
            else if((i<2*m)&&(i>=m)&&(j<2*n)&&(j>=n)){      
                O[i][j]=M[i-m][j-n];
            }
            else if((i<2*m)&&(i>=m)&&(j<3*n)&&(j>=2*n)){   
                O[i][j]=H[i-m][j-2*n];
            }
            else if((i<3*m)&&(i>=2*m)&&(j<n)){              
                O[i][j]=HV[i-2*m][j];
            }
            else if((i<3*m)&&(i>=2*m)&&(j<2*n)&&(j>=n)){    
                O[i][j]=V[i-2*m][j-n];
            }
            else if((i<3*m)&&(i>=2*m)&&(j<3*n)&&(j>=2*n)){  
                O[i][j]=HV[i-2*m][j-2*n];
            }
            
        }
    }
    return O;
}

int main ()
{
    int m,n;
    int t;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    if((m<0)||(n<0)){
        
            std::cout<<"Dimenzije matrice moraju biti nenegativne!";
            return 0;
    }
    std::cout<<"Unesite elemente matrice:"<<std::endl;
    matrica A(m, vektor(n));
    if((m!=0)&&(n!=0)){           //bilo bez ifa
        for(int i(0);i<m;i++){
          for(int j(0);j<n;j++){
              std::cin>>t;
              A[i][j]=t;
          }
        }
    }
    matrica M;
    M=OgledaloMatrica(A);
    std::cout<<"Rezultantna matrica: "<<std::endl;
    for(int i(0);i<3*m;i++){
        for(int j(0);j<3*n;j++){
            std::cout<<std::setw(4)<<M[i][j];
        }
        std::cout<<std::endl;
    }
    
	return 0;
}