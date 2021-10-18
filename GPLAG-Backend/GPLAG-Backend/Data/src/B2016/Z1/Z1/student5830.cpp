/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
using std::vector;
using std::cin;
using std::cout;
vector<int> IzdvojiGadne(vector<int> a,bool t)
{
	if(a.size()==0) return a;
	vector<int> opaki;
	vector<int> odvratni;
	for(int i=0; i<a.size(); i++) {
		int pomocni=a[i];
		int broj=a[i];
		int brojac0(0);
		int brojac1(0);
		int brojac2(0);
		do {
			if(pomocni%3==0) {
				brojac0=brojac0+1;
			} else if(pomocni%3==1) {
				brojac1=brojac1+1;
			} else if(pomocni%3==2) {
				brojac2=brojac2+1;
			}

			pomocni=pomocni/3;
		}while(pomocni!=0);
		bool k=true;
		for(int j=0; j<i; j++) {
			if(a[i]==a[j]) {
				k=false;
				break;
			}
		}
		if(k==true && brojac0%2==0 && brojac1%2==0 && brojac2%2==0) opaki.push_back(broj);
		else if(k==true && (brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0)) odvratni.push_back(broj);
	}
	if(t==true) {
		return opaki;
	} else if(t==false) {
		return odvratni;
	}
}
int main ()
{
	int broj;
	vector<int> slijed;
	vector<int> opaki;
	vector<int> odvratni;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		cin>>broj;
		if(broj!=0) slijed.push_back(broj);
		if(broj==0) break;
	} while(true);
	opaki=IzdvojiGadne(slijed,true);
	odvratni=IzdvojiGadne(slijed,false);
	cout<<"Opaki: ";
	for(int i=0;i<opaki.size();i++) {cout<<opaki[i]<<" ";}
	cout<<"\nOdvratni: ";
	for(int i=0;i<odvratni.size();i++) {cout<<odvratni[i]<<" ";}
	return 0;
}