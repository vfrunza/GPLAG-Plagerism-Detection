#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cmath>

template <typename Itertip1, typename Itertip2, typename Itertip3>
void SortirajPodrucjeVrijednosti (Itertip1 pp, Itertip1 pk, Itertip2 p2, Itertip3 p3, decltype(*p3+*p3)f(decltype(*pp+*pp), decltype(*pp+*pp)), bool fun(decltype(*pp+*pp), decltype(*pp+*pp))){
	int velicina=pk-pp;
	std::sort(pp, pk, fun);
	std::sort(p2, p2+velicina, fun);
	

	auto pocetak1=pp;
	auto pocetak2=p2;
	
	while(pp!=pk){
		auto vrijednost=f(*pp, *p2);
		bool logicka(false);
		
		auto q=p3;
		for(int i=0; i<velicina; i++){
			if(*q==vrijednost) {logicka=true;  break;}
			q++;
		}
		if(logicka==false)throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		pp++;
		p2++;
	
	}
	pp=pocetak1;
	p2=pocetak2;

	for(int i=0; i<velicina; i++){
		*p3=f(*pp, *p2);
		pp++;
		p2++;
		p3++;
	}
}

int ProstiFaktori(int broj)
{
	
	int brojac(0);
	int j(2);
	broj=std::abs(broj);
	if(broj==0 || broj==1)return 1;
	while(broj!=1) {
		if(broj%j==0) {
			brojac++;
			broj=broj/j;
		} else j++;
	}
	return brojac;
}

int f(int x, int y){
	return -2*x+y;
}
 bool g(int x, int y){
 	if (ProstiFaktori(x)==ProstiFaktori(y)) return x>y;
 	else return ProstiFaktori(x)>ProstiFaktori(y);
 }
int main ()
{
	int broj_elemenata;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>broj_elemenata;
	int broj;
	std::vector<int> v1(0);
	std::vector<int> v2(0);
	std::vector<int> v3(0);
	bool logicka(true);
	
	std::cout<<"Unesite elemente prvog vektora: ";
	for(int i=0; i<broj_elemenata; i++) {
		std::cin>>broj;

logicka=true;
		for(int j=0; j<v1.size(); j++){
			if(broj==v1.at(j)) {logicka=false; i--; break;};
		}
		if(logicka) v1.push_back(broj);
	}
	logicka=true;
	std::cout<<"Unesite elemente drugog vektora: ";
	for(int i=0; i<broj_elemenata; i++) {
		std::cin>>broj;
		logicka=true;
		for(int j=0; j<v2.size(); j++){
			if(broj==v2.at(j)){logicka=false; i--; break;}
		}
		if(logicka) v2.push_back(broj);
	}
	
	
	std::cout<<"Unesite elemente treceg vektora: ";
	for(int i=0; i<broj_elemenata; i++) {
		std::cin>>broj;
		logicka=true;
		for(int j=0; j<v3.size(); j++){
			if(broj==v3.at(j)) {logicka=false; i--; break;}
		}
		if(logicka) v3.push_back(broj);
	}
	
	std::cout<<std::endl;
	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), f, g);
		std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
	 for(int i=0; i<broj_elemenata; i++) {
	 	std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;
	 }
	}
	 
	 catch(std::logic_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	return 0;
}