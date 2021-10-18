#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> IzdvojiGadne(std::vector < int > v,bool p)
{
	std::vector<int> v3;

	for(int i: v) {

		std::vector<int> v1;
		std::vector<int> v2;
		int k=i;
		int broj(fabs(k));
		int ostatak;
		do {
			ostatak=broj%3;
			if(broj<3) {
				ostatak=broj;
				v1.push_back(ostatak);
				break;
			}
			broj=broj/3;
			v1.push_back(ostatak);
		} while(broj>0);
		for(int i=0; i<=9; i++) {
			int brojac(0);
			for(int j=0; j<v1.size(); j++) {
				if(i==v1[j]) {
					brojac+=1;
				} else {
					continue;
				}

			}
			if(brojac==0) continue;
			else {
				v2.push_back(brojac);
			}

		}
		int brojac1(0);
		int brojac2(0);
		for(i=0; i<v2.size(); i++) {
			if(v2[i]%2==0) {
				brojac1+=1;
			} else if(v2[i]%2!=0) {
				brojac2+=1;
			}
		}
		if(brojac1>0 && brojac2==0 && p==true) {
			v3.push_back(k);
		} else if(brojac2>0 && brojac1==0  && p==false && broj !=0) {
			v3.push_back(k);
		}
	}
	std::vector<int>v4;
	for(int i=v3.size()-1; i>=0; i--) {
		bool dupli(true);
		for(int j=i-1; j>=0; j--) {
			if(v3[i]==v3[j]) {
				dupli=false;
			} else {
				continue;
			}
		}

		if(dupli) {
			v4.push_back(v3[i]);
		}
	}
	std::vector<int>v5;
	for(int i=v4.size()-1; i>=0; i--) {
		v5.push_back(v4[i]);
	}
	return v5;

}

int main ()
{
	int broj;
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin>>broj;
		if(broj==0) break;
		v.push_back(broj);
	} while(broj !=0);
	bool t(true);
	bool f(false);
	std::vector<int>v1;
	v1=IzdvojiGadne(v,t);
	std::cout<<"Opaki: ";
	for(int i: v1) {
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
	std::vector<int>v2;
	v2=IzdvojiGadne(v,f);
	std::cout<<"Odvratni: ";
	for(int i: v2) {
		std::cout<<i<<" ";
	}
	return 0;
}