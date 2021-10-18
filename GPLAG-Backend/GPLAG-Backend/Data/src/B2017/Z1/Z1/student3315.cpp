#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <deque>


int Simetrican_broj(int broj){
	std::deque <int> dek1; 
	std::deque <int> dek2;
	int cifra;
	int i=0;
	while(broj!=0){
		cifra=broj%3;
		dek1.push_back(cifra);
		dek2.push_front(cifra);
		broj/=3;
		i++;
	}
	
	for(int i=0;i<dek1.size();i++){
		if(dek1.at(i)!=dek2.at(i)){
			return 0;
		}
	}
	return 1;
}

int prost_broj(int broj){

	for(int i=2;i<=sqrt(broj);i++){
		if(broj%i==0){
			return 0;
		}
	}
	return 1;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vektor,bool logicka){
	
	std::vector<int> rezultat;
	
	
	
	
	
	if(logicka){ 
	
	int a,b;
	for(int i=0;i<vektor.size();i++){
		
		if(vektor.at(i)<0){
			a=prost_broj(vektor.at(i)*(-1));
			b=Simetrican_broj(vektor.at(i)*(-1));
		}
		else{
			a=prost_broj(vektor.at(i));
			b=Simetrican_broj(vektor.at(i));
		}
	
	  if(a==1 && b==1){
	  	rezultat.push_back(vektor.at(i));
	  }
	}
	
	return rezultat;
	}
	
	else{
		int c,d;
		for(int j=0;j<vektor.size();j++){
			if(vektor.at(j)<0){
			c=prost_broj(vektor.at(j)*(-1));
			d=Simetrican_broj(vektor.at(j)*(-1));
			}
	    	else{
				c=prost_broj(vektor.at(j));
				d=Simetrican_broj(vektor.at(j));
			 }
		if(c==0 && d==1){
			rezultat.push_back(vektor.at(j));
		}	
			
		}
		
		return rezultat;
	}
}

int main ()
{
  std:: vector<int> vektor;
  int n;
  std::cout<<"Unesite elemente vektora (-1 za kraj): ";
  do{
    std::cin>>n;
    if(n==(-1))
    break;
    
    while(!std::cin){
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    std::cin>>n;
    }
    
    vektor.push_back(n);
  }while(1);
  
  int k;
  
  std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
  do{
  
  std::cin>>k;
  
  if(k==0 || k==1)
  break;
  
  else{
  	std::cout<<"Neispravan unos!";
  	std::cout<<" Unesite ponovo: ";
  	
  }
  
  }while(1);
  
    std::vector<int> novi_vektor;
    
	if(k==1){
		novi_vektor=IzdvojiSimetricneTernarne(vektor,true);
		
		if(novi_vektor.size()==0){
		std::cout<<"Nema prostih simetricnih brojeva u vektoru."<<std::endl;	
		}
		
	  
		
		else{
			
			int velicina1=novi_vektor.size();
			for(int r=0;r<novi_vektor.size();r++){
				if(velicina1==1 && novi_vektor.at(r)==0){
					return 0;
				}
				else 
				break;
			}
			
			
			
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int t=0;t<novi_vektor.size();t++){
			
			if((t<novi_vektor.size()-1) && t>=0){
				std::cout<<novi_vektor.at(t)<<", ";
			}
			else{
				std::cout<<novi_vektor.at(t)<<"."<<std::endl;
			}
		}
		
		}
	}
	
	
	else{
		novi_vektor=IzdvojiSimetricneTernarne(vektor,false);
		
		if(novi_vektor.size()==0){
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru."<<std::endl;
		}
		else{
			
			int velicina2=novi_vektor.size();
			for(int a=0;a<novi_vektor.size();a++){
				if(velicina2==1 && novi_vektor.at(a)==0){
					return 0;
				}
				else break;
				
			}
			
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int c=0;c<novi_vektor.size();c++){
			if(c<novi_vektor.size()-1 && c>=0){
				std::cout<<novi_vektor.at(c)<<", ";
			}
			else{
				std::cout<<novi_vektor.at(c)<<"."<<std::endl;
			}
		}
		
		}
		
		
	}
	return 0;
}