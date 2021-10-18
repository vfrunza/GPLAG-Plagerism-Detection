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
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

enum Smjer {Opadajuci=0,Rastuci=1};

bool ProvjeraStepena(int n)
{
	if(n==1) {
		return true;
	}
	int s=2;
	do {
		if(s==n) return true;
		if(s>n) return false;
	} while(s*=2);
	return 0;
}


deque<vector<int>>MaksimalniPodnizoviStepenaDvojke(vector<int>vektor,Smjer neki)
{
	deque<vector<int>>rast;
	deque<vector<int>>pad;
	vector<int>v;
	for(int i=0; i<vektor.size(); i++) {
		if(ProvjeraStepena(vektor.at(i)))
			v.push_back(vektor.at(i));
		else
			v.push_back(0);
	}
	if(neki==Rastuci) {
		vector<int>h;
		if(v.at(0)!=0)
			h.push_back(v.at(0));
		for(int i=0; i<int(v.size())-1; i++) {
			if(v.size()==0 && v.at(i)!=0)
				h.push_back(v.at(i));
			if(v.at(i)<=v.at(i+1) && v.at(i+1)!=0) {
				h.push_back(v.at(i+1));
			} else if(h.size()>1) {
				rast.push_back(h);
				h.resize(0);
				if(v.at(i+1)!=0)
					h.push_back(v.at(i+1));
			} else {
				h.resize(0);
				if(v.at(i+1)!=0)
					h.push_back(v.at(i+1));
			}
		}
		if(h.size()>1)
			rast.push_back(h);
		return rast;
	}



	if(neki==Opadajuci) {
		vector<int>k(1,v.at(0));
		for(int i=0; i<int(v.size())-1; i++) {
			if(v.at(i)>=v.at(i+1) && v.at(i+1)!=0)
				k.push_back(v.at(i+1));
			else if(k.size()>1) {
				pad.push_back(k);
				k.resize(0);
				k.push_back(v.at(i+1));
			} else {
				k.resize(0);
				k.push_back(v.at(i+1));
			}
		}
		if(k.size()>1)
			pad.push_back(k);
		return pad;
	}
}

int main ()
{
	vector<int>vektor;
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int k;
		cin>>k;
		vektor.push_back(k);
	}
	deque<vector<int>>rast;
	deque<vector<int>>pad;
	int izb;
	do {
		cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
opet:
		cin>>izb;
		if(izb==1 || izb==2) break;
		cout<<"Neispravan unos! Unesite ponovo: ";
		goto opet;
	} while(izb==1 || izb==2);
	if(izb==1) {
		rast=MaksimalniPodnizoviStepenaDvojke(vektor,Rastuci);
		cout<<"Maksimalni rastuci podnizovi: \n";
		for(int i=0; i<rast.size(); i++) {
			for(int j=0; j<rast.at(i).size(); j++) {
				cout<<rast.at(i).at(j)<<" ";
			}
			cout<<endl;
		}
	}
	if(izb==2) {
		pad=MaksimalniPodnizoviStepenaDvojke(vektor,Opadajuci);
		cout<<"Maksimalni opadajuci podnizovi: \n";
		for(int i=0; i<pad.size(); i++) {
			for(int j=0; j<pad.at(i).size(); j++) {
				cout<<pad.at(i).at(j)<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}