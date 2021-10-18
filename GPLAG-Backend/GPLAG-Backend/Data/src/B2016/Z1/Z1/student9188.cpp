/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

using namespace std;

int VratiTernarno(int n)
{  
	int suma=0;
	int k=1;
	
	while(n!=0)
	{
		suma=n%3*k;
		k*=10;
		n/=3;
	}
	return suma;
}



vector<int> IzdvojiGadne(vector<int> v,bool a);

int main ()
{    
	cout<<VratiTernarno(56);
	return 0;
}