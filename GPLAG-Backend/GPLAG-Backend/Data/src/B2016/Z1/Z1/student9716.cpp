/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

// brojevi koji nisu ni opaki ni odvratni popraviti

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

std::vector<int> TernarniBroj(long long int n)
{
	long long int x=n; int k(1);
	std::vector<int> v;
	long long int ternarni(0);
	while(x>0) { if(x%3==0) { k*=10; x/=3; } else break; }
	if(x%3==0) k*=10;
	while(x>0) {
		ternarni=ternarni*10+x%3;
		x/=3;
	}
	long long int temp=ternarni;
	long long int novi=0;
	while(temp!=0) {
		novi=novi*10+temp%10;
		temp/=10;
	}
	ternarni=novi;
ternarni*=k;
	while(ternarni>0) {
		v.push_back(ternarni%10);
		ternarni/=10;
	}
	return v;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a)
{
	std::vector<int> v1,v2;
	int brnul(0), brjed(0), brdva(0);
	std::vector<int> v3;
	int neg=0;

	for(int i=0; i<v.size(); i++) { if(v[i]==0) { v2.push_back(v[i]); continue; } else {
		neg=0;
		if(v[i]<0) {
			v[i]*=(-1);
			neg=1;
		}
		v3=TernarniBroj(v[i]);
		if(neg==1) v[i]*=(-1);
		brnul=0;
		brjed=0;
		brdva=0;
		for(int i=0; i<v3.size(); i++) {
			if(v3[i]==0) brnul++;
			else if(v3[i]==1) brjed++;
			else if(v3[i]==2) brdva++;
		}
		if(brnul%2==0 && brjed%2==0 && brdva%2==0 ) v1.push_back(v[i]);
		else if( (brnul%2!=0  || brnul==0) && (brjed%2!=0 || brjed==0) && (brdva%2!=0 || brdva==0) ) v2.push_back(v[i]);
		else continue;
	} }
	if(v1.size()>1) for(int i=0; i<v1.size()-1; i++) { for(int j=i+1; j<v1.size(); j++) {
		if(v1[i]==v1[j]) { v1.erase(v1.begin()+j); j--; }
	} }
	
if(v2.size()>1)	for(int i=0; i<v2.size()-1; i++) { for(int j=i+1; j<v2.size(); j++) {
		if(v2[i]==v2[j]) {  v2.erase(v2.begin()+j); j--; }
	} }

	if(a) return v1;
	else return v2;
}


int main ()
{
	std::vector<int> v;
	std::vector<int> v1,v2;
	long long int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>n;
	while(n!=0) {
		v.push_back(n);
		std::cin>>n;
	}
	v2=IzdvojiGadne(v, false);
	v1=IzdvojiGadne(v, true);
	if(v2.size()>1) for(int i=0; i<v2.size()-1; i++) { for(int j=i+1; j<v2.size(); j++) {
		if(v2[i]==v2[j]) v2.erase(v2.begin()+j);
	} }
	if(v1.size()>1) for(int i=0; i<v1.size()-1; i++) { for(int j=i+1; j<v1.size(); j++) { if(v1[i]==v1[j]) v1.erase(v1.begin()+j); } }
	std::cout<<"Opaki: ";
	if(v1.size()!=0) for(int i=0; i<v1.size(); i++) std::cout<<v1[i]<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	if(v2.size()!=0) for(int i=0; i<v2.size(); i++) std::cout<<v2[i]<<" ";

	return 0;
}