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
#include <cmath>
#include <deque>

using namespace std;

enum Smjer {Rastuci,Opadajuci};

bool pomocna(int a){
	for(int i=0;i<32;i++){
		if(a==pow(2,i)){return true;}
	}
	return false;
}
deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, enum Smjer nesto){
deque<vector<int>> d;
if(nesto==Rastuci){
/*	vector<int> tmp;
	int j=1;
	for(int i=0;i<v.size()-1;i++){
		tmp.resize(0);
		while(v.at(i)<=v.at(i+1) &&  pomocna(v.at(i))==true && pomocna(v.at(i+1))==true){
			tmp.push_back(v.at(i));
			if(i==v.size()-1) break;//
			i++;
			
		}
		if(v.at(i)>=v.at(i-1) && pomocna(v.at(i))==true )tmp.push_back(v.at(i));
		
		d.resize(j);
		
		for(int k=0;k<tmp.size();k++){
			d[j-1].push_back(tmp.at(k));
			if(k==tmp.size()-1) break;
		}
		j++;
		if(i==v.size()-1) break;
	}
	
	
*/
deque<vector<int>> rastuci;
int i=0,k=0;
bool logicka = false;
while(i<v.size()){
	while(i<v.size()-1 && v.at(i)<=v[i+1] && pomocna(v.at(i))==true && pomocna(v[i+1])==true){
		rastuci.resize(k+1);
		logicka=true;
		rastuci.at(k).push_back(v.at(i));
		i++;
		if(i==v.size()-1) break;
	}
	if(i<v.size() && logicka==true){
		rastuci.at(k).push_back(v.at(i));
		k++;
		i++;
	}
	if(logicka==false) i++;
	if(i>=v.size()) break;
	logicka=false;
}
return rastuci;
}
if(nesto==Opadajuci){
	
	/*vector<int> tmp;
	int j=1;
	for(int i=0;i<v.size()-1;i++){
		tmp.resize(0);
		while(v.at(i)>=v.at(i+1)  && pomocna(v.at(i))==true && pomocna(v.at(i+1))==true){
			tmp.push_back(v.at(i));

			i++;
				if(v.at(i)>=v.at(i+1) &&  pomocna(v.at(i))==true && pomocna(v.at(i+1))==true) continue;
		if(v.at(i)<=v.at(i-1) && pomocna(v.at(i))==true )tmp.push_back(v.at(i));	
		}
	   
		
		d.resize(j);
		
		for(int k=0;k<tmp.size();k++){
			d.at(j-1).push_back(tmp.at(k));
			if(k==tmp.size()-1) break;
		}
		j++;
		if(i==v.size()-1) break;
	}
}

return d;*/
deque<vector<int>> opadajuci;
int i=0,k=0;
bool logicka = false;
while(i<v.size()){
	while(i<v.size()-1 && v.at(i)>=v[i+1] && pomocna(v.at(i))==true && pomocna(v[i+1])==true){
		opadajuci.resize(k+1);
		logicka=true;
		opadajuci.at(k).push_back(v.at(i));
		i++;
		if(i==v.size()-1) break;
	}
	if(i<v.size() && logicka==true){
		opadajuci.at(k).push_back(v.at(i));
		k++;
		i++;
	}
	if(logicka==false) i++;
	if(i>=v.size()) break;
	logicka=false;
}
return opadajuci;

}
}
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	vector<int> vec(n);
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<vec.size();i++){
	cin>>vec.at(i);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a;
	cin >> a;
	if(a==1){
		deque<vector<int>> dek = MaksimalniPodnizoviStepenaDvojke(vec,Rastuci);
		cout<<"Maksimalni rastuci podnizovi: "<<endl;
		for(int i=0;i<dek.size();i++){
			for(int j=0;j<dek[i].size();j++){
				
				cout<<dek[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	if(a==2){
		deque<vector<int>> dek = MaksimalniPodnizoviStepenaDvojke(vec,Opadajuci);
		cout<<"Maksimalni opadajuci podnizovi: "<<endl;
		for(int i=0;i<dek.size();i++){
			for(int j=0;j<dek[i].size();j++){
				cout<<dek[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}