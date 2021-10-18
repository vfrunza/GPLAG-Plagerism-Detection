#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

double Korijen (int x) {
	return (sqrt(x));
}
bool StepenDvojke(int x) {
	if(sqrt(x)==int (Korijen(x))) return true;
	return false;
}
std::deque <std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, smjer s) {
	
	std::vector<int> v2;
	std::deque<std::vector<int>> d;
	if(s==1) {
	for(int i=0;i<v.size()-1;i++) {
		if(v.at(i)<v.at(i+1) && StepenDvojke(v.at(i))==1) {
			v2.push_back(v.at(i));
		}
		d.push_back(v2);
	}
	return d;
}
  else {
  	for(int i=v.size()-1;i>=0;i--) {
  		if(v.at(i)>v.at(i-1) && StepenDvojke(v.at(i)==1)) {
  			v2.push_back(v.at(i));
  		}
  		d.push_back(v2);
  	}
  }
  return d;

}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i=0;i<n;i++) {
		int x;
		std::cin>>x;
		v.push_back(x);
	}
	enum smjer {rastuci=1, opadajuci};
	int x;
	smjer s;
	std::cout<<"Unesite smjer: ";
	std::cin>>s;
	
	std::deque<std::vector<int>> d=MaksimalniPodnizoviStepenaDvojke(v,s);
	for(int i=0;i<d.size();i++) {
		std::cout<<d.at(i)<<std::endl;
	}
	return 0;
}