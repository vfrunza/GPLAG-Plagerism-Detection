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

enum Smjer {Rastuci,Opadajuci};

std::vector<int> NisuStepeniDvojke(std::vector<int> v)
{
	std::vector<int> a;
	for(int i=0; i<v.size(); i++) {
		int x=v.at(i);
		if(x==0) { a.push_back(v.at(i)); continue; }
		while(x!=0) {
			if(x%2!=0) {
				if(x!=1) {
					a.push_back(v.at(i));
					break;
				}
			}
			x/=2;
		}
	}
	return a;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, enum Smjer s)
{
	std::deque<std::vector<int>> d;
	std::vector<int> temp;
	bool T(true);
if(v.size()<2) return d;
	if(s==Rastuci) {
		for(int i=0; i<v.size()-1; i++) {
			int x=v.at(i);
			int y=v.at(i+1);
			for(int j=0; j<NisuStepeniDvojke(v).size(); j++)
				if(x==NisuStepeniDvojke(v).at(j) || y==NisuStepeniDvojke(v).at(j)) T=false;
			if(!T) {
				T=true;
				continue;
			}
			if(y>=x) {
				if(temp.size()==0) {
					temp.push_back(x);
					temp.push_back(y);
				} else temp.push_back(y);
			} else if(temp.size()!=0) {
				d.push_back(temp);
				int l=temp.size();
				for(int k=0; k<l; k++)
					temp.erase(temp.begin() + 0);
			}
		}
		if(temp.size()!=0)
			d.push_back(temp);
	} else if(s==Opadajuci) {
		for(int i=0; i<v.size()-1; i++) {
			int x=v.at(i);
			int y=v.at(i+1);
			for(int j=0; j<NisuStepeniDvojke(v).size(); j++)
				if(x==NisuStepeniDvojke(v).at(j) || y==NisuStepeniDvojke(v).at(j)) T=false;
			if(!T) {
				T=true;
				continue;
			}
			if(x>=y) {
				if(temp.size()==0) {
					temp.push_back(x);
					temp.push_back(y);
				} else temp.push_back(y);
			} else if(temp.size()!=0) {
				d.push_back(temp);
				int l=temp.size();
				for(int k=0; k<l; k++)
					temp.erase(temp.begin() + 0);
			}
		}
		if(temp.size()!=0)
			d.push_back(temp);

	}
	return d;
}

int main ()
{
	int n(0),t;
	std::vector<int> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int x;
		std::cin>>x;
		v.push_back(x);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>t;
	if(t==1) {
		std::cout<<"Maksimalni rastuci podnizovi: ";
		std::cout<<std::endl;
		for(int i=0; i<MaksimalniPodnizoviStepenaDvojke(v,Rastuci).size(); i++){
			for(int j=0; j<MaksimalniPodnizoviStepenaDvojke(v,Rastuci)[i].size(); j++)
				std::cout<<MaksimalniPodnizoviStepenaDvojke(v,Rastuci)[i][j]<<" ";
		std::cout<<std::endl;}
	} else if(t==2) {
		std::cout<<"Maksimalni opadajuci podnizovi: ";
		std::cout<<std::endl;
		for(int i=0; i<MaksimalniPodnizoviStepenaDvojke(v,Opadajuci).size(); i++){
			for(int j=0; j<MaksimalniPodnizoviStepenaDvojke(v,Opadajuci)[i].size(); j++)
				std::cout<<MaksimalniPodnizoviStepenaDvojke(v,Opadajuci)[i][j]<<" ";
		std::cout<<std::endl;}
	}
	return 0;
}