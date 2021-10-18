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
typedef std::vector<int> IntVektor;
IntVektor IzdvojiGadne(IntVektor a, bool opaki){
	IntVektor b;
	int temp,nula,jedan,dva;
	for(int i=0;i<a.size();i++){
		nula=0;
		jedan=0;
		dva=0;
		temp=a[i];
		do{
			if(temp%3==0)nula++;
			else if(std::abs(temp%3)==1)jedan++;
			else if(std::abs(temp%3)==2)dva++;
			temp=temp/3;
		} while(temp!=0);
		if(opaki){
			if(nula%2==0 && jedan%2==0 && dva%2==0){
				bool isti(true);
				 for(int j=0;j<b.size();j++){
				 	if(a[i]==b[j]) isti=false;
				 }
				 if(isti) b.push_back(a[i]);
			}
		}
		else if ((nula%2==1 || nula==0)&&(jedan%2==1 || jedan==0)&&(dva%2==1 || dva==0)){
			bool isti(true);
			for(int j=0;j<b.size();j++){
			 	if(a[i]==b[j]) isti=false;
			}
			if(isti) b.push_back(a[i]);
		}
	}
	return b;
}
int main ()
{
	IntVektor a,b;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int x;
	std::cin>>x;
	while(x!=0){
		a.push_back(x);
		std::cin>>x;
	}
	b = IzdvojiGadne(a,true);
	std::cout<<"Opaki: ";
	for(int i:b) std::cout<<i<<" ";
	b = IzdvojiGadne(a,false);
	std::cout<<"\nOdvratni: ";
	for(int i:b) std::cout<<i<<" ";
	return 0;
}