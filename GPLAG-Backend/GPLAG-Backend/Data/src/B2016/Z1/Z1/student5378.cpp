/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> IzdvojiGadne(std::vector<int>v , bool logicka_vrijednost){
	std::vector<int>vrati;
for (int i=0;i<v.size();i++){
	for(int j=0;j<v.size();j++){
		if(v[i]==v[j] && i!=j){
			v.erase(v.begin()+j);
			j--;
		}
	}
}
	for(int i=0;i<v.size();i++){
		int cifra;
		int broj=fabs(v[i]);
		int br1(0),br2(0),br3(0);
		while(broj!=0){
			cifra=broj%3;
			if(cifra==0)br1++;
			else if(cifra==1)br2++;
			else br3++;
			broj=broj/3;
		}
		if(logicka_vrijednost){
			if(br1%2==0 && br2%2==0 && br3%2==0)
			vrati.push_back(v[i]);
		}
			else{
				/*if(((br1+br2+br3)%2==1)&&(br1%2==1 && br2%2==1 && br3%2==1))
				*/
				if(((br1==0 || br2==0 || br3==0)&&(br1%2==1 && br2%2==1)||(br2%2==1&&br3%2==1)||
				(br1%2==1&&br3%2==1))||(((br1+br2+br3)%2==1)&&(br1%2==1 && br2%2==1 && br3%2==1)))

				vrati.push_back(v[i]);
			} 
			
		}
		return vrati;
	}

int main ()
{
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	std::vector<int> Vektor;
	
	while(std::cin>>n){
		if (n==0) break;
		Vektor.push_back(n);
	}
	std::vector<int>opaki;
	opaki=IzdvojiGadne(Vektor ,true);
	std::cout<<"Opaki: ";
	for(int i=0;i<opaki.size();i++){
		std::cout<<opaki[i]<<" ";
	}
	std::cout<<std::endl;
	std::vector<int>gadni;
	gadni=IzdvojiGadne(Vektor,false);
	std::cout<<"Odvratni: ";
	for(int i=0;i<gadni.size();i++){
		std::cout<<gadni[i]<<" ";
	}
	

}
