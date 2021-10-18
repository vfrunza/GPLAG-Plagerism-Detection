/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

vector<int>IzdvojiGadne(vector<int>V1, bool a){
	int br0, br1, br2;
	vector<int>Povratni;
	for(int i=0; i<V1.size(); i++){
	    do{
			if((V1[i]%3)*3==0){
			   br0++;
			   V1[i]/=3;
			}
			if((V1[i]%3)*3==1){
			   br1++;
			   V1[i]/=3;
			}
			if((V1[i]%3)*3==2){
			   br2++;
			   V1[i]/=3;
			}
		}while((V1[i]/3)!=0);
	

	br0=0;
	br1=0;
	br2=0;
	}
	return Povratni;
}

int main ()
{
	vector<int>V1;
	vector<int>IzdvojiGadne(std::vector<int>V1, bool a); 
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	do{
		cin>>n;
		V1.push_back(n);
	}while(n!=0);
	vector<int> a(IzdvojiGadne(V1, true)); 
	vector<int> b(IzdvojiGadne(V1, false));
	cout<<"Opaki: ";
	for(int i=0; i<a.size(); i++)
		cout<<a[i]<<" ";
	cout<<"Odvratni: ";
	for(int i=0; i<b.size(); i++)
		cout<<b[i]<<" ";
	return 0;
}