/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using std:: cout;
using std:: cin;
using std:: endl;


std:: vector<int> IzdvojiGadne(std:: vector<int>a, bool vrijednost)
{
	std:: vector<int> opaki;
	std:: vector<int> odvratni;
	std:: vector<int> vektor(0);
	
	if(a.size()==0) return vektor;
	
	for(int i=0; i<a.size(); i++) {
		for(int j=i+1; j<a.size(); j++) {
			if(a[i]==a[j]) {
				for(int m=j; m<a.size()-1; m++) {
					a[m]=a[m+1];
				}
				a.erase(a.begin()+a.size()-1);
				j--;
			}

		}
	}


	for(int i=0; i<a.size(); i++) {
		int broj(a[i]);
		int brojac0(0), brojac1(0), brojac2(0);
		while(broj!=0) {

			if(abs(broj%3)==0) brojac0++;
			if(abs(broj%3)==1) brojac1++;
			if(abs(broj%3)==2) brojac2++;
			broj/=3;
		}
		if((brojac0%2==0 || brojac0==0) && (brojac1%2==0 || brojac1==0) && (brojac2%2==0 || brojac2==0)) opaki.push_back(a[i]);
		if((brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0)) odvratni.push_back(a[i]);
		
	}

	if(vrijednost) return opaki;
	else return odvratni;
}


int main ()
{
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	std:: vector<int> a;
	int n;
	while(true) {
		cin>>n;
		if(n==0) break;
		a.push_back(n);
	}
	
	std:: vector<int>odvratni;
	std:: vector<int>opaki;
	opaki=IzdvojiGadne(a,1);
	odvratni=IzdvojiGadne(a,0);

	cout<<"Opaki: ";
	for(int i=0; i<opaki.size(); i++) {
		cout<<opaki[i]<<" ";
	}
	cout<<endl;

	cout<<"Odvratni: ";
	for(int i=0; i<odvratni.size(); i++) {
		cout<<odvratni[i]<<" ";
	}
	return 0;
}
