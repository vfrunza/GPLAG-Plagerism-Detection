#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
using std::domain_error;

typedef vector<vector<double>>Matrica;

Matrica HorizontalnoOgledalo(Matrica a){
    double pomocna;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size()/2;j++){
            pomocna=a[i][j];
            a[i][j]=a[i][a[i].size()-j-1];
            a[i][a[i].size()-j-1]=pomocna;
        }
    }
    return a;
}

Matrica VertikalnoOgledalo(Matrica a){
    double pomocna;
      for(int i=0;i<a.size()/2;i++){
          for(int j=0;j<a[i].size();j++){
            pomocna=a[i][j];
            a[i][j]=a[a.size()-i-1][j];
            a[a.size()-i-1][j]=pomocna;
          }
    }
    return a;
}
    Matrica OgledaloMatrica(Matrica m){
    //BACANJE IZUZETKA
    for(int i=0;i<m.size();i++)
    if(m[0].size() != m[i].size()) throw domain_error ("Matrica nije korektna");
    
    Matrica pomocna;
    pomocna=m;
    Matrica glavna;
    Matrica kombinovana=VertikalnoOgledalo(HorizontalnoOgledalo(m));
    Matrica horizontalna=HorizontalnoOgledalo(m);
    Matrica vertikalna=VertikalnoOgledalo(m);
    glavna.resize(3*m.size()); 
    for(int i=0;i<3*m.size();i++) glavna[i].resize(3*m[0].size());
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            glavna[i][j]=kombinovana[i][j];
        }
    }
    for(int i=0;i<m.size();i++){
        for(int j=m[0].size();j<2*m[0].size();j++){
            glavna[i][j]=vertikalna[i][j-m[0].size()];
        }
    }
    for(int i=0;i<m.size();i++){
        for(int j=2*m[0].size();j<3*m[0].size();j++){
            glavna[i][j]=kombinovana[i][j-2*m[0].size()];
        }
    }
    for(int i=m.size();i<2*m.size();i++){
        for(int j=0;j<m[0].size();j++){
            glavna[i][j]=horizontalna[i-m.size()][j];
        }
    }
    for(int i=m.size();i<2*m.size();i++){
        for(int j=m[0].size();j<2*m[0].size();j++){
            glavna[i][j]=pomocna[i-m.size()][j-m[0].size()];
        }
    }
    for(int i=m.size();i<2*m.size();i++){
        for(int j=2*m[0].size();j<3*m[0].size();j++){
            glavna[i][j]=horizontalna[i-m.size()][j-2*m[0].size()]; 
        }
    }
    for(int i=2*m.size();i<3*m.size();i++){
        for(int j=0;j<m[0].size();j++){
            glavna[i][j]=kombinovana[i-2*m.size()][j]; 
        }
    }
    for(int i=2*m.size();i<3*m.size();i++){
        for(int j=m[0].size();j<2*m[0].size();j++){
            glavna[i][j]=vertikalna[i-2*m.size()][j-m[0].size()]; 
        }
    }
    for(int i=2*m.size();i<3*m.size();i++){
        for(int j=2*m[0].size();j<3*m[0].size();j++){
            glavna[i][j]=kombinovana[i-2*m.size()][j-2*m[0].size()];
        }
    }
    return glavna;
}
int main ()
{
    try{
    int m,n;
    Matrica mat;
    cout<<"Unesite dimenzije matrice (m n): ";
    cin>>m>>n;
    if(m<0 || n<0) {cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0; }
    cout<<"Unesite elemente matrice: "<<endl;
    mat.resize(m);
    for(int i=0;i<m;i++){
            mat[i].resize(n);
        }
        for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cin>>mat[i][j];
        }
    } 
    Matrica konacna;
    konacna=OgledaloMatrica(mat);
    cout<<"Rezultantna matrica: "<<endl;
    for(int i=0;i<konacna.size();i++){
        for(int j=0;j<konacna[i].size();j++){
            cout<<setw(4)<<konacna[i][j];
        }
        cout<<endl;
    }
    return 0;
    }
    catch(std::domain_error izuzetak) {
    cout << izuzetak.what()<<endl;
}
}