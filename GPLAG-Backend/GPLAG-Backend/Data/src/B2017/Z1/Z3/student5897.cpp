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
#include <cmath>
#include <vector>
#include <deque>
using namespace std;
typedef deque<vector<int>> Mat;
enum Smjer{Opadajuci,Rastuci};
bool StepenDvojke(int x){
	for(int i=0;i<100;i++){
		if(pow(2,i)==x) return true;
	}
	return false;
}
Mat RASTUCI(vector<int>v){
	Mat M;
	int j(1);
	Mat prazna;
	if(v.size()==0) return prazna; 
	for(int i=0;i<v.size()-1;i++){
		if(v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))){
			vector<int>r;
			while(v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))){
				r.push_back(v.at(i));
				i++;
				if(i==v.size()-1) break;
			}
			r.push_back(v.at(i));
			M.resize(j);
			for(int k=0;k<r.size();k++){
				M.at(j-1).push_back(r.at(k));
				if(k==r.size()) break;
			}
			j++;
			if(i==v.size()-1) break;
		}
	}
	return M;
}
Mat OPADAJUCI(vector<int>v){
		Mat M;
	int j(1);
	Mat prazna;
	if(v.size()==0) return prazna; 
	for(int i=0;i<v.size()-1;i++){
		if(v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))){
			vector<int>r;
			while(v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))){
				r.push_back(v.at(i));
				i++;
				if(i==v.size()-1) break;
			}
			r.push_back(v.at(i));
			M.resize(j);
			for(int k=0;k<r.size();k++){
				M.at(j-1).push_back(r.at(k));
				if(k==r.size()) break;
			}
			j++;
			if(i==v.size()-1) break;
		}
	}
	return M;
}
Mat MaksimalniPodnizoviStepenaDvojke(vector<int>v,enum Smjer Karakter){
	if(Karakter==Rastuci)
		return RASTUCI(v);
	
	if(Karakter==Opadajuci)
		return OPADAJUCI(v);
	
}
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	int m;
	vector<int>v;
	for(int i=0;i<n;i++){
		cin>>m;
		v.push_back(m);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int karakter;
	cin>>karakter;
if(karakter==1){
	Mat M1(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	for(int i=0;i<M1.size();i++){
		for(int j=0;j<M1.at(i).size();j++){
			cout<<M1.at(i).at(j)<<" ";
			if(M1.at(i).size()==j) break;
		}
		if(M1.size()==i) break;
		cout<<endl;
	}
	return 0;
}
if(karakter==2){
	Mat M2(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	for(int i=0;i<M2.size();i++){
		for(int j=0;j<M2.at(i).size();j++){
			cout<<M2.at(i).at(j)<<" ";
			if(M2.at(i).size()==j) break;
		}
		if(M2.size()==i) break;
		cout<<endl;
	}
	return 0;
}
	return 0;
}