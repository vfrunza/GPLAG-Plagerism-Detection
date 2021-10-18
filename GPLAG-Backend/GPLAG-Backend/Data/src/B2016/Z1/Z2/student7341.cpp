/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/ 

#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>


typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica( Matrica a){
    Matrica prosirena;
    if(a.size()==0) return prosirena;
    
    prosirena.resize(3*a.size());
    if(a[0].size()==0) return prosirena;
    
    for(int i=0;i<prosirena.size();i++) prosirena[i].resize(3*(a[0].size()));
    
   //provjera da li je grbava
   
    for(int i=0; i<a.size();i++){
       if (a[0].size()!=a[i].size())  throw std::domain_error ("Matrica nije korektna");
   
    }
    //pravis vertiklanu
    Matrica vertikalna(a.size(),std::vector<double>(a[0].size()));
    int j(0);
    for(int i=a.size()-1;i>=0;i--) {
        vertikalna.at(j)=a.at(i);
    	   j++;
    }
    
    
     // pravis horizontaalnu   k ide kroz redove, i kroz kolone
    Matrica horizontalna (a.size(),std::vector<double>(a[0].size()));
    for(int i=a[0].size()-1;i>=0;i--){
   	 	  for(int k=0;k<a.size();k++){
   	 	      horizontalna[k][i]=a[k][(a[0].size())-1-i];
   	     }
    }
   
   //pravis kombinovanu, mijenjas redove horizontalne
    Matrica kombi (a.size(),std::vector<double>(a[0].size()));
    int z(0);
    for(int i=a.size()-1;i>=0;i--){
    	   kombi.at(z)=horizontalna.at(i);
    	   z++;
    }
    
    //kombinovanu prosirujes sa vertiklanom i kombinovanom jos jednom
    Matrica kombi2=kombi;
    for(int i=0;i<a.size();i++){
    	for(int k=0;k<a[0].size();k++){
    	kombi2.at(i).push_back(vertikalna[i][k]);
    	}
    	for(int l=0;l<a[0].size();l++){
    	kombi2.at(i).push_back(kombi[i][l]);
    	}
    }
    
    
    //horizontalnu prosirujes sa pocetnom i jos jednom horizontalnom
    Matrica horizontalna2=horizontalna;
    for(int i=0;i<a.size();i++){
    	   for (int k=0; k<a[0].size();k++){
    	       horizontalna2.at(i).push_back(a[i][k]);
    	   }
    	   for(int l=0;l<a[0].size();l++){
    	      horizontalna2.at(i).push_back(horizontalna[i][l]);
    	   }
    }
    
    //konaca prosirena matrica
    for (int i=0;i<a.size();i++){
    	    prosirena[i]=kombi2[i];
         prosirena[i+a.size()]=horizontalna2[i];  
         prosirena[i+(2*a.size())]=kombi2[i];
    }
    	  
    	  
return prosirena ;

	
}

int main (){
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
	   std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	   return 0;
	}
 std::cout<<"Unesite elemente matrice: ";
	Matrica a(m, std::vector<double>(n));
	
	for(int i=0;i<m;i++){
		   for(int j=0;j<n; j++){
			      std::cin>>a[i][j];
		   }
	}
	
	
	try {
	  auto prosirena=OgledaloMatrica(a);
	
	
	  //ispis matrice
  	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
	  for(int i=0; i<prosirena.size();i++){
	     	for(int j=0; j<prosirena[0].size();j++){
			         std::cout<<std::setw(4)<<prosirena[i][j];
		     }
      	std::cout<<std::endl;	
		 }
	
	}
	
	catch (std::domain_error izuzetak) {
	       std::cout<< izuzetak.what() <<std::endl;
	}
	
	
	return 0;
}