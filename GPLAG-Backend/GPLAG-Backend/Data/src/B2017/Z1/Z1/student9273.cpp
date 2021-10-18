/*B 2017/2018, Zadaća 1, Zadatak 1
	
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

bool DaLiJeProst(int broj){
	
	if(broj<0) broj*=-1;
	
if(broj==0 || broj==1) return false;

	for(int i=2;i<broj;i++){
		if(broj%i==0) return false;
	}
return true;	
}

int PretvoriUTernarni(int broj){
	if(broj<0) broj*=-1;
	std::vector<int> brojevi;	
	while(broj!=0){
		brojevi.push_back(broj%3);
		broj/=3;
	}
	int pretvoreni(0);
	
	for (int i=brojevi.size();i>0;i--){
		pretvoreni=pretvoreni*10+brojevi.at(i-1);
		
	}
return pretvoreni;	
}

bool JeLiSimetrican(int broj){
	std::vector<int> obrnuti;
	std::vector<int>normalni;
	while (broj!=0) {
		obrnuti.push_back(broj%10);
		broj/=10;
	}
	for(int i=obrnuti.size()-1;i>=0;i--){
		normalni.push_back(obrnuti.at(i));
	}
	if (normalni==obrnuti) return true;
return false;
}

bool DaLiJePrisutan(int broj, std::vector<int>poslani){
	if(poslani.size()!=0){
		for (int i = 0; i <=poslani.size()-1; i++) {
			if(broj==poslani.at(i)) return true;
		}
	}	
return false;	
}

std::vector<int> IzbaciDuple(std::vector<int> testni){
	std::vector<int>bez_duplih;
	for (int i = 0; i<=testni.size()-1; i++) {
		if(!DaLiJePrisutan(testni.at(i),bez_duplih)) {
			bez_duplih.push_back(testni.at(i));
		}
	}
return bez_duplih;
}

std::vector<int> IzbaciProste(std::vector<int>poslani){
	std::vector<int>bez_prostih ;
	for (int i = 0; i<=poslani.size()-1; i++) {
		if(!DaLiJeProst(poslani.at(i))) bez_prostih.push_back(poslani.at(i));
	}
return bez_prostih;
}

std::vector<int> IzbaciSlozene(std::vector<int> poslani){
	std::vector<int>bez_slozenih;
	for (int i = 0;i<=poslani.size()-1; i++) {
		if(DaLiJeProst(poslani.at(i))) bez_slozenih.push_back(poslani.at(i));
	}
return bez_slozenih;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> poslani, bool opcija){
	std::vector<int>bez_duplih ;
	std::vector<int>ternarni;
	std::vector<int>finalni ;
	
	if(poslani.size()==0) return finalni;
	
	bez_duplih=IzbaciDuple(poslani);
	if(opcija==1) bez_duplih=IzbaciSlozene(bez_duplih);
	else bez_duplih=IzbaciProste(bez_duplih);
	
	for(int i=0;i<bez_duplih.size();i++){
		ternarni.push_back(PretvoriUTernarni(bez_duplih.at(i)));
	}
	
	for(int i=0;i<ternarni.size();i++){
		if(JeLiSimetrican(ternarni.at(i))){
			finalni.push_back(bez_duplih.at(i));
		}
	}
	
return finalni;
}

int main ()
{
	std::vector<int> uneseni ;
	int opcija;
	int broj;
	std::vector<int>ternarni_simetricni;
	std::cout << "Unesite elemente vektora (-1 za kraj): " ;
	do{
		std::cin >> broj;
		if(broj==-1)break;
		uneseni.push_back(broj);
	}while(broj!=-1);
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
		std::cin >> opcija;
		while (opcija!=1 && opcija!=0) {
			std::cout << "Neispravan unos! Unesite ponovo: " ;
			std::cin >> opcija;
		}
		
	
	ternarni_simetricni=IzdvojiSimetricneTernarne(uneseni,opcija);
	
	if(opcija == 1 && ternarni_simetricni.size()!=0) std::cout << "Prosti simetricni brojevi iz vektora su: ";
	else if(opcija == 1 && ternarni_simetricni.size()==0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else if(opcija == 0 && ternarni_simetricni.size()!=0) std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	else if(opcija == 0 && ternarni_simetricni.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	if(ternarni_simetricni.size()!=0){
		for (int i = 0; i <= ternarni_simetricni.size()-1; i++) {
			
			std::cout << ternarni_simetricni.at(i);
			if(i!=ternarni_simetricni.size()-1)std::cout << ", ";
			else std::cout << ".";
		}
	}
	

	return 0;
}