#include <iostream>
#include <vector>
#include <limits>
bool DaLiJeProst(int n) {
	
	int max = std::numeric_limits<int>::max();
	if(n<=1) return false;
	for(int i=2;(unsigned int)(i*i)<=n;i++){
		if((unsigned int)(i*i)>=max) return true;
		if(n%i==0) {
		return false;
		}
	}
	
		return true;
}

std::vector<int> IzdvojiSimetricneTernarne( std::vector<int> V1, int ps){
	std::vector<int> VP;
	std::vector<int> VS;
	std::vector<int> VSP;
	std::vector<int> VSS;
	
	for(int i=0;i<V1.size();i++){
		if(DaLiJeProst(V1.at(i))==true)
		VP.push_back(V1.at(i));
		else 
		VS.push_back(V1.at(i));
	}

	
	if(ps==true){
		
		for(int i=0;i<VP.size();i++){
			std::vector<int> vektorcifara;
			int cifra2,cifra;
			bool simetricni(true);
			cifra2=VP.at(i);
			do{
			cifra=cifra2;
			cifra = cifra%3;
			vektorcifara.push_back(cifra);
			cifra2=cifra2/3;
			} while(cifra2 != 0);
			
			for(int i=0;i<vektorcifara.size();i++){
				if(vektorcifara.at(i)!=vektorcifara.at(vektorcifara.size()-i-1))
				simetricni=false ;
			}
			    if (simetricni==true) {
		     	VSP.push_back(VP.at(i));
			}
		}
		
	} else if (ps==false)	{
			
		for(int i=0;i<VS.size();i++){
			std::vector<int> vektorcifara;
			bool simetricni(true);
			int cifra2,cifra;
			cifra2=VS.at(i);
			do{
			cifra=cifra2;
			cifra = cifra%3;
			vektorcifara.push_back(cifra);
			cifra2=cifra2/3;
			} while(cifra2 != 0);
			
			for(int i=0;i<vektorcifara.size();i++){
				if((vektorcifara.at(i))!=vektorcifara[vektorcifara.size()-i-1])
				simetricni=false ;
			}
			    if (simetricni==true)
		    	VSS.push_back(VS.at(i));
		}
	}
	std::vector<int> vektor;
	if(ps==true){
		for(int i=0;i<VSP.size();i++){
			bool vecPostoji=false;
			int var=VSP.at(i);
			for( int j=i;j<VSP.size();j++){
				if (var==VSP.at(j) && i!=j){
				vecPostoji=true;
			}
			}
			if(!vecPostoji)	vektor.push_back(VSP.at(i));
			
		}
	} else if (ps==false) {
		for(int i=0;i<VSS.size();i++){
			bool vecPostoji=false;
			int var=VSS.at(i);
			for( int j=i;j<VSS.size();j++){
				if (var==VSS.at(j) && i!=j){
					vecPostoji=true;
				}
			}
				if(!vecPostoji) vektor.push_back(VSS.at(i));
			}
		}
		return vektor;
}


int main () {
	int a;
	std::vector<int> V1;
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	
	do {
	std::cin>>a;
	if(a==-1) break;
	V1.push_back(a);
	} while(a!=-1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int ps;
	do{
	std::cin>>ps;
	if(ps!=1 && ps!=0) std::cout<<"Neispravan unos! Unesite ponovo: ";
	
	}while(ps!=1 && ps!=0);
	
    std::vector<int> vektor(IzdvojiSimetricneTernarne(V1,ps));
	if(ps==true) {
		if(IzdvojiSimetricneTernarne(V1,ps).size() == 0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
		std::cout<<"Prosti simetricni brojevi iz vektora su: " ;
		for(int i=0;i<vektor.size();i++){
			if(i==vektor.size()-1) std::cout<<vektor.at(i)<<".";
			else
			std::cout<<vektor.at(i)<<", ";
		}
	} else {
		if(IzdvojiSimetricneTernarne(V1,ps).size() == 0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<vektor.size();i++){
			if(i==vektor.size()-1) std::cout<<vektor.at(i)<<".";
			else
			std::cout<<vektor.at(i)<<", ";
		}
	}
	
	return 0;
}