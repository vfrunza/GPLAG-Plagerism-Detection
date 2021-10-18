#include <iostream>
#include <vector> 

std::vector<int> IzdvojiGadne (std::vector<int> v, bool t) {
	int broj, tcifra;
	long long int ternarni=0, brojac;
	std::vector<int> v1;
	
	for(int i=0; i<v.size(); i++) {
		
		ternarni=0;
		broj=v[i];
		brojac=1;
		while(broj!=0) {
			
			tcifra=broj%3;
			
			
			ternarni+=tcifra*brojac;
			
			brojac=brojac*10;
			
			broj=broj/3;
			
		}
	
	int nizbrojaca[10]={0};
	
	int cifra, opak, odvratan;
	while(ternarni!=0) {
		cifra=abs(ternarni)%10;
		
		nizbrojaca[cifra]++;
		ternarni=ternarni/10;
	}
	
	opak=1;
	for(int j=0; j<10; j++) {
		if(nizbrojaca[j]%2!=0) opak=0;
	}
	
	odvratan=1;
	for(int z=0; z<10; z++) {
		if(nizbrojaca[z]%2==0 && nizbrojaca[z]!=0) odvratan=0;
	}
	nizbrojaca[10]={0};
	
	if(t==true && opak==1) v1.push_back(v[i]);
	
	if(t==false && odvratan==1) v1.push_back(v[i]);
	
	}
	int k=v1.size();
	
	for(int i=0; i<k-1; i++) {
	
		for(int j=i+1; j<k; j++) {
			if(v1[i]==v1[j]) {
				for(int z=j; z<k-1; z++)
				v1[z]=v1[z+1];
		        k--;
		        j--;
		
            }
		}
	}
	v1.resize(k);

	return v1; 
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v, v1;
	int a;
	std::cin >> a;
	while(a!=0) {
		v.push_back(a);
		std::cin >> a;
		}

	
	v1=IzdvojiGadne(v, true);
	std::cout << "Opaki: ";
	for(int i=0; i<v1.size(); i++)
	std::cout << v1[i] << " ";
	std::cout<<std::endl;
	v1=IzdvojiGadne(v, false);
	std::cout << "Odvratni: ";
	for(int i=0; i<v1.size(); i++)
	std::cout << v1[i] << " ";
	
	
	return 0;
}