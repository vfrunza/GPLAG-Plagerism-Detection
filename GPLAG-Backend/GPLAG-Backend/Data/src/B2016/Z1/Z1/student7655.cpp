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
#include <limits>
typedef std::vector <int> vektor;
int funkcija (int x){
	vektor cifre;
	vektor ponavljanje;
	int parno(0);
	int neparno(0);
	int y(x);
	for (; ;){
		
		cifre.push_back(y%10);
		y/=10;
		if (y==0) break;
	}
	for (int i=0; i<cifre.size(); i++){
		int counter(1);
		int c(0);
		for (int j=0; j<ponavljanje.size(); j++){
			if (cifre[i]==ponavljanje[j])  {c=1; break;}
		}
		if (c==1) continue; 
		ponavljanje.push_back(cifre[i]);
		for (int j=i+1; j<cifre.size(); j++){
			if(cifre[i]==cifre[j]) counter++;
		}
		if (counter %2 ==0)  parno++;
		else neparno++;
	}
	//if (parno.size!=0 && neparno.size!=0) 
/*	std::cout<<neparno<<std::endl;*/
	if (parno!=0 && neparno!=0) return -1;
	if (parno==0) return false; else return true;
/*	 */
	/**/
}
vektor Pretvori (vektor brojevi){
	
	int k(0);
	for (int q: brojevi) {int br_cifara(0); int v(q); 
		/*for (; ;){
			br_cifara++;
			v=v/10;
			if (v==0) break;
		}*/
		v = q;
		int novi_broj(0);
		int i(0);
		for (; ;){
			novi_broj+= (v%3)*pow(10,i); i++;
			v=v/3;
			if (v==0) break;
		}
		q = novi_broj;
		brojevi[k]=novi_broj;
		k++;
	}
	return brojevi; 
}
vektor IzdvojiGadne (vektor brojevi, bool m){
	vektor brojevi1 = Pretvori(brojevi);
	/*for (int x: brojevi1) std::cout<<x<<std::endl;*/
	vektor brojevi2;
	
	int x = brojevi1.size();
	for (int i=0; i<x; i++){
		int c(0);
		for (int j =0; j<brojevi2.size(); j++){
			if (brojevi[i]==brojevi2[j]) {c=1; break;}
		}
		if (c==1) continue;
		int ks = funkcija(brojevi1[i]);
		if (ks==-1) continue;
/*		std::cout<<"kenan"<<ks<<std::endl;*/
		if(ks==m) brojevi2.push_back(brojevi[i]);
	}
/*	for (int x: brojevi2) std::cout<<x<<std::endl; */
	return brojevi2; 
}

int main ()
{
/*	vektor brojevi, kenan;
	int n(0);
	int k;

	std::cout<< "Unesite brojeve (0 za prekid unosa): ";
	for (; ;) 
	{std::cin>>k; if (k==0) break; brojevi.push_back(k); n++; }
	std::cout<<"Opaki: ";
	kenan = IzdvojiGadne(brojevi, true);
	for (int x: kenan) std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: " ;
	kenan = IzdvojiGadne(brojevi, false);
	for (int x: kenan) std::cout<<x<<" ";
*/
std::vector<int> brojevi = { std::numeric_limits<int>::min(), 0, 0, 0};
vektor kenan;
	int n(0);
	int k;
std::cout<<"Opaki: ";
	kenan = IzdvojiGadne(brojevi, true);
	for (int x: kenan) std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: " ;
	kenan = IzdvojiGadne(brojevi, false);
	for (int x: kenan) std::cout<<x<<" ";
return 0;
}