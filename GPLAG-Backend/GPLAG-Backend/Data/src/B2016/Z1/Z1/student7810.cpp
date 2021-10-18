/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include<vector>
#define EPSILON 0.0001

using std::cin;
using std::cout;
using std::endl;
using std::vector;
vector<int> IzdvojiGadne (vector<int> v, bool opaki){
	if(opaki){
		vector<int> gadni;
		int suma(0),broj,br0(0),br1(0),br2(0),t;
		bool opak=true;
		for(int x : v){
			suma=0;
			br0=0;
			br1=0;
			br2=0;
			broj=x;
			opak=true;
			do{
				suma*=10;
				t=abs(x%3);
				if(t==0) br0++;
				else if (t==1) br1++;
				else br2++;
				suma+=t;
				x/=3;
			}while(x!=0);
			if (br0%2!=0 || br1%2!=0 || br2%2!=0)
			opak=false;
			if (opak) {
				bool isti=false;
				for(int i=0;i<gadni.size();i++){
					if (abs(gadni[i]-broj)<EPSILON) {isti=true;break;}
				}
				if (!isti)
				gadni.push_back(broj);
			}
		}
		return gadni;
	}
	else{
		vector<int> gadni;
		int suma(0),broj,br0(0),br1(0),br2(0),t;
		bool odvratan=true;
		for(int x : v){
			suma=0;
			br0=0;
			br1=0;
			br2=0;
			broj=x;
			odvratan=true;
			do{
				suma*=10;
				t=abs(x%3);
				if(t==0) br0++;
				else if (t==1) br1++;
				else br2++;
				suma+=t;
				x/=3;
			}while(x!=0);
			if ((br0%2==0 && br0!=0) || (br1%2==0 && br1!=0) || (br2%2==0&& br2!=0))
			odvratan=false;
			if (odvratan) {
				bool isti=false;
				for(int i=0;i<gadni.size();i++){
					if (abs(gadni[i]-broj)<EPSILON) {isti=true;break;}
				}
				if (!isti)
				gadni.push_back(broj);
			}
		}
		
		return gadni;
	}
}
int main ()
{
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	vector<int> v;
	int x(1);
	while(x != 0){
		cin>>x;
		if (x==0) break;
		v.push_back(x);
	}
	vector<int> opaki;
	opaki=IzdvojiGadne(v,true);
	cout<<"Opaki: ";
	for (int i : opaki) cout<<i<<" ";
	cout<<endl;
	vector<int> odvratni;
	odvratni=IzdvojiGadne(v,false);
	cout<<"Odvratni: ";
	for (int i : odvratni) cout<<i<<" ";
	return 0;
}