#include <iostream>
#include <vector>
typedef std::vector<int> vektor;
bool ProstBroj(int broj){
	int brojac(0);
	if(broj==1) return false;
	else{
		for(int i=1; i<=abs(broj); i++){
			if(abs(broj)%i==0) brojac++;
		}
		if(brojac==2) return true;
		else return false;
	}
}
int PretvoriUTernarni(int broj){
	int k(1);
	int ternarni(0);
	do{
		int temp=broj;
		broj=broj/3;
		int ostatak=temp-broj*3;
		ternarni=ternarni+ostatak*k;
		k=k*10;
	}while(broj>0);
	return ternarni;
}
int ObrniCifre(int x){
		int obrnut(0);
		do{
			int temp=x;
			x=x/10;
			int ostatak=temp-x*10;
			obrnut=obrnut*10+ostatak;
		}while(x>0);
	return obrnut;
}
vektor IzdvojiSimetricneTernarne(vektor Brojevi, bool prost){
	vektor Prosti;
	for(int i=0; i<Brojevi.size(); i++){
		if(ProstBroj(Brojevi.at(i))==prost) Prosti.push_back(Brojevi.at(i));
	}
	vektor Ternarni;
	for(int i=0; i<Prosti.size(); i++){
		Ternarni.push_back(PretvoriUTernarni(Prosti.at(i)));
	}
	vektor Obrnuti;
	for(int i=0; i<Ternarni.size(); i++){
		int a=ObrniCifre(Ternarni.at(i));
		Obrnuti.push_back(a);
	}
	vektor Simetricni;
	for(int i=0; i<Ternarni.size(); i++){
		if(abs(Ternarni.at(i))==abs(Obrnuti.at(i))) Simetricni.push_back(Prosti.at(i));
	}
	vektor Pomocni;
	if(Simetricni.size()!=0){
	Pomocni.push_back(Simetricni.at(0));
	for(int i=1; i<Simetricni.size(); i++){
		for(int j=0; j<Pomocni.size(); j++){
			if(Simetricni.at(i)==Pomocni.at(j)) break;
			else{
				if(j==Pomocni.size()-1) Pomocni.push_back(Simetricni.at(i));
			}
		}
	}
	}
	return Pomocni;
}
int main ()
{
	vektor vektor1;
	int n;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		std::cin>>n;
		if(n!=-1) vektor1.push_back(n);
	}while(n!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int a;
	do{
		std::cin>>a;
		if(a!=0 && a!=1) std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while(a!=0 && a!=1);
	vektor1=IzdvojiSimetricneTernarne(vektor1, a);
	if(a==1){
		if(vektor1.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	}
	else{
		if(vektor1.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
	for(int i=0; i<vektor1.size(); i++){
		if(i<(vektor1.size()-1)) std::cout<<vektor1.at(i)<<", ";
		else std::cout<<vektor1.at(i)<<".";
	} 
	return 0;
}