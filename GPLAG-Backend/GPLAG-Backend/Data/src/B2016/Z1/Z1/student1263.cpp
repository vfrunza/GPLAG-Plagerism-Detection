/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>


int CifreBaze3(int i) {
	int suma0(0), suma1(0), suma2(0);
	int t;

	if( i==0) return 0;
	do{
		t=i%3;
		if(t==0) suma0++;
		else if(t==1 || t==-1) suma1++;
		else suma2++;
		i/=3;
	} while(i!=0);
	if((suma0%2==0 && suma1%2==0 && suma2%2==0) /*||
	(suma0==0 && suma1%2==0 && suma2%2==0) || (suma0%2==0 && suma1==0 && suma2%2==0) || (suma0%2==0 && suma1%2==0 && suma2==0) ||
	(suma0==0 && suma1==0 && suma2%2==0) || (suma0==0 && suma1%2==0 && suma2==0) || (suma0%2==0 && suma1==0 && suma2==0)*/)
	return 2;
	else if((suma0%2!=0 && suma1%2!=0 && suma2%2!=0) ||
	(suma0==0 && suma1%2!=0 && suma2%2!=0) || (suma0%2!=0 && suma1==0 && suma2%2!=0) || (suma0%2!=0 && suma1%2!=0 && suma2==0) ||
	(suma0==0 && suma1==0 && suma2%2!=0) || (suma0==0 && suma1%2!=0 && suma2==0) || (suma0%2!=0 && suma1==0 && suma2==0))
	return 1;
	else return 0;
}

bool Provjera(std::vector<int> vektor, int clan) {
	for(int i=0; i<vektor.size(); i++) {
		if(clan==vektor[i]) return false;
	}
	return true;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool vrijednost) {
	std::vector<int> novi;
	int uslovna;
	if(vrijednost){
		for(int i: v) {
			uslovna=CifreBaze3(i);
			if(uslovna==2 && Provjera(novi,i)) novi.push_back(i);
		}
		/*int velicina(novi.size());
		for(int i=0; i<velicina; i++) {
			for(int j=i+1; j<velicina; j++) {
				if(novi[j]==novi[i]) novi.erase(novi.begin()+j);
				
			}
		
		}*/
	}
	else{
		for(int i: v) {
			uslovna=CifreBaze3(i);
			if(uslovna==1 && Provjera(novi,i)) novi.push_back(i);
		}
		/*int velicina(novi.size());
		for(int i=0; i<velicina; i++) {
			for(int j=i+1; j<velicina; j++) {
				if(novi[j]==novi[i]) novi.erase(novi.begin()+j);
				
			}
		}*/
	}
	return novi;
}

int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int i;
	do {
		std::cin>>i;
		v.push_back(i);
	} while(i!=0);
	
	
	std::vector<int> a(IzdvojiGadne(v,true));
	std::cout<<"Opaki: ";
	for(int i:a) std::cout<<i<<" ";
	std::cout<<std::endl;
	
	std::vector<int> b(IzdvojiGadne(v,false));
	std::cout<<"Odvratni: ";
	for(int i:b) std::cout<<i<<" ";
	std::cout<<std::endl;
	return 0;
}