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
#include <cmath>

typedef std::deque<std::vector<int>> Dek_Vektora;
enum Smjer {Rastuci, Opadajuci};

bool Stepen_dvojke(int s){
	int i(1);
	if(i==s)
	return true;
	while(i<s)
	{
		i*=2;
		if(i==s)
		return true;
	}
	return false;
}

Dek_Vektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer a){
	Dek_Vektora b;
	int p(0);
	std::vector<int> v1;
	if(a==Rastuci){
		for(int i=0; i<v.size(); i++){
			p=i;
			while(p!=v.size()-1&&v.at(p)<=v.at(p+1)&&Stepen_dvojke(v.at(p))){	//v.size()-1 zbog v.at(p+1)
				v1.push_back(v.at(p));
				p++;
			}
			i=p;
			if(Stepen_dvojke(v.at(i)))
			v1.push_back(v.at(i));
			if(i==v.size()&&v.at(i)>=v.at(i-1)&&Stepen_dvojke(v.at(i)))
			v1.push_back(v.at(i));
			if(v1.size()>1)
			b.push_back(v1);
			v1.clear();
		}
	}
	else
	for(int i=0; i<v.size(); i++){
		p=i;
		while(p!=v.size()-1&&v.at(p)>=v.at(p+1)&&Stepen_dvojke(v.at(p))){
			v1.push_back(v.at(p));
			p++;
		}
		i=p;
		if(Stepen_dvojke(v.at(i)))
		v1.push_back(v.at(i));
		if(i==v.size()&&v.at(i)<v.at(i-1)&&Stepen_dvojke(v.at(i)))
		v1.push_back(v.at(i));
		if(v1.size()>1)
		b.push_back(v1);
		v1.clear();
	}
	return b;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n(0);
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v;
	int broj;
	for(int i=0; i<n; i++){
		std::cin>>broj;
		v.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int p(0);
	std::cin>>p;
	Smjer a;
	if(p==1)
	a=Rastuci;
	else
	a=Opadajuci;
	Dek_Vektora D=MaksimalniPodnizoviStepenaDvojke(v, a);
	if(p==1){
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(auto l:D){
			for(auto j:l){
				std::cout<<j<<" ";
			}
			std::cout<<std::endl;
		}
	}
	else{
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(auto z:D){
			for(auto k:z){
				std::cout<<k<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}