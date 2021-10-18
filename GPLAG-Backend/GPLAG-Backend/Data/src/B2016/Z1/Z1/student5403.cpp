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

std::vector<int> IzdvojiGadne(std::vector<int> v,bool m)
{
	std::vector<int>gadni;

	if(m==true) {
		for(int i=0; i<v.size(); i++) {
			int broj=v[i];

			bool opaki(true);

			int brojac[3];
			for(int k=0; k<=2; k++) {
				brojac[k]=0;
			}
			for(;;) {
				int tmp=abs(broj%3);
				broj/=3;
				if(tmp==0)
					brojac[0]++;
				else if(tmp==1)
					brojac[1]++;
				else if(tmp==2)
					brojac[2]++;
				if(broj==0)
					break;
			}
			for(int j=0; j<gadni.size(); j++) {
				if(v.at(i)==gadni.at(j))
					opaki=false;
			}
			int k(0);
			while(k<=2) {
				if(brojac[k]!=0) {
					if((brojac[k]%2)!=0) {
						opaki=false;
						break;
					}
				}
				k++;
			}

			if(opaki==true) {
				gadni.push_back(v[i]);
			}
		}
	} else if(m==false) {

		for(int i=0; i<v.size(); i++) {
			int broj=v[i];

			bool opaki(true);

			int brojac[3];
			for(int k=0; k<=2; k++) {
				brojac[k]=0;
			}


			for(;;) {
				int tmp=abs(broj%3);
				broj/=3;
				if(tmp==0)
					brojac[0]++;
				else if(tmp==1)
					brojac[1]++;
				else if(tmp==2)
					brojac[2]++;
				if(broj==0)
					break;
			}


			for(int j=0; j<gadni.size(); j++) {
				if(v.at(i)==gadni.at(j))
					opaki=false;
			}
			for(int k=0; k<=2; k++) {
				if(brojac[k]!=0) {
					if((brojac[k]%2)==0) {
						opaki=false;
						break;
					}
				}
			}

			if(opaki==true) {
				gadni.push_back(v[i]);
			}
		}

	}

	return gadni;
}

int main ()
{

	int x;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>x;
	std::vector<int>v;
	while(x!=0) {
		if(x==0)
			break;
		else {
			v.push_back(x);
			std::cin>>x;
		}
	}

	std::vector<int>a;
	a=IzdvojiGadne(v,true);
	std::vector<int>b;
	b=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int i=0; i<a.size(); i++) {
		std::cout<<a.at(i)<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i=0; i<b.size(); i++) {
		std::cout<<b.at(i)<<" ";
	}


	return 0;
}