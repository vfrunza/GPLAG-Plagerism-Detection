//B 2016/2017, Zadaća 1, Zadatak 1

#include <iostream>
#include <vector>
#include <cmath>

//pretvaranje brojeva u ternarne
std::vector<int> Pretvori(int a)
{
	std::vector<int> v(3);
	if(a==0)
	return v;
	while(a!=0){
		if(a%3==0)
		v[0]++;
		else if(a%3==1 || a%3==-1)
		v[1]++;
		else if(a%3==2 || a%3==-2)
		v[2]++;
		a=a/3;
		}

	
	return v;
}


std::vector<int> BezPonvaljanja (std::vector<int> v)
{
	std::vector<int> x;
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v[j]==v[i]) {
				v.erase(v.begin() + j);
				j--;
			}
		}
		x.push_back(v[i]);
	}
	return x;
}


std::vector<int> IzdvojiGadne(std::vector<int> v, bool a)
{
	std::vector<int> v_novi(BezPonvaljanja(v)); // formiramo novi vektor bez ponavljanja brojeva
	std::vector<int> x;
	std::vector<int> NoviVektor;
		if (a==0) {
		for(int i=0; i<v_novi.size(); i++) {
			x=Pretvori(v_novi[i]);
			if((x[0]%2==1 || x[0]==0) && (x[1]%2==1 || x[1]==0) && (x[2]%2==1 || x[2]==0)) 
				NoviVektor.push_back(v_novi[i]);
		}
		return NoviVektor;

	}
	if(a) {
		for(int i=0; i<v_novi.size(); i++) {
			x=Pretvori(v_novi[i]);
			if(x[0]%2==0 && x[1]%2==0 && x[2]%2==0 && (x[0]!=0 || x[1]!=0 || x[2]!=0))
				NoviVektor.push_back(v_novi[i]);
			}
		return NoviVektor;
	}
	

	return NoviVektor;
}


int main()
{
	int n;
	std::vector<int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	while(std::cin >> n, n!=0)
		v.push_back(n);
	for(int a=1; a>=0; a--) {
		if(a) {
			std::vector<int> novi(IzdvojiGadne(v, a));
			std::cout << "Opaki:";
			for(int x: novi) std::cout << " " << x;
		} else if(a==0) {
			std::vector<int> novi(IzdvojiGadne(v, a));
			std::cout << "Odvratni:";
			for(int x: novi) std::cout << " " << x;
		}
		std::cout << std::endl;
	} 

	return 0;
}
