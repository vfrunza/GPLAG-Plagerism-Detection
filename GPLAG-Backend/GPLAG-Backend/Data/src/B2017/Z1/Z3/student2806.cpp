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
using namespace std;

typedef deque<vector<int>> DekVek;
enum Smjer {Rastuci=1, Opadajuci=2};

/*vector<int> StepenDvojke (vector<int> v){
	vector<int> dvojka;
	for(int i=0; i<v.size(); i++){
		int br=1;
		while(br<v.at(i)) br*=2;
		if(br==v.at(i) || v.at(i)==1) dvojka.push_back(v.at(i));
	}
	return dvojka;
}*/

bool JeLiStepenDvojke(int br){
	if(br==1) return true;
	int brojac(1);
	for(int i=0; i<br; i++){
		brojac*=2;
		if(brojac==br) return true;
	}
	return false;
}

DekVek MaksimalniPodnizoviStepenaDvojke (vector<int> pom, Smjer ro){
	vector<int> v;
	
	DekVek podniz;
	
	if(ro==1){
		for(int i=0; i<pom.size()-1; i++){
			bool g(false);
			while(i<pom.size()-1 && pom.at(i)<pom.at(i+1) && JeLiStepenDvojke(pom.at(i)) && JeLiStepenDvojke(pom.at(i+1))) {
				v.push_back(pom.at(i));
				i++;
				g=true;
			}
			if(g==true) v.push_back(pom.at(i));
			if(v.size()!=0){
				podniz.push_back(v);
				v.resize(0);
			}
			g=false;
			
		}
	}
	
	else {
		for(int i=0; i<pom.size()-1; i++){
			bool g(false);
			while(i<pom.size()-1 && pom.at(i)>pom.at(i+1) && JeLiStepenDvojke(pom.at(i)) && JeLiStepenDvojke(pom.at(i+1))) {
				v.push_back(pom.at(i));
				i++;
				g=true;
			}
			if(g==true) v.push_back(pom.at(i));
			if(v.size()!=0){
				podniz.push_back(v);
				v.resize(0);
			}
			g=false;
			
		}
	}
	
	return podniz;
}

int main ()
{
	int n, br;
	int op_rast;
	bool ok(true);
	
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<int> v(n);
	for (int i=0; i<n; i++){
		cin>>br;
		v.at(i)=br;
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	while(ok==true){
		cin>>op_rast;
		if(op_rast!=1 && op_rast!=2){
			cin.ignore();
			cin>>op_rast;
			ok=true;
		}
		else ok=false;
	}
	if(op_rast==1){
		cout<<"Maksimalni rastuci podnizovi: "<<endl;
		DekVek d;

		d=MaksimalniPodnizoviStepenaDvojke(v, Smjer(op_rast));
		for(int i=0; i<d.size(); i++){
			for(int j=0; j<d.at(i).size(); j++){
				cout<<d.at(i).at(j)<<" ";
			}
			cout<<endl;
		}
	}
	if(op_rast==2) {
		cout<<"Maksimalni opadajuci podnizovi: "<<endl;
		DekVek d;

		d=MaksimalniPodnizoviStepenaDvojke(v, Smjer(op_rast));
		for(int i=0; i<d.size(); i++){
			for(int j=0; j<d.at(i).size(); j++){
				cout<<d.at(i).at(j)<<" ";
			}
			cout<<endl;
		}
	}
	
	
	return 0;
}