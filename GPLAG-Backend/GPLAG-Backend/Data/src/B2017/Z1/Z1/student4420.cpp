#include <iostream>
#include <vector>
#include <cmath>

	int DaLiJeProst(int n){
			n=fabs(n);
			if(n==0){
				return 0;
			}
			for(int i=2;i<=sqrt(n);i++){
			if(n%i==0) return 0;
			}
		return 1;
		}
		
	int PrebaciUTernarni(int n){
		int velicina1(0);
		int ternarni(0);
		while(n!=0){
			int t=n%3;
			n=n/3;
			ternarni=ternarni+ t*pow(10,velicina1);
			velicina1++;
			}
			return ternarni;}

	int BrCifTernarnog(int ternarni){
		int br1=ternarni;
		int cifre(0);
		while(br1!=0){
			cifre++;
			br1=br1/10;
		}
		return cifre;}
		
	int JelSimetrican(int ternarni, int cifre){
		int okrenut(0);
		int br2=ternarni;
		int velicina2=cifre;
		while(br2!=0){
			okrenut=okrenut+(br2%10)*pow(10,velicina2-1);
			br2=br2/10;
			velicina2--;
		}
		if(ternarni==okrenut){ return 1;}
		else{
			return 0;
		}
	}
	int PretvoriuDekadni(int ternarni){
		int pomocni=ternarni;
		int noviBr=0;
		int cif=0;
		while(pomocni!=0){
			noviBr+=(pomocni%10)*pow(3,cif);
			pomocni=pomocni/10;
			cif++;}
			
			return noviBr;}
	
	std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v1, bool JeLi){
			std::vector<int> nov_v;
			
	for(int i=0; i<v1.size();i++){
		if((DaLiJeProst(v1.at(i))==JeLi)){
			nov_v.push_back(v1.at(i));}}
			
	for(int i=0; i<nov_v.size();i++){
	nov_v.at(i)=PrebaciUTernarni(nov_v.at(i));}
	
	std::vector<int> nov_v2;
	for(int i=0; i<nov_v.size();i++){
	if(JelSimetrican(nov_v.at(i),BrCifTernarnog(nov_v.at(i)))==true){
		nov_v2.push_back(nov_v.at(i));
	}
	}
	
	for(int i=0;i<nov_v2.size();i++){
	nov_v2.at(i)=PretvoriuDekadni(nov_v2.at(i));}
	
	return nov_v2;}

int main(){
	int brojac(0);
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int n=0,a;
	while(n!=-1){
		std::cin>>n;
		v.push_back(n);}
		v.erase(v.begin()+v.size()-1);
		
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
		if(v.at(i)==v.at(j)){
			brojac++;
		}
		if(brojac>1){
			v.erase(v.begin()+j);
		}
		}
	brojac=0;
		}	
		
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	
	std::cin>>a;
	
	while(a!=0 && a!=1){
	std::cin>>a;
	std::cout<<"Neispravan unos! Unesite ponovo: ";}
	
	
	
	std::vector<int> vektor;
	
	vektor=IzdvojiSimetricneTernarne(v,a);

	if(a==1){
		if(vektor.size()==0){
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<vektor.size();i++){
			if(i!=vektor.size()-1){
			std::cout<<vektor.at(i)<<", ";}
			else{
				std::cout<<vektor.at(i)<<".";}
		}
	}

	if(a==0){
		if(vektor.size()==0){
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<vektor.size();i++){
			if(i!=vektor.size()-1){
				std::cout<<vektor.at(i)<<", ";}
			else{
				std::cout<<vektor.at(i)<<".";}
			}
}
		
	return 0;
}






