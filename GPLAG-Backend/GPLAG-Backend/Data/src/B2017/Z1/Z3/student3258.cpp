#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;


enum Smjer{Opadajuci, Rastuci};

bool DaLiJeStepenDvojke(int broj){
	if(broj<=0)return false;
	if(broj==1 || broj==2) return true;
	while(broj!=0){
		broj/=2;
		if(broj==1) return true;
		if(broj%2!=0) return false;
	}
	return true;
}



deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v, Smjer smjer){
	deque<vector<int>> podnizovi;
	Smjer testna=Opadajuci;
	vector<int> podniz;
	int brojac=0;
	if(v.empty()) return podnizovi;
	if(smjer==Rastuci){
		for(int i=0; i<v.size()-1; i++){
			bool temp=false;
			temp=DaLiJeStepenDvojke(v.at(i));
			if(temp){
				brojac++;
				podniz.push_back(v.at(i));
				if(v.at(i)<v.at(i+1)) continue;
				else{
					if(brojac<2){
						podniz.resize(0);
						brojac=0;
					}
					else{
						podnizovi.push_back(podniz);
						podniz.resize(0);
						brojac=0;
					}
				}
			}
		}	
	}
	if(smjer==Opadajuci){
		for(int i=0; i<v.size(); i++){
			bool temp=false;
			temp=DaLiJeStepenDvojke(v.at(i));
			if(temp){
				if(i==v.size()-1){
					if(v.at(i-1)>v.at(i)){
						podniz.push_back(v.at(i));
						podnizovi.push_back(podniz);
					} 
					else continue;
				}
				else{
				brojac++;
				podniz.push_back(v.at(i));
				if(v.at(i)>v.at(i+1)) continue;
				else{
					if(brojac<2){
						podniz.resize(0);
						brojac=0;
					}
					else{
						podnizovi.push_back(podniz);
						podniz.resize(0);
						brojac=0;
					}
				}
				}
			}
			else{
				if(brojac<2){
						podniz.resize(0);
						brojac=0;
					}
					else{
						podnizovi.push_back(podniz);
						podniz.resize(0);
						brojac=0;
					}
			}
		}	
	}
	
	return podnizovi;
}



int main (){
	cout<<"Unesite broj elemenata vektora: ";
	int br_elem;
	cin>>br_elem;
	cout<<"Unesite elemente vektora: ";
	vector<int> vektor;
	int temp;
	for(int i=0; i<br_elem; i++){
		cin>>temp;
		vektor.push_back(temp);
	}

	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	
	cin>>temp;
	Smjer tmp=Opadajuci;
	if(temp==2) tmp=Opadajuci;
	if(temp==1) tmp=Rastuci;
	auto dek=MaksimalniPodnizoviStepenaDvojke(vektor, tmp);
	if(tmp==Rastuci){ cout<<"Maksimalni rastuci podnizovi: "<<endl;
		for(auto x : dek){
			for(auto y : x) cout<<y<<" ";
			cout<<endl;
		}
	}

		if(tmp==Opadajuci){ cout<<"Maksimalni opadajuci podnizovi: "<<endl;
		for(auto x : dek){
			for(auto y : x) cout<<y<<" ";
			cout<<endl;
		}
	}

	
	return 0;
}