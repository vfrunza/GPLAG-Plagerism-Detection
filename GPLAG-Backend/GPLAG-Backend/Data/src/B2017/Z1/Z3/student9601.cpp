#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

enum Smjer{Rastuci=1,Opadajuci=2};

bool StepenDvojke(int broj){
	for(int i(0);;i++){
		int x=pow(2,i);
		if(broj==x)
			return true;
		else if(x>broj)
			return false;
	}
	return false;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer x){
	std::deque<std::vector<int>> dek;
	std::vector<int> v2;
	int brojac(0);
	if(x==1){
	for(int i(1);i<v.size();i++){
		if((StepenDvojke(v.at(i-1))&&StepenDvojke(v.at(i)))&&v.at(i-1)<=v.at(i)){
			int broj(v.at(i));
			if(brojac==0)
				v2.push_back(v.at(i-1));
			v2.push_back(broj);
			brojac++;
			if(i==v.size()-1&&v2.size()!=0)
				dek.push_back(v2);
		}
		else{
			if(v2.size()!=0)
				dek.push_back(v2);
			brojac=0;
			v2.resize(0);
		}
	}
	return dek;
	}
    else if(x==2){
	for(int i(1);i<v.size();i++){
		if((StepenDvojke(v.at(i-1))&&StepenDvojke(v.at(i)))&&v.at(i-1)>=v.at(i)){
			int broj(v.at(i));
			if(brojac==0)
				v2.push_back(v.at(i-1));
			v2.push_back(broj);
			brojac++;
			if(i==v.size()-1&&v2.size()!=0)
				dek.push_back(v2);
		}
		else{
			if(v2.size()!=0)
				dek.push_back(v2);
			brojac=0;
			v2.resize(0);
		}
	}
	return dek;
	}
	return dek;
}
int main ()
{
	std::deque<std::vector<int>> D;
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<v.size();i++)
		std::cin>>v.at(i);
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int x;
	std::cin>>x;
	
	if(x==1)
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	else
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	D=MaksimalniPodnizoviStepenaDvojke(v,Smjer(x));
	for(int i(0);i<D.size();i++){
		for(int j(0);j<D.at(i).size();j++){
			if(j==0)
				std::cout<<D.at(i).at(j);
			else
				std::cout<<" "<<D.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	return 0;
}