/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vektor;

int DecimalToTernary (int n){
	int broj{0};
	Vektor cifre;
	while(n!=0){
		cifre.push_back(abs(n%3));
		n=n/3;
	}
	for( int i{(int)cifre.size()-1}; i>=0; i--) {
		broj+=cifre[i];
		if(i==0) break;
		broj = broj*10;
	}
	return broj;
}

Vektor IzdvojiGadne ( Vektor vfunk, bool logicka ){
	Vektor pomocni;
	int broj0, broj1, broj2;
	
	for(int i{0}; i<vfunk.size(); i++){
		
		//SEGMENT U KOJEM RADIMO SA i. ELEMENTOM
		broj0=0; broj1=0; broj2=0;
		//logicke vrijednosti pronalaska odg cifara u ternarnom zapisu broja
		bool b0{false},b1{false},b2{false}; 
		int ternarni{ DecimalToTernary( vfunk[i]) };
		do{
			if(ternarni % 10==2) { broj2++; b2=true;}
			else if (ternarni % 10==1 ) { broj1++; b1=true;}
			else if (ternarni % 10==0 ) { broj0++; b0=true;}
			ternarni=ternarni/10;
		} while (ternarni>0);
		//Ovdje unosimo elemente u pomocni u ovisnosti od logicke
		if(logicka){
			// Uslovi parnosti brojeva cifara 0, 1 i 2 u ternarnom zapisu
			bool up0 { broj0!=0 && broj0%2==0 };
			bool up1 { broj1!=0 && broj1%2==0 };
			bool up2 { broj2!=0 && broj2%2==0 };
			bool nalaziSe{false};
			if( ((up0 && b0) || (up1 && b1) || (up2 && b2)) && (up0+up1+up2==b0+b1+b2) ) {
				//Sad ispitujemo da li se taj broj vec nalazi u pomocnom
				for(int j{0}; j<pomocni.size(); j++) if (vfunk[i]==pomocni[j]) nalaziSe=true;
				
				if(!nalaziSe) pomocni.push_back(vfunk[i]);
			}		
		} else if (!logicka){
			// Uslovi neparnosti brojeva cifara 0, 1 i 2 u ternarnom zapisu trazenog broja
			bool uNp0 { broj0!=0 && broj0%2==1 };
			bool uNp1 { broj1!=0 && broj1%2==1 };
			bool uNp2 { broj2!=0 && broj2%2==1 };
			bool nalaziSe{false};
			if( ((uNp0 && b0) || (uNp1 && b1) || (uNp2 && b2)) && (uNp0+uNp1+uNp2==b0+b1+b2) ) {
				//Sad ispitujemo da li se taj broj vec nalazi u pomocnom
				for(int j{0}; j<pomocni.size(); j++) if (vfunk[i]==pomocni[j]) nalaziSe=true;
				
				if(!nalaziSe) pomocni.push_back(vfunk[i]);
		}
	}
	
}
return pomocni;
}



int main (){
	cout << "Unesite brojeve (0 za prekid unosa): ";
	int n;
	Vektor vMain;
	Vektor Opaki;
	Vektor Odvratni;
	while(true){
		cin>>n;
		if(n==0) break;
		vMain.push_back(n);
	}
	cout<<"Opaki: ";
	Opaki=IzdvojiGadne(vMain, true);
	for (int x : Opaki){
		cout<< x<<" ";
	}
	cout<<endl;
	cout<<"Odvratni: ";
	Odvratni=IzdvojiGadne(vMain, false);
	for (int x : Odvratni){
		cout<< x<<" ";
	}
	return 0;
}