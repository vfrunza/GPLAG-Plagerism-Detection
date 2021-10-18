//B 2017/2018, Zadaća 1, Zadatak 3
#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci=1,Opadajuci=0};

bool StepenDvojke(int br){
	for(int i=1; i<=br; i*=2){
		if(br==i) return true;
	}
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer uvjet ){
	std::deque<std::vector<int>> deq;
	if(v.size()==0) return deq;
	int k(0);
	int *p(&v.at(0));
	int *q(&v.at(v.size()-1));
	if(uvjet){
		while(p<=q){
			while(p<=q && !(StepenDvojke(*p))) p++;
			int *tmp(p+1);
			int brojac(1);
			while(tmp<=q && *(tmp-1)<=*tmp && StepenDvojke(*tmp)) {
				tmp++;
				brojac++;
			}
			if(brojac>=2){
				deq.resize(k+1);
				while(p<tmp){
					deq.at(k).push_back(*p);
					p++;
				}
				k++;
				p=p-1;
			}
			p++;
		}
	}
	else {
		while(p<=q){
			while(p<=q && !(StepenDvojke(*p))) p++;
			int *tmp(p+1);
			int brojac(1);
			while(tmp<=q && *(tmp-1)>=*tmp && StepenDvojke(*tmp)) {
				tmp++;
				brojac++;
			}
			if(brojac>=2){
				deq.resize(k+1);
				while(p<tmp){
					deq.at(k).push_back(*p);
					p++;
				}
				k++;
				p=p-1;
			}
			p++;
		}
	}
	return deq;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int vel;
	std::cin>>vel;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v(vel);
	for(int i=0; i<vel; i++){
		int br;
		std::cin>>br;
		v.at(i)=br;
	}
	
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int uvjet;
	std::cin>>uvjet;
	
	if(uvjet==1){
		std::deque<std::vector<int>> rez(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		if(rez.size()==0){
			std::cout<<"Nema rastucih podnizova.";
			return 0;
		}
		else {
			std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
			for(auto x : rez){
				for(auto n : x){
					std::cout<<n<<" ";
				}	
				std::cout<<std::endl;
			}
		}
	}
	else if(uvjet==2){
		std::deque<std::vector<int>> rez(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		if(rez.size()==0){
			std::cout<<"Nema opadajucih podnizova.";
			return 0;
		}
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(auto x : rez){
			for(auto n : x){
				std::cout<<n<<" ";
			}
			std::cout<<std::endl;
		}
	}
	
	return 0;
}