#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;

Matrica Vertikalna(Matrica m){
    std::vector<double> pom;
    for(int i=0;i<m.size()/2;i++){
        pom=m[i];
          m[i]=m[m.size()-1-i];
                m[m.size()-1-i]=pom;
            }
            return m;
        }
Matrica Horizontalna(Matrica m){
    double el;
    for(int i=0;i<m[0].size()/2;i++){
        for(int j=0;j<m.size();j++){
            el=m[j][i];
            m[j][i]=m[j][m[0].size()-1-i];
            m[j][m[0].size()-1-i]=el;
        }
    }
    return m;
}

Matrica Kombinovana(Matrica m){
    std::vector<double>pom;
    for(int i=0;i<m.size()/2;i++){
        pom=m[i];
        m[i]=m[m.size()-1-i];
        m[m.size()-1-i]=pom;
    }
    Matrica p;
    p=m;
    double el;
    for(int i=0;i<p[0].size()/2;i++){
        for(int j=0;j<p.size();j++){
            el=p[j][i];
            p[j][i]=p[j][p[0].size()-1-i];
            p[j][p[0].size()-1-i]=el;
        }
    }
    return p;
}
Matrica OgledaloMatrica (Matrica m){
    if(m.size()==0)
    return m;
    for(int i=0;i<m.size();i++){
        if(m[i].size()!=m[0].size()){
            throw std::domain_error("Matrica nije korektna");
        }
    }
    Matrica y(3*m.size(),std::vector<double>(3*m[0].size()));
    Matrica n;
    Matrica p;
    Matrica q;
    n=Vertikalna(m);
    p=Horizontalna(m);
    q=Kombinovana(m);
    
    for(int i=0;i<m[0].size();i++){
        for(int j=0;j<m.size();j++){
            y[j][i]=q[j][i];
            y[j+m.size()][i]=p[j][i];
            y[j+2*m.size()][i]=q[j][i];
        }
}
for(int i=0;i<m[0].size();i++){
    for(int j=0;j<m.size();j++){
        y[j][i+m[0].size()]=n[j][i];
        y[j+m.size()][i+m[0].size()]=m[j][i];
        y[j+2*m.size()][i+m[0].size()]=n[j][i];
    }
}
for(int i=0;i<m[0].size();i++){
    for(int j=0;j<m.size();j++){
        y[j][i+2*m[0].size()]=q[j][i];
        y[j+m.size()][i+2*m[0].size()]=p[j][i];
        y[j+2*m.size()][i+2*m[0].size()]=q[j][i];
    }
}
return y;
}
int main (){
    int a,b;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>a>>b;
    if(a<0 || b<0){
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    Matrica m(a,std::vector<double>(b));
    std::cout<<"Unesite elemente matrice:";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            std::cin>> m[i][j];
        }
    }
    std::cout<<std::endl;
    Matrica y;
    try{
    y=OgledaloMatrica(m);
    } 
    catch(std::domain_error a){
    std::cout<<a.what();
    }
    std::cout<<"Rezultantna matrica:"<<std::endl;
    for(int i=0;i<y.size();i++){
        for(int j=0;j<y[0].size();j++){
            std::cout<<std::right<<std::setw(4)<<y[i][j];
        }
        std::cout<<std::endl;
    }
	return 0;
}