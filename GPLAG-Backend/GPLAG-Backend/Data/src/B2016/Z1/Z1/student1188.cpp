/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
std::vector<int> IzdvojiGadne(std::vector<int> v1, bool koji){
	std::vector<int>izdvojeni;
	//izdvoji opake kad je true
	if(koji==true){
		for(int i: v1){
			int x=i;
			int ostatak(0), nule(0), jedinice(0), dvojke(0);
			while(i!=0){
				ostatak=i%3;
				if(ostatak==0)
					nule++;
				if(ostatak==1)
					jedinice++;
				if(ostatak==2)
					dvojke++;
				i/=3;
			}
			if((nule%2==0) && (jedinice%2==0) && (dvojke%2==0)){
				int isti_su(0);
				for(int q: izdvojeni){
					if(q==x){
						isti_su=1;
					}
				}
					if(isti_su==0)
					izdvojeni.push_back(x);
			}	
		}
		return izdvojeni;
	}
	//izvoji odvratne ako je false
	if(koji==false){
		for(int i: v1){
			int x=i;
			int ostatak(0), nule(0),  jedinice(0), dvojke(0);
			while(i!=0){
				ostatak=i%3;
				if(ostatak==0)
					nule++;
				if(ostatak==1)
					jedinice++;
				if(ostatak==2)
					dvojke++;
				i/=3;	
			}
			//jesu li svi neparni (neki,ali ne i svi nule)
			if(((nule%2!=0)||(nule==0)) && ((jedinice%2!=0)||(jedinice==0)) && ((dvojke%2!=0)||(dvojke==0)) && ((nule!=0) || (jedinice!=0) || (dvojke!=0))){
				int isti_su(0);
				for(int b: izdvojeni){
					if(b==x){
						isti_su=1;
					}
				}	
					if(isti_su==0)	
						izdvojeni.push_back(x);
			}
		}
		return izdvojeni;
	}
	return v1;
}
int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>v;
	//unos
	for(int i=0;;i++){
		int broj;
		std::cin>>broj;
		if(broj!=0)
		v.push_back(broj);
		else break;
	}
	std::vector<int>opaki;
	std::vector<int>odvratni;
	
	opaki=IzdvojiGadne(v, true);
	odvratni=IzdvojiGadne(v, false);
	
	//ispis opakih
	std::cout<<"Opaki: ";
	for(int a: opaki)
		std::cout<<a<<" ";
		
	//ispis odvratnih	
	std::cout<<std::endl<<"Odvratni: ";
	for(int b: odvratni)
		std::cout<<b<<" ";
		
	return 0;
}