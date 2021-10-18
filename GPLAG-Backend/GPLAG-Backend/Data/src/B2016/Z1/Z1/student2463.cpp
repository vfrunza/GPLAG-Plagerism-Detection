/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

bool OpakiBrojevi(int n){
	
	std::vector<int> brojacParnih(3);
	int cifra(0), ostatak(0), dek(1), konacna(0);
	while(n!=0){
		
		cifra=n%3;
		brojacParnih[cifra]++; // ovdje se uvecava ona cifra koja je ujedno na toj poziciji u vektoru 
		ostatak=cifra*10;
		dek*=10;
		konacna=(dek*cifra)+ostatak;
		n = n/10;
		
	}
	if( brojacParnih[0]%2==0 && brojacParnih[1]%2==0 && brojacParnih[2]%2==0) return true;
	return false;
	
}


std::vector<int> IzdvojiGadne(std::vector<int> vektor, bool tn){
	std::vector<int> izdvojeni;
	for(int x: vektor){
		if(tn==true && OpakiBrojevi(x)==true) izdvojeni.push_back(x);
		if(tn==false && OpakiBrojevi(x)==false) izdvojeni.push_back(x);
	}
	return izdvojeni;
	
}

int main ()
{
	
	std::vector<int> NekiVektor, parni, neparni;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	parni= IzdvojiGadne(NekiVektor, true);
	neparni= IzdvojiGadne(NekiVektor, false);
	
	for(int b: parni){
		std::cout<< b << " ";
	}
	std::cout<<std::endl;
	
	for(int c: neparni){
		std::cout<< c << " ";
	}
	
	return 0;
}