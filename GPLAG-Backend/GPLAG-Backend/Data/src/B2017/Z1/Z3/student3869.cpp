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
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

deque<vector<int>MaksimalniPodnizoviStepenaDvojke>
(vector<int>niz, enum, smjer){
	deque<vector<int>>x;
	vector<int>stepen;
	for(int i=0; i<niz.size(); i++){
		int a;
		a=niz[i];
		for(int j=0; j<a; j++){
			if(a==(2^j|){
				stepen.push_back(a);
				break;
			}
		}
		if(smjer==1){
			for(int i=0; i<stepen.size(); i++){
				vector<int>novi;
				for(int j=i+1; j<(stepen.size()-1); j++){
					int b, c;
					b=stepen[j];
					c=stepen[j+1];
					if(b>c){
						novi.push_back(b);
						novi.push_back(c);
					}
					if(b<c){
						i=j;
						break;
					}
				}
				for(int k=0; k<(novi.size()-1); k++){
					int z;
					z=novi[k];
					if(z==novi[k+1]){
						novi.erase(novi[k]);
					}
			}
			x.push_back(novi);
		}
	}
	return x;
}


int main ()
{
	enum Smjer{Opadajuci, Rastuci};
	vector<int>nesto;
	int s;
	cout<<"Unesite broj elemenata niza: ";
	cin>>s;
	cout<<"Unesite elemente niza: ";
	for(int i=0; i<s; i++){
		int v;
		cin>>v;
		nesto.push_back(v);
	}
	deque<vector<int>>nestodrugo;
	nestodrugo=MaksimalniPodnizoviStepenaDvojke(nesto, smjer[0]);
	deque<vector<int>>nestotrece;
	nestotrece=MaksimalniPodnizoviStepenaDvojke(nesto, smjer[1]);
	for (int i=0; i<nestodrugo.size(); i++){
		for(int j=0; j<nestodrugo[i].size(); j++){
			cout<<nestodrugo[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}