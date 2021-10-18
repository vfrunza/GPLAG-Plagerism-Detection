
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>


typedef std::vector<std::vector<double> > Matrica;

   Matrica KreirajMatricu(int broj_redova, int broj_kolona ) {

     return Matrica(broj_redova, std::vector<double> (broj_kolona) );
}



Matrica HorizontalnoOgledalo(Matrica a)  {
     
   //  Matrica b(a.size(),std::vector<double>(a[0].size())); 
     Matrica b(a); 
     for(int i=0; i<a.size(); i++) {
        
        int k=0; 
        for(int j=(a[0].size()-1); j>=0; j--) {
            b[i][k]=a[i][j]; 
            k++; }
        
        
     }
     
     return b;
    
}



Matrica VertikalnoOgledalo(Matrica a) {
  
    
         Matrica c;
        for(int i=a.size()-1; i>=0; i--) {
             
          c.push_back(a[i]);
  
        }
         
       
    return c; 
}




 Matrica VertikalnoiHorizontalno(Matrica a) {
     Matrica d; 
    
     d=HorizontalnoOgledalo(a);
     d=VertikalnoOgledalo(d);
     return d;

}  


Matrica OgledaloMatrica(Matrica a) {
    
    
     for(int i=1; i<a.size(); i++)
     if(a[0].size() !=a[i].size()) throw std::domain_error ("Matrica nije korektna"); 
     
    
    
    Matrica b(HorizontalnoOgledalo(a));
    Matrica c(VertikalnoOgledalo(a));
    Matrica d(VertikalnoiHorizontalno(a));
    
    Matrica e(3*a.size(), std::vector<double> ( 3* a[0].size())); 
    
    
            for  (int i=0; i<a.size(); i++) 
            for(int j=0; j<a[i].size(); j++)
               e[i][j]=d[i][j];
               
               
             for(int i=0; i<a.size(); i++)
             for(int j=0; j<a[i].size(); j++)
             e[i][j+a[i].size()]=c[i][j];
             
             
            for(int i=0; i<a.size(); i++)
            for(int j=0; j<a[i].size(); j++)
            e[i][j+ 2*a[i].size()]=d[i][j];
            
            for(int i=0; i<a.size(); i++)
            for(int j=0; j<a[i].size();j++)
            e[i+a.size()][j]=b[i][j]; 
            
             for(int i=0; i<a.size(); i++)
            for(int j=0; j<a[i].size();j++)
            e[i+a.size()][j+a[i].size()]=a[i][j]; 
            
          
            
           for(int i=0; i<a.size(); i++)
            for(int j=0; j<a[i].size(); j++)
            e[i+a.size()][j+(2*a[i].size())]=b[i][j];   
        
            
             for(int i=0; i<a.size(); i++)
            for(int j=0; j<a[i].size();j++)
              e[i+2*a.size()][j]=d[i][j];
            
            for(int i=0; i<a.size(); i++)
            for(int j=0; j<a[i].size(); j++)
            e[i+2*a.size()][j+a[i].size()]=c[i][j];
            
            
            for(int i=0; i<a.size(); i++)
            for(int j=0; j<a[i].size(); j++) 
            e[i+2*a.size()][j+2*a[i].size()]=d[i][j];
    
    
    return e; 
}

int main () {
    int br_redova;
    int br_kolona; 
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>br_redova >> br_kolona;
    if(br_kolona <0 || br_redova <0 ) {
        std::cout <<"Dimenzije matrice moraju biti nenegativne!";
        return 0; 
    }
   
    Matrica a(KreirajMatricu(br_redova, br_kolona));

   std::cout << "Unesite elemente matrice: ";
     for(int i = 0; i < br_redova; i++)
        for(int j = 0; j < br_kolona; j++)  
       
     std::cin >> a[i][j];    

 
   try {

std::cout<<std::endl<<"Rezultantna matrica:" <<std::endl; 
       
   
     a=(OgledaloMatrica(a)); 
  
     
     for(int i=0; i<a.size(); i++) {
     for(int j=0; j<a[i].size(); j++) {
     std::cout << std::setw(4)<< a[i][j] ; }
     std::cout<<std::endl; 
     }


    }catch (std::domain_error izuzetak) {
        std::cout<<"IZUZETAK: " << izuzetak.what() << std::endl; 
    }

return 0;
}

