/*B 2017/2018, Zadaća 1, Zadatak 4
	
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
#include<string>


 std::string NapraviPalindrom(std::string s, std::vector<std::string> vs) {
	    
	    for(int i=0; i<vs.size(); i++)  {
	      	   
	      	    std::string pomocni(vs.at(i));   // pravim string koji se naziva pomocni i u njega kupim elemnt vektora vs
	      	    
	      	   
	      	     std::string pomocni2 (pomocni);  // pravim novi string  pomocni2
	      	  
	      	     int y=0; 
	      	     for( int  x=pomocni.size()-1; x>=0; x--) {  // u taj novi koji se  zove pomocni2 stavljam obrnuti stari
	      	     	
	      	     	pomocni2.at(y)=pomocni.at(x); 
	      	     	y++; 
	      	     }
	      	     
	      
	      	   for(int j=0; j<s.length(); j++) {  // sada ulazim u recenicu
	      	   	        
	      	   	        if(( pomocni.at(0) == s.at(j) )  && ( j==0 || s.at(j-1)==' '))  {  
	      	   	    
	      	   	                    int k=0; 
	      	   	                    
	      	   	                    while( k<pomocni.size() && j<s.size() && (pomocni.at(k)==s.at(j))) { // sve dok su isti da ide i kroz jedan i drugi 
	      	   	                    	   k++; 
	      	   	                    	   j++; 
	      	   	                    }
	      	   	                   // ako sam dosla do  kraja pomocnog stringa, tj  nasla  pomocnog stringa u gavnom stringu 
	      	   	             if(k==pomocni.size() && ( j==s.size() ||  !((s.at(j)>='a' && s.at(j)<='z') || (s.at(j)>='A' && s.at(j)<='Z')))) { 
	      	   	             	 // sada trebam napraviti prostor za  obrnutu rijec
	      	   	             	  
	      	   	             	 s.resize(s.size()+pomocni.size());   //mijenjam velicinu 
	      	   	             	 
	      	   	             	 int l=s.size()-1; 
	      	   	             	 
	      	   	             	 
	      	   	             	 // pravim prostor za novi string 
	      	   	             	 while (l>=j) { 
	      	   	             	        s.at(l)=s.at(l-pomocni.size()); 
	      	   	             	        l--;
	      	   	             	 	 }
	      	   	             	// e sada ovdje trebam ubaciti pomocni 2 
	      	   	                for (int m=0; m<pomocni2.size(); m++) {
	      	   	                	s.at(j)=pomocni2.at(m); 
	      	   	                	j++; 
	      	   	                   
	      	   	                	
	      	   	                }
	      	   	             }
	      	   	        }
	      	   	       // sad se ovdje trebam potruditi da lijepo se nastavi onj string s 
	      	   	        
	      	   	        }
	      	   	      
	    }  
	      	   return s; 
	      }
	  
  
  std::string NapraviPoluPalindrom( std::string s, std::vector<std::string> vs) {
  	           
  	           
  	           
  	            std::string pomocni, pomocni2; 
  	        
  	         for(int i =0;   i <vs.size(); i++) {  
  	         	std::string pomocni(vs.at(i)); 
  	         	std::string pomocni2(pomocni); 
  	         
  	         	pomocni2.resize(pomocni2.size()/2);   
  	         	
  	         
  	         	  
  	         	   int l=pomocni2.size()-1; 
  	         	for(int k=0; k<pomocni2.size()/2; k++) {  
  	         		     char bezz  = pomocni2[l]; 
  	         		     pomocni2.at(l)=pomocni2.at(k); 
  	         		     pomocni2.at(k)=bezz; 
  	         		     l--; 
  	         	} 
  	         
  	       
  	      
  	         for(int j= 0; j<s.size(); j++) {  
  	         	
  	         	
           if((pomocni.at(0)==s.at(j)) && (j==0 || s.at(j-1)==' ')) {  
           	
           	 int n=0; 
           	  
           	   while(  n<pomocni.size() && j<s.size() && pomocni.at(n)==s.at(j))  { 
           	   	     n++;
           	   	     j++;
           	   } 
           	   
           	   if(n==pomocni.size() && (j==s.size() || (!(( s.at(j)>='a' && s.at(j)<='z')  || (s.at(j)>='A' && s.at(j)<='Z')) ))) { {  
           	   	   
           	   	  
           	   	       j=j-pomocni2.size(); 
           	   	   
           	   	       for(int o=0; o<pomocni2.size(); o++) {
           	   	       	s.at(j)=pomocni2.at(o); 
           	   	       	j++;           	   	    
           	   	       	}
           	   	   
           	   }            
	      	   	                	
	      	   	              
           }
	      	   	       } 
	      	   	       
  	         }
          
  	         }
 return s;
}


  	          
  
  
  
  
  int main ()  {
  	
  	
  	 /* sa ovim sam unijela recenicu */ 
  	std::string recenica; 
	std::cout << "Unesite recenicu: "; 
	std::getline(std::cin , recenica); 
/*	std::cin.clear(); 
	std::cin.ignore(10000, '\n');  */
	
	 /* sada cu unosti vektor fraza */ 
	 
	std::vector<std::string> vektor_stringova; 
	  
	std::cout << "Unesite fraze: "; 
	
	  for(;;) {
	  	std::string fraza; 
	  	std::getline(std::cin,fraza); 
	  	if(fraza=="") break;  // ovo znaci prazan string 
	  	else 
	  	vektor_stringova.push_back(fraza); 
	  	
	  	
	  }
     std::string recenica2(recenica);
	 recenica= NapraviPalindrom(recenica,vektor_stringova);
	 std::cout <<"Recenica nakon Palindrom transformacije: " << recenica << std::endl; 

    recenica=NapraviPoluPalindrom(recenica2, vektor_stringova); 
	 std::cout << "Recenica nakon PoluPalindrom transformacije: "<< recenica; 
	return 0;
}