/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> IzdvojiGadne(std::vector<int> Niz, bool tacnost){
	if(Niz.size()==0) return Niz;
	std::vector<int> Opaki;
	std::vector<int> Odvratni;
		for(int i=0;i<Niz.size()-1;i++){
			for(int j=i+1;j<Niz.size();j++){
			if(Niz[i]==Niz[j]){
			Niz.erase(Niz.begin()+j);
			j--;
					}
			}
		}
		
		int brojac1(0);
			int brojac2(0);
			int brojac3(0);
	for(int i=0;i<Niz.size();i++){
		int pomocna=Niz[i];
	if(Niz[i]==0) continue;
		do {

			if((std::abs(pomocna)%3)==0) 
			brojac1++;
			if((std::abs(pomocna)%3)==1)
			brojac2++;
			if((std::abs(pomocna)%3)==2) 
			brojac3++;
			pomocna/=3;
			}
			while(pomocna!=0);
			if(brojac1%2==0 && brojac2%2==0 && brojac3%2==0) 
		
			Opaki.push_back(Niz[i]);
			
	
		   if((brojac1%2!=0 || brojac1==0) && (brojac2%2!= 0 || brojac2==0) && (brojac3%2!=0 || brojac3==0))
			Odvratni.push_back(Niz[i]);

			brojac1=0;
			brojac2=0;
			brojac3=0;
	}

	
	if(tacnost)

	return Opaki;
	
	else 
	return Odvratni;
}
int main () {	
	std::vector<int> Niz;
	int broj;
	std::vector<int> b;
	std::vector<int> c;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>broj;
		if(broj!=0)
	Niz.push_back(broj);
	}
	while(broj!=0);

	b=IzdvojiGadne(Niz,true);
	std::cout<<"Opaki: ";
	for(int x : b){
		
	
	std::cout<<x<<" ";
}
std::cout<<std::endl;
	c=IzdvojiGadne(Niz,false);
	std::cout<<"Odvratni: ";
	for(int y : c) {

	std::cout<<y<<" ";
	
}
	
	return 0;
}