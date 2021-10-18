#include <iostream>
#include <vector>
#include <cmath>
#include <deque> 

bool DaLiJeProst (int x) {
	if(x<=1) return false;
	for(int i=2;i<=sqrt(x);i++) {
		if(x%i==0)
		return false;
	}
	return true;
}
std::vector<int> ProstiBrojevi(std::vector<int> v) {
	std::vector<int> prosti;
	for(int i=0;i<v.size();i++) {
		if(DaLiJeProst(v.at(i))) {
			prosti.push_back(v.at(i));
		}
		
	}
	return prosti;
}
std::vector<int> SlozeniBrojevi(std::vector<int> v) {
	std::vector<int> slozeni;
	for(int i=0;i<v.size();i++) {
		if(DaLiJeProst(v.at(i))==false) {
			slozeni.push_back(v.at(i));
		}
		
	}
	return slozeni;
}


bool SimetricniTernari (int x) {
	
	x=abs(x);
	 std::vector<int> v;
	while(x!=0) {
		int c=x%3;
		x/=3;
    v.push_back(c);
	}
	for(int j=0;j<v.size()/2;j++) {
	 if(v.at(j)!=v.at(v.size()-1-j)) {
	 	return false;
	 }
	
 }
	return true;
	 
  }

std::vector<int> IzdvojiSimetricneTernare (std::vector<int> v, bool istinitost) {
	std::vector<int> simetricni1;
	if(istinitost) {
		std::vector<int> prosti=ProstiBrojevi(v);
		for(int i=0;i<prosti.size();i++) {
			if(SimetricniTernari(prosti.at(i))) {
				simetricni1.push_back(prosti.at(i));
			}
		}
		return simetricni1;
	}
	else {
		std::vector<int> simetricni2;
		std::vector<int> slozeni=SlozeniBrojevi(v);
		for(int i=0;i<slozeni.size();i++) {
			if(SimetricniTernari(slozeni.at(i))) {
				simetricni2.push_back(slozeni.at(i));
			}
		}
		return simetricni2;
	}
}
int main ()
{
	int x;
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
	std::cin>>x;
	v.push_back(x);
	if (x==-1) break;
	} while(x!=-1);
	v.resize(v.size()-1);
	int n;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
	std::cin>>n;
	 if(n==0 || n==1) break;
	 std::cout<<"Neispravan unos! Unesite ponovo: ";
	} while(n!=0 || n!=1);
	
	std::vector<int> simetricni=IzdvojiSimetricneTernare(v,n);
	
	if(n==1) {
		if(simetricni.size()==0) {
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		}
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	for(int i=0;i<simetricni.size();i++) {
		if(i==simetricni.size()-1) {
			std::cout<<simetricni.at(i)<<".";
		}
		else {
		std::cout<<simetricni.at(i)<<", ";
	    }
	}
}
}
   else {
   	if(simetricni.size()==0) {
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		}
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0;i<simetricni.size();i++) {
		if(i==simetricni.size()-1) {
			std::cout<<simetricni.at(i)<<".";
		}
		else {
		std::cout<<simetricni.at(i)<<", ";
	    }
        	}
       }
   	
   }
	
	
	return 0;
}



