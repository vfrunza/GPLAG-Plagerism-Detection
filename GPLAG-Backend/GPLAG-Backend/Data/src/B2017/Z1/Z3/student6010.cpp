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
#include<iomanip>
using namespace std;
typedef vector<vector<int>>Matrica;
typedef deque<vector<int>>DekVektora;
	enum Smjer{Opadajuci, Rastuci};

bool DaLiJeStepenDvojke(int n){
	if(n<1) return false;
	if(n==1 || n==2) return true;
	int pom=1;
	int proizvod=2;
	while(pom<n/2){
		proizvod*=2;
		pom++;
		if(proizvod==n)return true;
	}
	
	return false;
}




vector<vector<int>> OpadajuciPodnizovi (vector<int>v){
	vector<vector<int>>v1;
	vector<int>v2;
	if(v.size()==0) return v1;
	//int i(0);
	bool prethodni=0;int brojac=1,pom=0;
	if(v.at(0)>=v.at(1) && DaLiJeStepenDvojke(v.at(0)) && v.size()){ v2.push_back(v.at(0)); prethodni=true;brojac++;}
	
	for(int i(1);i<v.size()-1;i++){
	
		//////////////////////////////////////////////////////
		if(v.at(i)>=v.at(i+1) && (DaLiJeStepenDvojke(v.at(i))==1) ) {
			v2.push_back(v.at(i)); prethodni=true;
			brojac++;
			if(brojac>(v.size()-1)) {v2.push_back(v.at(i+1));v1.push_back(v2); break;}
			
		}
		else if(prethodni){
			pom=1;
			brojac--;
			if(DaLiJeStepenDvojke(v.at(i)))
		v2.push_back(v.at(i));
		prethodni=false;
		v1.push_back(v2);
		//for(int i(0);i<v2.size();i++)cout<<v2[i]; 12 16 8 4 9 
		//ne pada kada je zadnji stepen dvojke ali nije opadajuci(16) i kada zadnji nije ni stepen dvoje ni opadajuci(9)
		//pada kada je zadnji opadajuci ali nije stepen dvojke(3)
		//(pada kad je zadnji opadajuci  i stepen dvojke (1))
		v2.resize(0);
		
	}
	

	}
	if(!pom && brojac<v.size()-1) { 
	if(v.at(v.size()-1)<=v.at(v.size()-2) && DaLiJeStepenDvojke(v.at(v.size()-1))) 
	v2.push_back(v.at(v.size()-1) );
	v1.push_back(v2);
	}
	return v1;
	}
	
	
	vector<vector<int>> RastuciPodnizovi (vector<int>v){
	vector<vector<int>>v1;
	vector<int>v2;
	if(v.size()==0) return v1;
	//int i(0);
	bool prethodni=0;
	int brojac=1,pom=0;
	if(v.at(0)<=v.at(1) && DaLiJeStepenDvojke(v.at(0)) && v.size()){ v2.push_back(v.at(0)); prethodni=true; brojac++;}
	for(int i(1);i<v.size()-1;i++){
		if(v.at(i)<=v.at(i+1) && (DaLiJeStepenDvojke(v.at(i))==1) ) {
			v2.push_back(v.at(i)); prethodni=true;
			brojac++;
			if(brojac>(v.size()-1)) {v2.push_back(v.at(i+1));v1.push_back(v2); break;}
		}
		else if(prethodni){
			pom=1;
			brojac--;
			if(DaLiJeStepenDvojke(v.at(i)))
		v2.push_back(v.at(i));
		prethodni=false;
		v1.push_back(v2);
		v2.resize(0);
		}
	}
	if(!pom && brojac<v.size()-1) { 
		if(v.at(v.size()-1)>=v.at(v.size()-2) && DaLiJeStepenDvojke(v.at(v.size()-1)))
		v2.push_back(v.at(v.size()-1));
		v1.push_back(v2);
		}
	return v1;
	}
	
	

DekVektora MaksimalniPodnizoviStepenaDvojke (vector<int>v, Smjer s){
	vector<vector<int>>v1;
	vector<int>v2;
	deque<vector<int>>d;
	if(s==Rastuci) v1=RastuciPodnizovi(v);
	else if(s==Opadajuci)  v1=OpadajuciPodnizovi(v);
	for(int i(0);i<v1.size();i++){
		for(int j(0);j<v1.at(i).size();j++){
		if(v1.at(i).size()!=1) 
		v2.push_back(v1.at(i).at(j));
		else continue;
			}
			if(v1.at(i).size()!=1) 
			d.push_back(v2);
		v2.resize(0);
	}
	return d;
}


int main ()
{ 

	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	vector<int>v(n);
	cout<<"Unesite elemente vektora: ";
	for(int i(0);i<n;i++){
		cin>>v.at(i);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a;
	cin>>a;
	deque<vector<int>> d;
	if(a==1)
 d=MaksimalniPodnizoviStepenaDvojke(v, Rastuci );
	else if (a==2)
 d=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
	 if(a==1) cout<<"Maksimalni rastuci podnizovi: "<<endl;
	 		if(a==2) cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	 for(int i(0);i<d.size();i++){
	 	for( int j(0);j<d.at(i).size();j++){
	 		
	 		cout<<d.at(i).at(j)<<" ";
	 	}
	 	cout<<endl;
	 }
	
	 /*provjeraaaa vector<int> brojevi {};
deque<vector<int>>  d;
cout<<endl<<"Rastuci: ";
d=MaksimalniPodnizoviStepenaDvojke(brojevi,rastuci);
for(int i(0);i<d.size();i++){
	 	for( int j(0);j<d[i].size();j++){
	 		
	 		cout<<d[i][j]<<" ";
	 	}
	 	cout<<endl;
	 }
d=MaksimalniPodnizoviStepenaDvojke(brojevi,opadajuci);
cout<<endl<<"Opadajuci: ";
for(int i(0);i<d.size();i++){
	 	for( int j(0);j<d[i].size();j++){
	 		
	 		cout<<d[i][j]<<" ";
	 	}
	 	cout<<endl;
	 }
*/
	return 0;
}