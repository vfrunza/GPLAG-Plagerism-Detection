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
int brcifara(int n) {
	int b(0);
	while(n>0) {
		n=n/3;
		b++;
	}
	return b;
}
int pretvori(int n) {
	int s=0,s1=0;
	int br=brcifara(n);
	int br2=brcifara(n);
	while(n>0) {
		s=s+n%3*pow(10,br-1);
		n=n/3;
		br--;
	}
	while(s>0) {
		s1=s1+s%10*pow(10,br2-1);
		br2--;
		s=s/10;
	}
	return s1;
}
std::vector<int>Duplikati(std::vector<int>v) {
	std::vector<int>v2;
	for(int i=0; i<v.size(); i++) {
		bool t=true;
		for(int j=0; j<v2.size(); j++) 
			if(v2[j]==v[i]) t=false;
			if(t) v2.push_back(v[i]);
	}
	return v2;
}
std::vector<int>IzdvojiGadne(std::vector<int>v, bool tn) {
	std::vector<int>n;
	int br=0;
	int vrijednost=0;
	if(tn==true) {
	for(int i=0; i<v.size(); i++) {
		int p=pretvori(v[i]);
		int pom=p;
		while(p>0) {
			int a=pom;
			int m=p%10;
			while(a>0) {
				int k=0;
				k=a%10;
				if(k==m) br++;
				a=a/10;
			}
			if(br%2==0) vrijednost=1;
			else { vrijednost=0; break; }
			p=p/10;
			br=0;
		}
		if(vrijednost==1) n.push_back(pom);
	}
}
else if(tn==false) {
	br=0;
	vrijednost=1;
	for(int i=0; i<v.size();i++) {
		int p=pretvori(v[i]);
		int pom=p;
		while(p>0) {
			int a=pom;
			int m=p%10;
			while(a>0) {
				int k=0;
				k=a%10;
				if(k==m) br++;
				a=a/10;
			}
			if(br%2!=0) vrijednost=0;
			else {vrijednost=1; break; }
			p=p/10;
			br=0;
		}
		if(vrijednost==0) n.push_back(pom);
	}
}
std::vector<int>krajnji=Duplikati(n);
return krajnji;
}
int main ()
{
	std::vector<int>v;
	int br_elemenata,broj;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>br_elemenata;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<br_elemenata; i++) {
		std::cin>>broj;
		v.push_back(broj);
	}
	std::vector<int>p=IzdvojiGadne(v,false);
	for(int i=0; i<p.size(); i++) {
		std::cout<<p[i]<<" ";
	}
	return 0;
}