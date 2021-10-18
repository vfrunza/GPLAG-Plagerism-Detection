#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci, Opadajuci};

bool StepenBrojaDva(int a)
{
	if(a<=0) return false;
	int i(1);
	while(i<a) {
		i=i*2;
		
	}
	if(a==i) return true;
	return false;
}

std::vector<int> RastuciPodniz(std::vector<int>d, int a)
{
	std::vector<int> novi;
	int i(a);

	while((i+1)<d.size() && d.at(i)<=d.at(i+1) && StepenBrojaDva(d.at(i))) {
		novi.push_back(d.at(i));
		i++;
	}

	if(novi.size()>=1 && i<d.size() && StepenBrojaDva(d.at(i))) novi.push_back(d.at(i));
	return novi;
}

std:: vector<int> OpadajuciPodniz(std::vector<int>d, int a)
{
	std::vector<int> novi;
	int i(a);
	while((i+1)<d.size() && d.at(i)>=d.at(i+1) && StepenBrojaDva(d.at(i))) {
		novi.push_back(d.at(i));
		i++;
	}

	if(novi.size()>=1 && i<d.size() && StepenBrojaDva(d.at(i))) novi.push_back(d.at(i));
	return novi;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int>d, Smjer x)
{

	std::deque<std::vector<int>> dek;
	if(d.size()){
	for(int i=0; i<d.size()-1; i++) {
		std::vector<int> novi;
		if(x==Rastuci) novi=RastuciPodniz(d,i);
		else if(x==Opadajuci) novi=OpadajuciPodniz(d,i);
		if(novi.size()>1) {
			dek.push_back(novi);
			i=i+novi.size()-1;
		}

	}}

	return dek;


}

int main ()
{
	int a,broj_elemenata;
	std::vector<int>d;
	std::deque<std::vector<int>> dek;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_elemenata;
	
	std::cout<<"Unesite elemente vektora: ";
	int i(0);
	while(i<broj_elemenata){
		std::cin>>a;
		d.push_back(a);
		i++;

	} 

	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";

		std::cin>>a;
	
	
	if(a==1) {
		dek=MaksimalniPodnizoviStepenaDvojke(d,Rastuci);
		
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	
		for(std::vector<int> a: dek) {
			for(int s: a) std::cout<<s<<" ";
			std::cout<<std::endl;
		}
		
	
		
	} else if(a==2) {
		dek=MaksimalniPodnizoviStepenaDvojke(d,Opadajuci);
		
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	
		for(std::vector<int> a: dek) {
			for(int s: a) std::cout<<s<<" ";
			std::cout<<std::endl;
		}
	}


	return 0;
}