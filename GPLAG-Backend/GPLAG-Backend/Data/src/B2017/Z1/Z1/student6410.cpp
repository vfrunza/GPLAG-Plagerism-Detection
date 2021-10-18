
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst (int n){ 
	bool prost=true;
	if(n<=1) prost=false;
	else{
		for(int i=2; (unsigned int) (i*i)<=n; i++){
			if(n%i==0) prost=false;
		}
	}
	return prost;
}

std::vector<int> ternarnibr1(std::vector<int> ter1){
	std::vector<int> pom;
	int broj=0;
	for(int i=0; i<ter1.size(); i++){
		int pomocni(ter1.at(i));
		do{
			broj=broj+pomocni%3;
			pomocni=pomocni/3;
			broj=broj*10;
		} while(pomocni!=0);
		broj=broj/10;
		pom.push_back(broj);
		broj=0;
	}
	return pom;
}

std::vector<int> ternarnibr2(std::vector<int> ter2){
	std::vector<int> pom1;
	int ostatak;
	int broj=0;
	int b(-1);
	for(int i=0; i<ter2.size(); i++){
		int pomocni(ter2.at(i));
		do{
			b++;
			ostatak=pomocni%3;
			pomocni=pomocni/3;
			ostatak=ostatak*pow(10,b);
			broj=broj+ostatak;
			ostatak=0;
		}while(pomocni!=0);
		pom1.push_back(broj);
		ostatak=0;
		b=-1;
		broj=0;
	}
	return pom1;
}


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool broj){
	std::vector<int> pomocni1; 
	std::vector<int> pomocni2;
	

		for(int i=0; i<v.size(); i++){
			int prosti=v.at(i);
		if((DaLiJeProst(prosti))==true)
	pomocni1.push_back(prosti);
else pomocni2.push_back(prosti);
		}
		
		std::vector<int> simetrican;
		if(broj==true){
			std::vector<int> prosti1(ternarnibr2(pomocni1));
			std::vector<int> prosti2(ternarnibr1(pomocni1));
			for(int i=0; i<pomocni1.size(); i++){
				int a=prosti1.at(i);
				int b=prosti2.at(i);
				if(a==b) simetrican.push_back(pomocni1.at(i));
			}
		}
		else {
			std::vector<int> slozeni1(ternarnibr2(pomocni2));
			std::vector<int> slozeni2(ternarnibr1(pomocni2));
			for(int i=0; i<pomocni2.size(); i++){
				int a=slozeni1.at(i);
				int b=slozeni2.at(i);
				if(a==b) simetrican.push_back(pomocni2.at(i));
			}
		}
	
return simetrican;
	
}

int main ()
{ std::cout<<"Unesite elemente vektora (-1 za kraj): ";
std::vector<int> v;
int a;
	do{
		std::cin>>a;
		if(a==-1) break;
	else	v.push_back(a);
	} while(a!=-1);
	
	int broj;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>broj;
	if(broj!=0 && broj!=1){
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin>>broj;
	}
	
	if(broj==1){
		std::vector<int> v1=IzdvojiSimetricneTernarne(v,true);
		if(v1.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else{
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<v1.size(); i++){
					if(i==v1.size()-1) std::cout<<v1.at(i)<<".";
			else	std::cout<<v1.at(i)<<", ";
	
				
			}
				
		}
	}
	 if(broj==0){
	 		std::vector<int> v2=IzdvojiSimetricneTernarne(v,false);
		if(v2.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else{
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<v2.size(); i++){
					if(i==v2.size()-1) std::cout<<v2.at(i)<<".";
				else std::cout<<v2.at(i)<<", ";
			
				
			}
		}
	 }
	
	return 0;
} 