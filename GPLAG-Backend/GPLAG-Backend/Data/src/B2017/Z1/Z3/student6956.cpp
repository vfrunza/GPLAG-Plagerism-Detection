#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

enum Smjer {Rastuci,Opadajuci};
typedef std::deque<std::vector<int>> DekVektora;

DekVektora Brisanje(DekVektora m)
{
	for(int i=0; i<m.size(); i++) {
		if(m.at(i).size()==1) {
			m.erase(m.begin()+i);
			i--;
		}
	}
	return m;
}


bool DaLiJeStepenDva(int n)
{
	int k(0),z(0);
	bool stepen(false);
	while(n>z) {
		z=pow(2,k);
		if(n==z) {
			stepen=true;
		}
		k++;
	}
	if(stepen==true) return true;
	else return false;
}


DekVektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer S)
{
	DekVektora m(1,std::vector<int>());
	if(S==Rastuci) {
		v.push_back(100000);
		int a(0),b(1);
		for(int i=0; i<v.size()-1; i++) {
			
			if(DaLiJeStepenDva(v.at(i))==true && DaLiJeStepenDva(v.at(i+1))==true && v.at(i)<=v.at(i+1)) {
				m.at(a).push_back(v.at(i));

			} else {
				m.at(a).push_back(v.at(i));
				a++;
				b++;
				m.resize(b);
			}

		}
	}

	if(S==Opadajuci) {
		v.push_back(-100000);
		int a(0),b(1);

		for(int i=0; i<v.size()-1; i++) {
		
			if(DaLiJeStepenDva(v.at(i))==true && DaLiJeStepenDva(v.at(i+1))==true && v.at(i)>=v.at(i+1)) {
				m.at(a).push_back(v.at(i));
			} else {
				m.at(a).push_back(v.at(i));
				a++;
				b++;
				m.resize(b);
			}
		}
	}
	m=Brisanje(m);
	return m;
}

int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	std::vector<int> v(n);
	cout<<"Unesite elemente vektora: ";

	for(int i=0; i<v.size(); i++) {
		cin>>v.at(i);

	}

	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int n1;
	cin>>n1;

	Smjer s;

	if(n1==1) {
		s=Rastuci;
		DekVektora d {MaksimalniPodnizoviStepenaDvojke(v,s)};
		cout<<"Maksimalni rastuci podnizovi: ";
		cout<<endl;
		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(i).size(); j++) {
				cout<<d.at(i).at(j)<<" ";
			}
			cout<<endl;
		}
	}
	if(n1==2) {
		s=Opadajuci;
		DekVektora d {MaksimalniPodnizoviStepenaDvojke(v,s)};

		cout<<"Maksimalni opadajuci podnizovi: ";
		cout<<endl;
		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(i).size(); j++) {
				cout<<d.at(i).at(j)<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}