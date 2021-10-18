/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/

#include <iostream>
#include<vector> 
#include<iomanip> 
#include<stdexcept>
#include<cmath>

bool JesuLiJednaki(double a, double b, double Eps=1e-10){
	             if(std::fabs(a-b)<Eps)
	             return true; 
	             return false;
}

 typedef  std::vector<std::vector<double>> Matrica; 
 
Matrica  KreirajMatricu(int broj_redova, int broj_kolona) {
	    
	         return Matrica(broj_redova, std::vector<double> (broj_kolona)); 
}


Matrica UnesiMatricu(int broj_redova, int broj_kolona) {
	
	             Matrica  a(broj_redova, std::vector<double> (broj_kolona)); 
	             std::cout << "Unesite elemente matrice: " << std::endl; 
	             for(int i=0; i<broj_redova; i++) {
	             	for(int j=0; j<broj_kolona; j++) {
	             		std::cin >> a.at(i).at(j); 
	             	}
	             }
	             
	           return a; 
}

 bool GrbavaMatrica (Matrica m ) {
 	   
 	    int broj_kolona=m[0].size(); 
 	    for(int i=1; i<m.size(); i++ ) {
 	    	
 	    	if(broj_kolona!=m.at(i).size()) return false; 
 	    }
 	 return true; 
 }
 
 
void IspisiMatricu(Matrica m) {
	  
	    for(int i=0; i<m.size(); i++) {
	    	for(int j=0; j<m.at(0).size(); j++) {
	    	 std::cout << std::setw(6) << m.at(i).at(j);
	    	}
	    	std::cout << std::endl; 
	    }
} 
 
 
 
