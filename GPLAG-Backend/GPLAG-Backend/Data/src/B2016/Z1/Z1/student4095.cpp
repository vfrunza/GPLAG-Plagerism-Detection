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

long long int UTernarni (int n)
{
	long long int ternarni(0);
	bool negativan(false);
	if (n<0) 
		negativan=true;
	
	long long int i(1);
	while (n!=0)
	{
		ternarni+=(abs(n)%3)*i;
		n/=3;
		i*=10;
	}
	
	if(negativan)
		return -ternarni;
	return ternarni;
}

int DaLiJeGadan (long long int n)
{
	if (n<0) 
		n=-n;
	std::vector<int> br_cifara (10);
	while (n!=0)
	{
		int cifra=n%10;
		br_cifara[cifra]++;
		n/=10;
	}
	
	// cak i da je poslani broj nula, na poziciji 0 ce biti 1
	bool paran;
	for (int i=0; i<br_cifara.size(); i++)
	{
		// da ne ode van vektora
		if(!br_cifara[i])
			continue;
		if (br_cifara[i]%2)
		{
			paran=false;
			break;
		}
		else
		{
			paran=true;
			break;
		}
	}
	
	for(int i=0; i<br_cifara.size(); i++)
	{

		// neka preskoci nule	
		if (br_cifara[i]==0)
			continue;
		//ako je sljedeci neparan, a treba biti paran nije gadan 	
		if (paran)
		{
			if(br_cifara[i]%2)
				return 0;
		}
		else
		{
			if(!(br_cifara[i]%2))
				return 0;
		}
	}
	// opak
	if (paran) return 1;
	// odvratan
	return 2; 
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool logicka)
{
	std::vector<int> gadni;

	for (int i=0; i<v.size(); i++)
	{
		if (i==v.size()) 
			break;
		if (!DaLiJeGadan(UTernarni(v[i])))
			continue;
		if (logicka && DaLiJeGadan(UTernarni(v[i]))==1)
			gadni.push_back(v[i]);
		else if (!logicka && DaLiJeGadan(UTernarni(v[i]))==2)
			gadni.push_back(v[i]);
	}
	
	// ako se ponavljaju
	for (int i=0; i<int(gadni.size())-1; i++)
	{
		for (int j=i+1; j<gadni.size(); j++)
		{
			if (gadni[i]==gadni[j])
			{	
				gadni.erase(gadni.begin()+j);
				j--;
			}	
		}
	}
	return gadni;
}



int main ()
{
	std::vector<int> v;
	int n;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for (;;)
	{
		std::cin>>n;
		if (n==0)
			break;
		v.push_back(n);
	}
	std::vector<int> opaki=IzdvojiGadne(v, true);
	std::vector<int> odvratani=IzdvojiGadne(v, false);
	
	std::cout<<"Opaki: ";
	for (int x: opaki)
		std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for (int x: odvratani)
		std::cout<<x<<" ";
	return 0;
}