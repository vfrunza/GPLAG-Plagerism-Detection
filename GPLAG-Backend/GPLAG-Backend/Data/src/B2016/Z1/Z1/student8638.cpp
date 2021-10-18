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

std::vector<int> decimalno_u_ternarno(int x){
	std::vector<int> a;

	x = abs(x);

	while(x != 0){
		if(x==0)
		break;
		a.push_back(x%3);
		x /= 3;
	}
	
	return a;
	/*int k(1);
	long long int broj(0);
	
	for(int i=0; i<a.size(); i++){
		std::cout << a[i];
		broj += a[i]*k;
		k *= 10;
	}
	std::cout<<std::endl;
	for(int i=a.size()-1; i>=0; i--){
		std::cout << a[i];
	}
		std::cout<<std::endl;
	return broj;*/
	
}

int opak_ili_odvratan(std::vector<int> x){
	
	int temp;
	std::vector<int> vek;
	int brojac0(0), brojac1(0), brojac2(0);
	
	
	for(int i=x.size()-1; i>=0; i--){
	temp = x[i];
	if(temp == 0)
		brojac0++;
	if(temp == 1)
		brojac1++;
	if(temp == 2)
		brojac2++;
	
	}
	
	if(brojac0 != 0)
	vek.push_back(brojac0);
	if(brojac1 != 0)
	vek.push_back(brojac1);
	if(brojac2 != 0)
	vek.push_back(brojac2);
	
	bool opak(true), odvratan(true);
	
	for(int i=0; i<vek.size(); i++){
		if(vek[i] % 2 != 0 )
			opak = false;
		if(vek[i] % 2 == 0)
			odvratan = false;
		
	}
	if(opak == false && odvratan == true)
		return 1;
	if(opak == true && odvratan == false)
		return -1;
	else
		return 0;
	
}

std::vector<int> IzdvojiGadne(std::vector<int> vek, bool x){
	
	std::vector<int> opaki, odvratni;
	
	for(int i=0; i<vek.size(); i++){
		
		if(opak_ili_odvratan(decimalno_u_ternarno(vek[i])) == -1){
			bool sadrzan_opaki = false;
			for(int j=0; j<opaki.size(); j++){
				if(vek[i] == opaki[j]){
					sadrzan_opaki = true;
					break;
				}
			}
			if(sadrzan_opaki == false)
			opaki.push_back(vek[i]);
		}
		
		else if((opak_ili_odvratan(decimalno_u_ternarno(vek[i])) == 1)){
			bool sadrzan_odvratni = false;
			for(int k=0; k<odvratni.size(); k++){
				if(vek[i] == odvratni[k]){
					sadrzan_odvratni = true;
					break;
				}
			}
			if(sadrzan_odvratni == false)
			odvratni.push_back(vek[i]);
		}
	}	
	
	if(x) return opaki;
	else return odvratni;
	
}

int main ()
{ 

	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int element;
	std::vector<int> a;
	while(std::cin >> element){
		if(element == 0) break;
		a.push_back(element);
	}

	
	std::vector <int> b, c;
	
	for(int i=0; i<a.size(); i++){
		
		if(opak_ili_odvratan(decimalno_u_ternarno(a[i])) == -1)
			b = IzdvojiGadne(a,true);
		
		else if(opak_ili_odvratan(decimalno_u_ternarno(a[i])) == 1)
			c = IzdvojiGadne(a,false);
			
	}
	
	
	std::cout << "Opaki: ";
	for(int i=0; i<b.size(); i++)
		std::cout << b[i] << " ";
	
	std::cout << std::endl;
	
	std::cout << "Odvratni: ";
	for(int i=0; i<c.size(); i++)
		std::cout << c[i] << " ";
		
	return 0;
}