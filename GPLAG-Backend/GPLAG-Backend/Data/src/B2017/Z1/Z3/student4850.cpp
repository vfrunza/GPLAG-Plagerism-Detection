/*B 2017/2018, Zadaća 1, Zadatak 3
	
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
#include<deque>
#include<cmath>
  
 enum  podniz {Rastuci,Opadajuci} ;
   
   
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke( std::vector<int> v, 
                                         podniz a) {
  	                      
  	 
                     std::deque<std::vector<int>> dv;
  	                    
  	                for(int i=0; i<v.size(); i++) {
  	                
  	                    std::vector<int> pomocni; 
  	                    int j;
  	                    int l=0; 
  	                 	for( j=i; j<v.size(); j++) {
  	                 		
  	                 	  
  	                 	     int proizvod=1; 
  	                 	     bool jeste = false;
  	                 	    for(int k=1; k<=v[j]; k++) {
  	                 
  	                 	    	proizvod*=2;
  	                 	    	if( v[j]==1 || proizvod==v[j]){
  	                 	    		jeste=true; 
  	                 	    		break; 
  	                 	    	}
  	                 	    }
  	                 	     if(jeste == false) {
  	                 	     
  	                 	     	    i=j; 
  	                 	            break;  
  	                 	    
  	                 	     } 
  	                 	     else   {
  	                 	     
  	                 	     	 
  	                 	  if( l==0 ) {
  	                 	   	pomocni.push_back(v[j]);
  	                 	   } 
  	                 	      
  	                 	     if(l>0) {
  	                 	   if(jeste==true && a==Rastuci  && v[j]>v[j-1]) {
  	                 	   	   pomocni.push_back(v[j]);
  	                 	   	 
  	                 	   }
  	                 	     else if (jeste==true && a==Opadajuci && v[j]<v[j-1]) {
  	                 	   	
  	                 	 
  	                 	   	
  	                 	   	pomocni.push_back(v[j]);
  	                 	   }
  	                 	   else 
  	                 	   {
  	                 	   	
  	                 	   	j--;
  	                 	   	
  	                 	   	
  	                 	   	break;
  	                 	   }
  	                 	   
  	                 	     }
  	                 	     }
                       l++;
  	                 	}
  	                 
  	                 if(pomocni.size()>1) {
  	                 dv.push_back(pomocni);	
  	                 }
  	                 if(j==v.size()) break;
  	                 if( j<v.size()) i=j;
  	                  
  	                 
  	                }
  	                 
  	                
  	      return dv; 
  	               
  	                 }
                

  	                 	
int main () { 
	
	int n; 
	std::cout << "Unesite broj elemenata vektora: "; 
	std::cin >> n; 
	std::vector<int> v; 
	
	std::cout <<"Unesite elemente vektora: "; 
	for(int i = 0 ; i<n; i++) {
		
		int element; 
	  std::cin >> element; 
	  v.push_back(element);
	}
	  
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: " ;
	 int pomocna; 
	 std::cin >> pomocna;
	  
     podniz b=Rastuci;
	  
	   if(pomocna==1) 
	   	
	   	b=Rastuci; 
	  
	   else b=Opadajuci;

	
	

  std::deque<std::vector<int>> dv{MaksimalniPodnizoviStepenaDvojke(v ,b)};
    if(b==Rastuci && dv.size()>0) {
    	
    	std::cout <<"Maksimalni rastuci podnizovi: "<<std::endl;
    }
    if(b==Opadajuci && dv.size()>0) {
    	std::cout << "Maksimalni opadajuci podnizovi: "<< std::endl;
    }
     	
      for(int i=0; i<dv.size(); i++){
      	    for( int j=0; j<dv[i].size(); j++){
      	    	
      	    	std::cout << dv[i][j] << " ";
      	    }
      	    std::cout << std::endl; 
      } 
	
	return 0;
}