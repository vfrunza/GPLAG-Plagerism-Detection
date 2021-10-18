/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <deque>

bool JelNeparan(std::deque<int> broj){
	std::vector<int>pomocni(3);
	for(int i=0; i<broj.size(); i++){
		pomocni[broj[i]]++;
	}
	for(int i=0; i<3; i++){
		if(pomocni[i]!=0 && pomocni[i] % 2 == 0) return false;
		
	}
	return true;
}
bool JelParan(std::deque<int> broj){
	std::vector<int>pomocni(3);
	for(int i=0; i<broj.size(); i++){
		pomocni[broj[i]]++;
	}
	for(int i=0; i<3; i++){
		if(pomocni[i]!=0 && pomocni[i] % 2!=0) return false;
	}
	return true;
}
std::deque<int>Ternarni(int broj){
	std::deque<int>ternarni;
	if(broj==0){
		ternarni.push_front(0);
		return ternarni;
	}
	if(broj<0) broj*=-1;
	while(broj>0){
		ternarni.push_front(broj%3);
		broj/=3;
	}
	return ternarni;
}
std::vector<int> SrediVektor(std::vector<int>v){
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<=v.size()-1; j++){
			if(v[i]==v[j]){
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}
std::vector<int>IzdvojiGadne(std::vector<int> vektor, bool n){
	std::vector<int>rezultat;
	for(int i=0; i<vektor.size(); i++){
		std::deque<int> ternarni=Ternarni(vektor[i]);
		if(n==true){
			if(JelParan(ternarni)) rezultat.push_back(vektor[i]);
		}
		else if(n==false){
			if(JelNeparan(ternarni)) rezultat.push_back(vektor[i]);
		}
	}
	rezultat=SrediVektor(rezultat);
	return rezultat;
}
int main() {
	std::vector<int>v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int x;
	do {
		std::cin>>x;
		if(x==0)break;
		v.push_back(x);
	} while(x!=0);
	std::cout<<"Opaki: ";
	std::vector<int>Opaki = IzdvojiGadne(v,1);
	for(int i=0; i<Opaki.size(); i++) std::cout<<Opaki[i]<<" ";
	std::cout<<std::endl;
	std::vector<int>Odvratni = IzdvojiGadne(v, 0);
	std::cout<<"Odvratni: ";
	for(int i=0; i<Odvratni.size(); i++) std::cout<<Odvratni[i]<<" ";
	return 0;
}




