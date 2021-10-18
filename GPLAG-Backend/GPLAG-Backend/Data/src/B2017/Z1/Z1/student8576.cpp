#include <iostream>
#include <vector>
/*
bool JeLiSimetrican(int broj) {
	int cifra=0;
	int n=broj;
	while(n!=0) {
		cifra*=10;
		cifra+=n%10;
		n/=10;
	}
	if(cifra==broj) return true;
	return false;
}
*/
std::vector<int> PretvoriUTernarne(int n) {
	int x=n;
	std::vector<int> novi;
		while(x!=0) {
			int ostatak=x%3;
			novi.push_back(ostatak);
			x/=3;
		}
		
	return novi;
}

bool prosti (int n) {
	int prosti=true;
	for(int i=2; i<n; i++) {
		if(n%i==0) {
			prosti=false;
			break;
		}
	}
	if(prosti==true) return true;
	else return false;
}

bool JeLiSimetrican(std::vector<int> a) {
	
	int cifra(0);
	long int n=a.at(0);
	while(n!=0) {
		cifra*=10;
		cifra+=n%10;
		n/=10;
	}
	if(cifra==a.at(0)) return true;
	return false;
	
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool a) {
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;
	
	if(a==true) {
	 for(int i=0; i<v.size(); i++) {
	 	int n=v.at(i);
	 	bool b;
	 	b=prosti(n);
	 	if(b==true) v1.push_back(n);
	 }
	 
	 for(int j=0; j<v1.size(); j++) {
	 	int k=v1.at(j);
	 	std::vector<int> m= PretvoriUTernarne(k);
	 	bool d;
	 	d=JeLiSimetrican(m);
	 	std::cout<<d;
	 	}
	 }
	 /*
	if(a==false) {
		for(int i=0; i<v.size(); i++) {
			int m=v.at(i);
			bool c;
			c=prosti(m);
			if(c==false) v2.push_back(m);
		}
	}
	*/
 return v1;
}

int main ()
{
	std::vector<int> v;
	int n;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	for(;;) {
		std::cin>>n;
		if(n==-1) break;
		v.push_back(n);
	}
	int a;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>a;
	if(a==1) {
		std::vector<int> v1=IzdvojiSimetricneTernarne(v,true);
		for(int i=0; i<v1.size()-1; i++) {
			for(int j=i+1; j<v1.size(); j++) {
				if(v1.at(i)==v1.at(j)) {
					v1.erase(v1.begin()+j);
					j--;
				}
			}
		}
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<v1.size(); i++) {
			std::cout<<v1.at(i)<<" ";
		}
	}
	else if(a==0) {
		std::vector<int> v2=IzdvojiSimetricneTernarne(v,false);
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<v2.size(); i++) {
			std::cout<<v2.at(i)<<" ";
		}
	}
	
	return 0;
}
