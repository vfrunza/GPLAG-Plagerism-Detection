/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


vector <int> IzdvojiGadne (vector<int> v, bool tacnost){
	vector <int> v1;
	for(int i=0; i<v.size(); i++){
		int brojac0(0);
		int brojac1(0);
		int brojac2(0);
		int cifra=v.at(i)%3;
		if(cifra<0) cifra*=(-1);
		if(cifra==0)brojac0++;
		if(cifra==1)brojac1++;
		if(cifra==2)brojac2++;
		int pomocni_broj=v.at(i)/3;
		if(pomocni_broj<0) pomocni_broj*=(-1);
		for(unsigned int j=pomocni_broj; j>0; j/=3){
			if(j%3==0) brojac0++;
			else if(j%3==1) brojac1++;
			else brojac2++;
		}
		bool razlicitost=0;
		for(int j=0; j<v1.size(); j++){
			if(v.at(i)==v1.at(j)){
				razlicitost=1;
				break;
			}
		}
		if(razlicitost) continue;
		if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0 && tacnost) v1.push_back(v.at(i));
		else if((brojac0%2==1 || brojac0==0) && (brojac1==0 || brojac1%2==1) && (brojac2==0 || brojac2%2==1) && !tacnost) v1.push_back(v.at(i));
	}
	return v1;
}

int main ()
{
	vector<int> v;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		int element;
		cin>>element;
		if(element==0) break;
		v.push_back(element);
	} 
	vector<int> Opaki;
	vector<int> Odvratni;
	Opaki=IzdvojiGadne(v, 1);
	Odvratni=IzdvojiGadne(v, 0);
	cout<<"Opaki: ";
	for(int i=0; i<Opaki.size(); i++){
		cout<<Opaki.at(i)<<" ";
	}
	cout<<endl;
	cout<<"Odvratni: ";
	for(int i=0; i<Odvratni.size(); i++){
		cout<<Odvratni.at(i)<<" ";
	}
	
	return 0;
}