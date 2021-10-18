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

std::vector<int> IzdvojiGadne(std::vector<int> a, bool tip)
{
	std::vector<int> opaki, odvratni, ter, org;	
	
	//Brisanje kopija
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < i; j++)
			if(a[i] == a[j])
			{
				a.erase(a.begin() + i); 
				j--;
				i--;
			}
			
	//Racunanje najveceg stepena broja 3 koji se nalazi u broju
	for(int i = 0; i < a.size(); i++)
	{
		int j(0), broj(std::abs(a[i]));
		while(broj != 0)
		{
			broj = std::abs(a[i]);
			broj /= std::pow(3,j);
			if(broj != 0)
				j++;
			else
				j--;
		}
		
		//Pretvaranje u ternarni oblik
		int terbroj(0);
		int testbroj;
		testbroj = std::abs(a[i]);
		for(int k = j; k >= 0; k--)
		{
			bool prekid(false);
			while(testbroj > 0 && !prekid)
			 {
			 	testbroj -= std::pow(3,k);
			 	if(testbroj >= 0){
			 		terbroj += std::pow(10,k);
			 	}
			 	else if(testbroj < 0)
			 	{
			 		testbroj += std::pow(3,k);
					prekid = true;
			 	}
			 	else if(testbroj == 0)
			 		prekid = true;
			 }	
		}
		ter.push_back(terbroj);
		org.push_back(a[i]);
	}
	
	//Provjeravanje broja svake cifre i podjela na opake i odvratne
	std::vector<int> brcif, cif;
	bool postoji;
	int index;
	for(int i = 0; i < ter.size(); i++)
	{
			brcif.resize(0);
			cif.resize(0);
			int cifra, trcifra;
			cifra = ter[i];
			while(cifra != 0)
			{
				trcifra = cifra%10;
				postoji = false;
				for(int i = 0; i < cif.size(); i++)
					if(trcifra == cif[i])
					{
						postoji = true;
						index = i;
					}
				if(!postoji)
				{
					brcif.push_back(1);
					cif.push_back(trcifra);
				}
				if(postoji)
					brcif[index]++;
				cifra /= 10;
			}
			bool parni(true), neparni(true);
			for(int i = 0; i < cif.size(); i++)
			{
				if(brcif[i] % 2 == 0)
					neparni = false;
				if(brcif[i] % 2 != 0)
					parni = false;
			}
		if(parni)
			opaki.push_back(org[i]);
		if(neparni)
			odvratni.push_back(org[i]);
	}
	if(tip)
		return opaki;
	else
		return odvratni;
}

int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> a;
	int n;
	std::cin>>n;
	while(n != 0)
	{
		a.push_back(n);
		std::cin>>n;
	}
	std::cout<<"Opaki: ";
	std::vector<int> opaki;
	opaki = IzdvojiGadne(a, true);
	for(int i = 0; i < opaki.size(); i++)
		std::cout<<opaki[i]<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	std::vector<int> odvratni;
	odvratni = IzdvojiGadne(a, false);
	for(int i = 0; i < odvratni.size(); i++)
		std::cout<<odvratni[i]<<" ";
	return 0;
}