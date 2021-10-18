#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>
//true- opaki brojevi, paran broj jedinica
typedef std::vector<int> IntVektor;

IntVektor IzdvojiGadne (IntVektor v, bool a)  					//Trazena funkcija
{
	IntVektor rezultat(0,0);
	IntVektor pomocni;
	
	if(v.size()==0) return rezultat;

	//for(int i=0; i<v.size()-1; i++) {//Brisanje duplih
	for(int i=v.size()-2; i>0; i++) {
		for(int j=i+1; j<v.size(); j++) {
			if(v.at(i)==v.at(j)) {
				v.erase(v.begin()+j);
				j--;
			}
		}
	}

	for(int x: v ) {												//Prolazim kroz elemente poslanog vektora v
		int ostatak(0), brojac1(0), brojac2(0), brojac0(0);
		long long int broj(x);
		pomocni.resize(0);

		while(broj!=0) {											//Tenarna reprezentacija broja, zapisana u vektoru pomocni
			ostatak=abs(broj%3);
			pomocni.push_back(ostatak);
			broj/=3;
		}

		for(int i=0; i<pomocni.size(); i++) {
			if(pomocni.at(i)==1) brojac1++;
			else if(pomocni.at(i)==2) brojac2++;
			else if(pomocni.at(i)==0) brojac0++;
		}

		if(a && (brojac0%2==0 || brojac0==0) && (brojac1%2==0 || brojac1==0) && (brojac2%2==0 || brojac2==0)) rezultat.push_back(x);
		else if(!a && (brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0)) rezultat.push_back(x);
	}
	return rezultat;
}

int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	IntVektor UneseniVektor;
	int broj;
	

	while(std::cin>>broj, broj!=0) { 								//Unos vektora
		UneseniVektor.push_back(broj);
	}
	
	auto OpakiBrojevi=IzdvojiGadne(UneseniVektor, true); 			//Ispis vektora sa opakim brojevima
	std::cout<<"Opaki: ";
	for(int x:OpakiBrojevi) std::cout<<x<<" ";
	auto OdvratniBrojevi=IzdvojiGadne(UneseniVektor, false);		//Ispis vektora sa odvratnim brojevima
	std::cout<<"\nOdvratni: ";
	for(int x: OdvratniBrojevi ) std::cout<<x<<" ";
	return 0;
}