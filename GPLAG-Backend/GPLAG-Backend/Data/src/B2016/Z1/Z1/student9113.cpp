/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<vector>
#include <iostream>
bool PretvoriBroj (int x){
	int brojac1 = 0;
	int brojac2 = 0;
	int brojac3 = 0;
	
	while (x!=0){
		if (x % 3 == 0)
		brojac1++;
		else if (x % 3 == 1)
		brojac2++;
		else if (x % 3 == 2)
		brojac3++;
		x/=3;
	}
	if ((brojac1 %2==0 || brojac1 == 0) && (brojac2 %2 == 0 || brojac2 == 0) && (brojac3 %2 == 0 || brojac3 == 0))
		return true;
		else return false;
	}
bool PretvoriBroj1 (int n){
	int brojac1 = 0;
	int brojac2 = 0;
	int brojac3 = 0;
	
	while ( n!=0){
		if ( n%3== 0)
		brojac1++;
		else if (n %3 == 1)
		brojac2++;
		else if (n %3 == 2)
		brojac3++;
		n/=3;
		}
	if((brojac1 %2 == 1 || brojac1 == 0) && (brojac2 %2 == 1 || brojac2 == 0) && (brojac3 %2 ==1 || brojac3 == 0))
	return true ;
	else return false;
		
	
}	
std::vector<int> IzdvojiGadne (std::vector<int> v,bool k){
	std::vector<int> fini;
	std::vector<int> ogavni;
	for (int i = 0;i<v.size();i++)
	{
		if (PretvoriBroj(v[i]) == true ) fini.push_back(v[i]);
		if (PretvoriBroj1(v[i]) == true) ogavni.push_back(v[i]);
		
	}
	
	for (int i = 0; i < fini.size(); i++)
	{
		for (int j = i+1; j < fini.size();j++){
			if(fini[i] == fini[j]) {
		for (int k = j; k<fini.size()-1;k++){
			fini[k] = fini[k+1];
	     	}		
			fini.resize(fini.size()-1);
			j--;
		 } } }
	for (int i = 0; i < ogavni.size(); i++)
	{
		for (int j = i+1; j < ogavni.size(); j++)
		{
			if (ogavni[i] == ogavni[j] ){
				for (int k = j; k < ogavni.size()-1; k++){
					ogavni[k] = ogavni [k+1];
					
				}
				ogavni.resize(ogavni.size()-1);
				j--;
			}
		}
	}
	if (k==true)
	return fini;
	else return ogavni;
	
}	



int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int broj;
	do{
		std::cin>>broj;
		if(broj != 0) v.push_back(broj);
	} while (broj != 0);
	
	std::vector<int> fini; 
	fini = (IzdvojiGadne(v,true));
	std::vector<int> ogavni;
	ogavni = (IzdvojiGadne(v,false));
	std::cout<<"Opaki: ";
	for (int x: fini) std::cout<<x<<" ";		
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int y: ogavni )std::cout<<y<<" ";
	return 0;
}