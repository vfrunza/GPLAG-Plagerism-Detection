#include<iostream>
#include<vector>
#include<iomanip>

using std::cout;
using std::cin;
using std::vector;

typedef vector<vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica x){
    Matrica ogledalo;
    if(x.size()!=0 && x[0].size()==0){
        ogledalo.resize(3*x.size());
        return ogledalo;
    }
    if(x.size()==0) return ogledalo;
    int m=x.size(), n=x[0].size(), g=3*x.size(), f=3*x[0].size();
    ogledalo.resize(g);
    for(int i=0; i<g; i++){
        ogledalo[i].resize(f);
    }

int i(0);
        while(i<m){
        int k(m-1);
        do{
            int j(0);
            do{
            for(int l=n-1; l>=0; l--){
                ogledalo[i][j]=x[k][l];
                j++;
            }
            for(int l=0; l<n; l++){
                ogledalo[i][j]=x[k][l];
                j++;
            }
            for(int l=n-1; l>=0; l--){
                ogledalo[i][j]=x[k][l];
                j++;
            }
            }while(j<f);
            i++;
            k--;
}while(k>=0);
}
        while(i>=m && i<2*m){
            int k(0);
            do{
                int j(0);
                do{
                for(int l=n-1; l>=0; l--){
                    ogledalo[i][j]=x[k][l];
                    j++;
                }
                for(int l=0; l<n; l++){
                ogledalo[i][j]=x[k][l];
                j++;
            }
            for(int l=n-1; l>=0; l--){
                ogledalo[i][j]=x[k][l];
                j++;
            }
            }while(j<f);
            i++;
            k++;
            }while(k<x.size());
        }
        while(i>=2*m && i<3*m){
        int k(x.size()-1);
        do{
            int j(0);
            do{
            for(int l=n-1; l>=0; l--){
                ogledalo[i][j]=x[k][l];
                j++;
            }
            for(int l=0; l<n; l++){
                ogledalo[i][j]=x[k][l];
                j++;
            }
            for(int l=n-1; l>=0; l--){
                ogledalo[i][j]=x[k][l];
                j++;
            }
            }while(j<f);
            i++;
            k--;
}while(k>=0);
}
        return ogledalo;
}
                
int main ()
{
    int m(0),n(0);
    Matrica y;
    cout<<"Unesite dimenzije matrice (m n): ";
    cin>>m>>n;
    if(m<0 || n<0){ 
        cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    if(m==0 && n==0){
        cout<<"Unesite elemente matrice: "<<std::endl;
        cout<<"Rezultantna matrica: ";
        return 0;
    }
    Matrica x(m,vector<double>(n));
    cout<<"Unesite elemente matrice: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>x[i][j];
        }
    }
    cout<<std::endl;
    cout<<"Rezultantna matrica: ";
    cout<<std::endl;
    y=OgledaloMatrica(x);
    for(int i=0; i<y.size(); i++){
        for(int j=0; j<y[0].size(); j++){
            cout<<std::setw(4)<<y[i][j];
        }
        cout<<std::endl;
    }
	return 0;
}