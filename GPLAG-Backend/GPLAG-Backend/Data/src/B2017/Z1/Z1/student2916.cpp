#include <iostream>
#include <vector>
#include <cmath>

bool Prosti(int znak){
	if(znak<=1) return false;
	for(int i=2; i<znak;i++)
	if(znak%i==0) return false;
	return true;
	if(znak<0) znak=znak*-1;
}
int Ternarni (int slovo) {
	int s=0;
	int b=1;
	while(slovo>0){
		s+=slovo%3*b;
		slovo=slovo/3;
		b*=10;
	}
	return s;
}
bool Simetricnost(int tacka){
	int kraj=0;
	int unikat=tacka;
	while(unikat>0){
		kraj*=10;
		kraj+=unikat%10;
		unikat=unikat/10;
	}
	return tacka==kraj;
}
std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>sto, bool m){
	std::vector<int>rezultat;
	for(int i=0;i<sto.size(); i++){
		if(Prosti(sto.at(i))==m && Simetricnost(Ternarni(sto.at(i))))
		rezultat.push_back(sto.at(i));
	}
	return rezultat;
}

int main(){
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int>sto;
	int z;
	for(;;){
	std::cin>>z;
	if(z==-1) break;
	sto.push_back(z);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int b;
	bool l;
	for(;;) {
		std::cin>>b;
		if(b!=1&& b!=0){
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			int n;
			std::cin>>n;
		}
		else l=b;
		break;
	}

std::vector<int>rezultat(0);
rezultat=IzdvojiSimetricneTernarne(sto,l);
if(l=b) {
	if(rezultat.size()==0){
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	else {
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<rezultat.size(); i++){
			if(i<rezultat.size()-1) std::cout<<rezultat.at(i)<<", ";
			else std::cout<<rezultat.at(i)<<".";
		}
	}
}
else {
	if(rezultat.size()==0){
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	else {
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<rezultat.size(); i++){
			if(i<rezultat.size()-1) std::cout<<rezultat.at(i)<<", ";
			else std::cout<<rezultat.at(i)<<".";
		}
	}
}
return 0;
}
