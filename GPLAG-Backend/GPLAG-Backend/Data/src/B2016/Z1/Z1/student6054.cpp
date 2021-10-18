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
std::vector<int> IzdvojiGadne(std::vector<int> v, bool x ){
std::vector<int> konacni;
for (int i=0;i<v.size();i++) {	
	int brojac0(0),brojac1(0),brojac2(0);
	int temp=abs(v[i]);
	do{if(temp%3==0){
		brojac0++;
	}
	if(temp%3==1){
		brojac1++;
		
	}
	if (temp%3==2){
		brojac2++;
		
}
		temp=temp/3;
	}
while(temp!=0);
if (brojac1%2==0&& brojac0%2==0&& brojac2%2==0 && x==1) {
	konacni.push_back(v[i]);}
else if((brojac2%2!=0 || brojac2==0)&&(brojac0%2!=0||brojac0==0)&&(brojac1%2!=0||brojac1==0)&& x==0) {
	konacni.push_back(v[i]);}
	
}
if(konacni.size()==0 || konacni.size()==1) return konacni;
for(int i=0;i<konacni.size()-1;i++){
	int temp=konacni[i];
	for(int j=i+1;j<konacni.size();j++){
		if (temp==konacni[j]){
		konacni.erase(konacni.begin()+j);
		j--;
		}
	}
	
}
return konacni;}

int main ()
{
	std::vector<int> a  ;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int temp;
	std::cin>>temp;
	while(temp!=0){
		a.push_back(temp);
		std::cin>>temp;
		
		
	}
	
	std::vector<int> opaki,odvratni ;
	opaki=IzdvojiGadne(a,1);
	odvratni=IzdvojiGadne(a,0);
	std::cout<<"Opaki: ";
	for(int x:opaki)std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int i=0;i<odvratni.size();i++){
		std::cout<<odvratni[i]<<" ";
	}
	return 0;
}