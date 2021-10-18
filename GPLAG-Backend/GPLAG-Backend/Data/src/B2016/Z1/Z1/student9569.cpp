/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

int Pretvorba_tern(int broj){
	int	pomocna(broj);
	int pomoc_broj(0);
	int x;
	int i(0);
	
	while(pomocna!=0){
		x=pomocna%3;
		pomoc_broj=pow(10,i)*x+pomoc_broj;
		pomocna=pomocna/3;
		i++;
	}
	return pomoc_broj;
}

vector<int>IzdvojiGadne(vector<int> v, bool){
	vector<int> novi;
	int brojac_0(0),brojac_1(0),brojac_2(0);
	int pomocna, cifra;
	for(int i(0); i<=v.size();i++){
		pomocna=Pretvorba_tern(v[i]);
		while(pomocna!=0)
		cifra=pomocna%10;
		if(cifra==0) brojac_0++;
		if(cifra==1) brojac_1++;
		if(cifra==2) brojac_2++;
	}
	
	
	
}










int main ()
{
	int n;
	cin>>n;
	n=Pretvorba_tern(n);
	cout<<n;
	return 0;
}