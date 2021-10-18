#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> matrica;

std::vector<double> spoji(std::vector<double> v1,std::vector<double> v2){
    std::vector<double> rez=v1;
    for(int i=0;i<v2.size();i++){
        rez.push_back(v2[i]);
    }
return rez;
}

matrica hm(matrica mat){
    matrica rezultat;
    int vel1=mat.size();
    rezultat.resize(vel1);
    int vel2=mat[0].size();
    for(int i=0;i<rezultat.size();i++){
        rezultat[i].resize(vel2);
    }
    for(int i=0;i<vel1;i++){
        int k=0;
        for(int j=vel2-1;j>=0;j--){
            rezultat[i][k++]=mat[i][j];
        }
    }
return rezultat;
}

matrica vm(matrica mat){
    matrica rezultat;
    int vel1 = mat.size();
    rezultat.resize(vel1);
    int vel2=mat[0].size();
    for(int i=0;i<rezultat.size();i++){
        rezultat[i].resize(vel2);
    }
    int k=0; //POGLEDAJ DA LI JE PROBLEM STO JE K OVDJE!!!
    for(int i=vel1-1;i>=0;i--){
        for(int j=0;j<vel2;j++){
            rezultat[k][j]=mat[i][j];
        }
        k++;
    }
return rezultat;
}

matrica hv(matrica mat){
    matrica rezultat,rezultathv;
    int vel1 = mat.size();
    rezultat.resize(vel1);
    rezultathv.resize(vel1);
    int vel2=mat[0].size();
    for(int i=0;i<rezultat.size();i++){
        rezultat[i].resize(vel2);
        rezultathv[i].resize(vel2);
    }
    for(int i=0;i<vel1;i++){
        int k=0;
        for(int j=vel2-1;j>=0;j--){
            rezultat[i][k++]=mat[i][j];
        }
    }
    int k=0;
    for(int i=vel1-1;i>=0;i--){
        for(int j=0;j<vel2;j++){
            rezultathv[k][j]=rezultat[i][j];
        }
        k++;
    }
return rezultathv;
}

matrica OgledaloMatrica(matrica mat){
    for(int i=0;i<ulaz.size();i++){
    if(mat[i].size() != mat[0].size()) throw std::domain_error("Matrica nije korektna");
}
    if(mat.size()==0) return mat;
    try{
    int m,n;
    matrica defaultna=mat;
    matrica hvmat=hv(mat);
    matrica vmmat=vm(mat);
    matrica hmmat=hm(mat);
    m=mat.size();
    mat.resize(3*m);
    n=mat[0].size();
    for(int i=0;i<3*m;i++)
        mat[i].resize(3*n);
    for(int i=0;i<=m-1;i++){
        std::vector<double> temp;
        temp=spoji(hvmat[i],vmmat[i]);
        temp=spoji(temp,hvmat[i]);
        mat[i]=temp;
    }
    int j=0;
    for(int i=m;i<=2*m-1;i++){
        std::vector<double> temp1;
        temp1=spoji(hmmat[j],defaultna[j]);
        temp1=spoji(temp1,hmmat[j]);
        mat[i]=temp1;
        j++;
    }
    j=0;
    for(int i=2*m;i<=3*m-1;i++){
        std::vector<double> temp2;
        temp2=spoji(hvmat[j],vmmat[j]);
        temp2=spoji(temp2,hvmat[j]);
        mat[i]=temp2;
        j++;
    }
    return mat;
    }catch(std::exception &ex){
    std::cout<<ex.what();}
}

int main ()
{
try{
int m,n;
try{
std::cout<<"Unesite dimenzije matrice (m n): ";
std::cin>>m>>n;
if(!std::cin) throw ("Pogresan tip podataka");
}catch(std::domain_error &j){
    std::cout<<j.what();
    return 0;
}
if(m<0 || n<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
matrica ulaz(m,std::vector<double>(n));
std::cout<< "Unesite elemente matrice: ";
try{
for(int i=0;i<ulaz.size();i++){
    for(int j=0;j<ulaz[0].size();j++){
        
        std::cin>>ulaz[i][j];
        if(!std::cin) throw std::domain_error("Pogresan tip podataka");
    }
}
}catch(std::exception &g){
    std::cout<<g.what();
    return 0;
}
matrica izlaz;
std::cout<<std::endl;  //DODATNI NOVI RED
izlaz=OgledaloMatrica(ulaz);
std::cout<<"Rezultantna matrica: "<<std::endl;
for(int i=0;i<izlaz.size();i++){
    for(int j=0;j<izlaz[0].size();j++){
        std::cout<<std::setw(4)<<izlaz[i][j];
    }    
    std::cout<<std::endl;
}
}catch(const std::overflow_error& e){
    std::cout<<e.what();
}catch(const std::runtime_error& a){
    std::cout<<a.what();
}catch(const char a[]){
    std::cout<<a;
}catch(std::exception &ex){
    std::cout<<ex.what();
}catch(...){
    
}
return 0;
}