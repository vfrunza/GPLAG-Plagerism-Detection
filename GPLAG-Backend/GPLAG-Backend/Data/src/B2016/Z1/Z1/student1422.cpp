#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <limits>

typedef std::vector<int> Vektor;

Vektor PretvoriUTernarni(Vektor v){
	Vektor n(0,0);
	for(int x:v){
		if(x!=0){
		int pom(0),var(0),i(0);
		do{
			pom=x%3;
			x/=3;
			var+=pom*pow(10,i);
			i++;
		}while(x!=x%3);
		int y(var+x*pow(10,i));
		if(y<std::numeric_limits<int>::max() && y>std::numeric_limits<int>::lowest())
		n.push_back(y);
		}
		else if(x==0) n.push_back(x);
	}
	return n;
}

Vektor Cifre(int x){
	Vektor pom;
	do{
		pom.push_back(x%10);
		x/=10;
	}while(x!=0);
	return pom;
}

bool ParanBrojPuta(Vektor v){
	Vektor brojaci(3,0);
	//ako je cifra iz vektora ista kao index brojaca, povecava brojac sa tim indexom
	for(int a:v){
		a=abs(a);
		for(int i=0;i<int(brojaci.size());i++){
			if(a==i)
			brojaci.at(i)++;
			
			if(i==int(brojaci.size())) break;
		}
	}
	//ako neki od brojaca nije paran broj vraca false
	for(int i=0;i<int(brojaci.size());i++){
		if(brojaci.at(i)!=0 && brojaci.at(i)%2!=0)
		return false;
	}
	return true;
}

bool NeparanBrojPuta(Vektor v){
	Vektor brojaci(10,0);
	//ako je cifra iz vektora ista kao index brojaca, povecava brojac sa tim indexom
	for(int a:v){
		a=abs(a);
		for(int i=0;i<int(brojaci.size());i++){
			if(a==i)
			brojaci.at(i)++;
		}
	}
	//ako neki od brojaca nije paran broj vraca false
	for(int i=0;i<int(brojaci.size());i++){
		if(brojaci.at(i)!=0 && brojaci.at(i)%2==0)
		return false;
		if(i==int(brojaci.size())) break;
	}
	return true;
}

Vektor VratiUDekadni(Vektor v){
	Vektor novi(0,0);
	for(int x:v){
		Vektor pom(0,0);
		pom=Cifre(x);
		int suma(0);
		for(int i=0; i<int(pom.size());i++){
		suma+=pom.at(i)*pow(3,i);
		
		if(i==int(pom.size())) break;
		}
		novi.push_back(suma);
		}
		return novi;
}

Vektor IzbaciDuple(Vektor v){
	for(int i=0;i<int(v.size())-1;i++){
		for(int j=i+1;j<int(v.size());j++)
		if(v[i]==v[j]){
		v.erase(v.begin()+j);
		j--;
		}
	}
	return v;
}

Vektor Opaki(Vektor v){
	Vektor pomocni(PretvoriUTernarni(v)),novi(0,0);
	for(int a:pomocni){
		Vektor tmp(Cifre(a));
		if(ParanBrojPuta(tmp))
			novi.push_back(a);
	}
	return VratiUDekadni(novi);
}

Vektor Odvratni(Vektor v){
	Vektor pomocni(PretvoriUTernarni(v)),novi(0,0);
	for(int a:pomocni){
		Vektor tmp(Cifre(a));
		if(NeparanBrojPuta(tmp))
			novi.push_back(a);
	}
	return VratiUDekadni(novi);
}

Vektor IzdvojiGadne(Vektor v, bool log){
	Vektor v1(IzbaciDuple(v));
	if(log==true) return Opaki(v1);
	return Odvratni(v1);
}

int main () {
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	Vektor v(0);
	do{
		int el(0);
		std::cin>>el;
		if(el==0) break;
		else v.push_back(el);
	}while(1);
	Vektor v1(IzdvojiGadne(v,true));
	std::cout<<"Opaki: ";
	for(int x:v1) std::cout<<x<<" ";
	std::cout<<std::endl;
	Vektor v2(IzdvojiGadne(v,false));
	std::cout<<"Odvratni: ";
	for(int x:v2) std::cout<<x<<" ";
	std::cout<<std::endl;
	return 0;
}