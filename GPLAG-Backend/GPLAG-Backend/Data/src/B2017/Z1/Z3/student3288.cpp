#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <deque>
using std::cin;
using std::cout;
using std::vector;
using std::deque;

enum Smjer {Rastuci=1,Opadajuci=2};
int StepenDvojke(int n)
{
	for(int i=1; i<=n; i*=2) {
		if(i==n) return 1;
	}
	return 0;
}
std::deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer s)
{
	deque<vector<int>> d;
	vector<int> p;
	int x=0;
	if(s==Rastuci) {
		do {
			p.resize(0);
			for(int i=x; i<v.size()-1; i++) {
				if(v.at(i+1)>=v.at(i) && StepenDvojke(v.at(i))!=0 && StepenDvojke(v.at(i+1))!=0) {
					p.push_back(v.at(i));
					if(i+1==(v.size()-1) && StepenDvojke(v.at(i+1))){
						p.push_back(v.at(i+1));
						x=i+1;
						break;
					} 
				} else if(p.size()!=0 && (v.at(i+1)<v.at(i) || !StepenDvojke(v.at(i+1)))) {
					p.push_back(v.at(i));
					x=i;
					break;
				}
			}
			if(p.size()) d.push_back(p);
		} while(p.size());
	} else if(s==Opadajuci) {
		do {
			p.resize(0);
			for(int i=x; i<v.size()-1; i++) {
				if(v.at(i+1)<=v.at(i) && StepenDvojke(v.at(i))!=0 && StepenDvojke(v.at(i+1))!=0) {
					p.push_back(v.at(i));
					if(i+1==(v.size()-1) && StepenDvojke(v.at(i+1))){
						 p.push_back(v.at(i+1));
						 x=i+1;
						 break;
					}
				} else if(p.size()!=0 && (v.at(i+1)>v.at(i) || !StepenDvojke(v.at(i+1)))) {
					p.push_back(v.at(i));
					x=i;
					break;
				}
			}
			if(p.size()) d.push_back(p);
		} while(p.size());
	}
	return d;
}
int main ()
{
	int a,b;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>a;
	if(a<=0) return 0;
	cout<<"Unesite elemente vektora: ";
	vector<int> v(a);
	for(int i=0; i<a; i++) {
		cin>>v.at(i);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>b;
	Smjer smj = Smjer(b);
	if(b==1) {
		cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	} else if(b==2) {
		cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	deque<vector<int>> d(MaksimalniPodnizoviStepenaDvojke(v,smj));
	for(int i=0; i<d.size(); i++) {
		for(int j=0; j<d.at(i).size(); j++)
			cout<<d[i].at(j)<<" ";
		cout<<std::endl;
	}
	return 0;
}