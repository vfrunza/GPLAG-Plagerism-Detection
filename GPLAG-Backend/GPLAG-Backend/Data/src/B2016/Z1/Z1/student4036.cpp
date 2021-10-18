/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector> 
#include <cmath>

std::vector<int> izvrni(std::vector<int> v)
{
	std::vector<int> pomocni;
	
	for(int i = v.size()-1; i >= 0; i--)
	{
		pomocni.push_back(v[i]);
	}
	return pomocni;
}

bool daLiPostojiUVektoru(std::vector<int> v, int broj)
{
	for(int x : v)
	{
		if(x == broj)
		{
			return true;
		}
	}
	
	return false;
}

int OpakiIliOdvratniIliNijedno(int broj)
{
	int jedinica = 0;
	int dvica = 0;
	int nula = 0;
	
	broj = abs(broj);
	do
	{
		switch(broj%3)
		{
			case 0: nula++; break;
			case 1: jedinica++; break;
			case 2: dvica++; break;
		}
		broj/=3;
		
	} while(broj != 0);
	
	if(nula%2 == 0 && jedinica%2 == 0 && dvica%2 == 0)
	{
		return 1; //1 je opak
	} else if((nula%2 != 0 || nula == 0) && (jedinica%2 != 0 || jedinica == 0) && (dvica%2 != 0 || dvica == 0))
	{
		if(!(jedinica == 0 && dvica == 0 && nula == 1))
		{
			return 2; //2 je odvratan
		}
	} else
	{
		return 0; //ne valja
	}
}

std::vector<int> IzdvojiGadne (std::vector<int> vektor, bool jel_tacno){
	
    std::vector<int> vektor_u_ternarnom;
	std::vector<int> vektor_za_vratiti;
	for(int i = 0; i < vektor.size(); i++)
	{
		if(jel_tacno)
		{
			if(OpakiIliOdvratniIliNijedno(vektor[i]) == 1)
			{
				if(!daLiPostojiUVektoru(vektor_za_vratiti,vektor[i]))
				{
					vektor_za_vratiti.push_back(vektor[i]);
				}
			}
		} else
		{
			if(OpakiIliOdvratniIliNijedno(vektor[i]) == 2)
			{
				if(!daLiPostojiUVektoru(vektor_za_vratiti,vektor[i]))
				{
					vektor_za_vratiti.push_back(vektor[i]);
				}
			}
		}
	}
	
	return vektor_za_vratiti;
	
}



int main ()
{
	int broj;
	std::vector<int> vektor ;
	std::cout << "Unesite brojeve (0 za prekid unosa): " ;
	do {
		std::cin >> broj;
		vektor.push_back(broj);
	} while (broj != 0);
	
	std::vector<int> odvratni;
	std::vector<int> opaki ;
    opaki = IzdvojiGadne(vektor, true);
    odvratni = IzdvojiGadne(vektor, false);
    std::cout << "Opaki: " ;
    for (int broj: opaki) {
    std::cout << broj << " ";
    }
    std::cout << std::endl;
    std::cout << "Odvratni: " ;
    for (int broj : odvratni) {
    std::cout << broj << " ";
    }
	return 0;
}
