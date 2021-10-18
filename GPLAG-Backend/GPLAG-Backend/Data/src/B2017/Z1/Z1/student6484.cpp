/*B 2017/2018, Zadaća 1, Zadatak 1
	
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
#include<cmath>



 std::vector<int>   IzdvojiSimetricneTernarne(std::vector<int> v, bool a ) {
   	          
   	          
   	                   std::vector<int> pomocni; 
   	                   /* vektor pomocni nam sluzi da u njega ubacujemo ili sve
   	                     proste ili sve slozene brojeve , nebitno jesu li pozitivni ili negativni */
   	                     
   	                   
   	                   
   	                for(int i= 0 ; i < v.size(); i++){
   	                	 
   	                	 int p ; /* ako je elemenat pocetnog vektora negativan da vise ne bude i 
   	                	  to postizem promjenjivom p */
   	                	 
   	                	 if( v.at(i)<0) p=v.at(i)*(-1); 
   	                	 else  p=v.at(i); 
   	                	 if(p==1) continue; 
   	                	  
   	                	   bool    n=true; 
   	                	   /* ako je a true znaci da nam trebaju prosti , a  ako je 
   	                	    n false znaci da nam trebaju slozeni*/
   	                   for(int j=2; j<=std::sqrt(p); j++) {
   	                   	   if(p % j==0)  {
   	                   	   	n=false;
   	                   	   	break; 
   	                   }
   	                   } 
   	                   
   	                    if(a==true && n==true) {
   	                    	pomocni.push_back(v.at(i)); 
   	                    	
   	                    }
   	                    if(a==false && n==false) {
   	                    	pomocni.push_back(v.at(i)); 
   	                    }
   	                   
   	                   }
   	                   
   	                 /* u gornjem dijelu zadatka sam napravila vektor pomocni u kojeg sam stavljala 
   	                 ili proste ili slozene u zavisnoti od promjenjive a*/
   	                
   	         
   	         
   	         
   	           /* sada izbacujem  duplikate iz pomocnog */ 
   	           
   	           for(int i = 0 ;  i < pomocni.size()-1; i++) {
   	           	
   	           	       for( int j=i+1; j<pomocni.size(); j++){ 
   	           	       	if(  pomocni.at(i)==pomocni.at(j)) {
   	           	       		 // e sada ovdje izbacujem 
   	           	               for( int k=j;k<pomocni.size()-1; k++) {
   	           	               	        pomocni.at(k)=pomocni.at(k+1); 
   	           	               }
   	           	               pomocni.resize(pomocni.size()-1); 
   	           	       	}
   	           	       }
   	           	      }  
   	           
   	          /* sada ovdje  pravim vektor terarnih brojva i prebacujem sve u ternarni */
   	           
   	              std::vector<int>  vst; 
   	            for(int i = 0 ; i < pomocni.size(); i++) {
   	            	     
   	            	        int m; 
   	            	      if(pomocni.at(i)<0) m= pomocni.at(i)*(-1); 
   	            	      else  m = pomocni.at(i); 
   	            	     
   	            	     std::vector<int> pomocni2;
   	            	         
   	            	          while(m>0) {
   	            	          	 pomocni2.push_back(m%3); 
   	            	          	m=m/3; 
   	            	          
   	            	          }
   	            	      
   	 
   	            	        // sad ovdje ispitam je li simetrican  vektor pomocni2; 
   	            	            bool z=true; 
   	            	            int y=pomocni2.size()-1;
   	            	           
   	            	        for(int x=0 ;x< pomocni2.size()/2; x++) {
   	            	        	if(pomocni2.at(x) != pomocni2.at(y)) {
   	            	        		z=false; 
   	            	        		break ; 
   	            	        	}
   	            	        	y--; 
   	            	        }
   	            	 if(z==true)   vst.push_back(pomocni.at(i)); 
   	            }
   	           return vst; 
   }

int main ()   {
	 
	 std::vector<int> v;
	 std::cout << "Unesite elemente vektora (-1 za kraj):";
	 
	 
	  for(;;) {
	  	 int elemenat; 
	  	 std::cin >> elemenat; 
	  	 if(elemenat!=-1)
	  	 v.push_back(elemenat);
	  	 else
	  	 break; 
	  	 
	  }
	  
	  
	 
	   int w; 
	 std::cout << " Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: "; 
	    for(;;) {
	      
	         std::cin>>w; 
	        if(w==0 || w==1) break; 
	        else 
	        std::cout <<"Neispravan unos! " << "Unesite ponovo: "; 
	    }	
	   
	
	 bool q=true; 
	 if(w==1) q=true; 
	 if(w==0) q=false; 
	 
	 auto vek=IzdvojiSimetricneTernarne(v, q); 
	 if (q==true) {
	 	  if(vek.size()==0) {
	 	  	
	 	  	std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	 	  }
	 	  else {
	 	std::cout << "Prosti simetricni brojevi iz vektora su: ";
	 	for(int i=0; i<vek.size(); i++) {
	 	  if(i==vek.size()-1) std::cout << vek.at(i) << ".";
	 	  else 
	 	  std::cout  << vek.at(i) << ", "; 
	 }	
	 }
	 	
	 }
	 else {
	 	  if(vek.size()==0) {
	 	  	
	 	  	std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	 	  }
	 	  else {
	 std::cout << "Slozeni simetricni brojevi iz vektora su: "; 
	    	for(int i=0; i<vek.size(); i++) {
	  if(i==vek.size()-1) std::cout << vek.at(i) <<"."  ; 
	  else  
	   std::cout << vek.at(i) << ", ";
	 
	 }
	 }
	 }
	 
	return 0;
}