Matrica  NajvecaPlaninaMatrice(Matrica m) {
	      
	       if( m.size()==0 || m.at(0).size()==0) return m; 
	 if(GrbavaMatrica(m)==false) throw std::domain_error ("Matrica nije korektna"); 


          if(m.size()<3 || m.at(0).size()<3) {
          	Matrica y;
          	y=KreirajMatricu(1,1);
          	double naj=m.at(0).at(0);
          	for(int i=0; i<m.size(); i++) {
          		
          		for(int j=0; j<m[0].size(); j++){
          			if(naj<m.at(i).at(j)) {
          				naj=m.at(i).at(j);
          			}
          			
          		}
          	}
          	   y.at(0).at(0)=naj;
          	   return y; 
          }
          	
          

	 
	 /* e sada ovdje izracunala prvu  najvecu planinu */ 
	 
  	int  maksimalni_broj_obilazaka=0, koordinata_i=0, koordinata_j=0, maksimalni_vrh=0; 
	 bool a= false, nesto=false; 

	 
	
	 for(int i =1; i<m.size()-1; i++ ){
	 	   for(int j =1; j<m.at(0).size()-1; j++) {
	 	   	    
	 	   	    
	 	   	  /* moram ovdje napraviti  for petlju za krug obilaska */ 
	 	   	  int krug_kolona=0;  
	 	   	  
	 	   	  if(j<((m.at(0).size()-1)-j)) krug_kolona=j; 
	 	   	  else if(j>((m.at(0).size()-1)-j)) krug_kolona=m.at(0).size()-1-j; 
	 	   	   else if(j==(m.at(0).size()-1-j)) krug_kolona=j; 
	 	   	     
	 	   	  int krug_redova=0; 
	 	   	  
	 	   	  if(i<m.size()-i-1) krug_redova=i; 
	 	   	    else if(i>m.size()-1-i) krug_redova=m.size()-1-i; 
	 	   	    else if(i==m.size()-1-i) krug_redova=i; 
	 	   	    
	 	   	    
	 	   	   int krug=0; 
	 	   	     
	 	   	     if(krug_kolona<=krug_redova) krug=krug_kolona; 
	 	   	     else krug=krug_redova; 
	 	   	       
	 	   	       /*nakon sto sam se odlucila kolko puta se moze maksimalno obici  a to nam govori
	 	   	        promjenjiva krug sada obilazim i gledam kolko puta ce se najvise obici
	 	   	        i racunam sume krugova*/
	 	   	        
	 	   	        
	 	   	        
	 	   	      
	 	   	        
	 	   	        
	 	   	        int k;
	 	   	       int  suma2=0; 
	 	   	       for( k=1; k<=krug; k++) {
	 	   	       	/* ovdje ce izrcunati sumu pojdinacnog reda */
	 	   	       	  int suma =0; 
	 	   	       	  for( int l=i-k; l<=i+k; l++) {
	 	   	       	  	   
	 	   	       	  	  suma+=m.at(l).at(j-k); 
	 	   	       	  	 
	 	   	       	  }
	 	   	       	
	 	   	       	   
	 	   	       	  for( int l=i-k; l<=i+k; l++){
	 	   	       	  	suma+=m.at(l).at(j+k);
	 	   	       	  	
	 	   	       	  }
	 	   	       
	 	   	       	  for(int l=j-k+1; l<=j+k-1; l++){
	 	   	       	  	suma+=m.at(i-k).at(l);
	 	   	       	  
	 	   	       	  }
	 	   	       	  
	 	   	       	  for(int  l=j-k+1; l<=j+k-1; l++){
	 	   	       	  	suma+=m.at(i+k).at(l);
	 	   	       	  
	 	   	       	  }
	 	   	       	 
	 	   	           if(JesuLiJednaki(suma, m.at(i).at(j))) {
	 	   	           	k--; 
	 	   	           	break; 
	 	   	           }
	 	   	    
	 	   	             if( k==1  && suma>m.at(i).at(j) )   { 
	 	   	       	    k--; 
	 	   	       	   break; 
	 	   	       	   }
	 	   	       	   nesto =false; 
	 	   	       	   if(k==1  && suma < m.at(i).at(j)) {
	 	   	       	   	suma2=suma; 
	 	   	       	   	nesto=true; 
	 	   	       	   
	 	   	       	   }
	 	   	       	  
	 	   	       	   if( k>1 &&  suma>suma2) {
	 	   	       	    
	 	   	       	   k--; 
	 	   	       	   break;
	 	   	       	   }
	 	   	       	   if(k>1 && suma<suma2) {
	 	   	       	   	 suma2=suma; 
	 	   	       	   	
	 	   	       	   }
	 	   	       }
	 	   	      
	 	   	      if(k>krug && nesto==false) k--; 
	 	   	       if (nesto==true) k--;
	 	   	      maksimalni_broj_obilazaka=k; 	   
	 	   	     if(k>=1) {
	 	   	     	
	 	   	      	a=true; 
	 	   	     	maksimalni_vrh=m.at(i).at(j);
	 	   	     	koordinata_i=i; 
	 	   	     	koordinata_j=j; 
	 	   	     	break;
	 	   	     }
	 	   	       	   
	 	   	           	  
	 	   }	  
	 	 
	 	  if(a==true) break; 
	 }
	 
	 
  /* 	 std::cout <<" maksimalni_broj_obilazaka "  <<  maksimalni_broj_obilazaka  <<
	   " maksimalni_vrh " << maksimalni_vrh <<std::endl <<
	 "a taj element se nalazi na kordinatama " << koordinata_i << koordinata_j; */
	 
	 
	 
	   // ovdje cu sve prepisati  
	   
  	     bool nesto1=false;
	     int broj_obilazaka=0; 
	  
	      for(int i=1; i<m.size()-1; i++) {
	   	  for(int j=1; j<m.at(0).size()-1; j++){
	   	  	
	   	  	int krug_kolona=0;
	   	  	if(j<((m.at(0).size()-1-j))) krug_kolona=j;
	   	  	else if(j>((m.at(0).size()-1-j))) krug_kolona=m.at(0).size()-1-j;
	   	  	else if(j==(m.at(0).size()-1-j)) krug_kolona =j;
	   	  	
	   	    int krug_redova=0; 
	   	    if(i<((m.size()-1-i))) krug_redova=i; 
	   	    else if(i>(m.size()-i-1)) krug_redova=m.size()-1-i; 
	   	    else if(i==(m.size()-i-1)) krug_redova=i; 
	   	  
	   	  	
	   	  	int krug=0; 
	   	  	if(krug_redova <=krug_kolona) krug=krug_redova; 
	   	  	else krug=krug_kolona; 
	   	  	
	   	  	
	   	  	
	   	  	int k; 
	   	  	int suma2=0; 
	   	  	
	   	  	broj_obilazaka=0; 
	   	  	
	   	  	for(k=1; k<=krug; k++ ) {
	   	  		int suma=0; 
	   	  
	   	    for(int l=i-k; l<=i+k; l++ ) {
	   	    	 suma+=m.at(l).at(j-k); 
	   	    }
	   	    for(int l=i-k; l<=i+k; l++ ){
	   	    	 suma+=m.at(l).at(j+k);
	   	    }
	   	    for(int l=j-k+1; l<=j+k-1; l++){
	   	    	  suma+=m.at(i-k).at(l);
	   	    }
	   	    
	   	    for(int l=j-k+1; l<=j+k-1; l++) {
	   	    	suma+=m.at(i+k).at(l); 
	   	    }
	   	    if(JesuLiJednaki(suma,m.at(i).at(j))){
	   	    	k--;
	   	    	break; 
	   	    }
	   	    
	   	    if(k==1 && suma>m.at(i).at(j)) {
	   	    	k--;
	   	    	break;
	   	    }
	   	    nesto1=false;
	   	    if(k==1 && suma<m.at(i).at(j)) {
	   	    	suma2=suma; 
	   	    	nesto1=true;
	   	    }
	   	    if(k>1 && suma>suma2) {
	   	    	k--; 
	   	    	break; 
	   	    }
	   	    if(k>1 && suma<suma2) {
	   	    	suma2=suma; 
	   	    }
	   	  	}
	   	  	
	   	  	
	   	  	
	   	  	 if(k>krug && nesto1 == false) k--;
	   	  	
	   	  if(nesto1==true){
	   	  	k--;
	   	  }	
	   	  
	   	  if(k>=1) {
	   	  broj_obilazaka=k;
	   	  
	   	  
	   	  if(broj_obilazaka>maksimalni_broj_obilazaka) {
	   	  	maksimalni_broj_obilazaka=k; 
	   	  	koordinata_i=i;
	   	  	koordinata_j=j;
	   	   maksimalni_vrh=m.at(i).at(j);
	   	  	
	   	  }
	   	  
	   	  
	   	  
	   	  if(broj_obilazaka==maksimalni_broj_obilazaka) {
	   	  	  if(maksimalni_vrh <m.at(i).at(j))  {
	   	  	  	    maksimalni_vrh=m.at(i).at(j);
	   	  	  	    koordinata_j=j;
	   	  	  	    koordinata_i=i;
	   	  	  	    maksimalni_broj_obilazaka=broj_obilazaka;    
	   	  	  }
	   	  	  
	   	  	  
	   	  	 if(JesuLiJednaki(maksimalni_vrh,m.at(i).at(j))) {
	   	  	 	    if(koordinata_i>i) {
	   	  	 	    	 koordinata_i=i; 
	   	  	 	    	 koordinata_j=j; 
	   	  	 	    	 maksimalni_vrh=m.at(i).at(j);
	   	  	 	    }
	   	  	 	    if(koordinata_i==i) {
	   	  	 	    	if(koordinata_j>j) {
	   	  	 	    		
	   	  	 	    		koordinata_j=j; 
	   	  	 	    		koordinata_i=i;
	   	  	 	    	
	   	  	 	    	}
	   	  	 	    	
	   	  	 	    }
	   	  	 	
	   	  	 }
	   	  	
	   	  }
	   	  	 	    	}
	   	  
	   	  
	   	  
	   	  
	   	  
	   	  
	   	 
	   	  
	   	  }
	   }
	  
	 
	
	 
	 
   /*std::cout <<  "maksimalni_broj_obilazaka " << maksimalni_broj_obilazaka
	     << "koordinata_i "<< koordinata_i <<"koordinata_j" <<  koordinata_j << "maksimalni_vrh" << maksimalni_vrh;
	    
	     std::cout << std::endl;    */
	     
	     
	     
	    int  b=0, c=0;
  	   Matrica x; 
  	   x=KreirajMatricu(maksimalni_broj_obilazaka*2+1, maksimalni_broj_obilazaka*2+1);   
  	   for(int i=koordinata_i-maksimalni_broj_obilazaka; i <=koordinata_i+maksimalni_broj_obilazaka ; i++ ) {
  	   	    c=0; 
  	   	  for(int j=koordinata_j-maksimalni_broj_obilazaka; j<=koordinata_j+maksimalni_broj_obilazaka; j++){
  	   	    x.at(b).at(c)=m.at(i).at(j); 
  	   	   
  	   	    c++;
  	   	  }
  	   b++;
  	   
  	   } 
  	   
  	
  	  
  	  
  	   	       
  	   	  
  	  return x;  
  	  
  	 
 
 }
	  
	 
	 

int main ()  {
	
	 try {
	 
	 std::cout << "Unesite dimenzije matrice (m i n): "; 
	 int m,n; 
	 std::cin >> m >> n; 
	 if(m<0 || n<0) {
	 	std::cout << "Dimenzije matrice moraju biti nenegativne!" ; 
	 	return 0; 
	 }
	 Matrica mat; 
	  mat=KreirajMatricu(m,n); 
	  
	 mat=UnesiMatricu(m,n); 
	// IspisiMatricu(mat);
	 Matrica NajvecaPlanina=(NajvecaPlaninaMatrice(mat)); 
     std::cout << "Najveca planina unesene matrice je: " << std::endl;
	 IspisiMatricu(NajvecaPlanina);
	  
	 
	 
	 }
	 catch (std::domain_error izuzetak) {
	 	  std::cout << izuzetak.what() << std::endl; 
	 }
	return 0;
}