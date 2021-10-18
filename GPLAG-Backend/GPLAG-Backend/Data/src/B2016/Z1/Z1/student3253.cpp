/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

void pretvoriUTernarni(int broj) 
{
	int iduci;
	int cifra;
	std::vector<int> frekvencije(3);
		
	iduci = broj;
	cifra = 0;
	
	while ( iduci > 0 )
	{
		cifra = iduci % 3;
		iduci = iduci / 3;
		
		frekvencije[cifra]++;
		std::cout << cifra;
	} 
	std::cout << std::endl;
	
	
	for (int i=0; i<3; i++) 
	{
		std::cout << frekvencije[i] << ",";	
	}
	std::cout << std::endl;
	

	bool opak = true;
	bool odvratan = true;
	
	for (int i=0; i<3; i++) 
	{

		if ( frekvencije[i] % 2 != 0 )
		{
			opak = false;
		}
		
	
		if ( frekvencije[i] % 2 == 0 && frekvencije[i] != 0 ) 
		{
			odvratan = false;
		}
	}
	std::cout << opak << ", " << odvratan;
	std::cout << std::endl;
}


bool ProvjeriGadnost(int broj, bool tip) 
{
	int iduci;
	int cifra;
	std::vector<int> frekvencije(3);
		
	iduci = std::abs(broj);
	cifra = 0;
	
	while ( iduci > 0 )
	{
		cifra = iduci % 3;
		iduci = iduci / 3;
		
		frekvencije[cifra]++;
	} 
	

	bool opak = true;
	bool odvratan = true;
	
	for (int i=0; i<3; i++) 
	{
		
		if ( frekvencije[i] % 2 != 0 )
		{
			opak = false;
		}
		
	
		if ( frekvencije[i] % 2 == 0 && frekvencije[i] != 0 ) 
		{
			odvratan = false;
		}
	}

	if (tip == true) 
		return opak;
	else
		return odvratan;
}

std::vector<int> IzdvojiGadne (std::vector<int> brojevi, bool tip) 
{
	std::vector<int> rezultat(0);
	for (int i=0; i<brojevi.size(); i++) 
	{
		if ( ProvjeriGadnost(brojevi[i], tip) == true ) 
		{
			bool ranijedodat = false;
			for (int j=0; j<rezultat.size(); j++) {
				if ( brojevi[i] == rezultat[j] ) 
				{
					ranijedodat = true;
					break;
				}
			}
			if (ranijedodat == false) 
			{
				rezultat.push_back(brojevi[i]);
			}
		}

	
	}
	
	return rezultat;
}

int main ()
{

	int velicinaniza = 0;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	
	
	std::vector<int> brojevi(0);


	int input = 1;
	while (input != 0)
	{
    	
    	std::cin >> input;
    	
    	if ( input != 0)
    		brojevi.push_back(input);
	}
	
	std::vector<int> opaki = IzdvojiGadne(brojevi, true);
	std::vector<int> odvratni = IzdvojiGadne(brojevi, false);
	
	std::cout << "Opaki: ";
	for (int i=0; i<opaki.size(); i++)
	{
		std::cout << opaki[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for (int i=0; i<odvratni.size(); i++)
	{
		std::cout << odvratni[i] << " ";
	}

	
	
	
	return 0;
}