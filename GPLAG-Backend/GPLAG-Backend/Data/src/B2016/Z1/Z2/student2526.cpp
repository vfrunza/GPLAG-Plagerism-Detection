#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
std::vector<double> merge(std::vector<double> v1,std::vector<double> v2){
    std::vector<double>v3(v1.size()+v2.size());
    for (int i=0;i<v1.size();i++) v3[i]=v1[i];
    int j=0;
    for (int i=v1.size();i<v1.size()+v2.size();i++){
        v3[i]=v2[j];
        j++;
    } 
    return v3;
}

Matrica Horizontalna(Matrica a){
        Matrica v;
        std::vector<double> r;
        for(int i=0;i<a.size();i++){
            v.push_back(r);
            // sada okrenimo kolone
            for (int j=a[i].size()-1;j>=0;j--){
                v[i].push_back(a[i][j]);
        }
    }
    return v;
}
Matrica Vertikalna(Matrica a){
    Matrica v;
    for (int i=a.size()-1;i>=0;i--){
        v.push_back(a[i]);
    }
    return v;
}
Matrica OgledaloMatrica(Matrica m){
    if(m.size()==0) return m;
    // provjerimo ispravnost formata
    for(int i=0;i<m.size();i++){
        if(m[0].size()!=m[i].size()) throw std::domain_error("Matrica nije korektna");
    }
    Matrica v=Vertikalna(m),h=Horizontalna(m);
    Matrica k=Vertikalna(h);
    Matrica final(m.size()*3,std::vector<double>(3*m[0].size()));
    for (int i=0;i<m.size();i++){
        final[i]=merge(merge(k[i],v[i]),k[i]);
    }
    int j=0;
    for (int i=m.size();i<m.size()*2;i++){
        final[i]=merge(merge(h[j],m[j]),h[j]);
        j++;
    }
    j=0;
    for (int i=m.size()*2;i<m.size()*3;i++){
        final[i]=merge(merge(k[j],v[j]),k[j]);
        j++;
    }
    return final;
}

int main ()
{   
    std::cout<<"Unesite dimenzije matrice (m n): ";
    int m,n;
    std::cin>>m>>n;
    if(m<0||n<0){
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    Matrica a(m,std::vector<double>(n));
    std::cout<<"Unesite elemente matrice: ";
    for(int i{};i<m;i++){
        for(int j{};j<n;j++){
            std::cin>> a[i][j];
            
        }
    }
    try{
    Matrica f=OgledaloMatrica(a);
    std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
    for(int i=0;i<f.size();i++){
        for(int j=0;j< f[i].size();j++){
            std::cout<<std::setw(4)<<f[i][j];
        }
        std::cout<<std::endl;
    }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}