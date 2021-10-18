#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int ternarni(int n) {
	int cifra, zamjena(n), power(0);
	while(zamjena!=0) {
		cifra=10*cifra+zamjena%3;
		if(cifra==0) power++;
		zamjena/=3;
	}
	int rezultat(0);
	while(cifra!=0) {
		rezultat=10*rezultat+cifra%10;
		cifra/=10;
	} rezultat=rezultat*pow(10, power);
	return rezultat;
	
}
std::vector<int> IzdvojiGadne(std::vector<int> v, bool evil) {
	std::vector<int> sabazom3;
	std::vector<int> rez;
	for(int i=0; i<v.size(); i++) {
		sabazom3.push_back(ternarni(v[i]));
	} std::vector<int> counter(4, 0);
	int cifra;
	if(evil) {
		for(int i=0; i<sabazom3.size(); i++) {
			while (sabazom3[i]!=0) {
				cifra=sabazom3[i]%10;
				counter[cifra]++;
				sabazom3[i]/=10;
			} bool opakje=true;
			for(int j=0; j<4; j++) {
				if(counter[j]%2!=0 && counter[j]!=0)  opakje=false; break;
			} if(opakje) rez.push_back(v[i]);
		} 
	}
	else if(evil==false) {
		for(int i=0; i<sabazom3.size(); i++) {
			while (sabazom3[i]!=0) {
			cifra=sabazom3[i]%10;
			counter[cifra]++;
			sabazom3[i]/=10;}
		 bool odvratan=true;
		for(int j=0; j<4; j++) {
			if(counter[j]%2==0 && counter[j]!=0) odvratan=false; break;}
			if(odvratan) rez.push_back(v[i]);
		} }
	
	return rez;
	} 
int main ()
{
	std::vector<int> v;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	for(;;) {
		cin>>n;
		if(n==0) break;
		v.push_back(n);
	}
	std::vector<int> opaki(IzdvojiGadne(v, true));
	cout<<"Opaki: ";
	for(int i=0; i<opaki.size(); i++) {
		cout<<opaki[i];
	} cout<<"\nOdvratni: ";
	std::vector<int> odv(IzdvojiGadne(v, false));
	for(int i=0; i<odv.size(); i++) cout<<odv[i]<<" ";
	
	return 0;
}