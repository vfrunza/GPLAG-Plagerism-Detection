/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool logic){
	std::vector<int> Opaki, Odvratni;
	if(v.size()==0 && logic)
		return Opaki;
	else if(v.size()==0 && !logic)
		return Odvratni;
	for(int x: v){
		int sacuvaj(x);
		x=std::abs(x);
		std::vector<int> Ternarni;
		while(x!=0){
			Ternarni.push_back(x%3);
			x/=3;
		}
		int brojac0(0), brojac1(0), brojac2(0);
		for(int x: Ternarni){
			if(x==0) brojac0++;
			else if(x==1) brojac1++;
			else if(x==2) brojac2++;
		}
		if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0)
			Opaki.push_back(sacuvaj);
		else if((brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0))
			Odvratni.push_back(sacuvaj);
	}
	//Izbacivanje brojeva koji se ponavljaju u vektoru Opaki
	for(int i=0; i<Opaki.size(); i++){
		for(int j=i+1; j<Opaki.size(); j++){
			if(Opaki.at(i)==Opaki.at(j)){
				Opaki.erase(Opaki.begin() + j);
				j--;
			}
			if(j==Opaki.size())
				break;
		}
		if(i==Opaki.size())
			break;
	}
	//Izbacivanje brojeva koji se ponavljaju u vektoru Odvratni
	for(int i=0; i<Odvratni.size(); i++){
		for(int j=i+1; j<Odvratni.size(); j++){
			if(Odvratni.at(i)==Odvratni.at(j)){
				Odvratni.erase(Odvratni.begin() + j);
				j--;
			}
			if(j==Odvratni.size())
				break;
		}
		if(i==Odvratni.size())
			break;
	}
	
	
	if(logic)
		return Opaki;
	return Odvratni;
}

int main (){
	int broj;
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>broj;
		if(broj)
			v.push_back(broj);
	}while(broj);
	std::cout<<"Opaki: ";
	for(int x: IzdvojiGadne(v, true))
		std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int x: IzdvojiGadne(v, false))
		std::cout<<x<<" ";
	return 0;
}