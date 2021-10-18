#include<iostream>
#include<vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
	
	std::vector<std::vector<double>> V;
	std::vector<double> vektor;
	
	for(int i=0; i<=v.size()-1; ){
		
		if(i==0) {  if(v.at(i)<=v.at(i+1)) { vektor.push_back(v.at(i)); i++; }
                      else i++;
                      continue;
		}
		
		
	    if(i==v.size()-1) {  if(v.at(v.size()-1)>=v.at(v.size()-2)) vektor.push_back(v.at(v.size()-1));
                              break;	    
	}
	
	if(v.at(i)<=v.at(i+1)) { vektor.push_back(v.at(i)); i++; }
	
	else if(v.at(i)>=v.at(i-1)) { 
		
		vektor.push_back(v.at(i)); 
		i++; 
        V.push_back(v);
        v.resize(0);
        
	}
		
	}
	
	
   return V;
	
}



int main ()
{
    
    std::vector<std::vector<double>> M;	
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	 
	std::cin>>n;
	
	std::cout<<"Unesite elemente vektora: ";
	
	std::vector<double> v;
	int y;
	
	for(int i=0; i<n; i++){
		
		std::cin>>y;
		v.push_back(y);
		
	}
	 
	std::cout<<"Maksimalni rastuci podnizovi: ";
	
	M=RastuciPodnizovi(v);
	
	for(int i=0; i<M.size(); i++){
		for(int j=0; j<M[0].size(); j++)
		
		std::cout<<M[i][j];
		
		std::cout<<std::endl;
	}
	
	return 0;
}