#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> matrica;


std::vector<double> spoji(std::vector<double> a,std::vector<double> b,std::vector<double> c){
    std::vector<double> d;
    for(int i=0;i<a.size();i++) {d.push_back(a[i]);}
    for(int i=0;i<a.size();i++) {d.push_back(b[i]);}
    for(int i=0;i<a.size();i++) {d.push_back(c[i]);}
    return d;
    
}
matrica OgledaloMatrica(matrica m){
    matrica a;
    if(m.size()==0) return a;
    if(m[0].size()==0 and m.size()!=0) {
        a.resize(3*m.size());
        return a; }
    for(int i=0;i<m.size()-1;i++){
        if(m[i].size()!=m[i+1].size()) throw std::domain_error ("Matrica nije korektna!");
    }
    matrica h(m.size(),std::vector<double>(m[0].size()));
    matrica v,hv;
    std::vector<double> x;
    for(int i=m.size()-1;i>=0;i--){
        v.push_back(m[i]);
    }
    
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            h[i][j]=m[i][m[0].size()-1-j];
        }
    }
    
    for(int i=m.size()-1;i>=0;i--){
        hv.push_back(h[i]);
    }
    for(int i=0;i<m.size();i++){
        x=spoji(hv[i],v[i],hv[i]);
        a.push_back(x);
    }
    for(int i=0;i<m.size();i++){
        x=spoji(h[i],m[i],h[i]);
        a.push_back(x);
        
    }
    for(int i=0;i<m.size();i++){
        x=spoji(hv[i],v[i],hv[i]);
        a.push_back(x);
    }
    
  return a;  
    
    
}

int main ()
{
    
    try{
    int m,n;
    matrica nova;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    if(m<0 or n<0) {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    matrica a(m,std::vector<double> (n));
    std::cout<<"Unesite elemente matrice:";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            std::cin>>a[i][j];
        }
    }
    nova=OgledaloMatrica(a);
    std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
    if(nova.size()!=0){
     for(int i=0;i<nova.size();i++){
         std::cout<<" ";
         for(int j=0;j<nova[0].size();j++){
             std::cout<<std::right<<std::setw(3)<<nova[i][j]<<" ";
         }
         std::cout<<std::endl;
     }
    }
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
   
   
    return 0;
}