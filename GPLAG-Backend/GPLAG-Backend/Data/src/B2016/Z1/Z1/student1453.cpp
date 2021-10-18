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
using std::vector;

unsigned long long int decimal2ternary(int n){
	unsigned long long int i(1), suma(0);
	do{
		suma+=((n%3)*i);
		i*=10;
		n/=3;
	}while(n!=0);
	return	suma;
}

vector<int> IzdvojiGadne(vector<int> v, bool iskaz){
	vector<int> v1;
	
	for(int i=0;i<v.size();i++){
		bool ponavlja=false;
		for(int p:v1){
			if(v[i]==p){
				ponavlja=true;
				break;
			}
		}
		if(ponavlja) continue;
		
		unsigned long long int x(decimal2ternary(abs(v[i])));	
		vector<int> brojac(3,0);
		do{
			brojac[x%10]++;
			x/=10;
		}while(x!=0);
		
		
		if(iskaz){
			bool par=true;
			for(int j=0;j<3;j++){
				if(brojac[j]%2!=0){
					par=false; 
					break;
				}
			}
			
			if(par)v1.push_back(v[i]);
		}
		else{
			bool nepar=true;
			for(int j=0;j<3;j++){
				if(brojac[j]%2==0&&brojac[j]!=0){
					nepar=false; 
					break;
				}
			}
			if(nepar)v1.push_back(v[i]);
		}
	}
	return v1;
}




int main ()
{

	std::vector<int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int broj;
	do{
		std::cin >> broj;
		if(broj==0) break;
		v.push_back(broj);
	}while(1);
	std::cout << "Opaki: ";
	vector<int> v1(IzdvojiGadne(v,true));
	for(int x:v1) std::cout << x <<" ";
	std::cout << std::endl<<"Odvratni: ";
	vector<int> v2(IzdvojiGadne(v,false));
	for(int x:v2) std::cout << x <<" ";
	return 0;
}