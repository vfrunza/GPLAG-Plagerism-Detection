#include <iostream>
#include <vector>
#include <limits>

int BrojCifri(int n)
{
	int cifre{0};
	if(n < 0) n *= -1;
	while(n > 0)
	{
		cifre++;
		n /= 10;
	}
	return cifre;
}

int pretvori(int n)
{
	if(n == 0) return 0;
	int novi{0};
	int nule{0};
	//ako je broj % 3 == 0 na pocetku, da spasi nulu
	if(n % 3 == 0) 
	{
		int pomocni{n};
		while(pomocni % 3 == 0)
		{
			nule++;
			pomocni /= 3;
		}
		
	}
	
	while(n > 0)
	{
		novi += n % 3;	
		n /= 3;
		novi *= 10;
	} 
	novi /= 10;
	n = 0;
	//obrce broj
	while(novi > 0)
	{
		n += novi % 10;
		novi /= 10;
		n *= 10;
	}
	//dodaje nule
	n /= 10;
	if(nule != 0)
	{
		while(nule > 0)
		{
			n *= 10;
			nule--;
		}
		
	}

	return n;
}


int gadan(int n)
{
	std::vector<unsigned long int> cifre(3,0);	
	if(n == 0) return 2;
	while(n > 0)
	{
		if(n % 10 == 0) cifre[0]++;
		else if(n % 10 == 1) cifre[1]++;
		else if(n % 10 == 2) cifre[2]++;
		n /= 10;
	}
	
	int opak{0}, odvratan{0}, pomocni{0};
	
		//pomocni je za cifre koje se ne pojavljuju
	
	for(int i{0}; i < cifre.size(); i++)
	{
		if(cifre[i] == 0)
		{	
			pomocni++;
			continue;
		}
		if(cifre[i] % 2 == 0) opak++;
		if(cifre[i] % 2 == 1) odvratan++;
	}
	
		// 1 - opak
		// 2 - odvratan
		// 3 - ni jedno ni drugo

	if(opak == 3 - pomocni) return 1;
	if(odvratan == 3 - pomocni) return 2;
	return 3;
	
}

std::vector<int> IzdvojiGadne(std::vector<int> vektor, bool gadnost)
{
	std::vector<int> novi;
	bool negativan{false};
	
	if(gadnost)
	{
		for(int i{0}; i < vektor.size(); i++)
		{	

			if(vektor[i] < 0) 
			{
				negativan = true;
				vektor[i] *= -1;
			}
			if(gadan(pretvori(vektor[i])) == 1)
			{
				if(negativan) vektor[i] *= -1;
				novi.push_back(vektor[i]);
				
			}
			negativan = false;
		}	
	}
	else
	{
		for(int i{0}; i < vektor.size(); i++)
		{
			//if(BrojCifri(vektor[i]) > 4) continue;
			if(vektor[i] < 0)
			{
				negativan = true;
				vektor[i] *= -1;
			}
			if(gadan(pretvori(vektor[i])) == 2) 
			{	
				if(negativan) vektor[i] *= -1;
				novi.push_back(vektor[i]);
			}
			negativan = false;
		}
	}
	
		// brisanje viska elemenata
	
	for(int i{0}; i < novi.size(); i++)
	{
		for(int j{i+1}; j < novi.size(); j++)
		{
			if(novi[i] == novi[j]) 
			{
				novi.erase(novi.begin() + j);
				j--;
			}
		}
	}
	
	return novi;
	
}

int main ()
{
	std::vector<int> vektor;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int n;
	
	for(;;)
	{
		
		std::cin >> n;
		if(n == 0) break;
		if(std::cin)
			vektor.push_back(n);
		else
		{
			std::cout << std::endl << "Neispravan unos.";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}

	}
	
	std::vector<int> opaki;
	std::vector<int> odvratni;
	
	opaki = IzdvojiGadne(vektor, true);
	odvratni = IzdvojiGadne(vektor, false);
	std::cout << "Opaki: ";
	for(int x : opaki) std::cout << x << " ";
	std::cout << std::endl << "Odvratni: ";
	for(int x : odvratni) std::cout << x << " ";
	
	
	return 0;
}