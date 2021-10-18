#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

typedef std::vector<int> vektor;

vektor IzdvojiGadne (vektor v, bool x)
{
	vektor konacni;
	for(int i=0; i<v.size(); i++) {
		bool preskoci(false);
		for(int k=0; k<i; k++) {
			if(v[i]==v[k]) preskoci=true;
			}
		if(preskoci) continue;
		int brojac0(0), brojac1(0), brojac2(0), temp(v[i]);
		vektor broj_t;
		if(temp==0) broj_t.push_back(0);
		while(temp!=0) {
			broj_t.push_back(temp%3);
			temp/=3;
		}
		
		for(int x: broj_t) {
			if(abs(x)==0) brojac0++;
			else if(abs(x)==1) brojac1++;
			else if (abs(x)==2)brojac2++;
		}
		if(x){
			if(brojac0%2==0 and brojac1%2==0 and brojac2%2==0) 
				konacni.push_back(v[i]);
		}
		else if(x==false){
			if(brojac0==0) brojac0=1;
			if(brojac1==0) brojac1=1;
			if(brojac2==0) brojac2=1;
			if(brojac0%2==1 and brojac1%2==1 and brojac2%2==1) konacni.push_back(v[i]);
		}
	}
	return konacni;
}

using std::cout;
using std::cin;

int main ()
{
	cout << "Unesite brojeve (0 za prekid unosa): ";
	vektor v;
	double a;
	for(;;){
		cin>>a;
		if(!cin or int(a)-a>0.00001){
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Unesite brojeve (0 za prekid unosa): ";
			continue;
		}
		if(int(a)==0) break;
		v.push_back(int(a));
	}
	
	vektor c(IzdvojiGadne(v,true));
	cout << "Opaki: ";
	for(int i=0; i<c.size();i++){
		cout << c[i] << " ";
	}
	cout << std::endl;
	c=IzdvojiGadne(v,false);
	cout << "Odvratni: ";
	for(int i=0; i<c.size();i++){
		cout << c[i] << " ";
	}
	return 0;
}