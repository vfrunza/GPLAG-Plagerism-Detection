#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
std::vector<std::vector<double>> Ver_matrica(std::vector<std::vector<double>>v){
    if(v.size()==0){
        return v;
    }
    
    std::vector<std::vector<double>>p;
    std::vector<double> temp;
    for(int i=0;i<v.size();i++){
        
        for(int  j=v.size()-1;j>=i+1;j--){
            temp=v[j-1];
            v[j-1]=v[j];
            v[j]=temp;
        }
        
    }
    
    return v;
}


std::vector<std::vector<double>> Hor_matrica(std::vector<std::vector<double>>v){
    
    std::vector<std::vector<double>> s;
    s.resize(v.size());
    for(int i=0;i<s.size();i++){
        s[i].resize(v[i].size());
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            s[i][j]=v[i][v[i].size()-j-1];
        }
    }
    return s;
}


std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> v){
    std::vector<std::vector<double>>p;
    std::vector<std::vector<double>> s;
    s=v;
    
    p.resize(3*v.size());
    for(int i=0;i<p.size();i++){
        p[i].resize(3*v[0].size());
    }
    
    if(v.size()==0){
        return  v;
    }
    
    for(int i=0;i<v.size();i++){
        
        if(v[i].size()==0)
        return v;
    }
    
    for(int i=0;i<p.size();i++){
    if(p[0].size()!=p[i].size()){
        throw std::domain_error ("Matrica nije korektna");
        
    }
    }
    
    
    
    
    std::vector<std::vector<double>>p1;
    std::vector<std::vector<double>>p2;
    std::vector<std::vector<double>>p3;
    
    p1=(Hor_matrica(v));
    p2=(Ver_matrica(v));
    p3=(Ver_matrica(v));
    p3=(Hor_matrica(p3));
    
    
    
    int velicina1,velicina2;
    velicina1=p1.size();
    velicina2=p1[0].size();
    
    for(int i=0;i<p.size();i++){
        for(int j=0;j<p[i].size();j++){
            
            if(i<velicina1 && j<velicina2){
                p[i][j]=p3[i][j];
                
            }
            
            else if(i<velicina1 && j>=velicina2 && j<2*velicina2){
                p[i][j]=p2[i][j-velicina2];
            }
            
            else if(i<velicina1 && j>=2*velicina2){
                p[i][j]=p3[i][j-2*velicina2];
            }
            
            else if(i>=velicina1 && i<2*velicina1 && j<velicina2){
                p[i][j]=p1[i-velicina1][j];
            }
            else if(i>=velicina1 && i<2*velicina1 && j<2*velicina2 && j>=velicina2){
                p[i][j]=s[i-velicina1][j-velicina2];
            }
            else if(i>=velicina1 && i<2*velicina1 && j>=2*velicina2){
                p[i][j]=p1[i-velicina1][j-2*velicina2];
            }
            
            
            else if(i>=2*velicina1 && j<velicina2){
                p[i][j]=p3[i-2*velicina1][j];
            }
            
            else if(i>=2*velicina1 && j>=velicina2 &&  j<2*velicina2){
                p[i][j]=p2[i-2*velicina1][j-velicina2];
            }
            
            else if(i>=2*velicina1 && j>=2*velicina2){
                p[i][j]=p3[i-2*velicina1][j-2*velicina2];
            }
            
            
            
            
            
            
        }
    }
    return p;
}












int main ()
{
	try{
    int m,n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    
    if(m<0 || n<0){
    	std::cout<<"Dimenzije matrice moraju biti nenegativne!";
    	return 0;
    	
    }
    
    std::vector<std::vector<double>> v(m,std::vector<double>(n));
    
   std::cout<<"Unesite elemente matrice: ";
   for(int i=0;i<m;i++){
   	for(int j=0;j<n;j++){
   		std::cin>>v[i][j];
   	}
   }
   
   std::vector<std::vector<double>>Krajnja_matrica;
   Krajnja_matrica=OgledaloMatrica(v);
   std::cout<<std::endl;
   
   
   std::cout<<"Rezultantna matrica: ";
   std::cout<<std::endl;
   for(int i=0;i<Krajnja_matrica.size();i++){
   	for(int j=0;j<Krajnja_matrica[0].size();j++){
   		std::cout<<std::setw(4)<<Krajnja_matrica[i][j];
   	}
   	std::cout<<std::endl;
   }
}
	catch(std::domain_error izuzetak){
	    std::cout<<izuzetak.what();
	}
	return 0;
}