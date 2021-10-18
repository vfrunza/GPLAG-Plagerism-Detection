/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int>a, bool tacnost) {
	std::vector<int>v;
	std::vector<int>u;
	std::vector<int>c;
	std::vector<int>b;
	for(int i=0; i<a.size(); i++) {
		if(i==a[i]) break;
		int cifra;
		double ostatak;
		int brojac1=0;
		int brojac2=0;
		int brojac3=0;
		int broj=a[i];
		if(a[i]<0){
			a[i] = a[i]*(-1);
		}
		while(a[i]>0) {
			ostatak=a[i]/3;
			cifra=a[i]-int(ostatak)*3;
			if(cifra==0){
				brojac1 ++;
			}
			if(cifra==1) {
				brojac2 ++;
			}
			if(cifra==2) {
				brojac3 ++;
			}
			a[i]=int(ostatak);
			
		}
	
		if(brojac1%2==0 && brojac2%2==0 && brojac3%2==0){
			u.push_back(broj);
		}
		else if(brojac1>0 && brojac2>0&&brojac3==0 && brojac1%2!=0 && brojac2%2!=0){
			v.push_back(broj);
		}
		else if(brojac2>0 && brojac3>0 &&brojac1==0&& brojac3%2!=0 && brojac2%2!=0){
			v.push_back(broj);
		}
		else if(brojac1>0 && brojac3>0 &&brojac2==0&& brojac1%2!=0 && brojac3%2!=0){
			v.push_back(broj);
		}
		
		else if(brojac1>0&&brojac2>0&&brojac3>0&&brojac1%2!=0 && brojac2%2!=0 && brojac3%2!=0){
			v.push_back(broj);
		}
		else if(brojac1%2!=0&&brojac2==0&&brojac3==0){
			v.push_back(broj);
		}
			else if(brojac1==0&&brojac2%2!=0&&brojac3==0){
			v.push_back(broj);
		}
			else if(brojac1==0&&brojac2==0&&brojac3%2!=0){
			v.push_back(broj);
		}
	
			
		
		
		
	
	}
	
	for(int i=0; i<u.size(); i++) {
		bool t(true);
		for(int j=0; j<i; j++)
		if(u[j]==u[i]){
			t=false;
			
		}
		if(t) c.push_back(u[i]);
	}
	
	for(int i=0; i<v.size(); i++) {
		bool t(true);
		for(int j=0; j<i; j++)
		if(v[j]==v[i]){
			t=false;
			
		}
		if(t) b.push_back(v[i]);
	}
	
	
	if(tacnost==true) return c;
	
	if(tacnost==false) return b;
	
	else{
		return c;
		return b;
	}
}



int main ()
{
	int n;
	std::vector<int> a;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		std::cin>>n;
		if(n!=0) a.push_back(n);
		
		if(n==0) break;
	}
	bool tacnost(true);
	std::vector<int>o;
	o=IzdvojiGadne(a,tacnost);
	std::cout<<"Opaki: ";
	for(int i=0; i<o.size(); i++) {
		std::cout<<o[i]<<" ";
	}
	
	bool netacnost(false);
	std::vector<int> j;
	j=IzdvojiGadne(a,netacnost);
	std::cout<<"\nOdvratni: ";
	for(int i=0; i<j.size(); i++) {
		std::cout<<j[i]<<" ";
	}
	
	
	return 0;
}