#include <iostream>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<double>>Matrica;
Matrica EkspanzijaMatrice(Matrica a,int p, int q){
    if(p<=0 ||q<=0)throw std::domain_error("Nelegalni parametri");
    int tmp=a[0].size();
    for(int i=0; i<a.size(); i++){
        if(a[i].size()!=tmp)throw std::domain_error("Nekorektna matrica");
    }
    int k=a.size();
    a.resize(k*p);
    for(int i=0; i<a.size(); i++)a[i].resize(q*tmp);
    int vrste;
    for( vrste=0; vrste<a.size(); vrste++);
    int kolone(a[0].size()-1);
    for(int i=vrste-1;i>=0; i--){
        for(int j=kolone; j>=0; j--){
            int pr1=i/p;
            int pr2=j/q;
            a[i][j]=a[pr1][pr2];
        }
    }
    return a;
}    
int main() {
    try{
    std::cout<<"Unesite dimenzije matrice: "<<std::endl;
    int  m,n;
    std::cin>>m>>n;
    std::cout << "Unesite matricu: " << std::endl;
    Matrica a(m,std::vector<double>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            double s;
            std::cin >> s;
            a[i][j]=s;
        }
    }
    std::cout << "Unesite parametre za ekspanziju matrice: " << std::endl;
    int p,q;
    std::cin >> p>>q;
    a=EkspanzijaMatrice(a,p,q);
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a[0].size(); j++){
            std::cout << a[i][j]<<" ";
        }
        std::cout<< std::endl;
    }
    }
    catch(std::domain_error greska){
        std::cout << greska.what() << std::endl;
    }
    return 0;
}

