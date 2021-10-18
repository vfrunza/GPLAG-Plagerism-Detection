
/* Kopirani su samo neki ispisi recenica iz autotestova ili iz maina, koji moraju biti isti kao u autotestovima da bi radili, u slucaju da bude sumnje u prepisanost! */

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;



bool jeLiProst(long broj){
	/*if(broj<0) broj*=-1;
	if(broj==1) return false;*/
	if(broj<=1) broj=abs(broj);		
	
	for(int i=2; i<=sqrt(broj); i++){						
		if(broj%i==0) return false;
	}
	return true;
}

bool simetricanTernarno(long broj){
	
	//Pretvorimo prvo u ternarni (naopako) i zapisimo u dek
	deque<int> ternarni;
	if(broj<0) broj*=-1;
	while(broj>0){
		ternarni.push_front(broj%3);
		broj/=3;
	}
	
	//Provjeramao simetricnost tako sto provjerimo prvi i zadnji, drugi i predzadnji itd. sve do sredine 
	for(int i=0; i<=ternarni.size()/2; i++){
		if(ternarni.at(i)!=ternarni.at(ternarni.size()-1-i))
			return false;
	}
	return true;
}

bool imaBrojUVektoru(std::vector<int> vektor, int broj){
	for(int nu:vektor){
		if(nu==broj) return true;
	}
	return false;
}


vector<int> IzdvojiSimetricneTernarne(vector<int> brojevi, bool proste){
	vector<int> rezultujuci;
	
	//Izdvajamo sve ili proste ili slozene ( ovisno od parametra 'proste' ) onim redoslijedom kako su dati u vektor-parametru
	
	for(int i=0; i<brojevi.size(); i++){
		if(jeLiProst(brojevi.at(i))==proste && simetricanTernarno(brojevi.at(i))){
			//Ne trebamo vise puta ubacivati isti broj, tako da ovdje provjerimo je li se vec nalazi u vektoru
			if(!imaBrojUVektoru(rezultujuci,brojevi.at(i)))
				rezultujuci.push_back(brojevi.at(i));
		}
	}
	return rezultujuci;
}



int main ()
{
	//Unesite elemente vektora (-1 za kraj): Unesite: 1 - za proste brojeve, 0 - za slozene brojeve:
	cout<<"Unesite elemente vektora (-1 za kraj): ";
	
	vector<int> testni;
	int broj;
	//Unos vektora do -1
	do{
		cin>>broj;
		if(broj!=-1) testni.push_back(broj);
		
	}while(broj!=-1);
	
	cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int logicka;
	
	do{
		cin>>logicka;
		if(logicka!= 1 && logicka !=0) cout<<"Neispravan unos! Unesite ponovo: ";
	}while(logicka!= 1 && logicka !=0);
	
	
	auto rezultujuci(IzdvojiSimetricneTernarne(testni,logicka));
	
	//Ispis prije brojeva
	if(rezultujuci.size()>0){
		if(logicka)
			cout<<"Prosti simetricni brojevi iz vektora su: ";
		else{
			cout<<"Slozeni simetricni brojevi iz vektora su: ";
		}
	}
	else{
		if(logicka)	
			cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
			cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		
	}
		
	
	for(int i=0; i<rezultujuci.size(); i++){
		cout<<rezultujuci.at(i);
		if(i==int(rezultujuci.size())-1) cout<<".";
		else cout<<", ";
	}
	return 0;
}