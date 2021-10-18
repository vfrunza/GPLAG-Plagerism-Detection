/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std:: vector <int> IzdvojiGadne (std:: vector <int> izvorni, bool indikator)
{
	std:: vector <int> povratni;
	for (int i=0; i<izvorni.size(); i++)
	{
		int x=izvorni[i]; 
		int brojac0(0), brojac1(0), brojac2(0);
		std:: vector <int> ternarni;
		while (x!=0)
		{
			ternarni.push_back(x%3);
			x/=3;
		}
		for (int j=0; j<ternarni.size(); j++)
		{
			int y=ternarni[j];
			if (y==0) brojac0++;
			if (y==1) brojac1++;
		    if (y==2) brojac2++; 
		}
		//vraca opake
		if (indikator == true && brojac2%2==0 && brojac1%2==0 && brojac0%2==0 )
		povratni.push_back(izvorni[i]);
		//vraca odvratne
		else if (indikator == false && brojac2%2==1 && brojac0%2==1 && brojac1%2==1)
		povratni.push_back(izvorni[i]);
		
	}
	return povratni;
	
}
int main ()
{
	std:: cout << "Unesite brojeve (0 za prekid unosa): ";
	std:: vector <int> vektor;
	int broj(0);
	while (!broj)
		{
			
			std:: cin >> broj;
		    vektor.push_back(broj);
		   
		}
		
	std:: vector <int> opaki = IzdvojiGadne(vektor, true);
	std:: vector <int> odvratni = IzdvojiGadne(vektor, false);
	for (int  i: opaki)
	std:: cout << "Opaki: " << i << " " << std:: endl;
	for (int i: odvratni) 
	std:: cout << "Odvratni: " << i << " " << std:: endl;
	return 0;
}