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

std::vector<int> IzdvojiGadne(std::vector<int> v, bool d)
{
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v[j]==v[i]) {
				v.erase(v.begin() + j);
				j--;
			}
		}
	}
	std::vector<int> w;
	for(int i=0; i<v.size(); i++) {
		int b=(v[i]);
		int c;
		if(b==0 && d==true) continue;
		else if(b==0 && d==false) {w.push_back(v[i]); continue;}
		std::vector<int> a;
		while(b!=0) {
			c=abs(b%3);
			a.push_back(c);
			b=b/3;
		}
		int b1=0, b2=0, b0=0;
		for(int j=0; j<a.size(); j++) {

			if(a[j]==0) b0++;
			else if(a[j]==1) b1++;
			else if(a[j]==2) b2++;
		}
		
		if((b0%2==0 && b1%2==0 && b2%2==0 && d==true) || (b0%2==0 && b1%2==0 && b2==0 && d==true) || (b0%2==0 && b2%2==0 && b1==0 && d==true) || (b2%2==0 && b1%2==0 && b0==0 && d==true)) {
			w.push_back(v[i]);
		}
		if((b0%2==1 && b1%2==1 && b2%2==1 && d==false) || (b0%2==1 && b1%2==1 && b2==0 && d==false) || (b0%2==1 && b2%2==1 && b1==0 && d==false) || (b2%2==1 && b1%2==1 && b0==0 && d==false) || (b2%2==1 && b1==0 && b0==0 && d==false) || (b2==0 && b1%2==1 && b0==0 && d==false) || (b2==0 && b1==0 && b0%2==1 && d==false)) {
			w.push_back(v[i]);
		}
	}
	return w;
}
int main ()
{
	int n;
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin>>n;
		if(n==0) {
			break;
		}
		v.push_back(n);
	} while(n!=0);

	std::vector<int> op(IzdvojiGadne(v, true));
	std::vector<int> od(IzdvojiGadne(v, false));
	std::cout<<"Opaki: ";
	for(int i=0; i<op.size(); i++) {
		if(i!=op.size()-1)	std::cout<<op[i]<<" ";
		else std::cout<<op[i]<<" "<<std::endl;
	}
	std::cout<<"Odvratni: ";
	for(int i=0; i<od.size(); i++) {
		std::cout<<od[i]<<" ";
	}
	return 0;
}