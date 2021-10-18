
#include <iostream>
#include <vector>
#include <cmath>
#include<stdexcept>


using std::vector;

vector<int> IzdvojiGadne(vector<int> v, bool a) {
	vector<int> novi;
	for(int i=0; i<v.size(); i++) {
		int brojac2(0);
		int brojac1(0);
		int brojac0(0);
		
		long int j=fabs(v[i]);
		while(j!=0) {
			if(j%3==2) brojac2++;
			if(j%3==1) brojac1++;
			if(j%3==0) brojac0++;
			j=j/3;
		
		}
	
		if((brojac2%2==0 || brojac2==0) && (brojac1%2==0 || brojac1==0) && (brojac0%2==0 || brojac0==0)  && a==true) novi.push_back(v[i]);
		else if((brojac2%2!=0 || brojac2==0) && (brojac1%2!=0 || brojac1==0) && (brojac0%2!=0 || brojac0==0) && a==false) novi.push_back(v[i]);
	}
	int j;
	for(int i=0; i<novi.size(); i++) {
	for(j=i+1; j<novi.size(); j++) {
	
		if (novi[i]==novi[j]) {
			novi.erase(novi.begin()+j);
			j--;
		}
	}
	}
	/*for(int i=0; i<novi.size(); i++)
	for(int j=i+1; j<novi.size(); j++) {
		if (novi[i]==novi[j]) novi.erase(novi.begin()+j);
	}*/

	return novi;
}
int main ()
{	
	vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int p;
	do {
		std::cin>>p;
		if(p!=0) v.push_back(p);
	}
	while (p!=0);
	std::cout<<"Opaki: ";
	for(int i=0; i<IzdvojiGadne(v, 1).size(); i++) {
		std::cout<<IzdvojiGadne(v, 1)[i]<<" ";
	}
	std::cout<<std::endl;
		std::cout<<"Odvratni: ";
	for(int i=0; i<IzdvojiGadne(v, 0).size(); i++) {
		std::cout<<IzdvojiGadne(v, 0)[i]<<" ";
	}
	std::cout<<std::endl;

	return 0;
}