#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

typedef std::deque<std::vector<int>> Matrix;

enum Smjer {Rastuci=1,Opadajuci};

bool Stepenovanje(int broj)
{
	if(broj==1)return true;
	if(broj<=0)return false;
	int x(2);
	while(x<=broj) {
		if(x==broj)return true;
		x*=2;
	}
	return false;
}

Matrix MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,Smjer RiO)
{
	Matrix SpilVektora;
	int red(0);
	if(RiO==1) {
		for(int i=0; i<v.size(); i++) {
			if(i==v.size()-1)break;
			if(v.at(i)<=v.at(i+1) && Stepenovanje(v.at(i))) {
				SpilVektora.resize(red+1);
				while((i<v.size()-1 && v.at(i)<=v.at(i+1) && Stepenovanje(v.at(i)))) {
					SpilVektora.at(red).push_back(v.at(i));
					i++;
					if(i==v.size()-1 && Stepenovanje(v.at(i))) {
						if(v.at(i)>=v.at(i-1))SpilVektora.at(red).push_back(v.at(i));
						else break;
					} else if(i==v.size()-1) {
						SpilVektora.at(red).erase(SpilVektora.at(red).begin()+0);
						break;
					}
				}
				if(i==v.size()-1)break;
				if(SpilVektora.at(red).size()==1) {
					if(v.at(i)>v.at(i+1) && Stepenovanje(v.at(i))) {
						SpilVektora.at(red).push_back(v.at(i));
						red++;
					} else {
						SpilVektora.at(red).erase(SpilVektora.at(red).begin()+0);
						continue;
					}
				} else if (v.at(i)>v.at(i+1) && Stepenovanje(v.at(i))) {
					SpilVektora.at(red).push_back(v.at(i));
					red++;
				}
			}
		}
	} else if(RiO==2) {
		for(int i=v.size()-1; i>=0; i--) {
			if(i==0)break;
			if(v.at(i)<=v.at(i-1) && Stepenovanje(v.at(i))) {
				SpilVektora.resize(red+1);
				while((i>0 && v.at(i)<=v.at(i-1) && Stepenovanje(v.at(i)))) {
					SpilVektora.at(red).push_back(v.at(i));
					i--;
					if(i==0 && Stepenovanje(v.at(i))) {
						if(v.at(i)>=v.at(i+1))SpilVektora.at(red).push_back(v.at(i));
						else break;
					}else if(i==0) {
						SpilVektora.at(red).erase(SpilVektora.at(red).begin()+0);
						break;
					}
				}
				if(i==0)break;
				if(SpilVektora.at(red).size()==1) {
					if(v.at(i)>v.at(i-1) && Stepenovanje(v.at(i))) {
						SpilVektora.at(red).push_back(v.at(i));
						red++;
					} else {
						SpilVektora.at(red).erase(SpilVektora.at(red).begin()+0);
						continue;
					}
				} else if (v.at(i)>v.at(i-1) && Stepenovanje(v.at(i))) {
					SpilVektora.at(red).push_back(v.at(i));
					red++;
				}
			}
		}
	}
	return SpilVektora;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int broj;
	std::cin>>broj;
	int i(0);
	std::vector<int> vektor(broj);
	std::cout<<"Unesite elemente vektora: ";
	while(i<broj) {
		std::cin>>vektor.at(i);
		i++;
	}
	int s;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>s;
	Smjer way;
	way=Smjer(s);
	Matrix dekVektora;
	dekVektora=MaksimalniPodnizoviStepenaDvojke(vektor,way);
	if(dekVektora.size()==0 || dekVektora.at(0).size()==0)return 0;
	if(s==1) {
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(int i=0; i<dekVektora.size(); i++) {
			for(int j=0; j<dekVektora.at(i).size(); j++)
				std::cout<<dekVektora.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}
	} else if(s==2) {
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i=dekVektora.size()-1; i>=0; i--) {
			for(int j=dekVektora.at(i).size()-1; j>=0; j--)
				std::cout<<dekVektora.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}
	}
	return 0;
}