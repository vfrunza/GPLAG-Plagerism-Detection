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
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

long long int Stepen(int baza, int stepen){
	long long int d=1;
	for(int i=0;i<stepen;i++){
		d*=baza;
	}
	return d;
}

std::vector<int> IzdvojiGadne(std::vector<int>v, bool d)
{
	long long int s(0);
	int br(0),brojac[4]= {0};
	std::vector<int>g;
	std::vector<int>f;
	int vel=v.size();

	for(int i=0; i<vel; i++) {
		for(int j=i; j<vel-1; j++) {
			if(v[i]==v[j+1]) {
				for(int k=j+1; k<vel-1; k++) {
					v[k]=v[k+1];
				}
				vel--;
				j--;
			}
		}
	}

	for(int i=0; i<vel; i++) {
	long long int e=v[i];
		do {
			if(e<0) e=(long long int)(fabs(e));
		long long int m=e%3;
		long long int c=m*Stepen(10,br);
			br++;
			s+=c;
			e/=3;
		} while(e!=0);

		long long int n=s;
		do {
			int k=n%10;
			if(k==0) brojac[0]++;
			else if(k==1) brojac[1]++;
			else if(k==2) brojac[2]++;
			n/=10;
		} while(n!=0);

		bool opak(true), odvratan(true);
		for(int i=0; i<3; i++) {
			if(brojac[i]==0) continue;
			else if(brojac[i]%2!=0) {
				opak=false;
				break;
			}
		}

		for(int i=0; i<3; i++) {
			if(brojac[i]==0) continue;
			else if(brojac[i]%2==0) {
				odvratan=false;
				break;
			}
		}

		if(opak==true && odvratan==false) g.push_back(v[i]);
		if(odvratan==true && opak==false) f.push_back(v[i]);
		s=0;
		br=0;
		for(int i=0; i<3; i++) {
			brojac[i]=0;
		}
	}

	if(d) return g;
	else return f;
}

int main ()
{
	int n;
	std::vector<int>v;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		cin>>n;
		if(n==0) break;
		else v.push_back(n);

	} while(n!=0);

	auto b(IzdvojiGadne(v,1));
	auto c(IzdvojiGadne(v,0));
	cout<<"Opaki: ";
	for(int i=0; i<b.size(); i++) {
		cout<<b[i]<<" ";
	}
	cout<<endl;
	cout<<"Odvratni: ";
	for(int j=0; j<c.size(); j++) {
		cout<<c[j]<<" ";
	}
	return 0;
}