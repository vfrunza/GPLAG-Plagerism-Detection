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
#include <cmath>

bool DaLiJeBrojProst( int broj ){
	if(broj==1 || broj==-1)	return false;
	for(int i=2; i<broj; i++){
		if(broj%i==0)	return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne( std::vector<int> v, bool x ){
	std::vector<int> konacni;
	//ukoliko je broj prost idi dalje
	if(x==true){
		for(int i=0; i<v.size(); i++){
			//provjeravamo da li su brojevi prosti
			if(DaLiJeBrojProst(v.at(i))==true){
				//pretvorimo ga u ternarni b.s. ali naopako (sto nema ne smeta)
				int pomocni;
				pomocni=abs(v.at(i));
				std::vector<int> pom(0);
				while(pomocni!=0){
					pom.push_back(pomocni%3);
					pomocni/=3;
				}
				//provjeravamo da li je pretvoreni broj simetrican
				bool jeste(true);
				for(int j=0; j<pom.size()/2; j++){
					if(pom.at(j)!=pom.at(pom.size()-1-j)){	
						jeste=false;
						break;
					}
				}
				//ukoliko je broj simetrican, isti stavljamo u vector konacni, koj ce na kraju biti vracen iz funkcije
				if(jeste){
					konacni.push_back(v.at(i));
				}
			}
		}
	}
	else {
		for(int i=0; i<v.size(); i++){
			//uzimamo samo one koji nisu prosti
			if(DaLiJeBrojProst(v.at(i))==false){
				//pretvaramo ga u ternarni b.s. al broj ce biti naopako napisan, sto nama nije od velikog znacaja
				int pomocni;
				pomocni=abs(v.at(i));
				std::vector<int> pom(0);
				while(pomocni!=0){
					pom.push_back(pomocni%3);
					pomocni/=3;
				}
				//provjeravamo da li je pretvoreni broj simetrican
				bool jeste(true);
				for(int j=0; j<pom.size(); j++){
					if(pom.at(j)!=pom.at(pom.size()-1-j)){
						jeste=false;
						break;
					}
				}
				//ukoliko je broj simetrican, umecemo ga u vektor konacni koji ce na kraju biti vracen iz ove funkcije
				if(jeste){
				konacni.push_back(v.at(i));
				}
			}
		}
	}
	//provjeri da li ima brojeva koji se ponavljaju, ako ima izbaci ih
	for(int i=0; i<konacni.size(); i++){
		for(int j=i+1; j<konacni.size(); j++){
			if(konacni.at(j)==konacni.at(i)){
				for(int k=j; k<konacni.size()-1; k++){
					konacni.at(k)=konacni.at(k+1);
				}
				konacni.resize(konacni.size()-1);
				j--;
			}
		}
	}
	return konacni;
}

int main ()
{
	int broj;
	std::vector<int> v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	while(std::cin>>broj, broj!=-1){
		v.push_back(broj);
	}
	int n;
	bool x;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(std::cin >> n, n!=1 && n!= 0){
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	if(n==1)
		x=true;
	else if(n==0)
		x=false;
	std::vector<int> konacni;
	konacni=IzdvojiSimetricneTernarne(v,x);
	if(x==true){
		if(konacni.size()==0){
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		else {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<konacni.size(); i++){
				if(i!=konacni.size()-1)	
					std::cout << konacni.at(i) << ", ";
				else 	
					std::cout << konacni.at(i) << ".";
			}
		}
	}
	 else if(x==false){
		if(konacni.size()==0){
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(int i=0; i<konacni.size(); i++){
				if(i!=konacni.size()-1)	
					std::cout << konacni.at(i) << ", ";
				else 	
					std::cout << konacni.at(i) << ".";
				}
		}
	}
	return 0;
}
	
	
	
	
	
	
	
/*	std::vector<int> v{191, 233, 43, 313, 13, 678, 151, 23, 727, 173, -1, 5};
	std::vector<int> d; std::vector<int> b;
	d=IzdvojiSimetricneTernarne(v,true);
	b=IzdvojiSimetricneTernarne(v,false);
	for(int i=0; i<d.size(); i++){
		std::cout << d.at(i) << " ";
	}
	std::cout<<std::endl;
	for(int i=0; i<b.size(); i++){
		std::cout << b.at(i) << " ";
	}*/
