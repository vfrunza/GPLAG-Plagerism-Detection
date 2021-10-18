#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
enum Smjer { Rastuci, Opadajuci };
deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer GoreDolje)
{
	deque<vector<int>> d;
	Smjer gore(Rastuci);
	int brojac(0),red(0);
	bool StepenDvojke(false);
	for(int i=0; i<v.size(); i++) {
		int broj(v.at(i)),tmp(0);
		if(broj>0) {
			brojac=0;
			StepenDvojke=false;
			for(int j=0; j<=broj; j++) {
				if(int(pow(2,j))==broj) {
					StepenDvojke=true;
					brojac++;
					break;
				}
			}
			if(StepenDvojke==true && gore==GoreDolje) {
				StepenDvojke=false;
				d.resize(red+1);
				d.at(red).push_back(broj);
				brojac=1;
				tmp=0;
				for(int k=i+1; k<=v.size()-1; k++) {
					if(v.at(k)<=v.at(k-1)) break;
					if(v.at(k)>v.at(k-1) && v.at(k)>0 && v.at(k-1)>0) {
						brojac=1;
						StepenDvojke=false;
						for(int j=0; j<=v.at(k); j++) {
							if(int(pow(2,j))==v.at(k)) {
								StepenDvojke=true;
								brojac++;
								break;
							}
						}
						if(brojac>1 && StepenDvojke) {
							d.at(red).push_back(v.at(k));
							tmp=k;
						} else break;
					}
				}
				if(d.at(red).size()>1) red++;
				else if(d.at(red).size()<=1) d.resize(d.size()-1);
				if(tmp!=0) i=tmp;
			} else if(StepenDvojke==true && gore!=GoreDolje) {
				StepenDvojke=false;
				d.resize(red+1);
				d.at(red).push_back(broj);
				brojac=1;
				tmp=0;
				for(int k=i+1; k<=v.size()-1; k++) {
					if(v.at(k)>=v.at(k-1)) break;
					if(v.at(k)<v.at(k-1) && v.at(k)>0 && v.at(k-1)>0) {
						brojac=1;
						StepenDvojke=false;
						for(int j=0; j<=v.at(k); j++) {
							if(int(pow(2,j))==v.at(k)) {
								StepenDvojke=true;
								brojac++;
								break;
							}
						}
						if(brojac>1) {
							d.at(red).push_back(v.at(k));
							tmp=k;
						} else break;
					}
				}
				if(d.at(red).size()>1) red++;
				else if(d.at(red).size()<=1) d.resize(d.size()-1);
				if(tmp!=0) i=tmp;
			}
		}
	}
	return d;
}
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<int> v;
	int brojevi;
	for(int i=0; i<n; i++) {
		cin>>brojevi;
		v.push_back(brojevi);
	}
	cin.ignore(10000,'\n');
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int unos(0);
	cin>>unos;
	Smjer smjer(Opadajuci);
	if(unos==1) smjer=Rastuci;
	else if(unos==2) smjer=Opadajuci;
	deque<vector<int>> d(MaksimalniPodnizoviStepenaDvojke(v,smjer));
	if(d.size()!=0) {
		if(smjer==Rastuci) cout<<"Maksimalni rastuci podnizovi: \n";
		else if(smjer==Opadajuci) cout<<"Maksimalni opadajuci podnizovi: \n";
		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(i).size(); j++) {
				cout<<d.at(i).at(j)<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}