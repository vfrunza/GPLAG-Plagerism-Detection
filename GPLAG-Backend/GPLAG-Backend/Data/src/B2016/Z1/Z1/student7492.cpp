/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

typedef std::vector<int> VektorInt;

VektorInt Odvratni (VektorInt vektor){
	VektorInt vekt;
	VektorInt finalni;
	int brojac0(0),brojac1(0),brojac2(0);
	for(int i(0);i<vektor.size();i++){
		bool postoji=false;
		int broj=vektor[i];
		while(broj!=0){
			int cifra=broj%3;
			broj/=3;
			if(cifra<0) cifra=(-1)*cifra;
			vekt.push_back(cifra);
		}
		for(int j(0);j<vekt.size();j++){
			int broj2=vekt[j];
			if(broj2==0) brojac0++;
			if(broj2==1) brojac1++;
			if(broj2==2) brojac2++;
		}
		if((brojac0%2==1 && brojac1%2==1 && brojac2%2==1) || (brojac0%2==1 && brojac1%2==1 && brojac2==0) || (brojac0==0 && brojac1%2==1 && brojac2%2==1) || (brojac0%2==1 && brojac1==0 && brojac2%2==1) || (brojac0%2==1 && brojac1==0 && brojac2==0)||(brojac0==0 && brojac1%2==1 && brojac2==0)|| (brojac0==0 && brojac1==0 && brojac2%2==1)){
			for(int j(0);j<finalni.size();j++){
				if(finalni[j]==vektor[i]){
					postoji=true;
				}
			}
			if(postoji==false) finalni.push_back(vektor[i]);
		}
		vekt.clear();
		brojac0=0;
		brojac1=0;
		brojac2=0;
	}
	return finalni;
}

VektorInt Opaki(VektorInt vektor){
	VektorInt vekt;
	VektorInt finalni;
	int brojac0(0),brojac1(0),brojac2(0);
	for( int i(0);i<vektor.size();i++){
		bool postoji=false;
		int broj=vektor[i];
		while(broj!=0){
			int cifra=broj%3;
			broj/=3;
			if(cifra<0) cifra=(-1)*cifra;
			vekt.push_back(cifra);
		}
		for(int j(0);j<vekt.size();j++){
			int broj2=vekt[j];
			if(broj2==0) brojac0++;
			if(broj2==1) brojac1++;
			if(broj2==2) brojac2++;
		}
		if((brojac0%2==0 && brojac1%2==0 && brojac2%2==0)||(brojac0==0 && brojac1%2==0 && brojac2%2==0)||(brojac0%2==0 && brojac1==0 && brojac2%2==0)||(brojac0%2==0 && brojac1%2==0 && brojac2==0)||(brojac0%2==0 && brojac1==0 && brojac2==0)||(brojac0==0 && brojac1%2==0 && brojac2==0)||(brojac0==0 && brojac1==0 && brojac2%2==0)){
			for(int j(0);j<finalni.size();j++){
				if(finalni[j]==vektor[i]){
					postoji=true;
				}
			}
			if(postoji==false) finalni.push_back(vektor[i]);
		}
		vekt.clear();
		brojac0=0;
		brojac1=0;
		brojac2=0;
	}
	return finalni;
}

VektorInt IzdvojiGadne(VektorInt vektor, bool a){
	if(a==true){
		return Opaki(vektor);
	}
	if(a==false){
		return Odvratni(vektor);
	}
}

int main ()
{
	VektorInt vektor;
	int broj;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>broj;
		
	/*	while(!std::cin){
			std::cout<<"Pogresan unos unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000,'\n');
			std::cin>>broj;
		}*/
		if(broj==0) break;
		vektor.push_back(broj);
		
	}while(broj!=0);
	
	VektorInt v1=Opaki(vektor);
	VektorInt v2=Odvratni(vektor);
	std::cout<<"Opaki: ";
	for(int i(0);i<v1.size();i++){
		std::cout<<v1[i]<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i(0);i<v2.size();i++){
		std::cout<<v2[i]<<" ";
	}
	return 0;
}