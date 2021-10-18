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
#include <iomanip>
#include <cmath>
#define epsilon 0.000000001
using namespace std;

enum Smjer{Rastuci, Opadajuci};

deque<vector<int>> KreirajMatricu (int red, int kolona){
	return deque<vector<int>>(red, vector<int>(kolona));
}

bool Stepen(int broj){
	
		if(log(broj)/log(2)-int(log(broj)/log(2))<epsilon)return true;
	
	return false;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int>v, enum Smjer p){
	deque<vector<int>> rezultat=KreirajMatricu(0,0);
	
	if(v.size()<=1)return rezultat;
	
	if(p==Rastuci){
		for(int i=0; i<v.size();i++){
			
			if(!Stepen(v.at(i))) continue;
			
			int pocetak=i;
			if(i==v.size()-1)break;
		
			while(i!=v.size()-1 and v.at(i)<=v.at(i+1) and Stepen(v.at(i+1)) and v.at(i)!=0){
				if(i+1==v.size()-1){
					i++;
					break;
				}
				i++;
			}
			
			int kraj=i;
			
			if(kraj==pocetak)continue;
			vector<int>temp;
			
			
			int NemojSeKrahirat=pocetak;
			
			for(int j=0;j<kraj-pocetak+1;j++){
				temp.push_back(v.at(NemojSeKrahirat));
				NemojSeKrahirat++;
				if(NemojSeKrahirat>kraj)break;
			}
			rezultat.push_back(temp);
			
		}
	}else{
			for(int i=0; i<v.size();i++){
			
			if(!Stepen(v.at(i))) continue;
		   
			int pocetak=i;
			if(i==v.size()-1)break;
			
			while(i!=v.size()-1 and v.at(i)>=v.at(i+1) and Stepen(v.at(i+1)) and v.at(i+1)!= 0){
				if(i+1==v.size()-1){
					i++;
					break;
				}
				i++;
			}
			
			int kraj=i;
			
			if(kraj==pocetak)continue;
			vector<int>temp;
			
			
			int NemojSeKrahirat=pocetak;
			
			for(int j=0;j<kraj-pocetak+1;j++){
				temp.push_back(v.at(NemojSeKrahirat));
				NemojSeKrahirat++;
				if(NemojSeKrahirat>kraj)break;
			}
				rezultat.push_back(temp);
			
			
		}
		
	}
	
	return rezultat;
}
int main (){
	vector<int>v;
	int b;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>b;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<b; i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	int s;
	
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	cin>>s;
	Smjer sm;
	if(s==1){
		sm=Rastuci;
		cout<<"Maksimalni rastuci podnizovi: "<<endl;
	}
	else if(s==2){
		sm=Opadajuci;
		cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	}
	
	deque<vector<int>> rez=MaksimalniPodnizoviStepenaDvojke(v,sm);
	for(vector<int> x: rez){
		for(int y: x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	return 0;
}