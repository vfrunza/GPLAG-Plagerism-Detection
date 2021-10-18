/*B 2017/2018, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include<vector>
#include <deque>
using namespace std;
typedef std::vector<int >Vektor;
MaksimalniPodnizoviStepenaDvojke(Vektor v1) {
	Vektor v3;
	Vektor v2=v1;

	for(int i=0; i<v1.size(); i++) {
		for(int j=i+1; j<v2.size(); j++) {
			if(v1.at(i)<v2.at(j))
			v3.push_back(v2.at(i));
			break;
		}
	}
	
	return v3;
}


int main ()
{
	cout<<"Unesi niz: ";
	Vektor v1;
	int a;
	for(int i=0; ; i++) {
		cin>>a;
		if(a==-1) break;
		v1.push_back(a);
	}
Vektor v3=(MaksimalniPodnizoviStepenaDvojke(v1));
   
	cout<<"Rastuci vektor je: ";
	for(int i=0; i<v3.size(); i++) {
		cout<<v3.at(i)<<" ";
	}
	return 0;
}