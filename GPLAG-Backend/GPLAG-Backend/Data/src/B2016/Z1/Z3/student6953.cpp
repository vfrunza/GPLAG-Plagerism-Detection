#include<iostream>
#include<vector>
#include<iomanip>
typedef std::vector<std::vector<double>> Matrica; 
Matrica KreirajMatricu(int brojr, int brojk){
    return Matrica(brojr, std::vector<double> (brojk));
}
Matrica RastuciPodnizovi(std::vector<double> a){
    Matrica m; 
    if(a.size()==0) return m; 
    std::vector<double> pom; 
    int poc; 
       for(int k=0; k<a.size(); k++){
            if(k<a.size()-1 && a[k]<=a[k+1]){poc=k; 
                while(k<a.size()-1 && a[k]<=a[k+1])  k++;
                for(int i=poc; i<=k; i++) pom.push_back(a[i]);
                m.push_back(pom);
                pom.resize(0); 
            }
        }
    /*for(int l=0; l<m.size(); l++){
        for(int x=0;  x<m.size(); x++){
            if(m[l].size()<m[x].size() && l!=x){
                for(int p=0; p<m[l].size(); p++){
                    if(p==m[l].size()-1|| m[l][p]!=m[x][p]  ) break; 
                    else if(p==m[l].size()-1){
                        if(l!=m.size()-1){
                        for(int h=l; h<m.size()-1; h++){
                            m[h]=m[h+1];
                        }
                        m.resize(m.size()-1); l--;}
                        else if(l==m.size()-1) {m.resize(m.size()-1); }
                    }
                }
            }
        }
    }*/
    return m; 
}
Matrica OpadajuciPodnizovi(std::vector<double> a){
    Matrica m; 
    if(a.size()==0) return m; 
    std::vector<double> pom; 
    int poc; 
       for(int k=0; k<a.size(); k++){
            if(k<a.size()-1 && a[k]>=a[k+1]){poc=k; 
                while(k<a.size()-1 && a[k]>=a[k+1])  k++;
                for(int i=poc; i<=k; i++) pom.push_back(a[i]);
                m.push_back(pom);
                pom.resize(0); 
            }
        }
   /*for(int l=0; l<m.size(); l++){
        for(int x=0;  x<m.size(); x++){
            if(m[l].size()<m[x].size() && l!=x){
                for(int p=0; p<m[l].size(); p++){
                    if(p==m[l].size()-1 || m[l][p]!=m[x][p]) break; 
                    else if(p==m[l].size()-1){
                        if(l!=m.size()-1){
                        for(int h=l; h<m.size()-1; h++){
                            m[h]=m[h+1];
                        }
                        m.resize(m.size()-1); l--;}
                        else if(l==m.size()-1) {m.resize(m.size()-1); }
                    }
                }
            }
        }
    }*/
    return m; 
}
int main (){
    std::cout<<"Unesite broj elemenata vektora: "; 
    int n; 
    std::cin>>n; 
    std::vector<double> a(n);
    std::cout<<"Unesite elemente vektora: ";
    for(int i=0; i<n; i++){
        std::cin>>a[i]; 
    }
    std::cout<<"Maksimalni rastuci podnizovi: \n";
    Matrica m=RastuciPodnizovi(a); 
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[i].size(); j++){
            std::cout<<m[i][j]<<" "; 
        }
        std::cout<<"\n"; 
    }
    std::cout<<"Maksimalni opadajuci podnizovi: \n";
    Matrica k=OpadajuciPodnizovi(a); 
    for(int i=0; i<k.size(); i++){
        for(int j=0; j<k[i].size(); j++){
            std::cout<<k[i][j]<<" "; 
        }
        std::cout<<"\n"; 
    }
    return 0;
}