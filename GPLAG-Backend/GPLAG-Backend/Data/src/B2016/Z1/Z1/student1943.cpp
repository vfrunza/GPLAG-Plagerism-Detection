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

std::vector<int>OdstraniDuple(std::vector<int>v) {
	std::vector<int>k;
	for(int i=0;i<v.size();i++) {
		int broj_ponavljanja(0);
		for(int j=0;j<i;j++) 
		if(v[i]==v[j]) broj_ponavljanja++;
		if(broj_ponavljanja==0) k.push_back(v[i]);
	}
	return k;
}
int Ternarni(int n) {
	int broj(0);
	int r(0);
	int promjena(0);
	int brojac(0);
	while(n!=0) {
	int x=std::abs(n)%3;
		broj+=x;
		broj*=10;
		if(broj==0) { r=1; brojac++; }
		n=n/3;
		if(n==0) { break; }
	}
	broj/=10;
	while(broj!=0)  {
		promjena=promjena*10;
		promjena=promjena+broj%10;
		broj=broj/10;
	}
	if(r==1) {
	promjena*=10;
	}
    if(brojac==2) {
		promjena*=10;
	}
	return promjena;
}

int BrojPuta(int n) {
	int brojac0(0),brojac1(0),brojac2(0);
	while(n!=0) {
		int x=std::abs(n)%10;
		if(x==0) {
			brojac0++;
		}
		else if(x==1) {
			brojac1++;
		}
		else if(x==2) {
			brojac2++;
		}
		n=std::abs(n)/10;
	}
	// 7 kombinacije za parne
	if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0) {
		return 1;
	}
	else if(brojac0==0 && brojac1%2==0 && brojac2%2==0) {
		return 1;
	}
	else if(brojac1==0 && brojac0%2==0 && brojac2%2==0) {
		return 1;
	}
	else if(brojac2==0 && brojac0%2==0 && brojac1%2==0) {
		return 1;
	}
	else if(brojac1%2==0 && brojac0==0 && brojac2==0) {
		return 1;
	} 
	else if(brojac2%2==0 && brojac0==0 && brojac1==0) {
		return 1;
	}
	else if(brojac0%2==0 && brojac1==0 && brojac2==0) {
		return 1;
	}
	else if(brojac0%2!=0 && brojac1%2!=0 && brojac2%2!=0) {
		return 0;
	}
	else if(brojac0==0 && brojac1%2!=0 && brojac2%2!=0) {
		return 0;
	}
	else if(brojac1==0 && brojac0%2!=0 && brojac2%2!=0) {
		return 0;
	}
	else if(brojac2==0 && brojac0%2!=0 && brojac1%2!=0) {
		return 0;
	}
	else if(brojac0%2!=0 && brojac1==0 && brojac2==0) {
		return 0;
	}
	else if(brojac1%2!=0 && brojac0==0 && brojac2==0) {
		return 0;
	}
	else if(brojac2%2!=0 && brojac0==0 && brojac1==0) {
		return 0;
	}
	
	
	else {
	    return 5;
	}
} 
std::vector<int>IzdvojiGadne(std::vector<int>v,bool logika) {
	std::vector<int>p;
	std::vector<int>n;
	v=OdstraniDuple(v);
	for(int i=0;i<v.size();i++) {
		if(v[i]==0) {
			break;
		}
		if(BrojPuta(Ternarni(v[i]))==1) {
			p.push_back(v[i]);
		}
		else if(BrojPuta(Ternarni(v[i]))==0) {
			n.push_back(v[i]);
		}
		else {
			continue;
		}
	}
	if(logika) {
		return p;
	}
	else {
		return n;
	}
}




int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>v;
	std::vector<int>p;
	std::vector<int>n;
	int broj;
	do {
		std::cin>>broj;
		v.push_back(broj);
	}
	while(broj!=0);
	p=IzdvojiGadne(v,true);
	n=IzdvojiGadne(v,false);
	if(p.size()==0) {
		std::cout<<"Opaki: 0";
	}
	else {
		std::cout<<"Opaki: ";
	for(int j=0;j<p.size();j++) {
	std::cout<<p[j]<<" ";
	}
	}
	std::cout<<std::endl;
	if(n.size()==0) {
		std::cout<<"Odvratni: 0";
	}
	else {
	std::cout<<"Odvratni: ";
	for(int i=0;i<n.size();i++) {
	   std::cout<<n[i]<<" ";
	}
	}
	return 0;
}