#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>


std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>>m){
        
        int k=0,l=0,i=0,j=0,z=0,s=0,e=0;
       
                                  
        int brojac=0;
        for(int i=1;i<m.size();i++){
        
            if(m.at(0).size()!=m.at(i).size()) brojac++;
        
        }
        if(brojac!=0) throw std::domain_error ("Matrica nije korektna");
       
        std::vector<std::vector<double>> matrica(3*m.size());
        for(int i=0;i<3*m.size();i++){
            matrica[i].resize(3*m[0].size());
        }
         
   
        
        //prva 1 red
        for(int i=m.size()-1;i>=0;i--){
            for(j=m[0].size()-1;j>=0;j--){
                matrica[k][l]=m[i][j];
                l++;
                z++;
            }k++;l=0;
        }
        //sredisnka 1 red
        k=0;
        for(int i=m.size()-1;i>=0;i--){
            l=m[0].size();
            for(j=0;j<m[0].size();j++){
                matrica[k][l]=m[i][j];
                l++;

            }k++;l=m[0].size();
        }
        //zadnja 1 red
        k=0;
        for(int i=m.size()-1;i>=0;i--){
           l=m[0].size()*2;
            for(j=m[0].size()-1;j>=0;j--){
                matrica[k][l]=m[i][j];
                l++;

            }k++;l=m[0].size()*2;
        }
            l=0;s=k;
            //prva 2 red
         for(int i=0;i<m.size();i++){
            for(j=m[0].size()-1;j>=0;j--){
                matrica[k][l]=m[i][j];
                l++;

            }k++;l=0;
        }
        k=s;
        //sredisnja
        for(int i=0;i<m.size();i++){
            l=m[0].size();
            for(j=0;j<m[0].size();j++){
                matrica[k][l]=m[i][j];
                l++;

            }k++;l=m[0].size();
        }
        //Krajnja desna drugi red
        k=s;
        
        for(int i=0;i<m.size();i++){
            l=m[0].size()*2;
            for(j=m[0].size()-1;j>=0;j--){
                matrica[k][l]=m[i][j];
                l++;

            }k++;l=m[0].size()*2;
        }

        //prva zadnji red
        l=0;e=k;
        for(int i=m.size()-1;i>=0;i--){
            for(j=m[0].size()-1;j>=0;j--){
                matrica[k][l]=m[i][j];
                l++;
                z++;
            }k++;l=0;
        }
        //2 zadnji red

        k=e;
        for(int i=m.size()-1;i>=0;i--){
            l=m[0].size();
            for(j=0;j<m[0].size();j++){
                matrica[k][l]=m[i][j];
                l++;

            }k++;l=m[0].size();
        }
        //zadnja zadnji red
        k=e;
        for(int i=m.size()-1;i>=0;i--){
             l=m[0].size()*2;
            for(j=m[0].size()-1;j>=0;j--){
                matrica[k][l]=m[i][j];
                l++;
 
            }k++;l=m[0].size()*2;
        } 


return matrica;


}

int main()
{   
    
    int m,n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
     if(m<0 || n<0) {
         std::cout<<"Dimenzije matrice moraju biti nenegativne!";
         return 0;
     }
    
    std::vector<std::vector<double>> matrica(3*m,std::vector<double>(3*n));
    std::vector<std::vector<double>> m1(m,std::vector<double>(n));
   std::cout<<"Unesite elemente matrice: ";
   
        
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            std::cin>>m1[i][j];
        }
    }std::cout << std::endl;
  
    try{
    matrica=OgledaloMatrica(m1);
   std::cout<<"Rezultantna matrica:"<<std::endl;
    if(m!=0 && n!=0){
    for(int i=0;i<3*m;i++){ 
        for(int j=0;j<3*n;j++){ 
            std::cout<<std::right<<std::setw(4)<<matrica[i][j];
        }std::cout << std::endl;
    }}
    
    return 0;}
    
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}

