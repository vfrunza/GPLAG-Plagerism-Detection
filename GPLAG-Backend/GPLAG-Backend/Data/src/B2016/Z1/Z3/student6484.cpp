
#include<iostream>
#include<vector>
#include<iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v) {
	        Matrica Mat;
	      
          
	      
	          
	        for( int  i=0; i<v.size()-1; i++) {

	        		std::vector<double> pomocni;
	        		int j=i;
	        	
	        		 
	        		 while (j<v.size()-1  && v[j]<=v[j+1]){
                    	pomocni.push_back(v[j]);
	        		   j++;
	        		 }
	        	
	        		 pomocni.push_back(v[j]);
	        		 
	        		
	        	    
	        		 
	        		 
	        	    if(pomocni.size() > 1 ) {
	        	      Mat.push_back(pomocni);
	        	    } 
	        	    pomocni.resize(0); 
	        	   
	        	  
	             
	                   i=j;
	        	     
	        	}
	        
	     
	        
	    return Mat;
	
}
  
 Matrica OpadajuciPodnizovi(std::vector<double> v) {
	  
	  Matrica Mat; 
	  
	  for( int i=0; i<v.size()-1; i++) {
	  	std::vector<double> pomocni; 
	  	int j=i; 
	  	
	  	while( j<v.size()-1 && v[j]>=v[j+1]) {
	  		pomocni.push_back(v[j]);
	  		j++;
	  	}   
	  	 
	  	  pomocni.push_back(v[j]);
	        		
	  	
	  	
	  	  if(pomocni.size()>1  ) {
	  	     Mat.push_back(pomocni); 
	  	  } 
	  	  pomocni.resize(0);
	  	  
	  	  
	  	  
	  	 
	  	  i=j;
	  }
	  
	
	  	
	  return Mat; 
	
}   
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: "; 
	int n; 
	std::cin >> n; 
	
	std::vector<double> vektor;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		double element; 
		std::cin >> element;
		vektor.push_back(element);
	
	}
	
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl; 
	Matrica  Mat(RastuciPodnizovi(vektor)); 
	
	for(int i=0; i<Mat.size(); i++) {
		for(int j=0; j<Mat[i].size(); j++)
		std::cout<< Mat[i][j] << " ";  
		std::cout << std::endl; 
	}
	
	
 	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl; 
	Matrica Mat1(OpadajuciPodnizovi(vektor)); 
	
  	for(int i=0; i<Mat1.size(); i++) {
		for(int j=0; j<Mat1[i].size(); j++)
		std::cout <<Mat1[i][j] << " "; 
		std::cout << std::endl; 
	}  
	  

      
	    

	return 0;
}   


