#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> Vektor;

Matrica KreirajMatricu(int br_redova, int br_kolona){
    return Matrica(br_redova,Vektor(br_kolona));
}

Matrica UnesiMatricu(int br_redova, int br_kolona){
    auto m(KreirajMatricu(br_redova,br_kolona));
    
    for(int i=0;i<br_redova;i++){
        for(int j=0;j<br_kolona;j++){
            cin>>m.at(i).at(j);
        }
    }
    return m;
}

void IspisMatricu(Matrica m){
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m.at(0).size();j++){
            cout<<right<<setw(6)<<m.at(i).at(j);
        }
        cout<<endl;
    }
}

bool DaLiJeGrbava(Matrica m){
    
    for(int i=0;i<m.size()-1;i++)
        if(m.at(i).size()!=m.at(i+1).size())
            return true;
    return false;
}

Matrica NajvecaPlaninaMatrice (Matrica m){
    
    double maxi=0,maxj=0;
    int d=0,maxd=0;
    Matrica pom_m;
    
  
      
          if(DaLiJeGrbava(m)==true){
                           throw domain_error("Matrica nije korektna");
                           return pom_m;
           }
    
      
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m.at(i).size();j++){
                double suma=0;
                double proslasuma=0;
                double svesume=0;
                //3 3 1 0 0 0 9 0 1 3 0
                for(d=0;d<=i && d<=j && d<m.size()-i && d<m.at(i).size()-j;d++){
                    suma=0;
                    for(int k=i-d;k<=i+d;k++){
                        for(int g=j-d;g<=j+d;g++){
                            suma+=m.at(k).at(g);
                        }
                    }
                    
                    if(suma-svesume>=proslasuma && d!=0)break;
                    proslasuma=suma-svesume;
                    svesume=suma;
                    
                    if(d>=maxd){
                        
                        if(d==maxd && m.at(i).at(j)>m.at(maxi).at(maxj)){
                            maxi=i;
                            maxj=j;
                            maxd=d;
                        }
                        else{
                            maxi=i;
                            maxj=j;
                            maxd=d;
                        }
                        
                    }
                }
                
                
               
               
            }
        }
                Vektor red;
                for(int p=maxi-maxd;p<=maxi+maxd;p++){
                    for(int q=maxj-maxd;q<=maxj+maxd;q++){
                        red.push_back(m.at(p).at(q));
                    }
                    pom_m.push_back(red);
                    red.resize(0);
                }
                
        return pom_m;
    
}

int main ()
{
    int m,n;
    
    cout<<"Unesite dimenzije matrice (m i n): ";
    cin>>m>>n;
    
    if(m<0 || n<0){
        cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    
    cout<<"Unesite elemente matrice:";
    Matrica M;
   
    M=UnesiMatricu(m,n);
    
    cout<<endl<<"Najveca planina unesene matrice je: "<<endl;
    
    Matrica M1;
    try{
        NajvecaPlaninaMatrice(M);
    }catch(domain_error izuzetak){
        cout<<izuzetak.what();
    }
    
    M1=NajvecaPlaninaMatrice(M);
    IspisMatricu(M1);
    
	return 0;
}