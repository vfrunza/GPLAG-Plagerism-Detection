#include <iostream>
#include <vector>

std::vector<int> PrebaciUTernarni(int broj){
	std::vector<int> ternarni;
	while(broj!=0){
		ternarni.push_back(broj%3);
		broj/=3;
	}
	return ternarni;
}

bool DaLiJeOpak(int broj){
	std::vector<int> v = PrebaciUTernarni(broj);
	bool opak(true);
	int brojac (0);
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.size(); j++) if(v[i]==v[j]) brojac++;
		if(brojac%2!=0) opak=false;
		brojac=0;
		if(i==v.size()-1) break;
	}
	return opak;
}

bool DaLiJeOdvratan(int broj){
	std::vector<int> v = PrebaciUTernarni(broj);
	bool odvratan(true);
	int brojac (0);
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.size(); j++) if(v[i]==v[j]) brojac++;
		if(brojac%2==0) odvratan=false;
		brojac=0;
		if(i==v.size()-1) break;
	}
	return odvratan;
}

std::vector<int> IzbaciDuple(std::vector<int> v){
	std::vector<int> novi;
	if(v.size()>0) novi.push_back(v[0]);
	else return v;
	for(int i=1; i<v.size(); i++){
		bool ponavljanje(false);
		for(int j=0; j<novi.size(); j++){
			if(v[i]==novi[j]) {
				ponavljanje=true;
				break;
			}
		}
		if(ponavljanje) continue;
		else novi.push_back(v[i]);
	}
	return novi;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool opcija){
	std::vector<int> rez;
	if(opcija){
		for(int i=0; i<v.size(); i++) if(DaLiJeOpak(v[i])) rez.push_back(v[i]);
	}
	else{
		for(int i=0; i<v.size(); i++) if(DaLiJeOdvratan(v[i])) rez.push_back(v[i]);
	}
	rez = IzbaciDuple(rez);
	return rez;
}

int main ()
{
	std::vector<int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): " ;
	int a;
	do{
		std::cin >> a;
		v.push_back(a);
	}while(a!=0);
	v.pop_back();
	std::cout << "Opaki: ";
	std::vector<int> opaki = IzdvojiGadne(v,1);
	//opaki = IzbaciDuple(opaki);
	for(int i=0; i<opaki.size(); i++) std::cout << opaki[i] << " " ;
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	std::vector<int> odvratni = IzdvojiGadne(v,0);
	//odvratni = IzbaciDuple(odvratni);
	for(int i=0; i<odvratni.size(); i++) std::cout << odvratni[i] << " " ;
	return 0;
}