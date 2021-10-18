#include <iostream>
#include <math.h>
#include <deque>
#include <vector>

using std::vector;
using std::deque;
using std::cin;
using std::cout;
using std::string;
using std::endl;

enum Smjer{Rastuci, Opadajuci};

double LogPoBazi2(int broj){
	return (log(broj)/log(2));
}

bool DaLiJeStepenDvojke(int broj){
	//zbog domena log
	if(broj == 0) return false;
	if(LogPoBazi2(broj) - int(LogPoBazi2(broj)) < 0.000000001) return true;
	else return false;
}

deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> V, enum Smjer S){
	deque<vector<int>> D;
	if(S == Rastuci){
		for(int i = 0; i < V.size() - 1; i++){
			vector<int> temp;
			while(i < (V.size() - 1) && V.at(i) <= V.at(i + 1) && DaLiJeStepenDvojke(V.at(i)) &&  DaLiJeStepenDvojke(V.at(i + 1))){
				temp.push_back(V.at(i));
				i++;
				if(i == V.size() - 1) break;
			}
			temp.push_back(V.at(i));
			if(temp.size() >= 2) D.push_back(temp);
		}
	}
	else{
		for(int i = 0; i < V.size() - 1; i++){
			vector<int> temp;
			while(i < (V.size() - 1) && V.at(i) >= V.at(i + 1) && DaLiJeStepenDvojke(V.at(i)) &&  DaLiJeStepenDvojke(V.at(i + 1))){
				temp.push_back(V.at(i));
				i++;
				if(i == V.size() - 1) break;
			}
			temp.push_back(V.at(i));
			if(temp.size() >= 2) D.push_back(temp);
		}
	}
	return D;
}
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<int> V(n);
	for(int i = 0; i < V.size(); i++){
		cin>>V.at(i);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int opcija(-1);
	if(opcija != -1) cin.ignore(100000000, '\n');
	cin>>opcija;
	enum Smjer o;
	if(opcija == 1) o = Rastuci;
	else o = Opadajuci;
	deque<vector<int>> D(MaksimalniPodnizoviStepenaDvojke(V, o));
	if(D.size() == 0){
			return 0;
	}
	else{
		if(o == Rastuci) cout<<"Maksimalni rastuci podnizovi: ";
		else cout<<"Maksimalni opadajuci podnizovi: ";
	}
	cout<<endl;
	for(auto red : D){
		for(auto x : red){
			cout<<x<<" ";
		}
	cout<<endl;
	}
	return 0;
}