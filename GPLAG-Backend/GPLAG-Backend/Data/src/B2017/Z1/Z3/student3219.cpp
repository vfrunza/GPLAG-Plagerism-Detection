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
#include <iomanip>

using namespace std;

enum Smjer {Opadajuci,Rastuci};
typedef deque<vector<int>> Niz;


bool StepenDvojke(int n)
{
	for(int i=0; i<32; i++) {
		if(pow(2,i)==n)
			return true;
	}
	return false;
}


Niz MaksimalniPodnizoviStepenaDvojke (vector <int> a, Smjer smjer )
{


	Niz rastuci;
	Niz opadajuci;

	vector <int> pod1;
	vector <int> pod2;

	if(smjer==Rastuci) {
		for(int i=0; i<a.size()-1; i++) {

			pod1.clear();
			while(i<a.size()-1 && a.at(i)<=a.at(i+1) && StepenDvojke(a.at(i))==true && StepenDvojke(a.at(i+1))==true) {
				pod1.push_back(a.at(i));
				i++;

			}
			pod1.push_back(a.at(i));
			if(pod1.size()-1>0)
				rastuci.push_back(pod1);
		}
	}


	if(smjer==Opadajuci) {
		for(int j=0; j<a.size()-1; j++) {
			pod2.clear();
			while(j<a.size()-1 && a.at(j)>=a.at(j+1) && StepenDvojke(a.at(j))==true && StepenDvojke(a.at(j+1))==true) {
				pod2.push_back(a.at(j));
				j++;
			}
			pod2.push_back(a.at(j));

			if(pod2.size()-1>0)
				opadajuci.push_back(pod2);
		}

	}


	if(smjer==Rastuci) return rastuci;
	return opadajuci;
}


int main ()
{
	int a;
	int c;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>a;
	cout<<"Unesite elemente vektora: ";
	vector<int> b(a);
	for(int i=0; i<a; i++) {
		cin>>b.at(i);
	}

	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";


	Niz rastucii;
	Niz opadajucii;

	rastucii=MaksimalniPodnizoviStepenaDvojke(b, Rastuci);
	opadajucii=MaksimalniPodnizoviStepenaDvojke(b, Opadajuci);





	do {
		cin>>c;
		if(c==1) {
			cout<<"Maksimalni rastuci podnizovi: "<<endl;
			for(auto niz1: rastucii) {
				for(auto broj1: niz1) {
					cout<<broj1<<" ";

				}
				cout<<endl;
			}
			break;
		} 
		else if(c==2) {
			cout<<"Maksimalni opadajuci podnizovi: "<<endl;
			for(auto niz2: opadajucii) {
				for(auto broj2: niz2) {
					cout<<broj2<<" ";
				}
				cout<<endl;
			}
			
			break;
		}
		
		if(c!=1 || c!=2){
			cout<<"Neispravan unos! Unesite ponovo: ";
		}
		
	}while(1);

	return 0;
}