//B 2016/2017, Zadaća 1, Zadatak 4
	
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>



std::string  ObrniFraze(std::string s, std::vector<std::string> vs) {
	      
	           	for(int i=0; i<vs.size() ; i++) {
	         
	         	std::string pomocni=vs[i]; 
	     	        int j=0;
	            for( j=0; j<s.length(); j++) {  
		        int k=0;
		        int a=j;
		        if(pomocni[k]==s[j]  && (j==0 || s[j-1]==' ')) { 
	  	         
	  	          
	  	     while( pomocni[k]==s[j] &&  ( k<pomocni.size() && j<s.size()  )){
 	  	     	k++;
	  	       	j++;
	  	  	} 
		      
		      if(k==pomocni.size() && ( j==s.size()  || s[j]==' '  || s[j]==',' || s[j]=='.')) {
		      	 int b=j; 
		     	for (int l=0; l<=(b-a)/2; l++) {
		         char pok=s[a]; 
                s[a]=s[b-1];
                 s[b-1]=pok;
                 a++;
                 b--;
                 }
		      }
		      	}
	
	            }
	           	}


   return s; 
}



 std::string   IzmijeniUPigLatin(std::string s, std::vector<std::string> vs ) {
 	 
 	           for(int i=0; i<vs.size(); i++) {
 	           	    std::string pomocni= vs[i]; 
 	           	      
 	           	    for(int j=0; j<s.length(); j++) {
 	           	    	
 	           	    	int k=0; 
 	           	    	int a=j; 
 	           	    	if(pomocni[k]==s[j] && ( j==0 || s[j-1] == ' ' ) ) {
 	           	    		
 	           	     	while(pomocni[k]== s[j] && k<pomocni.size() && j<s.size()) {
 	           	    			k++;
 	           	    			j++;
 	           	    		}
 	           	    		
 	           	    		if ( k==pomocni.size() && (j==s.size() ||  s[j]== '.'  || s[j] == ',' || s[j]== ' ') ){
 	           	    		    int b=j;
 	           	    		     
 	           	    		       char ubaci=s[a];
 	           	    		      for(int l=a; l<s.size();l++)
 	           	    		             s[l]=s[l+1];
 	           	    		             s.resize(s.size()+2);
 	           	    		        
 	           	    		          
 	           	    		    	for(int r=s.size()-1; r>=b-1;r--)	 
 	           	    		    	 s[r]=s[r-3];
 	           	    		    	 s[b-1]=ubaci;
 	           	    		    	 s[b]='a';
 	           	    		    	 s[b+1]='y';
 	           	    		    
 	           	    		}
 	           	    	}
 	           	    	
 	           	    }
 	           } 
 	     
 	 return s;
 	
 }  
int main ()
{
	std::cout<<"Unesite recenicu: "; 
	std::string recenica; 
	std::getline(std::cin, recenica); 
        
        
      std::cout<<"Unesite fraze: ";
	std::vector<std::string> vektorstringova; 

	 
	for(;;) {
			std::string unesi; 
		std::getline(std::cin, unesi);
	
     	vektorstringova.push_back(unesi);
        
	}

	
    std::string  recenica1=recenica;
      recenica=(IzmijeniUPigLatin(recenica,vektorstringova));
    	std::cout<<std::endl<<recenica;
    	recenica1=(ObrniFraze(recenica1,vektorstringova));
	return 0;
}