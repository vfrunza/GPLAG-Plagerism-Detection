#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci,Opadajuci};

bool StepenDvojke(int n)
{
	if (n == 0)
		return false;
	while (n != 1) {
		if (n%2 != 0)
			return false;
		n = n/2;
	}
	return true;
}

std::deque<std::vector<int>> OpadajuciPodnizovi(std::vector<int>v)
{
	std::deque<std::vector<int>> dv;
	bool x(true);
	int l(0);
	for(int i=0; i<v.size()-1; i++) {
		if(v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
			if(x==true) {
				dv.push_back(std::vector<int>(0));
				x=false;
			}
			dv.at(l).push_back(v.at(i));
			if(i==v.size()-2 && v.at(i)>=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
				dv.at(l).push_back(v.at(i+1));
				break;
			}
		} else if(x==false) {
			x=true;
			dv.at(l).push_back(v.at(i));
			l++;
		}
	}
	return dv;
}

std::deque<std::vector<int>> RastuciPodnizovi(std::vector<int>v)
{
	std::deque<std::vector<int>> dv;
	bool x(true);
	int l(0);
	for(int i=0; i<v.size()-1; i++) {
		if(v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
			if(x==true) {
				dv.push_back(std::vector<int>(0));
				x=false;
			}
			dv.at(l).push_back(v.at(i));
			if(i==v.size()-2 && v.at(i)<=v.at(i+1) && StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1))) {
				dv.at(l).push_back(v.at(i+1));
				break;
			}
		} else if(x==false) {
			x=true;
			dv.at(l).push_back(v.at(i));
			l++;
		}
	}
	return dv;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s)
{
	std::deque<std::vector<int>> dv;
	if(s==Opadajuci) {
		dv=OpadajuciPodnizovi(v);
	} else {
		dv=RastuciPodnizovi(v);
	}
	return dv;
}

int main ()
{
	int n,x,y;
	std::vector<int> v;
	std::deque<std::vector<int>>dv;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>x;
		v.push_back(x);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>y;
	if(y==1) {
		dv=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(int i=0; i<dv.size(); i++) {
			for(int j=0; j<dv.at(i).size(); j++) {
				std::cout<<dv.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	} else if(y==2) {
		dv=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i=0; i<dv.size(); i++) {
			for(int j=0; j<dv.at(i).size(); j++) {
				std::cout<<dv.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}