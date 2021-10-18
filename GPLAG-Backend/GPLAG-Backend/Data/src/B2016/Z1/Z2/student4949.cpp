#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
using std::cin;
using std::cout;
using std::domain_error;
using std::setw;
using std::vector;
using std::endl;

typedef std::vector<std::vector<double>> matrica;

matrica vertikalna(matrica v){
    
    vector<double> a;
    for(int i=0;i<v.size()/2;i++){
        a=v[i];
        v[i]=v[v.size()-i-1];
        v[v.size()-i-1]=a;
    }
    return v;
    
}

matrica horizontalna(matrica v){
    double a;
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size()/2;j++){
            a=v[i][j];
            v[i][j]=v[i][v[i].size()-j-1];
            v[i][v[i].size()-j-1]=a;
        }
        
       
    }
    
    return v;
}

matrica kombinovano(matrica a){

    return vertikalna(horizontalna(a));
}


matrica OgledaloMatrica(matrica m){
    
    for(int i=0;i<m.size()-1;i++){
        if(m.size()==0) return m;
        if(m[i].size()!=m[i+1].size()) throw domain_error("Matrica nije korektna");
    }
    
    
    
    matrica v,h,hv;
    v=vertikalna(m);
    h=horizontalna(m);
    hv=kombinovano(m);
    
    
    int d=m.size(), e=m[0].size();
  
  matrica cijela(3*d,vector<double>(3*e));
  
  for(int i=0;i<3*d;i++){
      for(int j=0;j<3*e;j++){
        if(i<d && j<e) cijela[i][j]=hv[i][j];
    
        if(i<d && j<2*e && j>=e){ 
            cijela[i][j]=v[i][j-e];
        }
        if(i<d && j<3*e && j>=2*e){ 
            cijela[i][j]=hv[i][j-2*e];
        }
    
        if(i<2*d && i>=d && j<e ){ 
            cijela[i][j]=h[i-d][j];
        }
        
        if(i<2*d && i>=d && j<2*e && j>=e){ 
            cijela[i][j]=m[i-d][j-e];
            
        }
        
        if(i<2*d && i>=d && j<3*e && j>=2*e){ 
            cijela[i][j]=h[i-d][j-2*e];
        }
        if(i<3*d && i>=2*d && j<e){ 
            cijela[i][j]=hv[i-2*d][j];
        }
    
        if(i<3*d  && i>=2*d && j<2*e && j>=e){ 
            cijela[i][j]=v[i-2*d][j-e];
            
        }
        
        if(i<3*d && i>=2*d && j<3*e && j>=2*e){ 
            cijela[i][j]=hv[i-2*d][j-2*e];
            
        }
          
          
          
      }
     
      
  }
    
    
    
    
    return cijela;
    
}
int main ()
{   int m,n;
    matrica b;
    cout<<"Unesite dimenzije matrice (m n): ";
    cin>>m>>n;
    if(m<0 || n<0) cout<<"Dimenzije matrice moraju biti nenegativne!";
    else{
    matrica a(m,vector<double>(n));
    cout<<"Unesite elemente matrice: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            
        }
        
    }
    try{
    b=OgledaloMatrica(a);
    cout<<"Rezultantna matrica: "<<endl;
    for(int i=0;i<3*m;i++){
        for(int j=0;j<3*n;j++){
            cout<<setw(4)<<b[i][j];
            
        }
        cout<<endl;
    }
    }
    catch(domain_error izuzetak){
        cout<<izuzetak.what()<<endl;
        
    }
    
   
    
    }
	return 0;
}