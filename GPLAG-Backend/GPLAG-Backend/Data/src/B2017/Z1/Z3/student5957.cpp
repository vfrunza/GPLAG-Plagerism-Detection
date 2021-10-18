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
#include <string>
using std::string;
using std::deque;
using std::cout;
using std::cin;
using std::vector;
enum Smjer{Opadajuci,Rastuci};

bool StepenDvojke(int broj){
	if(broj==1) return true;
	if(broj<=0) return false;
	for(;;){
		if(broj%2==0) broj/=2;
		else return false;
		if(broj==1) return true;
	}
}

deque<vector<int>> RastuciOpadajuci(vector<int> v,bool istina){
	deque<vector<int>> mat(1);
	int k(0);
	for(int i(1);i<v.size();i++){
		if(istina && v.at(i-1)<=v.at(i) && StepenDvojke(v.at(i-1))){
			mat.at(k).push_back(v.at(i-1));
		}
		else if(!istina && v.at(i-1)>=v.at(i) && StepenDvojke(v.at(i-1))){
			mat.at(k).push_back(v.at(i-1));
		}
		else{
			if(StepenDvojke(v.at(i-1))) mat.at(k).push_back(v.at(i-1));
			mat.resize(mat.size()+1);
			k++;
		}
		if(i==v.size()-1 && StepenDvojke(v.at(i))) mat.at(k).push_back(v.at(i));
	}
	for(int i(0);i<mat.size();i++){
		if(mat.at(i).size()<2){
			mat.erase(mat.begin()+i); i--;
		}
	}
	return mat;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v,bool istina){
	if(v.size()<=1) return deque<vector<int>>(0);
	deque<vector<int>> mat;
	mat=RastuciOpadajuci(v,istina);
	return mat;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v,enum Smjer smjer){
	if(v.size()<=1) return deque<vector<int>>(0);
	deque<vector<int>> mat;
	if(smjer==Rastuci)
	mat=RastuciOpadajuci(v,true);
	if(smjer==Opadajuci)
	mat=RastuciOpadajuci(v,false);
	return mat;
}

int main ()
{
	int n(0),k(0);
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<int> v;
	for(int i(0);i<n;i++){
		int k(0);
		cin>>k;
		v.push_back(k);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>k;
	deque<vector<int>> mat;
	if(k==1){
		cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		mat=MaksimalniPodnizoviStepenaDvojke(v,Smjer(Rastuci));
		for(vector<int> i : mat){
			for(int j : i) cout<<j<<" ";
			cout<<std::endl;
	}
	}
	if(k==2){
		cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		mat=MaksimalniPodnizoviStepenaDvojke(v,Smjer(Opadajuci));
		for(vector<int> i : mat){
			for(int j : i) cout<<j<<" ";
			cout<<std::endl;
		}	
	}
	return 0;
}