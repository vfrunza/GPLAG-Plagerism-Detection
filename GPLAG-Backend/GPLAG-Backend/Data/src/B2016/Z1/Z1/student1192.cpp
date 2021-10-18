/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using std :: cout;
using std :: cin;
typedef std:: vector<int> vektor;

vektor IzdvojiGadne (vektor v, bool b){
	vektor a;
	for(int i=0; i<v.size(); i++){
		vektor br(3);
		int x(v[i]);
		while (x!=0){
			int o;
			o=abs(x)%3;
			if(o==0) br[0]++;
			if(o==1) br[1]++;
			if(o==2) br[2]++;
			x=x/3;
		}
		int p(1), n(1);
		for (int j=0; j<br.size(); j++){
			if(br[j]!=0){
			if(br[j]%2==0) n=0;
		}
		}
		
		for (int j=0; j<br.size(); j++){
			if(br[j]%2!=0) p=0;
		}
		int ponavljanje (0);
		for (int j=0; j<a.size(); j++){
			if(v[i]==a[j]) ponavljanje =1;
		}
		if(ponavljanje==0){
			if(p==1 && b==true) a.push_back(v[i]);
			if(n==1 && b==false) a.push_back(v[i]);
		}
	}
	return a;
}


int main ()
{
	cout << "Unesite brojeve (0 za prekid unosa): ";
	int a;
	cin >> a;
	vektor v;
	while (a!=0){
		v.push_back(a);
		cin >> a;
	}
	vektor o(IzdvojiGadne(v,true));
	cout << "Opaki: ";
	for (double x: o){
		cout << x << " ";
		
	}
	cout << "\nOdvratni: ";
	vektor d(IzdvojiGadne(v,false));
	for (double x: d){
		cout << x << " ";
		
	}
	
	
	
	return 0;
}