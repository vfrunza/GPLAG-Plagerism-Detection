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

enum Smjer{Rastuci,Opadajuci};

bool JelStepen(int n){
	int br=1;
	while(br<=n){
		if(br==n) return true;
		br*=2;
	}
	return false;
}
deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer smjer){
	deque<vector<int>> x;
	vector<int> vek1,vek2;
	for(int i(0);i<v.size()-1;i++){
		if(smjer==Smjer::Rastuci){
			if(v.at(i)<v.at(i+1)&&JelStepen(v.at(i))==true&&JelStepen(v.at(i+1))==true){
				if(vek1.size()==0){
					vek1.push_back(v.at(i));
				}
				vek1.push_back(v.at(i+1));
				continue;
			}
			if(vek1.size()!=0){
				x.push_back(vek1);
				vek1.resize(0);
			}
		}
		else{
			if(v.at(i)>v.at(i+1)&&JelStepen(v.at(i))==true&&JelStepen(v.at(i+1))==true){
				if(vek2.size()==0){
					vek2.push_back(v.at(i));
				}
				vek2.push_back(v.at(i+1));
				continue;
			}
			if(vek2.size()!=0){
				x.push_back(vek2);
				vek2.resize(0);
			}
		}
	}
	if(smjer==Smjer::Rastuci){
		x.push_back(vek1);
	}
	else{
		x.push_back(vek2);
	}
	return x;
}

int main ()
{
	int n,c;
	vector<int>v;
	deque<vector<int>>v1;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	for(int i(0);i<n;i++){
		int x;
		cin>>x;
		if(x==0) break;
		v.push_back(x);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>c;
	if(c==1){
	v1=MaksimalniPodnizoviStepenaDvojke(v,Smjer::Rastuci);
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	}
	else{
		v1=MaksimalniPodnizoviStepenaDvojke(v,Smjer::Opadajuci);
		cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	}
	
	for(int i(0);i<v1.size();i++){
		for(int j(0);j<v1.at(i).size();j++){
			cout<<v1.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
	return 0;
}