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

std::vector<int> IzdvojiGadne (std::vector<int>v, bool tacnost)
{
	std::vector<int>c;
	std::vector<int>rezultat(0,0);

	if(v.size()==0) return rezultat;

	for(int i=0; i<v.size()-1; i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v.at(i)==v.at(j)) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}

	for(int h=0; h<v.size(); h++) {
		int br0(0), br1(0), br2(0);
		long long int pomocni(abs(v.at(h)));

		while(pomocni!=0) {
			int d=pomocni%3;
			if(d==0) br0++;
			else if(d==1) br1++;
			else if(d==2) br2++;
			pomocni=pomocni/3;
			c.push_back(d);
		}
		c.resize(0);

		if((br0%2==0 && br1%2==0 && br2%2==0 && tacnost==true) || (br0==0 && br1%2==0 && br2%2==0 && tacnost==true) || (br0%2==0 && br1==0 && br2%2==0 && tacnost==true) || (br0%2==0 && br1%2==0 && br2==0 && tacnost==true) || (br0%2==0 && br1==0 && br2==0 && tacnost==true) || (br0==0 && br1%2==0 && br2==0 && tacnost==true) || (br0==0 && br1==0 && br2%2==0 && tacnost==true)) rezultat.push_back(v.at(h));

		if((br0%2!=0 && br1%2!=0 && br2%2!=0 && tacnost==false) || (br0==0 && br1%2!=0 && br2%2!=0 && tacnost==false) || (br0%2!=0 && br1==0 && br2%2!=0 && tacnost==false) || (br0%2!=0 && br1%2!=0 && br2==0 && tacnost==false) || (br0==0 && br1==0 && br2%2!=0 && tacnost==false) || (br0==0 && br1%2!=0 && br2==0 && tacnost==false) || (br0%2!=0 && br1==0 && br2==0 && tacnost==false)) rezultat.push_back(v.at(h));


		if(br0==0 && br1==0 && br2==0 && tacnost==false) rezultat.push_back(v.at(h));
	}

	return rezultat;
}

int main()
{
	std::vector<int>v;
	cout<<"Unesite brojeve (0 za prekid unosa): ";

	int broj;
	cin>>broj;
	while(broj!=0) {
		if (broj!=0) v.push_back(broj);
		cin>>broj;
	}

	std::vector<int> Opaki;
	std::vector<int> Odvratni;

	Opaki=IzdvojiGadne(v,true);
	Odvratni=IzdvojiGadne(v,false);

	cout<<"Opaki: ";
	for(int j=0; j<Opaki.size(); j++) cout<<Opaki.at(j)<<" ";
	cout<<"\n"<<"Odvratni: ";

	for(int k=0; k<Odvratni.size(); k++) cout<<Odvratni.at(k)<<" ";



	return 0;
}
