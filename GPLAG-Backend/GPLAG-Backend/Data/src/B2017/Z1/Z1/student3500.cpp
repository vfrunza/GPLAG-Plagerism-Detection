#include<iostream>
#include<vector>
#include<cmath>


bool DaLiJeProst(int n){
	
	if(n<2) return false;
	
	for(int i(2);i<=std::sqrt(n);i++)
	 if(n%i==0) return false;
	 
	 return true;
	
}

bool SimetricanUTernarnom(int n){
	
	int ternarnibroj(0),i(1),brojcifara(0);
	
	while(n!=0){
		
		ternarnibroj+=(n%3)*i;
		n/=3;
		i*=10;
		brojcifara++;
     	}
	
 int ternarni(ternarnibroj),obrnuti(0);
 
 
 for(int i(std::pow(10,brojcifara-1));i>0;i/=10){
 	
 	obrnuti+=(ternarnibroj%10)*i;
 	ternarnibroj/=10;
 }

	if(ternarni==obrnuti) return true;
	 return false;
}

 std::vector<int> IzbaciDuplikate(std::vector<int> vektor){
 	
 for(int i(0);i<vektor.size();i++)
   for(int j(i+1);j<vektor.size();j++)
 	 
 	 if(vektor.at(i)==vektor.at(j)) vektor.erase(vektor.begin()+j);
 	
 	return vektor;
 }
 
 
 
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool prost){
	
	std::vector<int> prosti,slozeni;
	
	if(prost) {
		
		for(int x:v) {
			
			if(x<0 && DaLiJeProst(-x) && SimetricanUTernarnom(-x)) prosti.push_back(x); 
				 else if(DaLiJeProst(x) && SimetricanUTernarnom(x)) prosti.push_back(x);
			}
		}
		
	else{
		
		for(int x:v){
			
			if(x<0 && !(DaLiJeProst(-x)) && SimetricanUTernarnom(-x)) slozeni.push_back(x);
			 else if(!(DaLiJeProst(x)) && SimetricanUTernarnom(x)) slozeni.push_back(x);
		}
	}	
	
	
	if(prost) return IzbaciDuplikate(prosti);
	 
	 else return IzbaciDuplikate(slozeni);
	
	
}



int main ()
{   
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	int x;
	
	do{
		std::cin>>x;
		v.push_back(x);
	}while(x!=-1);
	
	v.resize(v.size()-1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	int a;
	
	std::cin>>a;

	while(a!=1 && a!=0){
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>a;
	}
	
	
	if(a){
	  
	  if(IzdvojiSimetricneTernarne(v,a).size()==0)  std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	    
	    else {
	    	std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	    	
	    	for(int i(0);i<IzdvojiSimetricneTernarne(v,a).size();i++){
	    		
	    		if(i==IzdvojiSimetricneTernarne(v,a).size()-1) std::cout<<IzdvojiSimetricneTernarne(v,a).at(i)<<".";
	    		
	    		 else  std::cout<<IzdvojiSimetricneTernarne(v,a).at(i)<<", ";
	    		
	    	}
	    }
	}
	
	else{
		
		
		if(IzdvojiSimetricneTernarne(v,a).size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		 
		 else{
		 	
		 	std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		 	
		 	for(int i(0);i<IzdvojiSimetricneTernarne(v,a).size();i++){
		 		
		 		if(i==IzdvojiSimetricneTernarne(v,a).size()-1) std::cout<<IzdvojiSimetricneTernarne(v,a).at(i)<<".";
		 		
		 		else std::cout<<IzdvojiSimetricneTernarne(v,a).at(i)<<", ";
		 	   
		 		
		 	}
		 }
	 }
	 
	return 0;
}