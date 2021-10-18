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

using namespace std; 

vector<int> IzdvojiGadne(vector <int> v, bool a){
	
	vector <int> izlaz; 
	if(v.size()==0) return izlaz; 
	
	int pomocni, broj, cifra; 
	int brojac0=0, brojac1=0, brojac2=0;
	for(int i=0; i<v.size(); i++){
		pomocni=v[i];
		broj=v[i];
		if(pomocni<0) pomocni=-pomocni; 
		brojac0=0; brojac1=0; brojac2=0; 			// za svaki broj postavljamo brojace na 0
		if(pomocni==0){
			brojac0++; 
		}
		while(pomocni!=0){
			cifra=pomocni%3; 
			pomocni=pomocni/3; 					//gledamo koja je cifra pri promjeni u bazu 3
			if(cifra==0) brojac0++;								
			else if(cifra==1) brojac1++; 		// zavisno koja je cifra povećavamo odgovarajući brojac
			else if(cifra==2) brojac2++; 
		}
		if((brojac0%2==0 || brojac0==0) && (brojac1%2==0 || brojac1==0) && (brojac2%2==0 || brojac2==0)  && a==true){  // sa parnim brojem i true tj opaki
			bool sadrzi=false; 
			for(int i=0; i<izlaz.size(); i++){					//provjeravamo da li se taj broj nalazi već u vektoru
				if(broj==izlaz[i])
					sadrzi=true; 								
			}
			if(!sadrzi)											//ako se ne nalazi onda ga ubacujeo u vektor
				izlaz.push_back(broj); 
		}
		else if((brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0) && a==false){ // sa neparnim brojem i false tj odvratni
			bool sadrzi=false; 
			for(int i=0; i<izlaz.size(); i++){
				if(broj==izlaz[i])
					sadrzi=true;
			}
			if(!sadrzi)
				izlaz.push_back(broj); 
		}
	}
	return izlaz; 
}


int main ()
{
	vector<int> vektor; 
	int broj; 
	cout << "Unesite brojeve (0 za prekid unosa): "; 
	for(int i=0; ; i++){
		cin >> broj; 
		if(broj==0) break; 
		vektor.push_back(broj);
	}
	
	vector<int> opaki; 
	vector<int> odvratni; 
	opaki=IzdvojiGadne(vektor, true);
	odvratni=IzdvojiGadne(vektor, false);
	
	cout << "Opaki: "; 
	for(int x : opaki){
		cout << x << " "; 
	}
	cout << endl << "Odvratni: ";  
	for(int x : odvratni){
		cout << x << " "; 
	}
	
	
	return 0;
}