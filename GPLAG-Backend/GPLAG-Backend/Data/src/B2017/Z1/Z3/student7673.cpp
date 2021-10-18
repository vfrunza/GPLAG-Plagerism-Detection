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
#include <stdexcept>
#include <deque>
using namespace std;

int stepen(int n, int s){
	int rez=1;
	for(int i=0; i<s; i++) rez*=n;
	return rez;
}

bool stependvojke(int n){
	for(int i=0; i<10; i++) if(stepen(2,i)==n) return true;
	return false;
}

deque<vector<int>> opadajuci(vector<int> v){
	deque<vector<int>> rez;
	for(int i=0; i<v.size(); i++){
		vector<int> pom;
		if(stependvojke(v.at(i))) pom.push_back(v.at(i));
		i++;
		while(i!=v.size() && v.at(i)<=v.at(i-1) && stependvojke(v.at(i))) { pom.push_back(v.at(i)); i++; }
		if(pom.size()!=1 && pom.size()!=0) rez.push_back(pom);
		i--;
	}
	return rez;
}

deque<vector<int>> rastuci(vector<int> v){
	deque<vector<int>> rez;
	for(int i=0; i<v.size(); i++){
		vector<int> pom;
		if(stependvojke(v.at(i))) pom.push_back(v.at(i));
		i++;
		while(i!=v.size() && v.at(i)>=v.at(i-1) && stependvojke(v.at(i))) { pom.push_back(v.at(i)); i++; }
		if(pom.size()!=1 && pom.size()!=0) rez.push_back(pom);
		i--;
	}
	return rez;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, bool a){
	if(a) return rastuci(v);
	return opadajuci(v);
}

int main ()
{
	
	int n;
	vector<int> v;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	v.resize(n);
	for(int i=0; i<n; i++) cin>>v.at(i);
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a; cin>>a;
	if(a==1){
		cout<<"Maksimalni rastuci podnizovi: "<<endl;
		deque<vector<int>> d=MaksimalniPodnizoviStepenaDvojke(v,true);
		for(int i=0; i<d.size(); i++)
		{
			for(int j=0; j<d.at(i).size(); j++)
			{
				cout<<d.at(i).at(j)<<" ";
			} cout<<endl;
		}
		
	}
	else {
		cout<<"Maksimalni opadajuci podnizovi: "<<endl;
		deque<vector<int>> d=MaksimalniPodnizoviStepenaDvojke(v,false);
		for(int i=0; i<d.size(); i++)
		{
			for(int j=0; j<d.at(i).size(); j++)
			{
				cout<<d.at(i).at(j)<<" ";
			} cout<<endl;
		}
	} 
	return 0;
}