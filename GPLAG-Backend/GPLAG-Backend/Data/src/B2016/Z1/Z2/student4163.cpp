#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>

std::vector<std::vector<double>>horizontalna(std::vector<std::vector<double>>mat){
    std::vector<std::vector<double>>horizontal(mat.size(), std::vector<double>(mat[0].size()));
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            horizontal[i][j]=mat[i][mat[i].size()-1-j];
        }
    }
    return horizontal;
}
std::vector<std::vector<double>>vertikalna(std::vector<std::vector<double>>mat){
    std::vector<std::vector<double>>v(mat.size(),std::vector<double>(mat[0].size()));
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            v[i][j]=mat[mat.size()-1-i][j];
        }
    }
    return v;
}

std::vector<std::vector<double>>hv(std::vector<std::vector<double>>mat){
    std::vector<std::vector<double>>oba(mat.size(), std::vector<double>(mat[0].size()));
    std::vector<std::vector<double>>oba1(mat.size(), std::vector<double>(mat[0].size()));
    oba=horizontalna(mat);
    oba1=vertikalna(oba);
    return oba1;
}

std::vector<std::vector<double>>OgledaloMatrica(std::vector<std::vector<double>>mat){
    for(int i=0;i<mat.size();i++){
        if(mat[i].size()!=mat[0].size()) throw std::domain_error("Matrica nije korektna");
    }
    if(mat.size()==0){
        
        std::vector<std::vector<double>>nova;
        return nova;
    }
    std::vector<std::vector<double>>nova(3*mat.size(), std::vector<double>(3*mat[0].size()));
    std::vector<std::vector<double>>temp1;
    std::vector<std::vector<double>>temp2;
    std::vector<std::vector<double>>temp3;
    temp1=horizontalna(mat);
    temp2=vertikalna(mat);
    temp3=hv(mat);
    int a=mat.size();
    int b=mat[0].size();
    for(int i=0;i<3*a;i++){
        for(int j=0;j<3*b;j++){
            if(i<a){
                if(j<b){
                    nova[i][j]=temp3[i%a][j%b];
                }else if(j>=b && j<2*b){
                    nova[i][j]=temp2[i%a][j%b];
                }else if(j>=2*b && j<3*b){
                    nova[i][j]=temp3[i%a][j%b];
                }
            }else if(i>=a && i<2*a){
                if(j<b){
                    nova[i][j]=temp1[i%a][j%b];
                }else if(j>=b && j<2*b){
                    nova[i][j]=mat[i%a][j%b];
                }else if(j>=2*b && j<3*b){
                    nova[i][j]=temp1[i%a][j%b];
                }
            }else if(i>=2*a && i<3*a){
                if(j<b){
                    nova[i][j]=temp3[i%a][j%b];
                }else if(j>=b && j<2*b){
                    nova[i][j]=temp2[i%a][j%b];
                }else if(j>=2*b && j<3*b){
                    nova[i][j]=temp3[i%a][j%b];
                }
            }
        }
    }
    
    return nova;
}

int main(){
    try{
    int m,n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    if(m<0 || n<0) throw "Dimenzije matrice moraju biti nenegativne!";
    std::vector<std::vector<double>>mat(m,std::vector<double>(n));
    std::cout<<"Unesite elemente matrice: ";
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            double x;
            std::cin>>x;
            mat[i][j]=x;
        }
    }
   
    std::cout<<std::endl;
    std::vector<std::vector<double>>ogledalo;
    ogledalo=OgledaloMatrica(mat);
    std::cout<<"Rezultantna matrica: "<<std::endl;
    for(int i=0;i<ogledalo.size();i++){
        for(int j=0;j<ogledalo[i].size();j++){
            std::cout<<std::setw(4)<<ogledalo[i][j];
        }
        std::cout<<std::endl;
    }
    
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    catch(const char poruka[]){
        std::cout<<poruka<<std::endl;
    }
    return 0;
}